#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void printList(struct Node* n)
{
    printf("The list:\n");
    while (n != NULL) {
        printf(" %d ", n->data);
        n = n->next;
    }
    printf("\n");
}
void insert_node(struct Node* prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        printf("Error: the previous node is NULL\n");
        return;
    }

    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));

    new_node->data  = new_data;

    new_node->next = prev_node->next;

    prev_node->next = new_node;
}
//search for value and one you reach it delete it (if the value is repeated then delete only the first appearance
void delete_node(struct Node **head, int value)
{
    struct Node* temp = *head, *prev;

    // If the head node contains the wanted value then delete it
    if (temp != NULL && temp->data == value)
    {
        *head = temp->next;   // Change the head
        free(temp);               // free old head
        return;
    }

    //Search for the wanted value
    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    //In case the value isn't existed in the list
    if (temp == NULL) return;

    prev->next = temp->next;

    free(temp);  // Free memory
}
void insert_first(struct Node** head, int new_data) //insert a node as a head
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    new_node->data  = new_data;

    new_node->next = NULL;

    *head = new_node;
}
int main(){
    struct Node* head = NULL;
    int v;
    printf("Please enter the head value");
    scanf("%d",&v);
    insert_first(&head,v);
    //insert some values after the head
    insert_node(head,3);
    insert_node(head,7);
    insert_node(head,13);
    insert_node(head,5);
    printList(head);
    delete_node(&head,13);
    printf("The list after deleting the node which contains 13\n");
    printList(head);
    return 0;
}