#include "replace.h"

int main(int argc, char *argv[]) {
  CodeForExiting result = some_function(&argc, argv);

  switch (result) {
  case EXIT_WITHOUT_FILE: {
    printf("ERROR 1. NO FILE NAME FOR WORK");
    return EXIT_WITHOUT_FILE;
  }
  case SUCCES_CODE:
  default:
    break;
  }
}
