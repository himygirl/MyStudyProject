#include <iostream>
#include <windows.h>
#include <string.h>
#include <vector>

using namespace std;

// 引入this ： this是一个常量指针

//构造函数：每个类都分别定义了他的对象被初始化的方式，类通过一个或几个特殊的成员函数来控制其对象的初始化过程。
//和其他函数不一样的是，构造函数没有返回值；除此之外类似于其他函数，构造函数不能被声明成const的，
//当我们创建类的一个const对象时，直到构造函数完成初始化，对象才能真正取得其“常量”属性，因此，构造函数在const对象的构造过程中，可以向其写值
//只有当类没有声明任何构造函数时，编译器才会自动地生成默认构造函数。
class p
{


};
struct Sales_data  
{
	//新增的构造函数
	Sales_data() = default;
	Sales_data(const std::string &s) :bookNo(s) {}
	/*
	当某个数据成员被构造函数初始值忽略时，它将以与合成默认构造函数相同的方式隐式初始化。
	建议：构造函数不应该轻易覆盖掉类内的初始值，除非新赋的值与原来不同。如果你不能使用类内初始值，则所有构造函数都应该显示初始化每个内置类型的成员。
	*/
	Sales_data(const std::string &s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(p*n) {}
	Sales_data(std::istream &);

	//之前已有的其他成员
	std::string isbn()const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const;
		std::string bookNo;
		unsigned	units_sold = 0;
		double revenue = 0.0;
};

//友元
/*
类可以允许其他类或者函数访问它的非公有成员。方法时是：令其它类或者函数成为它的友元。

友元关系不存在传递性，每个类负责控制自己的友元类或友元函数。
*/
class MyClassTestA
{

	
public:
	MyClassTestA() {};
	~MyClassTestA() {};

	
private:
	void MyTestFriendA() {};
};

class MyClassTestB
{
	friend MyClassTestA;

	
public:

	void test() {
		MyClassTestA TestA;
	//	TestA.MyTestFriendA; //error C3867: “MyClassTestA::MyTestFriendA”: 非标准语法；请使用 "&" 来创建指向成员的指针
	}
	MyClassTestB() {};
	~MyClassTestB() {};

private:
	void MyTestFriendB() {};
};


//友元函数
//如果一个类想把一组重载函数声明成它的友元，它需要对这组函数中的每一个分别声明：
class A
{
public:
	friend void set_show(int x, A &a);      //该函数是友元函数的声明
private:
	int data;
};

void set_show(int x, A &a)  //友元函数定义，为了访问类A中的成员
{
	a.data = x; //如果上面没有加友元函数声明则报错：error C2248: “A::data”: 无法访问 private 成员(在“A”类中声明)
	cout << a.data << endl;
}


//友元类
class A_02
{
public:
	friend class C_02;                         //这是友元类的声明
private:
	int data;
};

class C_02             //友元类定义，为了访问类A中的成员
{
public:
	void set_show(int x, A_02 &a) { a.data = x; cout << a.data << endl; }
};

//友元成员函数

class A_03;    //当用到友元成员函数时，需注意友元声明与友元定义之间的互相依赖。这是类A_03的声明


class B_03
{
public:
	void set_show(int x, A_03 &a);             //该函数是类A的友元函数  //如果注释掉上面的class A_03, 则报错：error C2061: 语法错误: 标识符“A_03”
};

class A_03
{
public:
	friend void B_03::set_show(int x, A_03 &a);   //该函数是友元成员函数的声明
private:
	int data;
	void show() { cout << data << endl; }
};

void B_03::set_show(int x, A_03 &a)       //只有在定义类A后才能定义该函数，毕竟，它被设为友元是为了访问类A的成员
{
	a.data = x;
	cout << a.data << endl;
}

//友元声明和作用域
/*
类和非成员函数的声明不是必须在它们的友元声明之前。当一个名字第一次出现在一个友元声明中时，我们隐式地假定该名字在当前作用域中时可见的。
然而，友元本身不一定真的声明在当前作用域中。
甚至就算在类的内部定义该函数，我们也必须在类的外部提供相应的声明从而使得函数可见。换句话说，即使我们仅仅是用声明友元的类的成员调用该友元函数，它也必须是被声明过的：
*/

struct X 
{
	friend void f_03() {/*友元函数可以定义在类的内部*/}
	//X() { f(); }  //错误：f还没有被声明   //编译后报错：error C3861: “f”: 找不到标识符
	void g();
	 void h();
};

//void x::g() { return f(); }    //错误：f还没有被声明   //编译后： error C2653: “x”: 不是类或命名空间名称，error C3861: “f”: 找不到标识符
void f_03();							//声明那个定义在X中的函数
void X::h() { return f_03(); }	//正确：现在f的声明在作用域中了


//screen类的成员函数
class Screen
{
public:
	typedef std::string::size_type pos;
	/*
	我们已经提供了一个构造函数，所以编译器将不会自动生成默认的构造函数。如果我们的类需要默认的构造函数，必须显示地把它声明出来。
	*/
	Screen() = default; //因为Screen有另一个函数，所以本函数是必须的，cursor被其类内初始值初始化为0

	Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht* wd, c) {}

