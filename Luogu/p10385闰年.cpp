#include <iostream>

using namespace std;

int num[] = {13,1,2,3,5,4,4,2,2,2};
int y, m, d;
int ball;
int s;

int main(){
    y = 2000, m = 1, d = 1;
    while(1){
        if((m % 2 && m < 8) || (!(m%2) && m >= 8)){ //31天
            if(d >31) m++, d = 1;
        }else if(m == 2){
            if(!(y % 400) || (!(y % 4) && y % 100)){
                if(d > 29) m++, d = 1;
            }else{
                if(d > 28) m++, d = 1;
            }
        }else if(m <=12){  //30天
            if(d > 30) m++, d = 1;
        }
        if(m > 12) y++, m = 1;
        
        s = 0;
        s += num[y / 1000] + num[y / 100 %10] + num[y /10 %10] +num[y % 10];
        s += num[m / 10] + num[m %10];
        s += num[d / 10] + num[d %10];
        
        if(s > 50) ball++;
        
        if(y == 2024 && m == 4 && d == 13) break;

        d++;
    } 
    cout << ball;
    return 0;
}