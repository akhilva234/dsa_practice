#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int queue[MAX];
int front=-1,rear=-1;

void enqueue(int value){
    if(rear==MAX-1){
        printf("Queue Overflow");
        return;
    }
    queue[++rear]=value;
}
void dequeue(){
    if(front>rear || rear==-1){
        printf("Queue underflow");
        return;
    }
    front++;
}
void display(){
    if(front>rear || rear == -1){
        printf("Queue is empty");
        return;
    }
    for(int i=front;i<=rear;i++){
        printf("%d\t",queue[i]);
    }
}
void main(){
   int n,choice,value;
   printf("\nCreating queue..\n");
   enqueue(2);
   enqueue(45);
   front++;
   printf("\n..Queue Operations..\n");
    do{
        printf("\n\n1.Queue\n2.Dequeue\n3.Display\n4.Exit");
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
            case 4:printf("Exiting...");
                    break;
            default:printf("Invalid choice");
                    break;
        }
    }while(choice!=4);

}

