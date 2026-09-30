#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node *rear=NULL;
struct Node *front=NULL;

void enqueue(int value){
    struct Node *newNode = malloc(sizeof(struct Node));
    if(newNode==NULL){
        printf("Queue Overflow! Memory allocation failed.\n");
        return;
    }
    newNode->data=value;
    newNode->next=NULL;
    if(front==NULL){
        front=newNode;
        rear=newNode;
    }else{
        rear->next=newNode;
        rear=newNode;
    }
         
}
void dequeue(){
    if(front==NULL){
        printf("Queue underflow!\n");
        return;
    }
    struct Node *temp=front;
    front=front->next;
    printf("Deleted node %d\n",temp->data);
    free(temp);
}

void peek(){
    if(front==NULL){
        printf("Queue is empty!\n");
        return;
    }
    printf("Element at front is %d",front->data);
}

void display(){
    if(front==NULL){
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue is..:");
    struct Node *temp=front;
    while(temp!=NULL){
        printf("%d",temp->data);
        if(temp->next!=NULL){
            printf("->");
        }
        temp=temp->next;
    }
}
int main(){
    int n,choice,value;
     printf("\n..Queue Operations..\n");
    do{
        printf("\n\n1.Enqueue\n2.Dequeue\n3.Display\n4.Peek\n5.Exit\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("Enter the value: ");
                    scanf("%d",&value);
                    enqueue(value);
                    display();
                    break;
            case 2:dequeue();
                    display();
                    break;
            case 3:display();
                    break;
            case 4:peek();
                    break;
            case 5:printf("Exiting...");
                    break;
            default:printf("Invalid choice");
                    break;
        }
    }while(choice!=5);
}