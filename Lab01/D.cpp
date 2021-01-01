#include <iostream>
using namespace std;
void pt(int a, int b, int c);

int main() {
  int a, b, c, t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> a >> b >> c;
    pt(a, b, c);
  }
  return 0;
}

void pt(int a, int b, int c) {
  int gp[2 * (b + c) + 1][2 * (a + b) + 1];
  for (int i = 0; i < 2 * (b + c) + 1; i++) {
    for (int j = 0; j < 2 * (a + b) + 1; j++) {
      if ((i % 2 == 0 && j % 2 == 0 && i + j >= 2 * b &&
           i + j <= 2 * (a + b + c))) {
        gp[i][j] = 2;
      } else if ((i % 2 == 1 && j % 2 == 1 && i + j >= 2 * b &&
                  i + j <= 2 * (a + b + c)) &&
                 ((i < 2 * b) || (i > 2 * b && j > 2 * a))) {
        gp[i][j] = 5;
      } else if ((i % 2 == 1 && j % 2 == 0 && i + j >= 2 * b &&
                  i + j <= 2 * (a + b + c)) &&
                 ((i + j >= 2 * (a + b) && i < 2 * b) || (i > 2 * b))) {
        gp[i][j] = 4;
      } else if ((i % 2 == 0 && j % 2 == 1 && i + j >= 2 * b &&
                  i + j <= 2 * (a + b + c)) &&
                 ((i + j < 2 * (a + b) && i < 2 * b) ||
                  (i >= 2 * b && j < 2 * a))) {
        gp[i][j] = 3;
      } else {
        gp[i][j] = 1;
      }
    }
  }
  for (int i = 0; i < 2 * (b + c) + 1; i++) {
    for (int j = 0; j < 2 * (a + b) + 1; j++) {
      switch (gp[i][j]) {
        case 1:
          cout << ".";
          break;
        case 2:
          cout << "+";
          break;
        case 3:
          cout << "-";
          break;
        case 4:
          cout << "|";
          break;
        case 5:
          cout << "/";
          break;
        default:
          break;
      }
    }
    cout << endl;
  }
}