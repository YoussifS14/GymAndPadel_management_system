#pragma once
#include "point.h"

template<class type>
class Queue {
protected:
	 point<type>* head;
	 point<type>* tail;
	 int length;
public:
	 bool isEmpity();
	 void push(type val);
	 void pop();
	 type front();
	 type back();
	 int  Length();
	 Queue(void);
	 ~Queue(void);


};

