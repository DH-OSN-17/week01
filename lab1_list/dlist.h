#ifndef DLIST_H
#define DLIST_H

typedef struct DListNode {
    int value;
    struct DListNode* prev;
    struct DListNode* next;
} DListNode;

typedef struct DList {
    struct DListNode* head;
} DList;

void dlist_print_list(DList* list);
int dlist_insert_node(DList* list, int position, int value);
int dlist_delete_node(DList* list, int position, int* value);

#endif // LINKED_LIST_H
