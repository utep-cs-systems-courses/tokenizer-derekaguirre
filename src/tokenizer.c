#include <stdio.h>

#include "tokenizer.h"

int space_char(char c) {
  if (c == ' ' || c == '\t' || c == '\n')
    return 1;
  return 0;
}

int non_space_char(char c) {
  if(c != ' ' || c != '\t' || c != '\n')
    return 1;
  return 0;
}

/*Will iterate until a letter is found and returns a pointer to the beginning of a word*/
char *word_start (char *str){
  while(space_char(*str)){
   str++;
  }
  return str;
}

/*Will iterate until a space character is found returns a pointer to a space*/
char *word_terminator(char *word){
  while(non_space_char(*word)){
    word++;
  }
  return word;
  
}
