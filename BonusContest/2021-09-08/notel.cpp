#include <iostream>
#include <vector>
using namespace std;

const int mod = 1000000007;
int n,k;
vector<int> dp;

int main(int argc,const char** argv){
    freopen("notel.inp","r",stdin);
    freopen("notel.out","w",stdout);
    cin >> n >> k;
    dp.resize(n+1);
    dp[0] = 1;
    for(int i = 1;i <= k;i++){
    	for(int j = 0;j <= n;j++){
    		if(j - i >= 0) dp[j] += dp[j-i];
    		while(dp[j] >= mod) dp[j] -= mod;
    	}
    }
    cout << dp[n];
}