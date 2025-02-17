#include "Deque.h"
#include<iostream>

using namespace std;

template<class T>
Deque<T>::Deque() {
	 head = tail = myloc=0;
}

template<class T>
Deque<T>::~Deque() {
	 clear();
}

template<class T>
void Deque<T>::clear() {
	 point<T>* temp = head;
	 while (temp!=0) {
		  delete temp;
		  temp = temp->next;
	 }
	myloc= head = tail = 0;
}

template<class T>
int Deque<T>::length() {
	 int count = 0;
	 point<T>* temp = head;
	 while (temp != 0) {
		  count++;
		  temp = temp->next;
	 }
	 return	  count;
}

template<class T>
bool Deque<T>::isEmpty() {
	 return head == 0;
}

template<class T>
T Deque<T>::back() {
	 return tail->data;
}

template<class T>
T Deque<T>::front() {
	 return head->data;
}

template<class T>
void Deque<T>::push_front(T val) {
	 point<T>* temp = new point<T>;
	 temp->data = val;
	 temp->next = head;
	 head = temp;
	 if (tail == 0) {
		  tail = head;
	 }
}

template<class T>
void Deque<T>::push_back(T val) {
	 point<T>* temp = new point<T>;
	 temp->data = val;
	 temp->next = 0;
	 if (tail == 0) {
		  head = tail = temp;
	 }
	 else {
		  tail->next = temp;
		  tail = temp;
	 }
}

template<class T>
void Deque<T>::pop_back() {
	 if (head == tail) {
		  delete head;
		  head = tail = 0;
	 }
	 else {
		  point<T>* temp = head;
		  while (temp->next != tail) {
			   temp = temp->next;
		  }
		  delete tail;
		  tail = temp;
		  tail->next = 0;
	 }
}

template<class T>
void Deque<T>::pop_front() {
	 if (head == tail) {
		  delete head;
		  head = tail = 0;
	 }
	 else {
		  point<T>* temp = head;
		  head = head->next;
		  delete temp;
	 }
}

template <class T>
void Deque<T>::select(T val) {
	 point<T>* temp = head;
	 while (temp != 0) {
		  if (temp->data == val) {
			   myloc = temp;
			   return;
		  }
		  temp = temp->next;
	 }
	 myloc = 0;
	 cout << "Not Exist\n";
	 
}

template <class T>
bool Deque<T>::found(T val) {
	 point<T>* temp = head;
	 while (temp != 0) {
		  if (temp->data == val) {
			   return true;
		  }
		  temp = temp->next;
	 }
	 return false;
}