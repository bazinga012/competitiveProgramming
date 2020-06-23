// https://www.hackerrank.com/challenges/swap-nodes-algo/problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct node {
    int left;
    int right;
};


void Inorder(node root[],int i){
    if(i==-1)return;
    Inorder(root,root[i].left);
    printf("%d ",i+1);
    Inorder(root,root[i].right);
}

void Func(node root[],int i,int l,int k){
    if(i==-1 )return;
    if(l%k==0){
        int temp = root[i].left;
        root[i].left = root[i].right;
        root[i].right = temp;
    }
    Func(root,root[i].left,l+1,k);
    Func(root,root[i].right,l+1,k);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int N;
    scanf("%d",&N);
    node Tree[N];
    int l,r;
    for(int i=0;i<N;i++){
        scanf("%d%d",&l,&r);
        Tree[i].left = l!=-1? l-1 :-1;
        Tree[i].right = r!=-1? r-1 :-1;
    }
    int t,k;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        scanf("%d",&k);
        Func(Tree,0,1,k);
        Inorder(Tree,0);
        printf("\n");
    }
    return 0;
}
