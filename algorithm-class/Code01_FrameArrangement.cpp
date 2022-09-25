// https://acm.ecnu.edu.cn/contest/563/problem/A/
// Created by HuanyuLee on 2022/9/24.
//

#include <iostream>

using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    int coordinates[n+1];   // coordinates[0] save the answer
    for (int i = 1; i <= n; ++i) {
        cin >> coordinates[i];
    }

    int a = 123;
    string sa = to_string(a);

    // for test
    for (int i = 0; i < n+1; ++i) {
        cout << coordinates[i] << " ";
    }

    return 0;
}