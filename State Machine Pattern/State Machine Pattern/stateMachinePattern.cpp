#include<iostream>

using namespace std;

class state {
public:
	virtual void handleState() = 0;
};

class A : public state {
public:
	void handleState() override {
		cout << "This is class A implementation" << endl;
	}
};

class B : public state {
	void handleState() override {
		cout << "This is class B implemenation" << endl;
	}
};

class context {
	state* currentState;
public:
	context(state* currentState) {
		this->currentState = currentState;
	}

	void setState(state* newState) {
		this->currentState = newState;
	}

	void performAction() {
		currentState->handleState();
	}
};

int main() {
	A a;
	B b;

	context con(&a);
	con.performAction();
	con.setState(&b);
	con.performAction();
}