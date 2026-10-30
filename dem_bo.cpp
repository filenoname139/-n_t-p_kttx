#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
vector<int> pre;


void solve(){
  pre.assign(n+5,0);
  for(int i=1;i <= n;++i){
    pre[i]=(pre[i-1]+a[i-1]) % 7;
  }

  vector<int> xh_dau(7,-1);
  int res=0;
  for(int i=0;i <= n;++i){
    if(xh_dau[pre[i]] == -1) xh_dau[pre[i]]=i;
    else res=max(res,i-xh_dau[pre[i]]);
  }

  cout << res;
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
