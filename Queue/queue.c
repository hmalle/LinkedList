
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "queue.h"

queue_t *q_new()
{
  queue_t *q =  malloc(sizeof(queue_t));
  if(q == NULL){
    return NULL;
  }
  q->head = NULL;
  q->tail = NULL;
  q->q_size = 0;
  return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
  if(q == NULL){
    return; 
  }
  if(q->q_size == 1){  //Only 1 element in the queue. 
    free(q->head->value);   //Free the string pointed to by the head. 
    free(q->head);  //Free the first node
    free(q);         //Free the head and return
    return;
  }else{
    //Else when theres more than 1 element. 
    list_ele_t *curr_ptr;  //Allocate a temporary pointer
    list_ele_t *next_ptr;   //Allocate a temporary pointer
    curr_ptr = q->head; 
    next_ptr = q->head;

    while(curr_ptr !=NULL){
      next_ptr = curr_ptr->next;
      free(curr_ptr->value);
      free(curr_ptr);
      curr_ptr = next_ptr;
    }
    q->head = NULL;
    q->tail = NULL;
    free(q);
  }
}

bool q_insert_head(queue_t *q, char *s)
{
  if(q == NULL){  //If q doesnt exist create it and initialize the values. 
    return false;
  }

  char * str = malloc(strlen(s)+1); //Allocate new string
  strncpy( str, s, strlen(s)+1);
  if(str == NULL) 
    return false; 

  list_ele_t *new_node = malloc(sizeof(list_ele_t));  //Allocate new element
  if(new_node == NULL ){
    free(new_node);
    return false;
  }

  //Assign values to newh. 
  new_node->value = str;
  new_node->next = NULL;
 
  if(q->head==NULL){
    //Assign the first element to the queue and return true; 
    q->head = new_node;
    q->q_size = 1;
    q->tail = new_node;
  }else if(q->head != NULL){
    list_ele_t *tmp = q->head;  //A temporary pointer pointing to head. 
    q->head = new_node;
    q->head->next = tmp; 
    q->q_size +=1;
    //Nothing to do with the tail, its still the same value
  }
  return true;
}

bool q_insert_tail(queue_t *q, char *s)
{
  if(q ==NULL) 
    return false;
  else{
    char * str = malloc(strlen(s)+1); //Allocate new string
    strncpy( str, s, strlen(s)+1);

    if(str == NULL)
      return false; 
    
    list_ele_t *newh = malloc(sizeof(list_ele_t));  //Allocate new element
    if(newh == NULL ){ 
      //Unable to allocate memory
      free(newh);
      return false;
    }

    newh->value = str;
    newh->next = NULL;

    if(q->head== NULL){
      //Assign the first element to the queue and return true; 
      q->head = newh;
      q->tail = newh;
      q->q_size = 1;
    }else{
      list_ele_t *last = q->tail;  //A temporary pointer pointing to last element.
      last->next = newh;
      q->tail = newh;
      q->q_size +=1;
    }
    return true;
  }
}

bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
  if(q == NULL || q->head == NULL){
    return false;
  }else if(q->head->next == NULL){
    //We have only one element
    strncpy(sp, q->head->value, bufsize-1);
    free(q->head->value);
    free(q->head);
    q->head = NULL;
    q->tail = NULL;
    q->q_size = 0;
    return true;
  }else{
    //We have more than 1 element in the queue. 
    list_ele_t *tmp = q->head;
    q->head = q->head->next;
    strncpy(sp, tmp->value, bufsize-1);
    free(tmp->value);
    free(tmp);
    tmp=NULL;
    q->q_size -=1;
    return true;
  }

}

int q_size(queue_t *q)
{
  /* Remember: It should operate in O(1) time */
  if(q == NULL){
    return 0;
  }else{
    return q->q_size; 
  }
}

void q_reverse(queue_t *q)
{
  if(q==NULL || q->head == NULL || q->head->next==NULL ){
    //null, 0 elements or 1 element: nothing to reverse so return null 
    return;
  }else{
    list_ele_t *prv = q->head;
    list_ele_t *cur = q->head; 
    list_ele_t *nxt = q->head;
    q->head = q->tail;  //Immediately point to the last element; 
    q->tail = cur;   //aka q->head; 
    for(int a=0; cur->next != NULL; a++){
      //Reverse the rest of the elements
      nxt = cur->next; 
      cur->next = prv;
      //Advance a step
      prv = cur; 
      cur = nxt;
    }
    q->head->next = prv; //Link the last element->next to point to previous. 
    q->tail->next = NULL;
  }
}

