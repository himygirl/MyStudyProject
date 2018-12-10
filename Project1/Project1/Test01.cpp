
//包含来自标准库的头文件时，也应该用<> 包围头文件名。对于不属于标准库的头文件，则用“”包围。

//网上解释如下：
//include<XX.h>表示在标准库里面找(不用加绝对路径)
//include"..\XX.h"表示在指定文件中找(需要加路径(绝对或相对都行)
#include<iostream>

//命名空间可以帮助我们避免不经意的名字定义冲突，以及使用库中相同名字导致的冲突。
//标准库定义的所有名字都再命名空间std中。
using namespace std;



/*
void MyIostreamTest()
{

	//std::cout << "Enter  two numbers:" << std::endl; //等价与下面两行
	std::cout << "Enter  two numbers:";
	std::cout << std::endl;

	int a = 0, b = 0;
	//cin是istream类型对象。这个对象也被称为 标准输入。
	std::cin >> a >> b;

	//cout 是ostream类型的对象，此对象也被称为  标准输出
	//endl， 这是一个被称为 操纵符  的特殊字值。  写入endl的效果是结束当前行，并将与设备关联的缓冲区（buffer）中的内容刷到设备中。
	//缓冲刷新操作可以保证到目前为止程序所产生的所有输出都真正写入输出流中，而不是仅停留再内存中等待写入流。
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

void MyIf()
{
	int currVal = 0, val = 0;

	//if 只是判断第一个数为有效值
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
		std::cout << currVal << "  occurs  " << cnt << "  times  " << std::endl; //因为上面的语句，走不了else的情况。
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
*/