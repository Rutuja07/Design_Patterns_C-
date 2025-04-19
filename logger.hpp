#include <string>
#include <mutex>
using namespace std;

class Logger {
    static int counter;
    static Logger *logger_instance;
    static mutex mtx;
    Logger();
    Logger(const Logger&);
    Logger operator = (const Logger &);

    public:
     static Logger *get_Logger();
     void Log(string msg);
};
