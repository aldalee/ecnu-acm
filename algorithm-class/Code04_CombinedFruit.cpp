// https://acm.ecnu.edu.cn/contest/563/problem/D/
// Created by HuanyuLee on 2022/10/14.
// AC
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<>> heap;
    while (n--) {
        int x;
        cin >> x;
        heap.push(x);
    }
    int ans = 0;
    while (heap.size() > 1) {
        int i = heap.top();
        heap.pop();
        int j = heap.top();
        heap.pop();
        ans += i + j;
        heap.push(i + j);
    }
    cout << ans;
    return 0;
}

