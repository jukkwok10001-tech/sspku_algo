#include<iostream>
using namespace std;
//巧用双指针解决(既可编写算法函数，也可放在主函数中)
//对于执行操作而不返回结果的函数，使用void类型(主函数main类型为int，返回结果为0(正常)或1(异常))
//形参a[]即使标明了元素个数也不生效，数组形参实际上传入的是一个指向首个元素的指针
//也不需要&，指针提供了地址，函数操作就是对数组实参操作
void moveZeroes(int a[], int n){
    //定义慢指针l，快指针r
    //用快指针遍历，慢指针后发
    int l = 0;
    for(int r = 0; r < n; r++){
        if(a[r] != 0){
            a[l] = a[r];
            l++;
        }
    }
    if(l < n){
        for(l; l < n; l++){
            a[l] = 0;
        }
    }
}
int main(){
    int n;
    cin >> n;
    int nums[n];
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    //传递数组名实际上是传递数组的首地址(首个元素的地址)
    //函数体通过该地址对数组进行修改操作
    moveZeroes(nums, n);
    for(int i = 0; i < n; i++){
        cout << nums[i] << " ";
    }
}