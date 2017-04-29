#ifndef LIST_H
#define LIST_H

typedef struct ListNode {
    int value;
    struct ListNode* next;
} ListNode;

typedef struct List {
    struct ListNode* head;
} List;

void list_print_list(List* list);
int list_insert_node(List* list, int position, int value);
int list_delete_node(List* list, int position, int* value);

#endif // LINKED_LIST_H
