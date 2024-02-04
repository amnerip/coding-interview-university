#include <stdint.h>

typedef struct vector_item {
  int32_t value;
} vector_item;

typedef struct vector {
  int size;
  int capacity;

  // This means that at the and of this struct there's a contiguous
  // range of memory that holds 'struct vector_item's
  vector_item items[];
} vector;
