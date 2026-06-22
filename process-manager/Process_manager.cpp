#include<iostream>
#include<conio.h>
#include <windows.h>
using namespace std;

void skip()
{
	cout << "\033[00m" << "Press any key to continue!!!!";
	_getch();
}

class node
{
	string name;
	int priority;
	int current_dur;
	int total_dur;
	node* next;
	node* prev;
public:
	node(string n = "", int p = 0, int d = 0, node* ne = nullptr, node* pre = nullptr)
	{
		name = n;
		total_dur = current_dur = d;
		priority = p;
		next = ne;
		prev = pre;
	}
	string getname()
	{
		return name;
	}
	int getCurr_dur()
	{
		return current_dur;
	}
	int getpriority()
	{
		return priority;
	}
	node* getNext()
	{
		return next;
	}
	node* getPrev()
	{
		return prev;
	}
	int get_total_dur()
	{
		return total_dur;
	}
	void setname(string n)
	{
		name = n;
	}
	void setCurr_dur(int d)
	{
		current_dur = d;
	}
	void set_total_dur(int d)
	{
		total_dur = d;
	}
	void setpriority(int s)
	{
		priority = s;
	}
	void setPrev(node* p)
	{
		prev = p;
	}
	void setNext(node* n)
	{
		next = n;
	}
};

class queue
{
	int size;
	node* head;
	node* tail;
public:
	queue(int s = 0, node* h = nullptr, node* ta = nullptr)
	{
		head = h;
		tail = ta;
		size = s;
	}
	node* gethead()
	{
		return head;
	}
	node* gettial()
	{
		return tail;
	}
	int getsize()
	{
		return size;
	}
	void setSize(int s)
	{
		size = s;
	}
	void enqueue(node* newNode)
	{
		cout << "\033[90m" << "ADDED Task:  " << "\033[00m" << newNode->getname();
		cout << "\033[91m" << " (" << "\033[93mPriority " << "\033[00m" << newNode->getpriority() << " , ";
		cout << "\033[93mDuration " << "\033[00m" << newNode->getCurr_dur() << "\033[91m" << ")" << "\033[00m" << endl;
		if (size == 0)
		{
			head = tail = newNode;
		}
		else
		{
			tail->setNext(newNode);
			newNode->setPrev(tail);
			tail = newNode;
		}
		size++;
	}
	node* dequeue()
	{
		if (size == 0)
		{
			return nullptr;
		}

		node* temp = head;

		if (head == tail)
		{
			head = tail = nullptr;
		}
		else
		{
			head = head->getNext();
			head->setPrev(nullptr);
			temp->setNext(nullptr);
		}

		size--;
		return temp;
	}

	node* check_priority()
	{
		node* temp = head;
		int mini = 10;
		node* index_node = head;

		while (temp != nullptr)
		{
			if (temp->getpriority() < mini)
			{
				mini = temp->getpriority();
				index_node = temp;
			}
			temp = temp->getNext();
		}

		return index_node;
	}

	void print()
	{
		node* temp = head;

		cout << "\033[36m" << "Ready Queue: " << "\033[91m[ ";

		while (temp != nullptr)
		{
			cout << "\033[00m" << temp->getname() << "\033[91m" << " (" << "\033[93mPriority ";
			cout << "\033[00m" << temp->getpriority() << " , \033[93mDuration " << "\033[00m";
			cout << temp->getCurr_dur() << "\033[91m" << ")" << "\033[00m";
			if (temp->getNext() != nullptr)
				cout << "\n\t\t\t\t    \033[33m" << " , ";
			temp = temp->getNext();
		}
	
		cout << "\033[91m" << " ]" << "\033[00m" << endl;
	}
};

class stack
{
	int size;
	node* head;
	node* tail;
public:
	stack(int s = 0, node* h = nullptr, node* ta = nullptr)
	{
		head = h;
		tail = ta;
		size = s;
	}
	node* gethead()
	{
		return head;
	}
	node* gettail()
	{
		return tail;
	}
	int getsize()
	{
		return size;
	}
	void setSize(int s)
	{
		size = s;
	}

