#include<iostream>
using namespace std ;


template <typename T>
void selectionSort(T arr[] , int size) {
    T min ;
    //sorting
    for (int i=0 ; i<size -1; i++){
        min = i ;
        for (int j = i+1 ; j < size ; j++){
            if(arr[j] <  arr[min]){
                min = j ;
            }
        }

        swap(arr[i], arr[min]) ;

    }

}

template <typename T>
void display(T arr, int size){
    cout<<"Elements of array are : " ;

    for( int i=0; i<size ; i++){
        cout<< arr[i] << " " ;
    }
}



int main(){
    int arr[5] = {5,4,3,2,1} ;

    selectionSort(arr, 5); 

    display(arr, 5) ;
}