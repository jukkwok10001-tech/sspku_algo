#include<iostream>
using namespace std;
int gcd(int a, int b){
    int r = max(a, b) % min(a, b);
    if(r != 0){
        return gcd(min(a, b), r);
    }
    else{
        return min(a, b);
    }
}
int main(){
    int a, b;
    cin >> a >> b;
    int gcd_value = gcd(a, b);
    cout << gcd_value;
}