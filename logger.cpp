#include <iostream>
#include "logger.hpp"

using namespace std;


// one configuration mananger or logger - scenarios

// let's use logger 
int Logger:: counter = 0;
mutex Logger::mtx;
Logger *Logger::logger_instance = nullptr;
Logger* Logger::get_Logger() {
  if (logger_instance == nullptr) {
      mtx.lock();
      if(logger_instance == nullptr){
        logger_instance = new Logger();
      }
      mtx.unlock();
}
    return logger_instance;
}
Logger::Logger() {
   counter++;
   cout << " New instance created : No of instances" << counter << endl;
}

void Logger :: Log(string msg) {
   cout << msg << endl;
}
