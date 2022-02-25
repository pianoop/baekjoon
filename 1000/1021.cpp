//회전하는 큐
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
class SpinQue
{
private:
	Node<T>* head;
	int length;
public:
	SpinQue() :head(nullptr), length(0) {}
	~SpinQue()
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
			return;
		}
		if (head->next == nullptr)
		{
			new_node->next = new_node->prev = head;
			head->next = head->prev = new_node;
			head = new_node;
		}
		else
		{
			new_node->next = head;
			new_node->prev = head->prev;
			head->prev->next = new_node;
			head->prev = new_node;
			head = new_node;
		}
	}
	void pop_front()
	{
		if (empty())
		{
			std::cout << "-1\n";
			return;
		}
		if (length == 1)
		{
			delete head;
			head = nullptr;
		}
		else if (length == 2)
		{
			head = head->next;
			delete head->next;
			head->next = head->prev = nullptr;
		}
		else
		{
			Node<T>* temp = head;
			head->prev->next = head->next;
			head->next->prev = head->prev;
			head = head->next;
			delete temp;
		}
		length--;
	}
	void Clockwise()
	{
		if (length > 1)
		{
			head = head->prev;
		}
	}
	void CounterClockwise()
	{
		if (length > 1)
		{
			head = head->next;
		}
	}
	bool empty()
	{
		return head == nullptr;
	}
	int size()
	{
		return length;
	}
	T front()
	{
		return head->data;
	}
};

template <typename T>
T Min(T a, T b)
{
	return a < b ? a : b;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	SpinQue<int> sq1, sqm;
	int N, M;
	std::cin >> N >> M;
	for (int i = N;i > 0;i--)
	{
		sq1.push_front(i);
	}

	int total = 0;
	for (int i = 0;i < M;i++)
	{
		int x, n = 0;
		std::cin >> x;
		while (1)
		{
			if (sq1.front() == x)
			{
				total += Min(n, sq1.size() - n);
				sq1.pop_front();
				break;
			}
			sq1.Clockwise();
			n++;
		}
	}
	std::cout << total;

	return 0;
}