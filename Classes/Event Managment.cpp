#include<iostream>
using namespace std;
class Event
{
private:
	char* event_name;
	char event_time[9];
	char* event_venue;
	char event_date[11];

public:
	Event();

	Event(char event_name[20], char event_venue[50], char event_date[11], char event_time[9]);

	char* getString(int maxlength);

	char* get_event_name();
	void set_event_name();

	char* get_event_venue();
	void set_event_venue();

	char* get_event_date();
	void set_event_date();

	char* get_event_time();
	void set_event_time();

	void UserInput();

	void print();

	~Event();
};
char* Event::getString(int maxlength)
{
	//used this code from assignment given by mam
	char* temp = new char[maxlength];
	int size = 0;

	cin.getline(temp, maxlength);

	for (int i = 0; temp[i] != '\0'; i++)
	{
		size++;
	}

	char* new_array = new char[size + 1];

	for (int i = 0; i < size + 1; i++)
	{
		new_array[i] = temp[i];
	}

	delete[] temp;
	temp = new_array;
	return new_array;
}
Event::Event()
{
	event_name = new char[5]();
	event_venue = new char[5]();

	for (int i = 0; i < 11; i++)
		event_date[i] = '\0';

	for (int i = 0; i < 9; i++)
		event_time[i] = '\0';

	cout << "Default Constructor Called" << endl;
}

Event::Event(char event_name[20], char event_venue[50], char event_date[11], char event_time[9])
{

	int i = 0;
	while (event_name)
		i++;
	i++;
	this->event_name = new char[i]();
	i = 0;
	while (event_name)
	{
		this->event_name[i] = event_name[i++];
	}

	i = 0;
	while (event_venue)
	{
		i++;
	}
	i++;
	this->event_venue = new char[i]();
	i = 0;
	while (event_venue)
	{
		this->event_venue[i] = event_venue[i++];
	}
	i = 0;
	while (event_date)
	{
		this->event_date[i] = event_date[i++];
	}
	i = 0;
	while (event_time)
	{
		this->event_time[i] = event_time[i++];
	}

	cout << "Overloaed Function Called" << endl;

}

char* Event::get_event_name()
{

	return event_name;
}

char* Event::get_event_venue()
{
	return event_venue;
}

char* Event::get_event_date()
{

	return event_date;
}

char* Event::get_event_time()
{
	return event_time;
}

void Event::set_event_name()
{
	delete[] event_name;

	cout << "please enter Event Name: ";

	event_name = getString(20);

}

void Event::set_event_venue()
{
	delete[] event_venue;

	cout << "please enter Event Venue: ";
	event_venue = getString(50);

}

void Event::set_event_date()
{
	cout << "please enter the date: ";
	cin.getline(event_date, 11);
}

void Event::set_event_time()
{
	cout << "please enter the time: ";
	cin.getline(event_time, 9);
}

void Event::UserInput()
{
	set_event_name();
	set_event_venue();
	set_event_date();
	set_event_time();
}

void Event::print()
{
	cout << "Event Name : " << event_name << endl;
	cout << "Event Venue : " << event_venue << endl;
	cout << "Event Date : " << event_date << endl;
	cout << "Event Time : " << event_time << endl;
}

Event::~Event()
{
	//delete[] event_name;
	//delete[] event_venue;
}

int main()
{
	char name[20] = { "OPP-LAB 5" };
	char venue[50] = { "Google Classroom" };
	char date[11] = { "18-04-2121" };
	char time[9] = { "02:00 PM" };

	Event E1(name, venue, date, time);

	E1.print();
	E1.UserInput();
	E1.print();
	//E1.get_event_date();
	//E1.get_event_name();
	//E1.get_event_time();
	//E1.get_event_venue();
	system("pause");
	return 0;
}