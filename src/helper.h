#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_sensor.h>
#include <SDL2/SDL_video.h>
#include <bits/types/FILE.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
/*
  this is a helper file for  */




typedef struct {
  Uint8 tape[900];
  int tapePoint; //the point in the tape
  int readPoint; // point in the file

}BfTape;
typedef struct {
  char*buffer;
  size_t len;
} File_buf;

static char *load(char *fileName, char **buffer)
{
  FILE *srcFile = fopen(fileName, "r");
  size_t buffer_len = 1024;
  size_t bufferSize = 1024;


  char * ptr1, *ptr2;
  char inportFile[128];
  while ((getline(buffer, &bufferSize, srcFile)) > 0) {
    if (strstr(*buffer, "load")) {
      ptr1 = strchr(*buffer, '\"');
      ptr2 = strchr(ptr1 + 1, '\"');
      strncpy(inportFile, ptr1 + 1, ptr2 - ptr1 - 1);
      FILE *f = fopen(inportFile, "r");
      while (!feof(f)) {


        fread(buffer, buffer_len, 1,f);
      }
    }
  }
  return *buffer;
}
typedef struct {
  SDL_Renderer *rend;
  SDL_Window *wend;

}SDLDEF;
static void setupsdl(SDLDEF comp)
{
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_Window *wind = SDL_CreateWindow("brainFuck",0,0,800,600,SDL_WINDOW_BORDERLESS);
  SDL_Renderer *rend = SDL_CreateRenderer(wind,-1,0);
  comp.rend = rend;
  comp.wend = wind;
}
static int BfFileHandle(BfTape tape, char *buffer,FILE *srcFile){
SDLDEF display;
  while (buffer[tape.readPoint] != '\0') {
    switch (buffer[tape.readPoint]) {
    case '[':
      if (tape.tape[tape.tapePoint] == 0) {
        int loopDepth = 1;
        while (loopDepth != 0) {
          tape.readPoint++;
          if (buffer[tape.readPoint] == '[') {
            loopDepth++;
          } else if (buffer[tape.readPoint] == ']') {
            loopDepth--;
          }
        }
      } else {
        // If the current tape position is non-zero, continue execution
        tape.readPoint++;
      }
      break;

    case ']':
      if (tape.tape[tape.tapePoint] != 0) {
        int loopDepth = 1;
        while (loopDepth != 0) {
          tape.readPoint--;
          if (buffer[tape.readPoint] == '[') {
            loopDepth--;
          } else if (buffer[tape.readPoint] == ']') {
            loopDepth++;
          }
        }
      } else {
        tape.readPoint++;
      }
      break;
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
      tape.tape[tape.tapePoint]--;
      break;
    case '^':
      printf(" %d regster->%d \t",tape.tapePoint,tape.tape[tape.tapePoint]);
      break;
    case 'v':
      scanf("%d",&tape.tape[tape.tapePoint]);
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
      switch (tape.tape[tape.tapePoint]) {
      case 1:
        if (tape.tape[tape.tapePoint+= 1]==2) {
          system("ls");
        }
        break;
      case 2:
        if (tape.tape[tape.tapePoint]==2 && tape.tape[tape.tapePoint+= 1]==1) {
          system("echo hello,would!");
        }
        break;
        case 4:
          switch (tape.tape[tape.tapePoint+= 1]) {
          case 1:
            setupsdl(display);
            break;
          case 2:
            SDL_RenderClear(display.rend);
            break;
            case 3:
              SDL_RenderPresent(display.rend);
             break;
             case 4:
            SDL_SetRenderDrawColor(display.rend,tape.tape[tape.tapePoint+= 2],tape.tape[tape.tapePoint+= 3],
                                   tape.tape[tape.tapePoint+= 4], tape.tape[tape.tapePoint+= 5]);
            break;
            case 5:
            SDL_RenderDrawPoint(display.rend, tape.tape[tape.tapePoint +=2], tape.tape[tape.tapePoint +=3]);
            break;

            case 10:
              SDL_DestroyRenderer(display.rend);
              SDL_DestroyWindow(display.wend);
              break;
          default:
            break;
              }
          break;
      default:
        break;
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


