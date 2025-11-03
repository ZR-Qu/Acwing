#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

string maxstr = "";
int id;

int main(){
    int n;
    cin >> n;
    string t;
    for(int i = 1; i<=n; i++){
        cin >> t;
        int len1 = maxstr.size();
        int len2 = t.size();

        if(len1 < len2 ||(len1 == len2 && t > maxstr)){
            maxstr = t;
            id = i;
        }
    }
    cout << id << endl << maxstr << endl;
    return 0;
}