#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1e5 + 10;
int n;

struct range{
    int l, r;
    bool operator< (const range &w) const{
        return l < w.l;
    }
}range[N];

int main(){
    scanf("%d", &n);
    int l,r;
    for(int i = 0; i < n; i++){
        scanf("%d%d" , &l, &r);
        range[i] = {l, r};
    }
    sort(range, range + n);
    
    priority_queue<int, vector<int>, greater<int> > heap; //堆中放每组的右端点，大小为组数
    
    for(int i = 0; i < n; i++){
        int right;
        /*
        能放就放目前最小右端点的组中，不能放在最小组就开新组
        如果当前区间无法和堆顶的分组合并，其他的分组就更不可能合并，
        【当当前分组的左端点小于最小右端点组的右端点，那么当前分组的左端点一定小于其他分组的右端点
        当前分组的左端点一定大于等于其他分组的左端点（因为最开始的区间以左端点排序了）】
        所以，与其他分组之间也一定有交集放不了
        */
        if(!heap.empty()) right = heap.top();   //heap.top() 在 heap 为空时被访问,会Segmentation Fault段错误
        if(heap.empty() || range[i].l <= right) heap.push(range[i].r); // 可以改为heap.empty() || range[i].l <= heap.top() heap.empty()为空判断成功后，后面不会判断，避免了段错误
        else{
            heap.pop();
            heap.push(range[i].r); //r不是l
        }
    }
    
    cout << heap.size() <<endl;
    
    return 0;
}