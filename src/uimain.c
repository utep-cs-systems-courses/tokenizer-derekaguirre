#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"


int main() {
  
  char user_input[100]; /*user input array*/
  char **tokens; /*used for tokenize method*/
  List *history = init_history();
  
  while(1){ /* run as long as the user does not specify quitting which breaks loop*/
    printf("Enter desired string or command:\n\n");
    printf("i  = Input a string into the program\n");
    printf("h  = Print all entries in the history\n");
    printf("!# = Print specified entry in the history\n");
    printf("q  = Quit program\n\n");
      
    printf("$ ");
    fgets(user_input,100,stdin);

    if(*user_input == 'i'){
      printf("Input a string:\n");
      fgets(user_input,100, stdin);
      tokens = tokenize(user_input);
      
      printf("Tokenized string:\n");
      print_tokens(tokens);
      
      printf("Adding input to history...\n");
      add_history(history, user_input);
      
      printf("Freeing tokens from string...\n");
      free_tokens(tokens);
    }
    
    else if(*user_input == 'h'){
      printf("Printing history...\n");
      print_history(history);
    }
    
    else if (user_input[0] == '!'){
      int index = user_input[1] - '0'; //converts char into int

      printf("%s",get_history(history,index)); //prints what history returns
    }
    
    else if(*user_input == 'q'){
      free_history(history);
      printf("Exiting...\n\n");
      break;
    }
    
    else{
      printf("\nCommand not found, please re-enter command\n\n");
    }
    
  }
}
