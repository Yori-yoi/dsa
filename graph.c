#include<stdio.h>
struct node{
    int vertex;
    int weight;
    struct node* next;
};


int main() {
    int V;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    struct node** arr = (struct node**)malloc(V * sizeof(struct node*));
    for (int i = 0; i < V; i++) {
        arr[i] = NULL;
    }
    return 0;
}