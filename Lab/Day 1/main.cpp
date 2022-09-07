/******************************************************************************
ADT- rational number

value defination
integer numerator
integer denominator


preconditions-
denominator must not be 0

Operator defination.
abstract rationaltype add(rationaltype a, rationaltype b){
preconditions none

preconditions - 
function returs a new rationaltype.
new numerator value is (a.numerator)*(b.denominator)+(b.numerator)*(a.denominator)
new denominator (a.denominator)*(b.denominator)

    
}



abstract rationaltype sub(rationaltype a, rationaltype b){
preconditions none

preconditions - 
function returs a new rationaltype.
new numerator value is (a.numerator)*(b.denominator)-(b.numerator)*(a.denominator)
new denominator (a.denominator)*(b.denominator)
    
}




abstract rationaltype multiply(rationaltype a, rationaltype b){
preconditions none

preconditions - 
function returs a new rationaltype.
new numerator value is (a.numerator)*(b.numerator)
new denominator (a.denominator)*(b.denominator)
    
}

abstract rationaltype divide(rationaltype a, rationaltype b){
preconditions none

preconditions - 
function returs a new rationaltype.
new numerator value is (a.numerator)*(b.denominator)
new denominator (a.denominator)*(b.numerator)
    
}



abstract boolean equate(rationaltype a, rationaltype b){
preconditions none

preconditions - 
returns true iff a.numerator==b.numerator AND a.denominator==b.denominator 
else false
}

*******************************************************************************/
#include <iostream>

using namespace std;
 

class rational{
     public:
    int numerator;
    int denominator;
    public: rational(int p, int q){
     if (q==0){
         throw std::invalid_argument( "received infinity value" );
     }
        this->numerator=p;
       this->denominator=q;
    }
    static rational* add(rational a, rational b){
     return new rational((a.numerator)*(b.denominator)+(b.numerator)*(a.denominator),(a.denominator)*(b.denominator));
    }
     static rational* sub(rational a, rational b){
     return new rational((a.numerator)*(b.denominator)-(b.numerator)*(a.denominator),(a.denominator)*(b.denominator));
    }
     static rational* multiply(rational a, rational b){
     return new rational((a.numerator)*(b.numerator),(a.denominator)*(b.denominator));
    }
    
    static rational* divide(rational a, rational b){
     return new rational((a.numerator)*(b.denominator),(a.denominator)*(b.numerator));
    }
    static bool equate(rational a, rational b){
        if(a.numerator==b.numerator&a.denominator==b.denominator){
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
    cout<<c->numerator<<"\n";
    cout<<rational::equate(*a,*b);
    return 0;
}
/*
a/b

preconditions - b must not be zero

*/

