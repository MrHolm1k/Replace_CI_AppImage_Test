#include "replace.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  CodeForExiting result = some_function(&argc, argv);

  switch (result) {
  case EXIT_WITHOUT_FILE: {
    printf("Write file name and words. Exiting with code 1\n");
    return EXIT_WITHOUT_FILE;
  }
  case SUCCES_CODE:
  default:
    break;
  }

  FILE *file;
  struct File_data_replace file_to_edit;
  result = opening_file(argv[1], "r", &file);

  switch (result) {
  case ONLY_WORDS: {
    result = opening_file(argv[2], "r", &file);
    if (result == ONLY_WORDS) {
      printf("No file name, only words to replace. Exiting with code 2\n");
      return ONLY_WORDS;
    } else {
      file_to_edit.file = file;
      file_to_edit.name_of_file = argv[2];
      file_to_edit.word_to_changed = argv[1];
      file_to_edit.new_word = argv[3];
    }
    break;
  }
  case SUCCES_CODE: {
    file_to_edit.file = file;
    file_to_edit.name_of_file = argv[1];
    file_to_edit.word_to_changed = argv[2];
    file_to_edit.new_word = argv[3];
    break;
  }
  default:
    break;
  }

  int number_of_word = 0;
  int number_of_line = 0;
  result = replace_function(&number_of_word, &number_of_line, file_to_edit);

  switch (result) {
  case FILE_OPEN_ERROR: {
    printf("Error opening file for writing. Exiting with code 3\n");
    return FILE_OPEN_ERROR;
  }
  case SUCCES_CODE: {
    printf("Replaced %d words in %d lines\n", number_of_word, number_of_line);
    break;
  }
  default:
    break;
  }

  return result;
}
