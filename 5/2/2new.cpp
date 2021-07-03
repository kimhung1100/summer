    #include <iostream>
    #include <string>
    #include <vector>
    #include <queue>
    #include <cmath>


    using namespace std;
    #define MAX 20
    bool canMove(vector <int> storeG, int pos1, int pos2, int n) {
        if (pos1 / n == pos2 / n) {
            if (abs(pos1 - pos2) == 1)
                return true;
            return false;
        }
        else if (abs(pos1 - pos2) == n)
            return true;
        return false;
    }
    int main() {
        int t;
        cin >> t;
        for (int i = 0; i < t; i++) {
            int m , n;
            cin >> m >> n;
            
            vector <string> s(m);
            vector <int> storeG;
            
            for(int j = 0; j < m; j++) {
                cin >> s[j];
                for(int k = 0; k < n; k++) {
                    if(s[j][k] == '.') storeG.push_back(j*n + k);
                }
            }
            vector <int> graph [MAX * MAX];

            vector <int> start;
            if ( m == 1 || n == 1) {
                if ( m == 1 && n == 1) {
                    cout << "invalid" << endl;
                    continue;
                }
                else if (m == 1) {
                    int temp = 0;
                    bool lt = false;
                    for(int j = 0; j < s[0].size(); j++) {
                        if (s[0][j] == '.') {
                            temp ++;
                            if(s[0][j + 1] == '.') {
                                temp  ++;
                                j ++;
                                lt = true;
                            }
                        }
                    }
                    if (temp == 2 && lt == true)
                            cout << "valid" << endl;
                        else
                            cout << "invalid" << endl;
                }
                else if (n == 1) {
                    int temp = 0;
                    bool lt = false;
                    for(int j = 0; j < m; j++) {
                        if(s[j] == ".") {
                            temp ++;
                            if(s[j+1] == ".") {
                                temp ++;
                                j++;
                                lt = true;
                            }
                        }
                    }
                    if (temp == 2 && lt == true)
                            cout << "valid" << endl;
                        else
                            cout << "invalid" << endl;
                }
                continue;
            }
            for(int j = 0; j < m; ) {
                for(int k = 0; k < n; k++) {
                    if (s[j][k] == '.')
                        start.push_back(j * n + k);
                }
                if ( j == 0) j = m -1;
                else break;
            }
            for(int j = 0; j < n; ) {
                for (int k = 1; k < m - 1; k++) {
                    if (s[k][j] == '.')
                        start.push_back(k * n + j);
                }
                if (j == 0) j = n - 1;
                else break;
            }

            if (start.size() != 2) {
                cout << "invalid" << endl;
                continue;
            }

            
            for (int j = 0; j < storeG.size(); j++) {
                for(int k = 0; k < storeG.size(); k++) {
                    if(canMove(storeG, storeG[j], storeG[k], n)) {
                        graph[storeG[k]].push_back(storeG[j]);
                    }
                }
            }

            
            vector <bool> visited(n * m + 1);

            visited[start.front()] = true;
            queue <int> queue;
            queue.push(start.front());
            start.erase(start.begin());
            while (!queue.empty()) {
                int u = queue.front();
                queue.pop();
                for (int j = 0; j < graph[u].size(); j++){
                    int v = graph[u][j];
                    if (!visited[v]) {
                        queue.push(v);
                        visited[v] = true;
                    }
                }
            }
            if (visited[start[0]]) {
                cout << "valid" << endl;
            }
            else 
                cout << "invalid" << endl;

        }
    }