	char get()const						//读取光标处的字符
	{ return contents[cursor]; }		 //隐式内联
	inline char get(pos ht, pos wd) const; //显式内联

	Screen &move(pos r, pos c);   //能在之前被设为内联

private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string  contents;

};

//可变数据成员
/*
一个 可变数据成员永远不会是const，即使它是const对象的成员
*/

class Screen_02
{
public:
	typedef std::string::size_type pos;
	void some_member() const;

	Screen &set(char);
	Screen &set(pos, pos, char);

	char get()const						//读取光标处的字符
	{
		return contents[cursor];
	}		 //隐式内联
	inline char get(pos ht, pos wd) const; //显式内联

	Screen &move(pos r, pos c);   //能在之前被设为内联


	private:
	mutable size_t access_ctr; //即使在一个cosnt对象内也能被修改
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string  contents;
};




void Screen_02::some_member() const
{
	/*
	尽管some_member是一个cosnt成员函数，它仍然能够改变access_ctr的值。该成员是个可变成员，因此任何成员函数，包括const函数在内都能改变它的值
	*/
	++access_ctr;     
}

//返回*this 的成员函数
class Screen_03
{
public:
	typedef std::string::size_type pos;
	void some_member() const;

	Screen_03 &set(char);
	Screen_03 &set(pos, pos, char);

	char get()const						//读取光标处的字符
	{
		return contents[cursor];
	}		 //隐式内联
	inline char get(pos ht, pos wd) const; //显式内联

	Screen &move(pos r, pos c);   //能在之前被设为内联

	Screen_03  &MyConst(char,pos) const ;

private:
	mutable size_t access_ctr; //即使在一个cosnt对象内也能被修改
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string  contents;
};

inline Screen_03 &Screen_03::set(char c)
{
	contents[cursor] = c;
	return *this;    //将this对象作为左值返回
}

inline Screen_03 &Screen_03::set(pos r, pos col, char ch)
{
	contents[r *width + col] = ch;
	return *this;
}
/*
一个cosnt成员函数如果以引用的形式返回*thi，那么它的返回类型将是常量引用。
*/

/*
//报错：error C2511: “Screen_03 &Screen_03::MyConst(char,Screen_03::pos)”:“Screen_03”中没有找到重载的成员函数
 Screen_03 &Screen_03::MyConst(char a, pos b)
{
	return *this;
}
*/

//基于const的重载
//通过区分成员函数是否是const的。我们可以对其进行重载。
class Screen_04
{
public:	
	//根据对象是否是const重载了display函数
	Screen_04 &display(std::ostream &os) { return *this; }
	const Screen_04 &display(std::ostream &os) const { return *this; }

private:

};

