#include <bits/stdc++.h>

using namespace std;

class Observer {
public:
	virtual void update() = 0;
};

class Frame: public Observer {
public:
	void update() {
		cout << "Update Frame" << '\n';
	}
};

class Window: public Observer {
public:
	void update() {
		cout << "Update Window" << '\n';
	}
};

class Button {
private:
	Observer *observers;
public:
	void addObserver(Observer *obs) {
		cout << "Add observer" << '\n';
		observers = obs;
		this->notify();
	}
	void removeObserver(Observer *obs) {
		cout << "Remove observer" << '\n';
		observers = obs;
		this->notify();
	}

	void notify() {
		observers->update();
	}
};

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	Observer *obs[] = {
		new Frame,
		new Window,
	};
	Button *b = new Button;
	int n = sizeof(obs) / sizeof(obs[0]);
	for (int i = 0; i < n; i++) {
		b->addObserver(obs[i]);
		b->removeObserver(obs[i]);
	}

}