#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int a[1001];
int n;
#define MAX 100001
int bfs(int s ,int e) {
    int dist[MAX];
    for (int i = 0; i < MAX; i++)
        dist[i] = -1;
    queue <long long> q;
    q.push(s);
    dist[s] = 0;
    int cnt = 0;
    while(!q.empty()) {
        long long s = q.front();
        q.pop();
        if (s == e)
            break;
        for(int i = 0; i < n; i++) {
            long long temp = s * a[i];
            temp %= 100000;
            if (dist[temp] == -1) {
                dist[temp] = dist[s] + 1;
                q.push(temp);
                cnt ++;
            }   
        }
    }
    return dist[e];
}
int main(){
    int s, e;
    cin >> s >> e >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int res = bfs(s,e);
    cout << res;
}