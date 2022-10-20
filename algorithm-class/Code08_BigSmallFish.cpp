// https://acm.ecnu.edu.cn/contest/563/problem/H/
// Created by HuanyuLee on 2022/10/19.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct fish {
    int w;
    int a;
};

int main() {
    int N;
    scanf("%d", &N);
    vector<fish> arr(N);
    int L = 1e9, R = 0;
    for (int i = 0; i < N; ++i) {
        scanf("%d%d", &arr[i].w, &arr[i].a);
        L = min(L, arr[i].w);
        R += abs(arr[i].w * arr[i].a);
    }
    sort(arr.begin(), arr.end(), [](fish f1, fish f2) { return f1.a > f2.a; });
    int x;
    while (L <= R) {
        x = ((R - L) >> 1) + L;
        for (int i = 0; i < N; ++i) {
            if (x >= arr[i].w) x += arr[i].a;
            if (x <= 0) break;
        }
        if (x > 0) {
            R = x - 1;
        } else {
            L = x + 1;
        }
    }
    cout << x;
    return 0;
}
