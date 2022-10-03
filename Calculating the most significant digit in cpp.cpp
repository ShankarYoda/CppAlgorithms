#include <bits/stdc++.h>

using namespace std;

 

int MSD(int n){

      if(n == 0)

        return 0;

      int k = log10(n);

    int x = pow(10,k);

    int ans = n/x;

      return ans;

}

 

int main() {

    int n;

    cin >> n;

    cout << MSD(n) << endl;

    return 0;

}
