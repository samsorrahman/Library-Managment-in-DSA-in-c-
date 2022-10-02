#include<iostream>
#include<string>
#include<conio.h>
using namespace std;
class library{
private:
	struct Node
	{
		int id;
		string name, author, publisher;
		Node* next_add;
	};
public:
	Node* head= NULL;
	void menu();
	void insert();
	void search();
	void update();
	void del();
	void sort();
	void show();
};
void library::menu()
{
p:
	system("cls");
	int choice;
	cout << "\n\n\t\t\t ======================================================";
	cout << "\n\n\t\t\t ================Library Management System =============";
	cout << "\n\n\t\t\t ======================================================";
	cout << "\n\n 1. Insert New Record";
	cout << "\n\n 2. Search Record";
	cout << "\n\n 3. Update Record";
	cout << "\n\n 4. Delete Record";
	cout << "\n\n 5. Show all Record";
	cout << "\n\n 6. Exit";
	cout << "\n\n Enter Your Choice :";
	cin >> choice;
	switch (choice)
	{
	case 1:
		insert();
		break;

	case 2:
		break;
		search();
	case 3:
		update();
		break;
	case 4:
		del();
		break;

	case 5:
		sort();
		show();
		break;
	case 6:
		exit(0);
		break;
	default:
		cout << "\n\n Invalid Choice Please Try again ....";
	}
	_getch();
	goto p;
}
void library::insert(){
	system("cls");
	cout << "\n\n\t\t\t ======================================================";
	cout << "\n\n\t\t\t ================Library Management System =============";
	cout << "\n\n\t\t\t ======================================================";
	Node *new_node = new Node;
	cout << "\n\n Book ID: ";
	cin >> new_node->id;
	cout << "\n\n Name :";
	cin>> new_node->name;
	cout << "\n\n Author Name: ";
	cin >> new_node->author;
	cout << "\n\n Publisher: ";
	cin >> new_node->publisher;

	new_node->next_add = NULL;
	if (head == NULL)
	{
		head = new_node;
	}
	else
	{
		Node *ptr = head;
		while (ptr!=NULL)
		{
			ptr = ptr->next_add;
		}
		ptr->next_add =  new_node;
	}
	cout << "\n\n New Book Inserted successfully ...";
}
 
// Search Function
void library::search()
{
	system("cls");
	int t_id, found=0;
	cout << "\n\n\t\t\t ======================================================";
	cout << "\n\n\t\t\t ================Library Management System =============";
	cout << "\n\n\t\t\t ======================================================";
	if (head == NULL)
	{
		cout << "\n\n Linke List is Empty ..";
	}
	else
	{
		cout << "\n\n Book ID ...";
		cin >> t_id;
		Node* ptr = head;
		while (ptr!=NULL)
		{
			if (t_id == ptr->id)
			{
				system("cls");
				cout << "\n\n\t\t\t ======================================================";
				cout << "\n\n\t\t\t ================Library Management System =============";
				cout << "\n\n\t\t\t ======================================================";
				cout << "\n\n Book ID : " << ptr->id;
				cout << "\n\n Book Name: " << ptr->name;
				cout << "\n\n Author Name: " << ptr->author;
				cout << "\n\n Publisher Name" << ptr->publisher;
				found++;
			}
			ptr = ptr->next_add;
		}
		if (found == 0)
		{
			cout << "\n\n Book Id is Invalid ..";
		}

	}
}

