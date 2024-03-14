#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "./helper.h"





int parsbf(char *fileName){
    FILE *srcFile;
  srcFile = fopen(fileName, "r");
  char buffer[300000];
  while (!feof(srcFile)) {
    fread(buffer, sizeof(buffer), 1, srcFile);
  }
  BfTape tape = {
    {0},
    0,
    0
  };
  while (buffer[tape.readPoint] != '\0') {
    if (buffer[tape.readPoint] == '<') {
      if (tape.tapePoint == -1) {
        fclose(srcFile);
        printf("you are going to low");
        return -1;
      }else {
        tape.tapePoint--;
      }
    }
    if (buffer[tape.readPoint] == '>') {
      if (tape.tapePoint == sizeof(tape)) {
        fclose(srcFile);
        printf("you are going to high");
        return -1;
      }else {
        tape.tapePoint++;
      }
    }
    if (buffer[tape.readPoint] == '+') {
        tape.tape[tape.tapePoint]++;
    }
    if (buffer[tape.readPoint] == '-') {
        tape.tape[tape.tapePoint]--;
    }
    if (buffer[tape.readPoint] == '^') {
        printf("%d",tape.tape[tape.tapePoint]);
    }
    if (buffer[tape.readPoint] == '~') {
      for (int offset=1; tape.tape[tape.tapePoint - offset] != 0;offset++){
        char letter = tape.tape[tape.tapePoint + offset];
      printf("%c",letter);
      }
      printf("\n");
    }

    if (buffer[tape.readPoint] == 'e') {
      exit(0);
      }
    if (buffer[tape.readPoint] == '!') {
        if (tape.tape[tape.tapePoint]==1 && tape.tape[tape.tapePoint+= 1]==2) {
          system("ls");
        }
        if (tape.tape[tape.tapePoint]==2 && tape.tape[tape.tapePoint+= 1]==1) {
          system("echo hello,would!");
        }
    }
    tape.readPoint++;
  }
  printf("\n");


  fclose(srcFile);
  return 0;
}
