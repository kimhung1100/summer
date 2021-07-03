#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX 1000

void print(vector <int> distance, vector <bool> visited, int s) {
    for(int i = 1; i < distance.size(); i++) {
        if(visited[i] == false) cout << -1 << " ";
        else if (i == s) continue;
        else cout << distance[i] * 6 << " ";
    }
}
void bfs(int s, vector<int> distance, vector <int> graph[], vector <bool> visited){
    distance[s] = 0;
    visited[s] = true;
    queue <int> queue;
    queue.push(s);
    while(!queue.empty()) {
        int u = queue.front();
        queue.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];
            if (!visited[v]){
                distance[v] = distance[u] + 1;
                queue.push(v);
                visited[v] = true;
            }
        }
    }
    print(distance, visited, s);
}
void process(){
    int n, m;
    cin >> n >> m;
    vector <int> graph [MAX + 1];
    int u, v;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int s;
    cin >> s;
    vector <int> distance(n+1);
    //fill_n(distance,n,0);
    vector <bool> visited(n+1);
    //fill_n(visited,n,false);

    bfs(s, distance, graph, visited);
    
    cout << endl;
}

int main(){
    int q;
    cin >> q;
    for( int i = 1; i <= q; i++) 
        process();
}