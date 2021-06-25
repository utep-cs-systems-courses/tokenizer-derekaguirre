#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

/*Returns 1 if the char is a whitespace character*/
int space_char(char c) {
 if(c == ' ' || c == '\t'){
   return 1;
 }
 return 0;
}
/*Returns 1 if the char is non-whitespace character*/
int non_space_char(char c) {
  if(!space_char(c)){
   return 1;
 }
   return 0;
}

/*Will iterate until a letter is found and returns a pointer to the beginning of a word*/
char *word_start (char *str){
  char *tmp = str;  /*Pointer that points to a char type gets the address of the string*/
  while(space_char(*tmp) && tmp[0] != '\0'){ /*Iter through chars until a space or null is hit*/
    tmp++;
  }
  return tmp;
}

/*Iterates until it finds the end of a word*/
char *word_terminator (char *word){
  char *tmp = word_start(word);

  while(non_space_char(tmp[0]) && tmp[0] != '\0'){ /*Iter chars until letter or null is hit*/
    tmp++;
  }
  return tmp;
}

/*Counts the number of words in a string*/
int count_words(char *str){ 
  int counter = 0;
  while(*str != '\0'){ /*Iterates the counter if the current char is not the null terminator*/
    str = word_start(str); /*Pointer of str moves to address of the first char of the next word*/
    str = word_terminator(str); /*Pointer of str moves to address of next word terminator*/
    counter++;
  }
  return counter++;
}

/*Method that copies the string*/
char *copy_str(char *inStr, short len){
  char *str_copy = malloc((len+1) * sizeof(char));/*Allocates array space for 0 terminated string*/
  int i = 0;
  while(i < len){ /*Copies the entire length of the string into the new array*/
    str_copy[i] = inStr[i];
    i++;
  }
  str_copy[len+1] = '\0'; /*Places the null terminator at the end*/
  return str_copy;
}

/*Tokenizes a string*/
char **tokenize(char *str){
  int size = count_words(str); /*Calls word count to know how much space to allocate in new array*/
  char **tokens = malloc((size +1) * sizeof(char *)); /*Allocates array space for the tokens*/
  char *start= word_start(str);
  char *end = word_terminator(start);
  for (int i = 0; i < size; i++){
    tokens[i] = copy_str(start, end - start); /*Transfers the tokens using pointers to them*/
    start = word_start(end);
    end = word_terminator(start);
  }
  tokens[size] = NULL;
  return tokens;
  
}
/*Prints the current tokens*/
void print_tokens(char **tokens){
  int i;
  for(i = 0; tokens[i] != NULL; i++){
    printf("%s\n", tokens[i]);
  }
}
/*Deletes current tokens to free up space*/
void free_tokens(char **tokens){
  int i;
  for(i = 0; tokens[i] != NULL; i++){
    free(tokens[i]);
  }
  free(tokens);
}
