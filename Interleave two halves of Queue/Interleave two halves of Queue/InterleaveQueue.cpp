#include <iostream>
#include <queue>

using namespace std;

queue<int> interLeave(queue<int> q) {
	queue<int> q1, q2;
	int s = q.size();
	for (int i = 0; i < q.size() / 2 + 1; i++) {
		q1.push(q.front());
		q.pop();
	}

	while(!q.empty()) {
		q2.push(q.front());
		q.pop();
	}

	while((!q1.empty()) or (!q2.empty())) {
		if (!q1.empty()){
			q.push(q1.front());
			q1.pop();
		}
		if(!q2.empty()){
			q.push(q2.front());
			q2.pop();
		}
	}
	return q;
}


int main() {	
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);
	q = interLeave(q);
	while(!q.empty()) {
		cout << q.front();
		q.pop();
	}
}