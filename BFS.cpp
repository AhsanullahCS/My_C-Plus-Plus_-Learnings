#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int n,e;
    cout<<"ENTER THE NUMBER OF NODES AND THEN EDGES"<<endl;
    cin>>n>>e;
    vector<vector<int>>AdjList(n+1);

    for(int i=0; i<e; i++)
    {
        int e1,e2;
        cout<<"ENTER THE EDGES"<<endl;
        cin>>e1>>e2;
        AdjList[e1].push_back(e2);
        AdjList[e2].push_back(e1);
    }
    cout<<"::>---------------<::BFS::>----------------<::"<<endl;
    queue<int>st;
    vector<int>visited(n+1,false);

    st.push(1);
    visited[1] = true;

    while (!st.empty())
    {
        int node =st.front();
        st.pop();
        cout<<node<<" ";
        for(int next : AdjList[node])
        {
            if(!visited[next])
            {
            st.push(next);
            visited[next] = true;
            }
        }       
    }
return 0;
}