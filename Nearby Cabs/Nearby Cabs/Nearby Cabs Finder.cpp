#include<iostream>
#include<vector>
#include <queue>
#include <math.h>

using namespace std;

class Car {
public:
	string ID;
	int a;
	int b;
	Car(string ID, int a, int b) {
		this->ID = ID;
		this->a = a;
		this->b = b;
	}

	int distance() {
		return sqrt(a * a + b * b);
	}
};

class pCompare {
public:
	bool operator ()(Car A, Car B){
		return A.distance() < B.distance();
	}
};

void pque_adder() {
	priority_queue<Car, vector<Car>, pCompare> q;
	int check = 0;
	vector<Car> v;
	string s;
	int a;
	int b;
	while (check != -1) {
		cout << "Input the ID: ";
		cin >> s;
		cout << "Input the x axis: ";
		cin >> a;
		cout << "Input the y axis: ";
		cin >> b;
		q.push({ s, a, b });
		cout << "Enter -1 to exit: ";
		cin >> check;
	}
}

void nearest_three_finder() {
	priority_queue<Car, vector<Car>, pCompare> q;
	int check = 0;
	vector<Car> v;
	string s;
	int a;
	int b;
	while (check != -1) {
		cout << "Input the ID: ";
		cin >> s;
		cout << "Input the x axis: ";
		cin >> a;
		cout << "Input the y axis: ";
		cin >> b;
		if (q.size() >= 3) {
			if ((q.top().a * q.top().a) + (q.top().b * q.top().b) > (a * a + b * b)) {
				q.pop();
				q.push({ s, a, b });
			}
		}
		else
			q.push({ s, a, b });
		cout << "Enter -1 to exit: ";
		cin >> check;
	}

	for (int i=0; i <= q.size()+1; i++){
		cout << q.top().ID << endl;
		q.pop();
	}
}

int main() {
	nearest_three_finder();
}