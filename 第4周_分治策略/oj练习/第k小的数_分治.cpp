#include<iostream>
using namespace std;
int n;
int k;
int a[100010];
int tmp[100010];
void fun(int l, int r){
    //设置终止条件
    if(l >= r) return;
    //无限二分
    int mid = (l + r) / 2;
    fun(l, mid);
    fun(mid+1, r);
    //治理
    int i = l; //定义左指针
    int j = mid+1; //定义右指针
    int k = l; //定义赋值指针
    while(i <= mid && j <= r){
        if(a[i] < a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++];
    }
    while(i <= mid) tmp[k++] = a[i++];
    while(j <= r) tmp[k++] = a[j++];
    for(int i = l; i <= r; i++) a[i] = tmp[i];
}
int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    fun(0, n-1);
    cout << a[k-1] << endl;
}