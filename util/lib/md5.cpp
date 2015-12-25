#include <cstring>
#include <cstdio>
#include "md5.hpp"

#define F(x, y, z) (z ^ ( x & (y ^ z) ))
#define G(x, y, z) (y ^ ( z & (y ^ x) ))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))
#define LEFTROTATE(x, c) (((x) << (c)) | ((x) >> (32 - (c))))
#define FF(a, b, c, d, x, s, ac) {                  \
    (a) += F((b), (c), (d)) + (x) + (uint32_t)(ac); \
    (a) = LEFTROTATE((a), (s));                     \
    (a) += (b);                                     \
  }
#define GG(a, b, c, d, x, s, ac) {                  \
    (a) += G((b), (c), (d)) + (x) + (uint32_t)(ac); \
    (a) = LEFTROTATE((a), (s));                     \
    (a) += (b);                                     \
  }
#define HH(a, b, c, d, x, s, ac) {                  \
    (a) += H((b), (c), (d)) + (x) + (uint32_t)(ac); \
    (a) = LEFTROTATE((a), (s));                     \
    (a) += (b);                                     \
  }
#define II(a, b, c, d, x, s, ac) {                  \
    (a) += I((b), (c), (d)) + (x) + (uint32_t)(ac); \
    (a) = LEFTROTATE((a), (s));                     \
    (a) += (b);                                     \
  }

void to_bytes(uint32_t val, uint8_t* bytes) {
  bytes[0] = (uint8_t) val;
  bytes[1] = (uint8_t) (val >> 8);
  bytes[2] = (uint8_t) (val >> 16);
  bytes[3] = (uint8_t) (val >> 24);
}

md5sum_t md5 (uint8_t* msg, size_t initial_len) {
  uint32_t h0 = 0x67452301, h1 = 0xefcdab89, h2 = 0x98badcfe, h3 = 0x10325476;
  size_t new_len = initial_len + 1;
  int mod = new_len & 0x3F;
  new_len += (mod > 56) ? 120 - mod : 56 - mod;
  msg[initial_len] = 0x80;
  memset(&msg[initial_len + 1], 0, sizeof(uint8_t) * (new_len - (initial_len + 1)));
  to_bytes(initial_len<<3, msg + new_len);
  to_bytes(initial_len >> 29, msg + new_len + 4);
  static uint32_t w[16];
  for(size_t offset=0; offset<new_len; offset += 64) {
    for (int i = 0; i < 16; ++i)
      w[i] = *((uint32_t*)(msg + offset + (i<<2)));
    uint32_t a = h0, b = h1, c = h2, d = h3;
    FF(a, b, c, d, w[ 0],  7, 0xD76AA478);
    FF(d, a, b, c, w[ 1], 12, 0xE8C7B756);
    FF(c, d, a, b, w[ 2], 17, 0x242070DB);
    FF(b, c, d, a, w[ 3], 22, 0xC1BDCEEE);
    FF(a, b, c, d, w[ 4],  7, 0xF57C0FAF);
    FF(d, a, b, c, w[ 5], 12, 0x4787C62A);
    FF(c, d, a, b, w[ 6], 17, 0xA8304613);
    FF(b, c, d, a, w[ 7], 22, 0xFD469501);
    FF(a, b, c, d, w[ 8],  7, 0x698098D8);
    FF(d, a, b, c, w[ 9], 12, 0x8B44F7AF);
    FF(c, d, a, b, w[10], 17, 0xFFFF5BB1);
    FF(b, c, d, a, w[11], 22, 0x895CD7BE);
    FF(a, b, c, d, w[12],  7, 0x6B901122);
    FF(d, a, b, c, w[13], 12, 0xFD987193);
    FF(c, d, a, b, w[14], 17, 0xA679438E);
    FF(b, c, d, a, w[15], 22, 0x49B40821);
    GG(a, b, c, d, w[ 1],  5, 0xF61E2562);
    GG(d, a, b, c, w[ 6],  9, 0xC040B340);
    GG(c, d, a, b, w[11], 14, 0x265E5A51);
    GG(b, c, d, a, w[ 0], 20, 0xE9B6C7AA);
    GG(a, b, c, d, w[ 5],  5, 0xD62F105D);
    GG(d, a, b, c, w[10],  9, 0x02441453);
    GG(c, d, a, b, w[15], 14, 0xD8A1E681);
    GG(b, c, d, a, w[ 4], 20, 0xE7D3FBC8);
    GG(a, b, c, d, w[ 9],  5, 0x21E1CDE6);
    GG(d, a, b, c, w[14],  9, 0xC33707D6);
    GG(c, d, a, b, w[ 3], 14, 0xF4D50D87);
    GG(b, c, d, a, w[ 8], 20, 0x455A14ED);
    GG(a, b, c, d, w[13],  5, 0xA9E3E905);
    GG(d, a, b, c, w[ 2],  9, 0xFCEFA3F8);
    GG(c, d, a, b, w[ 7], 14, 0x676F02D9);
    GG(b, c, d, a, w[12], 20, 0x8D2A4C8A);
    HH(a, b, c, d, w[ 5],  4, 0xFFFA3942);
    HH(d, a, b, c, w[ 8], 11, 0x8771F681);
    HH(c, d, a, b, w[11], 16, 0x6D9D6122);
    HH(b, c, d, a, w[14], 23, 0xFDE5380C);
    HH(a, b, c, d, w[ 1],  4, 0xA4BEEA44);
    HH(d, a, b, c, w[ 4], 11, 0x4BDECFA9);
    HH(c, d, a, b, w[ 7], 16, 0xF6BB4B60);
    HH(b, c, d, a, w[10], 23, 0xBEBFBC70);
    HH(a, b, c, d, w[13],  4, 0x289B7EC6);
    HH(d, a, b, c, w[ 0], 11, 0xEAA127FA);
    HH(c, d, a, b, w[ 3], 16, 0xD4EF3085);
    HH(b, c, d, a, w[ 6], 23, 0x04881D05);
    HH(a, b, c, d, w[ 9],  4, 0xD9D4D039);
    HH(d, a, b, c, w[12], 11, 0xE6DB99E5);
    HH(c, d, a, b, w[15], 16, 0x1FA27CF8);
    HH(b, c, d, a, w[ 2], 23, 0xC4AC5665);
    II(a, b, c, d, w[ 0],  6, 0xF4292244);
    II(d, a, b, c, w[ 7], 10, 0x432AFF97);
    II(c, d, a, b, w[14], 15, 0xAB9423A7);
    II(b, c, d, a, w[ 5], 21, 0xFC93A039);
    II(a, b, c, d, w[12],  6, 0x655B59C3);
    II(d, a, b, c, w[ 3], 10, 0x8F0CCC92);
    II(c, d, a, b, w[10], 15, 0xFFEFF47D);
    II(b, c, d, a, w[ 1], 21, 0x85845DD1);
    II(a, b, c, d, w[ 8],  6, 0x6FA87E4F);
    II(d, a, b, c, w[15], 10, 0xFE2CE6E0);
    II(c, d, a, b, w[ 6], 15, 0xA3014314);
    II(b, c, d, a, w[13], 21, 0x4E0811A1);
    II(a, b, c, d, w[ 4],  6, 0xF7537E82);
    II(d, a, b, c, w[11], 10, 0xBD3AF235);
    II(c, d, a, b, w[ 2], 15, 0x2AD7D2BB);
    II(b, c, d, a, w[ 9], 21, 0xEB86D391);
    h0 += a, h1 += b, h2 += c, h3 += d;
  }
  return std::move (md5sum_t {{h0, h1, h2, h3}});
}
