#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *head=NULL;
struct Node *temp=NULL;

void insertAtBeg(int val){
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=head;
    newNode->prev=NULL;
    if (head != NULL) {
        head->prev = newNode;
    }
    head=newNode;
}
void insertAtEnd(int val){
    if(head==NULL){
        printf("List is empty..Inserting at beginning");
        insertAtBeg(val);
        return;
    }
    struct Node *newNode= malloc(sizeof(struct Node));
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->data=val;
    newNode->prev=temp;
    newNode->next=NULL;
}
void insertAtPos(int val,int pos){
    if(head==NULL){
        printf("List is empty..Inserting at beginning");
        insertAtBeg(val);
        return;
    }
    if(pos==1){
        insertAtBeg(val);
        return;
    }
    int count=0;
    temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    if(pos>=count){
        printf("position greater than or equal to list count..Inserting at end..");
        insertAtEnd(val);
        return;
    }
    count=1;
    temp=head;
    while(count<pos){
        temp=temp->next;
        count++;
    }
    struct Node *newNode=malloc(sizeof(struct Node));
    newNode->data=val;
    temp->prev->next=newNode;
    temp->prev=newNode;
    newNode->next=temp;

}

void deleteAtBeg(){
    if(head==NULL){
        printf("List is empty");
        return;
    }
    
    temp=head;
    head=head->next;
    if(head != NULL){
        head->prev = NULL;
    }
    free(temp);
}
void deleteAtEnd(){
    if(head==NULL){
        printf("List is empty");
        return;
    }
    temp=head;
    if(temp->next==NULL){
        deleteAtBeg();
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->prev->next=NULL;
    free(temp);
}
void deleteAtPos(int pos){
    if(head==NULL){
        printf("List is empty");
        return;
    }
    if(pos==1){
        deleteAtBeg();
        return;
    }
    temp=head;
    int count=1;
    while(count<pos&&temp->next!=NULL){
        temp=temp->next;
        count++;
    }
    if(count<pos){
        printf("Position greater than or equal to linked list size . deleting at end");
        deleteAtEnd();
        return;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);

}
void search(int val){
    if(head==NULL){
        printf("List is empty");
        return;
    }
    temp=head;
    while(temp!=NULL){
        if(temp->data==val){
            printf("%d found in the list",temp->data);
            break;
        }
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Element not found in the list");
    }
}
void display(){
    if(head==NULL){
        printf("List is empty");
        return;
    }
    temp=head;
    while(temp!=NULL){
        printf("%d",temp->data);
        if(temp->next!=NULL){
            printf("->");
        }
        temp=temp->next;
    }

}
void main(){
    int choice,value,pos;
    printf("linkedlist operations\n");
    do{
        printf("\n\n1.Insert at beginning\n2.Insert at end\n3.Insert at position\n4.Delete at beginning\n5.Delete at End\n6.Delete at position\n7.Display\n8.Search\n9.Exit\nEnter you choice: \n");
        scanf("%d",&choice);
        if(choice!=9 && choice!=4 && choice!=5 &&choice!=6&&choice!=7){
            printf("enter the value");
            scanf("%d",&value);
        }
        switch(choice){
            case 1:insertAtBeg(value);
                    display();
                    break;
            case 2:insertAtEnd(value);
                    display();
                    break;
            case 3:printf("Enter the position(1-n):");
                    scanf("%d",&pos);
                    insertAtPos(value,pos);
                    display(head);
                    break;
            case 4:deleteAtBeg();
                    display();
                    break; 
            case 5:deleteAtEnd();
                    display();
                    break;  
            case 6:printf("Enter the position(1-N):");
                    scanf("%d",&pos);
                    deleteAtPos(pos);
                    display();
                    break;
            case 7:display();
                    break; 
            case 8:search(value);
                    break;  
            case 9:break;
            default:printf("invalid choice");
                    break;
        }
    }while(choice!=9);
}