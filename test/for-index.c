#include <stdio.h>

int main(int argc, char **argv)
{
  int i;

  printf("running loop for(i = 0; i < 10; i++)\n");

  for(i = 0; i < 10; i++) {
    printf("inside loop, i = %d\n", i);
  }

  printf("finished loop, i = %d\n", i);

  return 0;
}
