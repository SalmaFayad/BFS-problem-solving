#include <bits/stdc++.h>

using namespace std;
vector<int>visited(100001);
vector<int>levels(100001);
vector<int>dest(100001);
vector<int>adj[100001];
   void bfs(int src){
        visited[src]=1;
        levels[src]=0;
        dest[src]=0;
        queue<int>q;
        q.push(src);
        while(!q.empty())
        {
            int parent=q.front();
            q.pop();
            for(auto child :adj[parent])
            {
                while(!visited[child])
                {
                    dest[child]=dest[parent]+1;
                    q.push(child);
                    visited[child]=1;
                    levels[dest[child]]++;
                }
            }
        }
    }
int main()
{
    int n,e;
    cin>>n>>e;
    for(int i=1; i<=e; i++)
    {
        int x,y;
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int m,src,t,c=0;
    cin>>m;
    while(m--)
    {
        cin>>src>>t;
        for(int i=0; i<=n; i++){
            levels[i]=0,visited[i]=0;}
            bfs(src);
            cout<<levels[t]<<"\n";
        }

    return 0;
}


