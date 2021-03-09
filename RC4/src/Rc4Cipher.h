/*
 * Author:  Hugo Fernández Solís
 * Project: Práctica 2 - Cifrado RC4
 * File:    Rc4Cipher.h - Defines the cipher.
 * 
 * References:
 *    C++:        https://www.cplusplus.com/reference/
 *    ULL:        https://campusingenieriaytecnologia.ull.es/mod/assign/view.php?id=282127
 *    Wikipedia:  https://en.wikipedia.org/wiki/Vigenère_cipher
 */

#pragma once

#include <array>
#include <string>
#include <vector>


/*
 * RC4 cipher.
 */
class Rc4Cipher {
  private:
    std::array<unsigned, 256> sBox_;    // S array.
    std::array<unsigned, 256> kBox_;    // T array.
    std::vector<unsigned> keyStream_;   // Array with the stream key.

  public:
    Rc4Cipher(const std::vector<unsigned>& newKey = {});  // Constructor por defecto.

    std::vector<unsigned> encrypt(const std::vector<unsigned>& message);    // Encrypts the passed message.
    std::vector<unsigned> decrypt(const std::vector<unsigned>& message);    // Decrypts the passed message.
  
  private:
    void KSA(void);   // KSA algorithm
    void PRGA(void);  // PRGA algorithm.
};
