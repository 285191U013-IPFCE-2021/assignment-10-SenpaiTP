#include "linked_list.h"
/*
 * Linked list
 */

#include <stdio.h>		/* printf */
#include <stdlib.h>		/* malloc, free */
#include <assert.h>		/* assert */

/* functions to create lists */
node *make_node (int v, node * q)
{
  node *p = malloc (sizeof (node));
  p->value = v;

  if (q == &SENTINEL_node)
    p->next = &SENTINEL_node;
  else
    p->next = q;
  return p;
}

/* free all nodes in the list p */
void free_list (node * p)
{
  node *q = p;
  while (q != &SENTINEL_node)
    {
      node *t = q->next;
      free (q);
      q = t;
    }
}


/* print list to console */
void print_list (node * p)
{
  printf("%d", p->value);
  if(p != NULL){
    printf(",");
  }
  print_list(p->next);
}

int sum_squares (node * p)
{
    // Add your code for excercise 2
    // You can find the tests in tests.cpp
    if(p != NULL){
      return (square(p->value)) + sum_squares(p->next);
    }
    else
      return 0;
}

node *map (node * p, int (*f) (int))
{
    // Add your code for excercise 3
    // Pre-condition value of p != NULL and that the linked list is not empty
    
    if(p != NULL){
      f = square(p->value); 
      p->value = f;
    }
    map(p->next, f);
    return NULL;
}


int square (int x)
{
  return x * x;
}
