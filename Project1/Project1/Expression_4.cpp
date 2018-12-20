#include <iostream>
#include <string>
#include <vector>

using namespace std;

void test()
{
	int i_01 = 0, j_02 = 0, k = 0;   //初始化，而非赋值

	int ival, jval;
	ival = jval = 0;    //正确：都被赋值为0

	//递增和递减运算符

	int i = 0, j;
	//前置的递增运算符：先算后用，后置的递增运算符：先用后算。递减一样
	j = ++i;        //j = 1,i =1 :前置版本得到递增之后的值
	j = i++;		//j=1，i=2	:后置版本得到递增之前的值。
/*
建议：除非必须，否则不用递增递减运算符的后置版本。
		建议养成使用前置版本的习惯，这样不仅不担心性能的问题，而且更重要的是写出的代码更复合编程的初衷。
*/

	vector <int>v = {0,1,2,3};
	auto pbeg = v.begin();
	//输出元素直至遇到第一个负值为止
	while (pbeg !=v.end() && *pbeg >=0)
	{
		std::cout << *pbeg++ << std::endl;   //输出当前值并将pbeg向前移动一个元素。
	}

	string s("some string");
	for (auto it = s.begin();it !=s.end() && !isspace(*it); ++it)
	{
		*it = toupper(*it);   //将当前字符改成大写形式
	}
/*
	//该循环的行为是未定义的！
	while (beg !=s.end() && !isspace(*beg))
	{
					*beg = toupper(*beg++);    //错误：该赋值语句未定义
	}
	//问题在于：赋值运算符左右两端的运算对象都用到了beg，并且右侧的运算对象还改变了beg的值，所以该赋值语句是未定义的。
	//编辑器可能按照下面任意一种思路处理该表达式：
	*beg  = toupper(*beg);			   //如果先求左侧的值
	*(beg + 1) = toupper(*beg);		//如果先求右值的值
*/


}

void test4_19()
{
	int test = 3;
	

	for (int* ptr = &test;ptr !=0; *ptr++)		//ptr向前移动
	{		
	//	std::cout << ptr << std::endl;   //kael_输出改变，因为*ptr++
	//	std::cout << *ptr << std::endl; //kael_输出指针所指的对象。对象改变。因为*ptr++
	//	std::cout << &ptr << std::endl; //kael_求ptr的地址。 因为ptr这个指针的地址一直没有改变，改变的是ptr这个指针指向的地址。
	}
		int* ptr02 = &test;
	if (ptr02 !=0 && *ptr02++)
	{
		//ptr02 是否为0.   *ptr02 是否为0.后置的递增运算符：先用后算
	}
	int ival = 1;
	if (ival++ && ival)
	{
		//判断ival和ival+1 两个值是否都非0
	}

	vector<int> vec(2, 4);

	//对于那些没有指定执行顺序的运算符来说，如果表达式指向并  修改同一个对象  ，将会引发错误并产生未定义的行为。
	if (vec[ival++]<=vec[ival])
	{
		//这个条件会导致崩溃，因为求值顺序不一定。因为c++ 只要四种运算符定义了求值顺序，>=不在其中  
		//四种分别是逻辑与&&，  逻辑或||，  条件运算符？： 和逗号  ，
	}


	system("pause");
}

//成员访问运算符

void test_4_6()
{
	//点运算符获取类对象的一个成员，表达式ptr->等价于(*ptr).mem;

	string s1 = "a string", *p = &s1;
	auto n = s1.size();		//运行string 对象S1 的size成员
	n = (*p).size();				//运行p所指对象的size成员,  解运算符的优先级低于点运算符
	//运行p的size成员，然后解引用size的结果
	//*p.size();    //错误：p是一个指针，它没有名未size的成员
	n = p->size();				//等价于(*p).size()

/*
箭头运算符作用于一个指针类型的运算对象，结果是一个左值。点运算符分成两种情况：
如果成员所属的对象是左值，那么结果是左值；反正，如果成员所属的对象是右值，那么结果是右值。

*/
}

//练习4.20

void test4_20()
{
	/*
	指针是C语言里面就有的东西，
	而迭代器是C++里面才有的，指针用起来灵活，效率高。迭代器功能更丰富一些（不见得是强大一些），
	c++的stl里面很多算法都是基于迭代器的，一部分算法的参数可以传递指针作为迭代器使用
	*/

	/*
	vector<string>::iteratior iter;
	*iter ++;				//合法： 先对iter加1，再返回iter指向的值
	(*iter)++;				//不合法：返回iter指向的值为string ++ 操作无意义
	*iter.empty();		//不合法：iter是一个指针，没有empty（）的成员
	iter->empty();		//合法：判断iter所指的值是否为空
	++*iter;				//不合法：*iter可以得到iter所指的字符串，但是字符串并没有++操作。
	iter++ ->empty(); //合法：首先判断iter说指向的值是否为空，再对iter加1
		
	*/

}

