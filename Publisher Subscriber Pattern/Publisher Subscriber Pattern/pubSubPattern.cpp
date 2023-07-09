#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Observer {
public:
	virtual void update(const string& message) = 0;
};

class concreteObserver : public Observer {
	string name;
public:
	explicit concreteObserver(const string& names) : name( names ){}

	void update(const string& message) override {
		cout << message << " "<< name << endl;
	}
};

class Publisher {
	vector<Observer*> observers;
public:
	void attachSubscriber(Observer* observer) {
		observers.push_back(observer);
	}

	void detachSubscriber(Observer* observer) {
		auto it = find(observers.begin(), observers.end(), observer);
		if (it != observers.end()) {
			observers.erase(it);
		}
	}

	void notifySubscribers(const string& message) {
		for (auto ob : observers) {
			ob->update(message);
		}
	}
};

int main() {

	concreteObserver o1("01");
	concreteObserver o2("02");
	concreteObserver o3("03");

	Publisher p;

	p.attachSubscriber(&o1);
	p.attachSubscriber(&o2);
	p.attachSubscriber(&o3);

	p.notifySubscribers("Notify all");

	p.detachSubscriber(&o2);

	p.notifySubscribers("Notify after removal");
	
}