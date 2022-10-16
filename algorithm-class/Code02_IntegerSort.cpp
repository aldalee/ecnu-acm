// https://acm.ecnu.edu.cn/contest/563/problem/B/
// Created by HuanyuLee on 2022/9/24.
// AC
#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int> &nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void quickSort(vector<int> &nums, int start, int end) {
    if (start >= end) {
        return;
    }
    int pivot = nums[start];
    int q = start;
    long y = 10; // bis of the number pivot
    while (pivot >= y) {
        y *= 10;
    }
    for (int i = start + 1; i <= end; i++) {
        long x = 10;    // bis of the number nums[i]
        while (nums[i] >= x) {
            x *= 10;
        }
        if (nums[i] * y + pivot > nums[i] + pivot * x) {
            ++q;
            swap(nums, q, i);
        }
    }
    swap(nums, q, start);
    quickSort(nums, start, q - 1);
    quickSort(nums, q + 1, end);
}


string largestNumber(vector<int> &nums) {
    quickSort(nums, 0, (int)nums.size() - 1);
    string ans;
    for (int &t: nums) {
        ans += to_string(t);
    }
    if (ans[0] == '0') {
        return "0";
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << largestNumber(arr);
    return 0;
}