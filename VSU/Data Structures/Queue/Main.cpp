#include "Queue.h"
using namespace std;

int main() {

	Queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(-10);
	cout << q.size() << endl;
	q.pop();
	cout << endl << q.min() << " " << q.max() << endl;
	return 0;
}