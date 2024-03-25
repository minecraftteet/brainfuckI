#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "./helper.h"





int parsbf(char *fileName){
  FILE *srcFile;
  int buffer_len = 300000;
  srcFile = fopen(fileName, "r");
  char *buffer = malloc(buffer_len);

  while (!feof(srcFile)) {

    fread(buffer, buffer_len, 1, srcFile);

  }
  BfTape tape = {
    {0},
    0,
    0
  };

  BfFileHandle(tape,buffer,srcFile);
  printf("\n");

  free(buffer);
  fclose(srcFile);
  return 0;
}
