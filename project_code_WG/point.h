#pragma once
template<class type>
class point {
public:
	 type data;
	 point<type>* next;
	 point() {
		  data = 0;
		  next = 0;
	 }
};
