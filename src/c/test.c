#include <stdio.h>
#include <string.h>

#define TEST(input, output) \
  do { \
    if (test(input, output)) { \
      printf("Error at %s\n", #input); \
      return -1; \
    } \
  } while(0)

void Initialize_Fast_IDCT(void);
void Fast_IDCT(short *block);

int test(const short *input, const short *output) {
  short block[64];

  memcpy(block, input, sizeof(block));
  Fast_IDCT(block);

  return memcmp(block, output, sizeof(block));
}

int main() {
  Initialize_Fast_IDCT();

  short input0[] = {
     23,  -1,  -2,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0
  };

  short output0[] = {
      2,   3,   3,   3,   3,   3,   3,   3,
      2,   3,   3,   3,   3,   3,   3,   3,
      2,   3,   3,   3,   3,   3,   3,   3,
      2,   3,   3,   3,   3,   3,   3,   3,
      2,   3,   3,   3,   3,   3,   3,   3,
      2,   3,   3,   3,   3,   3,   3,   3,
      2,   3,   3,   3,   3,   3,   3,   3,
      2,   3,   3,   3,   3,   3,   3,   3
  };

  TEST(input0, output0);

  short input1[] = {
     13,  -7,   0,   0,   0,   0,   0,   0,
      0,   2,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0
  };

  short output1[] = {
      1,   1,   1,   1,   2,   2,   2,   2,
      1,   1,   1,   1,   2,   2,   2,   2,
      1,   1,   1,   1,   2,   2,   2,   3,
      1,   1,   1,   1,   2,   2,   3,   3,
      0,   1,   1,   1,   2,   2,   3,   3,
      0,   0,   1,   1,   2,   2,   3,   3,
      0,   0,   1,   1,   2,   3,   3,   3,
      0,   0,   1,   1,   2,   3,   3,   3,
  };

  TEST(input1, output1);

  short input2[] = {
   -166,  -7,  -4,  -4,   0,   0,   0,   0,
     -2,   0,   0,   0,   0,   0,   0,   0,
     -2,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0,
      0,   0,   0,   0,   0,   0,   0,   0
  };

  short output2[] = {
    -24, -23, -21, -21, -21, -21, -21, -20,
    -24, -22, -21, -20, -21, -21, -21, -20,
    -23, -22, -21, -20, -20, -21, -20, -20,
    -23, -22, -20, -20, -20, -20, -20, -19,
    -23, -22, -20, -20, -20, -20, -20, -19,
    -23, -22, -20, -20, -20, -20, -20, -19,
    -23, -22, -20, -20, -20, -20, -20, -19,
    -23, -22, -20, -20, -20, -20, -20, -20
  };

  TEST(input2, output2);

  short input3[] = {
   -240,   8, -11,  47,  26,  -6,   0,   5,
     28,  -6,  85,  44,  -4, -25,   5,  16,
     21,   8,  32, -16, -24,   0,  30,  12,
     -2,  18,   0,  -2,   0,   7,   0, -15,
      7,   4,  15, -24,   0,   9,   8,  -6,
      4,   9,   0,  -5,  -6,   0,   0,   0,
     -4,   0,  -6,   0,   0,  10, -10,  -8,
      6,   0,   0,   0,   0,   0,   0,  -8
  };

  short output3[] = {
     21, -10, -26, -61, -43, -17, -22,  -8,
      5, -28, -47, -73, -11, -14, -24, -17,
    -14, -31, -61, -45,  -5, -18, -22, -34,
    -23, -36, -49, -32, -12, -33, -33, -35,
    -30, -39, -53,  -8, -19, -31, -43, -42,
    -41, -43, -50,  -4, -15, -33, -44, -66,
    -40, -38, -21, -14, -17, -26, -46, -52,
    -44, -47,  -9, -12, -30, -33, -38, -37
  };

  TEST(input3, output3);

  printf("All tests passed\n");
  return 0;
}
