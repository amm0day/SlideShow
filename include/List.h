#include "Error.h"

template<typename T>
class List {
public:
	List();

	void	pushBack(T data);
	void	pushFront(T data);
	void	pushIndex(int index, T data);
	void	delIndex(int index);
	void	delBack();
	void	delFront();
	int		getSize();
	T&		getBack();
	T&		operator[](int index);

private:
	class Node {
	public:
		Node *pNext;
		T data;
		Node(T data = T(), Node *pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	// "size" is for getting List size without iteration
	int Size;
	Node* head;
};

template<typename T>
List<T>::List() {
	Size = 0;
	head = nullptr;
}

template<typename T>
void List<T>::delFront() {
	if(head){
		Node *tmp = head;
		head = head->pNext;
		delete tmp;
		Size--;
	}
}

template<typename T>
void List<T>::delBack() {
	if(head){
		Node *current = head;
		Node *tmp;

		for(int i = 1; i < this->Size; i++)
			current = current->pNext;
		tmp = current->pNext;
		current->pNext = nullptr;
		delete tmp;
		Size--;

	}
}

template<typename T>
void List<T>::pushFront(T data) {
	head = new Node(data, head);
	Size++;
}

template<typename T>
void List<T>::pushBack(T data) {
	if(head){
		Node *current = head;
		while (current->pNext)
			current = current->pNext;
		current->pNext = new Node(data);
	} else
		head = new Node(data);
	Size++;
}

template<typename T>
int List<T>::getSize() {
	return this->Size;
}

template<typename T>
T& List<T>::operator[](int index) {
	Node *current = head;
	// Use negative index to get revers order index (with love from Python)
	if (index < 0 && index >= -this->Size)
		index += this->Size;
	if (index >= 0 && index < this->Size) {
		while (index-- > 0)
			current = current->pNext;
		return current->data;
	} else {
		cout << "Invalid index. list[" << index << "]" << endl;
		exit(1);
	}
}

template<typename T>
T& List<T>::getBack() {
	return this->head->data;
}

template<typename T>
void List<T>::pushIndex(int index, T data) {
Node* current = head;
	if (index > -1 && index <= this->Size){
		if(index == this->Size - 1)
			this->pushBack(data);
		else if(index == 0)
			this->pushFront(data);
		else{
			while (index-- > 0)
				current = current->pNext;
			current->pNext = new Node(data, current->pNext);
			Size++;
		}
	}
}

template<typename T>
void List<T>::delIndex(int index) {
	if (index > -1 && index <= this->Size){
		if(index == this->Size - 1)
			this->delBack();
		else if(index == 0)
			this->delFront();
		else{
			Node* current = head;
			Node* next;
			while (index-- > 0)
				current = current->pNext;
			next = current->pNext;
			current->pNext = next->pNext;
			delete next;
			Size--;
		}
	}
}