/*
void test_04()
{
	Screen_04 myScreen(5, 3);
	const  Screen_04 blank(5, 3);

	myScreen.set('#').display(cout);  //调用非常量版本
	blank.display(cout);						//调用常量版本

}

*/

//类的声明
//我们可以把类名作为类型的名字使用，从而直接指向类类型。
//编译器处理完类中的全部声明后才会处理成员函数的定义

//我们也可以仅仅声明类，而暂时不定义它
class Screen_05;     //Screen_05 类的声明  //这个种声明有时被称作前向声明，它向程序引入了名字Screen_05 并且指明Screen是一种类类型。
/*
对于一个类来说，在我们创建它的对象之前该类必须被定义过，而不能仅仅被声明。否则，编译器就无法了解这样的对象需要多少储存空间。
*/
//一旦一个类的名字出现后，它就被认为是声明过了（但尚未定义），因此类允许包含指向它自身类型的引用或指针：
class  Link_screen
{
	//Screen_05 windows;   //错误：使用未定义的 class“Screen_05”
	Link_screen *next;
	Link_screen *prev;
};

//7.3.3 节后练习
/*
知识点1：可以将类当作一种类型来看待，两个类即使成员部分完全相同，也属于不同的类型
知识点2：类允许包含指向它自身类型的指针或者引用
知识点3：创建一个类的对象之前必须先定义该类，仅仅声明是无法让编译器了解到该类需要多少空间的
*/
class MyclassY;  //前向声明，如果没有，会报错：

class MyclassX
{
	MyclassY *   MyclassTestY;  //如果没有  MyclassY的 前向声明 报错：error C2143: 语法错误: 缺少“;”(在“*”的前面)


};
class MyclassY
{
	MyclassX MyclassTestX;

};


//用于类成员声明的名字查找
typedef double Money;
string bal;
class Account
{
public:
	Money balance() { return bal; }   //该函数的return语句返回名为bal的成员，而非外层作用域的 string 对象。
private:
	Money bal;
};


//注意：这段代码仅为了说明而用，不是一段很好的代码
//！！！通常情况下不建议为参数和成员使用同样的名字

int height; //定义了一个名字，稍后将在Screen_06中使用
class Screen_06
{
public:
	typedef std::string::size_type pos;
	void dummy_fcn(pos hight)
	{
		cursor = width * height;   //哪个height？是哪个参数？  成员height
		cursor = width * this->height; //成员height
		//另一种表示该成员的方式
		cursor = width * Screen_06::height;   //成员height

		cursor = width * ::height;    //哪个height？  是那个全局的

		//NOTE:尽管外层的对象被隐藏掉了，但我们仍然可以用作用域运算符访问它。
	}

private:
	pos cursor = 0;
	pos height = 0 , width = 0;

};

//在文件中名字的出现处对其进行解析

int height_07;
class Screen_07
{
public:
	typedef std::string::size_type pos_07;
	void setHeight(pos_07 var);
	pos_07 height_07 = 0;   //隐藏了外层作用域中的height_07

};

Screen_07::pos_07 verify(Screen_07::pos_07) { Screen_07 myscreen_07; return myscreen_07.height_07; }
/*
Screen_07::pos_07 verify(Screen_07::pos_07);
kael：verify只声明，而未定义的时候，那么在别处引用，则会出现以下提示报错：
编译错误:无法解析的外部符号 "unsigned int __cdecl verify(unsigned int)"
*/
void Screen_07::setHeight(pos_07 var)
{
		//var:参数
		//height：类的成员
		//verify:全局函数
	 height_07 = verify(var);  //因为这里应用了全局函数verify，但verify并未定义，所以导致提示：无法解析的外部符号 "unsigned int __cdecl verify(unsigned int)"    
}
/*
请注意，全局函数verify的声明在screen_07类的定义之前是不可见的。然而，名字查找的第三步包括了成员函数出现之前的全局作用域。在此例中，verify的声明位于setHeight的定义之前，因此可以被正常使用。

*/


//练习7.34

