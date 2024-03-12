#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>


int8_t errorflag = 0;
FILE *srcFile;
int main(int argc, char *argv[]) {
  if (argv[1] == NULL) {
    errorflag = -1;
    printf("you must have a file as a arg\n");
    return errorflag;
  }
  srcFile = fopen(argv[1], "r");
  char buffer[300000];
  while (!feof(srcFile)) {
    fread(buffer, sizeof(buffer), 1, srcFile);
  }
  uint tape[900] ={0};
  int tapePoint =0;
  int readPoint =0;
  while (buffer[readPoint] != '\0') {
    if (buffer[readPoint] == '<') {
      if (tapePoint == -1) {
        fclose(srcFile);
        printf("you are going to low");
        errorflag = -1;
        return errorflag;
      }else {
        tapePoint--;
      }
    }
    if (buffer[readPoint] == '>') {
      if (tapePoint == sizeof(tape)) {
        fclose(srcFile);
        printf("you are going to high");
        errorflag = -1;
        return errorflag;
      }else {
        tapePoint++;
      }
    }
    if (buffer[readPoint] == '+') {
        tape[tapePoint]++;
    }
    if (buffer[readPoint] == '^') {
        printf("%d",tape[tapePoint]);
    }
    if (buffer[readPoint] == '!') {
        if (tape[tapePoint]==1) {
          system("ls");
        }
        if (tape[tapePoint]==2) {
          system("echo hello,would!");
        }
    }
    readPoint++;
  }
  printf("\n");


  fclose(srcFile);
  return errorflag;
}
