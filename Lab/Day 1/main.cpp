/******************************************************************************
ADT- rational number

*******************************************************************************/
#include <iostream>

using namespace std;
 class rational{
     public:
    int p;
    int q;
    public: rational(int p, int q){
     if (q==0){
         throw std::invalid_argument( "received infinity value" );
     }
        this->p=p;
       this->q=q;
    }
    static rational* add(rational a, rational b){
     return new rational((a.p)*(b.q)+(b.p)*(a.q),(a.q)*(b.q));
    }
     static rational* sub(rational a, rational b){
     return new rational((a.p)*(b.q)-(b.p)*(a.q),(a.q)*(b.q));
    }
     static rational* multiply(rational a, rational b){
     return new rational((a.p)*(b.p),(a.q)*(b.q));
    }
    
    static rational* divide(rational a, rational b){
     return new rational((a.p)*(b.q),(a.q)*(b.p));
    }
    static bool equate(rational a, rational b){
        if(a.p==b.p&a.q==b.q){
            return true;
        }
        else{
            return false;
        }
    }
};
int main()
{
    cout<<"Hello World\n";
    rational *a = new rational(2,3);
    rational *b = new rational(3,4);
    rational *c = rational::divide(*a,*b);
    cout<<c->p<<"\n";
    cout<<rational::equate(*a,*b);
    return 0;
}
/*
a/b

preconditions - b must not be zero

*/

