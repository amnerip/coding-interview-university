#include <stdint.h>

// mutable array with automatic resizing

// typedef struct vector_item {
//   int32_t value;
// } vector_item;

typedef struct in_memory_vector {
  int32_t size;
  int32_t capacity;

  // This means that at the and of this struct there's a contiguous
  // range of memory that holds 'struct vector_item's
  int32_t items[10];
} in_memory_vector;

#define VECTOR_INIT_CAPACITY 4
typedef struct _vector {
  int32_t _size;
  int32_t _capacity;

  // p1->p2->val
  int32_t* _items;
} vector;

void vector_init(vector* v);
void vector_free(vector* v);
void _vector_resize(vector* v);

void vector_set(vector* v, int32_t idx, int32_t value);
int32_t vector_get(vector* v, int32_t idx);
void vector_push(vector* v, int32_t val);
void vector_remove(vector* v, int32_t idx);

int32_t vector_size(vector *v);
int32_t vector_capacity(vector *v);
int vector_is_empty(vector *v);

