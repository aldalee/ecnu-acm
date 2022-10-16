// https://acm.ecnu.edu.cn/contest/563/problem/F/
// Created by HuanyuLee on 2022/10/14.
// AC
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 记录以[i,j]为中心划分的四个象限的最大值
void setRectangleMax(vector<vector<int>> &arr, int n, int m,
                     vector<vector<int>> &top_left,
                     vector<vector<int>> &bottom_left,
                     vector<vector<int>> &top_right,
                     vector<vector<int>> &bottom_right) {
    // ⅠⅡ 象限
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            top_left[i][j] = max({top_left[i - 1][j], top_left[i][j - 1], arr[i][j]});
        }
        for (int j = m; j >= 1; j--) {
            top_right[i][j] = max({top_right[i - 1][j], top_right[i][j + 1], arr[i][j]});
        }
    }
    // Ⅲ Ⅳ 象限
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= m; j++) {
            bottom_left[i][j] = max({bottom_left[i][j - 1], bottom_left[i + 1][j], arr[i][j]});
        }
        for (int j = m; j >= 1; j--) {
            bottom_right[i][j] = max({bottom_right[i + 1][j], bottom_right[i][j + 1], arr[i][j]});
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n + 1, vector<int>(m + 1, -1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf_s("%d", &arr[i][j]);
        }
    }
    vector<vector<int>> top_left(n + 2, vector<int>(m + 2, -1));
    vector<vector<int>> bottom_left(n + 2, vector<int>(m + 2, -1));
    vector<vector<int>> top_right(n + 2, vector<int>(m + 2, -1));
    vector<vector<int>> bottom_right(n + 2, vector<int>(m + 2, -1));
    setRectangleMax(arr, n, m, top_left, bottom_left, top_right, bottom_right);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (i == 1 || j == 1 || i == n || j == m)
                printf("%d ", 0);
            else {
                long tl = top_left[i - 1][j - 1];
                long tr = top_right[i - 1][j + 1];
                long bl = bottom_left[i + 1][j - 1];
                long br = bottom_right[i + 1][j + 1];
                printf("%ld ", tl * tr * bl * br);
            }
        }
        printf("\n");
    }
    return 0;
}