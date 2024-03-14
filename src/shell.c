#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "./helper.h"


int bfsh(){
  BfSh tape = {
    0,
    {0},
    0,
  };
  char command[1000];
  while (true) {
    printf("bfsh: ");
    scanf("%s",command);
    for (tape.readPoint = 0 ; command[tape.readPoint] != '\0';tape.readPoint++) {

    if (command[tape.readPoint] == '<') {
      if (tape.tapePoint == -1) {
        printf("you are going to low");
        return -1;
      }else {
        tape.tapePoint--;
      }
    }
    if (command[tape.readPoint] == '>') {
      if (tape.tapePoint == sizeof(tape.tape)+1) {
        printf("you are going to high");
        return -1;
      }else {
        tape.tapePoint++;
      }
    }
    if (command[tape.readPoint] == '+') {
        tape.tape[tape.tapePoint]++;
    }
    if (command[tape.readPoint] == '-') {
        tape.tape[tape.tapePoint]--;
    }
    if (command[tape.readPoint] == '^') {
        printf("%d\n",tape.tape[tape.tapePoint]);

    }
    if (command[tape.readPoint] == '~') {
      for (int offset=1; tape.tape[tape.tapePoint - offset] != 0;offset++){
      printf("%d",tape.tape[tape.tapePoint + offset]);
      }
      printf("\n");
    }
    if (command[tape.readPoint] == 'e') {
      exit(0);
      }
    }
    if (command[tape.readPoint] == '!') {
        if (tape.tape[tape.tapePoint]==1) {
          system("ls");
        }
        if (tape.tape[tape.tapePoint]==2) {
          system("echo hello,would!");
        }
    }
  }
return 0;

}
