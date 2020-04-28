#include <iostream>

struct Node
{
    int data;
    struct Node *next;
};

void printList(struct Node *n)
{
    while(n != NULL) {
        std::cout << n->data  << std::endl;
        n = n->next;
    }
}
// add node at the front
void push(struct Node** head_ref, int new_data)
{
    // allocate a new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    // put in data
    new_node->data = new_data;
    
    // make next of new node as head
    new_node->next = (*head_ref);
    
    // move the head to point to the new node
    (*head_ref) = new_node;
}

void insertAfter(struct Node* prev_node, int new_data)
{
    // check if given prev_node is NULL
    if(prev_node == NULL) {
        std::cout << "the given previous node cannot be NULL" << std::endl;
        return;
    }
    
    // allocate a new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    // put in data
    new_node->data = new_data;
    
    // make next of new_node as next of prev_node
    new_node->next = prev_node->next;
    
    // move the next of prev_node as new_node
    prev_node->next = new_node;
}

void append(struct Node** head_ref, int new_data)
{
    // allocate node
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node *last = *head_ref;  // used in step 5
    
    // put in data
    new_node->data = new_data;
    
    // make next of new last node NULL
    new_node->next = NULL;
    
    // if the linked list is empty, then make the new node as head
    if(*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    
    // else traverse till last node
    while(last->next != NULL) {
        last = last->next;
    }
    
    // change next of last node
    last->next = new_node;
    return;
}

void deleteNode(struct Node **head_ref, int key)
{
    // store head node
    struct Node* temp = *head_ref, *prev;
    
    // if head node itself holds the key to be deleted
    if(temp  != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    
    // search for key to be deleted and keep track of previous node
    while(temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    
    
    // if key is not present in linked list
    if(temp == NULL) {
        return;
    }
    
    // unlinked node from linked list
    prev->next = temp->next;
    
    // free memory
    free(temp);
}

int main()
{
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
    
    
    // allocate  3 nodes in the heap
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    
    head->data = 1; //assign data
    head->next = second; //link first node to second
    
    second->data = 2; //assign data
    second->next = third; //link second node to third
    
    third->data = 3;
    third->next = NULL;
    
    printList(head);
    
    /* Start with the empty list */
    head = NULL;
    
    // Insert 6.  So linked list becomes 6->NULL
    append(&head, 6);
    
    // Insert 7 at the beginning. So linked list becomes 7->6->NULL
    push(&head, 7);
    
    // Insert 1 at the beginning. So linked list becomes 1->7->6->NULL
    push(&head, 1);
    
    // Insert 4 at the end. So linked list becomes 1->7->6->4->NULL
    append(&head, 4);
    
    // Insert 8, after 7. So linked list becomes 1->7->8->6->4->NULL
    insertAfter(head->next, 8);
    
    std::cout << "Created Linked list is: " <<std::endl;
    printList(head);
    
    std::cout << "deleting node..." <<std::endl;
    deleteNode(&head, 1);
    
    std::cout << "linked list after deletion" <<std::endl;
    printList(head);
    return 0;
}
