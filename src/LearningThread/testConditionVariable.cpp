#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
using namespace std;
void foo(mutex &mtx, bool &flag, condition_variable &cv) {
    unique_lock<mutex> ulk(mtx);

    while (!flag) {
        cv.wait(ulk);
    }
    std::cout << this_thread::get_id() << std::endl;
}

void updateFlag(mutex &mtx, bool &flag, condition_variable &cv) {
    unique_lock<mutex> ulk(mtx);
    flag = !flag;
    cv.notify_all();
}

int main(int argc, char const *argv[]) {
    mutex mtx;
    condition_variable cv;
    bool flag = false;
    vector<thread> threads;

    for (size_t i = 0; i < 10; i++) {
        threads.emplace_back(foo, ref(mtx),ref(flag), ref(cv));
    }

    updateFlag(mtx,flag,cv);

    for(thread& _thread : threads)
    {
        _thread.join();
    }

    return 0;
}
