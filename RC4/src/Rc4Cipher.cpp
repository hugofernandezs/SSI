/*
 * Author:  Hugo Fernández Solís
 * Project: Práctica 2 - Cifrado RC4
 * File:    Rc4Cipher.cpp - Implements the cipher.
 * 
 * References:
 *    C++:        https://www.cplusplus.com/reference/
 *    ULL:        https://campusingenieriaytecnologia.ull.es/mod/assign/view.php?id=282127
 *    Wikipedia:  https://en.wikipedia.org/wiki/Vigenère_cipher
 */

#include "Rc4Cipher.h"

#include <vector>



/*
 * Constructor por defecto.
 * Inicializa el atributo sBox_ con valores 0-155.
 * Inicializa el atributo kBox_ repitiendo la semilla hasta completar el array.
 * Llamamos a los métodos KSA y PRGA consecutivamente.
 */
Rc4Cipher::Rc4Cipher(const std::vector<unsigned>& seed) {
  for(unsigned i = 0; i < 256; i++) {
    sBox_[i] = i;
    kBox_[i] = seed[i % seed.size()];
  }
  KSA();
  PRGA();
}


/*
 * Encripta el mensaje.
 * El resultado se almacenará en un vector.
 */
std::vector<unsigned> Rc4Cipher::encrypt(const std::vector<unsigned>& message) {
  std::vector<unsigned> encryptedMessage;
  for(unsigned i = 0; i < message.size(); i++) {
    encryptedMessage.emplace_back(keyStream_[i % 256] ^ message[i]);
  }
  return encryptedMessage;
}


/*
 * Desencripta el mensaje.
 * El resultado se almacenará en un vector.
 */
std::vector<unsigned> Rc4Cipher::decrypt(const std::vector<unsigned>& message) {
  std::vector<unsigned> decryptedMessage;
  for(unsigned i = 0; i < message.size(); i++) {
    decryptedMessage.emplace_back(keyStream_[i % 256] ^ message[i]);
  }
  return decryptedMessage;
}


/*
 * KSA algorithm.
 */
void Rc4Cipher::KSA(void) {
  unsigned j = 0;
  for(unsigned i = 0; i < 256; i++) {
    j = (j + sBox_[i] + kBox_[i]) % 256;
    std::swap(sBox_[i], sBox_[j]);
  }
}


/*
 * PRGA algorithm.
 */
void Rc4Cipher::PRGA(void) {
  unsigned i = 0, j = 0;
  for (unsigned k = 0; k < 256; k++) {
    i = (i + 1) % 256;
    j = (j + sBox_[i]) % 256;
    std::swap(sBox_[i], sBox_[j]);
    keyStream_.emplace_back(sBox_[(sBox_[i] + sBox_[j]) % 256]);
  }
}