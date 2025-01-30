#include "linked_list.h"
#include <stdio.h>
#include <string.h>

void list_init(list_t *h) { *h = NULL; }

int list_size(const list_t *h) {
  node_t *p = *h;
  int r = 0;
  while (p != NULL) { // Check if p is not NULL before accessing r += 1;
    p = p->next;
  }
  return r;
}

int list_empty(const list_t *h) { return (*h == NULL); }

void list_insert(list_t *h, node_t *n) {
  n->next = *h;
  *h = n;
}

node_t *list_find(const list_t *h, int id) {
  node_t *p = *h;
  while (p) {
    if (p->id == id)
      return p;
    p = p->next;
  }
  return NULL;
}

node_t *list_find_before(const list_t *h, int id) {
  node_t *p = *h;
  while (p && p->next) {
    if (p->next->id == id)
      return p;
    p = p->next;
  }
  return NULL;
}

node_t *list_delete(list_t *h, int id) {
  node_t *r = NULL;
  if (*h && (*h)->id == id) {
    r = *h;
    *h = (*h)->next; // Correctly update head to the next node
    r->next = NULL;
    return r;
  }
  node_t *p = list_find_before(h, id);
  if (p) {
    r = p->next;
    p->next = p->next->next;
    r->next = NULL;
  }
  return r;
}

void print_list(const list_t *h) {
  node_t *p = *h;
  while (p) {
    printf("%d: %s says %s\n", p->id, p->name, p->msg);
    p = p->next;
  }
}
