#ifndef REPLACE_H
#define REPLACE_H

#include <stdio.h>
#include <stdlib.h>

// Types
typedef enum {
  SUCCES_CODE,       // 0
  EXIT_WITHOUT_FILE, // 1
} CodeForExiting;

// Function
CodeForExiting some_function(int *args, char **arg);

#endif
