/******************************************************************************


*******************************************************************************/
#include <iostream>

using namespace std;
class queue_element{
    public:
  int priority;
  string name;
  queue_element(){
      //default constructor
  }
  queue_element(string a,int p){
      priority = p;
      name = a;
  }
};
class queue{
      public:

  queue_element *arr;
  int top;
  int bottom;
  int Size;
  public:
  queue(){
      //default constructor
  }
  queue(int size){
      arr = new queue_element[size];
      Size=size;
      top=0;
      bottom = 0;
  }
  void add(string name,int priority){
      if((top)>=Size){
          cout<<"Overflow"<<"\n";
          
      }else{
          
      queue_element *a= new queue_element(name,priority);
    
          arr[top]=*a;
          top++;
          sort();
      }}
      
   void sort(){
       if(top>1){
       for( int temp=top-1;temp>0;temp--){
       if(arr[temp].priority<arr[temp-1].priority){
           //swap;
           queue_element temp2=arr[temp];
           arr[temp]=arr[temp-1];
           arr[temp-1]=temp2;}
       }}
   }   
  queue_element pop(){
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
          cout<<arr[i].name<<" , ";
      }
      cout<<"\n";
  }
};
int main()
{  
    queue *my_queue = new queue(4);
    my_queue->add("enid blyton",4);
    my_queue->add("Harry potter",2);
    my_queue->add("sherlock homes",1);
         my_queue->add("pokemon",3);
         

    my_queue->display();
  
    return 0;
}
