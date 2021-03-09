/*
 * Author:  Hugo Fernández Solís
 * Project: Práctica 2 - Cifrado RC4
 * File:    rc4.cpp - Contains the main function of the assignment.
 * 
 * References:
 *    C++:        https://www.cplusplus.com/reference/
 *    ULL:        https://campusingenieriaytecnologia.ull.es/mod/assign/view.php?id=282127
 *    Wikipedia:  https://en.wikipedia.org/wiki/Vigenère_cipher
 */

#include <iostream>

#include "Rc4Cipher.h"

/*
 * Pide al usuario que introduzca la clave y el mensaje.
 * La 
 */
int main(void) {
  std::string auxString, auxMessage;
	std::cout << "=== PROGRAMA DE ENCRIPTADO DE VIGENERE ===\n\n"
						<< "Inserte la clave: ";
	std::getline(std::cin, auxString);
	
	std::cout << "Inserte el mensaje a cifrar: ";
	std::getline(std::cin, auxMessage);
	std::vector<unsigned> key;
	std::vector<unsigned> message;
	std::string auxData;
	for(const char& data : auxString) {
		if(data != ' ') {
			auxData.push_back(data);
		}
		else {
			key.emplace_back(std::stoi(auxData));
			auxData.clear();
		}
	}
  for(const char& data : auxMessage) {
		if(data != ' ') {
			auxData.push_back(data);
		}
		else {
			message.emplace_back(std::stoi(auxData));
			auxData.clear();
		}
	}

	Rc4Cipher cipher(key);
	std::vector<unsigned> encrypted = cipher.encrypt(message);
	std::vector<unsigned> decrypted = cipher.decrypt(encrypted);

	std::cout << "\nMensaje cifrado: "; 
  for(const unsigned& digit : encrypted) {
    std::cout << digit << ", ";
  }
  std::cout << "\b\b  " << std::endl;
	std::cout << "\nMensaje descifrado: "; 
  for(const unsigned& digit : decrypted) {
    std::cout << (char)digit << ", ";
  }
  std::cout << "\b\b  " << std::endl;
	std::cout << std::endl;
}