/*
 * Author:  Hugo Fernández Solís
 * Project: Práctica 1 - Cifrado de Vigenere
 * File:    vigenere.cpp - Contains the main function of the assignment.
 * 
 * References:
 *    C++:        https://www.cplusplus.com/reference/
 *    ULL:        https://campusingenieriaytecnologia.ull.es/pluginfile.php/353240/mod_assign/intro/PracticaVigenere.pdf
 *    Wikipedia:  https://en.wikipedia.org/wiki/Vigenère_cipher
 */

#include <algorithm>
#include <iostream>

#include "VigenereCipher.h"

int main(void) {
	std::string key, message;
	std::cout << "=== PROGRAMA DE ENCRIPTADO DE VIGENERE ===\n\n"
						<< "Inserte la clave: ";
	std::getline(std::cin, key);
	
	std::cout << "Inserte el mensaje a cifrar: ";
	std::getline(std::cin, message);
	message.erase(remove(message.begin(), message.end(), ' '), message.end());

	VigenereCipher cipher(key);
	std::string encrypted = cipher.encrypt(message);
	std::string decrypted = cipher.decrypt(encrypted);

	std::cout << "\nMensaje cifrado: ";
	for(const char& i : encrypted) {
		std::cout << i;
	}
	std::cout << "\nMensaje descifrado: ";
	for(const char& i : decrypted) {
		std::cout << i;
	}
	std::cout << std::endl;
}