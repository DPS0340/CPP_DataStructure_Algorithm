#include <iostream>
#include <vector>

using namespace std;

struct binary_tree {
   int n;
   binary_tree* left;
   binary_tree* right;
};


int main() {
    // 귀찮아서 배열에 박음
    binary_tree tree[6];
    for(int i=0;i<6;i++) {
        tree[i].n = i;
        tree[i].left = NULL;
        tree[i].right = NULL;
    }
    tree[0].left =  &tree[1];
    tree[0].right = &tree[2];
    tree[2].left = &tree[3];
    tree[2].right = &tree[4];
    tree[3].left = &tree[5];
    binary_tree testtree[6];
    for(int i=0;i<6;i++) testtree[i] = tree[i];
    vector<binary_tree> vertical = {testtree[0]};
    while(1) {
        if(vertical.size() == 0) break;
        binary_tree current = vertical[vertical.size()-1];
        vertical.pop_back();
        cout << current.n << endl;
        if(current.left == NULL && current.right == NULL && vertical.size() > 0) {
            if(vertical[vertical.size()-1].left != NULL)vertical[vertical.size()-1].left = NULL;
            else if(vertical[vertical.size()-1].right != NULL)vertical[vertical.size()-1].right = NULL;
            else break;
        }
        else if(current.left != NULL) {
vertical.push_back(current);
vertical.push_back(*current.left);
}
        else if(current.right != NULL) {
vertical.push_back(current);
vertical.push_back(*current.right);
}
    }
    return 0;
}