#include <iostream>

using namespace std;

int main()
{   int len=5;
int range=5;
    int unsortArray[len+1];
    for(int i=0;i<=len;i++){
        cin>>unsortArray[i];
    }
     int countArray[range]={0};
     
     //update count array 
     for(int i=0;i<=len;i++){
    countArray[unsortArray[i]]++;
    }
    
     //Cumulative addition
     for(int i=1;i<=len;i++){
    countArray[i]+=countArray[i-1];
    }
    //rightshift
     for(int i=len;i>0;i--){
    countArray[i]=countArray[i-1];
    }
    
    //sortArray
    int sortArray[len]={};
     for(int i=0;i<=len;i++){
         int temp = unsortArray[i];
    sortArray[countArray[temp]]=temp;
     countArray[temp]++;
    }
    
    cout<<"Hello World";
 for(int i=0;i<=len;i++){
    cout<<"\n"<<sortArray[i];
    }
    return 0;
}
