#include<iostream>
#include<cstdlib>
using namespace std;

int partition(int array[], int p, int r){
    int k = 0;                          // to store the exchange number
    int x = array[r];                   // assign last number as pivot to x
    int i = p - 1;                      
    for(int j = p; j < r;j++){
        // put into the first subarray
        if (array[j] < x){
            i++;
            k = array[i];
            array[i] = array[j];
            array[j] = k;
        }
    }
    // pivot back to middle
    k = array[i+1];
    array[i+1] = array[r];
    array[r] = k;
    return i+1;
}
void quicksort(int array[],int p,int r){   // input array, pivot
    if (p < r){
        int q = partition(array,p,r);
        quicksort(array,p,q-1);
        quicksort(array,q+1,r);
    }
}

void printarray(int array[],int size){
    for(int i = 0;i<size;i++){
        cout << array[i] << " ,";
    }
    cout << endl;
}
int main(){
    int array[] = {8,1,6,4,0,3,9,5};
    
    int p = 0;                       // partition number
    int r = sizeof(array)/sizeof(array[0]);           // choose last element as pivot
    quicksort(array,p,r-1);
    printarray(array,r);
    
}