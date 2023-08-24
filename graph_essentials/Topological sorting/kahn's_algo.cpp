#include<bits/stdc++.h>
using namespace std;

void kahnAlgo(vector<int>graph[],int indegree[],queue<int>q,int n) {
    while(!q.empty()) {
        int node = q.front();
        cout<<node<<",";
        q.pop();
        for(int i=0;i<graph[node].size();i++) {
            int nbr = graph[node][i];
            indegree[nbr]--;
            if(indegree[nbr] == 0) q.push(nbr);
        }
    }
    return;
}
int main() {
    int n,m;
    cin>>n>>m;
    vector<int>graph[n];
    int indegree[n] = {0};
    for(int i=0;i<m;i++) {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        indegree[y]++;
    }
    queue<int>q;
    for(int i=0;i<n;i++) {
        if(indegree[i] == 0) q.push(i);
    }
    kahnAlgo(graph,indegree,q,n);
}
