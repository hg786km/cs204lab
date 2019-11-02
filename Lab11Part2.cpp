#include <bits/stdc++.h>
#define lli long long int
#define pb push_back
#define v32 vector<int>
#define v64 vector<lli>
#define v1024 vector <vector <int>>
#define vt vector
#define f(x, y, z) for (lli x = y; x < z; x++)
#define endl "\n"

using namespace std;
class UnionFind //rank is equal to number of vertices in a connected component
{
  public: v32 p, rank;
  UnionFind(int N) { rank.assign(N, 1);
  p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) 
  {
  if (!isSameSet(i, j)) {
  // if from different set
  int x = findSet(i), y = findSet(j);
  if (rank[x] > rank[y]) p[y] = x,rank[x]+=rank[y];
  // rank keeps the tree short
  else 
     {
     p[x] = y;
     rank[y]+=rank[x]; 
     }
  
  } 
 
  }   
};
v1024 graph;
v32 color;
bool dfs(int u){
  bool temp=true;
  for(auto x:graph[u]){
    if(color[x]==0){
        color[x]=3-color[u];
        temp=temp&dfs(x);
    }
    else if(color[x]+color[u]!=3)return false;
  }
  return temp;
}
int main() 
{ 
  int n,m;
  cin>>n>>m;
  graph.resize(n+1);
  color.resize(n+1);
  f(i,0,n+1)
  color[i]=0;
  UnionFind UNION(n+1);
  v32 X(m),Y(m),W(m);
  f(i,0,m){
    int x,y,w;cin>>x>>y>>w;
    w=w%2;
    X[i]=x,Y[i]=y,W[i]=w;
    if(w==0){
      UNION.unionSet(x,y);
    }
  }
  f(i,0,m){
    if(W[i]){
      if(UNION.isSameSet(X[i],Y[i])){
        cout<<"YES\n";
        return 0;
      }
      else 
          {
            graph[UNION.findSet(X[i])].pb(UNION.findSet(Y[i]));
            graph[UNION.findSet(Y[i])].pb(UNION.findSet(X[i]));
          }
    }
  }
  f(i,1,n+1){
    if(color[i]==0){
      color[i]=1;
      if(!dfs(i)){
        cout<<"YES\n";
        return 0;
      }
    }
  }
  cout<<"NO\n";
  return 0; 	
}


