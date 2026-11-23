#include "replace.h"

CodeForExiting some_function(const int *args, char **arg) {
  (void)arg;
  if (*args < 4) {
    return EXIT_WITHOUT_FILE;
  } else {
    return SUCCES_CODE;
  }
}

CodeForExiting opening_file(const char *name_file, const char *type_of_opening,
                            FILE **file) {
  *file = fopen(name_file, type_of_opening);

  if (*file == NULL) {
    return ONLY_WORDS;
  }

  return SUCCES_CODE;
}

CodeForExiting replace_function(int *number_of_word, int *number_of_line,
                                struct File_data_replace file_replace) {
  FILE *temp = tmpfile();
  if (temp == NULL) {
    fclose(file_replace.file);
    return FILE_OPEN_ERROR;
  }

  char line[4096];
  size_t old_len = strlen(file_replace.word_to_changed);
  *number_of_word = 0;
  *number_of_line = 0;

  while (fgets(line, sizeof(line), file_replace.file) != NULL) {
    (*number_of_line)++;
    char *pos = line;
    char *found;

    while ((found = strstr(pos, file_replace.word_to_changed)) != NULL) {
      fwrite(pos, 1, found - pos, temp);
      fputs(file_replace.new_word, temp);
      pos = found + old_len;
      (*number_of_word)++;
    }
    fputs(pos, temp);
  }

  fclose(file_replace.file);
  FILE *out = fopen(file_replace.name_of_file, "w");
  if (out == NULL) {
    fclose(temp);
    return FILE_OPEN_ERROR;
  }

  rewind(temp);
  size_t bytes;
  while ((bytes = fread(line, 1, sizeof(line), temp)) > 0) {
    fwrite(line, 1, bytes, out);
  }

  fclose(temp);
  fclose(out);
  return SUCCES_CODE;
}
