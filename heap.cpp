#include<iostream>
using namespace std; 

int Floor(double x){
	return (int)(x);
}

int parent(int i){
	return Floor(i/2);
}

int left(int i){
	return 2*i;
}

int right(int i){
	return 2*i+1;
}

// 需要調整index值，使其符合array index的定義 
void maxHeapify(int A[], int i, int n){
	int l = left(i);
	int r = right(i);
	int largest;int c;
	if (l <= n && A[l-1] > A[i-1])
		largest = l;
	else
		largest = i;
	if (r <= n && A[r-1] > A[largest-1])
		largest = r;
	if (largest != i){
		c = A[i-1];
		A[i-1] = A[largest-1];
		A[largest-1] = c;
		maxHeapify(A,largest,n);
	}

}

void buildMaxHeap(int A[],int n){
	for(int i = Floor(n/2); i >= 1; i--)
		maxHeapify(A,i,n);
}

void printArray(int A[],int n){
	for(int i = 0;i<n;i++)
		cout << A[i] << " ";
	cout << endl;
}
int main(){
	int A[] = {4,1,3,2,16,9,10,14,8,7};
	int n = sizeof(A)/sizeof(A[1]);
//	cout << Floor(4.6);
	buildMaxHeap(A,n);
	printArray(A,n);
//	system("pause");
} 
