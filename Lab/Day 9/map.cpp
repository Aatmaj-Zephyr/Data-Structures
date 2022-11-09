#include<map>
#include <iostream>

using namespace std;

int main()
{
    map<int, int> mymap;
    cout<<"\n Checking if map is empty......."<<mymap.empty();
    mymap.insert({1,2});
    cout<<"\n Inserting 1,2 into the map.......";
    mymap.insert({3,2});
    cout<<"\n Inserting 3,2 into the map.......";
    mymap.insert({3,5});
    cout<<"\n Inserting 3,5 into the map.......(wont work)";
    mymap.insert({5,3});
    cout<<"\n Inserting 5,3 into the map.......(wont work)";
    cout<<"\n Iterating through the map and printing each value.......\n";
    for(auto i=mymap.begin();i!=mymap.end();i++){
        cout<<"("<<i->first<<i->second<<")"<<"\n";
    }
    mymap.erase(3);
    cout<<"\n Erasing 3 key from the map.......";
    cout<<"\n Iterating through the map and printing each value.......\n";
    for(auto i=mymap.begin();i!=mymap.end();i++){
        cout<<"("<<i->first<<i->second<<")"<<"\n";
    }
    mymap.clear();
    cout<<"\n Clearing map.......";
    cout<<"\n Iterating through the map and printing each value(empty).......\n";
    for(auto i=mymap.begin();i!=mymap.end();i++){
        cout<<"("<<i->first<<i->second<<")"<<"\n";
    }
    
    

    return 0;
}
