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
   bool empty(){
       if(&null==top.get_next()){
           return true;
       }
       return false;
   }
void push(int value){
    
  stack_element *s = new stack_element();

 s->set_value(value);
 s->point(top.get_next());
 top.point(s);

}
int pop(){
    if(empty()==false){
    int temp =top.get_next()->get_value();
    top.point(top.get_next()->get_next());
    return temp;
}
}
int peek(){
    return top.get_next()->get_value();
}
void print(){
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
    stack my_stack;
    
      string str;
  //BAD QUALITY CODE
    // Taking string input using getline()
    getline(cin, str);
    for (int i = 0; i <= str.length(); i++){
        if(str[i]=='('){
            my_stack.push(0);
        }
        if(str[i]=='{'){
            my_stack.push(1);
        }
        if(str[i]=='['){
            my_stack.push(2);
        }
        if(str[i]==')'){
            if(my_stack.peek()!=0){
                cout<<"wrong";
                return 0;
            }
            else{
                my_stack.pop();
            }
        }
        if(str[i]=='}'){
            if(my_stack.peek()!=1){
                cout<<"wrong";
                return 0;
            }
            else{
                my_stack.pop();
            }
        }
        if(str[i]==']'){
            if(my_stack.peek()!=2){
                cout<<"wrong";
                return 0;
            }
            else{
                my_stack.pop();
            }
        }
    }
    if(my_stack.empty()==false){
        cout<<"wrong";
        return 0;
    }
    cout<<"correct";
    my_stack.print();
    
    
   
    return 0;
}
