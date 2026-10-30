#include <bits/stdc++.h>
#define uint unsigned int
using namespace std;
int n;
vector<int> a;


void solve(){
  for(int mask=0;mask < (1 << n);++mask){
    int res=0;
    for(int i=0;i < n;++i){
      if((mask >> i) & 1){
        res+=a[i];
      }else res-=a[i];
    }

    if(res % 360 == 0){
      cout << "YES";
      return;
    }
  }

  cout << "NO";
}

signed main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  a.resize(n);
  for(int i=0;i < n;++i){
    cin >> a[i];
  }

  solve();
  return 0;
}
