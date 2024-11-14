#include <chrono>
#include <iostream>
#include <thread>
#include <future>
#include <vector>
using namespace std;

int getSum(int num,int id)
{
    int userNum = 0;
    cout << "Task: " << id<< "Enter a Number\n";
    cin >> userNum;
    return num + userNum;
}

int main(int argc, const char** argv) {

    // 这相当于一个异步任务，会在新线程中执行。和用thread创建线程不同，这个是异步的，不会阻塞主线程。
    future<int> result = async(getSum, 10, 0); // 默认是launch::async, 会在新线程中执行。
    vector<future<int>> results;
    for (size_t i = 0; i < 10; i++)
    {
        results.push_back(async(getSum, 10, i+1));
    }
    for (size_t i = 0; i < 20; i++)
    {
        std::cout << " Main Thread is Working---" << std::endl;
        this_thread::sleep_for(chrono::milliseconds(200));
    }

    auto rs = result.get(); // 使用get()获取异步任务的结果，这个会阻塞主线程，直到异步任务完成。
    cout << "Result: " << rs << endl;
    for (auto &f : results)
    {
        // rs += f.get();
         std::cout << "result: "<< f.get() << std::endl;
    }
    std::cout << rs << std::endl;
    return 0;
}