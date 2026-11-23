#ifndef REPLACE_H
// Macroses

#define REPLACE_H

// Types
typedef enum {
  SUCCES_CODE,       // 0
  EXIT_WITHOUT_FILE, // 1
} CodeForExiting;

// Function
CodeForExiting some_function(int *args, char **arg);

#endif

#include <stdio.h>
#include <stdlib.h>
