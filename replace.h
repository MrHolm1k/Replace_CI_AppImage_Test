#ifndef REPLACE_H
#define REPLACE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
  SUCCES_CODE,       // 0
  EXIT_WITHOUT_FILE, // 1
  ONLY_WORDS,        // 2
  FILE_OPEN_ERROR,   // 3
  BAD_CODE,          // 4
} CodeForExiting;

struct File_data_replace {
  FILE *file;
  const char *name_of_file;
  const char *word_to_changed;
  const char *new_word;
};

struct File_data_replaced_new {
  FILE *file;
  const char *name_of_file;
  const int number_of_word;
  const char *word_to_changed;
};

CodeForExiting some_function(const int *args, char **arg);

CodeForExiting opening_file(const char *name_file, const char *type_of_opening,
                            FILE **file);

CodeForExiting replace_function(int *number_of_word, int *number_of_line,
                                struct File_data_replace file_replace);

#endif
