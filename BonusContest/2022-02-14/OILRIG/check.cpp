// annotshy
// base on VNOI, luriya, kiennguyen246

#include <bits/stdc++.h>
#define F first 
#define S second
#define pb push_back

using namespace std;

random_device rd;
mt19937_64 mt(rd());

// runtime
void exit_with_runtime() {
  double x = 1.0 * clock() / CLOCKS_PER_SEC;
  cerr << "\n\n---------------------\nTime elapsed: " << x << " s.\n\n";
  exit(0);
}

const string Task = "OILRIG"; // task name
const int nTest = 10000; // max test

int random(int l, int r) {
  return mt() % (r - l + 1) + l;
}

int main() {
  srand(time(NULL));
  for(int Test = 1; Test <= nTest; ++ Test) {
    ofstream inp(Task + ".inp");

    int n = 20;
    inp << n << "\n";
    for(int i = 1; i <= n; ++ i) {
      inp << random(1, 1000000000) << " " << random(0, n - 1) << " " << random(1, 1000000000) << "\n";
    }
    for(int i = 2; i <= n; ++ i) {
      inp << random(1, i - 1) << " " << i << "\n";
    }

    inp.close();
    ////////////////// CODE CHECK ////////////////////////
    system((Task + ".exe").c_str());
    system((Task + "_BF.exe").c_str());
    if(system(("fc " + Task + ".out " + Task + ".ans").c_str()) != 0) {
      cout << "Test" << Test << ": WRONG!\n";
      exit_with_runtime();
    }
    cout << "Test " << Test << ": ACCEPTED!\n";
  }
  exit_with_runtime();
}