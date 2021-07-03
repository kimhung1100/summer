#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    char grid[501][501];
    bool vis[501][501];
    
    int mvx[] = {0, -1, 0, 1};
    int mvy[] = {-1, 0 , 1, 0};
    for(int i = 0; i < n; i++) 
        cin >> grid[i];
    int sy, sx, ey, ex;
    cin >> sx >> sy >> ex >> ey;
    sx -- ; sy --; ex --; ey--;
    queue <int> qx; queue <int> qy;
    qx.push(sx); qy.push(sy);
    vis[sx][sy] = true;
    
    while(!qx.empty() && !qy.empty()) {
        int px = qx.front(), py = qy.front();
        qx.pop(); qy.pop();
        if (px == ex && py == ey) {
            cout << "YES";
            return 0;
        }
        for(int i = 0; i < 4; i++){
            int nx = px + mvx[i], ny = py +mvy[i];
            if (nx < 0 || ny < 0 || nx == m || ny == n) continue;
            
            if (grid[nx][ny] == '.' && vis[nx][ny] == false) {
                vis[nx][ny] = 1;
                qx.push(nx); qy.push(ny);
            }
        }
    }
    cout << "NO";
    return 0;
}