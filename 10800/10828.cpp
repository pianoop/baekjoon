//스택
//-------------------------------------------------------------------
#include <iostream>

template <typename T>
class Node
{
public:
	T data;
	Node* next;
};

template <typename T>
class Stack
{
private:
	Node<T>* head;
public:
	Stack() :head(NULL) {}
	~Stack()
	{
		while (head != NULL)
			pop_back();
	}

	void push_back(T val)
	{
		Node<T>* new_node = new Node<T>{ val,NULL };
		if (head != NULL)
			new_node->next = head;
		head = new_node;
	}
	void pop_back()
	{
		if (head == NULL)
		{
			printf("-1\n");
			return;
		}	
		Node<T>* temp = head;
		head = head->next;
		delete temp;
	}
	bool empty()
	{
		return head == NULL;
	}
	int size()
	{
		int s = 0;
		Node<T>* temp = head;
		while (temp != NULL)
		{
			s++;
			temp = temp->next;
		}
		return s;
	}
	int top()
	{
		if (head == NULL)
			return -1;
		return head->data;
	}
};

int main()
{
	Stack<int> s1;

	int n;
	scanf("%d", &n);

	char c[6];
	for (int i = 0;i < n;i++)
	{
		scanf("%s", c);

		if (c[0] == 'p')
		{
			if (c[1] == 'u')
			{
				int x;
				scanf("%d", &x);
				s1.push_back(x);
			}
			else
			{
				if(!s1.empty())
					printf("%d\n", s1.top());
				s1.pop_back();
			}
		}
		else if (c[0] == 's')
			printf("%d\n", s1.size());
		else if (c[0] == 'e')
		{
			printf("%d\n", s1.empty());
		}
		else
			printf("%d\n", s1.top());
	}

	return 0;
}