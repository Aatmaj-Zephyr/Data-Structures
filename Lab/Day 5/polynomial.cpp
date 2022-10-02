/******************************************************************************
Add two polynomials

*******************************************************************************/
#include <iostream>

using namespace std;

class node{
    public:
    node* pointer;
    int value;
    int priority;
    node(){
        
    }
    public:
    node(node *pointer, int value,int priority){
        this->pointer=pointer;
        this->value=value;
        this->priority=priority;
    }
    void point(node *pointer){
        this->pointer=pointer;
    }
};
class linkedlist{
        public:

    node *top;
    node * bottom;
    linkedlist(){
       top= new node(NULL,0,0);
       bottom= new node(NULL,0,0);

    }
    void add(node *toBeAdded){
       if(top->pointer!=NULL)
       {top->pointer->point(toBeAdded);}
       if(bottom->pointer==NULL){
           bottom->point(toBeAdded);
       }
        top->point(toBeAdded);
    }
    void add(int value,int priority){
        add(new node(NULL,value,priority));
    }
     void display(){
         node temp;
         temp.point(bottom->pointer);
do{
    cout<<"\n"<<temp.pointer->value<<"*"<<"x^("<<temp.pointer->priority<<")";
            
            temp.point(temp.pointer->pointer);
}
        while(temp.pointer!=NULL);
        
    }
    
};

linkedlist* addPoly(linkedlist a,linkedlist b){
 linkedlist *c = new linkedlist();
 node temp1;
 temp1.point(a.bottom->pointer);
 node temp2;
 temp2.point(b.bottom->pointer);

 
 
 for (int i=0;0==0;i++){
 //Only for integral powers of x
 //assuming sorted polynomials
 int temp3=0;
  if(temp1.pointer==NULL && temp2.pointer==NULL)
 {
     break;
 }
 if(temp1.pointer!=NULL && temp1.pointer->priority==i){
 temp3=temp3+temp1.pointer->value;
 temp1.point(temp1.pointer->pointer);
 }
 
 if(temp2.pointer!=NULL && temp2.pointer->priority==i){
 temp3=temp3+temp2.pointer->value;
 temp2.point(temp2.pointer->pointer);
 //cout<<temp3;
 }
 c->add(temp3,i);

 }
//a.display();
 return c;
};

linkedlist* minusPoly(linkedlist a){
    node* temp=a.bottom;
 linkedlist *c = new linkedlist();
    while(temp->pointer!=NULL){
        c->add(-temp->pointer->value,temp->pointer->priority);
        temp->point(temp->pointer->pointer);
    }
    return c;
}

linkedlist* subPoly(linkedlist a,linkedlist b){
    
    return addPoly(a,*minusPoly(b));
}
int main()
{
  
linkedlist *mylink=new linkedlist();
mylink->add(2,1);
mylink->add(20,2);
mylink->add(14,4);
//mylink->display();

linkedlist *mylink2=new linkedlist();
mylink2->add(7,0);
mylink2->add(2,1);
mylink2->add(31,3);
mylink2->add(5,4);

cout<<"Hello";

//mylink2->display();
linkedlist *c = addPoly(*mylink,*mylink2);

c->display();
        


linkedlist *d = subPoly(*mylink,*mylink2);
d->display();

    return 0;
}
