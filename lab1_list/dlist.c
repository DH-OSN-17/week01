#include "dlist.h"
#include <stdio.h>
#include <stdlib.h>

void dlist_print_list(DList* list) {
    DListNode* node = list->head;
    while(node != NULL) {
        printf("%i ", node->value);
        node = node->next;
    }
    printf("\n");
}

int dlist_insert_node(DList* list, int position, int value) {
    if(position == -1) {
        DListNode* new_node = (DListNode*) malloc(sizeof(DListNode));
        new_node->value = value;
        new_node->next = list->head;

        if(list->head != NULL) {
            list->head->prev = new_node;
        }

        new_node->prev = NULL;
        list->head = new_node;
        return 0;
    }

    DListNode* node = list->head;
    for(int i = 0; i < position; i++) {
        if(node == NULL) {
            return -1;
        }
        node = node->next;
    }

    if(node == NULL) {
        return -1;
    }

    DListNode* new_node = (DListNode*) malloc(sizeof(DListNode));
    new_node->value = value;
    new_node->prev = node->prev;
    node->next->prev = new_node;
    new_node->next = node->next;
    node->next = new_node;

    return 0;
}

int dlist_delete_node(DList* list, int position, int* value) {
    if(position == 0) {
        if(list->head == NULL) {
            return -1;
        }

        *value = list->head->value;
        DListNode* next_head = list->head->next;
        free(list->head);
        list->head = next_head;

        if(list->head->next != NULL) {
            list->head->next->prev = list->head;
        }

        return 0;
    }

    DListNode* node = list->head;
    for(int i = 0; i < position; i++) {
        if(node == NULL) {
            return -1;
        }
        node = node->next;
    }

    if(node == NULL) {
        return -1;
    }

    *value = node->prev->value;
    DListNode* prev_prev = node->prev->prev;

    if(prev_prev != NULL) {
        prev_prev->next = node;
    }

    free(node->prev);
    node->prev = prev_prev;

    return 0;
}
