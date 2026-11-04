#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits> //for error checking
#include <memory> //for the smart pointer
#include <string>
#include <vector>

#include "strand.h"

int main(int argc, char* argv[]) {
    std::vector<std::string> command_line{argv, argv + argc}; //convert c-style arrays of command line input to strings in a vector
    std::string input_sequence{""};
    if (command_line.size() < 2) { //check if a filename was supplied via command line with startup of program
        std::cout << "No file name included in argument, please try again.\n";
        return 1;
    }
    std::ifstream input_file(command_line.at(1)); //open file
    if (input_file.is_open()) { //make sure file is open
        std::getline(input_file, input_sequence); //collect input sequence
        input_file.close(); //close file
    } else {
        std::cout << "File unable to be opened, double check file name and retry input.\n";
        return 2;
    }
    auto sequence_ptr = std::make_unique<Strand>(); //using a unique pointer for practice
    int menu_input{0};
    std::cout << "Which sequence is this?\n";
    std::cout << "1. Template DNA Sequence\n";
    std::cout << "2. Coding DNA Sequence\n";
    std::cout << "3. mRNA Sequence\n";
    std::cout << "4. Amino Acid Sequence\n";
    while ((!(std::cin >> menu_input)) && (menu_input != 1 && menu_input != 2 && menu_input != 3 && menu_input != 4)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please enter \"1\", \"2\", \"3\", or \"4.\" Ctrl+C to force quit. ";
    }
    std::transform(input_sequence.begin(), input_sequence.end(), input_sequence.begin(), ::toupper);
    bool no_sequence_error{false};
    switch (menu_input) {
        case 1:
            no_sequence_error = sequence_ptr->SetTemplate(input_sequence);
            if (!no_sequence_error) {
                return 4;
            }
            break;
        case 2:
            no_sequence_error = sequence_ptr->SetCoding(input_sequence);
            if (!no_sequence_error) {
                return 4;
            }
            break;
        case 3:
            no_sequence_error = sequence_ptr->SetMRNA(input_sequence);
            if (!no_sequence_error) {
                return 4;
            }
            break;
        case 4:
            no_sequence_error = sequence_ptr->SetAminoAcidSequence(input_sequence);
            if (!no_sequence_error) {
                return 4;
            }
            break;
        default:
            std::cout << "Something went horribly wrong.\n";
            return 42;
            break;
    }
    std::string output_file_name{""};
    if (command_line.size() < 3) {
        std::cout << "What would you like to name the output file?: ";
        std::cin >> output_file_name;
        std::cout << "Is " << output_file_name << " correct? (y/n): ";
        char user_answer{'z'};
        while ((!(std::cin >> user_answer)) && (user_answer != 'y' && user_answer != 'n')) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "What would you like to name the output file?: ";
            std::cin >> output_file_name;
            std::cout << "Is " << output_file_name << " correct? (y/n): ";
        }
    } else {
        std::cout << "Is the output file name " << command_line.at(2) << " correct? (y/n): ";
        output_file_name = command_line.at(2);
        char user_answer{'z'};
        while ((!(std::cin >> user_answer)) && (user_answer != 'y' && user_answer != 'n')) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "What would you like to name the output file?: ";
            std::cin >> output_file_name;
            std::cout << "Is " << output_file_name << " correct? (y/n): ";
        }
    }
    std::ofstream output_file(output_file_name);
    if (output_file.is_open()) {
        output_file << "Template Sequence:\n";
        output_file << sequence_ptr->GetTemplate() << "\n";
        output_file << "Coding Sequence:\n";
        output_file << sequence_ptr->GetCoding() << "\n";
        output_file << "mRNA Sequence:\n";
        output_file << sequence_ptr->GetMRNA() << "\n";
        output_file << "Amino Acid Sequence:\n";
        output_file << sequence_ptr->GetAminoAcidSequence();
        output_file.close();
        std::cout << "File writing complete.\n";
    } else {
        std::cout << "Error in writing to file. Unkown why. Perhaps try again.\n";
        return 3;
    }
    return 0;
}