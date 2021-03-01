/*
 * Author:  Hugo Fernández Solís
 * Project: Práctica 1 - Cifrado de Vigenere
 * File:    VigenereCipher.h - Implements a cipher that uses de Vigenere encryption
 *          method. Given a key word it will encrypt and disencrypt any given message.
 * 
 * References:
 *    C++:        https://www.cplusplus.com/reference/
 *    ULL:        https://campusingenieriaytecnologia.ull.es/pluginfile.php/353240/mod_assign/intro/PracticaVigenere.pdf
 *    Wikipedia:  https://en.wikipedia.org/wiki/Vigenère_cipher
 */

#pragma once

#include <string>


constexpr unsigned MODULE = 26;
constexpr char LIMITER = 'a';


/*
 * Vigenere cipher.
 */
class VigenereCipher {
  private:
    std::string keyWord_;     // Key word to cipher the message.

  public:
    VigenereCipher(const std::string& newKeyWord = {});   // Default constructor.
    VigenereCipher(const VigenereCipher& copy);           // Copy constructor.

    const std::string& key_word(void) const;    // Returns a const reference to the key word.
    std::string& key_word(void);                // Returns a reference to the key word.

    std::string encrypt(const std::string& message);    // Encrypts the passed message.
    std::string decrypt(const std::string& message);    // Decrypts the passed message.
};