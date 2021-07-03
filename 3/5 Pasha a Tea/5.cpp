#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
    
    int n, w;
    cin >> n >> w;
    vector <int> ar(2*n);
    for(int i = 0; i < 2*n; i++)
        cin >> ar[i];
    sort(ar.begin(),ar.begin()+2*n);
    double wpg;
    ar[0] <= ar[n] /2 ? wpg = (double)ar[0] : wpg = (double) ar[n] / 2;
    if(wpg <= (double)w/(3*n)) {
        double ret = wpg * 3 * n;
        if(ret != (int) ret)
            cout << fixed << ret;
        else
            cout << (int)ret;
        return 0;
    }
    else
        cout << w;
        /*
    int w;
    double a;
    cin >> w >> a;
    cout << w << " ";
    cout << (int)a << endl;
    if(a == (int)a) cout << (int)a;
    else cout << fixed << a;
    */
}