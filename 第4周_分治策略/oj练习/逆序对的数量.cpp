//采用分治的思路
//附上草稿
//以[9,7,8,3,2]为例，按照归并的l、r、mid参数进行划分
//(0,4)→(0,2)+(3,4)
//  (0,2)→(0,1)+(1,2)
//      (0,1)→(0,0)+(1,1) return 空
//      *触发边界条件会回溯至(0,1)节点，这里的l=0、r=1，还有我们定义的mid=0
//      *我们要做的就是比较[l,mid]和[mid+1,r]，使用双指针遍历即可
//      *之后同理
//      (1,2)→(1,1)+(2,2) return 空
//  (3,4)→(3,3)+(4,4) return 空 
//思路：先分再治。
//(1)分：不断二分区间直至区间仅含1个元素
//(2)治：两重for循环遍历比较[l,mid]和[mid+1,r]，符合逆序定义计数器自增1
#include<iostream>
using namespace std;
int n;
int count;
int a[1000010];
void fun(int l, int r){
    //注意！一定要有终止条件，否则将无限递归
    if(l >= r) return;
    int mid = (l + r) / 2;
    //以下这两步其实就是将原数组彻底地二分至只包含单个元素的数组的集合
    fun(l,mid);
    fun(mid+1,r);
    //"分"完就可以回溯地开始"治"了
    //要"治"的就是fun(l,r)中的实参取值和mid划分成的两数组
    for(int i = l; i <= mid; i++){
        for(int j = mid+1; j <= r; j++){
            if(a[i] > a[j]) count +=1;
        }
    }
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    fun(0, n-1);
    cout << count;
}