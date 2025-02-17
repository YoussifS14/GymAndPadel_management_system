#include "Queue.h"

template<class t>
Queue<t>::Queue(void)
{
	 head = 0;
	 tail = 0;
	 length = 0;
}
template<class t>
Queue<t>::~Queue(void)
{
	 while (head != 0) {
		  point<t>* temp = head;
		  head = head->next;
		  delete temp;
	 }
}

template<class t>
bool Queue<t>::isEmpity(void) {
	 return length == 0;
}

template<class type>
void Queue<type>::push(type val) {
	 point<type>* temp = new point<type>;
	 temp->data = val;
	 temp->next = 0;
	 if (head == 0) {
		  head = temp;
		  tail = temp;
	 }
	 else {
		  tail->next = temp;
		  tail = temp;
	 }
	 length++;

}
template<class t>
void Queue<t>::pop(void) {
	 if (head == 0) return;
	 point<t>* temp = head;
	 head = head->next;
	 delete temp;
	 length--;
}

template<class t>
t Queue<t>::front(void) {
	 if (head == 0) return 0;
	 return head->data;
}
template<class t>
t Queue<t>::back(void) {
	 if (tail == 0) return 0;
	 return tail->data;
}
template<class t>
int Queue<t>::Length(void) {
	 return length;
}
