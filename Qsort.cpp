#include <iostream>
#include <vector>

using namespace std;

vector<int> myqsort(vector<int> vec) {
	vector<int> myvec = vec;
	if (myvec.size() <= 1) return myvec;
	int pivot = myvec[0];
	vector<int> smaller;
	vector<int> larger;
	for (int i = 1; i < myvec.size(); i++) {
		if (myvec[i] <= pivot) smaller.push_back(myvec[i]);
		else larger.push_back(myvec[i]);
	}
	vector<int> result;
	result.push_back(pivot);
	smaller = myqsort(smaller);
	larger = myqsort(larger);
	result.insert(result.begin(), smaller.begin(), smaller.end());
	result.insert(result.end(), larger.begin(), larger.end());
	return result;
}

void main() {
	vector<int> vec;
	for (int i = 1; i <= 9; i++) vec.push_back(10 - i);
	vector<int> result = myqsort(vec);
	for (int i = 0; i < 9; i++) printf("%d ", result[i]); // 1 2 3 4 5 6 7 8 9
	return;
}
