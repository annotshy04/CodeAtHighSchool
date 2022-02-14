string Add(string a, string b) {
  string res = "";
  while(a.size() < b.size()) a = "0" + a;
  while(b.size() < a.size()) b = "0" + b;
  int carry = 0;
  for(int i = a.size() - 1; i >= 0; -- i) {
    int tmp = a[i] - 48 + b[i] - 48 + carry;
    carry = tmp / 10;
    tmp = tmp % 10;
    res = (char)(tmp + 48) + res;
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
    res = (char) (tmp % 10 + 48) + res;
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
        int a1 = a[j] - 48;
        int b1 = b[i - j - 1] - 48;
        tmp += a1 * b1;
      }
    tmp += carry;
    carry = tmp / 10;
    res = (char)(tmp % 10 + 48) + res;
  }
  while(res.size() > 1 && res[0] == '0') res.erase(0, 1);
  return res;
}