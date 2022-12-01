

#include <iostream>

using namespace std;

//for graph of fixed size 6
ine len=6;
int ctr=0;
int visited[6]={-1,-1,-1,-1,-1,-1};
int adjustancy[6][6];//{{0,1,1,1,1},{1,0,0,0,0},{1,0,0,0,0},{1,0,0,0,0},{1,0,0,0,0}} ;
bool searchinvisited(int j){
    for(int i=0;i<6;i++){
     if(visited[i]==j){
        // cout<<j;
         return true;
     }   
    }
    return false;
}
void visitedadd(int j){
    visited[ctr]=j;
    ctr++;
}
int bfs( int value){
    visitedadd(value);
    for(int i=0;i<6;i++){
        if(adjustancy[value][i]==1){
          //  cout<<(searchinvisited(i));
            if(!searchinvisited(i)){ //element not visited already
                
                bfs(i);
            }
        }
}
cout<<value;
return 0;

}
int main()
{   cout<<"Hello World \n";

int ans[6];


  
    for(int i=0;i<6;i++){
       for(int j=0;j<6;j++){
       cout<<"Join "<<i<<" and "<<j<<"? \n";
       cin>>adjustancy[i][j];
    }
    }
    
    bfs(2);
        
    

    return 0;
}
