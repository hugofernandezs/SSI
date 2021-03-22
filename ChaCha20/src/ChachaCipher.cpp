/*
 * Hugo fernández Solís
 */

#include "ChachaCipher.h"


ChachaCipher::ChachaCipher(const std::array<uint32_t, 8>& key):
keyStream_(key) {}



std::array<uint32_t, 16> ChachaCipher::cipher(void) {
  std::array<uint32_t, 16> initialBlock;
  initialBlock[0] = 0x61707865;
  initialBlock[1] = 0x3320646e;
  initialBlock[2] = 0x79622d32;
  initialBlock[3] = 0x6b206574;
  for(int i = 4; i < 12; i++) {
    initialBlock[i] = keyStream_[i - 4];
  }
  initialBlock[12] = 0x00000001;
  initialBlock[13] = 0x09000000;
  initialBlock[14] = 0x4a000000;
  initialBlock[15] = 0x00000000;
  print_block(initialBlock);

  std::array<uint32_t, 16> chachaBlock = chacha_block(initialBlock);
  print_block(chachaBlock);

  std::array<uint32_t, 16> resultBlock;
  for(size_t i = 0; i < 16; i++) {
    resultBlock[i] = initialBlock[i] + chachaBlock[i];
  }
  print_block(resultBlock);
  return resultBlock;
}



std::array<uint32_t, 16> ChachaCipher::chacha_block(const std::array<uint32_t, 16>& block) {
  std::array<uint32_t, 16> aux = block;

  for(uint32_t i = 0; i < ROUNDS; i++) {
    // Bloque en columnas.
    QR(aux[0], aux[4], aux[ 8], aux[12]);
    QR(aux[1], aux[5], aux[ 9], aux[13]);
    QR(aux[2], aux[6], aux[10], aux[14]);
    QR(aux[3], aux[7], aux[11], aux[15]);
    // Bloque en diagonales.
    QR(aux[0], aux[5], aux[10], aux[15]);
    QR(aux[1], aux[6], aux[11], aux[12]);
    QR(aux[2], aux[7], aux[ 8], aux[13]);
    QR(aux[3], aux[4], aux[ 9], aux[14]);
  }
  return aux;
}



void ChachaCipher::print_block(const std::array<uint32_t, 16>& array) {
  int auxCount = 0;
  std::cout << "\nBloque tras iteraciones: " << std::endl;
  for (const uint32_t& block : array) {
    if(auxCount == 4) {
      std::cout << std::endl;
      auxCount = 0;
    }
    std::cout << std::hex << std::setfill('0') << std::setw(8) << block << "  ";
    auxCount++;
  }
  std::cout << std::endl;
}