#include <iostream>
#include <string>
#include <vector>

using namespace std;

int search(string str,vector <string> arr, int n) {
    for(int i=0;i<n;i++) {
        if(str == arr[i]) return 1;
    }
    return 0;
}

int main() {
	int n;
    string temp;
    cin >> n;
    vector<string> wordlist;
    vector<string> word;
    for(int i=1;cin >> temp;i++) {
        if(i > n) {
            i -= n;
            wordlist.clear();
        }
        word.push_back(temp);
        cout << temp << endl;
        if(word.size() == 2  && (word[0].substr(word[0].length()-1) != word[1].substr(0, 1) || search(temp, wordlist, i))) {
            cout << i << " 번은 병신이다" << endl << "찰싹찰싹" << endl;
        break;
        }
        if(word.size() == 2) word.erase(word.begin());
        wordlist.push_back(temp);
    }
	return 0;
}