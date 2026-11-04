#ifndef BIO_STRAND_H
#define BIO_STRAND_H

#include <string>

class Strand {
 public:
  void SetTemplate(std::string emplate);
  void SetCoding(std::string coding);
  void SetMRNA(std::string mrna);
  void SetAminoAcidSequence(std::string amino_acid_sequence);
  std::string GetTemplate() {return dna_template_;};
  std::string GetCoding() {return dna_coding_;};
  std::string GetMRNA() {return mrna_sequence_;};
  std::string GetAminoAcidSequence() {return "Placeholder";};
 private:
  std::string dna_template_;
  std::string dna_coding_;
  std::string mrna_sequence_;
  std::string amino_acid_sequence_;
};

#endif