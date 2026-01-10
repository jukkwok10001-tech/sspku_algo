#include<iostream>
#include<vector> //vector头文件，可以引入动态数组方便操作
using namespace std;
//定义一个原地操作函数
//删去首个元素，并将第二个元素传至末尾
void mod(vector<int>& a){
    if(a.size() > 1){
        //删除首个元素
        a.erase(a.begin());
        //将此时的首个元素追加至末尾
        a.push_back(a[0]);
        //删掉此时的首个元素
        a.erase(a.begin());
    }
    //当数组a只有一个元素时，删去首个元素，数组变空值，继续追加索引会越界
    //因此需要额外处理，这里的函数返回空值即可
    else{
        return ; //或者不写else语句也可以
    }
}
int main(){
    int n;
    cin >> n;
    //这里不事先约定数组长度为n(即a(n))，使用push_back追加输入
    //这样的好处是数组长度可以动态调整，并通过size()函数调用
    vector<int> a;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        a.push_back(num);
    }
    vector<int> b;
    if(a.size() == 1) cout << a[0];
    else{
        while(a.size() > 1){
            b.push_back(a[0]);
            mod(a);
        }
        //数组a长度变成1后会跳出循环，此时追加最后一个元素即可
        b.push_back(a[0]); 
        //这里上界必须使用b.size()，防止越界访问报错(例如数组长度为n，却要访问n+1个元素)
        for(int i = 0; i < b.size(); i++){
            cout << b[i] << " ";
        }
    } 
}