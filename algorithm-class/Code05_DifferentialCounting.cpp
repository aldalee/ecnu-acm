// https://acm.ecnu.edu.cn/contest/563/problem/E/
// Created by HuanyuLee on 2022/10/13.
// not AC
#include <iostream>
#include <unordered_map>

using namespace std;

int read() {
    int x = 0, w = 1;
    char c = 0;
    while (c < '0' || c > '9') {
        if (c == '-') w = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return x * w;
}

int main() {
    int n, x;
    cin >> n >> x;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = read();
    }
    unordered_map<int, int> hashtable;
    for (int i = 0; i < n; ++i) {
        hashtable[arr[i] - x] = i;
    }
    int count = 0;
    for (int i = 0; i < n; ++i) {
        auto it = hashtable.find(arr[i]);
        if (it != hashtable.end()) {
            count++;
        }
    }
    cout << count;
    return 0;
}