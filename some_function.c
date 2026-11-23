#include "replace.h"

CodeForExiting some_function(int *args, char **arg);

CodeForExiting some_function(int *args, char **arg) {
  if (*args == 1) {

    return EXIT_WITHOUT_FILE;

  }
  // if else () {}
  else
    return SUCCES_CODE;
}
