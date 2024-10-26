#include <iostream>
#include <thread>
#include <atomic>
#include <vector>

using namespace std;
void increment(int n, atomic<int>& counter)
{
    for (size_t i = 0; i < n; i++)
    {
        counter++; // 由于counter是原子操作，不需要加锁
    }
}

int main(int argc, char const *argv[])
{
    atomic<int> a( 0 ); // 原子操作,不会出现线程安全问题
    a++; // 支持原子操作
    int val = a.load(); // 读取原子操作的值
    a.store(10); // 储存
    atomic<int> counter(0);
    vector<thread> threads;
    for (size_t i = 0; i < 5; i++)
    {
        threads.emplace_back(increment,100000,ref(counter));
    }
    for(auto & _thread : threads)
    {
        _thread.join();
    }
    cout << counter << endl;
    return 0;


}
