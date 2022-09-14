/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;


class stack_element{
    public:
    stack_element *next;
    int value;
    
    stack_element(){;
    
    }
    stack_element(stack_element next_element, int value_){
    next=&next_element;
    value=value_;
    }
    void set_value( int value_){
        value=value_;
    }
    
    int get_value(){
     //  cout<<"\n"<<value;
        return value;
    }
     stack_element* get_next(){
        return next;
    }
    void point(stack_element next_element){
    next=&next_element;
    }
    void print(){
        cout<<"\n"<<value;
        /*if(next!=NULL){
        next->print();
        }*/
    }
    
};

 class stack{
     public:
    stack_element null;
    
    stack_element top;
   stack(){
       top.point(null);
       null.set_value(0);
      // null.point(NULL)
        top.set_value(100);
   }
void push(int value){
 stack_element *s= new stack_element(*top.get_next(),value);
 top.point(*s);
}
int pop(){
    int temp =top.get_next()->get_value();
    top.point(*top.get_next());
    cout<<"\n"<<temp;
    return temp;
}
void print(){
    top.get_value();
     stack_element *p;
     p=&top;
    /* while(p!=&null){
         p->print();
         p=p->get_next();
     }*/
    //top.get_next().print();
    top.print();
}
};

int main()
{
    cout<<"Hello World";
    stack my_stack;
    my_stack.push(2);
    my_stack.push(3);
    my_stack.pop();
    my_stack.push(5);
    my_stack.pop();
    my_stack.pop();
   // my_stack.print();
    
    /*for(int i=10;i<=0;i--){
        stack_element temp;
        temp
    }
    */
   
    return 0;
}

