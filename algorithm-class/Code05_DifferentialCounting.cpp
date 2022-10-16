// https://acm.ecnu.edu.cn/contest/563/problem/E/
// Created by HuanyuLee on 2022/10/13.
// AC
#include <iostream>

using namespace std;
#define MAX_VALUE 3000000
#define MAX_LENGTH 7000000
// hashCount[]的索引代表原数组arr[]的值，hashCount[i]的值代表arr[i]出现的次数
// 因为arr[i]有正有负，因此做这样的处理
// hash(x) = MAX_VALUE + x    x ∈ [-MAX_VALUE,MAX_VALUE]
// 查找 x 的位置，时间复杂度O(1)
long hashCount[MAX_LENGTH];
int read() {
    int x = 0, w = 1;
    char c = 0;
    while (c < '0' || c > '9') {
        if (c == '-') w = -1;
        c = (char)getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + (c - '0');
        c = (char)getchar();
    }
    return x * w;
}

int main() {
    int n, x;
    cin >> n >> x;
    long diff[n];
    long count = 0;
    for (int i = 0; i < n; ++i) {
        int num = read();
        // a[i] - a[j] = x 等价于 a[i] - x = a[j]
        // 求差值数组
        diff[i] = num - x;
        // 将数num映射到hash表中
        hashCount[num + MAX_VALUE]++;
    }
    // 统计有序对的个数
    for (int i = 0; i < n; ++i) {
        count += hashCount[diff[i] + MAX_VALUE];
    }
    printf("%ld", count);
    return 0;
}