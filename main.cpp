#include <bits/stdc++.h>
//salma mohamed ali  
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int src=1, dest=n;
        vector<int>adj[n+1];
        vector<int>visited(n+1);
        vector<int>levels(n+1);
        vector<int>parents(n+1);
        for(int i=1;i<=m;i++)
        {
            int x,y;
            cin>>x>>y;

            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        visited[1]=1;
        levels[1]=0;
        parents[1]=-1;
        queue<int>q;
        q.push(1);
        while(!q.empty())
        {
            int parent=q.front();
            q.pop();
            for(auto child :adj[parent])
            {
                while(!visited[child])
                {
                    q.push(child);
                    visited[child]=1;
                    levels[child]=levels[parent]+1;
                    parents[child]=parent;
                }
            }
        }
        cout<<levels[n]<<"\n";
    }

    return 0;
}
