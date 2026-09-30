#include<stdio.h>
#define MAX 10
int top=-1;
int arr[MAX];
void push(int value){
    if(top==MAX-1){
        printf("\nstack overflow");
        return;
    }
    top++;
    arr[top]=value;
    printf("Pushed into stack:%d\n",arr[top]);
}
void pop(){
    if(top==-1){
        printf("\nstack underflow");
        return;
    }
    printf("Popped from stack:%d\n",arr[top]);
    top--;
    
}

void peek(){
    printf("Top element is:%d\n",arr[top]);
}
void display(){

    if(top<0){
        printf("Stack is empty");
        return;
    }
    for(int i=top;i>=0;i--){
        printf("%d\t",arr[i]);
    }
}

void main(){
    int n,choice,value;
    printf("\nCreating Stack..\n");
    push(10);
    push(19);

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