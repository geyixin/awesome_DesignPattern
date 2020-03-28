/*
 * @Author: Eashin
 * @Date: 2020-03-28 16:24:27
 * @LastEditTime: 2020-03-28 20:26:00
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /DesignPattern/simpleFactory.cpp
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
            printf("我是大橘。");
        }
        else if (name == "bosi"){
            printf("我是波斯猫。")
        }
        else if (name == "mddm"){
            printf("我是缅甸大猫。")
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

