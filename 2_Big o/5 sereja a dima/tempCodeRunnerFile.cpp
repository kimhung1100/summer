#include <iostream>

using namespace std;

int main(){
    int n;
     cin >> n;
    int card[n];
    for(int i = 0; i < n; i++)
        cin >> card[i];
    int L = 0;
    int scrS = 0;
    int scrD = 0;
    int R = n - 1;
    for(int turn = 0; turn < n; turn++){
        int temp;
        if(card[L] >= card[R]){
            temp = card[L];
            L ++;
        }
        else {
            temp = card[R];
            R --;
        }
        if(turn % 2) 
            scrD += temp;
        else
            scrS += temp;
    }
    cout << scrS << " " << scrD;

}