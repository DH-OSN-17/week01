#include <stdio.h>
#include "list.h"
#include "dlist.h"

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubble_sort(int* array, size_t len) {
    for(int i = 0; i < len; i++) {
        for(int j = i + 1; j < len; j++) {
            if(array[i] > array[j]) {
                swap(array+i, array+j);
            }
        }
    }
}

int partition(int* array, int top, int bottom) {
    int x = array[top];
    int i = top - 1;
    int j = bottom + 1;

    do {
        do {
           j--;
        } while (x < array[j]);
        do {
            i++;
        } while (x > array[i]);
        if (i < j) {
            swap(array+i, array+j);
        }
    } while (i < j);

    return j;
}


void quick_sort(int* array, int top, int bottom) {
    int middle;
    if (top < bottom) {
        middle = partition(array, top, bottom);
        quick_sort(array, top, middle);
        quick_sort(array, middle+1, bottom);
    }
    return;
}

void print_array(int* array, size_t len) {
    while(len--) {
        printf("%i ", *(array++));
    }
    printf("\n");
}

int main(){
    int array[10] = {3, 5, 87, 3, 7, 2, 5, 6 , 3, 1};
    print_array(array, 10);
    quick_sort(array, 0, 9);
    print_array(array, 10);

    List list = {NULL};
    list_insert_node(&list, -1, 1);
    list_insert_node(&list,  0, 2);
    list_insert_node(&list,  1, 3);
    list_insert_node(&list, -1, 4);
    list_insert_node(&list, -1, 5);
    list_insert_node(&list, -1, 6);

    list_print_list(&list);

    int val;
    list_delete_node(&list, 0, &val);
    list_print_list(&list);
    list_delete_node(&list, 2, &val);
    list_print_list(&list);
    list_delete_node(&list, 1, &val);
    list_print_list(&list);
    list_delete_node(&list, 0, &val);
    list_print_list(&list);

    return 0;
}
