/******************************************************************************
Stack- dynamic implementation.

*******************************************************************************/
#include <iostream>

using namespace std;


class stack_element{
    public:
    stack_element *next;
    int value;
    
    stack_element(){
        
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
    void point(stack_element* next_element){
    next=next_element;
    }
   
    
};

 class stack{
     public:
    stack_element null;
    
    stack_element top;
   stack(){
      
       top.point(&null);
      
   }
void push(int value){
  stack_element *s = new stack_element();

 s->set_value(value);
 s->point(top.get_next());
 cout<<"\n"<<s->value<<" is pushed.";
 top.point(s);

}
int pop(){
    int temp =top.get_next()->get_value();
    top.point(top.get_next()->get_next());
    cout<<"\n"<<temp<<" is popped.";
    return temp;
}
void peek(){
    cout<<"The last element is "<<top.get_next->get_value();
}
void print(){
     cout<<"\n"<<"stack contents are-- ";
     stack_element *p = new stack_element();
     p->point(top.get_next());
     while(&*p->get_next()!=&null){
    int temp2 =p->get_next()->get_value();
    cout<<"\n"<<temp2;
         p->point(p->get_next()->get_next());
     }
     delete p;
    
}
};

int main()
{
    cout<<"Hello World";
    stack my_stack;
    my_stack.push(2);
    my_stack.push(3);
    
    my_stack.push(5);
    my_stack.pop();
    my_stack.pop();
    my_stack.push(7);
    my_stack.push(5);

    my_stack.print();
    
    
   
    return 0;
}
