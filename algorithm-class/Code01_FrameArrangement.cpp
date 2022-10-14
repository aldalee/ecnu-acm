// https://acm.ecnu.edu.cn/contest/563/problem/A/
// Created by HuanyuLee on 2022/9/24.
// AC

#include <iostream>
#include <algorithm>

using namespace std;

int binarySearchFirstMaxNumber(const int x[], int n, int ans) {
    int l = 0;
    int r = n - 1;
    int index = -1;
    while (l <= r) {
        int mid = ((r - l) >> 1) + l;
        if (x[mid] > ans) {
            index = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return index;
}

int getMinimumQuantityK(const int x[], int n, int k) {
    int count = 1;
    int i = 0;
    int ans = x[i] + k;
    while (i < n) {
        if (ans >= x[n - 1]) {
            break;
        }
        // find next
        i = binarySearchFirstMaxNumber(x, n, ans);
        ans = x[i] + k;
        count++;
    }
    return count;
}

int main() {
    int n, k;
    cin >> n >> k;
    int x[n];
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    sort(x, x + n);
    cout << getMinimumQuantityK(x, n, k);
    return 0;
}