#include <stdio.h>
#include <stdlib.h>

typedef struct _node node;
typedef struct _edge edge;

int size = 10;

typedef struct _node {
    char name;
    int length;
    int dij;
    int printed;
    edge** edges;
} node;

typedef struct _edge {
    int length;
    node** nodes;
} edge;

node* find_dest(node* from, edge* line) {
    node* result = NULL;

    for(int i=0;i<2;i++) {
        if(line->nodes[i] != from) {
            result = line->nodes[i];
            break;
        }
    }

    return result;
}

void dijkstra(node* start) {
    start->dij = 1;

    int index = 0;

    while(start->edges[index] != NULL) {
        index++;
    }

    for(int i=0;i<index;i++) {
        node* dest = find_dest(start, start->edges[i]);
        if(start->length + start->edges[i]->length < dest->length) {
            dest->length = start->length + start->edges[i]->length;
        }
        if(dest->dij == 0) {
            dijkstra(dest);
        }
    }
}

node* make_node(node* start, char name, int edge_length) {
    int index = 0;
    while(start->edges[index] != NULL) {
        index++;
    }
    
    start->edges[index] = (edge*)malloc(sizeof(edge));

    start->edges[index]->length = edge_length;

    start->edges[index]->nodes = (node**)calloc(1, sizeof(node*) * 2);

    start->edges[index]->nodes[0] = start;
    
    start->edges[index]->nodes[1] = (node*)malloc(sizeof(node*));

    start->edges[index]->nodes[1]->name = name;
    start->edges[index]->nodes[1]->dij = 0;
    start->edges[index]->nodes[1]->printed = 0;
    start->edges[index]->nodes[1]->length = (~(0) & ~(1 << 31));
    start->edges[index]->nodes[1]->edges = (edge**)calloc(1, sizeof(edge*) * size);

    return start->edges[index]->nodes[1];
}

edge* make_edge(node* start, node* dest, int edge_length) {
    int index = 0;
    while(start->edges[index] != NULL) {
        index++;
    }
    
    start->edges[index] = (edge*)malloc(sizeof(edge));

    start->edges[index]->length = edge_length;

    start->edges[index]->nodes = (node**)calloc(1, sizeof(node*) * 2);

    start->edges[index]->nodes[0] = start;
    
    start->edges[index]->nodes[1] = dest;

    return start->edges[index];
}

void print_graph(node* start) {
    start->printed = 1;

    printf("%c: %d\n", start->name, start->length);

    int index = 0;

    while(start->edges[index] != NULL) {
        index++;
    }

    for(int i=0;i<index;i++) {
        node* dest = find_dest(start, start->edges[i]);
        if(dest->printed == 0) {
            print_graph(dest);
        }
    }
}

int main(void) {
    node* start = (node*)malloc(sizeof(node));
    
    start->name = 'A';
    start->dij = 0;
    start->printed = 0;
    start->edges = (edge**)calloc(1, sizeof(edge*) * size);

    start->length = 0;

    node* b = make_node(start, 'B', 6);
    node* c = make_node(start, 'C', 10);
    make_edge(b, c, 1);

    dijkstra(start);

    print_graph(start);

    return 0;
}
