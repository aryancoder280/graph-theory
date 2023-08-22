#include<bits/stdc++.h>
using namespace std;

bool dfs(int node,vector<int>graph[],bool visited[],bool done[]) {

    for(int i=0;i<graph[node].size();i++) {
        int val = graph[node][i];
        if(!visited[val]) {
            visited[val] = true;
            if(dfs(val,graph,visited,done)) return true;
            visited[val] = false;
        }
        else if(visited[val]) return true;
    }
    done[node] = true;
    return false;
}
bool solve(int n, vector<vector<int>>edges) {
    vector<int>graph[n+1];
    for(int i=0;i<edges.size();i++) {
        int u,v;
        u = edges[i][0];
        v = edges[i][1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bool visited[n+1] = {false};
    bool done[n+1] = {false};
    for(int i=1;i<=n;i++) {
        if(!done[i]) {
            visited[i] = true;
             if(dfs(i,graph,visited,done)) return true;
             visited[i] = false;
        }
    }
    return false;
}
