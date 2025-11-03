#include <iostream>
#include <string>

using namespace std;

string queue;

int main(){
    cin >> queue;
    int time = 0;
    int cnt_M = 0;
    for(auto& i: queue){
        if(i == 'M') cnt_M++;
        else{
            if(cnt_M) time = max(time + 1, cnt_M);
        }
    }
    cout << time << endl;
    return 0;
}