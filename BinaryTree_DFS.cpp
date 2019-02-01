#include <iostream>
#include <vector>
 
using namespace std;
 
struct binary_tree {
   int n;
   binary_tree* left;
   binary_tree* right;
};
 
binary_tree* init(int n) {
	binary_tree* tree = (binary_tree*)malloc(sizeof(binary_tree));
	tree->n = n;
	return tree;
}
 
binary_tree* left(binary_tree* parent, binary_tree* child) {
	parent->left = child;
	return child;
}
 
binary_tree* right(binary_tree* parent, binary_tree* child) {
	parent->right = child;
	return child;
}
 
void find(binary_tree* tree) {
	vector<binary_tree*> vertical = {tree};
    while(vertical.size() != 0) {
        binary_tree* current = vertical[vertical.size()-1];
        vertical.pop_back();
        cout << current->n << endl;
        if(current->left == NULL && current->right == NULL && vertical.size() > 0) {
            if(vertical[vertical.size()-1]->left != NULL) vertical[vertical.size()-1]->left = NULL;
            else if(vertical[vertical.size()-1]->right != NULL) vertical[vertical.size()-1]->right = NULL;
            else break;
        }
        else if(current->left != NULL) {
			vertical.push_back(current);
			vertical.push_back(current->left);
		}
        else if(current->right != NULL) {
			vertical.push_back(current);
			vertical.push_back(current->right);
		}
    }
    return;
}
 
int main() {
    binary_tree* first = init(0);
    binary_tree* current = first;
    for(int i=1;i<11;i++) current = left(current, init(i));
    current = first;
    for(int i=11;i<21;i++) current = right(current, init(i));
    find(first);
    return 0;
}
