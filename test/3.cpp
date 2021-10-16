#include<iostream>
using namespace std;

void swap(int &a, int &b){
	int temp = a;
	a = b; 
	b = temp;
}

void outputArr(int arr[], int n){
	for ( int i = 0 ; i < n; i++){
		cout << arr[i] << " " ;
	}
}

int main(){
	int arr[12] = {2,3,56,5,4,8,9,6,3,2,4,4};
	for (int i = 0; i < 12-1; i++){
		for(int j = i+1; j < 12; j++){
			if(arr[i] > arr[j]){
				swap(arr[i], arr[j]);
			}
		}
	}
	outputArr(arr, 12);
	return 0;
}