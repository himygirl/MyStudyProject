#include "MyClass1_5.h"
#include<iostream>
#include<string>


//����01
Sales_item::Sales_item()
{
	isbn = "0-201-70353-x";
	units_sold = 0;
	revenue = 0.0;
}
//���������������������ᱨ���޷��������ⲿ���� "public: __thiscall Sales_item::~Sales_item(void)" (??1Sales_item@@QAE@XZ)���÷����ں��� "void __cdecl `dynamic atexit destructor for 'temporary''(void)" (??__Ftemporary@@YAXXZ) �б�����
Sales_item::~Sales_item()
{
}


void Sales_item::cin()
{
	std::cin >> isbn;
	std::cin >> units_sold;
	std::cin >> revenue;

}

void Sales_item::cout()const
{
	std::cout << isbn << "\t";
	std::cout << units_sold << "\t";
	std::cout << revenue << endl;


}

Sales_item temporary;
Sales_item &Sales_item::sum(const Sales_item &item)
{
	if (isbn == item.isbn)
	{
		temporary.isbn = isbn;
		temporary.units_sold = units_sold + item.units_sold;
		temporary.revenue = revenue + item.revenue;
		return temporary;
	}

	std::cout << "Wrong Isbn ???" << std::endl;
				return temporary;

}

double Sales_item::avg_price()
{
	if (units_sold)
	{
		return revenue / units_sold;
	}
	else
	{
		return 0;
	}



}

const Sales_item Sales_item::operator+(Sales_item& Test)
{
	return Sales_item(isbn,units_sold+Test.units_sold,revenue+Test.revenue);



}

/*
int main()
{

	Sales_item book;
	std::cout << "Enter a Sales_item: " << std::endl;
	book.cin();
	book.cout();

	Sales_item book2;
	std::cout << "Enter anoter Sales_item: " << std::endl;
	book.cin();
	std::cout << "The sum of the same book is:\t";
	book.sum(book2).cout();

	std::cout << "The average price of the same book is:\t";
	std::cout << book.sum(book2).avg_price();
	std::cout << std::endl;

	Sales_item bookC;
	bookC = book + book2;  //�������
	 bookC.display();
	
	

	system("pause");
	return 0;

	//�������ݣ�0-205-70353-x  4   32       0-205-70353-x  6   60 
}
*/


/*

//���� 02
Sales_item::Sales_item() : units_sold(0), revenue(0.0)
{
}
Sales_item::~Sales_item()
{
}

std::istream& Sales_item::input(std::istream& in)
{
	double price;
	in >> isbn >> units_sold >> price;
	//�����Ƿ����ɹ�
	if (in)
		revenue = units_sold * price;
	else
	{
		//����ʧ�ܣ�������λΪĬ��״̬
		units_sold = 0;
		revenue = 0.0;
	}
	return in;
}

std::ostream& Sales_item::output(std::ostream& out) const
{
	out << isbn << "\t" << units_sold << "\t"
		<< revenue << "\t" << avg_price();
	return out;
}

double Sales_item::avg_price() const
{
	if (units_sold)
		return revenue / units_sold;
	else
		return 0;
}


int main()
{
	Sales_item item;
	//���벢���һ�齻��
	cout << "Enter some transactions(Ctr+Z to end):" << endl;
	while (item.input(cin))
	{
		cout << "The transaction readed is:" << endl;
		item.output(cout);
		cout << endl;
	}
	return 0;
}
*/