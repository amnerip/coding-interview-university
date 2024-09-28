#include "./vector.h"
#include <stdlib.h>

void vector_init(vector* v) {
  v->_size = 0;
  v->_capacity = VECTOR_INIT_CAPACITY;

  v->_items = malloc(sizeof(int32_t) * v->_capacity);
}

void vector_free(vector* v) {
  free(v->_items);
}

void vector_set(vector* v, int32_t idx, int32_t val) {
  if (idx < 0 || idx >= v->_size) {
    return;
  }
  v->_items[idx] = val;
}
int32_t vector_get(vector* v, int32_t idx) {
  if (idx < 0 || idx >= v->_size) {
    return -1;
  }

  return v->_items[idx];
}

void vector_push(vector* v, int32_t val) {
  if (v->_capacity == v->_size) {
    _vector_resize(v);
  } 
  v->_items[v->_size] = val;
  v->_size += 1;
}

void _vector_resize(vector *v) {
  v->_capacity = v->_capacity * 2;
  int32_t* new_items = malloc(sizeof(int32_t)*v->_capacity);
  for (int i = 0; i < v->_size; i++) {
    new_items[i] = v->_items[i];
  }
  free(v->_items);
  v->_items = new_items;
}

void vector_remove(vector* v, int32_t idx) {
  for (int i = idx+1; i < v->_size; i++) {
    v->_items[i-1] = v->_items[i];
  }
  v->_size -= 1;
}

int32_t vector_size(vector *v) {
  return v->_size;
}


int32_t vector_capacity(vector *v) {
  return v->_capacity;
}

int vector_is_empty(vector *v) {
  return v->_size == 0;
}
