//AC
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
class SpinDeque
{
private:
	Node<T>* head;
	Node<T>* tail;
	int length;
public:
	SpinDeque() :head(nullptr), tail(nullptr), length(0) {}
	~SpinDeque()
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
			head = tail = new_node;
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
			new_node->prev = tail;
			tail->next = new_node;
			head->prev = new_node;
			head = new_node;
		}
	}
	void push_back(const T& _val)
	{
		Node<T>* new_node = new Node<T>{ _val,nullptr,nullptr };
		length++;

		if (tail == nullptr)
		{
			head = tail = new_node;
			return;
		}
		if (tail->next == nullptr)
		{
			new_node->next = new_node->prev = head;
			head->next = head->prev = new_node;
			tail = new_node;
		}
		else
		{
			new_node->next = head;
			new_node->prev = tail;
			head->prev = new_node;
			tail->next = new_node;
			tail = new_node;
		}
	}
	void pop_front()
	{
		if (empty())
		{
			return;
		}
		if (length == 1)
		{
			delete head;
			head = tail = nullptr;
		}
		else if (length == 2)
		{
			head = head->next;
			delete head->next;
			head->next = head->prev = nullptr;
		}
		else
		{
			tail->next = head->next;
			head->next->prev = tail;
			delete head;
			head = tail->next;
		}
		length--;
	}
	void pop_back()
	{
		if (empty())
		{
			return;
		}
		if (length == 1)
		{
			delete head;
			head = tail = nullptr;
		}
		else if (length == 2)
		{
			tail = tail->next;
			delete tail->next;
			tail->next = tail->prev = nullptr;
		}
		else
		{
			head->prev = tail->prev;
			tail->prev->next = head;
			delete tail;
			tail = head->prev;
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
	T back()
	{
		return tail->data;
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

	int N, M, x;
	char c;
	std::cin >> N;
	std::string s1;
	while (N--)
	{
		SpinDeque<int> sd1;
		int flag = 0;
		bool reverse = false;
		std::cin >> s1 >> M >> c;
		for (int i = 0;i < M;i++)
		{
			std::cin >> x >> c;
			sd1.push_back(x);
		}
		if (M == 0)
			std::cin >> c;

		for (int i = 0;i < int(s1.length());i++)
		{
			if (s1[i] == 'R')
			{
				reverse =!reverse;
			}
			else
			{
				if (sd1.empty())
				{
					flag = 1;
					break;
				}
				if (reverse == true)
					sd1.pop_back();
				else
					sd1.pop_front();
			}
		}

		if (flag)
			std::cout << "error\n";
		else
		{
			std::cout << "[";
			if (reverse == false)
			{
				if (!sd1.empty())
				{
					std::cout << sd1.front();
					sd1.pop_front();
				}
				while (!sd1.empty())
				{
					std::cout << "," << sd1.front();
					sd1.pop_front();
				}
			}
			else
			{
				if (!sd1.empty())
				{
					std::cout << sd1.back();
					sd1.pop_back();
				}
				while (!sd1.empty())
				{
					std::cout << "," << sd1.back();
					sd1.pop_back();
				}
			}
			std::cout << "]\n";
		}
	}

	return 0;
}