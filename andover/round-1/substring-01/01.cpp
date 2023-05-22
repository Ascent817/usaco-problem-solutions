#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;

  while (s.find("01") != string::npos) {
    s.replace(s.find("01"), 2, "");
  }

  cout << s.length() << endl;
  cout << s << endl;
}