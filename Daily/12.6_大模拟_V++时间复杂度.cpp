#include <bits/stdc++.h>
using namespace std;
#define INF 1e9

int getw(string complex){
    int w;
    if(complex == "O(1)") w = 0;
    else{
        size_t pos1 = complex.find('^');
        size_t pos2 = complex.find(')');
        size_t len = pos2 - pos1 - 1;
        w = stoi(complex.substr(pos1+1, len));
    }
    return w;
}

int toarg(string a){
    if(a == "n") return INF;
    return stoi(a);
}

struct info{
    char var = 0;
    bool contribution = 0;
    bool blocked = 0;

    // info() {
    //     var = 0;
    //     contribution = 0;
    //     blocked = false;
    // }
};



void solve(){

    // -- 初始化 --
    int max_w = 0;
    int cur_w = 0;

    bool used[26], is_err;

    is_err = false;
    memset(used , false, sizeof used);

    stack<info> st;

    // -- 开始处理 --
    int L; string complex;
    cin >> L >> complex;

    int correct_w = getw(complex);


    for(int i = 0; i < L; i++){
        bool contri = 0, is_blocked = 0; //判断是否为无法进入的循环
        char type; cin >> type;
        if(type == 'F'){
            char i; cin >> i;
            if(!used[i-'a']){
                used[i-'a'] = true;
            }else{
                is_err = true;
            }


            string xx, yy;  cin >> xx >> yy;

            // 如果已经有错了，只输入就不处理后续了
            if(is_err) continue;

            int x = toarg(xx);
            int y = toarg(yy);

            if(!st.empty() && st.top().blocked){ // 如果栈中已经为无法进入的循环
                is_blocked = true;
                contri = 0; //外层进不去，内层就也进不去，也对复杂度没有贡献
            }else{
                if(x > y){
                    is_blocked = true;
                }else if(x < y && y == INF){
                    contri = 1;
                    cur_w++;
                    max_w = max(max_w, cur_w);
                }
            }

            st.push({i, contri, is_blocked});

        }else if(type == 'E'){
            if (is_err) continue;

            if (st.empty()) {
                is_err = true;
                continue;
            }

            info top = st.top(); st.pop();
            used[top.var - 'a'] = false;

            if (!top.blocked) {
                cur_w -= top.contribution;
            }
        }
    }

    if (!st.empty()) is_err = true;

    // --输出结果--
    if(is_err == true){
        cout << "ERR" << endl;
    }else{
        if(max_w == correct_w){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    return;
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}