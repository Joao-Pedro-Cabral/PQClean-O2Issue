
#include <stdint.h>
#include <stdio.h>

int main() {
  uint8_t tmp[56];
  uint32_t d32[14];
  for (int i = 0; i < 56; i ++) {
      tmp[i] = 37*i;
  }
  // The issue happens in this loop
  for (int i = 0; i < 14; i ++) {
      uint32_t w;
      w = (uint32_t)tmp[(i << 2) + 0]
          | ((uint32_t)tmp[(i << 2) + 1] << 8)
          | ((uint32_t)tmp[(i << 2) + 2] << 16)
          | ((uint32_t)tmp[(i << 2) + 3] << 24);
      d32[i] = w;
  }
  for (int i = 0; i < 14; i ++) {
      printf("%d\n", d32[i]);
  }
  return 0;
}
