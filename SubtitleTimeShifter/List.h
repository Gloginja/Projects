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
	element* current;

public:
	List() {
		this->count = 0;
		this->first = nullptr;
		this->last = nullptr;
		this->current = nullptr;
	}


	void append(T _data) {

		element* tmp = new element(_data);
		if (count == 0) {
			first = tmp;
			last = tmp;
			current = tmp;
		}
		else {
			last->next = tmp;
			tmp->prev = last;
			last = tmp;
		}
		count++;
	}

	T pop() {
		T dataPop;
		if (count != 0) {
			dataPop = last->data;
			element* tmp = last;
			last = last->prev;
			if (last != nullptr) {
				last->next = nullptr;
			}
			delete tmp;
			count--;
		}
		else dataPop = nullptr;
		return dataPop;

	}
   
	T popFront() {
		T dataPop;
		if (count != 0) {
			dataPop = first->data;
			element* tmp = first;
			first = first->next;
			if (first != nullptr) {
				first->prev = nullptr;
			}
			delete tmp;
			count--;
		}
		else dataPop = nullptr;
		return dataPop;

	}


	int getCount() {
		return this->count;
	}

	void resetCurrent()
	{
		this->current = this->first;
	}

	T getCurrent()
	{
		if (this->current != nullptr) return this->current->data;
		else
			return nullptr;
	}

	void nextCurrent()
	{
		this->current = this->current->next;
	}

	bool currentLast()
	{
		if (current == nullptr) return true; else return false;
	}

};
