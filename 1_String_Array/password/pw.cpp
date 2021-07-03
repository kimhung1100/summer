#include <iostream>

using namespace std;


void print (int indmin, int indmax, int k){
    int min = (indmin/k * 5) + indmin;
    int max = (indmax/k * 5) + indmax;
    if(indmax % k == 0 && indmax >= k) max -= 5;
    if(indmin % k == 0 && indmax >= k) min -= 5;
    cout << min << " " << max;
}
int main(){
    int n, k;
    cin >> n >> k;
    string *s = new string[n];
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    string pas;
    cin >> pas;
    ////////
    for(int i = 0; i< n; i++){
        for(int j = i; j < n; j++){
            if(s[i].size() > s[j].size()){
                string temp = s[j];
                s[j] = s[i];
                s[i] = temp;
            }
        }
    }
    
    int indmin, indmax = 0;
    for(int i = 0; i < n; i++)
        if(s[i].size() == pas.size()){
            indmin = i+1; break;}
    for(int i = 0; i < n; i++){
        if(i == n - 1) indmax = i+1;
        if(s[i+1].size() > pas.size()){
            indmax = i+1; break;}
    }
    
    print(indmin, indmax, k);
    
    
    return 0;
}