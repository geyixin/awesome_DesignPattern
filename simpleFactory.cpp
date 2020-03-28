/*
 * @Author: Eashin
 * @Date: 2020-03-28 16:24:27
 * @LastEditTime: 2020-03-28 21:02:52
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /awesomme_DesignPattern/simpleFactory.cpp
 */

#include <iostream>

using namespace std;

// 没使用简单工厂模式
class Cat{
public:
    Cat(string name){
        this->name = name;
        if (name == "daju"){
            // 返回大橘
        }
        else if (name == "bosi"){
            // 返回波斯猫
        }
        else if (name == "mddm"){
            // 返回缅甸大猫
        }
    }

    void getName() {
        if (name == "daju"){
            cout << "我是大橘。" << endl;
        }
        else if (name == "bosi"){
            cout << "我是波斯猫。" << endl;
        }
        else if (name == "mddm"){
            cout << "我是缅甸大猫。" << endl;
        }
    }
private:
    string name;
};

int main(void)
{
    Cat daju = Cat("daju");
    Cat bosi = Cat("bosi");
    Cat mddm = Cat("mddm");
    daju.getName();
    bosi.getName();
    mddm.getName();
    return 0;
}

// 使用 简单工厂模式

/**
 * @description: 定义一个猫咪的抽象类
 * @param {type} 
 * @return: 
 */
class Cat2 {
public:
    virtual void getName() = 0; // 纯虚函数
};

class Daju:Cat2{
public:
    virtual void getName() {
        cout << "我是大橘。" << endl;
    }
}

class Bosi:Cat2{
public:
    virtual void getName() {
        cout << "我是波斯。" << endl;
    }
}

class Mddm:Cat2{
public:
    virtual void getName() {
        cout << "我是缅甸大猫。" << endl;
    }
}

/**
 * @description: 猫咪生产工厂
 * @param {type} 
 * @return: 
 */
class Factory{
public:
    Cat2 * createCat(string name) {
        if (name == "daju"){
            return new Daju;
        }
        eles if (name == "bosi"){
            return new Bosi;
        }
        else if (name == "mddm"){
            return new Mddm;
        }
    }
}

int main(void)
{
    Factory * factory = new Factory;
    Cat2 * cat2 = NULL;
    cat2 = factory->createCat("daju");
    cat2->getName();
    delete cat2;
    cat2 = NULL;

    cat2 = factory->createCat("bosi");
    cat2->getName();
    delete cat2;
    cat2 = NULL;

    cat2 = factory->createCat("mddm");
    cat2->getName();
    delete cat2;
    cat2 = NULL;

    delete factory;
    factory = NULL;
    return 0;
}
