#include <iostream>
#include <vector>

using namespace std;


// arr은 오름차순 정렬되어있고, 같은 값을 가진 원소가 없다고  가정
// n이 존재하지 않는 경우는 없다고 가정
int bs(vector<int> arr, int n) {
    // 시간 복잡도 테스트용 카운터
    int count = 0;
    const int length = arr.size();
    int delta = length / 4;
    int index = length / 2;
    while(arr[index] != n) {
        count++;
        if(arr[index] < n) {
            index += delta;
            if(delta < 1) {
                index++;
            }
        } else {
            index -= delta;
            if(delta < 1) {
                index--;
            }
        }
        delta /= 2;
    }
    cout << "size: " << length << endl;
    cout << "count: " << count << endl;
    return index;
}

int main() {
	vector<int> arr;
    // 테스트 배열 초기화
    for(int i=0;i<1000000;i++) {
        arr.push_back(i + 1);
    }
    cout << "location is: " << bs(arr, 3) << endl;
	return 0;
}