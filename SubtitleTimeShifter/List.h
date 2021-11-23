#pragma once


template<typename T>
class List {

	int count;
	struct element {
		T data;
		element* next;
		element* prev;
		element(T _data) {
			this->data = _data;
			this->next = nullptr;
			this->prev = nullptr;
		}
	};
	element* first;
	element* last;

public:
	List() {
		this->count = 0;
		this->first = nullptr;
		this->last = nullptr;
	}


	void append(T _data) {

		element* tmp = new element(_data);
		if (count == 0) {
			first = tmp;
			last = tmp;
		}
		else {
			last->next = tmp;
			tmp->prev = last;
			last = tmp;
		}
		count++;
	}

	T pop() {
		T datapop;
		if (count != 0) {
			datapop = last->data;
			element* tmp = last;
			last = last->prev;
			if (last != nullptr) {
				last->next = nullptr;
			}
			delete tmp;
			count--;
		}
		else datapop = -1;
		return datapop;

	}
   
	int getCount() {
		return this->count;
	}


};
