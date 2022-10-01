#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    char data;
    struct node* next;
};
char peek(struct node* head){
    return head->data;
}
void display(struct node* head){
    while(head!=NULL){
        printf("%c",head->data);
        head=head->next;
    }
    printf("\n\n");
}
struct node* push(struct node* head,char val){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data=val;
    temp->next=head;
    return temp;
}
struct node* pop(struct node* head){
    struct node* temp = head;
    if(temp->data!=')'){
        printf("%c",temp->data);
    }
    head=head->next;
    free(temp);
    return head;
}
int main(){
    struct node* head=(struct node*)malloc(sizeof(struct node));
    head->next=NULL;
    head->data=')';
    char str[50]={0};
    printf("Enter the expression\n");
    scanf("%s",str);
    for(int i=0;i<50;i++){
        if(str[i]!=0 && str[i+1]==0){
            str[i+1]=')';
            break;
        }
    }
    printf("\n");
    printf("The postfix expression is\n");
    for(int i=0;i<strlen(str);i++){
        if(str[i]=='-'||str[i]=='+'||str[i]=='*'||str[i]=='/'||str[i]=='^'||str[i]=='('||str[i]==')'){
            if(str[i]=='('){
                head=push(head,')');
            }
            else if(str[i]==')'){
                while(peek(head)!=')'){
                    head=pop(head);
                }
                if(head!=NULL){
                    head=pop(head);
                }
            }
            else if(str[i]=='-'||str[i]=='+'){
                if(head->next==NULL){
                    head=push(head,str[i]);
                }
                else if(peek(head)!=')'){
                    head=pop(head);
                    head=push(head,str[i]);
                }
                else{
                    head=push(head,str[i]);
                }
            }
            else if(str[i]=='^'){
                head=push(head,str[i]);
            }
            else if(str[i]=='*'||str[i]=='/'){
                if(head->next==NULL){
                    head=push(head,str[i]);
                }
                else{
                    if(peek(head)=='^'){
                        head=pop(head);
                        head=push(head,str[i]);
                    }
                    else if(peek(head)=='-'||peek(head)=='+'){
                        head=push(head,str[i]);
                    }
                    else if(peek(head)==')'){
                        head=push(head,str[i]);
                    }
                    else{
                        head=pop(head);
                        head=push(head,str[i]);
                    }
                }
            }
        }
        else{
            printf("%c",str[i]);
        }
    }
    printf("\n");
    return 0;
}