	void push(node* newNode, bool whereToGo)
	{
		if (newNode->getCurr_dur() == 0)
			newNode->setCurr_dur(newNode->get_total_dur());
		if (whereToGo)
			cout << "\033[92m" << "The completed task \033[00m" << newNode->getname() << "\033[92m is pushed into the stack!!!\n" << "\033[00m";
		else
			cout << "\033[91m" << "The killed task \033[00m" << newNode->getname() << "\033[91m is pushed into the stack!!!\n" << "\033[00m" ;

		if (size == 0)
		{
			head = tail = newNode;
		}
		else
		{
			tail->setNext(newNode);
			newNode->setPrev(tail);
			tail = newNode;
		}

		size++;
	}
	node* pop(bool whereToGo)
	{
		if(whereToGo)
		cout << "\033[92m" << "The Completed task is poped out form the stack!!!\n\n" << "\033[00m";
		else 
		cout << "\033[91m" << "The Killed task is poped out form the stack!!!\n\n" << "\033[00m";
		node* temp = tail;

		if (head == tail)
		{
			head = tail = nullptr;
		}
		else
		{
			tail = tail->getPrev();
			temp->setPrev(nullptr);
			tail->setNext(nullptr);
		}
		size--;

		return temp;
	}

	void print()
	{
		int counter = 3;
		if (size < 3)
		{
			counter = size;
		}

		node* temp = tail;

		cout << "\033[36m" << "\n\|------------------|\n";
		for (int i = 0; i < counter; i++)
		{
			cout << "\033[00m" << "    " << temp->getname();

			if (i != counter - 1)
				cout << "\033[91m" << "\n\t  |\n";
			temp = temp->getPrev();
		}
	cout << "\033[36m" << "\n|------------------|\n" << "\033[00m";
	}
};

void find_highest_priority(queue& readyQueue)
{
	cout << "\n\033[36m****************************************************************************************************************\n" << "\033[00m";
	cout << "\t\t\t\t\t" << "The queue is prioritized" << "\033[36m!!!!" << "\033[00m";
	cout << "\n\033[36m****************************************************************************************************************\n\n\n" << "\033[00m";
	node* temp = readyQueue.gethead();
	node* priority_node = readyQueue.check_priority();

	while (true)
	{
		if (temp == priority_node)
		{
			break;
		}
		temp = temp->getNext();
		readyQueue.enqueue(readyQueue.dequeue());
	}
}

void run_Task(queue& readyQueue, int timeSlice, stack &completed_Task)
{
	system("cls");
	cout << "\t\t\t";
	readyQueue.print();
	int totaltime = 0;	
	int difference = readyQueue.gethead()->getCurr_dur() - timeSlice;

	if (difference <= 0)
		totaltime = readyQueue.gethead()->getCurr_dur() * 1000;
	else
		totaltime = timeSlice * 1000;

	readyQueue.gethead()->setCurr_dur(difference);

	cout << "\033[90m" << "\n\n\nRunning " << "\033[00m" << readyQueue.gethead()->getname() << "\033[00m";
	cout << "\033[90m" << " for " << "\033[00m" << (totaltime / 1000) << "\033[90m" << " seconds...." << endl;
	Sleep(totaltime);
	cout << "Time slice completed!!\n\n";

	if (difference <= 0)
		completed_Task.push(readyQueue.dequeue(), true);
	else
		readyQueue.enqueue(readyQueue.dequeue());
}

