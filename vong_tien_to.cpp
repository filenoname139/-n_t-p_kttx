#include <bits/stdc++.h>
#define uint unsigned int
using namespace std;
int n;
vector<int> a;


void solve(){
  vector<int> tron(n*2+1,0);
  for(int i=0;i < 2*n;++i){
    tron[i+1] = tron[i] + a[i%n];
  }


  // ------------------------------------------

  // int dem=0;
  // for(int i=0;i < n;++i){
  //   int pre=0;
  //   bool flag=0;
  //   for(int j=i;j < i+n;++j){
  //     pre+=tron[j];
  //     if(pre < 0){
  //       flag=1;
  //       break;
  //     }
  //   }
    
  //   if(!flag) dem++;
  // }

  // ------------------------------------------

  deque<int> dq;
  
  for(int j=1;j <= n;++j){
    while(!dq.empty() && tron[dq.back()] >= tron[j]){
      dq.pop_back();
    }
    dq.push_back(j);
  }

  int dem=0;

  for(int i=0;i < n;++i){
    if(tron[dq.front()] >= tron[i]){
      dem++;
    }

    if(!dq.empty() && dq.front() == i+1){
      dq.pop_front();
    }

    if(i+1 < n){
      int nej=i+n+1;
      while(!dq.empty() && tron[dq.back()] >= tron[nej]){
        dq.pop_back();
      }
      dq.push_back(nej);
    }
  }

  cout << dem;
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
