void KMP(string a) {
  int len = a.length();
  kmp[0] = -1;
  for(int i = 1; i < len; ++ i) {
    int k = kmp[i - 1];
    while(k >= 0 && a[i] != a[k + 1]) k = kmp[k];
    kmp[i] = k + 1;
    res += (kmp[i] == n);
  }
}
