#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void list_print_list(List* list) {
    ListNode* node = list->head;
    while(node != NULL) {
        printf("%i ", node->value);
        node = node->next;
    }
    printf("\n");
}

int list_insert_node(List* list, int position, int value) {
    if(position == -1) {
        ListNode* new_node = (ListNode*) malloc(sizeof(ListNode));
        new_node->value = value;
        new_node->next = list->head;
        list->head = new_node;
        return 0;
    }

    ListNode* node = list->head;
    for(int i = 0; i < position; i++) {
        if(node == NULL) {
            return -1;
        }
        node = node->next;
    }

    if(node == NULL) {
        return -1;
    }

    ListNode* new_node = (ListNode*) malloc(sizeof(ListNode));
    new_node->value = value;
    new_node->next = node->next;
    node->next = new_node;

    return 0;
}

int list_delete_node(List* list, int position, int* value) {
    if(position == 0) {
        if(list->head == NULL) {
            return -1;
        }

        *value = list->head->value;
        ListNode* next_head = list->head->next;
        free(list->head);
        list->head = next_head;

        return 0;
    }

    ListNode* node = list->head;
    for(int i = 0; i < position - 1; i++) {
        if(node == NULL) {
            return -1;
        }
        node = node->next;
    }

    if(node == NULL || node->next == NULL) {
        return -1;
    }

    *value = node->next->value;
    ListNode* next_next = node->next->next;
    free(node->next);
    node->next = next_next;

    return 0;
}
