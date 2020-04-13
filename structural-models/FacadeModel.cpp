/*
 * @Author: Eashin
 * @Date: 2020-04-13 22:08:26
 * @LastEditors: Eashin
 * @LastEditTime: 2020-04-13 22:30:29
 * @Description: 
 * @FilePath: /structural-models/FacadeModel.cpp
 */

#include <iostream>

using namespace std;

// 子系统1:电灯
class Light {
public:
    void On() {
        cout << "light on." << endl;
    }
    void Off() {
        cout << "Pad off." << endl;
    }
};

// 子系统2:音响
class VoiceBox {
public:
    void On() {
        cout << "VoiceBox on." << endl;
    }
    void Off() {
        cout << "VoiceBox off." << endl;
    }
};

// 子系统3:投影仪
class Projector {
public:
    void On() {
        cout << "Projector on." << endl;
    }
    void Off() {
        cout << "Projector off." << endl;
    }
};

// Facade：智能管家
class IntelligentServer {
public:
    IntelligentServer() {
        light = new Light();
        vb = new VoiceBox();
        pro = new Projector();
    }
    ~IntelligentServer() {
        delete light;
        delete vb;
        delete pro;
    }

    void HappyTime() {
        cout << "Happy Time:" << endl;
        light->On();
        vb->On();
        pro->On();
    }

    void RelaxTime() {
        cout << "Relax Time:" << endl;
        light->On();
        vb->On();
        pro->Off();
    }

private:
    Light* light;
    VoiceBox* vb;
    Projector* pro;
};

int main() {
    IntelligentServer* ser;
    ser->HappyTime();
    ser->RelaxTime();
    return 0;
}