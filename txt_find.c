#include "txt_find.h"
#include <stdio.h>
#include <string.h>

/*
get a line from input and insert to s char array
*/
int getlines(char s[])
{
    int i = 0,temp_char;
    while ( i <LINE && ((temp_char = getchar()) != '\n' && temp_char !=EOF))
    {
        s[i] = temp_char;
        i++;
    }
    s[i] = '\0';

   return i;
}

/*
get a word from input and insert to w char array
*/
int getword(char w[])
{
    char temp_char;
    int i;
    for ( i = 0; i <WORD ; i++)
    {
    
        scanf("%c",&temp_char);
        if(temp_char =='\n' || temp_char == '\t' || temp_char == ' '|| temp_char == EOF || temp_char =='\r')
        break;
        else
        {
        w[i] = temp_char;
        }
    }
    w[i] = '\0';
   return i;
}

/*
 checks if s is simalar to t , even by removing one letter
 first check if the strings are equals if true return 2
 the function go over s and remove each letter and check if the strings are equals
 if true return 1 else return 0
*/
int similar( char *s,char *t, int size_togo, int index_1)
{
    char temp_word [WORD];
    int k;
    int equals = equals_com(s,t,index_1);
    if(equals == 1)
      return 2;
    for (int i = index_1; i < size_togo+index_1; i++)
    {
        k=0;
      for (int j = index_1; j < size_togo+index_1 ;j++)
      {
       if(i!=j)
       {
           temp_word[k] = s[j];
            k++;
       }
       }
       temp_word[k] = '\0';
      equals = equals_com(temp_word,t,0);
      if(equals == 1)
      return 1;
    }
    return 0;
}

/*
return 1 if the word appear in the line once or more
*/
int word_in_line(char *full_line,char *full_word)
{
int i=0,temp_word_s,main_word_s,sim;
main_word_s = size_of_word(full_word,0);
while (full_line[i]!='\0' && full_line[i] != '\r')
{
    if(full_line[i]== ' ')
    {
        i++;
    }
    else{
    temp_word_s= size_of_word(full_line,i);
    if(temp_word_s == main_word_s)
    {
      sim = similar(full_line,full_word,temp_word_s,i);
      if(sim == 2)
      {return 1;}
    }
  i = i + temp_word_s;
    }
}
return 0;
}

/*
if the word appear in the line or a similar word appear the function prints the similar or equal word
*/
void prints_words_inline(char *full_line,char *full_word)
{
int i=0,temp_word_s,main_word_s,sim;
main_word_s = size_of_word(full_word,0);
while (full_line[i]!='\0' && full_line[i] != '\r')
{
    if(full_line[i]== ' ')
    {
        i++;
    }
    else{
    temp_word_s= size_of_word(full_line,i);
    if(temp_word_s == main_word_s || temp_word_s == main_word_s +1)
    {
      sim = similar(full_line,full_word,temp_word_s,i);
      if(sim == 2 || sim == 1)
      print_word(full_line,i,temp_word_s);
    }
  i = i + temp_word_s;
    }
}
}

/*
return the size of a word in a line 
*/
int size_of_word(char *str, int index_1)
{
    int counter = 0;
    while (str[index_1]!= ' ' && str[index_1]!= '\0' && str[index_1]!= '\r')
    {
        counter++;
        index_1++;
    }
    return counter; 
}

/*
print the word from the line 
*/
void print_word(char *str,int index_1, int size)
{
    char temp_word [WORD];
    int k=0;
    for (int i = index_1; i < size + index_1; i++,k++)
    {
        temp_word[k] = str[i];
    }
    temp_word[k] = '\0';
    printf("%s\n",temp_word);
}

/*
get a line from input and check if the line contain the word full_word 
*/
void choose_a(char *full_word)
{
    char line_1[LINE]="";
    int counter,i=0;
    counter = getlines(line_1);
    while ((counter != 0) && (i<LINES))
    {
        if(strstr(line_1,full_word) != NULL)
        {
            printf("%s\n",line_1);
        }
        memset(line_1,0,LINE);
        counter = getlines(line_1);
    }
}

/*
get a line from input and check if the line contain the word full_word,
or even similar word by one more letter , then print the similar or equal word
*/
void choose_b(char *full_word)
{
    char line_1[LINE]="";
    int counter=-1,i=0;
    counter = getlines(line_1);
    while (counter != 0 && i<LINES)
    {
        prints_words_inline(line_1,full_word);
       memset(line_1,0,LINE);
       counter = getlines(line_1);
    }
}

/*
compare two strings one is longer the the other one, start to copare from a spicific position
return 1 if equal else return 0
*/
int equals_com(char * full_word , char * full_line,int index_1)
{
    for (int i = 0; i <= size_of_word(full_word,0); i++)
    {
        if(full_word[i]=='\0')
        {
                return 1;  
        }
        if(full_word[i] != full_line[index_1 + i])
        return 0;
    }
    return 0;
}
