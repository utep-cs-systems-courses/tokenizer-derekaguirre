#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int main() {
  printf("Hello!\n");
  char str[50];

  printf("\nEnter a string:\n");
  fgets(str,50,stdin);

  printf("%s\n", str);
  int letter_pos = 4;
  printf("space_Char output\n");
  printf("%d", space_char(str[letter_pos]));
  printf("\n");
    
  printf("non_space_char output\n");
  printf("%d", non_space_char(str[letter_pos]));
  printf("\n");

  printf("word_start output\n");
  printf("%c",word_start(str));
  printf("\n");

  printf("word_terminator output\n");
  printf("%c",word_terminator(str));
  printf("\n");
  
  printf("copy_str output\n"); 
  printf("%s", copy_str(str,sizeof(str)));
  printf("\n");
 
  printf("count_words output\n");
  printf("%d", count_words(str));
  printf("\n");
	      
}
	     
