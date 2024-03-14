#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "./helper.h"




int8_t errorflag = 0;

int bfsh();

int parsbf(char *fileName);

int main(int argc, char *argv[]) {
  if (argv[1] == NULL) {
    bfsh();
  }
  else {
    parsbf(argv[1]);
  }
  return 0;
}
