#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

    void insertAtBeg(struct Node *head,int value){
    struct Node *newNode=malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=head->next;
    head->next=newNode;
}
void insertAtEnd(struct Node *head,int value){
    struct Node *newNode=malloc(sizeof(struct Node));
    if(head->next==NULL){
        insertAtBeg(head,value);
        return;
    }
    struct Node *temp=head->next;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    newNode->data=value;
    temp->next=newNode;
    newNode->next=NULL;
}
void insertAtPos(struct Node *head,int value,int pos){
    if(head->next==NULL){
        insertAtBeg(head,value);
        return;
    }
    if(pos<=1){
        printf("position less than or equal to one inserting at beginning");
        insertAtBeg(head,value);
        return;
    }
    int count=1;
    struct Node *temp=head->next;
    while(count<pos-1 && temp->next!=NULL){
        temp=temp->next;
        count++;
    }
    struct Node *newNode=malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=temp->next;
    temp->next=newNode;

}
void deleteAtBeg(struct Node *head){
    if(head->next==NULL){
        printf("list is empty..");
        return;
    }
   struct Node *temp=head->next;
   head->next=temp->next;
   printf("Deleted..%d",temp->data);
   free(temp);
    
}
void deleteAtEnd(struct Node *head){
     if(head->next==NULL){
        printf("list is empty..");
        return;
    }
    struct Node *temp=head->next;
     if(temp->next==NULL){
        deleteAtBeg(head);
        return;
    }
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    struct Node *newNode=temp->next;
    printf("Deleted:%d",newNode->data);
    temp->next=NULL; 
    free(newNode); 
}
void deleteAtPos(struct Node *head,int pos){
    if(head->next==NULL){
        printf("list is empty..");
        return;
    }
    if(pos<=1){
        printf("position less than or equal to one deleting at beginning");
        deleteAtBeg(head);
        return;
    }
    struct Node *temp=head->next;
    int count=1;
    while(count<pos-1&&temp->next->next!=NULL){
        temp=temp->next;
        count++;
    }
    if(count<pos-1){
        printf("Position greater than or equal to linked list size . deleting at end");
        deleteAtEnd(head);
        return;
    }
    struct Node *newNode=temp->next;
    temp->next=newNode->next;
    printf("Deleted:%d",newNode->data);
    free(newNode);

}
void display(struct Node *head){
    printf("Linkedlist is..\n");
    if(head->next==NULL){
        printf("Empty linkedlist");
    }
    struct Node *temp=head->next;
    while(temp!=NULL){
        printf("%d",temp->data);
        if(temp->next!=NULL)
            printf("->");
        temp=temp->next;
    }
}
void main(){
    int choice,value,pos;
    struct Node *head;
    head=malloc(sizeof(struct Node));
    head->next=NULL;
    printf("linkedlist operations\n");
    do{
        printf("\n\n1.Insert at beginning\n2.Insert at end\n3.Insert at position\n4.Delete at beginning\n5.Delete at End\n6.Delete at position\n7.Display\n8.Exit\n\n");
        scanf("%d",&choice);
        if(choice!=8 && choice!=4 && choice!=5 &&choice!=6&&choice!=7){
            printf("enter the value");
            scanf("%d",&value);
        }
        switch(choice){
            case 1:insertAtBeg(head,value);
                    display(head);
                    break;
            case 2:insertAtEnd(head,value);
                    display(head);
                    break;
            case 3:printf("Enter the position");
                    scanf("%d",&pos);
                    insertAtPos(head,value,pos);
                    display(head);
                    break;
            case 4:deleteAtBeg(head);
                    display(head);
                    break; 
            case 5:deleteAtEnd(head);
                    display(head);
                    break;  
            case 6:printf("Enter the position");
                    scanf("%d",&pos);
                    deleteAtPos(head,pos);
                    display(head);
                    break;
            case 7:display(head);
                    break;   
            case 8:break;
            default:printf("invalid choice");
                    break;
        }
    }while(choice!=8);
}