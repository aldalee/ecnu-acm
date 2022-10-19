// https://acm.ecnu.edu.cn/contest/563/problem/G/
// Created by HuanyuLee on 2022/10/19.
// AC
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, l;
    int q = 0;
    scanf("%d%d", &n, &l);
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    sort(arr.begin(), arr.end());
    int i = 0, j = n - 1;
    // 每次只装一个箱子，选最大和最小的装箱，若溢出则只装最大的物品
    while (i <= j) {
        if (arr[i] + arr[j] <= l) {
            i++;
        }
        j--;
        q++;
    }
    cout << q;
    return 0;
}
