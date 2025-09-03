
#include "inner.h"
#include "randombytes.h"

int main() {
  sampler_context spc;

  unsigned char seed[48];
  inner_shake256_context sc;

  randombytes(seed, sizeof seed);
  inner_shake256_init(&sc);
  inner_shake256_inject(&sc, seed, sizeof seed);
  inner_shake256_flip(&sc);

  int logn = 9;
  spc.sigma_min = fpr_sigma_min[logn];
  PQCLEAN_FALCON512_CLEAN_prng_init(&spc.p, &sc);
}
