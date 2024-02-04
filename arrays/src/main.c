#include <stdio.h>
#include <stdlib.h>

#include "./vector.h"


int main(int argc, char *argv[]) {
  vector v = {0, 10};

  printf("&v = %p, capacity: %d\n", &v, v.capacity);

  for (int i = 0; i < v.size; i++) {
    printf("%d", v.items[i].value);
  }
  return EXIT_SUCCESS;
}
