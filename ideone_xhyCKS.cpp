#include <iostream>
#include <string>
 
using namespace std;
 
int main() {
    string line;
    getline(cin, line);
    for(int i=0;i<line.length();i++) {
        if('A' <= line[i] && line[i] <= 'Z') {
           line[i] %= 65;
           line[i] += 13;
           line[i] %= 26;
           line[i] += 'A';
        } else if('a' <= line[i] && line[i] <= 'z') {
           line[i] %= 97;
           line[i] += 13;
           line[i] %= 26;
           line[i] += 'a';
        }
    }
    cout << line;
    return 0;
}