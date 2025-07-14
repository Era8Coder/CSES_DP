#include<iostream>
#include<bitset>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
typedef long long ll;
typedef long double ld;
using namespace std;

ld distance(ll px, ll py, ll qx, ll qy){
    return sqrt((qx-px)*(qx-px) + (qy-py)*(qy-py));
}

void printvec(vector<int> &v){
    int n=v.size();
    for(int i=0; i<n; i++){
       cout<<v[i]<<" ";
    }
    cout<<endl;
}

ll gcd(ll a, ll b){
    while(b != 0){
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}

ll lcm(ll a, ll b){
    ll prod = a*b;
    return prod/gcd(a,b);
}

void solve(){
    int n;  cin>>n;
    vector<ll> dp(n+1,-1);
    ll MOD=1e9+7;
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    dp[4]=8;
    dp[5]=16;
    dp[6]=32;
    for(int i=7; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3] + dp[i-4] + dp[i-5] + dp[i-6];
        dp[i] = dp[i]%MOD;
    }
    cout<<dp[n]<<endl; 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;  t=1;
    while(t--){
        solve();
    }
    return 0;
}
