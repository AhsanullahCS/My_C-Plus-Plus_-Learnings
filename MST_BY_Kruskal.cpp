#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> parent, rankArr;

int findParent(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = findParent(parent[x]); 
}

void unionSet(int a, int b)
{
    a = findParent(a);
    b = findParent(b);

    if (a != b)
    {
        if (rankArr[a] < rankArr[b])
            parent[a] = b;
        else if (rankArr[a] > rankArr[b])
            parent[b] = a;
        else
        {
            parent[b] = a; 
            rankArr[a]++;
        }
    }
}
int main()
{
    int n, e;
    cout << "ENTER THE NUMBER OF NODES AND EDGES\n";
    cin >> n >> e;

    vector<pair<int, pair<int,int>>> edges;

    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        if (u == v) continue;       
        edges.push_back({w, {u, v}});
    }

    sort(edges.begin(), edges.end());
    parent.resize(n + 1);
    rankArr.resize(n + 1, 0);
    for (int i = 1; i <= n; i++) 
        parent[i] = i;

    int mstCost = 0;
    vector<pair<int,int>> mstEdges;

    for (auto edge : edges)
    {
        int w = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;

        if (findParent(u) != findParent(v))   
        {
            unionSet(u, v); 
            mstCost += w;
            mstEdges.push_back({u, v});
        }
    }
    cout << "\nEdges in MST "<<endl;
    for (auto e : mstEdges)
        cout << e.first << " - " << e.second <<endl;

    cout << "Total MST Cost = " << mstCost << endl;

    return 0;
}
