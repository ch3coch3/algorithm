#include<iostream>
#include<cstdlib>
using namespace std;

void merge(int A[],int p,int q,int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    // cout << q << " " << n2;
    int L[n1]; int R[n2];
    for(int i = 0;i < n1;i++){
        L[i] = A[p + i - 1];
    }
    for(int j = 0;j < n2;j++){
        R[j] = A[q + j];
    }
    L[n1] = 10000;
    R[n2] = 10000;
    int li = 0;
    int ri = 0;
    for(int k = 0;k < r;k++){
        if (L[li] <= R[ri]){
            A[k] = L[li];
            li++;
        }
        else{
            A[k] = R[ri];
            ri++;
        }
    }
}

void mergeSort(int A[],int p,int r){
    if (p < r){
        int q = (p + r)/2;
        mergeSort(A,p,q);
        mergeSort(A,q+1,r);
        merge(A,p,q,r);
    }
}

void printResult(int A[],int size){

    for(int i = 0 ; i < (size + 1);i++){
        cout << A[i] << " ,";
    }
    cout << endl;
}

int main(){

    int A[] = {5,2,4,7,1,3,2,6};
    int p = 0;
    int r = sizeof(A)/sizeof(A[0]);
    mergeSort(A,p,r);
    printResult(A,r);
}