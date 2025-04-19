#include <iostream>
#include <thread>
#include "logger.hpp"

using namespace std;

void User1() {
    Logger* logger1 = Logger::get_Logger();
    logger1->Log("this message is from user 1");
}

void User2() {
    Logger* logger2 = Logger::get_Logger();
    logger2->Log("this message is from user 2");
}
int main() {

    thread t1(User1);
    thread t2(User2);

    t1.join();
    t2.join();

    return 0;
}
