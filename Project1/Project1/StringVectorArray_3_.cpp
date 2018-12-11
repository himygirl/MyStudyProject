#include<iostream>
#include<fstream>
#include<cassert>
#include<string>

using namespace std;

//1.逐行读入
void readTxt01(string file)
{
	ifstream infile;
	infile.open(file.data());   //将文件流对象与文件连接起来。
	assert(infile.is_open()); //若失败，则输出错误消息，并终止程序运行


	string s;
	while (getline(infile,s)) 
	{
		cout << s << endl;
	}

	infile.close();   //关闭文件输入流

	system("pause");
}

//2.逐个字符读入（忽略空格与回车）
void readTest02(string file)
{

	ifstream infile;
	infile.open(file.data());   //将文件流对象与文件连接起来。
	assert(infile.is_open()); //若失败，则输出错误消息，并终止程序运行

	char c;
	while (!infile.eof())
	{
		infile >> c;
		cout << c << endl;
	}

	infile.close();
	system("pause");
}

//3.逐个字符读入（包括空格与回车）
void readTest03(string file)
{

	ifstream infile;
	infile.open(file.data());   //将文件流对象与文件连接起来。
	assert(infile.is_open()); //若失败，则输出错误消息，并终止程序运行

	char c;
	infile >> noskipws;
	while (!infile.eof())
	{
		infile >> c;
		cout << c << endl;
	}

	infile.close();  //关闭文件输入流
	system("pause");
}

void Mystring()
{

	string s8 = string(10,'c'); //拷贝初始化，s8的内容是cccccccccc
	string s2 = "Value";
	string s3("Value");

	s2.empty();
	
	std::cout << s2 <<"----"<< s3<< std::endl;

	system("pause");
}

int main()
{

	//Mystring();

	readTxt01("H:/云渲染接口.txt");   //注意斜杠
	//readTest02("H:/云渲染接口.txt");
	//readTest03("H:/云渲染接口.txt");
	return 0;
}