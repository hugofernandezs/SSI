/*
 * Author:  Hugo Fernández Solís
 * Project: Práctica 1 - Cifrado de Vigenere
 * File:    VigenereCipher.cpp - Implements a cipher that uses de Vigenere encryption
 *          method. Given a key word it will encrypt and disencrypt any given message.
 * 
 * References:
 *    C++:        https://www.cplusplus.com/reference/
 *    ULL:        https://campusingenieriaytecnologia.ull.es/pluginfile.php/353240/mod_assign/intro/PracticaVigenere.pdf
 *    Wikipedia:  https://en.wikipedia.org/wiki/Vigenère_cipher
 */

#include "VigenereCipher.h"

#include <vector>



/*
 * Default constructor.
 */
VigenereCipher::VigenereCipher(const std::string& newKeyWord): keyWord_(newKeyWord) {
  for(char& letter : keyWord_) {
    letter -= LIMITER;
  }
}


/*
 * Copy constructor.
 */
VigenereCipher::VigenereCipher(const VigenereCipher& copy): keyWord_(copy.key_word()) {
  for(char& letter : keyWord_) {
    letter -= LIMITER;
  }
}


/*
 * Returns a const reference to the key word.
 */
const std::string& VigenereCipher::key_word(void) const {
  return keyWord_;
}


/*
 * Returns a reference to the key word.
 */
std::string& VigenereCipher::key_word(void) {
  return keyWord_;
}


/*
 * Encrypts the passed message.
 */
std::string VigenereCipher::encrypt(const std::string& message) {
  std::string encryptedMessage;
  unsigned count = 0;
  for(const char& letter : message) {
    encryptedMessage.push_back((((letter - LIMITER) + keyWord_[count]) % MODULE) + LIMITER);
    count++;
    count %= keyWord_.size();
  }
  return encryptedMessage;
}


/*
 * Decrypts the passed message.
 */
std::string VigenereCipher::decrypt(const std::string& message) {
  std::string decryptedMessage;
  unsigned count = 0;
  for(const char& letter : message) {
    decryptedMessage.push_back(((((letter - LIMITER) - keyWord_[count]) + 26) % MODULE) + LIMITER);
    count++;
    count %= keyWord_.size();
  }
  return decryptedMessage;
}