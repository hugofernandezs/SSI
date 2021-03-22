/*
 * Hugo fernández Solís.
 */

#include <array>
#include <bitset>
#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>

constexpr uint8_t RDRL_SIZE = 10;


/*
 * Implementa un cifrado chacha20
 */
class CAcipher {
  private:
    std::array<uint8_t, RDRL_SIZE> generator1_;
    std::array<uint8_t, RDRL_SIZE> generator2_;
    std::pair<uint8_t, uint8_t> prn_;
  
  public:
    CAcipher(const std::pair<uint8_t, uint8_t>& newPRN);
    std::vector<uint8_t> cipher(const uint8_t& size);
};
