#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int mvx [] = {-1, 1, 0, 0};
int mvy [] = {0, 0, -1, 1};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m ,n;
        cin >> m >> n;
        char maze[20][20];
        bool vis[20][20];
        
        for (int i = 0; i < 20; i++) {
            fill_n(vis[i],20,0);
        }
        vector <int> stx;
        vector <int> sty;
        for (int i = 0; i < m; i++) 
            cin >> maze[i];
           
        
        for (int i = 0; i < m; i++) 
            for(int j = 0; j < n; j++) {
                if (i == 0 || i == m-1 || j == 0 || j == n - 1) 
                    if(maze[i][j] == '.') {
                        stx.push_back(j); sty.push_back(i); }
                    
            }
        if (stx.size() != 2) {
            cout << "invalid" << endl;
            continue;
        }

        queue <int> qx; queue <int> qy;
        qx.push(stx[1]); qy.push(sty[1]);
        stx.pop_back(); sty.pop_back();

        while(!qx.empty() && !qy.empty()) {
            int px = qx.front(), py = qy.front();
            qx.pop(); qy.pop();
            for (int i = 0; i < 3; i++) {
                int nx = px + mvx[i], ny = py + mvy[i];
                if (nx < 0 || ny < 0 || nx == n || ny == m) continue;
                if (maze[nx][ny] == '.' && vis[nx][ny] == false) {
                    vis[nx][ny] = true;
                    qx.push(nx); qy.push(ny);
                }
            }
        }
        if (vis[stx[0]][sty[0]]) 
            cout << "valid" << endl;
        else
            cout << "invalid" << endl;
        
    }
}