#include <string>
#include <iostream>
#include <vector>

using namespace std;

/*
局部静态对象：在程序的执行路径第一次经过对象定义语句时初始化，并且指导程序终止才被销毁，
在此期间即使对象所在的函数结束执行也不会对它有影响。

*/
size_t count_calls()
{
	static size_t ctr = 0; // 调用结束后。此值仍然有效
	return ++ctr;
}

void Test_6_1_1()
{
		for (size_t i=0; i!= 10; ++i)
		{
			cout << count_calls() << endl;
		}

		system("pause");
}

//拷贝大的类类型对象或者容器对象比较低效，甚至有的类类型（包括IO类型在内）根本就不支持拷贝操作。
//当函数无须修改引用形参的值时，最好使用常量引用。
bool Test_6_2_2(const string &s1,const string &s2)
{
	return s1.size() < s2.size();
}

void test( string& a)
{
}

void test02(const string& b)
{

}
void test03()
{
	const	string b;
//	test(b); //错误，test只能接受普通string，不接受const string

	 //string c  =const_cast<string>(b); //错误：const_cast只是改变运算对象的底层const

	test02(b);
}

void test6_2_4()
{
	

	/*
	//尽管形式不同，但这三个print函数是等价的
	//每个函数都有一个const int*类型的形参。
	void print(const int*);
	void print(const int[]);			 //可以看出来，函数的意图是作用于一个数组
	void print(cosnt int[10]);		//这里的维度表示我们期望数组含有多少个元素，实际不一定。
	
	int i =0, j[2] ={0,1};
	print(&i);		//正确：&i的类型是int*
	print(j);			//正确：j转换成int*并指向j[0]

	//和其他使用数组的代码一样，以数组作为形参的函数也必须确保使用数组时不会越界。
	*/

}

/*
c++ 语言运行将变量定义成数组的引用，基于同样的道理，形参也可以是数组的引用。
此时，引用形参绑定到对应的实参上，也就是绑定到数组上：
*/

//正确：形参是数组的引用，维度是类型的一部分
void test6_2_5(int (&arr)[10])
{
	for (auto elem:arr)
	{
		cout << elem << endl;
	}
}
/*
& arr两端的括号必不可少
		f(int &arr[10])			//错误：将arr声明成了引用的数组
		f(int (&arr)[10])		//正确:arr是具有10个整数的整型数组的引用
*/

void test_6_24(const int (&ia)[10]) //入参如果这样，就是不对的(const int ia[10])，以传值的方式转递数组，是错误的。
{
	//sizeof(ia)/sizeof(ia[0])  获取到数组的元素个数
	cout << "sizeof(ia)     " << sizeof(ia)/sizeof(ia[0])<< endl;
	for (int i = 0; i<sizeof(ia);++i)
	{
		cout <<ia[i] << endl;
	}
	system("pause");
}

//含有可变形参的函数
/*
1.如果所有的实参类型相同，可以传递一个名为initializer_list的标准库类型；
2.如果实参的类型不同，我们可以编写一种特殊的函数，也就是所谓的可变参数模板
3.c++还有一种特殊的形参类型（即省略符），可以用它传递可变数量的实参。不过需要注意的是：这种功能一般只用于与c函数交互的接口程序。


//initializer_list 形参：initializer_list是一种标准库类型（模板类型），用于表示某种特定类型的值的数组。
//initializer_list对象中的元素永远是常量值，我们无法改变initializer_list对象中元素的值


initializer_list<T> lst; //默认初始化； T类型元素的空列表
initializer_list<T> lst{a,b,c...}; //lst的元素数量和初始值一样多；lst的元素是对应初始值的副本；列表中的元素是const

lst2(lst)   
lst2 = lst  //拷贝或赋值一个initializer_list对象不会拷贝列表中的元素；拷贝后，原始列表和副本共享元素

lst.size()   //列表中的元素数量
lst.begin()   //返回指向lst中的首元素的指针
lst.end()		//返回指向lst中尾元素下一位置的指针
*/

