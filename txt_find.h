#ifndef ITXT_FIND_H
#define ITXT_FIND_H
#define LINE 256
#define WORD 30
#define LINES 250

int getlines(char s[]);
int getword(char w[]);
int similar( char *s,char *t, int size_togo, int index_1);
void choose_b(char *full_word);
void choose_a(char *full_word);
void print_word(char *str,int index_1, int size);
int size_of_word(char *str, int index_1);
void prints_words_inline(char *full_line,char *full_word);
int word_in_line(char *full_line,char *full_word);
int equals_com(char * full_word , char * full_line,int index_1);
#endif