void library::update()
{
	system("cls");
	int t_id, found = 0;
	cout << "\n\n\t\t\t ======================================================";
	cout << "\n\n\t\t\t ================Library Management System =============";
	cout << "\n\n\t\t\t ======================================================";
	if (head == NULL)
	{
		cout << "\n\n Linke List is Empty ..";
	}
	else
	{
		cout << "\n\n Book ID ...";
		cin >> t_id;
		Node* ptr = head;
		while (ptr != NULL)
		{
			if (t_id == ptr->id)
			{
				system("cls");
				cout << "\n\n\t\t\t ======================================================";
				cout << "\n\n\t\t\t ================Library Management System =============";
				cout << "\n\n\t\t\t ======================================================";
				cout << "\n\n Book ID : " << endl;
				cin >> ptr->id;
				cout << "\n\n Book Name: " << endl;
				cin >> ptr->name;
				cout << "\n\n Author Name:" << endl;
				cin >> ptr->author;
				cout << "\n\n Publisher Name" << endl;
				cin >> ptr->publisher;
				found++;

				cout << "\n\n\t\t\t Book Updated Successfully " << endl;
			}
			ptr = ptr->next_add;
		}
		if (found == 0)
		{
			cout << "\n\n Book Id is Invalid ..";
		}

	}
}

void library::del()
{
	system("cls");
	int t_id, found = 0;
	cout << "\n\n\t\t\t ======================================================";
	cout << "\n\n\t\t\t ================Library Management System =============";
	cout << "\n\n\t\t\t ======================================================";
	if (head == NULL)
	{
		cout << "\n\n Linke List is Empty ..";
	}
	else
	{
		cout << "\n\n Book ID ...";
		cin >> t_id;
	
		if (t_id==head->id)
		{
			Node* ptr = head;
			head = head->next_add;
			delete ptr;
			cout << "Deleteed Successfully" << endl;
			found++;
		}
		else
		{
			Node* prev = head;
			Node*ptr = head;
			while (ptr != NULL)
			{
				if (t_id == ptr->id)
				{
					prev->next_add = ptr->next_add;
					delete ptr;
					cout << "\n\n Deleete Successfully";
					found++;
					break;
				}
				prev = ptr;
				ptr = ptr->next_add;
			}
		}
		if (found == 0)
		{
			cout << "\n\n book id is invalid"; 
		}
	}
}

void library::sort()
{
	
	if (head == NULL)
	{
		system("cls");

		cout << "\n\n\t\t\t ======================================================";
		cout << "\n\n\t\t\t ================Library Management System =============";
		cout << "\n\n\t\t\t ======================================================";
		cout << "\n\n Linked list is Empty" << endl;
		_getch();
		menu();
	}
	int count = 0, t_id;
	string t_name, t_author, t_publisher;
	Node* ptr = head;
	while (ptr!=NULL)
	{
		count++;
		ptr = ptr->next_add;
	}
	for (int i = 1; i <= count; i++)
	{
		Node* ptr = head;
		for (int j = 1; j < count; j++)
		{
			if (ptr->id> ptr->next_add->id)
			{
				// save data into temp var
				t_id = ptr->id;
				t_name = ptr->name;
				t_author = ptr->author;
				t_publisher = ptr->publisher;
				// save data into curent node
				ptr->id = ptr->next_add->id;
				ptr->name = ptr->next_add->name;
				ptr->author = ptr->next_add->author;
				ptr->publisher = ptr->next_add->publisher;

				// save data into next node
				ptr->next_add->id = t_id;
				ptr->next_add->name = t_name;
				ptr->next_add->author = t_author;
				ptr->next_add->publisher = t_publisher;
				
				 

			}
			ptr = ptr->next_add;
		}
	}
}
void library::show()
{
	system("cls");
	cout << "\n\n\t\t\t ======================================================";
	cout << "\n\n\t\t\t ================Library Management System =============";
	cout << "\n\n\t\t\t ======================================================";

	
	
		Node* ptr = head;
		while (ptr != NULL)
		{			
				cout << "\n\n Book ID : " << ptr->id;
				cout << "\n\n Book Name: " << ptr->name;
				cout << "\n\n Author Name: " << ptr->author;
				cout << "\n\n Publisher Name" << ptr->publisher;
				cout << "\n\n\n ================================================================";

				ptr = ptr->next_add;
		}
		

}

int main()
{


	
	library obj;
	obj.menu();
	_getch();
	return 0;
}