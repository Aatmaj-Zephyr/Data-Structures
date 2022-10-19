/******************************************************************************
Add two polynomials

*******************************************************************************/
#include <iostream>

using namespace std;

class node{
    public:
    node* pointer;
    int value;
    node(){
        
    }
    public:
    node(node *pointer, int value){
        this->pointer=pointer;
        this->value=value;
    }
    void point(node *pointer){
        this->pointer=pointer;
    }
};
class linkedlist{
        public:

    node *top;
    node * bottom;
    
    /******
     * 
     * Since top and bottom are nodes, edge cases do not come to picture
     * *****/
    linkedlist(){
       top= new node(NULL,-1);
       bottom= new node(NULL,-1);

    }
    node* findbefore(int value){
        node temp;
        temp.point(bottom);
        while(temp.pointer!=top){
            if(temp.pointer->pointer->value==value){
                return temp.pointer;
            }
            temp.point(temp.pointer->pointer);
        }
        //Do nothing if not found
        cout<<"Sorry node not found";
        return NULL;
        
    }
    node* findafter(int value){
        node temp;
        temp.point(bottom->pointer);
        while(&temp!=top){
            if(temp.pointer->value==value){
                return temp.pointer;
            }
            temp.point(temp.pointer->pointer);
        }
        //Do nothing if not found
        cout<<"Sorry node not found";
      return NULL;
    }
    
    void add(int value,int ValueToBeAddedAfter){
        add(new node(NULL,value), ValueToBeAddedAfter);
    }
    void add(node *toBeAdded, int ValueToBeAddedAfter){
         if(top->pointer!=NULL)
       {top->pointer->point(toBeAdded);} //first addition
       if(bottom->pointer==NULL){
           bottom->point(toBeAdded); //first addition
       }
       else{
      node *NodeToBeAddedAfter = findafter(ValueToBeAddedAfter);
      toBeAdded->point(NodeToBeAddedAfter->pointer);
      NodeToBeAddedAfter->point(toBeAdded);
           
       }
    }
    void Delete(int value){
        node *NodeToBeDeleted = findbefore(value);
        NodeToBeDeleted->point(NodeToBeDeleted->pointer->pointer);
    }
     void display(){
         node* temp;
         temp->point(bottom->pointer);
do{
    cout<<"\n"<<temp->pointer->value;
            
            temp->point(temp->pointer->pointer);
}
        while(temp->pointer!=NULL);
        
    }
    
};


int main()
{
  
linkedlist *mylink=new linkedlist();
mylink->add(2,1);
mylink->add(20,2);
mylink->add(280,20);
mylink->add(281,2);
//mylink->display();
mylink->Delete(280);
mylink->display();



cout<<"Hello";

    return 0;
}
