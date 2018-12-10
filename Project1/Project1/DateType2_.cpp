
#include<iostream>

using namespace std;

void Date01()
{
	int a = -1;
	int b = 1;

	int a_01 = -1;
	unsigned b_01 = 1;

	int c = a * b;
	int c_01 = a_01 * b_01;  //这个结果须视在当前机器上int所占位数而定。书中的环境下是4294967295   ？？？

	std::cout << "c------" << c << "c_01-------" << c_01 << std::endl;
	system("pause");

}

void dateType02()
{
	unsigned u = 10, u2 = 42;
	std::cout << u2 - u << std::endl; //u2-u =32.     print  32
	std::cout << u - u2 << std::endl; //u-u2 =-32.    print 4294967264

	/*
	在我们现实生活中，10-42=-32，但是在C++里面并不是这样。得到-32后时int型，要把它再放入unsigned型，则必须取其模。

取模过程上一篇笔记中已经有记录：原码—反码—补码。

所以，先把32化成二进制，然后在符号位上添上1（int依旧占32位），得到

所以可知-32的二进制为     ：10000000000000000000000000100000；

然后符号位不变，取得反码：11111111111111111111111111011111；

最后在末尾加1取得补码     ：11111111111111111111111111100000；

然后输出时化为十进制，便得到输出的结果
	*/
	int i = 10, i2 = 42;
	std::cout << i2 - i << std::endl;  //i2-i = 32    print 32
	std::cout << i - i2 << std::endl;  //i -i2 = -32   print -32
	std::cout << i - u << std::endl;   //i-u  = 0   print 0
	std::cout << u - i << std::endl;   //u-i  = 0   print 0

	system("pause");
}

void dateType03()
{
	/*
	！！！！ 建议初始化每一个内置类型的变量
	用花括号来初始化的形式， 被称为列表初始化。
	这种形式的特点：如果我们使用列表初始化且初始值，存在丢失信息的风险，则编辑器将报错。
	
	*/
	int units_sold_01 = 0;
	int units_sold_02 = { 0 };
	int units_sold_03{ 0 };
	int units_sold_04(0);
}




void dateType04()
{
	//2.2.3 节练习。

	int _; //合法
	
	double Double = 3.14; //合法
}


//2.2.4节练习      练习2.13
int i_001 = 42;

void dateType05()
{
	int i_001 = 100; //新建局部变量 i_001，覆盖了全局变量 i_001
	int j_001 = i_001;

	std::cout << j_001 << std::endl;
	system("pause");
}

//2.2.4节练习      练习2.14
void dateType06()
{
	int i = 100, sum = 0;
	for (int i = 0; i !=10; i++)
	{
		sum += i;
	}

	std::cout << i << "     " << sum << std::endl; //显示访问i变量会访问到全局变量上，因为for循环里的i，是局部变量。这里离开了局部，所以访问的是全局的变量 i=100

	system("pause");
}


//！！！！！引用必须被初始化。引用只能绑定在对象上。
void dateType07()
{
	// int &refVal; //报错：引用必须被初始化。
  //	int &refVal02 = 10;  //报错，引用类型的初始值必须是一个对象。

	int i_07 = 1024;
	int &r_07 = i_07; //引用只能绑定在对象上
}


//2.3.1节练习    练习2.16
void dateType08()
{
	int i = 0, &r1 = i;
	double d = 0, &r2 = d;

	r2 = 3.14159;
	r2 = r1;
	i = r2;
	r1 = d;

}

//2.3.1节练习    练习2.17
void dateType09()
{
	int i, &ri = i;
	i = 5; 
	ri = 10;
	std::cout << i << "   " << ri << std::endl; //print 10   10 

	system("pause");

}

void dateType10()
{
	int ival = 42;
	int *p = &ival;  //取地址符（操作符&）

	// & * p =&ival; //这是非法的。因为引用不是对象，没有实际地址，所以不能定义指向引用的指针。
	std::cout << p << std::endl;
	system("pause");
}

void dateType11()
{
	/*
	指针的值（即地址）应属下列4种状态之一：
	1.指向一个对象；
	2.指向紧邻对象所占空间的下一个位置；
	3.空指针，意味着指针没有指向任何对象；
	4.无效指针，也就是上述情况之外的其他值；
	
	
	*/
	double dval;
	double *pd = &dval;
	double *pd2 = pd;

	//int *pi = pd;  //错误：指针pi的类型和pd的类型不匹配。
	//pi = &dval;   //错误：试图把double型对象的地址，赋给int型指针。


}

//指针
void dateType12()
{
	int ival = 42;
	int *p = &ival;


	std::cout << "p的地址-----" << p << std::endl;
	std::cout <<"p的对象--------"<< *p<<std::endl;   //由符号*得到指针p 所指的对象，输出42.
	/*
	&出现在表达式中，是一个取地址。
	*出现在表达式中，是一个解引用符。

*/
	//建议：初始化所有指针
	//在新标准下，现在c++程序最好使用nullptr，同时尽量避免使用NULL；
	//生成空指针的方法：
	int *p1 = nullptr;
	int *p2 = 0;
	int *p3 = NULL;
	std::cout << "p2的地址-----" << p2 << std::endl;

	/*
	只要指针拥有一个合法值，就能将它用在条件表达式中。如果指针的值是0，条件取false，任何非零的指针对应的条件值都是true。

	*/

	//!!! 把int变量直接赋给指针是错误的操作，即使int变量的值恰好等于0也不行。
	system("pause");
}

// void*  是一种特殊的指针类型，可用于存放任意对象的地址。一个void* 存放着一个地址。不同的是：我们对该地址中到底是个什么类型的对象并不了解。
void dateType13()
{
	double obj = 3.14, *pd = &obj;
	void *pv = &obj; //obj可以是任意类型的对象
	pv = pd;              //pv可以存放任意类型的指针。

}

//2.3.2节练习。    练习2.21
void dateType14()
{
	int i = 0;
//	double* dp = &i; // 非法定义，类型不一致
// int *ip = i; //非法定义，没有取地址操作符
	int *p = &i;  //合法定义。 &取地址符。
	
}
//复合类型的声明
void dateType15()
{
	int i = 1024, *p = &i, &r = i;    //i 是一个int型的数，p是一个int型指针，r是一个int型引用。
	int *p1，p2;    //p1是指向int的指针，p2是int。*是修饰符。所以一起定义的时候。*p2. 这种形式着重强调变量具有的复合类型。

	int* p3; //这种形式着重强调本次声明定义了一种复合类型。
	
}

void dateType16()
{
	int i = 30;
	int *p = &i;
	int  *p_02 = p;

	//最简单的方法是从右向左阅读r的定义。里变量名最近的符号（此例种是&r的符号&）对变量的类型有最直接的的影响，因此r是应该引用。声明符的其余部分可以去顶r引用的类型是什么。
	int*& r = p; //r是一个对指针p的引用。！！！！！！！！  个人理解：int* & 是指针的引用。

	int *rr = r;
	std::cout << "p--------" << p << "    " << "p_02------" << p_02 << std::endl;

	std::cout << "rr--------" << r << std::endl;
	system("pause");
}

//如果没有 main方法，会报：fatal error LNK1561: 必须定义入口点 这个错误
int main() 
{
	//Date01(); 

	//dateType02();
	//dateType05();
	//dateType06();

	//dateType09();
	//dateType10();
	//dateType12();

	dateType16();
	return 0;
}

