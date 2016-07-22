#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
  int *sorted;
  int *new_sorted;
  int current;
  int count = 0;
  bool placed_current;

  while (scanf("%d", &current) != EOF) {
    placed_current = false;

    count++;
    new_sorted = malloc(sizeof(int) * count);

    if (! new_sorted) {
      printf("Could not allocate memory\n");
      return 1;
    }

    if (count > 1) {
      for (int i = 0; i < count - 1; i++) {
        if (sorted[i] > current && ! placed_current) {
          new_sorted[i] = current;
          placed_current = true;
        }

        new_sorted[placed_current ? i+1 : i] = sorted[i];
      }
      free(sorted);
    }

    if (! placed_current) {
      new_sorted[count - 1] = current;
    }

    sorted = new_sorted;
    new_sorted = NULL;
  }

  for(int i = 0; i < count; i++) {
    printf("[%d]: %d\n", i, sorted[i]);
  }

  free(sorted);

  return 0;
}
