/******************************************************************************
Hashing

*******************************************************************************/
#include <iostream>
const int len=7;
using namespace std;
class hashtable{
    public: int arr[len];
    public: int collision = 0;
    public: void print(){
        for(int i=0;i<len;i++){
            cout<<arr[i]<<",";
        }
    }
    public: void addquad(int a){
        int temp =hash(a);
        if(arr[temp]!=0){
            collision++;
            temp++;
            //overflow not considered
               for(int i=0;i<len;i++){
                   if(arr[(i*i+temp)%len]==0){
                    arr[(i*i+temp)%len]=a;
                    break;
                   }
                }
                
            }
            else{
                arr[temp]=a;
            }
        }
    public: void addlinear(int a){
        int temp =hash(a);
        if(arr[temp]!=0){
            collision++;
            temp++;
            //overflow not considered
               for(int i=0;i<len;i++){
                   if(arr[(i+temp)%len]==0){
                    arr[(i+temp)%len]=a;
                    break;
                   }
                }
                
            }
            else{
                arr[temp]=a;
            }
        }
    public: bool searchlinear(int a){
         int temp =hash(a);
        if(arr[temp]!=a){
          
            for(int i=0;i<len;i++){
                if(arr[(i+temp)%len]==a){
                    return true;
                }
                
            }
        return false;
        }
        else{
            return true;
        }
    }  
    public: bool searchquad(int a){
         int temp =hash(a);
        if(arr[temp]!=a){
          
            for(int i=0;i<len;i++){
                if(arr[(i*i+temp)%len]==a){
                    return true;
                }
                
            }
        return false;
        }
        else{
            return true;
        }
    }  
    public: int hash(int a){
    return a%10;
        
    }
};
int main()
{    
    hashtable *linear = new hashtable();
    hashtable *quad = new hashtable();
    linear->addlinear(1002);
    linear->addlinear(12);
    linear->addlinear(212);
    linear->addlinear(123);
    linear->addlinear(125);
    cout<<linear->searchlinear(1002)<<"\n";
    cout<<linear->searchlinear(100)<<"\n";
    cout<<linear->searchlinear(123)<<"\n";
    linear->print();
    cout<<"\n"<<linear->collision<<"\n";
    
    quad->addquad(1002);
    quad->addquad(12);
    quad->addquad(212);
    quad->addquad(123);
    quad->addquad(125);
    cout<<quad->searchquad(1002)<<"\n";
    cout<<quad->searchquad(100)<<"\n";
    cout<<quad->searchquad(123)<<"\n";
    quad->print();
    cout<<"\n"<<linear->collision<<"\n";
    cout<<"Hello World";

    return 0;
}