void error_msg(initializer_list<string> il) 
{
	for (auto beg = il.begin();beg != il.end();++beg)
	{
		cout << *beg << " ";
	}
	cout << endl;
	system("pause");
}

void error_msg02()
{
	string expected = "abc";
	string actual = "def";

	if (expected !=actual)
	{
		error_msg({ "functionX", expected,actual });
	}
	else
	{
		error_msg({"functionX","okay"});
	}
}

//省略符形参
/*
省略符形参是为了便于c++程序访问某些特殊的c代码而设置的，这些代码使用了名为varargs的 c 标准库功能。
通常，省略符形参不应用于其他目的。你的 c 编译器文档会描述如何使用varargs

！！！！省略符形参应该仅仅用于c 和 c++ 通用的类型。特别应该注意的是，大多数类类型的对象在传递给省略符形参时都无法正确拷贝。

省略符形参只能出现在形参列表的最后一个位置，它的形式无外乎以下两种:
void foo(parm_list,...)
void foo(...)
*/




void test_6_27(initializer_list<int> mylist) {
	int a=0;
	for (auto c  = mylist.begin(); c != mylist.end();c++)
	{
		
		a= *c + a;
	}

	cout << a << endl;
	system("pause");
}

//不用返回局部对象的引用或指针
/*
函数完成后，它所占用的储存空间也随之被释放掉。因此，函数终止意味着局部变量的引用将指向不再有效的内存区域:
*/
// 严重错误:这个函数试图返回局部对象的变量

/*
同样，返回局部对象的指针也是错误的。一旦函数完成，局部对象被释放，指针将指向一个不存在的对象。
*/
const string& manip()
{
	string ret ="abc";
	if (!ret.empty())
	{
		return ret; //错误:返回局部对象的引用!     //warning C4172: 返回局部变量或临时变量的地址: ret
	}
	else
	{
		return "Empty"; //错误:"Empty"时一个局部临时量    //warning C4172: 返回局部变量或临时变量的地址: ret
	}
}


const string manip_02()
{
	string ret = "abc";
	if (!ret.empty())
	{
		return ret; 
	}
	else
	{
		return "Empty";
	}
}

char &get_val(string &str, string::size_type ix)
{
	return str[ix];            //假定索引值是有效的
}

void get_val()
{
	string s("a value");

	cout << s << endl;
	get_val(s, 0) = 'A';     //将s[0]的值改为A
	//  shorterstring("hi","bye") ="X";		//错误：返回值是个常量
	cout << s << endl;   //输出A value
}

//列表初始化返回值。
/*
函数可以返回花括号包围的值的列表。类似于其他返回结果，此处的列表也用来对表示函数返回到临时量进行初始化。
*/
vector<string> process()
{
	string expected = "abc";
	string actual = "def";
	if (expected.empty())
	{
		return {};				//返回一个空vector对象
	}
	else if (expected == actual)
	{
		return { "functionX","okay" }; //返回列表初始化的vector对象
	}
	else
	{
		return { "functionX",expected,actual };
	}
}

//递归
//计算val的阶乘，即1*2*3....*val

int factorial(int val)
{
	if (val > 1)
	{
		return factorial(val - 1)*val;
		//return factorial(val--)*val; //会导致奔溃
	}
	return 1;
}



//节后练习 6.32
//正确的程序，返回的是数组第1~10个元素
int &get(int *arry, int index) { return arry[index]; }

void test_6_32()
{
	int ia[10];
	for (int i = 0; i != 10; ++i)
	{
		get(ia, i) = i;
	}

}

void test6_33(vector<int>a, int ix)
{
	if (ix != -1)
	{
		cout << a[ix] << endl;
		ix--;
		test6_33(a, ix); //递归
	}
}

//6.3.3 返回数组指针

/*
虽然从语法上来说，要想定义一个返回数组的指针或引用的函数比较烦琐，但是有一些方法可以简化这一任务，
其中最直接的方法是使用类型别名
*/
typedef int arrT[10]; //arrT是一个类型别名，它代表的类型是含有10个整数的数组
//using arrT = int[10]; //arrT的等价声明，

