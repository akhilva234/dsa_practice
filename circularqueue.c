#include<stdio.h>
#define MAX 5
int front=-1;
int rear=-1;
int q[MAX];

void enqueue(int value){
    if((rear+1)%MAX==front){
        printf("Queue overflow!!");
        return;
    }
    if (front == -1)
    {
        front = 0;
        rear = 0;
        
    }else{
        rear=(rear+1)%MAX;
    }
    
    q[rear]=value;
}
void dequeue(){
    if(front==-1){
        printf("Queue underflow!!");
        return;
    }
    
    if(front==rear){
        front=-1;
        rear=-1;
    }else{
        front=(front+1)%MAX;
    }
}
void display(){
    if(front  == -1){
        printf("Queue is empty");
        return;
    }
    int i = front;
    while(1){
        printf("%d\t",q[i]);
        if(i==rear)
            break;
        i=(i+1)%MAX;
    }
}
void main(){
   int n,choice,value;
   printf("\nCreating queue..\n");
   printf("\n..Circular Queue Operations..\n");
    do{
        printf("\n\n1.Queue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice");
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
