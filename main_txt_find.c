#include "txt_find.h"
#include <stdio.h>

/*
get a input of word and char from user, if the letter is a the function print the line
in the text that contain the sequnce of the word.
if the letter is b the function will print all the words that equal or similar in the text 
*/
int main()
{
    char note;
    char word[WORD];
    getword(word);
    printf("\nthe word to look for is:%s\n",word);
    scanf("%c",&note);
    printf("letter is:%c\n",note);
    if(note == 'a')
    {
        choose_a(word);
    }
    else
    {
        choose_b(word);
    }
    
    return 1;
}