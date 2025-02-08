/*
 * This file contains a few basic structure and function definitions for a
 * singly-linked list.  The list is defined in such a way as to hide its
 * internal implementation details from code outside this file.
 */

#include <stdlib.h>

#include "list.h"

/*
 * This structure is used to represent a single link in a singly-linked list.
 * For simplicity, this structure can only store integer values.  Note that
 * this structure is not defined in list.h, so it is not visible outside this.
 * file.  In other words, link structures can only be used within the current
 * file.
 */
struct link {
  int val;
  struct link* next;
};

/*
 * This structure is used to represent an entire singly-linked list.  Note that
 * only a forward declaration of this structure is present in list.h.  This
 * means that, while code outside the current file can use list structures,
 * that code cannot access the internals of a list structure.  For example,
 * code outside the current file can't access any fields of the list structure,
 * and pointers to list structures can't be dereferenced outside this file.
 */
struct list {
  struct link* head;
};

/*  
 * This structure represents an iterator over a linked list.  It contains one
 * field that holds a pointer to the link currently being examined in the
 * current iteration.
 */

struct list_iterator {
    struct link* curr; 
};

/*
 * This function allocates, initializes, and fills a small linked list and
 * returns a pointer to it.
 DO NOT CHANGE
 */
struct list* list_setup() {
  struct list* list = malloc(sizeof(struct list));
  struct link* next = NULL;
  int i;

  for (i = 10; i > 0; i--) {
    struct link* link = malloc(sizeof(struct link));
    link->val = i*2 + 1;
    link->next = next;
    next = link;
  }
  list->head = next;
  return list;
}

/*
 * This function allocates a lst iterator, initializes it to start iteration
 * at the beginning of the specified list, and returns a pointer to the
 * iterator.
 */

struct list_iterator* list_iterator_create(struct list* list) {
    struct list_iterator* itr = malloc(sizeof(struct list_iterator));
    itr->curr = list->head;
    return itr;
}


/*
 * This function is used to indicate whether an iterator has more elements to
 * examine.  It returns 1 if there are more elements to examine for itr and 0
 * if there are no more elements to examine.
 */

int list_iterator_has_next(struct list_iterator* itr) {
    if (itr->curr == NULL) {
	return 0;
    }
    return 1;
}


/*
 * This function returns the value associated with the current element in an
 * iterator's iteration and advances the iterator to the element in the list.
 */

int list_iterator_next(struct list_iterator* itr) {
    int temp = itr->curr->val;
    itr->curr = itr->curr->next;
    return temp;
}


