#include "stdio.h"
#include "stdlib.h"
#define MAX 100

struct node
{
    int info;
    struct node *link;
};

struct node *start[6];

void addrCalSort(int a[], int n);
void insertInList(int num, int addr);
int hashFn(int x, int large);

int main(){
    int a[MAX], n;

    printf("Enter the number of elements in the list: \n");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("Enter element %d : ", i +1);
        scanf("%d", &a[i]);
    }

    printf("The unsorted list is : \n");
    for(int i = 0; i < n; i++){
        printf("%d | ", a[i]);
    }
    printf("\n");

    addrCalSort(a, n);

    printf("The sorted list is : \n");
    for(int i = 0; i < n; i++){
        printf("%d | ", a[i]);
    }
    printf("\n");

    return 0;
}

void addrCalSort(int a[], int n){
    int addr, large = 0;
    struct node *p;

    for(int i = 0; i <= 5; i++){
        start[i] = NULL;
    }

    for(int i = 0; i < n; i++){
        if(a[i] > large){
            large = a[i];
        }
    }

    for(int i = 0; i < n; i++){
        addr = hashFn(a[i], large);
        insertInList(a[i], addr);
    }

    int k = 0;
    for(int j = 0; j<=5; j++){
        p = start[j];
        while( p!= NULL){
            a[k++] = p->info;
            p = p->link;
        }
    }
}

int hashFn(int x, int large){
    int addr;
    float temp;
    temp = (float)x/large;
    addr = temp*5;
    return addr;
}

void insertInList(int num, int addr){
    struct node *q, *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = num;


    if(start[addr] == NULL || num < start[addr]->info){
        temp->link = start[addr];
        start[addr] = temp;
    }
    else{
        q = start[addr];
        while(q->link != NULL && q->link->info < num){
            q = q->link;
        }
        temp->link = q->link;
        q->link = temp;
    }
}