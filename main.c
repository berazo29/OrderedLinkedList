#include <stdio.h>
#include <stdlib.h>

//  Data Structure LinkList Node
struct Node{
    int data;
    struct Node* next;
};

// Print the LinkList
void printList( struct Node* node ){
    if ( node == NULL ){
        printf("EMPTY\n");
    }
    while ( node != NULL ){
        printf("%d ", node->data);
        node = node->next;
    }
}

// Count the nodes First Node
int countNodes( struct Node* head ){
    struct Node* current = head;
    int count = 0;

    while ( current != NULL ){
        count++;
        current = current->next;
    }

    return count;
}

// Insert node at any position from 1 to any location
void insertNode( struct Node** node, int location, int data ){

    // Check for validity
    int i = 1;
    struct Node* prevNode;
    struct Node* nextNode;
    struct Node* newNode = ( struct Node* )malloc( sizeof( struct Node ) );

    // This is use for skip insertion
    if ( !newNode || location == 0){
        //printf("M error"); // Memory error
        return;
    }

    newNode->data = data;
    nextNode = *node;

    // Insert in the beginning
    if( location == 1 || nextNode == NULL ){
        newNode->next = *node;
        *node = newNode;
    } else{
        while(nextNode != NULL && (i < location ) ){
            i++;
            prevNode = nextNode;
            nextNode = nextNode->next;
        }
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }

}


int main() {

    // Data

    // Initialize
    struct Node* head = NULL;
//    struct Node* second = NULL;
    insertNode(&head, 0,1);
    insertNode(&head, 1,2);

    insertNode(&head, 2, 4);
    insertNode(&head, 0, 7);
    insertNode(&head, 1, 5);
    insertNode(&head, 10, 10);


    printf("head = %d\n", head->data);

    int length = countNodes(head);

    printf("Nodes = %d\n", length);

    printList(head);




    return 0;
}
