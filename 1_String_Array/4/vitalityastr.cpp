#include <iostream>
#include <string>

using namespace std;

void cre_Str(string &ret, string s){
    for(int i = 0; i < s.size(); i++){
        ret.push_back(s[i]);
    }
    for(int i = ret.size()-1; i > -1; i--){
        if(ret[i] == 'z') ret[i] = 'a';
        else{
            ret[i] += 1;
            break;
        }
    }
}
int main(){
    string s; string t;
    cin >> s >> t;
    string ret;
    for(int i = s.size() - 1; i > -1; i--){
        if(s[i] < t[i] - 1){
            cre_Str(ret,s);
            break;
        }
        if(i < s.size() -1){
            if(s[i] < t[i]){
                cre_Str(ret,s);
                break;
            }
        }
            
    }
    if(ret.empty()) cout << "No such string";
    else
        cout << ret;
}