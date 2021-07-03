#include <iostream>

using namespace std;

int main(){
    string s, t;
    cin >> s >> t;
/*
    //need tree
    char cnS[26];
    cnS[0] = 'a';
    
    char cnT[26];
    cnT[0] = 'a';
    for(int i = 1; i < 26; i++){
        cnS[i] = cnS[i-1] +1;
        cnT[i] = cnT[i-1] +1;
    }
    for(int i = 0; i < s.size(); i++){
        for(int j = 0; j < 26; j++){
            
        }
    }
*/
    //int *cnS;
    int *cnS = new int[s.size()]; 
    for(char i : s ){
        cnS[i - 97] += 1;
    }
    for(int i = 0; i < s.size(); i++){
        cout << cnS[i] << " ";
    }
}