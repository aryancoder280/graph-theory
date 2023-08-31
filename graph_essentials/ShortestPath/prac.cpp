#include<bits/stdc++.h>
using namespace std;
void bellManFord(vector<vector<int> >edges,int ver) {
    vector<int>dist(ver,INT_MAX);
    dist[1] = 0;
    for(int j=1;j<ver-1;j++) {
        for(int i=0;i<edges.size();i++) {
                int u = edges[i][0];
                int v = edges[i][1];
                int w = edges[i][2];
                if(dist[u]!=INT_MAX && dist[u]+w<dist[v]) {
                    dist[v] = dist[u]+w;
            }
        }
    }
    //check for -ve cycle
    for(int i=0;i<edges.size();i++) {
         int u = edges[i][0];
                int v = edges[i][1];
                int w = edges[i][2];
                if(dist[u]!=INT_MAX && dist[u]+w<dist[v]) {
                    {
                        cout<<"Negative cycle\n";
                        return ;
                    }
                }
    }
    for(int i=1;i<ver;i++) {
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}
int main() {
    //we will be creating edgeListin
    int v,e;
    cin>>v>>e;
    vector<vector<int> > edges;
    for(int i=0;i<e;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
    bellManFord(edges,v+1);
}
