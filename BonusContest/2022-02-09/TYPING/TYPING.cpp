#include<bits/stdc++.h>

#define Task "TYPING"
#define pb push_back
#define MOD 1000000007
#define F first
#define S second

using namespace std;

const int maxn = 200005;

int type;
string s;
int n;

void query_1() {
	int res = 0;
	n = s.size();
	char last = '.';
	for(int i = 0; i < n; ++ i) {
		if(s[i] == 'T') continue;
		if(last == '.') last = s[i];
		else res += (last != s[i]);
		last = s[i];
	}
	cout << res << "\n";
}

long long pre[maxn], sum[maxn];
pair<int, int> seg[maxn];

void query_2() {
	s = " " + s;
	for(int i = n; i >= 1; -- i) {
		if(s[i] == 'I') {
			s += "A";
			break;
		}
		if(s[i] == 'A') {
			s += "I";
			break;
		}
	}
	char last = '.';
	map<char, int> last_pos;
	int start_point, cnt = 0;
	for(int i = 1; i <= n + 1; ++ i) {
		if(s[i] == 'T') continue;
		if(last != '.') {
			if(s[i] != last) {
				char prec = 'A' + 'I' - s[i];
				seg[++ cnt] = {last_pos[prec] - last_pos[s[i]], i - start_point};
				last = s[i];
				start_point = i;
			}
		} else {
			last = s[i];
			start_point = i;
		}
		last_pos[s[i]] = i;
	}
	long long ans = 0;
	for(int i = 1; i <= cnt; ++ i) {
		ans = (ans + 1ll * seg[i].S * pre[i - 1] % MOD) % MOD;
		sum[i] = (sum[i - 1] + seg[i].F) % MOD;
		pre[i] = (pre[i - 1] + sum[i]) % MOD;
	}
	cout << ans << "\n";
}

void Solve(int Test) {
	cin >> type >> s;
	n = s.size();
	if(type == 0) {
		query_1();
	} else query_2();
}

signed main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  if(fopen(Task".inp", "r")) {
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
  }
  int test = 1;
  cin >> test;
  for(int i = 1; i <= test; ++ i) {
    Solve(i);
  }
}
