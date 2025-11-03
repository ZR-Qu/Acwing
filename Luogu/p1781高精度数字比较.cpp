#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

vector<int> A;
vector<int> B;

int no1;

bool cmp(vector<int> a, vector<int> b){
    if(!(a.size() == b.size())) return a.size() > b.size();
    for(int i = a.size() - 1; i >= 0; i--){
        if(!(a[i] == b[i])) return a[i] > b[i];
    }
    return 0;
}

int main(){
    int n;
    cin >>n;
    for(int i = 1; i <= n; i++){
        string t;
        cin >> t;
        B.clear();  //动态数组记得清空，因为后面是pushback
        for(int i = t.size() - 1; i >= 0; i--) B.push_back(t[i] - '0');
        if(cmp(B, A)){
            A = B;  //！！！ 动态数组可以直接用 = 赋值
            no1 = i;
        }
    }
    printf("%d\n", no1);

    for(int i = A.size() - 1; i >= 0; i--) printf("%d", A[i]);
}