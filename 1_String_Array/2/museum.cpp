#include <iostream>

using namespace std;

int main(){
    string s;
    cin >> s;
    char array[26];
    array[0] = 'a';
    for(int i = 1; i < 26; i++){
        array[i] = array[i-1] +1;
    }
    int ret = 0;
    int iter = 0;
    int cur1 = 0;
    int cur2 = 0;
    int count = 0;
    int j1 =0;
    int j2 = 0;
    for(int i = 0; i < s.size(); i++){
        for(int j = iter; j <= 26; j++){
            if(j == 26)  j = 0;
            if(array[j] == s[i]){
                cur1 = count;
                count = 0;
                j1 = j;
                break;
            }
            count ++;
        }
        for(int j = iter; j >= -1; j--){
            if(j == -1)  j = 25;
            if(array[j] == s [i]){
                cur2 = count;
                count = 0;
                j2 = j;
                break;
            }
            count ++;
        }
        if(cur1 > cur2){
            ret += cur2;
            iter = j1;
        }
        else{
            ret += cur1;
            iter = j2;
        }
        cur1 = 0; cur2 = 0;
    }
    cout << ret;
}