#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
/*
  this is a helper file for  */




typedef struct {

  uint tape[900];
  int tapePoint;
  int readPoint;

}BfTape;
typedef struct {
  char*buffer;
  size_t len;
} File_buf;
static char *load(char *fileName, char *buffer,size_t buffer_len,int bufferOffSet)
{
  FILE *srcFile = fopen(fileName, "r");
  size_t bufferSize = 1024;

  char * ptr1, *ptr2;
  char inportFile[128];
  while ((getline(&buffer, &bufferSize, srcFile)) > 0) {
    if (strstr(buffer, "load")) {
      ptr1 = strchr(buffer, '\"');
      ptr2 = strchr(ptr1 + 1, '\"');
      strncpy(inportFile, ptr1 + 1, ptr2 - ptr1 - 1);
      FILE *f = fopen(inportFile, "r");
      while (!feof(f)) {


        fread(buffer, buffer_len, 1,f);
        bufferOffSet++;
      }
    }
  }

  return buffer;
}
static int BfFileHandle(BfTape tape, char *buffer,FILE *srcFile){

  while (buffer[tape.readPoint] != '\0') {
    switch (buffer[tape.readPoint]) {
      case '<':
        if (tape.tapePoint == -1) {
          fclose(srcFile);
          printf("you are going to low");
          return -1;
        }else {
          tape.tapePoint--;
        }
        break;
    case '>':
      if (tape.tapePoint == sizeof(tape)) {
        fclose(srcFile);
        printf("you are going to high");
        return -1;
      }else {
        tape.tapePoint++;
      }
      break;
    case '+':
      tape.tape[tape.tapePoint]++;
      break;
    case '-':
      tape.tape[tape.tapePoint]++;
      break;
    case '^':
      printf("%d",tape.tape[tape.tapePoint]);
      break;
    case '~':
      for (int offset=1; tape.tape[tape.tapePoint - offset] != 0;offset++){
        char letter = tape.tape[tape.tapePoint + offset];
      printf("%b",letter);
      }
      printf("\n");
      break;
    case 'e':
      exit(0);
      break;
    case '!':
      if (tape.tape[tape.tapePoint]==1 && tape.tape[tape.tapePoint+= 1]==2) {
        system("ls");
      }
      if (tape.tape[tape.tapePoint]==2 && tape.tape[tape.tapePoint+= 1]==1) {
        system("echo hello,would!");
      }
      break;
    default:
      break;
    }
    tape.readPoint++;
  }
  return 0;
}
typedef struct {
  int readPoint;
  uint tape[900];
  int tapePoint;
}BfSh;