/*
知识点1：名字查找的顺序：由内而外、自上而下

知识点2：类的定义处理步骤：首先编译成员的声明，直到类全部可见是再编译函数体

即成员函数在类的声明全部处理完之后才会被定义，所以可以调用函数中定义的任何名字

知识点3：在类中，类型名要特殊处理，最好是定义在类的一开始，并且不能与外层作用域中同名

此题中，会出现错误：pos未定义


class Screen_08
{
public:
	
	void dummy_fcn(pos hight)
	{
		cursor = width * height;   //哪个height？是哪个参数？  成员height
		cursor = width * this->height; //成员height
		//另一种表示该成员的方式
		cursor = width * Screen_08::height;   //成员height

		cursor = width * ::height;    //哪个height？  是那个全局的

		//NOTE:尽管外层的对象被隐藏掉了，但我们仍然可以用作用域运算符访问它。
	}

private:
	pos cursor = 0;
	pos height = 0, width = 0;
	typedef std::string::size_type pos;   
};
*/

//练习7.35
typedef string Type;
Type initVal();
class Exercise
{
public:
	typedef double Type;
	Type setVal(Type);
	//Type initVal();  //无法解析的外部符号 "public: double __thiscall Exercise::initVal(void)" (?initVal@Exercise@@QAENXZ)，该符号在函数 "public: double __thiscall Exercise::setVal(double)" (?setVal@Exercise@@QAENN@Z) 中被引用
	Type initVal() { return MyType; }  //编译通过。

private:
	int val;
	Type MyType;
};

Type Mytype02;
//Type Exercise::setVal(Type parm) //kael：这里的返回Type 是全局的类型：typedef string Type; //编译报错:error C2556: “Type Exercise::setVal(Exercise::Type)”: 重载函数与“Exercise::Type Exercise::setVal(Exercise::Type)”只是在返回类型上不同
Exercise::Type Exercise::setVal(Type parm)  
{
	val = parm + initVal();      // warning C4244: “=”: 从“Exercise::Type”转换到“int”，可能丢失数据

	//return  val;  
	return MyType;
	//return Mytype02;
}

//构造函数再探
//构造函数的初始值有时必不可少
//如果成员是const或者是引用的话，必须将其初始化。类似的，当成员属于某种类类型且该类没有定义默认构造函数时，也必须将这个成员初始化。
class ConstRef
{
public:
	ConstRef(int ii);
private:
	int i;
	//const int ci;  //kael：未初始化，会导致定义构建函数时，报错： error C2789: “ConstRef::ci”: 必须初始化常量限定类型的对象
	const int ci =0;
	//int &ri;     //kael：未初始化，会导致定义构建函数时，报错： error C2530: “ConstRef::ri”: 必须初始化引用
	int &ri = i;
};

ConstRef::ConstRef(int ii)
{
	i = ii;			//正确
	//ci = ii;			//错误：不能给const赋值  
	//ri = i;			//错误：ri 没被初始化		//

}
/*
Note: 如果成员时Const、引用，或者属于某种未提供默认构造函数的类类型，我们必须通过构造函数初始化列表为这些成员提供初值。

建议：使用构造函数初始化
		在很多类中，初始化和赋值的区别事关底层效率的问题：前者直接初始化数据成员，后者则先初始化在赋值。
		除了效率问题外更重要的是，一些数据成员必须被初始化。建议读者养成使用构造函数初始化的习惯，这样能避免某些竟意想不到的编译错误，特别是遇到有的类含有需要构造函数初始化的成员时。
*/

//成员初始化的顺序
//构造函数初始值列表只说明用于初始化成员的值，而不限定初始化的具体执行顺序。
//！！！不过如果一个成员时用另一个成员来初始化的，那么这两个成员的初始化顺序就很关键了。
class XXX
{
	int i;
	int j;
public:
	//未定义的：i在j之前被初始化
	XXX(int val) :j(val), i(j) {};  //kael：编译通过，但这种初始化方式，可能会导致一些问题？？？？？
	/*
	从构造函数初始值的形式上来看仿佛是先用val初始化了j，然后再用j初始化i。实际上，i先被初始化，因此这个初始化的效果是试图使用未定义的值j初始化i ！

	Best practices：最好令构造函数初始值的顺序与成员声明的顺序保持一致。而且如果可能的话，尽量避免使用某些成员初始化其他成员。
	
	*/
};

