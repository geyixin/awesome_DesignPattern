/*
 * @Author: Eashin
 * @Date: 2020-04-02 22:37:00
 * @LastEditTime: 2020-04-02 23:07:19
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /creational-models/abstractFactory.cpp
 */

#include <iostream>

using namespace std;

/**
 * @description: 抽象类：猫
 * @return: None
 */
class Cat {
public:
    virtual void getName() = 0;
};

/**
 * @description: 抽象类：狗
 * @return: None
 */
class Dog {
public:
    virtual void getName() = 0;
};

/**
 * @description: 具体类：中国 猫咪
 */
class ChineseCat : public Cat {
public:
    void getName() {
        cout << "中国猫咪。" << endl;
    }
};

/**
 * @description: 具体类：中国 狗狗
 */
class ChineseDog : public Dog {
public:
    void getName() {
        cout << "中国狗狗。" << endl;
    }
};

/**
 * @description: 具体类：美国 猫咪
 */
class USACat : public Cat {
public:
    void getName() {
        cout << "美国猫咪。" << endl;
    }
};

/**
 * @description: 具体类：美国 狗狗
 */
class USADog : public Dog {
public:
    void getName() {
        cout << "美国狗狗。" << endl;
    }
};

/**
 * @description: 抽象工厂
 * @return: 猫 或者 狗
 */
class AbstractFactory {
public:
    virtual Cat * createCat() = 0;
    virtual Dog * createDog() = 0;
};

/**
 * @description: 具体工厂：中国 工厂
 */
class ChineseFactory : public AbstractFactory {
public:
    virtual Cat * createCat() {
        return new ChineseCat;
    }
    virtual Dog * createDog() {
        return new ChineseDog;
    }
}; 

/**
 * @description: 具体工厂：美国 工厂
 */
class USAFactory : public AbstractFactory {
public:  
    virtual Cat * createCat() {
        return new USACat;
    }
    virtual Dog * createDog() {
        return new USADog;
    }
};

int main() {
    Cat * cat = NULL;
    Dog * dog = NULL;

    AbstractFactory * abf = NULL;

    abf = new ChineseFactory;

    cat = abf->createCat();
    dog = abf->createDog();

    cat->getName(); // 中国猫咪。
    dog->getName(); // 中国狗狗。

    delete cat;
    delete dog;
    delete abf;

    return 0;
}