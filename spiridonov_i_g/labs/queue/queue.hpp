class Queue
{
public:
	Queue() = default;
	Queue(int size);
	Queue(const Queue&);

	~Queue();

	bool isEmpty();
	bool isFull();
	int top();
	int pop();
	void enqueue(int value);

	Queue& operator=(const Queue&);
private:
	int* data_;
	int size_;
	int start_;
	int end_;
};