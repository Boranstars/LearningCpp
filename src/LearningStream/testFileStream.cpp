#include <ctime>
#include <fstream>
#include <iostream>
#include <ostream>
#include <chrono>
int main(int argc, const char** argv) {
    
    std::fstream file("./test.txt",std::ios::in | std::ios::out | std::ios::app);
    if (file.is_open()) {
        file << "---------------------------------\n";
        file << "hello\n";
        file << "argc: " << argc << std::endl;
        file << "argv: [";
        for (size_t i = 0; i < argc; i++)
        {
            file << argv[i] << "," ;
        }
        file << "]"<< std::endl;
        auto time = std::chrono::system_clock::now();
        auto nowTime = std::chrono::system_clock::to_time_t(time);
        file << std::ctime(&nowTime) << std::endl;
    }
    file.close();
    std::ifstream infile("./test.txt");
    std::cout << infile.rdbuf();
    return 0;
}

