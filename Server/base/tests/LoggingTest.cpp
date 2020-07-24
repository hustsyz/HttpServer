 
#include "../Logging.h"
#include "../Thread.h"
#include <string>
#include <unistd.h>
#include <vector>
#include <memory>
#include <iostream>
using namespace std;

void threadFunc()
{
    for (int i = 0; i < 100000; ++i)
    {
        LOG << i;
    }
}

void type_test()
{
    // 13 lines
    cout << "----------type test-----------" << endl;
    cout << __FILE__ << __LINE__ << endl;
    LOG << 0;
    cout << __FILE__ << __LINE__ << endl;
    LOG << 1234567890123;
    cout << __FILE__ << __LINE__ << endl;
    LOG << 1.0f;
    cout << __FILE__ << __LINE__ << endl;
    LOG << 3.1415926;
    cout << __FILE__ << __LINE__ << endl;
    LOG << (short) 1;
    cout << __FILE__ << __LINE__ << endl;
    LOG << (long long) 1;
    cout << __FILE__ << __LINE__ << endl;
    LOG << (unsigned int) 1;
    cout << __FILE__ << __LINE__ << endl;
    LOG << (unsigned long) 1;
    cout << __FILE__ << __LINE__ << endl;
    LOG << (long double) 1.6555556;
    cout << __FILE__ << __LINE__ << endl;
    LOG << (unsigned long long) 1;
    cout << __FILE__ << __LINE__ << endl;
    LOG << 'c';
    cout << __FILE__ << __LINE__ << endl;
    LOG << "abcdefg";
    cout << __FILE__ << __LINE__ << endl;
    LOG << string("This is a string");
    cout << __FILE__ << __LINE__ << endl;
}

void stressing_single_thread()
{
    // 100000 lines
    cout << "----------stressing test single thread-----------" << endl;
    for (int i = 0; i < 100000; ++i)
    {
        LOG << i;
    }
}

void stressing_multi_threads(int threadNum = 4)
{
    // threadNum * 100000 lines
    cout << "----------stressing test multi thread-----------" << endl;
    vector<shared_ptr<Thread>> vsp;
    for (int i = 0; i < threadNum; ++i)
    {
        shared_ptr<Thread> tmp(new Thread(threadFunc, "testFunc"));
        vsp.push_back(tmp);
    }
    for (int i = 0; i < threadNum; ++i)
    {
        vsp[i]->start();
    }
    sleep(3);
}

void other()
{
    // 1 line
    cout << "----------other test-----------" << endl;
    LOG << "fddsa" << 'c' << 0 << 3.666 << string("This is a string");
}

//cout << __FILE << __LINE__ << endl;
int main()
{
    // 共500014行
    type_test();
    sleep(3);

    stressing_single_thread();
    sleep(3);

    other();
    sleep(3);

    stressing_multi_threads();
    sleep(3);
    return 0;
}