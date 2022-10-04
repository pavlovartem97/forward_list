#include <iostream>
#include <forward_list>

struct Node {
	int value = 0;
	Node* next = nullptr;
};

struct List {
	Node* first = nullptr;
	int size_ = 0;

	void push_front(const int value) {
		Node* newNode = new Node;
		newNode->value = value;
		newNode->next = first;
		first = newNode;
		size_++;
	}

	void print() {
		Node* curNode = first;
		while (!(curNode == nullptr))
		{
			std::cout << curNode->value << "\n";
			curNode = curNode->next;
		}
	};

	void clear() {
		while (first != nullptr) {
			Node* tmpNode = first->next;
			delete first;
			first = tmpNode;
		}
		size_ = 0;
	}

	void pop_front() {
		if (first != nullptr) {
			Node* tmpNode = first->next;
			delete first;
			first = tmpNode;
			size_--;
		}
	}

	bool is_empty() {
		if (first != nullptr) {
			return true;
		}
		return false;
	}

	void insert_after(int position, int value) {
		Node* curNode = first;
		int pos = 0;
		while (!(curNode == nullptr))
		{
			if (position == pos) {
				Node* tmpNode = new Node;
				tmpNode->value = value;

				tmpNode->next = curNode->next;

				curNode->next = tmpNode;

				size_++;
				return;
			}

			pos++;
			curNode = curNode->next;
		}
	}

	int operator[] (const int index) {
		Node* curNode = first;
		int pos = 0;
		while (!(curNode == nullptr))
		{
			if (index == pos) {
				return curNode->value;
			}
			pos++;
			curNode = curNode->next;
		}

		std::cout << "Out of range";
	}

	int size() {
		return size_;
	}
};

int main()
{
	{
		Node* node = new Node;
		node->value = 5;

		node->next = new Node;
		node->next->value = 10;

		node->next->next = new Node;
		node->next->next->value = 15;

		node->next->next->next = nullptr;
	}

	{
		std::cout << "List from std:\n";
		std::forward_list<int> list;

		list.push_front(10);
		list.push_front(5);
		list.push_front(-19);

		list.pop_front();

		for (auto i : list) {
			std::cout << i << " ";
		}
		std::cout << "\n";
	}

	{
		std::cout << "Own list:\n";

		List list;

		list.push_front(10);
		list.push_front(5);
		list.push_front(-19);
		list.insert_after(2, 20);

		for (int i = 0; i < list.size(); ++i) {
			std::cout << list[i] << "\n";
		}

		list.print();

		std::cout << "List after clear:\n";
		list.clear();

		list.print();
	}
}

