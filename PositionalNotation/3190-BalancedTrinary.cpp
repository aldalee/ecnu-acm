//
// Created by HuanyuLee on 2022/2/2.
// AC
#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int T;
    cin >> T;
    string s;
    int num = 0;
    for (int i = 0; i < T; ++i) {
       cin >> s;
       int p = s.length() - 1;
       int w = p;
       while (p >= 0){
           if (s[w-p] == '1')
               num += pow(3, p);
           if (s[w-p] == '-')
               num -= pow(3, p);
           p--;
        }
        cout << "case #"+ to_string(i)+":\n";
        cout << num << endl;
        num = 0;
    }
    return 0;
}
