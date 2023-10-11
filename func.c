#include "main.h"
char *_strdup(char *str) {
	char *str1;
	int i, size = 0;

	for (i = 0; str[i] != '\0'; i++) {
		size++;
	}
	size++;

	str1 = malloc(sizeof(char) * size);

	for (i = 0; str[i] != '\0'; i++) {
		str1[i] = str[i];
	}
	str1[i] = '\0';
	return str1;
}

int _str_len(char *str) {
	int i, len = 0;
	for (i = 0; str[i] != '\0'; i++) {
		len++;
	}
	return len;
}

/*void write_str(char *str) {
  write(STDOUT_FILENO, str, _str_len(str));
  }*/
void free_mem(char **dptr)
{
	/*for (int i = 0; dptr[i] != NULL; i++) {
	  free(dptr[i]);
	  }*/
	free(dptr);
}
