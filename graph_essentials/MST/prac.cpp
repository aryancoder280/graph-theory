#include<bits/stdc++.h>
using namespace std;

int find_set(int val,vector<int>&parent) {
    if(parent[val] == -1) return val;
    else {
        return parent[val] = find_set(parent[val],parent);
    }
}

bool union_set(int u,int v,vector<int>&parent,vector<int>&ranking) {
    int s1 = find_set(u,parent);
    int s2 = find_set(v,parent);
    if(s1!=s2) {
        if(ranking[s1]<ranking[s2]) swap(s1,s2);
        parent[s2] = s1;
        ranking[s1]+=ranking[s2];
        return true;
    }
    return false;
}
int maxNumEdgesToRemove(int n, vector<vector<int>> edges) {

    vector<pair<int,pair<int,int>>>vp;
    for(int i=0;i<edges.size();i++) {
        int type = edges[i][0];
        int a = edges[i][1];
        int b = edges[i][2];
        vp.push_back({type,{a,b}});
    }
    vector<int>parent(n+1,-1);
    vector<int>ranking(n+1,1);
    int cnt = 0;
    for(int i=0;i<vp.size();i++) {
        int type = vp[i].first;
        int u = vp[i].second.first;
        int v = vp[i].second.second;
        if(type == 3) {
            if(!union_set(u,v,parent,ranking)) {cnt++;
                cout<<type<<" "<<u<<" "<<v<<endl;
            }
        }
    }
    vector<int>parent1(n+1,-1);
    vector<int>ranking1(n+1,1);
    for(int i=0;i<vp.size();i++) {
        int type = vp[i].first;
        int u = vp[i].second.first;
        int v = vp[i].second.second;
        if(type == 1) {
            if( (find_set(u,parent) == find_set(v,parent) ) || !union_set(u,v,parent1,ranking1)) {
                    cout<<type<<" "<<u<<" "<<v<<endl;
                cnt++;
            }
        }
    }
    vector<int>parent2(n+1,-1);
    vector<int>ranking2(n+1,1);
    for(int i=0;i<vp.size();i++) {
        int type = vp[i].first;
        int u = vp[i].second.first;
        int v = vp[i].second.second;
        if(type == 2) {
            if( (find_set(u,parent) == find_set(v,parent) ) || !union_set(u,v,parent2,ranking2)) {
                    cout<<type<<" "<<u<<" "<<v<<endl;
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    int n,e;
    cin>>n>>e;
    vector<vector<int>>edges;
    for(int i=0;i<e;i++) {
        int type,u,v;
        cin>>type>>u>>v;
        vector<int>temp;
        temp.push_back(type);
        temp.push_back(u);
        temp.push_back(v);
        edges.push_back(temp);
        temp.clear();
    }
    cout<<maxNumEdgesToRemove(n,edges);
}
