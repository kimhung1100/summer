    #include <iostream>
    #include <queue>
    #include <algorithm>

    using namespace std;

    int main(){
        int c;
        cin >> c;
        for (int l = 0 ;l  < c ; l ++) {
            int n, t, m;
            cin >> n >> t >> m;
            queue <int> lqu;
            queue <int> rqu;
            for(int i = 0; i < m; i++) {
                int a; string s;
                cin >> a >> s;
                if(s == "left")
                    lqu.push(a);
                else if (s == "right")
                    rqu.push(a);
            }
            int ttime = 0;
            int ferry = 0; // 0 left 1 right
            for ( ; ; ) {
                if(ttime >= lqu.front() && ferry == 0 && !lqu.empty()) {
                    while (ttime >= lqu.front() && ferry == 0 && !lqu.empty()) {
                        lqu.pop();
                        cout << ttime + t << endl;
                    }
                    ferry = 1;
                    ttime += t;
                    continue;
                }
                else if (ttime >= rqu.front() && ferry == 1 && !rqu.empty()) {
                    while (ttime >= rqu.front() && ferry == 1 && !rqu.empty()) {
                        rqu.pop();
                        cout << ttime + t << endl;
                    }
                    ferry = 0;
                    ttime += t;
                    continue;
                }
                else if (ttime >= rqu.front() && ferry == 0 && !rqu.empty()) {
                    ttime += t;
                    ferry = 1;
                    while (ttime >= rqu.front() && ferry == 1 && !rqu.empty()) {
                        rqu.pop();
                        cout << ttime + t << endl;
                    }
                    ferry = 0;
                    ttime += t;
                    continue;
                }
                else if (ttime >= lqu.front() && ferry == 1 && !rqu.empty()) {
                    ferry = 0;
                    while (ttime >= rqu.front() && ferry == 0) {
                        rqu.pop();
                        cout << ttime + t << endl;
                    }
                    ferry = 1;
                    ttime += t;
                    continue;
                }
                else if (!lqu.empty() && !rqu.empty()) {
                    ttime = min(lqu.front(), rqu.front());
                    ferry = lqu.front() < rqu.front() ? 0 : 1;
                    ttime += t;
                }
                else if (!lqu.empty() && rqu.empty()) {
                    ttime += t;
                    ferry = 0;
                }
                else if (lqu.empty() && !rqu.empty()) {
                    ttime += t;
                    ferry = 1;
                }
                else 
                    break;
                
            }
            if(l != c -1)
            cout << endl;
        }
    }