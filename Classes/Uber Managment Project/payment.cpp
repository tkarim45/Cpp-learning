#define _CRTDBG_MAP_ALLOC
#include"payment.h"


payment::payment():cash(0),type(""),card_number("")
{

}
payment::payment(string card_number, string type)
{
	this->card_number = card_number;
	this->type = type;
}
payment::payment(const payment& p)
{
	card_number = p.card_number;
	type = p.type;
	cash = p.cash;
}
string payment::get_card_number()
{
	return card_number;
}
void payment::set_card_number(string num)
{
	card_number = num;
}

ostream& operator<<(ostream& out, const payment& p)
{
	if (p.type == "card")
	{
		cout << p.card_number << "," << p.type << endl;
	}
	else if (p.type == "cash")
	{
		out << p.cash << "," << p.type << endl;
	}
	return out;
}
payment::payment(double cash, string type)
{
	this->cash = cash;
	this->type = type;
}