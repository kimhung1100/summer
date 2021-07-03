#include <iostream>
#include <string>
#include <vector>
#include <queue>

class point {
public:
    int x;
    int y;
    point(int _x, int _y) {
        x = _x; y = _y;
    }
    point () {

    }
    bool operator == (point& point) {
        if (x == point.x && y == point.y)
            return true;
        return false;
    }
};

using namespace std;
#define MAX 20
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int m , n;
        cin >> m >> n;
        vector <string> s(m);
        for(int j = 0; j < m; j++)
            cin >> s[j];
        vector <char> c[MAX];

        vector <point> visited[20];
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                string temp = s[j];
                c[j].push_back(temp[k]);
                if (temp[k] == '.') {
                    visited.push_back(point(j,k));
                }
            }
        }
        int cnt = 0;
        vector <point> ste;
        for(int j = 0; i < m; ) {
            for (int k = 0; k < n; k++) {
                if(c[j][k] == '.') {
                    ste.push_back(point(j,k));
                }
            }
            if ( j == 0)
                j = m -1;
            else 
                break;
        }
        for (int j = 0; j < n; ) {
            for(int k = 0; k < m; k++) {
                if (c[j][k] == '.') {
                    ste.push_back(point(k,j));
                }
            }
            if ( j == 0)
                j = n -1;
            else 
                break;
        }

        if (ste.size() != 2) {
            cout << "invalid" << endl;
            continue;
        }

        
        

        queue <point> queue;
        queue.push(ste.front());

        while(!queue.empty()) {
            point p = queue.front();
            queue.pop();
            for(int j = 0; j < )
        }

        

        

    }
}