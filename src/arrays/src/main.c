#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "./vector.h"


int main(int argc, char *argv[]) {
  vector v;
  vector_init(&v);

  printf("New vector with capacity %d has %d items\n", vector_capacity(&v), vector_size(&v));
  for (int32_t i = 0; i < 16; i++) {
    vector_push(&v, i);
  }

  for (int32_t i = 0; i < 16; i++) {
    printf("%d\n", vector_get(&v, i));
  }
  vector_free(&v);
  return EXIT_SUCCESS;
}