//arrT* func(int i); // func 返回一个指向含有10个整数的数组的指针

//声明一个返回数组指针的函数。
int arr_01[10];     //arr_01 是一个含有10个整数的数组
int *p1[10];			//p1是一个含有10个指针的数组
int(*p2)[10] = &arr_01;  //p2是一个指针。它指向含有10个整数的数组。

/*
举个例子，下面这个func函数的声明没有使用类型别名
int (*func(int i)) [10];
可以按照以下的顺序来逐层理解该声明的含义：

func(int i)表明调用func函数时需要一个int类型的实参。
(*func(int i)) 意味着我们可以对函数调用的结果执行解引用操作。
(*func(int i))[10] 表示解引用func的调用将得到一个大小事10的数组。
int (*func(int i))[10] 表示数组中的元素事int类型。
*/


//使用尾置返回类型？？？？kael 不是太明白
void func_02()
{
	//func_01 接受一个int类型的实参，返回一个指针，该指针指向含有10个整数的数组。
	auto func_01(int i)->int(*)[10];	
}

//重载和const形参
//一个拥有顶层const的形参无法和另一个没有顶层const的形参区分开来:
void myfunction(int i){}
//void myfunction(const int i){}   //error C2084: 函数“void myfunction(int)”已有主体  //会报错

void myfunction_02(int * i) {}
//void myfunction_02( int * const i) {}   //error C2084: 函数“void myfunction_02(int *)”已有主体 //kael：这个const 是顶层const，修饰 i


//对于接受引用或指针的函数来说，对象是常量还是非常量对应的形参不同
//定义了4个独立的重载函数

void myfunction_03(int& i) {}
void myfunction_03(int i) {}

void myfunction_03(int * i) {}
void myfunction_03(const int * i) {}     //kael：指向const int的指针。所以是底层指针
//建议：最好只重载那些确实非常相似的操作。有些情况下，给函数起不同的名字能使得程序更易理解。

const string &shorterString(const string &s1, const string &s2)
{
	return s1.size() <= s2.size() ? s1 : s2;

}

string &shorterString(string& s1, string & s2)
{
	//auto &r = shorterString(s1,s2); //warning C4717: “shorterString”: 如递归所有控件路径，函数将导致运行时堆栈溢出 //kael:依据类型，那么是调用了本身，所以是递归。
	auto &r = shorterString(const_cast<const string&>(s1), const_cast<const string&>(s2));
	return const_cast<string&>(r);
}

//重载与作用域
//如果我们再内层作用域中声明名字，它将隐藏外层作用域中声明的同名实体。在不同的作用域中无法重载函数名：
string read() { return ""; }
void print_02(const string& i) {}
void print_02(double i) {}
/*
如果在检查了所有实参之后没有任何一个函数脱颖而出，则该调用时错误的。编译器将报告二义性调用信息。
！！！调用重载函数时，应该尽量避免强制类型转换。如果在实际应用中确实需要强制类型转换，则说明我们设计的形参集合不合理。
*/
void fooBar(int ival)
{
	bool read = false; //新作用域：隐藏了外层的read
	//string s = read();   //错误：read是一个bool值，而非函数
	//不好的习惯：通常来说，在局部作用域中声明函数不是一个好的选择

	void prinprint_02(int i);			//新作用域：隐藏了之前的print  ,//kael ：允许声明新函数
	//void prinprint_02(int i) {};		//本地函数定义是非法的
	//print("Value: ");   //错误：print(const string&) 被隐藏掉了
	print_02(ival);			//正确：当前print(int) 可见
	print_02(3.14);			//正确：调用print(int); print(double)被隐藏掉了

}

//6.5特殊用途语言特性
//6.5.1默认实参
//我们可以为一个或多个形参定义默认值，不过需要注意的是，一旦某个形参被赋予了默认值，它后面的所有形参都必须是默认值
//kael：前空没事， 后空不行。

