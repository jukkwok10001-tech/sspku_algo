//之前是先排序再取数，只在排序上应用了分治策略
//现在尝试在排序的同时完成取数
//这里套用快速排序的模板
#include<iostream>
using namespace std;
int n, k;
int a[100010];
int fun(int l, int r, int m){
    //定义终止条件
    //分到最后必然是单个元素构成数组，返回的也是第1小的值，即a[l]
    if(l >= r) return a[l]; //a[l]就是最终结果
    int pivot = a[l]; //选定首个元素充当基准值
    //快速排序的分法是基于基准值的分类
    int i = l-1; //定义左指针(配合do-while的指针先行)
    int j = r+1; //定义右指针(配合do-while的指针先行)
    while(i < j){
        do i++; while(a[i] < pivot);
        do j--; while(a[j] > pivot);
        if(i < j) swap(a[i], a[j]);
    }
    //无限二分
    //但是要有取舍，并非每个分支我们都去递归
    //要找第m小的数，若左侧数组元素个数<m，说明第m小的数必定在右侧数组
    //*左侧包含的元素都是小于pivot的元素，就是最小的若干元素的集合，其长度和m本质相同，有可比性
    if(j-l+1 >= m)
        return fun(l, j, m); //左分支，此时仍然是找第m小的元素
        //必须要有return返回，因为是int类型，要返回值，仅有开头的不够，这里return才能传递下去
        //void类型则不用返回值，只是原地操作
    else
        return fun(j+1, r, m-(j-l+1)); //右分支，此时m发生改变，找第m-(j-l+1)个元素(左边元素个数为j-l+1)
}
int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << fun(0, n-1, k) << endl;
}