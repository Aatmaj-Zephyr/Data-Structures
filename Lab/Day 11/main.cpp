

#include <iostream>

using namespace std;

int ctr=0;
int visited[6]={0,0,0,0,0};
    int adjustancy[6][6]={{0,1,1,1,1},{1,0,0,0,0},{1,0,0,0,0},{1,0,0,0,0},{1,0,0,0,0}} ;
bool elementnotinvisited(int j){
    for(int i=0;i<6;i++){
     if(visited[i]==j){
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
    for(int i=0;i<6;i++){
        if(adjustancy[value][i]==1){
            if(!elementnotinvisited(i)){
                visitedadd(i);
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
/*
    for(int i=1;i<6;i++){
        int temp;
        cin>>temp;
        adjustancy[i][0]=temp;
        adjustancy[0][i]=adjustancy[i][0];
    }
    cout<<adjustancy;
    for(int i=1;i<6;i++){
       for(int j=1;j<6;j++){
       cout<<"Join "<<adjustancy[i][0]<<" and "<<adjustancy[0][j]<<"? \n";
       cin>>adjustancy[i][j];
    }
    */
    bfs(2);
        
    

    return 0;
}
