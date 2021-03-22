/*
 * Hugo fernández Solís
 */

#include "CAcipher.h"


CAcipher::CAcipher(const std::pair<uint8_t, uint8_t>& newPRN): prn_(newPRN) {
  for(uint8_t i = 0; i < 10; i++) {
    generator1_[i] = 1;
    generator2_[i] = 1;
  }
}


std::vector<uint8_t> CAcipher::cipher(const uint8_t& size) {
  std::vector<uint8_t> result;
  for(uint8_t i = 0; i < size; i++) {
    uint8_t generatorBit1 = generator1_[2] ^ generator1_[9];
    uint8_t generatorBit2 = generator2_[1] ^ generator2_[2] ^ generator2_[5] ^ generator2_[7] ^ generator2_[8] ^ generator2_[9];
    uint8_t prnBit = generator2_[prn_.first] ^ generator1_[prn_.second];
    result.emplace_back(uint8_t(prnBit ^ generator1_[9]));
    for(uint8_t j = RDRL_SIZE - 1; j > 0; j--) {
      generator1_[j] = generator1_[j - 1];
      generator2_[j] = generator2_[j - 1];
    }
    generator1_[0] = generatorBit1;
    generator2_[0] = generatorBit2;
  }
  return result;
}