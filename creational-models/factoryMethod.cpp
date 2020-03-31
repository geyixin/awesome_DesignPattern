/*
 * @Author: Eashin
 * @Date: 2020-03-31 19:50:06
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /creational-models/factoryMethod.cpp
 */

#include <iostream>

using namespace std;

/**
 * @description: 猫咪抽象类
 * @param {type} 
 * @return: 
 */
class Cat {
public:
    virtual void getName() = 0;
};

//---------------------------

/**
 * @description: 工厂抽象类
 * @param {type} 
 * @return: 
 */
class AbstractFacotry {
public:
    virtual Cat * createCat() = 0;
};

//---------------------------

/**
 * @description: 产品：大橘猫
 * @param {type} 
 * @return: 
 */
class Daju : public Cat {
public:
    virtual void getName() {
        cout << "我是大橘。" << endl;
    }
};

/**
 * @description: 产品：波斯猫
 * @param {type} 
 * @return: 
 */
class Bosi : public Cat {
public:
    virtual void getName() {
        cout << "我是波斯。" << endl;
    }
};

/**
 * @description: 产品：缅甸大猫
 * @param {type} 
 * @return: 
 */
class Mddm : public Cat {
public:
    virtual void getName() {
        cout << "我是缅甸大猫。" << endl;
    }
};

//---------------------------

/**
 * @description: 大橘工厂
 * @param {type} 
 * @return: 
 */
class DajuFactory : public AbstractFacotry {
public:
    virtual Cat * createCat() {
        return new Daju;
    }
 };

 /**
 * @description: 波斯猫工厂
 * @param {type} 
 * @return: 
 */
class BosiFactory : public AbstractFacotry {
public:
    virtual Cat * createCat() {
        return new Bosi;
    }
 };

 /**
 * @description: 缅甸大猫工厂
 * @param {type} 
 * @return: 
 */
class MddmFactory : public AbstractFacotry {
public:
    virtual Cat *createCat() {
        return new Mddm;
    }
 };


int main() {
    // 现在只要对接口编程。 
    AbstractFacotry *abf = NULL;
    Cat *cat = NULL;

    // 利用多态，完成具体产品的生产
    abf = new DajuFactory;
    cat = abf->createCat();
    cat->getName(); // 我是大橘。
 }