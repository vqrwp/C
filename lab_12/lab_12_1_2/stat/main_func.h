#ifndef MAIN_FUNC_H
#define MAIN_FUNC_H

int counting_array(FILE *fi);
void reading_file(FILE *fi, int *pa, int count);
void print_in_file(FILE *fo, int *pa, int *pb);
void free_n_close(FILE *fi, FILE *fo, int *pa);
int editing_array(int *pa, int *pb, FILE *fi, FILE *fo, char *f);

#endif 