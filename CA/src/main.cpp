/*
 * Hugo fernández Solís.
 */

#include <array>

#include "CAcipher.h"

/*
 * Programa de prueba del chacha20.
 */
int main(void) {
  CAcipher aux({2, 6});
  std::vector<uint8_t> result = aux.cipher(13);
  std::cout << "Result: {";
  for (const uint& bit : result) {
    std::cout << bit << ", ";
  }
  std::cout << "\b\b}" << std::endl;
}