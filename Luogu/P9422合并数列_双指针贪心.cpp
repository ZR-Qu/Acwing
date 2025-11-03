// #include <iostream>
// using namespace std;

// const int N = 1e5 + 10;
// int a[N], b[N];
// int n, m;
// int ans;

// int main()
// {
//   scanf("%d%d", &n, &m);
//   for(int i = 0; i < n; i++) scanf("%d", &a[i]); 
//   for(int i = 0; i < m; i++) scanf("%d", &b[i]); 

//   int i = 0, j = 0;
//   while(i < n || j < m){
//     if(a[i] < b[j]){
//       a[i + 1] += a[i];
//       i++;
//       ans++;
//     }else if(a[i] > b[j]){
//       b[j + 1] += b[j];
//       j++;
//       ans++;
//     }else{
//       i++; j++;
//     }
//   }

//   printf("%d", ans);

//   return 0;
// }

#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N], b[N];
int n, m;
int s1, s2;
int ans;

int main()
{
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++) scanf("%d", &a[i]); 
  for(int i = 0; i < m; i++) scanf("%d", &b[i]); 

  int i = 0, j = 0;
  s1 = a[0]; s2 = b[0];
  while(i < n || j < m){
    if(s1 < s2){
      i++;
      s1 += a[i];
      ans++;
    }else if(s1 >s2){
      j++;
      s2 += b[j];
      ans++;
    }else{
      i++; j++;
      if(i < n) s1 = a[i];
      if(j < m) s2 = b[j];
    }
  }

  printf("%d", ans);

  return 0;
}