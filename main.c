#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//  Data Structure Linked List Node
struct Node{
    int data;
    struct Node* next;
};

// Print the LinkList
void printList( struct Node* node ){
    if ( node == NULL ){
        printf("empty\n");
    }
    while ( node != NULL ){

        printf("%d ", node->data);
        node = node->next;
        if (node == NULL){
            printf("\n");
        }
    }
}

// Count the nodes First Node
int countNodes( struct Node* head ){

    // Initialize head and counter
    struct Node* current = head;
    int count = 0;

    // Count the nodes
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
	    free(newNode);
        return;
    }

    newNode->data = data;
    nextNode = *node;

    // Insert in the beginning
    if( location == 1 || nextNode == NULL ){
        newNode->next = *node;
        *node = newNode;

    } else{

        // Insert at the location given
        while(nextNode != NULL && (i < location ) ){
            i++;
            prevNode = nextNode;
            nextNode = nextNode->next;
        }

        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }

}

// Delete node at any location
void deleteNode( struct Node** node, int location ) {

    int i = 1;
    struct Node* prevNode;
    struct Node* nextNode;

    // If linked list empty just return
    if ( *node == NULL || location == 0){
        return;
    }

    nextNode = *node;

    //Delete the first node
    if ( location == 1 ){
        *node = (*node)->next;
        free(nextNode);
        return;

    } else{

        // Delete from any other location
        while ( nextNode != NULL && ( i < location ) ){
            i++;
             prevNode = nextNode;
             nextNode = nextNode->next;
        }

        // Delete last node
        if ( nextNode == NULL ){
            // Do nothing
            //printf("location does not exist\n");
            return;

        } else{
            prevNode->next = nextNode->next;
            free(nextNode);
        }
    }

}

// Search data
int searchNode(int key, struct Node* node){

    // Return Zero not found
    int location = 0;
    struct Node* ptr = node;

    while ( ptr != NULL){

        if (ptr->data == key){
            location++;
            break;
        }
        location++;

        ptr = ptr->next;

        if ( ptr == NULL ){
            location = 0;
            break;
        }
    }

    return location;
}

// TEST
void testLinkedList(){

    // Initialize
    struct Node* head = NULL;

    // TEST insert nodes in linked list
    insertNode(&head, 0,0); // empty
    printList(head);
    insertNode(&head, 10,1); // 1
    printList(head);
    insertNode(&head, 10,2); // 1 2
    printList(head);
    insertNode(&head, 1,3); // 3 1 2
    printList(head);

    // TEST delete nodes in linked list
    deleteNode(&head , 10); // 3 1 2
    printList(head);
    deleteNode(&head , 0); // 3 1 2
    printList(head);
    deleteNode(&head , 2); // 3 2
    printList(head);
    deleteNode(&head , 2); // 3
    printList(head);
    deleteNode(&head , 1); // empty
    printList(head);
    deleteNode(&head , 1); // empty
    printList(head);

}

int main(int argc, char* argv[argc+1]) {

    struct Node* head = NULL;
    // File name from the arguments
    if ( argc != 2 ){
        return EXIT_SUCCESS;
    }

    // Declare the read and write pointers
    FILE* fp;

    fp = fopen(argv[1], "r");

    // Check if the file unable to open
    if (fp == NULL){
        printf("Unable to read the file \n");
        return EXIT_SUCCESS;
    }

    // Get the number from file
    char action[10];
    int data;
    int delete;
    int insert;

    while (fscanf(fp, "%s %d\n",action, &data ) != EOF ){
        delete = strcmp( action, "DELETE" );
        insert = strcmp( action, "INSERT" );
        if ( delete == 0 ){
            printf("DELETE\n");

        } else if( insert == 0 ){
            printf("INSERT\n");

        } else{
            printf("ERROR\n");

        }
    }

    // Close the read file
    fclose(fp);

    return EXIT_SUCCESS;
}
