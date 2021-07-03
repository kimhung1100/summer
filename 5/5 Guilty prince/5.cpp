#include <iostream>
#include <queue>


using namespace std;
int mvx[] = {0, -1, 0, 1};
int mvy[] = {-1, 0 , 1, 0};
int bfs() {
    int w, h;
    cin >> w >> h;
    char grid [20][20];
    bool visited [20][20];
    for (int i = 0; i < 20; i++)
        for(int j = 0; j < 20; j++)
            visited[i][j] = false;
    int sx, sy;
    bool start = false;
    for (int i = 0; i < h; i++) {
        cin >> grid[i];
        if (start == false)
        for(int j = 0; j < w; j++) {
            if (grid[i][j] == '@') {
                sx = i; sy = j;
                start = true;
            }
        }
    }
    int cnt = 1;
    queue <int> qx;
    queue <int> qy;
    qx.push(sx);
    qy.push(sy);
    visited[sx][sy] = true;

    while (!qx.empty() && !qy.empty()) {
        int px = qx.front(), py = qy.front();
        qx.pop(); qy.pop();
        for(int i = 0; i < 4; i++) {
            int nx = px + mvx[i], ny = py + mvy[i];
            if (nx <0 || ny < 0 || nx == h || ny == w) continue;
            if (grid[nx][ny] == '.' && visited[nx][ny] == 0) {
                visited [nx][ny] = 1;
                qx.push(nx); qy.push(ny);
                cnt ++;
            }
        }
    }
    for (int i = 0; i < 20; i++)
        for(int j = 0; j < 20; j++)
            visited[i][j] = false;
    return cnt;
}
int main(){
    int n;
    cin >> n;
    int cnt = 1;
    while (n --) {
        int ret = bfs();
        cout << "Case " << cnt << ": " << ret << endl;
        cnt ++;
    }
}