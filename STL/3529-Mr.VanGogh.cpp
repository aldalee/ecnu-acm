//
// Created by HuanyuLee on 2022/2/2.
// AC
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int nums[21][21] = {0};
    nums[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        nums[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            nums[i][j] = nums[i-1][j]+ nums[i-1][j-1];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << nums[i][j];
            if (j != i)
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}