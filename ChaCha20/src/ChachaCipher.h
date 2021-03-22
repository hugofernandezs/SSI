/*
 * Hugo fernández Solís.
 */

#include <array>
#include <iomanip>
#include <iostream>

#define ROTL(a, b) (((a) << (b)) | ((a) >> (32 - (b))))
#define QR(a, b, c, d) ( \
  a += b, d ^= a, d= ROTL(d, 16),   \
  c += d, b ^= c, b= ROTL(b, 12),   \
  a += b, d ^= a, d= ROTL(d,  8),   \
  c += d, b ^= c, b= ROTL(b,  7))
#define ROUNDS 10


/*
 * Implementa un cifrado chacha20
 */
class ChachaCipher {
  private:
    std::array<uint32_t, 8> keyStream_;     // Almacena la key. 
  
  public:
    ChachaCipher(const std::array<uint32_t, 8>& key);   // Constructor.
    std::array<uint32_t, 16> cipher(void);              // Cifrado.
  
  private:
    std::array<uint32_t, 16> chacha_block(const std::array<uint32_t, 16>& block);   //Algoritmo chacha20.
    void print_block(const std::array<uint32_t, 16>& array);
};
