#include <stdio.h>
#include <stdint.h>

void print_binary(uint16_t num);
uint16_t rotl (uint16_t num, int k);
uint16_t rotr (uint16_t num, int k);
uint16_t pack (uint16_t num);
struct Words unpack (uint16_t num);

// name idea: 1 WORD = 2 Byte
struct Words {
  unsigned int a : 1;
  unsigned int b : 1;
  unsigned int c : 1;
  unsigned int d : 3; // max_val = 8
  unsigned int e : 5; // max_val = 32;
  unsigned int f : 5; // max_val = 32;
} word;

int main() {
  uint16_t num = 19878;
  uint16_t test_num;
  int k = 7;
  struct Words test_word;

  print_binary(num);

  test_num = rotl(num, k);
  print_binary(test_num);

  test_num = rotr(num, k);
  print_binary(test_num);

  test_num = pack(num);
  print_binary(test_num);
  
  test_word = unpack(num);
  printf("%d %d %d %d %d %d\n", test_word.a, test_word.b, test_word.c
                              , test_word.d, test_word.e, test_word.f);

  return 0;
}

void print_binary(uint16_t num) {
  char buffer[17];
  buffer[16] = '\0';

  for (int i = 15; i >= 0; --i) {
    buffer[i] = '0' + (num & 1);
    num >>= 1;    // num = num >> 1
  }

  printf("%s\n", buffer);

  return;
}

uint16_t rotl (uint16_t num, int k) {
  return (num << k) | (num >> (16-k));
}

uint16_t rotr (uint16_t num, int k) {
  return (num >> k) | (num << (16-k));
}

uint16_t getBits (int n) {
  return ((1 << n) - 1);
}

// fragmentate bits, save it to corresponding struct member and return it
struct Words unpack (uint16_t num) {
  unsigned int extracted;

  extracted = getBits(1) & rotr(num, 1-1) ;
  word.a = extracted;

  extracted = getBits(1) & rotr(num, 2-1) ;
  word.b = extracted;

  extracted = getBits(1) & rotr(num, 3-1) ;
  word.c = extracted;

  extracted = getBits(3) & rotr(num, 4-1) ;
  word.d = extracted;

  extracted = getBits(5) & rotr(num, 7-1) ;
  word.e = extracted;

  extracted = getBits(5) & rotr(num, 12-1) ;
  word.f = extracted;

  return word;
}

uint16_t pack (uint16_t num) {
  uint16_t result;

  unpack(num);
  // concatenate struct values to one uint16_t number
  result = rotl(word.a, 15) | rotl(word.b, 14) | rotl(word.c, 13)
         | rotl(word.d, 10) | rotl(word.e, 5) | rotl(word.f, 0);

  return result;
}
