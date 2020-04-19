/*
 * @Author: Eashin
 * @Date: 2020-04-19 16:05:50
 * @LastEditors: Eashin
 * @Description: 
 * @FilePath: /behavioral-models/commandModel.cpp
 */


#include <iostream>
#include <vector>

using namespace std;

// 类：烧烤师傅
class Barbecuer {
public:
    void BakeMutton() {
        cout << "烤羊肉串。" << endl;
    }
    void BakeVegetables() {
        cout << "烤蔬菜。" << endl;
    }
};

// 抽象命令
class Command {
public:
    Command(Barbecuer* bar) {
        this->barbecuer = bar;
    }
    virtual void ExcuteCommand() = 0;
protected:
    Barbecuer* barbecuer;
};

// 具体命令：烤羊肉串
class CommandBakeMutton : public Command {
public:
    CommandBakeMutton(Barbecuer* barbecuer) : Command(barbecuer) {}

    void ExcuteCommand() {
        barbecuer->BakeMutton();
    }
};

// 具体命令：烤蔬菜
class CommandBakeVegetables : public Command {
public:
    CommandBakeVegetables(Barbecuer* barbecuer) : Command(barbecuer) {}

    void ExcuteCommand() {
        barbecuer->BakeVegetables();
    }
};

// 服务员：收集命令，下发给 烧烤师傅
class Waiter {
public:
    Waiter(Command* comm) {
        this->command = comm;
    }
    void Notify() {
        command->ExcuteCommand();
    }
private:
    Command* command;
};

// 收银台：收集服务员收集的命令，下发给 烧烤师傅【相比于Waiter，它可以一次性下发很多订单給烧烤师傅】
class Casher {
public:
    Casher() { 
        bake_comm_list.clear(); 
    }

    void add_comm(Command* comm) {
        bake_comm_list.push_back(comm);
    }
    
    void Notify() {
        for(auto ele : bake_comm_list) {
            ele->ExcuteCommand();
        }
    }

private:
    vector<Command*> bake_comm_list;
};

int main() {
    Barbecuer* bar = new Barbecuer;
    Command *c1 = new CommandBakeMutton(bar);
    Command *c2 = new CommandBakeVegetables(bar);
    Command *c3 = new CommandBakeVegetables(bar);

    Casher *casher = new Casher;
    casher->add_comm(c1);
    casher->add_comm(c2);
    casher->add_comm(c3);
    casher->Notify();
    /*
    烤羊肉串。
    烤蔬菜。
    烤蔬菜。
    */

    Waiter * waiter = new Waiter(c1);
    waiter->Notify();
    /*
    烤羊肉串。
    */

    return 0;
}