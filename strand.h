#ifndef BIO_STRAND_H
#define BIO_STRAND_H

#include <map>
#include <string>

class Strand {
 public:
  bool SetTemplate5(std::string emplate);
  bool SetTemplate3(std::string emplate);
  bool SetCoding5(std::string coding);
  bool SetCoding3(std::string coding);
  bool SetMRNA5(std::string mrna);
  bool SetAminoAcidSequence(std::string amino_acid_sequence);
  void CalculateLengthyAminoAcids();
  std::string GetTemplate5() {return dna_template_5_;};
  std::string GetCoding5() {return dna_coding_5_;};
  std::string GetMRNA5() {return mrna_sequence_5_;};
  std::string GetAminoAcidSequence5() {return amino_acid_sequence_5_;};
  std::string GetLengthyAminoAcids() {return lengthy_amino_acids_;};
  bool GetEnoughBases() {return enough_bases_;};
  std::string ReverseDirectionality();
  void CalculateAminoAcids5();
  void CalculateAminoAcids3();

 private:
  std::string dna_template_5_;
  std::string dna_coding_5_;
  std::string mrna_sequence_5_;
  std::string amino_acid_sequence_5_;
  std::string lengthy_amino_acids_5_;
  std::string lengthy_amino_acids_3_;
  std::string dna_template_3_;
  std::string dna_coding_3_;
  std::string mrna_sequence_3_;
  std::string amino_acid_sequence_3_;
  bool enough_bases_;
  const std::map<std::string, char> codon_to_amino_acid_{
    {"UUU", 'F'}, {"UUC", 'F'}, {"UUA", 'L'}, {"UUG", 'L'},
    {"UCU", 'S'}, {"UCC", 'S'}, {"UCA", 'S'}, {"UCG", 'S'},
    {"UAU", 'Y'}, {"UAC", 'Y'}, {"UAA", 'X'}, {"UAG", 'X'},
    {"UGU", 'C'}, {"UGC", 'C'}, {"UGA", 'X'}, {"UGG", 'W'},
    {"CUU", 'L'}, {"CUC", 'L'}, {"CUA", 'L'}, {"CUG", 'L'},
    {"CCU", 'P'}, {"CCC", 'P'}, {"CCA", 'P'}, {"CCG", 'P'},
    {"CAU", 'H'}, {"CAC", 'H'}, {"CAA", 'Q'}, {"CAG", 'Q'},
    {"CGU", 'R'}, {"CGC", 'R'}, {"CGA", 'R'}, {"CGG", 'R'},
    {"AUU", 'I'}, {"AUC", 'I'}, {"AUA", 'I'}, {"AUG", 'M'},
    {"ACU", 'T'}, {"ACC", 'T'}, {"ACA", 'T'}, {"ACG", 'T'},
    {"AAU", 'N'}, {"AAC", 'N'}, {"AAA", 'K'}, {"AAG", 'K'},
    {"AGU", 'S'}, {"AGC", 'S'}, {"AGA", 'R'}, {"AGG", 'R'},
    {"GUU", 'V'}, {"GUC", 'V'}, {"GUA", 'V'}, {"GUG", 'V'},
    {"GCU", 'A'}, {"GCC", 'A'}, {"GCA", 'A'}, {"GCG", 'A'},
    {"GAU", 'D'}, {"GAC", 'D'}, {"GAA", 'E'}, {"GAG", 'E'},
    {"GGU", 'G'}, {"GGC", 'G'}, {"GGA", 'G'}, {"GGG", 'G'}
  };
  const std::map<char, std::string> amino_acid_char_to_string_{
    {'A', "Ala"}, {'R', "Arg"}, {'N', "Asn"}, {'D', "Asp"},
    {'C', "Cys"}, {'E', "Glu"}, {'Q', "Gln"}, {'G', "Gly"},
    {'H', "His"}, {'I', "Ile"}, {'L', "Leu"}, {'K', "Lys"},
    {'M', "Met"}, {'F', "Phe"}, {'P', "Pro"}, {'S', "Ser"},
    {'T', "Thr"}, {'W', "Trp"}, {'Y', "Tyr"}, {'V', "Val"},
    {'X', "STOP"}
  };
};

#endif