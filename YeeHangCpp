#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  ifstream infile;
  infile.open("salesin.txt");
  string ai, bi, ci;
  infile >> ai;
  int a = stoi(ai);
  infile >> bi;
  int b = stoi(bi);
  infile >> ci;
  int c = stoi(ci);
  infile.close();
  int ans;
  if (((a >= b) && (b >= c)) || ((b >= a) && (a >= c))) {
      ans = a + b;
  } else if (((a >= c) && (c >= b)) || ((c >= a) && (a >= b))) {
      ans = a + c;
  } else if (((b >= c) && (c >= a)) || ((c >= b) && (b >= a))) {
      ans = b + c;
  }
  ofstream outfile;
  outfile.open("salesout.txt");
  string finaloutput = to_string(ans);
  outfile << finaloutput;
  outfile.close();
}