bool want_to_kill(queue& readyQueue, stack & killed_Task, stack& completed_Task)
{
	system("cls");
	cout << "\033[33mBEFORE: \n\t\t\t";
	readyQueue.print();
	cout << endl;
	find_highest_priority(readyQueue);
	cout << "\n\n\t\t\t";
	readyQueue.print();
	cout << "\033[93m" << "\n\n\n\n\t\t\tPress" << "\033[00m k" << "\033[93m to\033[91m kill \033[92m" << readyQueue.gethead()->getname();
	if(killed_Task.getsize() != 0)
		cout << "\033[93m" << "\n\t\t\tPress" << "\033[00m u" << "\033[93m to\033[91m restore \033[92m" << killed_Task.gettail()->getname();
	if (completed_Task.getsize() != 0)
		cout << "\033[93m" << "\n\t\t\tPress" << "\033[00m c" << "\033[93m to\033[91m see Completed task \033[92m";
	cout << "\033[93m task \n\t\t\tPress" << "\033[00m enter \033[93mto" << "\033[33m continue" << "\033[00m!!!";

	char ch;
	while (true)
	{
		ch = _getch();

		if (((completed_Task.getsize() != 0) && (ch == 'c' || ch == 'C'))
			|| (((killed_Task.getsize() != 0) && (ch == 'u' || ch == 'U')) 
				|| ch == 'k' || ch == 'K' || ch == '\n' || ch == '\r'))
			break;
	}

	if (ch == 'k' || ch == 'K')
	{
		system("cls");
		killed_Task.push(readyQueue.dequeue(), false);
		return true;
	}

	if ((killed_Task.getsize() != 0) && (ch == 'u' || ch == 'U'))
	{
		readyQueue.enqueue(killed_Task.pop(false));
		return true;
	}

	if ((completed_Task.getsize() != 0) && (ch == 'c' || ch == 'C'))
	{
		system("cls");
		completed_Task.print();
		skip();
		return true;
	}
	return false;
}

void want_to_restore(queue& readyQueue, stack& killed_Task, stack& completed_Task)
{
	
	char ch;
	while (true)
	{
		ch = _getch();

		if (ch == 'k' || ch == 'K' || ch == '\n' || ch == '\r')
			break;
	}
}

int main()
{
	stack completed_Task;
	stack killed_Task;

	queue readyQueue;
	node* n1 = new node("task1", 2, 5);
	node* n2 = new node("task2", 1, 2);
	node* n3 = new node("task3", 4, 6);
	node* n4 = new node("task4", 7, 3);
	node* n5 = new node("task5", 3, 2);
	node* n6 = new node("task5", 5, 4);

	readyQueue.enqueue(n1);
	readyQueue.enqueue(n2);
	readyQueue.enqueue(n3);
	readyQueue.enqueue(n4);
	readyQueue.enqueue(n5);
	readyQueue.enqueue(n6);
	cout << "\n\n\n\n\t\t\t";
	readyQueue.print();
	cout << "\033[93m" << "\n\n\n\n\n\t\t\t\tLets start the process management: \n\t\t\t\t";
	skip();
	system("cls");

	while (true)
	{
		if (readyQueue.getsize() == 0)
		{
			system("cls");
			cout << "\033[91m" << "\n\n\n\n\t\t\tThe size of the queue is zero!!!\n" << "\033[00m";
			if (killed_Task.getsize() != 0)
				cout << "\033[93m" << "\t\t\tPress " << "\033[36mU " << "\033[93mto pop Task again!!!\n" << "\033[00m";
			if (completed_Task.getsize() != 0)
				cout << "\033[93m" << "\t\t\tPress" << "\033[36m c" << "\033[93m to\033[91m see Completed task \033[92m\n";
			cout << "\033[93m" << "\t\t\tPress any key to" << "\033[91m end " << "\033[93mthe Application\033[00m";
			char ch = _getch();
			system("cls");
			
			if ((killed_Task.getsize() != 0) && (ch == 'u' || ch == 'U'))
			{
				readyQueue.enqueue(killed_Task.pop(false));
				continue;
			}

			if ((completed_Task.getsize() != 0) && (ch == 'c' || ch == 'C'))
			{
				system("cls");
				completed_Task.print();
				skip();
				continue;
			}

			cout << "\033[93m" << "\n\n\n\n\n\n\t\t\tThanks for using the application!!!!\n\n\n\n\n\n\n" << "\033[00m";
			return 0;
		}

		if (want_to_kill(readyQueue, killed_Task, completed_Task))
		{
			continue;
		}

		run_Task(readyQueue, 3, completed_Task);
		cout << endl;
		cout << endl;
		skip();
		system("cls");
	}
}