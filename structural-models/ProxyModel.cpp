/*
 * @Author: Eashin
 * @Date: 2020-04-08 17:11:15
 * @LastEditors: Eashin
 * @Description: 
 * @FilePath: /structural-models/ProxyModel.cpp
 */

#include <iostream>

using namespace std;

class Cat {
public:
    Cat (string name) {
        this->name = name;
    }
    string getName() {
        return this->name;
    }
private:
    string name;
};

// subject
class Shopping {
public:
    virtual void buy(Cat cat) = 0;
};

// real subject
class DajuShopping : public Shopping {
public:
    void buy(Cat cat) {
        cout << "购买了中国的" << cat.getName() << endl;
    }
};

// real subject
class MddmShopping : public Shopping {
public:
    void buy(Cat cat) {
        cout << "购买了缅甸的" << cat.getName() << endl;
    }
};

// proxy
class ProxyShopping : public Shopping {
public:
    ProxyShopping(Shopping* shop) {
        this->shopping = shop;
    }
    void buy(Cat cat) {
        this->shopping->buy(cat);
        if (cat.getName() == "大橘") cout << "大橘很胖" << endl;
        if (cat.getName() == "缅甸大猫") cout << "缅甸大猫很大" << endl;

    }
private:
    Shopping* shopping;
};

int main() {
    Cat cat1("大橘");
    Cat cat2("缅甸大猫");
    ProxyShopping * proxy = new ProxyShopping(new DajuShopping);
    proxy->buy(cat1);

    ProxyShopping * proxy2 = new ProxyShopping(new MddmShopping);
    proxy2->buy(cat2);

    return 0;
}