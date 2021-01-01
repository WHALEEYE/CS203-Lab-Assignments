#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    const long long md = 1000000007;
    long long n;
    long long x;
    cin >> n;
    x = ((n * (n + 1) / 2) % md) * ((n * (n + 1) / 2) % md) % md;
    cout << x << endl;
  }
}