#include<iostream>
#include<fstream> 
using namespace std ;

void writeTofile(string fileName){

    ofstream fout ;
    fout.open(fileName, ios::app) ;

    if(!fout){
        cerr << "Error opening file (fout)"; 
        return ;
    }

    int i= 0 ;
    while (i <=10)
    {
        fout<<"Value of i is : " << i << "\n" ;

        i++ ;
    }
    fout.close() ;

}
void readFromFile(string fileName ){
    ifstream fin ;
    fin.open(fileName , ios::in) ; 

    if(!fin){
        cerr << "Error opening file (fin)" ;
        return ;
    }

    string var ;
    int i ;
    getline(fin, var) ;
    // getline(fin, i) ; //wont wonk for other than string datatypes
    // fin >> i ; 
    // fin.ignore() ;
    // cout<< var << "\n" << i ;

    while(getline(fin,var )){
        cout << var <<endl ;
    }
    fin.close() ;
}
int main(){

    string file = "temp.txt" ;

    // writeTofile(file) ;

    readFromFile(file) ;
}
