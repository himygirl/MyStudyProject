
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


//const的引用， 术语：常量引用是对const的引用。
void dateType17()
{
	int i = 42;
	const int &r1 = i;
	const int &r2 = 42;
	const int &r3 = r1 * 2;
	 //int &r4 =  r1 * 2;   //错误：r4是一个普通的非常量引用。

/*
	// const 常量值不能赋给   非常量的原理分析：

	double dval = 3.14;
	const int &ri = dval;

//编辑器对上述赋值过程
	double dval = 3.14;
	const int temp = dval;   //由双精度浮点数生成一个临时的整形常量
	const int &ri = temp;    //让ri绑定这个临时量。

	//假设：可以赋值给非常量
    int &r6 = temp；//则意味着r6 引用了一个临时量。而r6的值是可以改变的。去改变一个临时量，这种行为再c++里是非法的。
	
	*/
}



void dateType18()
{
	int abc = 1;
	const int &abcd = abc;
	abc = 3;

	//abcd = 5; //错误：error C3892: “abcd”: 不能给常量赋值。     abcd是一个常量引用。那本质上是一个常量。所以不能赋值。
	std::cout << abcd << std::endl;

	system("pause");
}


//指向常量的指针 不能用于改变其所指对象的值。要想存放常量对象的地址，只能使用指向常量的指针。
void dateType19()
{
	const double pi = 3.14;
	//double *ptr = &pi;				//错误：ptr 是一个普通指针
	const double *cptr = &pi;		
	//*cptr = 42;                           //错误：不能给*cptr赋值

	double dval = 3.14;				//dval 是一个双精度浮点数，它的值可以改变
	cptr = &dval;                      //正确： 但是不能通过cptr改变dval的值。

}

//常量指针必须初始化。  把*放在const关键字之前用以说明指针是一个常量，这样的书写形式隐含着一层意味，即不变的是指针本身的值，而非指向的那个值：
void dateType20()
{
	int errNumb = 0;
		int *const curErr = &errNumb;   //curErr将一直指向errNumb
		const double pi = 3.14159;

		//要想弄清楚这些声明的含义最行之有效的方法是：从右向左阅读。
		const double *const pip = &pi; //pip 是一个指向常量对象的常量指针。
}

void dateType21()
{
//	int i = -1, &r = 0;    //引用r的赋值对象，必须是一个对象。
	int i = -1;
	int i2 = 2;
	//const int i2 = i, &r = i;
	int *const p2 = &i2;// 把*放在const关键字之前用以说明指针是一个常量

	const int *const p3 = &i2;
	const int *pi = &i2;
	//const int &const r2;


	const int i3 = i, &r = i;
	//int *const p4 = &i3;   //非法。分析：int *const p4  ：p4是指向int的常量指针。    i3 是指向常量int的指针。   

	const int *const p5 = &i3;
	const int *pi3 = &i3;
	
}


//顶层const
/*
指针本身是一个对象，它又可以指向另外一个对象。因此，指针本身是不是常量依据指针所指的是不是一个常量就是两个独立的问题了。
用名词顶层const 表示指针本身是个常量， 而用名词底层const 表示指针所指的对象是一个常量。
kael认为：const是顶层，还是底层，是由声明定义的 那个值是否可以改变决定的。如果决定了声明定义的值，不能被改变，则是顶层。反之，则为底层。
*/
void dateType22()
{
	int i = 0;
	int *const p1 = &i;				  //不能改变P1的值，这是一个顶层const。    p1是常量指针。  所以不能改变P1.
	const int ci = 42;					//不能改变ci的值，这是一个顶层const。        ci是常量int。  所以不能改变ci。
	const int *p2 = &ci;				// 允许改变P2的值，这是一个底层const。      p2是指向常量int的指针。所以p2的值，是允许改变的。
	const int *const p3 = p2;		//靠右的const是顶层const，靠左的是底层const。
	const int &r = ci;                //用于声明引用的const都是底层const。

	//底层const的限制：
	//当执行对象的拷贝操作时，拷入和拷出的对象必须具有相同的底层const资格，或者两个对象的数据类型必须能够转换。一般来说，非常量可以转换成常量，反之不行。

	//int *p = p3;			//错误：p3包含底层const的定义，而p没有
	p2 = p3;					//正确：p2和p3都是底层const
	p2 = &i;					//正确：int* 能转换成const int*
//	int &r = ci;              //错误：普通的int& 不能绑定到int常量上。 //kael认为：& 是为了改变原始的那个被引用的值。所以被应用的值，是否可以被改变。决定了它是否可以被引用。
	const int &r2 = i;   //const int& 可以绑定到一个普通int上。
}



