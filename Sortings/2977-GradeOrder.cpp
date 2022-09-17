//
// Created by HuanyuLee on 2022/2/2.
// AC

#include <iostream>
#include <algorithm>
using namespace std;
struct Student{
    string id;
    int grades{};
};
bool cmp(Student& s1,Student& s2){
    if (s1.grades == s2.grades)
        return s1.id < s2.id;
    return s1.grades > s2.grades;
}
int main(){
    int T;
    cin >> T;
    int N,M,G;  // 学生数、题目数、分数线
    for (int i = 0; i < T; ++i) {
        cin >> N >> M >> G;
        Student s[N];
        int a[M+1];   // 每个题目的分值
        for (int j = 1; j <= M; ++j)
            cin >> a[j];
        int S;  // 学生解出的题目总数
        int index;  // 学生解出的题目题号
        int count = 0;  // 不低于分数线的学生人数
        for (int j = 0; j < N; ++j) {
            cin >> s[j].id >> S;
            for (int k = 1; k <= S; ++k) {
                cin >> index;
                s[j].grades += a[index];
            }
            if (s[j].grades >= G)
                count++;
        }
        //
        sort(s,s+N,cmp);

        cout << "case #" << i << ":\n";
        cout << count << endl;
        for (int j = 0; j < count; ++j)
            cout << s[j].id << " " << s[j].grades << endl;
    }
    return 0;
}