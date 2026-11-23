#include "main_function.h"

CodeForExiting some_function(int *args, char **arg) {
  if (*args == 1) {

    return EXIT_WITHOUT_FILE;

  }
  // if else () {}
  else
    return SUCCES_CODE;
}

FILE *opening_file(const char *name_file, const char *type_of_opening) {
  // Нужно открыть файл, необходимо проверить:
  // 1. Сущесствует ли файл, и если да, то откроеться ли он;
  // 2. Потом как мы открываем файл (switch case);
  // 3. Открываем потом в FILE и возращаем указатель?
  FILE *file;

  return file;
}
