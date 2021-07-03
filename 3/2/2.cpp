#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, a, b;
    cin >> n >> a >> b;
    vector <int> ar(n);
    for(int i = 0; i < n; i++)
        cin >> ar[i];
    sort(ar.begin(), ar.begin() + n);
    int x = ar[n - a] - ar[b - 1];
    cout << x;
}