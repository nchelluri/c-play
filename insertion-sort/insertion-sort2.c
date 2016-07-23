#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100000

int main(int argc, char *argv[])
{
  int vals[MAX_ITEMS + 1];
  int count = 0;
  int current;
  int currentIndex;

  while (count < MAX_ITEMS && scanf("%d", &current) != EOF) {
    for (currentIndex = 0; currentIndex < count; currentIndex++) {
      if (vals[currentIndex] > current) {
        break;
      }
    }

    for(int i = count; i > currentIndex; i--) {
      vals[i] = vals[i - 1];
    }

    vals[currentIndex] = current;

    count++;
  }

  for (int i = 0; i < count; i++) {
    printf("[%d]: %d\n", i, vals[i]);
  }

  return 0;
}
