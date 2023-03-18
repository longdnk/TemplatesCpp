#include <bits/stdc++.h>

using namespace std;

class Device {
protected:
    string code;
    int pos;
    string status;
public:
    void setStatus(string st) {
        this->status = st;
    }

    virtual void turnOn() = 0;

    void turnOff() {
        this->setStatus("off");
    }
};

class Lamp: public Device {
protected:
    int light;
};

class LightLamp: public Lamp {
public:
    void turnOn() {
        cout << "Turn on light lamp" << '\n';
        this->setStatus("on");
    }

};

class SleepLamp: public Lamp {
protected:
    string color;
public:
    void setLight(int l) {
        this->light = l;
    }

    void setColor(string c) {
        this->color = c;
    }

    void turnOn() {
        cout << "Turn on Sleep lamp" << '\n';
        this->setStatus("on");
    }
};

class Inverter: public Device {
protected:
    int temp;
    string mode;
    int power;
public:
    void setTemp(int t) {
        this->temp = t;
    }

    void setMode(string m) {
        this->mode = m;
    }

    void turnOn() {
        cout << "Turn on Inverter" << '\n';
        this->setStatus("on");
    }

    void setPower(int p) {
        this->power = p;
    }
};

class TV: public Device {
protected:
    int sound;
    int channel;
public:
    void setSound(int s) {
        this->sound = s;
    }

    void selectChannel(int c) {
        this->channel = c;
    }

    void turnOn() {
        cout << "Turn on TV" << '\n';
        this->setStatus("on");
    }
};

struct device {
    string code;
    int pos;
    string status;
    int light;
    string color;
    int temp;
    string mode;
    int power;
    int sound;
    int channel;
    string Type;
};

const int maxn = 1e5 + 9;
device dv[maxn];

struct Node {
    device info;
    Node *next;
};

struct ListDevice {
    Node *head;
    Node *tail;
};

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Device *d[] = {
        new SleepLamp,
        new Inverter,
    };
    int n = sizeof(d) / sizeof(d[0]);
    for (int i = 0; i < n; ++i) {
        d[i]->turnOn();
    }
}