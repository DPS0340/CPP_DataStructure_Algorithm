#include <iostream>

using namespace std;

int* select(int arr[], int len) {
    int* result = new int[len];
    int min;
    int mindex;
    for(int i=0;i<len;i++) {
        for(int j=0;j<len;j++) {
            if(arr[j] != NULL) {
                min = arr[j];
                mindex = j;
                break;
            }
        }
        for(int j=mindex;j<len;j++) {
            if(arr[j] != NULL && arr[j] < min) {
                min = arr[j];
                mindex = j;
            }
        }
        arr[mindex] = NULL;
        result[i] = min;
    }
    return result;
}

int main() {
	int arr[5] = {3, 1, 4, 5, 2};
    int* result = select(arr, 5);
    for(int i=0;i<5;i++) cout << result[i] << " ";
	return 0;
}
