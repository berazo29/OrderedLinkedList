#include <stdio.h>
#include <stdlib.h>

//  Data Structure LinkList Node
struct Node{
    int data;
    struct Node* next;
};

// Print the LinkList
void printList(struct Node* node)
{
    if (node == NULL){
        printf("EMPTY\n");
    }
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}


int main() {
    struct Node* head = NULL;
    struct Node* node = NULL;

    head = (struct Node*)malloc(sizeof(struct Node));
    node = (struct Node*)malloc(sizeof(struct Node));

    head->data = 3;
    head->next = node;

    node->data = 5;

    printList(head);
    printf("\n");
    printList(node);




    return 0;
}
