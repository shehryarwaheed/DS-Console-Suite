//#include<iostream>
//#include<fstream>
//#include<conio.h>
//#include<windows.h>
//#include<string>
//using namespace std;
//
//int validValue(int l, int u, string s)
//{
//	int a = 0;
//	while (true)
//	{
//		if (cin >> a && a >= l && a <= u)
//		{
//			break;
//		}
//		cout << "\033[91m" << "\nYou entered invalid input kindly enter between the range!!!\n\t\t\t\t\t" << "\033[00m" << "Enter " << s << " again: " << "\033[36m";
//		cin.clear();
//		cin.ignore();
//	}
//	cout << "\033[00m";
//	return a;
//}
//
//void Title(string name = "NOTEPAD")
//{
//	cout << "\033[33m" << "************************************************************************************************************************\n" << "\033[00m";
//	cout << "\033[33m" << "*\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t*" << "\033[00m" << endl;
//	cout << "\033[33m" << "*\t\t\t\t\t\t\t\033[00m" << name << "\t\t\t\t\t\t\t\t\033[33m*" << "\033[00m" << endl;
//	cout << "\033[33m" << "*\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t*" << "\033[00m" << endl;
//	cout << "\033[33m" << "************************************************************************************************************************\n" << "\033[00m";
//}
//
//string* loadFileinfo(int &finalNumber)
//{
//	ifstream file("file_info.txt");
//	string number;
//
//	if (!file)
//	{
//		cout << "\n\nThe number loading file is not opening!!!!\n\n\n";
//		return 0;
//	}
//	getline(file, number);
//	
//	finalNumber = stoi(number);
//
//	string* names = new string[20];
//
//	for (int i = 0; i < finalNumber; i++)
//	{
//		getline(file, names[i]);
//	}
//
//	file.close();
//	return names;
//}
//
//void updateinfo(string* nameslist, int numberofFiles)
//{
//	ofstream infofile("file_info.txt", ios::trunc);
//
//	if (!infofile)
//	{
//		cout << "\n\n\nInfo file is not opening!!!\n\n\n";
//		return;
//	}
//
//	infofile << numberofFiles << '\n';
//
//	for (int i = 0; i < numberofFiles; i++)
//	{
//		infofile << nameslist[i] << "\n";
//	}
//
//	infofile.close();
//}
//
//template <typename T>
//class node
//{
//	T data;
//	node<T>* next;
//	node<T>* prev;
//public:
//	node(T d = 0, node<T>* n = nullptr, node<T>* p = nullptr)
//	{
//		data = d;
//		next = n;
//		prev = p;
//	}
//	T get()
//	{
//		return data;
//	}
//	node<T>* getNext()
//	{
//		return next;
//	}
//	node<T>* getPrev()
//	{
//		return prev;
//	}
//	void set(T d)
//	{
//		data = d;
//	}
//	void setPrev(node<T>* p)
//	{
//		prev = p;
//	}
//	void setNext(node<T>* n)
//	{
//		next = n;
//	}
//};
//
//template <typename T>
//class Queue 
//{
//	T* arr;
//	int top;
//	int capacity;
//
//public:
//	Queue(int size = 100)
//	{
//		capacity = size;
//		arr = new T[capacity];
//		top = 0;
//	}
//	~Queue()
//	{
//		delete[] arr;
//	}
//	bool isEmpty()
//	{
//		return top == 0;
//	}
//	bool isFull()
//	{
//		return top == capacity;
//	}
//	void push(T val)
//	{
//		if (isFull())
//			return;
//
//		arr[top++] = val;
//	}
//	T pop()
//	{
//		if (isEmpty())
//			return T();
//
//		return arr[--top];
//	}
//	T topval()
//	{
//		if (isEmpty())
//			return T();
//
//		return arr[top - 1];
//	}
//	int size()
//	{
//		return top;
//	}
//	void settop(int number)
//	{
//		top = number;
//	}
//};
//
//template <typename T>
//class doublylist
//{
//	int size;
//	node<T>* head;
//	node<T>* tail;
//	node<T>* cursorPos;
//
//public:
//	doublylist(node<T>* h = nullptr, node<T>* t = nullptr, T s = 0)
//	{
//		size = s;
//		head = h;
//		tail = cursorPos = t;
//	}
//	node<T>* getHead()
//	{
//		return head;
//	}
//	node<T>* getTail()
//	{
//		return tail;
//	}
//	node<T>* getCursor()
//	{
//		return cursorPos;
//	}
//	int getSize()
//	{
//		return size;
//	}
//	void setSize(int s)
//	{
//		size = s;
//	}
//	void setHead(node<T>* h)
//	{
//		head = h;
//	}
//	void setTail(node<T>* ta)
//	{
//		tail = ta;
//	}
//	void setCursor(node<T>* cur)
//	{ 
//		cursorPos = cur;
//	}
//
//	void insertMid(T data)
//	{
//		node<T>* newNode = new node<T>(data);
//
//		if (cursorPos == nullptr && size == 0)
//		{
//			insertEnd(data);
//		}
//
//		else if (cursorPos == nullptr )
//		{
//			newNode->setNext(head);
//			head->setPrev(newNode);
//			cursorPos = newNode;
//		}
//
//		else if (cursorPos == tail)
//		{
//			insertEnd(data);
//		}
//		else
//		{
//			node<T>* temp = cursorPos->getNext();
//
//			cursorPos->setNext(newNode);
//			newNode->setPrev(cursorPos);
//
//			newNode->setNext(temp);
//			temp->setPrev(newNode);
//			size++;
//
//			cursorPos = newNode;
//		}
//	}
//	void insertEnd(T data)
//	{
//		node<T>* newNode = new node<T>(data);
//
//		if (tail == nullptr)
//		{
//			tail = newNode;
//			head = newNode;
//		}
//		else
//		{
//			tail->setNext(newNode);
//			newNode->setPrev(tail);
//			tail = newNode;
//		}
//		cursorPos = tail;
//		size++;
//	}
//
//	node<T>* deleteNode()
//	{
//		if (size != 0 || cursorPos != nullptr)
//		{
//			node<T>* temp = cursorPos;
//
//			if (head == tail)
//			{
//				head = tail = cursorPos = nullptr;
//			}
//			else if (cursorPos == head && size > 1)
//			{
//				head = head->getNext();
//				head->setPrev(nullptr);
//				cursorPos = nullptr;
//			}
//			else if (cursorPos == tail)
//			{
//				tail = tail->getPrev();
//				tail->setNext(nullptr);
//				cursorPos = tail;
//			}
//			else
//			{
//				node<T>* prev = cursorPos->getPrev();
//				node<T>* next = cursorPos->getNext();
//
//				prev->setNext(next);
//				next->setPrev(prev);
//
//				cursorPos = prev;
//			}
//
//			size--;
//
//			return temp;
//		}	
//	}
//
//	void restore(Queue<node<char>*> &restoring_stack)
//	{
//		node<char>* newNode = restoring_stack.pop();
//
//		node<char>* next = newNode->getNext();
//		node<char>* prev = newNode->getPrev();
//		
//		if (next == nullptr && prev == nullptr)
//		{
//			head = tail = cursorPos = newNode;
//		}
//		else if (prev == nullptr)
//		{
//			newNode->setNext(head);
//			head->setPrev(newNode);
//			head = cursorPos = newNode;
//		}
//		else if (next == nullptr)
//		{
//			tail->setNext(newNode);
//			newNode->setPrev(tail);
//			tail = cursorPos = newNode;
//		}
//		else
//		{
//			prev->setNext(newNode);
//			newNode->setPrev(prev);
//
//			next->setPrev(newNode);
//			newNode->setNext(next);
//
//			cursorPos = newNode;
//		}
//		
//		size++;
//	}
//
//	void printSize()
//	{
//		cout << endl << "The size of the Document is: " << size << endl;
//	}
//	void frontPrint()
//	{
//		if (size == 0)
//			return;
//
//		cout << endl;
//		node<T>* temp = head;
//		bool once = true;
//		while (temp != nullptr)
//		{
//			if (cursorPos == nullptr && once)
//			{
//				cout << "\033[36m" << "|" << "\033[00m";
//				once = false;
//			}
//
//			if (temp == cursorPos && cursorPos != nullptr)
//				cout << "\033[91m";
//			cout << temp->get();
//			if (temp == cursorPos && cursorPos != nullptr)
//				cout << "\033[00m";
//
//			if (temp == cursorPos && cursorPos != nullptr)
//			{
//				cout << "\033[36m" << "|" << "\033[00m";
//				once = true;
//			}
//			temp = temp->getNext();
//		}
//	}
//};
//
//int notepadToFile(doublylist<char> &notepad,string filename)
//{
//	if (notepad.getSize() == 0)
//	{
//		std::ofstream file(filename, ios::trunc);
//
//		if (!file)
//		{
//			cout << "\n\n\n\n\n\n\n\n\t\t\t\t\t\tThe selected file is not opening!!!!\n\n\n";
//			return 0;
//		}
//		file.close();
//	}
//	else
//	{
//		std::ofstream file(filename, ios::trunc);
//
//		node<char>* temp = notepad.getHead();
//		while (temp != nullptr)
//		{
//			file << temp->get();
//			temp = temp->getNext();
//		}	
//
//		file.close();
//	}
//	return 1;
//}
//
//int fileToNotepad(doublylist<char>& notepad, string filename)
//{
//	ifstream file(filename);
//
//	if (!file)
//	{
//		cout << "\n\n\nThe file ( " << filename << " ) is not ready to copy file!!!!!\n\n\n";
//		return 1;
//	}
//
//	char ch;
//	while (file.get(ch))
//	{
//		notepad.insertEnd(ch);
//	}
//
//	file.close();
//	return 0;
//}
//
//int filecreator(ofstream &WorkingFile,int & numberofFiles, string* &namesOfFile, string & titleFileName)
//{
//	system("cls");
//	Title();
//
//	string name;
//	cout << "\n\n\n\n\n\n\t\t\t\t\t\tEnter a file name to create: ";
//	cin >> name;
//
//	name += ".txt";
//
//	for (int i = 0; i < numberofFiles; i++)
//	{
//		if (namesOfFile[i] == name)
//		{
//			return 1;
//		}
//	}
//
//	WorkingFile.open(name);
//	namesOfFile[numberofFiles++] = name;
//	titleFileName = name;
//	updateinfo(namesOfFile, numberofFiles);
//	return 0;
//}
//
//int saveAfile(doublylist<char>& notepad, string titleFileName)
//{
//	system("cls");
//	Title(titleFileName);
//	if ((notepadToFile(notepad, titleFileName)))
//	{
//		cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  The FILE is SAVED........\n\n";
//		cout << "\t\t\t\t\t\tPress any key to continue!!!!";
//		_getch();
//		return 1;
//	}
//	else return 0;
//}
//
//int main()
//{
//	// notepad related things
//	doublylist<char> notepad;
//	Queue<node<char>*> restoring_Stack;
//	ofstream WorkingFile;
//	bool isSave = true;
//	//
//	//  character entered by the user
//	char userinput;
//	//	if he wants to open a file or not
//	char fileChoice;
//	int userFilechoice = 0;
//
//	//files information related things
//	int numberofFiles = 0;
//	string* namesOfFile = loadFileinfo(numberofFiles);
//	bool isPresent = false;
//
//	//UI related
//	string titleFileName;
//
//	//SCREEN 1
//	Title();
//
//	cout << "\n\n\n\t\t\t\t\t\tCreate a Blank document: \n\n\t\t\t\t\t\t";
//	cout << "\033[92m" << "  Yes     " << "\033[00m" << "OR      " << "\033[91m" << "NO";
//	cout << "\033[00m" << "\n\n\t\t\t\t\t\t Enter you choice: " << "\033[36m";
//	cout << "\033[00m";
//	while (true)
//	{
//		fileChoice = _getch();
//
//		if (fileChoice == 'y' || fileChoice == 'Y' || fileChoice == 'n' || fileChoice == 'N')
//			break;
//	}
//
//	if (numberofFiles < 1 && fileChoice == 'n' || fileChoice == 'N')
//	{
//		cout << "\033[91m\n\n\n\n\t\t\t\t\t       There exists no file!!!!\n\n\n\t\t\t\t\t       ";
//		Sleep(1500);
//		cout << "\033[92mCreating a new file....\033[00m";
//		Sleep(2500);
//
//		while (true)
//		{
//			if (filecreator(WorkingFile, numberofFiles, namesOfFile, titleFileName))
//			{
//				cout << "\033[91m\n\n\n\n\n\n\t\t\t\t\t\t The file name already exists!!!\033[0m\n\n\t\t\t\t\t\tPress any key to continue!!!! : ";
//				_getch();
//				continue;
//			}
//			break;
//		}
//	}
//
//	//SCREEN 2
//	else if (fileChoice == 'n' || fileChoice == 'N')
//	{
//		system("cls");
//		Title();
//
//		cout << "\n\n\n\t\t\t\t\tEnter number to open a respective file: \n\n";
//		for (int i = 0; i < numberofFiles; i++)
//		{
//			cout << "\t\t\t\t\t\033[00m" << i + 1 << ")\033[93m  " << namesOfFile[i] << "\033[00m\n" << endl;
//		}
//		cout << "\t\t\t\t\tEnter option: " << "\033[36m";
//		userFilechoice = validValue(1, numberofFiles, "option");
//
//		titleFileName = namesOfFile[userFilechoice - 1];
//
//		isPresent = true;
//	}
//
//	//SCREEN 3
//	else
//	{
//		while (true)
//		{
//			if (filecreator(WorkingFile, numberofFiles, namesOfFile, titleFileName))
//			{
//				cout << "\033[91m\n\n\n\n\n\n\t\t\t\t\t\t The file name already exists!!!\033[0m\n\n\t\t\t\t\t\tPress any key to continue!!!! : ";
//				_getch();
//				continue;
//			}
//			break;
//		}
//	}
//
//	//SCREEN 4
//	system("cls");
//	Title();
//
//	cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  LOADING........";
//	Sleep(1500);
//
//	// IF the selected file is not present or deleted
//	if (!WorkingFile)
//	{
//		cout << "\n\n\n\n\n\n\n\t\t\t\t\t\t\tThe file \" " << titleFileName << " \" is not opening!!!!!\n\n\n\n\n\n\n\n\n\n\n";
//		return 0;
//	}
//
//	// copy existing file content into the notepad so it can be edited
//	if (isPresent)
//	{
//		fileToNotepad(notepad, titleFileName);
//	}
//
//	// loop that actually runs notepad
//	while (true)
//	{
//		// Main Notepad
//		system("cls");
//		Title(titleFileName);
//		notepad.frontPrint();
//		userinput = _getch();
//
//		//to save a file CTRL + S
//		if (userinput == 19)
//		{
//			if (saveAfile(notepad, titleFileName) == 0)
//			{
//				break;
//			}
//			isSave = true;
//			continue;
//		}
//
//		// test case to check the size of list
//		if (userinput == '#')
//		{
//			notepad.printSize();
//			_getch();
//			continue;
//		}
//
//		//ESC key
//		if (userinput == 27)
//		{
//			if (!isSave)
//			{
//				system("cls");
//				cout << "\n\n\n\n\n\n\n\t\t\t\tDo you really not want to save the file?";
//				while (true)
//				{
//					fileChoice = _getche();
//
//					if (fileChoice == 'y' || fileChoice == 'Y' || fileChoice == 'n' || fileChoice == 'N')
//						break;
//				}
//				if (fileChoice == 'y' || fileChoice == 'Y')
//				{
//					if (saveAfile(notepad, titleFileName) == 0)
//					{
//						break;
//					}
//				}
//			}
//
//			system("cls");
//			cout << "\n\n\n\n\n\n\n\t\t\t\t\tThanks for using the application!!!\n\n\n\t\t\t\t\t\t    GOOD BYE!!!\n\n\n\n\n\n\n\n\n\n\n";
//			break;
//		}
//
//		// ENTER key
//		if (userinput == '\r')
//			userinput = '\n';
//
//		// CTRL + Z
//		if (userinput == 26)
//		{
//			if (restoring_Stack.size() != 0)
//			{
//				notepad.restore(restoring_Stack);
//				system("cls");
//				notepad.frontPrint();
//			}
//			continue;
//		}
//
//		// BACKSPACE key
//		if (userinput == 8)
//		{
//			if (notepad.getCursor() != nullptr)
//			{
//				node<char>* newNode = notepad.deleteNode();
//				restoring_Stack.push(newNode);
//				system("cls");
//				notepad.frontPrint();
//			}
//			continue;
//		}
//		
//		// special condition to check any functional key is pressed ( ARROW KEYS )
//		if (userinput == 0 || userinput == 224 || userinput == -32)
//		{
//			userinput = _getch();
//
//			//left key 
//			if (userinput == 75)
//			{
//				if (notepad.getCursor() == nullptr)
//				{
//					continue;
//				}
//				else if (notepad.getSize() > 1 && notepad.getCursor() != notepad.getHead())
//				{
//					notepad.setCursor(notepad.getCursor()->getPrev());
//					system("cls");
//					notepad.frontPrint();
//				}
//				else if (notepad.getCursor() == notepad.getHead())
//				{
//					notepad.setCursor(nullptr);
//					system("cls");
//					notepad.frontPrint();
//				}
//				continue;
//			}
//
//			// right key 
//			if (userinput == 77)
//			{
//				if (notepad.getCursor() == nullptr)
//				{
//					notepad.setCursor(notepad.getHead());
//					system("cls");
//					notepad.frontPrint();
//					cout << flush;
//				}
//				else if (notepad.getSize() > 1 && notepad.getCursor() != notepad.getTail())
//				{
//					notepad.setCursor(notepad.getCursor()->getNext());
//					system("cls");
//					notepad.frontPrint();
//					cout << flush;
//				}
//				continue;
//			}
//
//			// if up and down key is pressed
//			if (userinput == 72 || userinput == 80)
//				continue;
//		}
//
//		restoring_Stack.settop(0);
//		isSave = false;
//		notepad.insertMid(userinput);
//	}
//
//	WorkingFile.close();
//}