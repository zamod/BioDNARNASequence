#include <iostream>
#include <string>

#include "strand.h"

std::string Strand::ReverseDirectionality(std::string sequence) {
  std::string reversed{""};
  for (auto it = sequence.rbegin(); it != sequence.rend(); it++) {
    reversed += (*it);
  }
  return reversed;
}

void Strand::CalculateLengthyAminoAcids() {
  for (const auto& element : amino_acid_sequence_5_) {
    lengthy_amino_acids_5_ += amino_acid_char_to_string_.at(element);
    lengthy_amino_acids_5_ += " ";
  }
  if (!lengthy_amino_acids_5_.empty()) {
    lengthy_amino_acids_5_.pop_back(); //removes last empty space to correct the previous loop
  }
  for (const auto& element : amino_acid_sequence_3_) {
    lengthy_amino_acids_3_ += amino_acid_char_to_string_.at(element);
    lengthy_amino_acids_3_ += " ";
  }
  if (!lengthy_amino_acids_3_.empty()) {
    lengthy_amino_acids_3_.pop_back(); //removes last empty space to correct the previous loop
  }
}

void Strand::CalculateAminoAcids5() {
  std::string current_codon{""}; //holds the bases in each codon
  int loop_count{0};
  for (const auto& element : mrna_sequence_5_) {
      current_codon += element;
      ++loop_count;
      if (loop_count % 3 == 0) {
        if (codon_to_amino_acid_.find(current_codon) != codon_to_amino_acid_.end()) {
          amino_acid_sequence_ += codon_to_amino_acid_.at(current_codon);
          current_codon = "";
        }
      }
    }
}

void Strand::CalculateAminoAcids3() {
  std::string current_codon{""}; //holds the bases in each codon
  int loop_count{0};
  for (const auto& element : mrna_sequence_3_) {
      current_codon += element;
      ++loop_count;
      if (loop_count % 3 == 0) {
        if (codon_to_amino_acid_.find(current_codon) != codon_to_amino_acid_.end()) {
          amino_acid_sequence_ += codon_to_amino_acid_.at(current_codon);
          current_codon = "";
        }
      }
    }
}

bool Strand::SetTemplate5(std::string emplate) {
    dna_template_5_ = emplate;
    dna_coding_5_ = "";
    mrna_sequence_5_ = "";
    amino_acid_sequence_5_ = "";
    dna_coding_3_ = "";
    dna_template_3_ = "";
    mrna_sequence_3_ = "";
    amino_acid_sequence_3_ = "";
    for (const auto& element : emplate) {
        switch (element) {
            case 'A':
              dna_coding_3_ += "T";
              mrna_sequence_3_ += "U";
              break;
            case 'T':
              dna_coding_3_ += "A";
              mrna_sequence_3_ += "A";
              break;
            case 'C':
              dna_coding_3_ += "G";
              mrna_sequence_3_ += "G";
              break;
            case 'G':
              dna_coding_3_ += "C";
              mrna_sequence_3_ += "C";
              break;
            default:
              std::cout << "Error in sequence\n";
              return false;
        }
    }
    dna_template_3_ = ReverseDirectionality(dna_template_5_);
    dna_coding_5_ = ReverseDirectionality(dna_coding_3_);
    mrna_sequence_5_ = ReverseDirectionality(mrna_sequence_3_);
    std::string current_codon{""}; //holds the bases in each codon
    int loop_count{0};
    CalculateAminoAcids3();
    CalculateAminoAcids5();
    CalculateLengthyAminoAcids();
    if (loop_count % 3 != 0) {
      enough_bases_ = false;
    } else {
      enough_bases_ = true;
    }
    return true;
}

bool Strand::SetTemplate3(std::string emplate) {
  return SetTemplate5(ReverseDirectionality(emplate));
}

bool Strand::SetCoding5(std::string coding) {
    dna_coding_5_ = coding;
    dna_template_5_ = "";
    mrna_sequence_5_ = "";
    amino_acid_sequence_5_ = "";
    dna_template_3_ = "";
    for (const auto& element : coding) {
        switch (element) {
            case 'A':
              dna_template_3_ += "T";
              mrna_sequence_5_ += "U";
              break;
            case 'T':
              dna_template_3_ += "A";
              mrna_sequence_5_ += "A";
              break;
            case 'C':
              dna_template_3_ += "G";
              mrna_sequence_5_ += "G";
              break;
            case 'G':
              dna_template_3_ += "C";
              mrna_sequence_5_ += "C";
              break;
            default:
              std::cout << "Error in sequence\n";
              return false;
        }
    }
    std::string current_codon{""}; //holds the bases in each codon
    int loop_count{0};
    dna_template_5_ = ReverseDirectionality(dna_template_3_);
    dna_coding_3_ = ReverseDirectionality(dna_coding_5_);
    mrna_sequence_3_ = ReverseDirectionality(mrna_sequence_5_);
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
    CalculateLengthyAminoAcids();
    if (loop_count % 3 != 0) {
      enough_bases_ = false;
    } else {
      enough_bases_ = true;
    }
    return true;
}

bool Strand::SetCoding3(std::string coding) {
  return SetCoding5(ReverseDirectionality(coding));
}

bool Strand::SetMRNA5(std::string mrna) {
    mrna_sequence_5_ = mrna;
    dna_coding_5_ = "";
    dna_coding_3_ = "";
    dna_template_5_ = "";
    dna_template_3_ = "";
    for (const auto& element : mrna) {
        switch (element) {
            case 'A':
              dna_template_3_ += "T";
              dna_coding_5_ += "A";
              break;
            case 'U':
              dna_template_3_ += "A";
              dna_coding_5_ += "T";
              break;
            case 'C':
              dna_template_3_ += "G";
              dna_coding_5_ += "C";
              break;
            case 'G':
              dna_template_3_ += "C";
              dna_coding_5_ += "G";
              break;
            default:
              std::cout << "Error in sequence\n";
              return false;
        }
    }
    std::string current_codon{""}; //holds the bases in each codon
    int loop_count{0};
    dna_template_5_ = ReverseDirectionality(dna_template_3_);
    dna_coding_3_ = ReverseDirectionality(dna_coding_5_);
    mrna_sequence_3_ = ReverseDirectionality(mrna_sequence_5_);
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
    CalculateLengthyAminoAcids();
    if (loop_count % 3 != 0) {
      enough_bases_ = false;
    } else {
      enough_bases_ = true;
    }
    return true;
}

bool Strand::SetAminoAcidSequence(std::string amino_acid_sequence) {
    std::cout << "code to be added later";
    return false;
}