//练习：7.38
/*
Sales_data(std::istream &is = std::cin) { read(is, *this); }//将默认实参直接赋予变量即可
*/

class MyTestClass
{
public:
	 string mystring = " ";

	 //MyTestClass(string a) ;//构造函数只声明未定义：无法解析的外部符号 "public: __thiscall MyTestClass::MyTestClass(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)
	 MyTestClass(string a) {};
	//MyTestClass(std::istream myIstream);
};
void test_07()
{
	MyTestClass Mytestclass02("string");
	

}

//委托构造函数

//练习7.41
//知识点1：委托构造函数：一个委托构造函数使用它所属类的其他构造函数执行它自己的初始化过程
class OH
{
	//kael_依据下面的例子，可以了解，委托构造函数的重点是，自己的初始化过程，看符合“：”后面的内容。可理解。
	OH(string s, int a, int b) :book(s), price(a), sale(b) {}   //三参数构造函数列表和函数体首先被执行
	OH() :OH("", 0, 0) {} //默认构造函数又委托给了三参数构造函数
	OH(istream& is) :OH() {}    //OH(istream& is) 是一个委托构造函数，它委托给了构造函数OH()


	string book;
	int price;
	int sale;

};

//知识点2：当构造函数委托给另一个构造函数时，受委托的构造函数的初始值列表及其函数体先被执行，接着才会执行到委托函数的函数体
class OH_02
{
public:
	OH_02(string s, int a, int b) :book(s), price(a), sale(b) { cout << "OH(string s, int a, int b)" << endl; } //三参数构造函数列表和函数体首先被执行
	OH_02() :OH_02("", 0, 0) {} //默认构造函数又委托给了三参数构造函数
	OH_02(istream& is) :OH_02() { cout << "OH(istream& is)" << endl; } //OH_02(istream& is) 是一个委托构造函数，它委托给了构造函数OH_02()

	string book;
	int price;
	int sale;
};
//Best Practices :如果定义了其他构造函数，那么最好也提供一个默认构造函数。



/*
//类的构造函数在初始化成员时，有以下两种方法：
方式一：

CSomeClass::CSomeClass()
{

	x = 0;

	y = 1;

}

方式二：

CSomeClass::CSomeClass() : x(0), y(1)
{
}

方式一我们可以称为赋值初始化，通过在函数体内进行赋值初始化。

方式二我们称为列表初始化，在冒号后使用初始化列表进行初始化。

这两种方式的主要区别在于：
对于在函数体中初始化, 是在所有的数据成员被分配内存空间后才进行的。

所以最好使用第二种方法。
*/

//Note ：能通过一个实参调用的构造函数定义了一条从构造函数的参数类型向类类型隐式转换的规则。


