#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>


int8_t errorflag = 0;
FILE *srcFile;
int main(int argc, char *argv[]) {
  if (argv[1] == NULL) {
  int readPoint =0;
  uint tape[900] ={0};
  int tapePoint =0;
  char command[1000];
  while (command[readPoint--] != 'e') {
    printf("bfsh: ");
    scanf("%s",command);
    for (readPoint = 0 ; command[readPoint] != '\0';readPoint++) {

    if (command[readPoint] == '<') {
      if (tapePoint != -1) {
        fclose(srcFile);
        printf("you are going to low");
        errorflag = -1;
        return errorflag;
      }else {
        tapePoint--;
      }
    }
    if (command[readPoint] == '>') {
      if (tapePoint == sizeof(tape)) {
        fclose(srcFile);
        printf("you are going to high");
        errorflag = -1;
        return errorflag;
      }else {
        tapePoint++;
      }
    }
    if (command[readPoint] == '+') {
        tape[tapePoint]++;
    }
    if (command[readPoint] == '^') {
        printf("%d\n",tape[tapePoint]);

    }
    if (command[readPoint] == '!') {
        if (tape[tapePoint]==1) {
          system("ls");
        }
        if (tape[tapePoint]==2) {
          system("echo hello,would!");
        }
    }
  }
}
  }
  else {

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
}
