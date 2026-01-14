//思路：套用归并排序的模板
#include<iostream>
using namespace std;
int n;
int a[100010];
int tmp[100010];
int count; //计数器
long long fun(int l, int r){
    //设立终止条件(函数类型为long long，输出整数)
    if(l >= r) return 0;
    //彻底二分
    int mid = (l + r) / 2;
    //原数组逆序对数量=两个二分数组各自的逆序对之和+两个二分数组之间的逆序对数量
    long long ans = fun(l, mid) + fun(mid+1, r);
    //双指针治(治的就是当前的[l,r]区间，但是有关键参数mid)
    int i = l; //左指针
    int j = mid + 1; //右指针
    int k = l; //给tmp赋值的指针，位置和a数组同步(方便处理)
    while(i <= mid && j <= r){
        if(a[i] <= a[j]){
            tmp[k++] = a[i++];
        }
        else{
            tmp[k++] = a[j++];
            //递归是先传递后回归，回归的都是已经排序好的数组(正是我们使用双指针遍历的这两个数组[l,mid]和[mid+1,r])
            //*单个元素也算排序好的数组
            //现在是对2个二分数组继续排序、继续回归到上一个节点
            //我们在排序时操作的是tmp数组，a数组完全没改动，因此操作和判断是独立的(且i和j指针会遍历完[l,r]之间的所有元素，不用担心遗漏)
            //该分支是a[i] > a[j]的情况，且i天然小于j，正是逆序对的定义
            //由于二分数组都已排序好，当a[i]>a[j]时，[i,mid]间的(mid-i+1)个元素都必然和a[j]形成逆序对
            //要知道此时判断完会j++，不会再看a[j]元素，为了不遗漏a[i+1]~a[mid]和a[j]形成的逆序对，需要对ans自增
            ans += mid - i + 1;
        }
    }
    while(i <= mid){
        tmp[k++] = a[i++];
    }
    while(j <= r){
        tmp[k++] = a[j++];
    }
    for(int i = l; i <= r; i++){
        a[i] = tmp[i];
    }
    return ans;
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << fun(0, n-1) << endl;
}