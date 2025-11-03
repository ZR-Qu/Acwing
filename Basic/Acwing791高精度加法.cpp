#include <iostream>
#include <string>
#include <vector>

const int N = 1e5+10;

using namespace std;

vector<int> add(vector<int> a, vector<int> b){
    vector<int> c;
    int t = 0;  //初始化为0
    for(int i = 0 ; i < a.size() || i < b.size(); i++){
        if(i < a.size()) t += a[i];
        if(i < b.size()) t += b[i];
        c.push_back(t % 10);
        t = t /10; 
    }

    if(t) c.push_back(t); //最后有进位 +1

    return c;
}

int main(){
    string x, y;
    cin >> x >> y;

    vector<int> a, b;
    for(int i = x.size() - 1; i >= 0; i--) a.push_back(x[i] - '0');
    for(int i = y.size() - 1; i >= 0; i--) b.push_back(y[i] - '0');
    
    vector<int> c = add(a, b);
    
    for(int i = c.size() - 1; i >= 0 ; i--) printf("%d", c[i]);
    
    return 0;
}