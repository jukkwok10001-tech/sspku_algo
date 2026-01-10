#include<iostream>
using namespace std;
//由于int最多只能存储2147483648，所以要用long long类型才可以
long long fibonacci(int n){
    if(n == 1) return 1;
    else if(n == 2) return 1;
    else return fibonacci(n - 1) + fibonacci(n - 2);
}
int main(){
    int n;
    cin >> n;
    cout << fibonacci(n) << endl;
}