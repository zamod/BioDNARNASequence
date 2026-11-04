#include <iostream>
#include <string>

#include "strand.h"

void Strand::SetTemplate(std::string emplate) {
    dna_template_ = emplate;
    dna_coding_ = "";
    mrna_sequence_ = "";
    amino_acid_sequence_ = "";
    for (const auto& element : emplate) {
        switch (element) {
            case 'A':
              dna_coding_ += "T";
              mrna_sequence_ += "U";
              break;
            case 'T':
              dna_coding_ += "A";
              mrna_sequence_ += "A";
              break;
            case 'C':
              dna_coding_ += "G";
              mrna_sequence_ += "G";
              break;
            case 'G':
              dna_coding_ += "C";
              mrna_sequence_ += "C";
              break;
            default:
              std::cout << "Error in sequence\n";
        }
    }
    std::string current_codon{""}; //holds the bases in each codon
    int loop_count{0};
    for (const auto& element : mrna_sequence_) {
      current_codon += element;
      ++loop_count;
      if (loop_count % 3 == 0) {
        if (codon_to_amino_acid_.find(current_codon) != codon_to_amino_acid_.end()) {
          amino_acid_sequence_ += codon_to_amino_acid_.at(current_codon);
          current_codon = "";
        }
      }
    }
    if (loop_count % 3 != 0) {
      enough_bases_ = false;
    } else {
      enough_bases_ = true;
    }
}

void Strand::SetCoding(std::string coding) {
    dna_coding_ = coding;
    dna_template_ = "";
    mrna_sequence_ = "";
    amino_acid_sequence_ = "";
    for (const auto& element : coding) {
        switch (element) {
            case 'A':
              dna_template_ += "T";
              mrna_sequence_ += "U";
              break;
            case 'T':
              dna_template_ += "A";
              mrna_sequence_ += "A";
              break;
            case 'C':
              dna_template_ += "G";
              mrna_sequence_ += "G";
              break;
            case 'G':
              dna_template_ += "C";
              mrna_sequence_ += "C";
              break;
            default:
              std::cout << "Error in sequence\n";
        }
    }
    std::string current_codon{""}; //holds the bases in each codon
    int loop_count{0};
    for (const auto& element : mrna_sequence_) {
      current_codon += element;
      ++loop_count;
      if (loop_count % 3 == 0) {
        if (codon_to_amino_acid_.find(current_codon) != codon_to_amino_acid_.end()) {
          amino_acid_sequence_ += codon_to_amino_acid_.at(current_codon);
          current_codon = "";
        }
      }
    }
    if (loop_count % 3 != 0) {
      enough_bases_ = false;
    } else {
      enough_bases_ = true;
    }
}

void Strand::SetMRNA(std::string mrna) {
    mrna_sequence_ = mrna;
    dna_coding_ = "";
    dna_template_ = "";
    for (const auto& element : mrna) {
        switch (element) {
            case 'A':
              dna_template_ += "T";
              dna_coding_ += "T";
              break;
            case 'U':
              dna_template_ += "A";
              dna_coding_ += "A";
              break;
            case 'C':
              dna_template_ += "G";
              dna_coding_ += "G";
              break;
            case 'G':
              dna_template_ += "C";
              dna_coding_ += "C";
              break;
            default:
              std::cout << "Error in sequence\n";
        }
    }
    std::string current_codon{""}; //holds the bases in each codon
    std::string current_codon{""}; //holds the bases in each codon
    int loop_count{0};
    for (const auto& element : mrna_sequence_) {
      current_codon += element;
      ++loop_count;
      if (loop_count % 3 == 0) {
        if (codon_to_amino_acid_.find(current_codon) != codon_to_amino_acid_.end()) {
          amino_acid_sequence_ += codon_to_amino_acid_.at(current_codon);
          current_codon = "";
        }
      }
    }
    if (loop_count % 3 != 0) {
      enough_bases_ = false;
    } else {
      enough_bases_ = true;
    }
}

void Strand::SetAminoAcidSequence(std::string amino_acid_sequence) {
    std::cout << "code to be added later";
}