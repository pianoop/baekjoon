//최소 힙
//-------------------------------------------------------------------
#include <iostream>

class Heap
{
private:
	int size=0;
	int* heap;
	int cap;
public:
	Heap() :cap(100000), heap((int*)malloc(sizeof(int)* cap)){}
	Heap(const int& n):cap(n), heap((int*)malloc(sizeof(int)* n)){}
	~Heap()
	{
		free(heap);
	}

	void push(const int& value)
	{
		if (size == cap)
			return;
		size++;
		heap[size] = value;
		update(size);
	}
	void pop()
	{
		if (size == 0)
			return;
		heap[1] = heap[size--];
		downdate(1);
	}

	void update(const int& idx)
	{
		int child = idx;
		while (child > 1 && heap[child] < heap[child / 2])
		{
			swap(child, child / 2);
			child /= 2;
		}
	}

	void downdate(const int& idx)
	{
		int parent = idx;
		int child = idx * 2;
		if (child + 1 <= size)
			child = heap[child] < heap[child + 1] ? child : child + 1;

		while (child <= size && heap[child] < heap[parent])
		{
			swap(child, parent);

			parent = child;
			child *= 2;
			if (child + 1 <= size)
				child = heap[child] < heap[child + 1] ? child : child + 1;
		}
	}

	bool empty()
	{
		return size == 0;
	}

	int getSize()
	{
		return size;
	}

	void swap(const int& a, const int& b)
	{
		int temp = heap[a];
		heap[a] = heap[b];
		heap[b] = temp;
	}

	int top()
	{
		return heap[1];
	}
};



int main()
{
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);

	int N;
	std::cin >> N;

	Heap* h1 = new Heap(N);
	int order;
	while (N--)
	{
		std::cin >> order;
		if (order > 0)
			h1->push(order);
		else
		{
			if (h1->empty())
				std::cout << "0\n";
			else
			{
				std::cout << h1->top() << "\n";
				h1->pop();
			}
		}
	}

	delete h1;
	return 0;
}