//2.4.4   constexpr和常量表达式
//常量表达式：是指值不会改变并且在编译过程就能得到计算结果的表达式。
int j = 0;
constexpr  int i = 42;              //i 的类型是整型常量，i和j都必须定义在函数体之外。
void dateType23()
{
	const int max_files = 20;             //max_files 是常量表达式
	const int limit = max_files + 1;    //limit是常量表达式
	//const int sz = get_size();          //sz不是常量表达式  //尽管sz本身是一个常量，但它的具体价值直到运行时才能获取到，所以也不是常量表达式。

	//c++ 11 新标准规定，允许将变量声明为constexpr类型以便由 编译器 来验证变量的值是否是一个常量表达式。
	//声明为constexpr的变量一定是一个常量，而且必须用常量表达式初始化。

	constexpr  int mf = 20;                      //20是常量表达式
	constexpr int limit_01 = mf + 1;        //mf+1是常量表达式
	std::string mystring = "aaaa";
	int myint = mystring.size();
	//constexpr int sz =mystring.size(); //error C2131: 表达式的计算结果不是常数  //只有当size是一个constexpr函数时，才是一条正确的声明语句。

	//!!!!!一般来说，如果你认定变量时一个常量表达式，那就把它声明成constexpr类型。
	/*
	//字面值类型。
	到目前为止接触过的数据类型中，算术类型、引用和指针都属于字面值类型。   只定义类、IO库、string类型不属于字面值类型，也就不能被定义成constexpr。
	
	函数体内定义的变量一般来说并非存放在固定地址中，因此constexpr指针不能指向这样的变量。相反的，定义与所有函数体之外的对象，其地址固定不变，能用来初始化constexpr指针。
	
	*/



	//指针和constexpr
	/*
	在constexpr声明中如果定义了一个指针，限定符constexpr仅对指针有效，与指针所指的对象无效：
	*/
	const int *p = nullptr;						//p 是一个执行整型常量的指针
	constexpr int *q = nullptr;				//q是一个指向整数的常量指针。

	constexpr int *np = nullptr;			 //np是一个指向整数的常量指针，其值为空

	constexpr  const int *p01 = &i;   //p01是常量指针，指向整型常量i
	constexpr int *p1 = &j;               //p1是常量指针，指向整数j
	//int *aaaa = NULL;
}


//2.5 处理类型

#include "MyClass1_5.h";
void dateType2_5_1()
{
	//类型别名是一个名字，它是某种类型的同义词。有两种方法可用于定义类型别名。
	//传统的方法是使用：关键字：typedef
	typedef double wages;    //wages 是double的同义词；
	typedef wages  base,     *p001;    //base 是double的同义词，p是double*的同义词。
	base aaa;

	//使用别名声明来定义类型的别名：
	using SI = Sales_item;     //SI 是Sales_item的同义词。

	typedef char *pstring;
	const pstring cstr = 0;   //cstr 是指向char的常量指针
	const pstring *ps;          //ps 是一个指针，它的对象是指向char的常量指针。

	const char *cstr001 = 0;     //如果尝试，用char*   去替换pstring的话：是对const pstring cstr的错误理解。这里是：指向char常量的，指针。

}

