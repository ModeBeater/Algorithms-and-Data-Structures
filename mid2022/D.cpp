#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 1){
        cout << 0 << endl;
    }
    else {
        int i = 2;
        int cnt = 0;
        while (n > 1) {
            if (n % i == 0) {
                while (n % i == 0) {
                    n = n / i;
                }
                cnt++;
            } 
            i++;
        }
        cout << cnt << endl;
    }
  
}