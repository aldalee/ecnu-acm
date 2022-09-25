// https://acm.ecnu.edu.cn/contest/563/problem/B/
// Created by HuanyuLee on 2022/9/24.
//
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int getK(int x) {
    int k = 0;
    while (x != 0) {
        x /= 10;
        k++;
    }
    return k;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    // descending order
    sort(arr,arr+n, greater<int>());
    int k;
    for (int i = 0; i < n; ++i) {
        
    }

    return 0;
}
