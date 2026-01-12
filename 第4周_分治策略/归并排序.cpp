//问题：输入n个数并对其排序
//方法：分治策略
#include<iostream>
using namespace std;
int a[100010];
int tmp[100010];
//定义归并排序函数MergeSort
//定义参数l和r，分别指代需要排序的数组的首尾索引
void MergeSort(int l, int r){
    //设立边界条件(由于int取整，所以输入的l小于r时，边界条件为l = r；l > r只是输入可能存在的问题)
    if(l >= r) return ;
    //注意：int代表了取整。l=1、r=3时，mid=2；l=1、r=4时，mid=int(2.5)=2
    int mid = (l + r) / 2;
    //分
    MergeSort(l, mid);
    MergeSort(mid+1, r);
    //治
    int i = l; //定义左指针i
    int j = mid+1; //定义右指针j
    int k = l; //定义临时数组tmp的赋值指针k
    while(i <= mid && j <= r){
        if(a[i] < a[j]){
            tmp[k] = a[i];
            i++; k++;
            //也可写成tmp[k++]=a[i++]
        }
        else{
            tmp[k] = a[j];
            j++; k++;
        }
    }
    while(i <= mid){
        tmp[k] = a[i];
        i++; k++;
    }
    while(j <= r){
        tmp[k] = a[j];
        j++; k++;
    }
    //tmp索引的范围是[l, r]
    //我们正在处理的也是原数组中索引从l至r的[l,mid]和[mid+1,r]两个子数组的归并排序问题
    //应该将tmp的排序结果赋值给a[]锁定修改操作，递归地回溯至下一个子问题的求解
    for(int i = l; i <= r; i++){
        a[i] = tmp[i];
    }
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    MergeSort(0, n-1);
    for(int i = 0; i < n; i++){
        cout << a[i] << " " ;
    }
}