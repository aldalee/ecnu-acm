// https://acm.ecnu.edu.cn/contest/563/problem/L/
// Created by HuanyuLee on 2022/11/6.
// AC
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    int x;
    priority_queue<int, vector<int>> maxHeap;
    priority_queue<int, vector<int>, greater<>> minHeap;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        maxHeap.push(x);
        minHeap.push(x);
    }
    int a, b;
    // 每次取最大，最终得到的是最小值
    while (maxHeap.size() != 1) {
        a = maxHeap.top();
        maxHeap.pop();
        b = maxHeap.top();
        maxHeap.pop();
        maxHeap.push(a * b + 1);
    }
    // 每次取最小，最终得到的是最大值
    while (minHeap.size() != 1) {
        a = minHeap.top();
        minHeap.pop();
        b = minHeap.top();
        minHeap.pop();
        minHeap.push(a * b + 1);
    }
    cout << minHeap.top() - maxHeap.top();
    return 0;
}