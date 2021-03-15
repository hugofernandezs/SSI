/*
 * Hugo fernández Solís.
 */

#include <array>

#include "ChachaCipher.h"


int main(void) {
  const std::array<uint32_t, 8> key {
    0x03020100,
    0x07060504,
    0x0b0a0908,
    0x0f0e0d0c,
    0x13121110,
    0x17161514,
    0x1b1a1918,
    0x1f1e1d1c
  };

  ChachaCipher cipher(key);
  cipher.cipher();
}