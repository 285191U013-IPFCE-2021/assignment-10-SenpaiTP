#include "btree.h"

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>


struct tree_node * Insert (int x, struct tree_node *t)
{
  // Insert item x into the tree t

  if(t == NULL){
    return Initialize(t->item = x);
  }
  if(t->item < x){
    t->right = Insert(x, t->right);
  }
  else if(t->item > x){
    t->left = Insert(x, t->left);
  }
  return NULL;
}

struct tree_node * Remove (int x, struct tree_node *t)
{
 // Remove one item from the tree t
  if (t == NULL){
    return t;
  }
  if(x < t->item){
    t->left = Remove(x, t->left);
  }
  else if(x > t->right){
    t->right = Remove(x, t->right);
  }
  else{
    if(t->left == NULL){
      struct tree_node* TempN = t->right;
      free(t);
      return TempN;
    }
    else if(t->right == NULL){
      struct tree_node* TempN = t->left;
      free(t);
      return TempN;
    } 

  }
  return t;
}


int Contains (int x, struct tree_node *t)
{

  // Return true if the tree t contains item x. Return false otherwise.
  
  
  if((t->left->item || t->right->item) == x){
    return 1;
  }
  else if(t->left || t->right){
    if(t->left){
      return (Contains(x, t->left) &&  Contains(x, t->right));
    }
    if(t->right){
      return(Contains(x, t->left) &&  Contains(x, t->right));
    }
  }
}


struct tree_node * Initialize (struct tree_node *t)
{
  // Create an empty tree
  struct tree_node *new_tree_node = malloc(sizeof(struct tree_node));
  new_tree_node->item = NULL;
  new_tree_node->left = NULL;
  new_tree_node->right = NULL;

  return NULL;
}

int Empty (struct tree_node *t)
{
  // Test if empty
  if(t->left == NULL && t->right == NULL && t->item == NULL){
    return 1;
  }
  return 0;
}

int Full (struct tree_node *t)
{
    // Test if full
    if(t->item == NULL){
      return 1;
    }

    if(t->left == NULL && t->right == NULL){
      return 1;
    }
    if((t->left) && (t->right)){
      return (Full(t->left) && (Full(t->right)));
    }
}
