#include <iostream>
using namespace std;
 
struct linked {
    int n;
    linked* prev;
    linked* next;
};
 
void deleteE(linked* elem) {
    elem->prev->next = elem->next;
    elem->next->prev = elem->prev;
    free(elem);
    return;
}

linked* lstinit(int n) {
    linked* elem = (linked*)malloc(sizeof(linked));
    elem->n = n;
    elem->prev = elem;
    elem->next = elem;
    return elem;
}

linked* push(linked* elem, int n) {
    linked* newe = (linked*)malloc(sizeof(linked));
    newe->n = n;
    newe->prev = elem;
    newe->next = elem->next;
    newe->next->prev = newe;
    newe->prev->next = newe;
    return newe;
}

void removelst(linked* elem) {
    elem->prev->next = NULL;
    while(elem->next != NULL) {
        elem = elem->next;
        free(elem->prev);
    }
    free(elem);
}

int main() {
    int k = 10;
    linked* first = lstinit(0);
    linked* last = first;
    for(int i=1;i<k;i++) {
    	last = push(last, i);
	}
    // 연결 끊기
    deleteE(first->next);
    cout << first->next->n << endl;
    // 리스트 삭제
    removelst(first);
    cout << first->next->n;
	return 0;
}
