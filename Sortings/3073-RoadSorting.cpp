//
// Created by HuanyuLee on 2022/2/2.
// AC
#include <iostream>
#include <algorithm>
using namespace std;
struct Road{
    int i;
    int j;
    int a;
};
bool cmp(Road& r1,Road& r2){
    if (r1.a == r2.a){
        if (r1.i == r2.i)
            return r1.j < r2.j;
        return r1.i < r2.i;
    }
    return r1.a > r2.a;
}
int main(){
    int T,N,M;
    cin >> T;
    for (int k = 0; k < T; ++k) {
        cin >> N >> M;
        Road road[M];
        for (int i = 0; i < M; ++i) {
            cin >> road[i].i >> road[i].j >> road[i].a;
        }
        sort(road,road+M,cmp);
        cout << "case #" + to_string(k) + ":" << endl;
        for (int j = 0; j < M; ++j) {
            cout << "("+to_string(road[j].i) + "," + to_string(road[j].j) + ","+ to_string(road[j].a) + ")\n";
        }
    }
    return 0;
}
