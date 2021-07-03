#include <iostream>
#include <stack>

using namespace std;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        stack <char> c;
        for(int j = 0; j < s.size(); j++) {
            if (s[j]  >= 'a' && s[j] <= 'z')
                cout << s[j];
            else if (s[j] != ')')
                c.push(s[j]);
            else 
                while(1) {
                    if(c.top() == '(') {
                        c.pop();
                        break;
                    }
                    else {
                        cout << c.top();
                        c.pop();
                    }
                }
        }
        cout << endl;
    }
}