//抑制构造函数函数定义的隐式转换
//在要求隐式转换的程序上下文中，我们可以通过将构造函数声明为explicit加以阻止：
class Sales_data_02 
{
public:
	Sales_data_02() = default;
	Sales_data_02(const std::string &s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(p*n) {}

	//Note：我们用explicit关键字声明构造函数时，它将只能以直接初始化的形式使用。而且，编译器将不会在自动转换过程中使用该构造函数。
	explicit Sales_data_02(const std::string &s) :bookNo(s) {}
	explicit Sales_data_02(std::istream&);
	explicit Sales_data_02(string c, int a);
private:
	string bookNo;
	unsigned units_sold;
	double revenue;

};
/*
//page ：265
//此时，没有任何构造函数能用于隐式地构建 Sales_data_02 对象，之前的两种用法都无法通过编译：
item.combine(null_book);   //错误：string 构造函数是explicit的
item.combine(cin);				//错误：istream构造函数是explicit的
*/

//为转换显式地使用构造函数
/*
page ：265
尽管编译器不会将explicit的构造函数用于隐式转换过程，但是我们可以使用这样的构造函数显式地强制进行转换：

//正确:实参是一个显式构造的Sales_data对象
item.combine(Sales_data(null_book));

//正确：static_cast 可以使用expicit 的构造函数
item.combine(static_cast<Sales_data>(cin));

*/

//7.5.5 聚合类
/*
聚合类（aggregate class）使得用户可以直接访问其成员，并且具有特殊的初始化语法形式。当一个类满足以下条件时，我们说它时聚合的：
*所有成员都是public的。
*没有定义任何构造函数。
*没有类内初始值
*没有基类，也没有virtual函数

*/

//例如，下面的类是一个聚合类：
struct Data
{
	int ival;
	string s;
};

//vall.ival =0 ; vall.s =string("Anna")
Data vall = { 0,"Anna" }; //我们可以提供一个花括号括起来的成员初始化列表，并用它初始化聚合类的数据成员：

//错误：不能使用“Anna”初始化ival，也不能使用1024 初始化 s
//Data val2 = {"Anna", 0}; //初始值的顺序必须与声明的顺序一致

/*
如果初始值列表中的元素个数少于类的成员数量，则靠后的成员被值初始化。初始化列表的元素个数绝对不能超过类的成员数量。

值得注意的是，显式地初始化类的对象的成员存在三个明显的缺点：

*要求类的所有成员都是Public的
*将正确初始化每个对象的每个成员的重任交给了类的用户（而非类的作者）。因为用户很容易忘掉某个初始值，或者提供一个不恰当的初始值，所以这样的初始化过程坑长乏味且容易出错。
*添加或者删除一个成员以后，所有的初始化语句都需要更新

*/

//7.5.6  字面值常量类
/*
数据成员都是字面值类型的聚合类是字面值常量类。如果一个类不是聚合类，但它符合下述要求，则也是一个字面值常量类：
*数据成员都必须是字面值类型
*类必须至少含有一个constexpr构造函数
*如果一个数据成员含有类内初始值，则内置类型成员的初始值必须是一条常量表达式；或者如果成员属于某种类类型，则初始值必须使用成员自己的consexpr构造函数。
*类必须使用析构函数的默认定义，该成员负责销毁类的对象。

*/


//constexpr 构造函数体一般来说应该是空的。我们通过前置关键字constexpr就可以声明一个constexpr构造函数
//constexpr构造函数必须初始化所有数据成员，初始值或者使用constexpr构造函数，或者是一条常量表达式。

class Debug
{
	constexpr Debug(bool b = true) :hw(b), io(b), other(b) {}
	constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) {}
	constexpr bool any() { return hw || io || other; }

	void set_io(bool b) { io = b; }
	void set_hw(bool b) { hw = b; }
	void set_other(bool b) { hw = b; }

private:
	bool hw;				  //硬件错误，而非IO错误  ？
	bool io;				//IO错误  ？
	bool other;			//其他错误	？



};


//7.6  类的静态成员

//有的时候类需要它的一些成员与类本身直接相关，而不是与类的各个对象保持关联。
/*
*类的静态成员存在于任何对象之外，对象中不包含任何与静态数据成员有关的数据。因此，每个Accout对象将包含两个数据成员：owner和amout。
只存在一个interestRate对象而且它被所有Account对象共享。

*类似的，静态成员函数也不与任何对象绑定在一起，它们不包含this指针。作为结果，静态成员函数不能声明成const的，而且我们也不能在static函数体内使用this指针。
这一限制及适用与this的显式使用，也对调用非静态成员的隐式使用有效。

*/
class Account_02
{
public:
	void calculate() { amount += amount * interestRate; }
	static double rate() { return interestRate; }
	static void rate(double);

private:
	std::string  owner;
	double amount;
	static double interestRate;
	//static double initRate(); //kael：不管有没有：double Account_02::interestRate = initRate(); 无法解析的外部符号 "private: static double Account_02::interestRate" 
	static double initRate() { return interestRate; }  //kael：如果没有double Account_02::interestRate = initRate();， 则出现：无法解析的外部符号 "private: static double Account_02::interestRate"
};

