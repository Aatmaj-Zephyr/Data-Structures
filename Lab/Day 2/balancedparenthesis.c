#include<stdio.h>
#include<stdlib.h>
struct node{
    char data;
    struct node* next;
};
char peek(struct node* ptr){
    return ptr->data;
}
struct node* insertatstart(struct node* ptr,char par){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data=par;
    temp->next= ptr;
    return temp;
}
struct node* pop(struct node*ptr){
    struct node* temp=ptr;
    ptr=ptr->next;
    free(temp);
    return ptr;
}
int main(){
    struct node* head=(struct node*)malloc(sizeof(struct node));
    head->next=NULL;
    char par[50]={0};
    printf("\nEnter the expression less than length 50\n");
    scanf("%s",par);
    for(int i=0;i<50;i++){
        if(par[i]=='('){
            head=insertatstart(head,'(');
        }
        else if(par[i]==')'){
            if(peek(head)=='('){
                head=pop(head);
            }
            else{
                head=insertatstart(head,')');
            }
        }
        else if(par[i]=='{'){
            head=insertatstart(head,'{');
        }
        else if(par[i]=='}'){
            if(peek(head)=='{'){
                head=pop(head);
            }
            else{
                head=insertatstart(head,'}');
            }
        }
        else if(par[i]=='['){
            head=insertatstart(head,'[');
        }
        else if(par[i]==']'){
            if(peek(head)=='['){
                head=pop(head);
            }
            else{
                head=insertatstart(head,']');
            }
        }
    }
    if(head->next==NULL){
        printf("The parenthesis is balanced\n");
    }
    else{
        printf("The parenthesis is not balanced\n");
    }
    return 0;
}
