#include<iostream>
#include<cmath>
using namespace std;
//定义一个判断质数的布尔型函数
//使用函数的好处在于符合对应条件后，会直接跳出函数体返回return后面的值
bool prime(int a){
    if(a == 2) return true;
    if(a == 3) return true;
    //判断一个数是否为质数，只需遍历2至开方值能否被整除
    //sqrt()是cmath头文件的内置开平方函数
    double k = sqrt(a);
    for(int i = 2; i <= k; i++){
        if(a % i == 0) return false;
    }
    //只有不是2或3，且在2-k的遍历中不存在整除情形的a才能安全抵达下一步的return true
    return true;
}
int main(){
    int m;
    cin >> m;
    if(prime(m)){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}