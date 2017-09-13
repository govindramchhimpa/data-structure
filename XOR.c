#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node* npx;
};
 
/* returns XORed value of the node addresses */
struct node* XOR(struct node *a, struct node *b) {
    return (struct node*) ((unsigned int) (a) ^ (unsigned int) (b));
}
 

void insert(struct node **head_ref, int data) {
    // Allocate memory for new node
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->npx = XOR(*head_ref, NULL);
    if (*head_ref != NULL) {
        // *(head_ref)->npx is XOR of NULL and next. So if we do XOR of
        // it with NULL, we get next
        struct node* next = XOR((*head_ref)->npx, NULL);
        (*head_ref)->npx = XOR(new_node, next);
    }
 
    // Change head
    *head_ref = new_node;
}
 
// prints contents of doubly linked list in forward direction
void printList(struct node *head) {
    struct node *curr = head;
    struct node *prev = NULL;
    struct node *next;
 
    printf("Following are the nodes of Linked List: \n");
 
    while (curr != NULL) {
        // print current node
        printf("%d ", curr->data);
 
        // get address of next node
        next = XOR(prev, curr->npx);
 
        // update prev and curr
        prev = curr;
        curr = next;
    }
}
 
int main() {
    struct node *head = NULL;
    int n,i,value;
    printf("how many values u want 2 enter:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
	scanf("%d",&value);
    insert(&head, value);}
    printList(head);
 
    return (0);
}
