#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main()
{
    std::vector<int> c = {1, 2, 3, 4, 5, 6, 7};
    int x = 5;
    c.erase(std::remove_if(c.begin(), c.end(), [&,x](int n)mutable->bool { return n < x; }), c.end());
 
    std::cout << "c: ";
    std::for_each(c.begin(), c.end(), [](int i){ std::cout << i << ' '; });
    std::cout << '\n';
 
    // 闭包的类型不能被指名，但可用 auto 提及
    // C++14 起，lambda 能拥有自身的默认实参
    auto func1 = [](int i = 6) { return i + 4; };
    std::cout << "func1: " << func1() << '\n';
 
    // 与所有可调用对象相同，闭包能可以被捕获到 std::function 之中
    // （这可能带来不必要的开销）
    std::function<int(int)> func2 = [](int i) mutable ->int { return i + 4; };
    std::cout << "func2: " << func2(6) << '\n';


    unordered_map<string,int>table;
    table["Monday"] = 1;
    string m = "ABC";
    cout<<endl<<(m=="ABC");
    cout<<endl;
    vector<int>vec(10);
    for(int i = 0 ; i < 10 ; i ++  )
    {
        vec[i] = i;
    }
    cout<<vec.size()<<endl;
    vector<int >::iterator iter1 = vec.begin() ;
    for(; iter1 != vec.end() ; iter1++)
    {
        if((*iter1) == 0)
        {
            iter1 = vec.erase(iter1);
            break;
        }
    }
    cout<<*iter1<<endl;
    for(vector<int >::iterator iter = vec.begin() ; iter != vec.end() ; iter++)
    {
        cout<<*iter<<" ";
    }
    cout<<endl<<vec.size()<<endl;

}
