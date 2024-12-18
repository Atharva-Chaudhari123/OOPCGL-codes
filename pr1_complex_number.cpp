
/*
Implement a class Complex which represents the Complex Number data type. Implement the following operations: 
 
1. Constructor (including a default constructor which creates the complex number 0+0i). 
 
2. Overloaded operator+ to add two complex numbers. 
 
3. Overloaded operator* to multiply two complex numbers. 
 
4. Overloaded << and >> to print and read Complex Numbers.
*/

#include<iostream>
using namespace std ;

class complex{
    public: 
    int real ;
    int imag ;

    complex(){
        //1) complex number 0+0i
        this-> real = 0 ;
        this-> imag = 0 ;
    }
    void input(){
        cout<<"Enter real : ";
        cin >> real ;
        cout<< "Enter imag : " ;
        cin >> imag ;
    }
    //2 )
    complex operator + (complex &temp){
        complex res ;
        res.real  = this->real + temp.real ; 
        res.imag = this->imag + temp.imag ;

        return res;
    }
    //3) 
    complex operator * (complex &temp) {
        complex res ;
        res.real = this-> real * temp.real ;
        res.imag = this->imag * temp.imag ;
        return res ;
    }
    // 4)
    friend istream &operator >>(istream &in ,complex &temp){
        cout<<"Enter real : " ;
        in >> temp.real ;
        cout<< "Enter imag : " ;
        in >> temp.imag ;

        return in ;
    }
    //we have to declare this function as friend because , in is an object of
    // of 3rd party class , which cannot directly have access to the members of a class
    //so in order to manipulate such members we have declared the function as friend
    // so that istream object in will be able to access those members of the class


    friend ostream &operator << (ostream &out , complex &temp){
        out <<  temp.real <<" + " << temp.imag  <<"i"<<endl;
        
        return out ;

    }

} ;


int main(){
    complex c1, c2 ; 

    cin >> c1 ;
    cin >> c2 ;

    cout<< "c1 data : " <<endl ;
    cout << c1 ;
    cout<< "\nc2 data : " <<endl  ;
    cout<<c2 ;

    complex c3 = c1 + c2 ;

    cout << "\nc3 data" <<endl ; 
    cout << c3 ;

    complex c4 = c1*c2 ;
    cout<<"\nc4 data" <<endl ;
    cout<<c4 ;

}