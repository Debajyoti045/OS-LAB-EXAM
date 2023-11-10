#include <bits/stdc++.h>
using namespace std;

int main()
{

  cout << "parent process" << endl;
  fork();
  cout << "child process" << endl;
  return 0;
}