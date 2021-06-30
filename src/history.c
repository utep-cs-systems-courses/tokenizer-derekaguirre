#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

/*Initializes the linked list*/
List *init_history(){
  List *list = malloc(sizeof(List)); /*Allocate space for the list and items*/
  list->root = malloc(sizeof(Item));
  
  return list;
}

/*adds a string to the history list*/
void add_history(List *list, char *str){
  Item *item = list->root; /*Pointer to current item is set at the root of the list*/  
  int index = 1;
  int length = 0;
  char *temp_str = str;
  while(temp_str[length] != '\0'){/*need to determing size of string*/
    length++;
  } 
  
  while(item->next != NULL){ /*Iterate until hitting null*/
    item = item->next;
    index++;
  }
  item->next = malloc(sizeof(Item)); /*allocate memory for the next item*/

  item->next->id = index;
  item->next->str = copy_str(str,length); /*Saves a copy of the string*/
}

/*Gets the string stored at the specified id*/
char *get_history(List *list, int id){
  Item *temp_list = list->root->next;
  
  while(temp_list != NULL){ /*iterate until the ID is found */
    if(temp_list->id == id){ 
      printf("ID: %d\n", id);
      printf("String:\n");
      return temp_list->str; /*print the string found at the current id*/
    }
    temp_list = temp_list->next;
  }
  return "ID does not exist, please try again.\n"; /*if null is reached*/
}

/*Print every string in the list*/
void print_history(List *list){
  Item *temp_str = list->root->next; /*skip root because there is no value there*/
  while(temp_str != NULL){ /*iter while printing all IDs until hitting null*/
    printf("ID: %d\n", temp_str->id);
    printf("String: %s\n\n", temp_str->str);
    temp_str = temp_str->next;
  }
}

/*Frees the strings and the list*/
void free_history(List *list){
  Item *temp_str = list->root;
  Item *temp_next;
  while(temp_str != NULL){
    temp_next = temp_str->next; /*hold next string before freeing current one*/
    free(temp_str);
    temp_str = temp_next; /*set current to next string*/
  }
}
