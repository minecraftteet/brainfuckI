#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {

  uint tape[900];
  int tapePoint;
  int readPoint;

}BfTape;
typedef struct {
  int readPoint;
  uint tape[900];
  int tapePoint;
  char command[1000];
}BfSh;
