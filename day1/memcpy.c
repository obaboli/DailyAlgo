// implentation of memcpy that has safeguards of memmove for overlapping memory

#include <stdint.h>
#include <stdio.h>
#include <string.h>

void *my_memcpy(void *dest, const void *src, size_t n) {
  uint8_t *destTemp = dest;
  const uint8_t *srcTemp = src;

  if (dest == NULL || src == NULL) {
    printf("ERROR: NULL pointer\n");
    return NULL;
  }

  if (dest > src) {
    while (n > 0) {
      n--;
      destTemp[n] = srcTemp[n];
    }
  } else {
    while (n > 0) {
      *destTemp++ = *srcTemp++;
      n--;
    }
  }

  return dest;
}

int main() {
  int test[50] = {0};
  size_t size = sizeof(test) / sizeof(*test);

  for (size_t i = 0; i < size; i++) {
    test[i] = i;
  }

  int other[50] = {[0 ... 49] = 1};

  // dest > src
  for (size_t i = 0; i < size; i++) {
    printf("%d ", other[i]);
  }
  printf("\n");

  my_memcpy(other, test, 50 * sizeof(int));

  for (size_t i = 0; i < size; i++) {
    printf("%d ", other[i]);
  }
  printf("\n\n");

  // src > dest
  for (size_t i = 0; i < 10; i++) {
    printf("%d ", test[i]);
  }
  printf("\n");

  my_memcpy(test, test + 1, 10 * sizeof(int));

  for (size_t i = 0; i < 10; i++) {
    printf("%d ", test[i]);
  }
  printf("\n");

  return 0;
}
