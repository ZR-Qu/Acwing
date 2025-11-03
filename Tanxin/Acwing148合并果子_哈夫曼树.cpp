#include <iostream>
#include <queue>
using namespace std;

const int N = 1e4 + 10;
int n;
int w, ans;

int main(){
    cin >> n;
    priority_queue<int, vector<int>, greater<int> > heap;
    
    for(int i = 0; i < n; i++){
        scanf("%d", &w);
        heap.push(w);
    }
    
    int t1, t2;
    while(heap.size() > 1){
        t1 = heap.top(); heap.pop();
        t2 = heap.top(); heap.pop();
        ans += t1 + t2;
        heap.push(t1 + t2);
    }
    
    cout << ans << endl;
    return 0;
}