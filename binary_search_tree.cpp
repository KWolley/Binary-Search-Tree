//
// binary_search_tree.cpp
//
// Please refer to binary_search_tree.h for documentation.
//

#include "binary_search_tree.h"
#include <string>

using namespace std;

// DONE
bt_node* init_node(int data) {
  bt_node* new_node = new bt_node;
  new_node -> data = data;
  new_node -> left = NULL;
  new_node -> right = NULL;
  return new_node;
}

// DONE
void insert(bt_node** top, bt_node* new_node) {
  if (*top == NULL){
    *top = new_node;
    return;
  } else {
    bt_node* tmp = *top;
    int dat = new_node -> data;
    if (dat < tmp -> data) {
      insert(&tmp -> left, new_node);
    } else {
      insert(&tmp -> right , new_node);
    }
  }
}

// DONE
void insert_data(bt_node** top, int data) {
  if (*top == NULL){
    *top = init_node(data);
    return;
  } else {
    bt_node* new_node = *top;  
    if(data < new_node -> data) {
      insert_data(&new_node -> left, data);
    } else {
      insert_data(&new_node -> right, data);
    }
    return;
  }
}


// TO BE DONE
void remove(bt_node** top, int data) {
  // casse 1 if *top == NULL this is the bail out
  if (*top == NULL){
    return;
  } else {
    if (data < (*top) -> data){ // if data < current node traverse left
      remove(&(*top)->left, data);
    }
    if (data > (*top) -> data){ // if data >= current node traverse right
      remove(&(*top) -> right, data);
    }
    if (data == (*top) -> data){  // if data == the data that is in the current node

    // case 1 - no children
      if ((*top) -> left == NULL) {  // if no left child
        *top = (*top) -> right;
      } else if ( (*top) -> right == NULL){  // if no right child
        *top = (*top) -> left;
      } else {
        bt_node* cursor = (*top) -> right;  // create cursor to traverse through tree
        while (cursor -> left != NULL){ // until the cursor has reached the end cont. left
          cursor = cursor -> left;
        }
        (*top) -> data = cursor -> data;  // assign top data to the data at cursor
        delete cursor;  // delete cursor
        remove(&((*top) -> right), cursor -> data); // remove cursor data that still remains
      }
    }
  }
}

// DONE
bool contains(bt_node* t, int data) { 
  if (t == NULL){
    return false;
  } else {
    if (t -> data == data){
      return true;
    }
    while (t !=NULL) {
      if (data < t-> data ) {
        return contains(t -> left, data);
      } else {
        return contains(t -> right, data);
      }
    }
  }
}

// DONE
bt_node* get_node(bt_node* t, int data) {
  if (t == NULL){
    return t = NULL;
  }
  while (t !=NULL) {
    if (t -> data == data) {
      return t;
      }
    if (data < t-> data ) {
      t = get_node(t -> left, data);
      } else {
        t = get_node(t -> right, data);
    }
  }
}

// DONE
int size(bt_node* t) {
  if (t == NULL){
    return 0;
  }
  // count nodes starting left to right
  return  1 + size(t-> left) + size(t-> right); //
}

void to_array_help(bt_node* t, int arr[], int * index){
  if(t == NULL){
    return;
  }
  if (t -> left != NULL){
    to_array_help(t -> left, arr, index);
  }
  arr[*index] = t -> data;
  (*index)++;
  
  if (t -> right != NULL) {
    to_array_help(t -> right, arr, index);
  }
   
}

void to_array(bt_node* t, int arr[]) {
  //bt_node* new_node = t;
  if (t == NULL){
    return;
  } else {
    int index = 0;
    to_array_help(t,arr,&index);
    }
}


