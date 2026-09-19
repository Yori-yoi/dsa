#include<stdio.h>
#include <stdlib.h>
struct node{
    int vertex;
    int weight;
    struct node* next;
};

void generator(int v,struct node ** arra){
    struct node* current;
    for(int i=0;i<v;i++){
        int choice=0;
        printf("current vertex: %d , do u wanna add a link 1 for yes 0 for no",i);
        scanf("%d",&choice);
        if (choice==1){
            arra[i]=(struct node *)malloc(sizeof(struct node));
            current= arra[i];
        }
        while(choice==1){
            int ver,wt;
            printf("connection to which node and weight: ");
            scanf("%d %d", &ver,&wt);
            current->vertex=ver;
            current->weight=wt;
            printf("enter choice if u wanna add another");
            scanf("%d",&choice);
            if(choice==0){
                current->next=NULL;
                break;
            }
            current->next=(struct node *)malloc(sizeof(struct node));
            current=current->next;
            
        }
        
    }

}
int main(){
    int V;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    struct node ** arr=(struct node**)malloc(V*sizeof(struct node *));
    for (int i = 0; i < V; i++) {
        arr[i] = NULL;  
    }
    generator(V,arr);
    return 0;
}