#include<bits/stdc++.h>
using namespace std;

int findSet(int val,vector<int>parent) {
    if(parent[val] == -1) return val;
    else {
        return findSet(parent[val],parent);
    }
}
void unionSet(int a,int b,vector<int>&parent) {
    int set1 = findSet(a,parent);
    int set2 = findSet(b,parent);
    if(set1!=set2) {
            parent[set2] = set1;
    }
    return;
}
int main() {
    int n,m;
    cin>>n>>m;
    vector<int>parent(n,-1);
    while(m--) {
        int op;
        cin>>op;
        if(op == 1) {
            int x;
            cin>>x;
            cout<<x<<" belongs to"<<findSet(x,parent);
        }
        else {
            int x,y;
        cin>>x>>y;
            unionSet(x,y,parent);
        }
    }
}