//使用类的静态成员

void test_08() {
Account_02 ac1;
Account_02*ac2 = &ac1;
double r;
r = Account_02::rate();    //使用作用域运算符访问静态成员

r = ac1.rate();					//通过Account的对象或引用
r = ac2->rate();				//通过指向Account对象的指针
}

//定义静态成员
//当在类的外部定义静态成员时，不能重复static关键字，该关键字只出现在类的内部的声明语句：
void Account_02::rate(double newrate)
{
	interestRate = newrate;
}
//Note:  和类的所有成员一样，当我们指向类外部的静态成员时，必须指明成员所属的类名。static关键字则只出现在类内部的声明语句中。

/*
因为静态数据成员不属于类的任何一个对象，所以它们并不是在创建类的对象时被定义的。这意味着它们不是由类的构造函数初始化的。而且一般来说，我们不能在类的内部
初始化静态成员。相反的，必须在类的外部定义和初始化每个静态成员。和其他对象一样，一个静态数据成员只能定义一次。
		类似于全局变量，静态数据成员定义在任何函数之外。因此一旦它被定义，就将一直存在于程序的整个生命周期中。
*/

//定义并初始化一个静态成员
double Account_02::interestRate = initRate();
/*
上面这条语句定义了名为interestRate 的对象，该对象时类Account的静态成员，其类型时double。从类名开始，这条定义语句的剩余部分就都位于类的作用域之内了。
因此，我们可以直接使用initRate函数。注意：虽然initRate时私有的，我们也能用它初始化interestRate。和其他成员的定义一样，interestRate的定义也可以访问类的私有成员。

*/

/*
TIP：要想确保对象只定义一次，最好的方法是把静态成员的定义与其他非内联函数的定义放在同一个文件中。

*/


//静态成员的类内初始化
/*
Best Practices ：即使一个常量静态数据成员在类内部被初始化了，通常情况下也应该在类的外部定义一下该成员
*/

//静态成员能用于某些场景，而普通成员不能

//静态数据成员的类型可以就是它所属的类类型。而非静态数据成员则受限制，只能声明成它所属的指针或引用：
class Bar 
{
private:
	static  Bar mem1;  //正确：静态成员可以是不完全类型
	Bar*  mem2;				//正确：指针成员可以是不完全类型
	//Bar mem3;				//错误：数据成员必须是完全类型
	/*
类的定义和声明也可以像函数一样分开。
栗子：

class CSys;

上述声明被称为前向声明。对于CSys来说，其声明之后和定义之前，被称为不完全类型。
	
	*/
};
//静态成员和普通成员的另外一个区别是我们可以使用静态成员作为默认实参：
class Screen_8
{
public:
	//Bkground 表示一个在类中稍后定义的静态成员
	Screen_8& clear(char = bkground);

private:
	static const char bkground;
};

//练习：7.56
/*
知识点1：类的静态成员：该成员只需与类的本身有关，而不是与类的对象有关，加上static关键字即可声明，其不与任何实例化对象绑定，但是我们仍然可以使用类作用域运算符访问静态成员。
知识点2：static声明在内部。在外部定义时，不加static.类似与一个全局变量，其初始值必须是常量表达式。
知识点3：静态成员独立于任何对象，其类型可以是它所属的类类型。而非静态成员只能声明为其类的指针或引用

*/






/*
非静态数据成员不能作为默认实参，因为它的值本身属于对象的一部分，这么做的结果是无法真正提供一个对象以便从中获取成员的值，最终将引发错误。
*/


/*

int main()
{
	OH_02 myoh_02; //创建对象，OH_02，执行构造函数初始化，从而输出：OH(string s, int a, int b)

	system("pause");
}

*/