#include <iostream>
#include <algorithm>

using namespace std;

const int P = 110;

int N , V , S[P];
int v[P][P] , w[P][P];
int f[P];

int main()
{
    cin >> N >> V;
    for(int i = 1 ; i <= N ; i++){
        cin >> S[i];
        for(int j = 1 ; j <= S[i] ; j++) cin >> v[i][j] >> w[i][j];
    }
    
    for(int i = 1 ; i <= N ; i++){
        for(int j = V ; j >= 0 ; j--){
            for(int k = 1 ; k <= S[i] ; k++){
                if(j >= v[i][k]) f[j] = max(f[j] , f[j-v[i][k]] + w[i][k]);
            }
        }
    }
    
    cout << f[V] <<endl;
    
    return 0 ;
}