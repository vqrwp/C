#ifndef RK_COUNTING_WORDS_IN_FILE_H
#define RK_COUNTING_WORDS_IN_FILE_H

#include <stdio.h>

typedef struct num_word
{
    char *string;
    int num;
}num_words;

struct num_word *counting_words(FILE *fi, FILE *fo);

#endif //RK_COUNTING_WORDS_IN_FILE_H
