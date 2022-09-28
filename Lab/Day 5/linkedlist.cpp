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
    void add(int value){
        add(new node(NULL,value,0));
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

int main()
{
    cout<<"Hello World";
linkedlist *mylink=new linkedlist();
mylink->add(2);
mylink->add(20);

mylink->display();
    return 0;
}
