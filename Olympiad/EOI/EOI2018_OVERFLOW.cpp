// annotshy

#include <bits/stdc++.h>

#define Task "CF"

using namespace std;

const int maxn = 200005;

string Add(string a, string b) {
  string res = "";
  while(a.size() < b.size()) a = "0" + a;
  while(b.size() < a.size()) b = "0" + b;
  int carry = 0;
  for(int i = a.size() - 1; i >= 0; -- i) {
    int tmp = a[i] - '0' + b[i] - '0' + carry;
    carry = tmp / 10;
    tmp = tmp % 10;
    res = (char)(tmp + '0') + res;
  }
  if(carry > 0) res = "1" + res;
  return res;
}
 
string Sub(string a, string b) {
  string res = "";
  while(a.size() < b.size()) a = "0" + a;
  while(b.size() < a.size()) b = "0" + b;
  bool neg = false;
  if(a < b) {
    swap(a, b);
    neg = true;
  }
  int borrow = 0;
  for(int i = a.size() - 1; i >= 0; -- i) {
    int tmp = a[i] - b[i] - borrow;
    if(tmp < 0) {
      tmp += 10;
      borrow = 1;
    } else borrow=0;
    res = (char) (tmp % 10 + '0') + res;
  }
    while(res.size() > 1 && res[0] == '0') res.erase(0, 1);
    if(neg) res = "-" + res;
    return res;
}
 
string Mul(string a, string b) {
  string res = "";
  int n = a.size();
  int m = b.size();
  int len = n + m - 1;
  int carry = 0;
  for(int i = len; i >= 0; -- i) {
    int tmp = 0;
    for(int j = n - 1; j >= 0; -- j)
      if(i - j <= m && i - j >= 1) {
        int a1 = a[j] - '0';
        int b1 = b[i - j - 1] - '0';
        tmp += a1 * b1;
      }
    tmp += carry;
    carry = tmp / 10;
    res = (char)(tmp % 10 + '0') + res;
  }
  while(res.size() > 1 && res[0] == '0') res.erase(0, 1);
  return res;
}

bool Compare(string a, string b) {
	if(a.size() > b.size()) return 0;
	if(a.size() < b.size()) return 1;
	int len = a.size();
	for(int i = 0; i < len; ++ i) {
		if(a[i] > b[i]) return 0;
		if(a[i] < b[i]) return 1;
	}
	return 1;
}

void Solve(int Test) {
  string m, a, b;
  char c; cin >> m >> a >> b >> c;
  if(a[0] == '-' || b[0] == '-') {
  	cout << 0 << "\n";
  	return;
  }
  if(!Compare(a, m) || !Compare(b, m)) {
  	cout << 0 << "\n";
  	return;
  }
  if(c == '-') a = Sub(a, b);
  if(c == '+') a = Add(a, b);
  if(c == '*') a = Mul(a, b);
  if(a[0] == '-') {
  	cout << 0 << "\n";
  	return;
  }
  if(Compare(a, m)) cout << 1 << "\n";
  else cout << 0 << "\n";
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
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

/*no pain no gain*/
