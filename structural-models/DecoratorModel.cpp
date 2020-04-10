/*
 * @Author: Eashin
 * @Date: 2020-04-10 21:25:43
 * @LastEditors: Eashin
 * @LastEditTime: 2020-04-11 00:14:45
 * @Description: 
 * @FilePath: /structural-models/DecoratorModel.cpp
 */

#include <iostream>

using namespace std;

// 抽象构件
class Cat {
public:
    virtual void show() = 0;
};

// 具体构件：大橘
class Daju : public Cat {
public:
    Daju (int age) {
        this->age = age;
    }
    void show() {
        cout << "大橘: " << to_string(this->age) << "岁. ";
    }
private:
    int age;
};

// 具体构件：缅甸大猫
class Mddm : public Cat {
public:
    Mddm (int age) {
        this->age = age;
    }
    void show() {
        cout << "缅甸大猫: " << to_string(this->age) << "岁. ";
    }
private:
    int age;
};

// 抽象装饰器
class AbstractDecorator : public Cat {
public:
    AbstractDecorator() {}   // 默认构造函数需显式写出，否则 DecoratorCatJacket 中构造函数会出问题。
    AbstractDecorator(Cat* cat) {
        this->cat = cat;
    }
    void show() {
        this->cat->show();
    }
private:
    Cat* cat;   // 关键点
};

// 具体的装饰器：Jacket装饰器
class DecoratorCatJacket : public AbstractDecorator {
public:
    DecoratorCatJacket(Cat* cat) {
        this->cat = cat;
    }
    void show() {
        this->cat->show();
        addJacket();
    }
    void addJacket() {
        cout << "Wear jacket. ";
    }
private:
    Cat* cat;
};

// 具体的装饰器：Shoes装饰器
class DecoratorCatShoes : public AbstractDecorator {
public:
    DecoratorCatShoes(Cat* cat) {
        this->cat = cat;
    }
    void show() {
        this->cat->show();
        addShoes();
    }
    void addShoes() {
        cout << "Add shoes. ";
    }
private:
    Cat* cat;
};

int main() {
    Cat* cat = NULL;
    AbstractDecorator* addJacket = NULL;
    AbstractDecorator* addShoes = NULL;
    AbstractDecorator* addJacketAndShoes = NULL;

    cat = new Daju(10); // 大橘10岁
    addJacket = new DecoratorCatJacket(cat); // 给大橘穿个夹克
    addJacketAndShoes = new DecoratorCatShoes(addJacket); // 给穿了夹克的大橘再穿个鞋子
    addJacketAndShoes->show();  // 大橘: 10岁. Wear jacket. Add shoes. 

    cout << endl;

    cat = new Mddm(2);
    addShoes = new DecoratorCatShoes(cat);
    addJacketAndShoes = new DecoratorCatJacket(addShoes);
    addJacketAndShoes->show();  // 缅甸大猫: 2岁. Add shoes. Wear jacket. 

    return 0;
}