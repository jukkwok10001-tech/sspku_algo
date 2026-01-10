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
//当n较大时，递归运行速度很慢，此时根据递归公式使用for循环(动态规划)效率断崖式提高