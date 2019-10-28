
#include <bits/stdc++.h> 
using namespace std; 
vector <vector <int> > adj;
vector<int> color; 

bool dfs(int u)
{
    bool temp=true;
    for(auto x:adj[u]){
        if(color[x]==-1)
        {
            color[x]=1-color[u];
            temp=(temp&dfs(x));
        }
        else if(color[x]+color[u]!=1) return false;
    }
    return temp;
}
  

  
// Driver Code 
int main() 
{ 
    // no of nodes 
    int n,m,x,y;
    cin>>n;
    adj.resize(n); 
    color.resize(n);
    for(int i = 0;i<n;i++)
    {   
        color[i]=-1;
    }
    cin>>m;
    for(int i = 0;i<m;i++)
    {   
        cin>>x>>y;  
        adj[x-1].push_back(y-1); 
        adj[y-1].push_back(x-1); 
    }
    bool ans=true;
  
    for(int i = 0; i<n;i++)
    {
        if(color[i]==-1)
        {
            color[i]=0;
            ans=dfs(i);
        }
        if(ans==0)break;
    }
    if(ans==0)
    {
        cout<<"NO";
    }
    else{
        cout<<"YES";
    }
    cout<<endl;
    return 0; 
}
