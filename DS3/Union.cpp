#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef long li;
#define forz(n) for (long i = 0; i < n; i++)
#define rforz(a,n) for (long i = a; i < n; i++)
#define forlz(n) for (long int i = 0; i < n; i++)
#define inf 99999
void swap(int &a,int &b){
    int t = a;
    a = b;
    b = t;
}
void make_set(int t,vector<int> &parent,vector<int> &rank){
    parent[t] = t;
    rank[t] = 0;
}

int findroot(int v,vector<int> &parent){
    if(v == parent[v]){
        return v;
    }
    return parent[v] = findroot(parent[v],parent);
}
void union_set(int x,int y,vector<int> &parent,vector<int> &rank){
    int x = findroot(x,parent);
    int y = findroot(y,parent);
    if(x != y){
        if(rank[x]<rank[y]){
            swap(x,y);
        }
        parent[y] = x;
        if(rank[x] == rank[y]){
            rank[x]++;
        }
    }
}



int main(){
    
    return 0;
}
