#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main(){
    int n, q;
    cin >> n;
    vector <int> graph [10001];
    int path[10001];
    fill_n(path,1000,-1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cin >> q;
    bool queen[1001];
    fill_n (queen,1001,false);
    for (int i = 0; i < q; i++){
        int a;
        cin >> a;
        queen[a] = true;
    }

    stack <int> st;
    queue <int> queue;

    queue.push(1);
    path[1] = 0;
    int min = 1000000000;
    while (!queue.empty()) {
        int p = queue.front();
        queue.pop();
        for (int i = 0; i < graph[p].size(); i++) {
            int v = graph[p][i];
            if (path[v] == -1) {
                path[v] = path[p] + 1;
                queue.push(v);
            }
            /*
            if (queen[v] == true && path[v] < min) {
                min = path[v];
            }*/
        }
    }
    int id ;
    for (int i = 1; i <= n; i++) {
        if(queen[i] == true && path[i] < min) {
            min = path[i];
            id = i;
        }
    }
    cout << id;
    return 0;
}