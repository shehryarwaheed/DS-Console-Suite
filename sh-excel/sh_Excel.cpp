//#include <SFML/Graphics.hpp> 
//#include <iostream>   
//#include <conio.h>  
//#include <Windows.h>
//using namespace std;
//using namespace sf;
//
//class node
//{
//	string nameofcell;
//	string data;
//	node* right;
//	node* left;
//	node* up;
//	node* down;
//public:
//	node(string d = 0)
//	{
//		data = d;
//		right = left = up = down = nullptr;
//	}
//	string get()
//	{
//		return data;
//	}
//	string getname()
//	{
//		return nameofcell;
//	}
//	node* getright()
//	{
//		return right;
//	}
//	node* getleft()
//	{
//		return left;
//	}
//	node* getup()
//	{
//		return up;
//	}
//	node* getdown()
//	{
//		return down;
//	}
//	void set(string d)
//	{
//		data = d;
//	}
//	void setleft(node* p)
//	{
//		left = p;
//	}
//	void setright(node* n)
//	{
//		right = n;
//	}
//	void setup(node* u)
//	{
//		up = u;
//	}
//	void setdown(node* d)
//	{
//		down = d;
//	}
//	void setnameofcell(string name)
//	{
//		nameofcell = name;
//	}
//};
//
//class doublylist
//{
//	int size;
//	node* head;
//	node* tail;
//
//	void creategriddata(int rows)
//	{
//		node* prevrownode = nullptr;
//		node* prevrowhead = nullptr;
//
//		for (int i = 0; i < rows; i++)
//		{
//			node* prevnode = nullptr;
//			for (int j = 0; j < rows; j++)
//			{
//				node* newnode = new node("\0");
//
//				if (j == 0)
//				{
//					prevrowhead = newnode;
//				}
//
//				if (i == 0 && j == 0)
//				{
//					head = tail = newnode;
//				}
//
//
//				if (prevnode != nullptr)
//				{
//					newnode->setleft(prevnode);
//					prevnode->setright(newnode);
//				}
//
//				prevnode = tail = newnode;
//
//				newnode->setup(prevrownode);
//				if (prevrownode != nullptr)
//				{
//					prevrownode->setdown(newnode);
//					prevrownode = prevrownode->getright();
//				}
//			}
//			prevrownode = prevrowhead;
//		}
//	}
//	void cellnames(int rows)
//	{
//		node* temp1 = head;
//		for (int i = 0; i < rows; i++)
//		{
//			node* temp2 = temp1;
//			for (int j = 0; j < rows; j++)
//			{
//				if (i == 0 && j == 0)
//				{
//					temp2->setnameofcell("Grid");
//				}
//				else if (i == 0)
//				{
//					string colname(1, 'A' + (j - 1));
//					temp2->setnameofcell(colname);
//				}
//				else if (j == 0)
//				{
//					string rowname = to_string(i);
//					temp2->setnameofcell(rowname);
//				}
//				else
//				{
//					string colname(1, 'A' + (j - 1));
//					string rowname = to_string(i);
//					temp2->setnameofcell(colname + rowname);
//				}
//				temp2 = temp2->getright();
//			}
//			temp1 = temp1->getdown();
//		}
//	}
//
//public:
//	doublylist(int r = 0)
//	{
//		size = r * r;
//		head = tail = nullptr;
//		creategriddata(r);
//		cellnames(r);
//	}
//	node* gethead()
//	{
//		return head;
//	}
//	node* gettail()
//	{
//		return tail;
//	}
//	int getsize()
//	{
//		return size;
//	}
//
//	string accessgrid_data(int r, int c)
//	{
//		string dataofnode;
//		node* temp = head;
//		for (int i = 0; i < r; i++)
//		{
//			temp = temp->getdown();
//		}
//
//		for (int j = 0; j < c; j++)
//		{
//			temp = temp->getright();
//		}
//
//		dataofnode = temp->get();
//		return dataofnode;
//	}
//	string getcell_name(int r, int c)
//	{
//		string dataofnode;
//		node* temp = head;
//		for (int i = 0; i < r; i++)
//		{
//			temp = temp->getdown();
//		}
//
//		for (int j = 0; j < c; j++)
//		{
//			temp = temp->getright();
//		}
//
//		dataofnode = temp->getname();
//		return dataofnode;
//	}
//	void setgrid_data(int r, int c, string dataofnode)
//	{
//		node* temp = head;
//		for (int i = 0; i < r; i++)
//		{
//			temp = temp->getdown();
//		}
//
//		for (int j = 0; j < c; j++)
//		{
//			temp = temp->getright();
//		}
//
//		temp->set(dataofnode);
//	}
//
//	void printsize()
//	{
//		cout << endl << "the size of the document is: " << size << endl;
//	}
//};
//
//string text_field(Font& font, string prevdata = "", string display = "data")
//{
//	char data[100] = "";
//	int len = 0;
//
//	for (int i = 0; prevdata[i] != '\0'; i++)
//	{
//		data[len++] = prevdata[i];
//	}
//
//	RenderWindow window(VideoMode(800, 300), "text_field");
//
//	Text data_field;
//	data_field.setFont(font);
//	data_field.setCharacterSize(50);
//	data_field.setFillColor(Color::White);
//	data_field.setPosition(100, 100);
//
//	while (window.isOpen())
//	{
//		Event event;
//
//		while (window.pollEvent(event))
//		{
//			if (event.type == Event::Closed)
//			{
//				window.close();
//				return string(data);
//			}
//
//			if (event.type == Event::TextEntered)
//			{
//				if (event.text.unicode == '\b' && len > 0)
//				{
//					len--;
//					data[len] = '\0';
//				}
//				else if (event.text.unicode == '\r')
//				{
//					if (len == 0)
//						data[len] = '\0';
//					return data;
//				}
//				else if ((event.text.unicode < 128) && len < 99)
//				{
//					data[len] = static_cast<char>(event.text.unicode);
//					len++;
//					data[len] = '\0';
//				}
//			}
//
//			data_field.setString("enter " + display + ":  " + string(data));
//		}
//
//		window.clear(Color::Black);
//		window.draw(data_field);
//		window.display();
//	}
//}
//
//void initializefonts(Font& font1, Font& font2)
//{
//	if (!font1.loadFromFile("font\\bbhsansbogle-regular.ttf"))
//		cout << "error loading font1!" << endl;
//	if (!font2.loadFromFile("font\\robotocondensed-regular.ttf"))
//		cout << "error loading font2!" << endl;
//}
//
//Sprite& initializebackground(RenderWindow& window)
//{
//	Texture* backtex = new Texture;
//	if (!backtex->loadFromFile("images\\back2.png"))
//		cout << "the back texture is not loading!!" << endl;
//
//	Sprite background;
//	background.setTexture(*backtex);
//	background.setScale(window.getSize().x / background.getGlobalBounds().width,
//		window.getSize().y / background.getGlobalBounds().height);
//	return background;
//}
//
//void initializecells(RectangleShape**& cells, doublylist& grid,
//	int rows, int cols,
//	float cells_starting_horizontal, float cells_starting_vertical,
//	float cellwidth, float cellsize, float gap,
//	Color verylightblue, Color lightblue)
//{
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols; j++)
//		{
//			if (i == 0 && j == 0)
//			{
//				grid.setgrid_data(i, j, "Grid");
//				cells[i][j].setFillColor(lightblue);
//			}
//			else if (i == 0)
//			{
//				grid.setgrid_data(i, j, string(1, 'A' + (j - 1)));
//				cells[i][j].setFillColor(verylightblue);
//			}
//			else if (j == 0)
//			{
//				grid.setgrid_data(i, j, to_string(i));
//				cells[i][j].setFillColor(verylightblue);
//			}
//
//			cells[i][j].setSize({ cellwidth - gap, cellsize - gap });
//			cells[i][j].setPosition(cells_starting_horizontal + j * cellwidth,
//				cells_starting_vertical + i * cellsize);
//			cells[i][j].setOutlineThickness(1);
//			cells[i][j].setOutlineColor(Color::Black);
//		}
//	}
//}
//
//void highlightselectedcells(RectangleShape**& cells, bool**& isselected, int rows, int cols, Color selectioncolor)
//{
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols; j++)
//		{
//			if (isselected[i][j])
//			{
//				cells[i][j].setFillColor(selectioncolor);
//				cells[i][j].setOutlineThickness(2);
//				cells[i][j].setOutlineColor(Color::Black);
//			}
//			else if (i == 0 || j == 0)
//			{
//				continue;
//			}
//			else
//			{
//				cells[i][j].setFillColor(Color::White);
//				cells[i][j].setOutlineThickness(2);
//				cells[i][j].setOutlineColor(Color::Black);
//			}
//		}
//	}
//}
//
//void renderall(RenderWindow& window, Sprite& background, Text& title_of_program, RectangleShape** cells,
//	Text& cell_data, doublylist& grid, int rows, int cols, float cellwidth, float cellsize,
//	float cells_starting_horizontal, float cells_starting_vertical, bool**& isselected, Color verylightyellow,
//	RectangleShape countcell, Text countcelldata, RectangleShape sumbar, Text sumcelldata,
//	RectangleShape avgbar, Text avgcelldata, bool nametime)
//{
//	window.clear();
//	window.draw(background);
//	window.draw(title_of_program);
//	window.draw(countcell);
//	window.draw(countcelldata);
//	window.draw(sumbar);
//	window.draw(sumcelldata);
//	window.draw(avgbar);
//	window.draw(avgcelldata);
//
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols; j++)
//		{
//			if (nametime)
//				cell_data.setString(grid.getcell_name(i, j));
//			else
//				cell_data.setString(grid.accessgrid_data(i, j));
//			cell_data.setPosition(10 + cells_starting_horizontal + j * cellwidth,
//				cells_starting_vertical + i * cellsize);
//			window.draw(cells[i][j]);
//			window.draw(cell_data);
//		}
//	}
//	highlightselectedcells(cells, isselected, rows, cols, verylightyellow);
//	window.display();
//}
//
//void clearselection(bool**& isselected, int rows, int cols)
//{
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols; j++)
//		{
//			isselected[i][j] = false;
//		}
//	}
//}
//
//bool stringtoint(string& str, int& result)
//{
//	if (str.empty())
//	{
//		str = "0";
//		return false;
//	}
//
//	bool isnegative = false;
//	int startindex = 0;
//
//	if (str[0] == '-')
//	{
//		isnegative = true;
//		startindex = 1;
//		if (str.length() == 1)
//			return false;
//	}
//
//	for (int i = startindex; i < str.length(); i++)
//	{
//		if (!isdigit(str[i]))
//			return false;
//	}
//
//	result = stoi(str);
//	return true;
//}
//
//void sumandavg(bool**& isselected, int& sum, int& avg, doublylist& grid, int rows, int cols)
//{
//	sum = avg = 0;
//	int count = 0;
//	bool isnum = false;
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols; j++)
//		{
//			if (isselected[i][j])
//			{
//				int number = 0;
//				string parameter = grid.accessgrid_data(i, j);
//				isnum = stringtoint(parameter, number);
//				if (!isnum)
//				{
//					sum = avg = 0;
//					return;
//				}
//				sum += number;
//				count++;
//			}
//		}
//	}
//	avg = sum / count;
//}
//
//void update_data(bool**& isselected, string node_data, doublylist& grid, int rows, int cols)
//{
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols; j++)
//		{
//			if (isselected[i][j])
//			{
//				cout << "updated for [" << i << "][" << j << "] \n";
//				grid.setgrid_data(i, j, node_data);
//			}
//		}
//	}
//}
//
//void cellcountvalue(bool** isselected, int& count, int rows, int cols)
//{
//	count = 0;
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols; j++)
//		{
//			if (isselected[i][j])
//				count++;
//		}
//	}
//}
//
//void touppercase(string& word)
//{
//	for (int i = 0; word[i] != '\0'; i++)
//	{
//		if (word[i] >= 97 && word[i] <= 122)
//		{
//			word[i] -= 32;
//		}
//	}
//}
//
//void select_cells_by_name(string names, bool**& isselected, int rows, int cols, bool& multi_selected)
//{
//	if (names == "")
//	{
//		multi_selected = false;
//		return;
//	}
//
//	names += ',';
//	touppercase(names);
//	string temp;
//
//	for (int i = 0; names[i] != '\0'; i++)
//	{
//		if (names[i] == ',')
//		{
//			int letter = (temp[0] - 'A') + 1;
//			int number = temp[1] - 48;
//			if (cols <= letter || rows <= number)
//			{
//				multi_selected = false;
//				return;
//			}
//			temp = "";
//			isselected[number][letter] = true;
//			continue;
//		}
//		temp += names[i];
//	}
//}
//
//int main()
//{
//	int rows;
//	int cols;
//	rows = cols = 8;
//	float cellsize = 70.f;
//	float cellwidth = 120.f;
//	float cellheight = cellsize - 1;
//	float cells_starting_horizontal = 0;
//	float cells_starting_vertical = 300.f;
//	float gap = 2.f;
//	bool nametime = false;
//	bool multi_selected = false;
//
//	float countcellwidth = (cellwidth - gap) * 2;
//
//	int counter = 16 - rows;
//	for (int i = 0; i < counter / 2; i++)
//		cells_starting_horizontal += 120.f;
//
//	Clock clickclock;
//	bool firstclick = false;
//	float doubleclickthreshold = 0.3f;
//
//	RenderWindow window(VideoMode(1920, 1080), "sh excel");
//
//	//************************ fonts ************************
//	Font font1, font2;
//	initializefonts(font1, font2);
//
//	//************************ text *************************
//	Text title_of_program;
//	title_of_program.setFont(font1);
//	title_of_program.setFillColor(Color::White);
//	title_of_program.setLetterSpacing(1);
//	title_of_program.setCharacterSize(120);
//	title_of_program.setScale(1, 1);
//	title_of_program.setPosition(770.f, 30.f);
//	title_of_program.setString("sh excel");
//
//	Text cell_data;
//	cell_data.setFont(font2);
//	cell_data.setFillColor(Color::Black);
//
//	Text countcelldata;
//	countcelldata.setFont(font1);
//	countcelldata.setFillColor(Color::Black);
//	countcelldata.setPosition(7 + cells_starting_horizontal, 210.f);
//
//	Text sumcelldata;
//	sumcelldata.setFont(font1);
//	sumcelldata.setFillColor(Color::Black);
//	sumcelldata.setPosition(140 + countcellwidth + cells_starting_horizontal, 210.f);
//	int newsum = 0;
//
//	Text avgcelldata;
//	avgcelldata.setFont(font1);
//	avgcelldata.setFillColor(Color::Black);
//	avgcelldata.setPosition(260 + (countcellwidth * 2) + cells_starting_horizontal, 210.f);
//	int newavg = 0;
//
//	//************************ background *******************
//	Sprite background = initializebackground(window);
//
//	//************************ colors ************************
//	Color verylightyellow(255, 255, 230);
//	Color lightyellow(245, 245, 200);
//	Color gray(128, 128, 128);
//	Color verylightblue(220, 240, 255);
//	Color lightblue(190, 220, 255);
//	Color verylightgreen(200, 255, 200);
//
//	//*********************** selected count cell **********************
//	RectangleShape countcell;
//	countcell.setSize({ countcellwidth, cellsize - 10 });
//	countcell.setOutlineThickness(2);
//	countcell.setOutlineColor(Color::Black);
//	countcell.setPosition(cells_starting_horizontal, 200.f);
//	countcell.setFillColor(Color::White);
//	int count = 0;
//
//	//************************** sum bar ***************************
//	RectangleShape sumbar;
//	sumbar.setSize({ countcellwidth, cellsize - 10 });
//	sumbar.setOutlineColor(Color::Black);
//	sumbar.setOutlineThickness(2);
//	sumbar.setFillColor(Color::White);
//	sumbar.setPosition(130 + countcellwidth + cells_starting_horizontal, 200.f);
//
//	//************************** average bar ***************************
//	RectangleShape avgbar;
//	avgbar.setSize({ countcellwidth, cellsize - 10 });
//	avgbar.setOutlineColor(Color::Black);
//	avgbar.setOutlineThickness(2);
//	avgbar.setFillColor(Color::White);
//	avgbar.setPosition(250 + (countcellwidth * 2) + cells_starting_horizontal, 200.f);
//
//	//*********************** data grid **********************
//	doublylist grid(rows);
//
//	bool** isselected = new bool* [rows];
//	for (int i = 0; i < rows; i++)
//	{
//		isselected[i] = new bool[cols];
//
//		for (int j = 0; j < cols; j++)
//			isselected[i][j] = false;
//	}
//
//	RectangleShape** cells = new RectangleShape * [rows];
//	for (int i = 0; i < rows; i++)
//		cells[i] = new RectangleShape[cols];
//
//	initializecells(cells, grid, rows, cols, cells_starting_horizontal,
//		cells_starting_vertical, cellwidth, cellsize, gap,
//		verylightblue, lightblue);
//
//	int selectedrow = 1, selectedcol = 1;
//	isselected[selectedrow][selectedcol] = true;
//
//	//*********************** main loop **********************
//	while (window.isOpen())
//	{
//		Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == Event::Closed)
//				window.close();
//
//			//----------- keyboard ------------
//			if (event.type == Event::KeyPressed && !(Keyboard::isKeyPressed(Keyboard::LControl) || Keyboard::isKeyPressed(Keyboard::RControl)))
//			{
//				bool altpressed = Keyboard::isKeyPressed(Keyboard::LAlt) || Keyboard::isKeyPressed(Keyboard::RAlt);
//				bool shiftpressed = Keyboard::isKeyPressed(Keyboard::LShift) || Keyboard::isKeyPressed(Keyboard::RShift);
//
//				if (!shiftpressed && !(event.key.code == Keyboard::Enter))
//				{
//					clearselection(isselected, rows, cols);
//				}
//
//				if (event.key.code == Keyboard::Right && selectedcol < cols - 1)
//					selectedcol++;
//				else if (event.key.code == Keyboard::Left && selectedcol > 1)
//					selectedcol--;
//				else if (event.key.code == Keyboard::Down && selectedrow < rows - 1)
//					selectedrow++;
//				else if (event.key.code == Keyboard::Up && selectedrow > 1)
//					selectedrow--;
//
//				if (altpressed && event.key.code == Keyboard::F)
//				{
//					nametime ? nametime = false : nametime = true;
//				}
//
//				if (!multi_selected)
//				{
//					isselected[selectedrow][selectedcol] = true;
//				}
//
//				if (altpressed && event.key.code == Keyboard::N)
//				{
//					multi_selected = true;
//					clearselection(isselected, rows, cols);
//					string cells_selection = text_field(font1, "", "names to select cell");
//					select_cells_by_name(cells_selection, isselected, rows, cols, multi_selected);
//					if (!multi_selected)
//						clearselection(isselected, rows, cols);
//						isselected[selectedrow][selectedcol] = true;
//				}
//
//				if (event.key.code == Keyboard::Enter)
//				{
//					string node_data;
//					if (multi_selected)
//						node_data = text_field(font1);
//					else
//						node_data = text_field(font1, grid.accessgrid_data(selectedrow, selectedcol));
//					update_data(isselected, node_data, grid, rows, cols);
//					multi_selected = false;
//				}
//			}
//
//			//----------- mouse ---------------
//			if ((event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
//				&& !(Keyboard::isKeyPressed(Keyboard::LShift) || Keyboard::isKeyPressed(Keyboard::RShift)))
//			{
//				int mousex = event.mouseButton.x;
//				int mousey = event.mouseButton.y;
//
//				int clickedrow = (mousey - cells_starting_vertical) / cellheight;
//				int clickedcol = (mousex - cells_starting_horizontal) / cellwidth;
//
//				if (clickedrow >= 1 && clickedrow < rows && clickedcol >= 1 && clickedcol < cols)
//				{
//					bool ctrlpressed = Keyboard::isKeyPressed(Keyboard::LControl) || Keyboard::isKeyPressed(Keyboard::RControl);
//
//					if (!ctrlpressed)
//					{
//						clearselection(isselected, rows, cols);
//						isselected[clickedrow][clickedcol] = true;
//					}
//					else
//					{
//						isselected[clickedrow][clickedcol] = !isselected[clickedrow][clickedcol];
//					}
//
//					selectedrow = clickedrow;
//					selectedcol = clickedcol;
//
//					float timesincelastclick = clickclock.getElapsedTime().asSeconds();
//
//					if (timesincelastclick < doubleclickthreshold)
//					{
//						string node_data = text_field(font1, grid.accessgrid_data(selectedrow, selectedcol));
//						update_data(isselected, node_data, grid, rows, cols);
//						firstclick = false;
//					}
//					else
//					{
//						firstclick = true;
//					}
//					clickclock.restart();
//				}
//			}
//		}
//
//		sumandavg(isselected, newsum, newavg, grid, rows, cols);
//
//		cellcountvalue(isselected, count, rows, cols);
//		countcelldata.setString("selected cells: " + to_string(count));
//
//		sumcelldata.setString("sum:  " + to_string(newsum));
//		avgcelldata.setString("avg:  " + to_string(newavg));
//
//		renderall(window, background, title_of_program, cells, cell_data, grid, rows,
//			cols, cellwidth, cellsize, cells_starting_horizontal, cells_starting_vertical,
//			isselected, verylightyellow, countcell, countcelldata, sumbar, sumcelldata, avgbar,
//			avgcelldata, nametime);
//	}
//}