//덱
//-------------------------------------------------------------------
#include <iostream>

template <typename T>
class Node
{
public:
	T data;
	Node* prev;
	Node* next;
};

template <typename T>
class Deque
{
private:
	Node<T>* head;
	Node<T>* tail;
	int length;
public:
	Deque() :head(nullptr),tail(nullptr), length(0) {}
	~Deque()
	{
		while (head != nullptr)
			pop_front();
	}
	void push_front(const T& _val)
	{
		Node<T>* new_node = new Node<T>{ _val,nullptr,nullptr };
		length++;

		if (head == nullptr)
		{
			head = new_node;
			tail = new_node;
		}
		else
		{
			new_node->next=head;
			head->prev = new_node;
			head = new_node;
		}
	}
	void push_back(const T& _val)
	{
		Node<T>* new_node = new Node<T>{ _val,nullptr,nullptr };
		length++;

		if (head == nullptr)
		{
			head = new_node;
			tail = new_node;
		}
		else
		{
			tail->next=new_node;
			new_node->prev = tail;
			tail = new_node;
		}
	}
	void pop_front()
	{
		if (empty())
		{
			std::cout << "-1\n";
			return;
		}
		length--;
		if (head == tail)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			head = head->next;
			delete head->prev;
			head->prev = nullptr;
		}
	}
	void pop_back()
	{
		if (empty())
		{
			std::cout << "-1\n";
			return;
		}
		length--;
		if (head == tail)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			tail = tail->prev;
			delete tail->next;
			tail->next = nullptr;
		}
	}
	bool empty()
	{
		return tail == nullptr;
	}
	int size()
	{
		return length;
	}
	T front()
	{
		return head->data;
	}
	T back()
	{
		return tail->data;
	}
};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	Deque<int> q1;
	int n;
	std::cin >> n;
	std::string s1;
	for (int i = 0;i < n;i++)
	{
		std::cin >> s1;
		if (s1== "push_front")
		{
			int x;
			std::cin >> x;
			q1.push_front(x);
		}
		else if (s1 == "push_back")
		{
			int x;
			std::cin >> x;
			q1.push_back(x);
		}
		else if (s1 == "pop_front")
		{
			if (!q1.empty())
				std::cout<< q1.front()<<"\n";
			q1.pop_front();
		}
		else if (s1 == "pop_back")
		{
			if (!q1.empty())
				std::cout << q1.back() << "\n";
			q1.pop_back();
		}
		else if (s1 == "size")
			std::cout << q1.size() << "\n";
		else if (s1 == "empty")
			std::cout << q1.empty() << "\n";
		else if (s1 == "front")
		{
			if (q1.empty())
				std::cout << "-1\n";
			else
				std::cout << q1.front() << "\n";
		}
		else
		{
			if (q1.empty())
				std::cout << "-1\n";
			else
				std::cout << q1.back() << "\n";
		}
	}

	return 0;
}