//位运算符（左结合律）
/*
~ 位求反
<< 左移
>>右移
&	位与
^ 位异或
|	位或
*/

//4.9   sizeof运算符


void  MySizeof_4_28()
{
	/*
	sizeof操作符检测的是系统为后面()中(无歧义时不用()也行)的类型、变量等分配的内存空间的字节数
	在16位int平台下是2；
	在32位int平台下是4；
	在64位int平台下是8
	*/
	std::cout << sizeof(int) << std::endl;  //int输出4 //其他类型这样写就好了
	std::cout << sizeof(string) << std::endl;

	system("pause");
}
struct Sales_data
{

};
void  MySizeof_4_29()
{
	/*
	sizeof(type)
	sizeof expr
	*/

	Sales_data data, *p; 
	sizeof(Sales_data);				//储存Sales_data类型的对象所占用的空间大小
	sizeof data;							//data的类型的大小，即sizeof(Sales_data)
	sizeof p;								//指针所占用的空间大小
	sizeof *p;								//p所指类型的空间大小，即sizeof(Sales_data)
	//sizeof data.revenue;			//Sales_data的revenue成员对应类型的大小
	//sizeof Sales_data::revenue;	//另一种获取revenue大小的方式。

	int x[10];
	int *p_02 = x;
	std::cout << sizeof(x) << std::endl;			 //输出40     kael：输出的是数组的元素大小的和。4*10
	std::cout << sizeof(*x) << std::endl;			//输出4    kael：x指向的值的大小
	std::cout << sizeof(p_02) << std::endl;		//输出4		kael：p_02这个指针的大小
	std::cout << sizeof(*p_02) << std::endl;		//输出4    kael:   p_02指向的值的大小
	

	system("pause");
}

void  MySizeof_4_30()
{
	/*
	sizeof x +y				等价于		(sizeof x)  +y;
	sizeof p->mem[i]		 等价于		sizeof(p->mem[i]);
	sizeof a <b               等价于		(sizeof a)<b;
	
	
	*/
}

//类型转换

void TypeConversion()
{
	/*
	bool		flag;
	short	sval;
	int		 ival;
	long		 lval;
	float		fval;
	char		cval;
	unsigned short usval;
	unsigned int	uival;
	unsigned long ulval;
	double				 dval;

	3.14159L + 'a'; //'a'提升成int，然后该int 值转换成long double
	dval + ival;		//ival转换成double
	dval + fval;		//fval转换成double
	ival = dval;		//dval转换成（切除小数部分后）int
	flag = dval;		//如果dval是0，则flag是false，否则是true
	cval + fval;		//cval提升成int，然后该int值转换成float
	sval + cval;		//sval和cval都提升成int
	cval + lval;       //cval转换成long
	ival + ulval;		//ival转换成 unsigned long
	usval + ival;		//根据unsigned short和int所占空间的大小进行提升
	uival + lval;		//根据unsigned int 和long 所占空空间的大小进行转换
*/
}

void TypeConversion_02()
{
	int i;
	const int &j = i;		//非常量转换成 const int 的引用
	const int *p = &i;		//非常量的地址转换成const的地址
	//int &r = j, *q = p; //错误：不允许const转换成非常量
}
void test_4_35()
{
	char cval;
	int ival = 1;
	unsigned int ui = 2;
	float fval;
	double dval = 3;

	cval = 'a' + 3;
	fval = ui - ival * 1.0;
	dval = ui * fval;
	cval = ival + fval + dval;

}

//转换

void TypeConversion_03()
{
	const char* pc =" hellow world";
	
	//char *q = static_cast<char*>(pc);// 错误：static_cast 不能转换掉const性质
	string mystring = static_cast<string>(pc); //正确：字符串字面值转换成string类型
	//string mystring02 = const_cast<string>(pc);  //错误：const_cast只改变常量属性。//kael：const_cast只是改变运算对象的底层const
	char *p = const_cast<char*>(pc);  //正确：但是通过p写值是未定义的行为，//kael ：因为pc的const是顶层const，而const_cast只改变运算对象的底层const。
	/*
	如果对象本身不是一个常量，使用const_cast强制转换，获取写权限是合法行为。然而如果对象是一个常量，再使用const_cast执行写炒作就会产生未定义的后果。
	
	*/
	

	//reinterpret_cast 本质上依赖于机器。要向安全的使用，必须对涉及的类型和编译器实现转换的过程都非常了解。
	int a = 3;
	int *ip =&a ;
	//我们必须牢记pc所指的真实对象是一个int而非字符串，如果把pc当成普通的字符指针使用就可能再运行时发生错误。
	char *pc_02 = reinterpret_cast<char*>(ip);

}

/*
int main()
{
	//test4_19();
	//MySizeof_4_28();
	//MySizeof_4_29();
	test_4_35();
	return 0;
}

*/