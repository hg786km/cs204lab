#include<bits/stdc++.h>
 
#define lli long long int
#define vi vector<int>
#define vs vector<string>
#define vlli vector<lli>
#define pii pair< int , int >
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define f(a,b,c) for(int a=b;a<c;a++)
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
 
int main()
{
    fastio;
    lli n;
    string s,temp;
    set<string> SS;
    vs S;
    cin>>n;
    f(i,0,n)
    {
        cin>>s;
        temp=s;
        S.push_back(s);
        reverse(all(s));
        if(s!=temp)
        {
            SS.insert(s);
        }
    }
    bool flag=false;
    tr(S,it)
    {
        if(present(SS,*it))
        {
            flag=true;
            break;
        }
    }
    if(flag)
    {
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
}
