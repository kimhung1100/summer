#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dost(int n){
    if (n == 1) {
        cout << "Discarded cards:" << endl;
        cout << "Remaining card: 1" << endl;
        return ; }
    queue <int> qu;
    for(int i = 1; i <= n; i++)
        qu.push(i);
    cout << "Discarded cards:";
    while (qu.size() != 1) {
        if(qu.size() == 2) {
            cout << " " << qu.front();
            qu.pop();
            break;
        }
        cout << " " << qu.front() << ",";
        qu.pop();
        qu.push(qu.front());
        qu.pop();
    }
    cout << endl;
    cout << "Remaining card: " << qu.front();
    cout << endl;
    return ;
}
int main(){
    int n;
    while(1) {
        cin >> n;
        if( n == 0)
            break;
        else
            dost(n);
    }
}