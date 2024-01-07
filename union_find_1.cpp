#include <bits/stdc++.h>
using namespace std;
class unionFind{
    vector<int> rank; // ignored 
    vector<int> parent;
    vector<int> size;
    public:
    unionFind(int n){
        rank.resize(n+1, 0);
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }
    
    int findParent(int node){
        if(node == parent[node]){
            return node;
        }
        parent[node] = findParent(parent[node]); //path compression 
        return parent[node];
    }

    void unionByRank(int u, int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else{
            parent[ulp_u] = ulp_v;
            ++rank[ulp_v];
        }
    }
    
    void unionBySize(int u, int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if(ulp_u == ulp_v){
            return;
        }
        if(size[ulp_u] > size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }

};
int main(){
    unionFind uf(7);
    
    // uf.unionByRank(1, 2);
    // uf.unionByRank(2, 3);
    // uf.unionByRank(4, 5);
    // uf.unionByRank(6, 7);
    // uf.unionByRank(5, 6);
    
    uf.unionBySize(1, 2);
    uf.unionBySize(2, 3);
    uf.unionBySize(4, 5);
    uf.unionBySize(6, 7);
    uf.unionBySize(5, 6);
    
    //check if 1 and 4 are in the same component or not
    if(uf.findParent(1) == uf.findParent(4)){
        cout << "Yes connected..." << endl << endl ;
    }
    else{
        cout << "No, connected !!!" << endl << endl ;
    }

    uf.unionByRank(3, 7);

    //After adding (3, 7) -->
    if(uf.findParent(1) == uf.findParent(4)){
        cout << "Yes connected..." << endl << endl ;
    }
    else{
        cout << "No, connected !!!" << endl << endl ;
    }

    return 0;
}