#include<iostream>
#include<fstream>
#include<cassert>
#include<string>

using namespace std;

//1.���ж���
void readTxt01(string file)
{
	ifstream infile;
	infile.open(file.data());   //���ļ����������ļ�����������
	assert(infile.is_open()); //��ʧ�ܣ������������Ϣ������ֹ��������


	string s;
	while (getline(infile,s)) 
	{
		cout << s << endl;
	}

	infile.close();   //�ر��ļ�������

	system("pause");
}

//2.����ַ����루���Կո���س���
void readTest02(string file)
{

	ifstream infile;
	infile.open(file.data());   //���ļ����������ļ�����������
	assert(infile.is_open()); //��ʧ�ܣ������������Ϣ������ֹ��������

	char c;
	while (!infile.eof())
	{
		infile >> c;
		cout << c << endl;
	}

	infile.close();
	system("pause");
}

//3.����ַ����루�����ո���س���
void readTest03(string file)
{

	ifstream infile;
	infile.open(file.data());   //���ļ����������ļ�����������
	assert(infile.is_open()); //��ʧ�ܣ������������Ϣ������ֹ��������

	char c;
	infile >> noskipws;
	while (!infile.eof())
	{
		infile >> c;
		cout << c << endl;
	}

	infile.close();  //�ر��ļ�������
	system("pause");
}

void Mystring()
{

	string s8 = string(10,'c'); //������ʼ����s8��������cccccccccc
	string s2 = "Value";
	string s3("Value");

	s2.empty();
	
	std::cout << s2 <<"----"<< s3<< std::endl;

	system("pause");
}

int main()
{

	//Mystring();

	readTxt01("H:/����Ⱦ�ӿ�.txt");   //ע��б��
	//readTest02("H:/����Ⱦ�ӿ�.txt");
	//readTest03("H:/����Ⱦ�ӿ�.txt");
	return 0;
}