#include<stdlib.h>
#include<stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *head){
    struct Node *ptr = head;
    do{
	printf("Element is %d\n", ptr->data);
	ptr = ptr->next;
    }while(ptr!=head);
}

struct Node * insertAtFirst(struct Node *head, int data){
    struct Node *a;
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    a=head->next;
    while(a->next != head){
	a = a->next;
    }
    // At this point p points to the last node of this circular linked list

    a->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;

}
// Case 3
struct Node * insertAtEnd(struct Node *head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head;
 
    while(p->next!=head){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    return head;
}
struct Node * insertAtIndex(struct Node *head, int data, int index){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    struct Node * p = head;
    int i = 0;
 
    while (i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
// Case 1: Deleting the first element from the linked list
struct Node * deleteFirst(struct Node * head){
    struct Node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
// Case 2: Deleting the element at a given index from the linked list
struct Node * deleteAtIndex(struct Node * head, int index){
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    
    p->next = q->next;
    free(q);
    return head;
}

int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    clrscr();
    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 4;
    head->next = second;

    // Link second and third nodes
    second->data = 3;
    second->next = third;

    // Link third and fourth nodes
    third->data = 6;
    third->next = fourth;

    // Terminate the list at the third node
    fourth->data = 1;
    fourth->next = head;
  printf("Circular Linked list before insertion\n");
    linkedListTraversal(head);
    head = insertAtFirst(head, 6969);
    printf("Circular Linked list after insertion\n");
    linkedListTraversal(head);

     printf("Circular Linked list before insertion\n");
    linkedListTraversal(head);
    head = insertAtEnd(head, 11);
    printf("Circular Linked list after insertion\n");
    linkedListTraversal(head);

     printf("Circular Linked list before insertion\n");
    linkedListTraversal(head);
    head = insertAtIndex(head, 58 ,3);
    printf("Circular Linked list after insertion\n");
    linkedListTraversal(head);
  
     printf("Circular Linked list before deletion\n");
    linkedListTraversal(head);
    head = deleteFirst(head);
    printf("Circular Linked list after deletion\n");
    linkedListTraversal(head);

    printf("Circular Linked list before deletion\n");
    linkedListTraversal(head);
    head = deleteAtIndex(head,4);
    printf("Circular Linked list after deletion\n");
    linkedListTraversal(head);



     getch();
    return 0;
}

