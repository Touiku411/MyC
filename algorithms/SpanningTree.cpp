#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
vector<vector<int>> vec;
vector<int> parent;
vector<bool> visited;
vector<set<pair<int,int>>> cycles;
set<pair<int, int>> seen_back_edges;
void dfs(int u, int p){ // u = current node, p = u's parent node
    visited[u] = true;
    parent[u] = p;
    for(int v : vec[u]){// 變歷u走過的點
        if(v == p)continue;
        if(visited[v])
        {
            pair<int, int> edge = make_pair(min(v, u), max(v, u));// 3(u)碰到1(v)
            if(seen_back_edges.count(edge))continue;
            seen_back_edges.insert(edge);

            set<pair<int, int>> current_cycle;
            current_cycle.insert(edge);
            int cur = u;
            while(cur != v){
                int next = parent[cur];
                pair<int, int> edge = make_pair(min(next, cur), max(next, cur));
                current_cycle.insert(edge);
                cur = next;
            }
            cycles.push_back(current_cycle);
        }
        else{
            dfs(v, u);
        }
    }
}
bool commonSide(){
    if (cycles.size() < 2) return false;
    for(int i = 0; i < cycles.size() - 1 ; ++i){
        for(int j = i + 1; j < cycles.size(); ++j){
            for(auto edge : cycles[i]){
                if(cycles[j].count(edge)){
                    return true;
                }
            }
        }
    }
    return false;
}
int main(){
    int n;
    cin >> n;
    vec.assign(n + 1, vector<int>(0));
    visited.assign(n + 1, false);
    parent.assign(n + 1, -1);
    int u, v;
    while(cin >> u && u != -1){
        cin >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    dfs(1, -1);
    bool allvisited = true;
    for(int i = 1; i <= n; ++i){
        if(visited[i] == false){
            allvisited = false;
            break;
        }
    }
    if(allvisited && cycles.size() >= 2){
        cout << "y\n";
        if(commonSide()){
            cout << "There are at least three cycles.\n";
        }
    }
    else{
        cout << "n\n";
    }

    
    
}
