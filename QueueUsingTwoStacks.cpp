/*
#include<iostream>
#include<stack>

using namespace std;

stack<int> StackFBottom;
stack<int> StackRBottom;

class Q
{
public:
	void Qpush(int);
	void Qpop(void);
	int Qfront(void);
	int Qback(void);
	int Qempty(void);
};

void Q::Qpush(int x)
{
	StackFBottom.push(x);
}

void Q::Qpop(void)
{
	while (StackFBottom.empty() == 0)
	{
		StackRBottom.push(StackFBottom.top());
		StackFBottom.pop();
	}
	
	StackRBottom.pop();
	
	while (StackRBottom.empty() == 0)
	{
		StackFBottom.push(StackRBottom.top());
		StackRBottom.pop();
	}
}

int Q::Qfront(void)
{
	while(StackFBottom.empty()==0)
	{
		StackRBottom.push(StackFBottom.top());
		StackFBottom.pop();
	}
	int x = StackRBottom.top();
	while (StackRBottom.empty() == 0)
	{
		StackFBottom.push(StackRBottom.top());
		StackRBottom.pop();
	}
	return x;
}

int Q::Qback(void)
{
	int x;
	x = StackFBottom.top();
	return x;
}

int Q::Qempty(void)
{
	int x = StackFBottom.empty();
	return x;
}


int main()
{
	Q bleh;
	int holder;
	for (int i = 0; i < 10; i++)
	{
		bleh.Qpush(i);
	}
	cout << "Front: "<<bleh.Qfront()<<endl;
	cout << "Rear:" << bleh.Qback() << endl;

	while (!bleh.Qempty())
	{
		holder = bleh.Qfront();
		bleh.Qpop();
		cout << " ->" << holder;
	}
	
	getchar();

	return 0;
}
*/