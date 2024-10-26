#include <iostream>
#include <mutex>
#include <random>
#include <shared_mutex>
#include <thread>
#include <vector>
/**
 * @brief 模拟读者线程
 * 
 * @param rw_mutex 
 * @param shared_data 
 */
void reader(std::shared_mutex &rw_mutex, int &shared_data) {
    std::shared_lock shareLock(rw_mutex); // 读锁，这是一个共享锁
    // 读线程之间可以并发执行
    std::cout << "[Reader Thread] " << std::this_thread::get_id()
              << "Read the data: " << shared_data << std::endl;
}

/**
 * @brief 模拟写者线程
 * 
 * @param rw_mutex 
 * @param shared_data 
 * @param data_to_write 
 */
void writer(std::shared_mutex &rw_mutex, int &shared_data, int data_to_write) {
    std::unique_lock uniLock(rw_mutex); // 写锁，这是一个独占锁
    // 写线程之间不能并发执行
    shared_data = data_to_write;
    std::cout << "[Writer Thread] " << std::this_thread::get_id()
              << "Write the data: " << shared_data << std::endl;
}

int main(int argc, char const *argv[]) {
    std::vector<std::thread> threads;
    std::shared_mutex rw_mutex;
    int shared_data = 0;

    threads.emplace_back(writer, std::ref(rw_mutex), std::ref(shared_data),rand());
    threads.emplace_back(writer, std::ref(rw_mutex), std::ref(shared_data),rand());

    
    for (size_t i = 0; i < 5; i++)
    {
        threads.emplace_back(reader,std::ref(rw_mutex), std::ref(shared_data));
    }
    
    for(auto & thread : threads)
    {
        thread.join();
    }   
    return 0;
}
