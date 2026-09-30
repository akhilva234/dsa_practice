#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
 struct Node *top=NULL;

void push(int value){

    struct Node *newNode=malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack Overflow! Memory allocation failed.\n");
        return;
    }
    newNode->next=top;
    newNode->data=value;
    top=newNode;
}
void pop(){
    if(top==NULL){
        printf("Stack underflow\n");
        return;
    }
    struct Node *temp=top;
    top=top->next;
    free(temp);
}
void peek(){
    if(top==NULL){
        printf("Stack underflow\n");
        return;
    }
    printf("Top node is:%d",top->data);
}
void display(){
    if(top==NULL){
        printf("Stack underflow\n");
        return;
    }
    struct Node *temp=top;
    while(temp!=NULL){
        printf("%d",temp->data);
        if(temp->next!=NULL){
            printf("->");
        }
        temp=temp->next;
    }
}

void main(){
    int choice,value;
    printf("\n..Stack Operations..\n");
    do{
        printf("\n\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("Enter the value: ");
                    scanf("%d",&value);
                    push(value);
                    display();
                    break;
            case 2:pop();
                    display();
                    break;

            case 3:peek();
                    display();
                    break;
            case 4:display();
                    break;
            case 5:printf("Exiting...");
                    break;
            default:printf("Invalid choice");
                    break;
        }
    }while(choice!=5);

}