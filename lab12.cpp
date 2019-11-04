#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
const int MAX = 1e4 + 5;
const int NUM = 1e9 + 7;
int id[MAX], nodes, edges;
pair <long long, pair<int, int> > p[MAX];

void initialize()
{
    for(int i = 0;i < MAX;++i)
        id[i] = i;
}

int root(int x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(int x, int y)
{
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}

long long kruskal(pair<long long, pair<int, int> > p[])
{
    int x, y;
    long long cost, maximumCost = 1;
    for(int i = 0;i < edges;++i)
    {
        x = p[i].second.first;
        y = p[i].second.second;
        cost = -1*p[i].first;
        if(root(x) != root(y))
        {
            maximumCost *= cost%NUM;
            union1(x, y);
        }    
    }
    return maximumCost;
}

int main()
{
    int x, y;
    long long weight, cost, maximumCost;
    initialize();
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        p[i] = make_pair(-1*weight, make_pair(x, y));
    }
    sort(p, p + edges);
    maximumCost = kruskal(p);
    cout << maximumCost << endl;
    return 0;
}