void dateType2_5_2()
{
	//auto 类型说明符
	auto ii = 0, *p = &ii;		 //ii是整数、p是整型指针
	//auto sz = 0, pi = 3.14;	     //错误：sz和pi的类型不一致，这种声明方式要求sz与pi类型一致。

	//auto一般会忽略掉顶层const，同时底层const则会保留下来，
	const int ci = ii, & cr = ci;
	auto b = ci;      //b 是一个整数（ci的顶层const 特性被忽略掉了）
	auto c = cr;      //c是一个整数（cr是ci的别名，ci本身是一个顶层const）
	auto d = &ii;     //d是一个整型指针（整数的地址就是指向整数的指针）
	auto e = &ci;    //e是一个指向整数常量的指针（对常量对象取地址是ii一种底层const）

	auto *p001 = &ci;    //p的类型是：const int *
	//如果希望推断出的auto类型是一个顶层const，需要明确指出：
	const auto f = ci;    //ci的推断类型是int，f是const int

	//还可以将引用的类型设为auto，此时原来的初始化规则仍然适用：
	auto &g = ci;               //g是一个整型常量引用，绑定到ci
	//auto &h = 42;           //错误：不能为非常量引用绑定字面值
	const auto &j = 42;     //正确：可以为常量引用绑定字面值。

	auto &n = i, *p2 = &ci; //错误：i的类型是int而&ci的类型是const int


}

//decltype 类型指示符
void dateType2_5_3()
{
	//希望从表达式的类型推断出定义的变量的类型，但是不想用该表达式的值初始化变量。
	//decltype（f()） sum =x ;   //sum的类型就是函数f的返回类型。

	//如果decltype使用的表达式是一个变量，则decltype返回该变量的类型（包括顶层const和引用在内）:
	const int ci = 0, &cj = ci;
	decltype(ci) x = 0;  //x的类型是const int
	decltype(cj) y = x;  //y的类型是const int&， y绑定到变量x
	//decltype(cj) z;        //错误:z是一个引用，必须初始化


	int i001 = 42, *p = &i001, &r = i001;
	//因为r是一个引用，因此decltype（r）的结果是引用类型，
	//但如果decltype（r+0），显然这个表达式的结果将是一个具体值，而非一个引用。
	decltype(r + 0) b;     //正确：加法的结果是int，因此b是一个（未初始化的）int

	//如果表达式的操作是解引用操作，则decltype将得到引用类型。
	//decltype(*p) c;         //错误：c是int& ，必须初始化.   p是int*， 


	//decltype的表达式如果是加上了括号的变量，结果将是引用
	//decltype((i001)) d;  //错位：d是int& ，必须初始化。
	decltype(i001) e;       //正确：e是一个（未初始化的）int

	//切记：decltyp((variable))(注意是双层括号)的结果永远是引用，而deltype（variable）结果，只有当variable本身就是一个引用时才是引用。


	int a = 3, bb = 4;
	decltype(a) c = a;
	std::cout << "c----" << c << std::endl;
	decltype((bb)) d = a;
	std::cout << "d----" << d << std::endl;
	++c;
	std::cout << "c++----" << c << std::endl;
	++d;
	std::cout << "d++----" << d << std::endl;
	

	system("pause");

}
struct mykaelstruct
{

};

//预处理器概述
/*
//确保头文件多次包含仍能安全工作的常用技术时预处理器。
//当预处理器看到#include标记时就会用指定的头文件的内容代替#include

#define指令把一个名字设定为预处理变量，
另外两个指令则分别检查某个指定的预处理变量是否已经定义：
#ifdef 当且仅当变量已定义时为真，
#ifndef当且仅当变量未定义时为真。
一旦检查结果为真，则执行后续操作直至遇到#endif指令为止。

!!!!头文件即使（目前还）没有被包含在任何其他头文件中，也应该设置保护符。
头文件保护符很简单，程序员只要习惯性地加上就可以了，没必要太在乎你的程序需不需要。
*/

#ifndef SALES_DATA_H   //#ifdef 当且仅当变量已定义时为真，
#define SALES_DATA_H  //定义宏:其实宏是用空间效率换取了时间效率,效率最高。
										//虽然使用inline提示符也将函数或模板定义为内联的，但这只是一种提示而已，到底编译器有没有优化还依赖于编译器的实现，而使用宏函数则是完全由代码本身控制
#include<string>
struct Sales_data
{

};
#endif // !SALES_DATA_H

#define  MYTEST(a,b) b<a? a:b;
#define  MYTEST001() std::cout<<"define"<<std::endl;
void dateType2_5_4()
{
	int c = MYTEST(3,5);
	MYTEST001();
	std::cout << c << std::endl;
	system("pause");
}

/*
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

	//dateType16();
	//dateType18();
	//dateType2_5_3();
	 dateType2_5_4();

	return 0;
}

*/