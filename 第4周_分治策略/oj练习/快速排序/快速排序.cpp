//同样的排序问题，这次使用快速排序解决
#include<iostream>
using namespace std;
int n;
int a[100010];
void QuickSort(int l, int r){
    //1.终止条件

    //2.分(根据元素值划分并递归)

    //3.治(排序方式)

}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    QuickSort(0, n-1);
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
}