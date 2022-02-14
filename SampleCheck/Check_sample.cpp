// annotshy
// base on VNOI

#include <bits/stdc++.h>

using namespace std;

// use this rd() instead of using rand()
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());

// runtime
void exit_with_runtime()
{
    double x = 1.0 * clock() / CLOCKS_PER_SEC;
    cerr << "\n\n---------------------\nTime elapsed: " << x << " s.\n\n";
    exit(0);
}

const string Task = "GARDEN"; // task name
const int nTest = 100; // max test

int RandInt(int l, int r) {
  return uniform_int_distribution<int> (l, r) (rd);
}

int main() {
  srand(time(NULL));
  for(int Test = 1; Test <= nTest; ++ Test) {
    ofstream inp(Task + ".inp");
    //////////////// CODE GENERATE START HERE ///////////////////////
    int m = RandInt(1, 100);
    int n = RandInt(1, 100);
    int k = RandInt(1, 100);
    inp << Test << "\n" << m << " " << n << " " << k << "\n";
    for(int i = 1; i <= m; ++ i) {
      for(int j = 1; j <= n; ++ j) {
        int x = RandInt(1, 1000000000);
        int sign = RandInt(0, 1);
        if(!sign) inp << x << " \n"[j == n];
        else inp << - x << " \n"[j == n];
      }
    }
    inp.close();
    ////////////////// CODE CHECK START HERE ////////////////////////
    system((Task + ".exe").c_str());
    system((Task + "_BF.exe").c_str());
    if(system(("fc " + Task + ".out " + Task + ".ans").c_str()) != 0) {
      cout << "Test" << Test << ": WRONG!\n";
      /* expected answer and output found */
      long long ANS, OUT;
      ifstream fa, fo;
      fa.open(Task + ".ans");
      fo.open(Task + ".out");
      while(fa >> ANS) {
        fo >> OUT;
        if(ANS != OUT) {
          cout << "Expected: " << ANS << "\nFound: " << OUT << "\n";
          fa.close();
          fo.close();
          exit_with_runtime();
        }
      }
    }
    cout << "Test " << Test << ": ACCEPTED!\n";
  }
  exit_with_runtime();
}

