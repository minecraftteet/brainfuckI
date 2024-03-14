#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "./helper.h"




int bfsh(){
  int readPoint =0;
  uint tape[900] ={0};
  int tapePoint =0;
  char command[1000];
  while (true) {
    printf("bfsh: ");
    scanf("%s",command);
    for (readPoint = 0 ; command[readPoint] != '\0';readPoint++) {

    if (command[readPoint] == '<') {
      if (tapePoint == -1) {
        printf("you are going to low");
        return -1;
      }else {
        tapePoint--;
      }
    }
    if (command[readPoint] == '>') {
      if (tapePoint == sizeof(tape)) {
        printf("you are going to high");
        return -1;
      }else {
        tapePoint++;
      }
    }
    if (command[readPoint] == '+') {
        tape[tapePoint]++;
    }
    if (command[readPoint] == '-') {
        tape[tapePoint]--;
    }
    if (command[readPoint] == '^') {
        printf("%d\n",tape[tapePoint]);

    }
    if (command[readPoint] == '~') {
      for (int offset=1; tape[tapePoint - offset] != 0;offset++){
      printf("%d",tape[tapePoint + offset]);
      }
      printf("\n");
    }
    if (command[readPoint] == 'e') {
      exit(0);
      }
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
return 0;

}
