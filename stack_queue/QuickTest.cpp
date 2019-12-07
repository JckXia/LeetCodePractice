// Example program
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int greaterThan(int a,int b){
 return a>b;
}

int main()
{
  vector<int> a={4,123,512,9,0,-42,3};
  sort(a.begin(),a.end(),greaterThan);
  for (auto it = a.begin(); it != a.end(); it++) {
    cout << *it << endl;
}
}