typedef string::size_type sz; 
string screen(sz ht = 24, sz wid = 80, char backgrnd = ' ') { return " "; }
//string screen(sz ht, sz wid , char backgrnd = ' abc') { return " "; } //error C2084: 函数“std::string screen(sz,sz,char)”已有主体

//6.5.2 内联函数 和 constexpr函数
//内联说明只是向编译器发出的一个请求，编译器可以选择忽略这个请求

inline const string & testInline(const string &s1, const string & s2)
{
	return s1.size() <= s2.size() ? s1 : s2;
}
/*
一般来说，内联机制用于优化规模较小、流程直接、频繁调用的函数。很多编译器都不支持内联递归函数。
*/

//constexpr 函数   是指能用于常量表达式的函数。
//遵守的约定: 函数的返回类型及所有形参的类型都是字面值类型，而且函数体中必须有且只有一天return 语句：
constexpr int new_sz() { return 42; }
constexpr int foo = new_sz();   //正确：foo是一个常量表达式

//我们允许constexpr函数的返回值并非一个常量：
//如果arg 是常量表达式，则scale(arg)也是常量表达式
constexpr size_t scale(size_t  cnt) { return new_sz()*cnt; }
//当scale的实参是常量表达式时，它的返回值也时常量值；反之则不然：
int arr[scale(2)];   //正确:scale(2)是常量表达式
int i = 2;				//i 不是常量表达式
//int a2[scale(i)];     //错误:scale(i)不是常量表达式

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
//assert宏的原型定义在<assert.h>中，其作用是如果它的条件返回错误，则终止程序执行。
void testAssert()
{
	FILE *fp;
	//会出现提示：因为高版本的vs，在安全性上，做了调整。具体:https://blog.csdn.net/xiaojinzichen/article/details/47322061
	//error C4996: 'fopen': This function or variable may be unsafe. Consider using fopen_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.
	//fp = fopen("d:/test.txt", "w"); //以可写的方式打开一个文件，如果不存在久创建一个同名文件
	fopen_s(&fp,"d:/test.txt", "w");
	assert(fp);    //所有这里不会出错
	fclose(fp);

	//fp = fopen("noexitfile.txt", "r");   //以只读方式打开一个文件，如果不存在久打开文件失败
	fopen_s(&fp,"noexitfile.txt", "r");
	assert(fp);				//所以这里出错
	fclose(fp);				//程序永远都执行不到这里
}

//#define MYTEST 3  //后面不需要加 ；
void testIndef()
{
	//如果 MYTEST 未定义，将执行#ifndef 和   #endif之间的代码，如果定义了MYTEST,则只执行   #endif 的代码
#ifndef MYTEST001   //这是"if not defined"的简写
	cout << "have mytest" << endl;
#endif
	cout << "no have my test" << endl;

}

	void f() {};
	void f(int i) {};
	void f(int a, int b) {};
	void f(double a, double b= 3.14) {};

void test6_50()
{
/*
	f(2.56, 42);  //不合法， 42为 int
	
	报错:
	“f”: 2 个重载有相似的转换
		可能是“void f(double,double)”或    “void f(int,int)”, 尝试匹配参数列表“(double, int)”时	
		kael: 因为 函数 f ，声明了两个函数：	void f(int a, int b) {};    void f(double a, double b= 3.14) {}; 两个都可以，于是产生了二义性。
		//造成二义性调用的原因是在函数匹配时两个或多个函数提供的匹配一样好，编译器找不到唯一的最佳匹配。
		如果去掉一个，那么编译就是正确的。因为以下概念：
		候选函数:函数匹配的第一步是选定本次调用的重载函数集，集合中的函数被称为候选函数
		可行函数:根据实参情况，从候选函数中挑选出能被这实参调用的函数，此次选出的函数被称为可行函数。
	*/
	f(42);
	f(42, 0);
	f(2.56, 3.14);

}

