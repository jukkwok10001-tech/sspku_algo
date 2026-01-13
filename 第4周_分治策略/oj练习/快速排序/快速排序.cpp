//同样的排序问题，这次使用快速排序解决
#include<iostream>
using namespace std;
int n;
int a[100010];
void QuickSort(int l, int r){
    cout << "l = " << l << "  r = " << r << endl;
    if(l >= r){
        return;
    }
    int i = l-1; //定义左指针，初始化为l
    int j = r+1; //定义右指针，初始化为r
    int pivot = a[l]; //定义待排数组第一个元素的值为基准
    while(i < j){
        //只要元素值≤基准值，左指针自增1。i会停在[左起]首个大于基准值的元素
        do i++; while(a[i] <= pivot); 
        //只要元素值>基准值，右指针自减1。j会停在[右起]首个小于等于基准值的元素
        do j--; while(a[j] > pivot);
        if(i < j){
            swap(a[i], a[j]);
        }
    }
    QuickSort(l,j);
    QuickSort(j+1,r);
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