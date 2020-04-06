/*
 * @Author: Eashin
 * @Date: 2020-04-05 21:52:15
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /creational-models/SingletonModel.cpp
 */

#include <iostream>
#include <mutex>

using namespace std;


// 懒汉模式 版本 1 :【缺陷：线程安全】
class Singleton_lazy_man {
private:
    Singleton_lazy_man () {
        instance = NULL;
        cout << "Singleton_lazy_man In use." << endl;
    }
    static Singleton_lazy_man* instance;
public:
    static Singleton_lazy_man * getInstance() {
        if (!instance) {
            instance = new Singleton_lazy_man;
        }
        return instance;
    }
};

Singleton_lazy_man* Singleton_lazy_man::instance = NULL;    // 静态变量初始化，放类外


// 懒汉模式 版本 2 :【双重锁定：未被创建时再加锁】

class Singleton_lazy_man_2 {
private:
    Singleton_lazy_man_2 () {
        instance = NULL;
        cout << "Singleton_lazy_man_2 In use." << endl;
    }
    static Singleton_lazy_man_2* instance;
    static mutex mu;
public:
    static Singleton_lazy_man_2 * getInstance() {
        if (!instance) {
            lock_guard<mutex> lock(mu);
            if (!instance) {
                instance = new Singleton_lazy_man_2;
            }
        }
        return instance;
    }
};

Singleton_lazy_man_2* Singleton_lazy_man_2::instance = NULL;
mutex Singleton_lazy_man_2::mu;


// 饿汉模式 版本 1

class Singleton_hungry_man {
private:
    Singleton_hungry_man () {
        instance = NULL;
        cout << "Singleton_hungry_man In use." << endl;
    }
    static Singleton_hungry_man* instance;
public:
    static Singleton_hungry_man * getInstance() {
        return instance;
    }
};

Singleton_hungry_man* Singleton_hungry_man::instance  = new Singleton_hungry_man;   // 声明的时候就创建

// 饿汉模式 版本 2【局部静态变量】

class Singleton_hungry_man_2 {
private:
    Singleton_hungry_man_2 () {
        cout << "Singleton_hungry_man_2 In use." << endl;
    }
public:
    static Singleton_hungry_man_2& getInstance() {
        static Singleton_hungry_man_2 instance;
        return instance;
    }
};


int main() {
    Singleton_lazy_man* instance_1_1 = Singleton_lazy_man::getInstance();
    Singleton_lazy_man* instance_1_2 = Singleton_lazy_man::getInstance();
    if (instance_1_1 == instance_1_2) cout << "Singleton_lazy_man 一样的" << endl;

    Singleton_lazy_man_2* instance_2_1 = Singleton_lazy_man_2::getInstance();
    Singleton_lazy_man_2* instance_2_2 = Singleton_lazy_man_2::getInstance();
    if (instance_2_1 == instance_2_2) cout << "Singleton_lazy_man_2 一样" << endl;

    Singleton_hungry_man* instance_h_1 = Singleton_hungry_man::getInstance();
    Singleton_hungry_man* instance_h_2 = Singleton_hungry_man::getInstance();
    if (instance_h_1 == instance_h_2) cout << "Singleton_hungry_man 一样" << endl;
    
    Singleton_hungry_man_2& instance_h2_1 = Singleton_hungry_man_2::getInstance();
    Singleton_hungry_man_2& instance_h2_2 = Singleton_hungry_man_2::getInstance();


    /* 
    输出结果：(注意 Singleton_hungry_man 第一个输出)
    Singleton_hungry_man In use.
    Singleton_lazy_man In use.
    Singleton_lazy_man 一样的
    Singleton_lazy_man_2 In use.
    Singleton_lazy_man_2 一样
    Singleton_hungry_man 一样
    Singleton_hungry_man_2 In use.
    */

    return 0;
}
