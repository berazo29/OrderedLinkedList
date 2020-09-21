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

// Count the nodes First Node
int countNodes(struct Node* head){
    struct Node* current = head;
    int count = 0;

    while (current != NULL){
        count++;
        current = current->next;
    }
    return count;
}


int main() {

    // Data
    int arr[] = {3,5,7};

    // Initialize
    struct Node* head = NULL;
//    struct Node* second = NULL;
//    head = (struct Node*)malloc(sizeof(struct Node));
//    second = (struct Node*)malloc(sizeof(struct Node));
//    head->data = 5;
//    head->next = second;
//    second->data = 4;
//    second->next = NULL;

    int length = countNodes(head);

    printf("Nodes = %d\n", length);

    printList(head);




    return 0;
}
