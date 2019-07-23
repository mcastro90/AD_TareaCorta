#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
  int i;
  int a[10];
  for (i = 0; i < 9; i++)
    a[i] = i;
    
  for (i = 0; i < 10; i++){
    printf("%d %d", a[i], i);
  }
  printf("\n");
  return 0;
}
