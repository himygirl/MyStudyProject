#include<iostream>
using namespace std;



/*
void MyIostreamTest()
{

	//std::cout << "Enter  two numbers:" << std::endl; //等价与下面两行
	std::cout << "Enter  two numbers:";
	std::cout << std::endl;

	int a = 0, b = 0;
	std::cin >> a >> b;

	std::cout << a << "+" << b << "is " << a + b << std::endl;

	system("pause");



	*
	*
	*
	*
	*
	*


}

void MyIostreamTest_04()
{
	std::cout << "Enter  two numbers:";
	std::cout << std::endl;

	int v1 = 0, v2 = 0;
	std::cin >> v1 >> v2;
	std::cout << "The sum of" << v1;
    std::cout << std::endl;

	system("pause");

}

void Myfor()
{
	int a = 0;

	for (int i = 0; i < 5; i++)
	{
		//a = a + i;
		std::cout << i << std::endl;
		//pritn  0 1 2 3 4
	}

	for (int i = 0; i < 5; ++i)
	{
		//a = a + i;
		std::cout << i << std::endl;
		//pritn  0 1 2 3 4
	}

	int b = 1;
	for (int i = 0; i < 5; ++i)
	{
		
		b++;
		std::cout << b << std::endl;
		//pritn  2 3 4 5 6
	}


	int c = 1;
	for (int i = 0; i < 5; ++i)
	{

		++c;
		std::cout << c << std::endl;
		//pritn  2 3 4 5 6
	}

	system("pause");
}

void myWhile()
{
	int sum = 0, val = 1;
	while (val<5)
	{
		std::cout <<"begin:"<< val << std::endl;
		// print 1 2 3 4 
		sum += val;
		++val;
		std::cout <<"end:" <<val << std::endl;
		// print 2 3 4 5 6
	}
	system("pause");
	
}

//
void MyTest()
{
	int MyTestsum = 0, val = 0;
	//当我们使用一个istream对象作为条件时，其效果是检查流的状态。如果流是有效的，即流未遇到错误，那么检测成功。当遇到文件结束符，
	//或遇到无效输入（例如读入的值不是一个整数）。istream对象的状态会变为无效。
	while (std::cin >> val)
	{
		MyTestsum += val;
		
	}
	//输入结束后，按CTRL + Z。这是文件结束符的方法。然后按Enter。才会输出。
	std::cout << MyTestsum << std::endl;

}
*/
void MyIf()
{
	int currVal = 0, val = 0;

	if (std::cin >>currVal)
	{
		int cnt = 1;
		while (std::cin >>val)
		{
			if (val==currVal)
			{
				++cnt;
			}
			else
			{
				std::cout << currVal << "  occurs  " << cnt << "  times  " << std::endl;
				currVal = val;
				cnt = 1;
			}	
		}

		int b = 4;
		std::cout << currVal << "  occurs  " << cnt << "  times  " << std::endl;
	}
	// 测试数组： 42 42 42 42 42 55 55 62 100 100 100
}

void test001()
{
	int a = 0;
	while (a<3)
	{
		a++;
	}

	int b = 2;


}



int main()
{
	//MyIostreamTest(); //输入输出流代码练习
	//MyIostreamTest_04();

	//Myfor();
	//myWhile();
	//MyTest();
	MyIf();
	//test001();




	system("pause");
	return 0;

}