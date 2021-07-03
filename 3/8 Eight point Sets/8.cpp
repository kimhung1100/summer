#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

class pnt {
private:
    int x;
    int y;
public:
    pnt(){
        x = 0; y = 0;
    }
    pnt(int _x, int _y) {
        x = _x;
        y = _y;
    }
    bool operator < (const pnt& p) {
        if (x < p.x || x == p.x && y < p.y)
            return true;
        else
            return false;
    }
    bool operator == (const pnt& p) {
        if (x == p.x && y == p.y)
            return true;
        else
            return false;
    }
    int getX(){
        return x;
    }
    int getY() {
        return y;
    }
};
int main(){
    vector <pnt> ar;
    int x, y;
    for(int i = 0; i < 8; i++) {
        cin >> x >> y;
        ar.push_back(pnt(x,y));
    }
    sort(ar.begin(), ar.end());
    int x2 = ar[7].getX() - ar[0].getX() - 1;
    int y2 = ar[7].getY() - ar[0].getY() - 1;
    if(x2 < 1 || y2 < 1) {
        cout << "ugly";
        return 0;
    }
    else if (x2 == 1 && y2 == 1) {
        x2 = ar[7].getX() - 1;
        y2 = ar[7].getY() - 1;
        pnt pn;
        pn = pnt(x2, y2);
        for(int i = 0; i < 8; i++)
            if(ar[i] == pn) {
                cout << "ugly";
                return 0;
            }
        cout << "respectable";
        return 0;
    }
    
    else {
        for(int i = 0; i < 8; i++) 
            if(ar[i].getX() > ar[0].getX() && ar[i].getY() > ar[0].getY()
                && ar[i].getX() < ar[7].getX() && ar[i].getY() < ar[7].getY() ) {
                cout << "ugly";
                return 0;
            }
        if(ar[3].getY() != ar[0].getY() || ar[4].getY() != ar[2].getY() ){
            cout << "ugly";
            return 0;
        }
        cout << "respectable";
    }
}