//函数指针 ：函数指针指向的是函数而非对象

//pf指向一个函数，该函数的参数是两个const string的引用，返回值是bool类型
bool(*pf)(const string& a, const string & b); //（*pf）括号必不可少，未初始化 //kael 声明了一个指向函数的指针

//使用函数指针
bool lengthCompare(const string& a, const string & b) {return true; }

string::size_type sumLength(const string&, const string&);
bool cstringCompare(const char*, const char *);
void testfunctionPoint()
{

	pf = 0; //正确：pf 不指向任何函数
//	pf = sumLength;  //错误：返回类型不匹配
//	pf = cstringCompare; //错误：形参类型不匹配
pf = lengthCompare;		//pf 指向名为lengthCompare的函数
pf = &lengthCompare;   //等价的赋值语句：取地址符是可选的

bool b1 = pf("hello", "goodbye");							//调用lengthCompare函数
bool b2 = (*pf)("hello", "goodbye");						//一个等价的调用
bool b3 = lengthCompare("hello", "goodbye");		//另一个等价的调用
}

//重载函数的指针

void ff_02(int* a) {};
void ff_02(unsigned int a) {};
void(*pf1)(unsigned int) = ff_02;   //pf1 指向ff(unsigned)

//void(*pf2)(int) = ff_02;    //错误：没有任何一个ff与该形参列表匹配
//double(*pf3)(int *) = ff_02; //错误：ff_02 和pf3  的返回类型不匹配

//函数指针形参
//形参可以是指向函数的指针。此时，形参看起来是函数类型，实际上却是指针使用:

//第三个形参是函数类型，它会自动地转换成指向函数的指针
void useBigger(const string & s1, const string& s2, bool pf_03(const string&, const string &)) {};

//等价的声明：显式地将形参定义成指向函数的指针
void useBigger(const string &s1, const string &s2, bool(*pf_03(const string &, const string &))) {};

void testUseBigger() {

 string a = "a";
 string b = "b";
//我们可以直接把函数作为实参使用，此时它会自动转换成指针
useBigger(a, b, lengthCompare);

}

//类型别名和decltype能让我们简化使用了函数指针的代码:
//Func 和 Func2是函数类型
typedef bool func(const string&, const string&);
typedef decltype(lengthCompare) Func2;   //等价的类型

//FuncP 和 FuncP2 是指向函数的指针
typedef bool(*FuncP)(const string&, const string&);
typedef decltype(lengthCompare) *FuncP2;   //等价的类型

//-----将auto和decltype用于函数指针类型
string::size_type sumLength(const string&, const string&);
string::size_type largerLength(const string&, const string&);
//根据其形参的取值，getFun函数返回指向SumLength或者largerLength的指针
decltype (sumLength) *getFcn(const string&);
/*
声明getFun唯一需要注意的地方是，牢记当我们将decltype作用于某个函数时，它返回函数的类型并非指针类型。因此，我们显式地加上* 以表明我们需要返回指针，而非函数。


*/

/*
int main()
{
	int array_a[10] = {1,2,3,4,5,6,7,8,9,10};
	int array_b[9] = { 1,2,3,4,5,6,7,8,9 };
	//Test_6_1_1();
//	test_6_24(array_b); //无法从“int [9]”转换为“const int [10]”
	//test_6_24(array_a); //入参只能是大小为10个元素的数组
	//error_msg02();
	//test_6_27({ 1,2,3 });

	//std::cout << manip() << endl;  //kael : 会引发异常，导致崩溃。
	//std::cout << manip_02() << endl; //kael :这个方法用的时拷贝，而不是引用，所以原来的值是否销毁，对其没有影响。所以不会引发奔溃。

	
	//std::cout << factorial(5) << std::endl; //kael: 输出了总的值，而不会像for循环一样，递归一次，输出一次。


	string abc = "abc";
	string def = "def";
	
	std::cout << shorterString(abc, def) << std::endl;


	testIndef();
	system("pause");
	return 0;
}

*/