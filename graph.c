#include<stdio.h>
#include <stdlib.h>
struct node{
    int vertex;
    int weight;
    struct node* next;
};
void flush() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void generator(int v,struct node ** arra){
    struct node* current;
    for(int i=0;i<v;i++){
        int choice=0;
        printf("current vertex: %d , do u wanna add a link 1 for yes 0 for no :",i);
        scanf("%d",&choice);
        flush();
        if (choice==1){
            arra[i]=(struct node *)malloc(sizeof(struct node));
            current= arra[i];
        }
        while(choice==1){
            int ver,wt;
            printf("connection to which node and weight :");
            scanf("%d %d", &ver,&wt);
            flush();
            while (ver < 0 || ver >= v) {
                printf("Invalid node! Must be between 0 and %d. Try again (node weight): ", v - 1);
                scanf("%d %d", &ver, &wt);
                flush();
            }
            current->vertex=ver;
            current->weight=wt;
            printf("enter choice if u wanna add another :");
            scanf("%d",&choice);
            flush();
            if(choice!=1){
                current->next=NULL;
                break;
            }
            current->next=(struct node *)malloc(sizeof(struct node));
            current=current->next;
        }
    }
}
void printGraph(struct node ** array,int v){
    for(int i=0;i<v;i++){
        printf("[ Node %d ]-> ",i);
        struct node* current=array[i];
        while(current!=NULL){     
            printf("[ Node %d | Weight : %d] -> ",current->vertex,current->weight);
            current=current->next;
        }
        printf("NULL\n");
    }
}
void Eraser(struct node ** array,int v){
    for(int i=0;i<v;i++){
        struct node* current=array[i];
        while(current!=NULL){
            struct node* nex=current->next;
            free(current);
            current= nex;
        }
    }
    free(array);
}


int main(){
    int V;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    flush();
    struct node ** arr=(struct node**)malloc(V*sizeof(struct node *));
    for (int i = 0; i < V; i++) {
        arr[i] = NULL;  
    }
    generator(V,arr);
    printGraph(arr,V);
    Eraser(arr,V);
    return 0;
}