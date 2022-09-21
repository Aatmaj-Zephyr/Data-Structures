/******************************************************************************
static implementation of stack

*******************************************************************************/
#include <iostream>

using namespace std;

class queue{
  int *arr;
  int top;
  int bottom;
  int Size;
  public:
  queue(int size){
      arr = new int [size];
      Size=size;
      top=0;
      bottom = 0;
  }
  void add(int a){
      if(top>Size){
          cout<<"Overflow"<<"\n";
          
      }else{
      arr[top]=a;
      top++;}
  }
  int pop(){
      if(bottom==top){
          cout<<"underflow"<<"\n";
          top=0;
          bottom=0;
          
      }else{
      
      bottom++;
      return arr[bottom-1];//alternative to temp method of removal
      }
  }
  void display(){
      for (int i= bottom;i<top;i++){
          cout<<arr[i]<<" ";
      }
      cout<<"\n";
  }
};
int main()
{
    queue *my_queue = new queue(2);
    my_queue->add(2);
     my_queue->add(3);
      my_queue->add(4);
       my_queue->pop();
        my_queue->add(4);
    my_queue->display();
    my_queue->pop();
    my_queue->pop();
    my_queue->pop();
      my_queue->display();
      my_queue->add(2);
     my_queue->add(3);
       my_queue->display();
    return 0;
}
