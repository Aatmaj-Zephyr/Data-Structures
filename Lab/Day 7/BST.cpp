/******************************************************************************

array implementation of binary search tree.
*******************************************************************************/
#include <iostream>
const int len = 31;
using namespace std;
class structure{
   public:  int arr[len];
   public:  structure(){
    
    }
    public: void print(){
        for(int i=0;i<len;i++){
            //cout<<arr[i]<<",";
        }
        infix(1); cout<<"\n";
        prefix(1); cout<<"\n";
        postfix(1); cout<<"\n";
        
    }
    public : void infix(int a){
        if(arr[a]!=0){
            if(a<len){
                 infix(a*2);
            cout<<arr[a]<<",";
           
            infix(a*2+1);
           }
        }
        
    }
     public : void prefix(int a){
        if(arr[a]!=0){
            if(a<len){
                    cout<<arr[a]<<",";
                 infix(a*2);

            infix(a*2+1);
           }
        }
        
    }
     public : void postfix(int a){
        if(arr[a]!=0){
            if(a<len){
                 infix(a*2);
            
            infix(a*2+1);
            cout<<arr[a]<<",";
           }
        }
        
    }
    
   public: void add(int a){
          int currentnode=1;
      while(true){
          int currentval=arr[currentnode];
          if(currentval==0){
              arr[currentnode]=a;
              break;
          }
          if(currentval>a){
              currentnode=2*currentnode+1;
          }
          else if(currentval<a){
              currentnode=2*currentnode;
          }
          if(currentnode>len){
              cout<<"Overflow";
             break;
          }
          
      }
    }
 public: int search(int a){
      int currentnode=1;
      while(true){
          int currentval=arr[currentnode];
          if(currentval==a){
              return currentnode;
          }
          if(currentval>a){
              currentnode=2*currentnode+1;
          }
          else if(currentval<a){
              currentnode=2*currentnode;
          }
          if(currentnode>len){
              return -1;
          }
          
      }
  }  
};
int main()
{   structure *my=new structure();
my->add(20);
my->add(37);
my->add(32);
my->add(13);
my->add(9);
my->add(34);
//cout<<my->search(2);
my->print();
    cout<<"Hello World";

    return 0;
}
