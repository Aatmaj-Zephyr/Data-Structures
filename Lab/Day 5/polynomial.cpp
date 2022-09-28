/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

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
         node* temp;
         temp=&*bottom;

        while(temp->pointer!=NULL){
            cout<<temp->pointer->value;
            temp->point(temp->pointer->pointer);
        }
    }
    
};

linkedlist* addPoly(linkedlist a,linkedlist b){
 linkedlist *c = new linkedlist();
 node *temp1=a.bottom->pointer;
 node *temp2=b.bottom->pointer;
 while(true){
 if(temp1->value == temp2->value){
     c->add(temp1->value+temp2->value,temp1->priority);
      temp1->point(temp1->pointer->pointer);
      temp2->point(temp2->pointer->pointer);
 }
 if(temp1->value > temp2->value){
     c->add(temp1->value,temp1->priority);
      temp1->point(temp1->pointer->pointer);
 }
 if(temp1->value < temp2->value){
     c->add(temp2->value,temp2->priority);
       temp2->point(temp2->pointer->pointer);

 }
 if(temp1->pointer == NULL){
              cout<<"b";

     return c;
 }
if(temp2->pointer == NULL){
              cout<<"a";

     return c;

 }

 }
 return c;
};
int main()
{
    cout<<"Hello World";
linkedlist *mylink=new linkedlist();
mylink->add(2,1);
mylink->add(20,2);
mylink->add(14,4);
//mylink->display();

linkedlist *mylink2=new linkedlist();
mylink2->add(2,1);
mylink2->add(30,3);
mylink2->add(5,4);

//mylink2->display();
linkedlist *c = addPoly(*mylink,*mylink2);
c->display();
    return 0;
}
