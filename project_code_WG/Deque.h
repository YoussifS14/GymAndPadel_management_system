#pragma once
#include "point.h"
template<class T>
class Deque
{
private:
	 point<T>* myloc;
	 
	 point<T>* head;
	 point<T>* tail;
public:
	 //extra functions
	 Deque();
	 ~Deque();
	 void clear();
	 void select(T data);
	 bool found(T data);
	 //main functions
	 void push_front(T data);
	 void push_back(T data);
	 void pop_front();
	 void pop_back();
	 T front();
	 T back();
	 bool isEmpty();
	 int length();
};

