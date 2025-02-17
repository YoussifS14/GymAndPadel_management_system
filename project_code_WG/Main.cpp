#include<iostream>
#include "Queue.cpp"

using namespace std;

int main() {
	 Queue<int> q;
	 q.push(1);
		  
	 cout << q.front() << endl;
	 cout << q.back() << endl;
	 q.push(2);
	 cout << q.front() << endl;
	 cout << q.back() << endl;
	 q.push(3);
	 cout << q.front() << endl;
	 cout << q.back() << endl;
	 q.pop();
	 cout << q.front() << endl;
	 cout << q.back() << endl;

}