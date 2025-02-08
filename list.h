/*
 * This file contains basic linked list declarations.  Only a forward
 * declaration of the list structure is included, thus preventing users of the
 * list structure from accessing its internals.
 */

#ifndef __LIST_H
#define __LIST_H

struct list;

struct list* list_setup();

/* list iterator */
struct list_iterator;

struct list_iterator* list_iterator_create(struct list* list);
int list_iterator_has_next(struct list_iterator* itr);
int list_iterator_next(struct list_iterator* itr);

#endif
