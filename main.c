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
        printf("EMPTY\n");
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
    if( location == 1 ){
        newNode->next = nextNode;
        *node = newNode;

    } else{

        // Insert at the location given
        while(nextNode != NULL && (i < location ) ){
            i++;
            prevNode = nextNode;
            nextNode = nextNode->next;
        }

        prevNode->next = newNode;
        newNode->next = nextNode;
    }

}

// Delete node at any location
void deleteNode( struct Node** node, int location ) {

    int i = 1;
    struct Node* prevNode;//q
    struct Node* nextNode;//p

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

void DestroyLikedList( struct Node** head ){
    struct Node* temp;
    struct Node* iterator;
    iterator = *head;
    while (iterator){
        temp = iterator->next;
        free(iterator);
        iterator = temp;
    }
    *head = NULL;
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
    struct Node* ptr = NULL;
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
    int num;
    int insert;
    int delete;

    while (fscanf(fp, "%s %d\n",action, &num ) != EOF ){

        insert = strcmp( action, "INSERT" );
        delete = strcmp( action, "DELETE" );

        if ( insert == 0 ){

            // Insert first node to the left
            if ( head == NULL || num < head->data ){
                insertNode( &head, 1, num );
            } else if( num == head->data ){
                // Do nothing
            } else{
                // Traverse the linked list
                ptr = head;

                if( ptr->next == NULL){
                    insertNode( &head, 2, num );

                } else{
                    while( ptr != NULL ){
                        int loc = 0;
                        if ( ptr->data == num ){
                            break;
                        }

                        if ( ptr->data > num ){
                            loc = searchNode( ptr->data,head );
                            insertNode( &head, loc, num );
                            break;
                        }
                        if ( ptr->next == NULL){
                            loc = searchNode( ptr->data, head );
                            insertNode( &head, loc+1, num);
                            break;
                        }
                        ptr = ptr->next;
                    }
                }
            }


        } else if( delete == 0 ){
            if ( head != NULL ){
                int loc = searchNode( num, head );
                deleteNode( &head, loc );
            }

        } else{
            printf("ERROR ACTION\n");

        }
        printList( head );
    }

    // Close the read file
    DestroyLikedList(&head);
    fclose(fp);

    return EXIT_SUCCESS;
}
