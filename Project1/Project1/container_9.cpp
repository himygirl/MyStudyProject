#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <list>
#include <deque>
#include <forward_list>
#include <array>
#include <stdint.h>
#include <deque>
using namespace std;


//一个容器就是一些特定类型对象的集合
//9.1 顺序容器概述
/*
							顺序容器类型
vector				可变大小数组。支持快速随机访问。在尾部之外的位置插入或删除元素可能很慢
deque				双端队列。支持快速随机访问。在头尾位置插入/删除速度很快
list					双向链表。只支持双向顺序访问。在list中任何位置进行插入/删除操作速度都很快
forward_list		单向链表。只支持单向顺序访问。在链表任何位置进行插入/删除操作书店都很快
array				固定大小数组。支持快速随机访问。不能添加或删除元素
string				与vector相似的容器，但专门用于保存字符。随机访问快。在尾部插入/删除速度快


list和forward_list两个容器的设计目的是令容器任何位置的添加和删除操作都很快速。作为代价，这两个容器不支持元素的随机访问：为了访问一个元素，我们只能
遍历整个容器。而且，与vector、deque和array相比，这两个容器的额外内存开销也很大。
deque是一个更为复杂的数据结构。与string和vector类似，deque支持快速的随机访问。与string和vector一样，在deque的中间位置添加或删除元素的代价（可能）
很高。但是，在deque的两端添加或删除元素都是很快的，与list或forward_list添加删除元素的速度相当。

//以下是一些选择容器的基本原则：

*除非你有很好的理由选择其他容器，否则应使用vector。
*如果你的程序有很多小的元素，且空间的额外开销很重要，则不要使用list或forward_list
*如果程序要求随机随机访问元素，应使用vector或deque
*如果程序要求在容器的中间插入或删除元素，应使用list或forward_list
*如果程序需要在头尾位置插入或删除元素，但不会在中间位置进行插入或删除操作，则使用deque。
*如果程序只有在读取输入时才需要在容器中间位置插入元素，随后需要随机访问元素，则
---首先，确定是否真的需要在容器中间位置添加位置。当处理输入数据时，通常可以很容易地向vector追加数据，
然后在调用标准库的sort函数来重排容器中的元素，从而避免在中间位置添加元素。
---如果必须在中间位置插入元素，考虑在输入阶段使用list，一旦输入完成，将list中的内容拷贝到一个vector中。


Best Practices：
	如果你不确定应该使用哪种容器，那么可以在程序中只使用vector和list公共的操作：使用迭代器，不使用下标操作，避免随机访问。
	这样，在必要时选择使用vector或list都很方便

	练习：9.1 节练习
知识点1：几种顺序容器的特点

vector：可变大小，支持快速随机访问，尾部插入数据很快

deque：双端队列。支持快速随机访问，头部插入数据很快

list：双向链表。支持双向顺序访问，在其任何位置插入删除数据都很快

array：固定大小数组，不能改变大小。(注意这里与普通的内置数组类型是不一样的)

string：与vector类似，专用于保存字符。

知识点2：在通常情况下，使用vector是非常好的选择。且新版本的标准库容器比旧版本快很多。C++程序应该使用标准库容器，而不是原始的数据结构如：内置数组。



(a)list，因为可能需要在容器的中间位置插入元素

(b)deque，因为需要在头部进行元素的删除，deque效率更高

(c)vector，无具体的删除插入操作，未知数量，vector是个不错的选择。


*/

/*
													表9.2：容器操作
类别名称
iterator							此容器类型的迭代器类型
const_iterator				可以读取元素，但不能修改元素的迭代器类型
size_type						无符号整数类型，足够保存此种容器类型最大可能容器的大小
difference_type			带符号整数类型，足够保存两个迭代器之间的距离
value_type					元素类型
reference						元素的左值类型；与value_type&含义相同
const_reference			元素的const左值类型

构造函数
C c；				 默认构造函数，构造空容器（array）
C c1(c2);			 构造c2的拷贝c1
C c(b,e);			构造c，将迭代器b和e指定的范围内的元素拷贝到c（array不支持）
C c(a,b,c......)		列表初始化c

赋值与swap
c1 = c2				 将c1中的元素替换为c2中元素
c1 = {a,b,c.....}	将c1中的元素替换为列表中元素(不适用于array)
a.swap(b)			交换a和b的元素
swap(a,b)			与a.swap(b)的元素

大小
c.size()				c中元素的数目(不支持forward_list)
c.max_size()		c可保存的最大元素数目
c.empty()			若c中储存了元素，返回false，否则返回true

添加/删除元素(不适用于array)
注：在不同容器中，这些操作都不同
c.insert(args)			将args中的元素拷贝进c
c.emplace(inits)		使用inits构造c中的一个元素
c.erase(args)			删除args指定的元素
c.clear()					删除c中的所有元素，返回void

关系运算符
==，!=						所有容器都支持相等（不等）运算符
<,<=,>,>=				关系运算符（无序关联容器不支持）

获取迭代器
c.begin(), c.end()				返回指向c的首元素和尾元素之后位置的迭代器
c.cbegin(),c.cengd()			返回const_iterator

反向容器的额外成员(不支持forward_list)
revere_iterator							按逆序寻址的迭代器
const_reverse_iterator				不能修改元素的逆序迭代器
c.rbegin(),c.rend()					返回指向c的尾元素和首元素之前位置的迭代器
c.crbegin(),c.crend()					返回const_reverse_iterator
*/

//迭代器范围
/*
一个迭代器范围由一对迭代器表示，两个迭代器分别指向同一个容器中的元素或者是尾元素之后的位置。这两个迭代器通常被称为begin和end，
或者是first和last(可能有些误导)，它们标记了容器中元素的一个范围。
		这种元素范围被称为左闭合区间，其标准数学描述为
		[begin,end)
表示范围自begin开始，于end之前结束。迭代器begin和end必须指向相同的容器。end可以与begin指向相同的位置，但不能指向begin之前的位置。


*/

//练习9.3
/*
知识点1：限制如下：

迭代器指向同一个容器或者最后一个元素之后的位置

可以反复递增begin直到end

知识点2：迭代器指向的元素范围是左闭合区间，注意end指向的是最后一个元素之后的位置
*/

//练习9.4,编写函数，接受一对指向vector<int>的迭代器和一个int值。在两个迭代器指定的范围中查找给定的值，返回一个布尔值来指出是否找到

bool find1(vector<int>::iterator a, vector<int>::iterator b, int c)//迭代器的类型要弄清楚
{
	for (a; a != b; a++)
	{
		if (*a == c)//迭代器需进行解引用操作
		{
			return true;
		}
	}
	return false;
}

void Test()
{

	vector<int> vec(20);//必须事先指定这个大小，才知道end的指向
	vec[0] = 4;
	vec[1] = 5;
	vec[2] = 2;
	vec[3] = 8;
	vec[4] = 9;
	vec[5] = 6;
	vec[6] = 7;//使用VS1010，不支持列表初始化，见谅
	int find_member = 1;
	if (find1(vec.begin(), vec.end(), find_member))
	{
		cout << "We have found it" << endl;
	}
	else
		cout << "Sorry,there is no " << find_member << " in the range" << endl;

}

//练习9.4：重写上一题的函数，返回一个迭代器指向找到的元素。注意，程序必须处理未找到给定值的情况。

vector<int>::iterator find2(vector<int>::iterator a, vector<int>::iterator b, int c)//迭代器的类型要弄清楚
{
	for (a; a != b; a++)
	{
		if (*a == c)//迭代器需进行解引用操作
		{
			return a;
		}
	}
	return b;//未找到的情况，返回最后一个迭代器
}

void Test02()
{
	vector<int> vec(20);//必须事先指定这个大小，才知道end的指向
	vec[0] = 4;
	vec[1] = 5;
	vec[2] = 2;
	vec[3] = 8;
	vec[4] = 9;
	vec[5] = 6;
	vec[6] = 7;//使用VS1010，不支持列表初始化，见谅
	int find_member = 1;
	if (find2(vec.begin(), vec.end(), find_member) != vec.end())
	{
		cout << "We have found it" << endl;
	}
	else
		cout << "Sorry,there is no " << find_member << " in the range" << endl;
}


//练习9.6
/*
下面程序有何错误？你应该如何修改它？

list<int>	lst1;
list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();

while(iter1<iter2){}

答：
迭代器之间无大于小于号的比较
两个迭代器不在同一容器内不能直接比较？？？？（kael疑问：不在同一个容器？）
while(*iter1<*iter2){}

*/

//练习9.7
//为了索引 int 的vector中的元素，应该使用什么类型？
//vector<int>::size_type   //size_type指的是无符号整数类型

//练习9.8：
//为了读取string的list中的元素，应该使用什么类型？如果写入list，又该使用什么类型？
//知识点：读和写的不同，如果要写则返回的必然不能是const iterator
/*
list<string>::iterator || list<string>::const_iterator  //读操作
list<string>::iterator //写操作
*/

//9.2.3 begin 和 end 成员
/*
不以c开头的函数都是被重载过的。也就是说，实际上又两个名为begin的成员。一个是const成员，返回容器的const_iterator类型。另一个是非常量成员，
返回容器的iterator类型。rbegin、end和rend的情况类似。当我们对一个非常量对象调用这些成员时，得到的是返回iterator的版本。
只有在对一个const对象调用这些函数时，才会得到一个const版本。与const指针和引用类似，可以将一个普通的iterator转换为对应的const_iterator,反之不行。

*/
void Test03()
{
	list<string> a = { "Milton","Shakespeare","Austen" };
	auto it1 = a.begin(); //list<string>::iterator
	auto it2 = a.rbegin(); //list<string>::reverse_iterator
	auto it3 = a.cbegin(); //list<string>::const_iterator
	auto it4 = a.crbegin(); // list<string>::const_reverse_iterator

//显式指定类型
	list<string>::iterator  it5 = a.begin();
	list<string>::const_iterator it6 = a.begin();
	//是iterator还是cosnt_iterator依赖于a的类型
	auto it7 = a.begin();  //仅当a是const时，it7是const_iterator
	auto it8 = a.cbegin(); //it8是cosnt_iterator

	/*
	当auto与begin或end结合使用时，获得的迭代器类型依赖于容器类型，与我们想要如何使用迭代器毫不相干。
	但以c开头的版本还是可以获得const_iterator的，而不管容器的类型时什么。
	*/
}
//Best Pratices   ： 当不需要访问时，应使用cbegin和cend。

//练习9.10
//下面4个对象分别时什么类型
void Test04()
{
	vector<int> v1;						
	const vector<int> v2;		

	//auto it1 = v1.begin(),it2 = v2.begin(); // error C3538: 在声明符列表中，“auto”必须始终推导为同一类型
	auto it1 = v1.begin();	//vector<int>::iterator
	auto it2 = v2.begin();		//const vector<int>::iterator
	auto it3 = v1.cbegin();		//vector<int>::const_iterator
	auto it4 = v2.cbegin();		//const vector<int>::cosnt_iterator
}

//容器定义和初始化
/*
每个容器类型都定义了一个默认构造函数。除array之外，其他容器的默认构造函数都会创建一个指定类型的空容器，且都可以接受指定容器大小和元素初始值的参数


																	容器定义和初始化
C c； 默认构造函数。如果C是一个array，则c中元素按默认方式初始化；否则c为空

C c1(c2)   c1初始化为c2的拷贝。c1和c2必须是相同类型(即，它们必须是相同的容器类型，且保存的是相同的元素类型；对于array类型，两者还必须具有相同大小)
C c1 = c2				

C c{a,b,c...}	c初始化为初始化列表中元素的拷贝。列表中元素的类型必须与C的元素类型相容。对于array类型，列表中元素数目必须等于或小于array的大小，
C c={a,b,c...}					任何遗漏的元素都进行值初始化

C c(b,e)		c初始化为迭代器b和e指定范围中的元素的拷贝。范围中元素的类型必须与C的元素类型相容(array不适用)

只有顺序容器(不包括array)的构造函数才能接受大小参数
C seq(n)		seq 包含n个元素，这些元素进行了值初始化；此构造函数是explicit的。(string 不适用)
C seq(n,t)		seq包含n个初始化为值t的元素
*/

void Test05()
{
	list<string> authors = { "Milton","Shakespeare","Austen" };
	vector<const char*> articles = { "a", "an","the" };

	list<string> list2(authors); //正确：类型匹配
	//deque<string> authList(authors); //错误：容器类型不匹配
	//vector<string> words(authors);  //错误：容器类型不匹配
	//正确：可以将const char* 元素转换为string
	forward_list<string> words(articles.begin(), articles.end());

}

//Note：只有顺序容器的构造函数才接受大小参数，关联容器并不支持

//值得注意的是，虽然我们不能对内置数组类型惊喜拷贝或对象赋值操作，但array并无此限制:
void Test06()
{
	int digs[10] = {0,1,2,3,4,5,6,7,8,9}; 
	//int cpy[10] = digs;    //错误：内置数组不支持拷贝或赋值
	array<int,10> digits = { 0,1,2,3,4,5,6,7,8,9};
	array<int, 10> copy = digits;   //正确：只要数组匹配即合法

}

//练习9.11
//对6种创建和初始化vector对象的方法，每一种都给出一个实例。解释每个vector包含什么值
void Test07()
{
//注意C++11新标准中vector初始化的方法(除了array以外的标准库容器皆适用)
/*
	vector<int> vec;
	vector<int> vec(10);
	vector<int> vec(10, 1);
	vector<int> vec{ 1,2,3,4,5 };
	vector<int> vec(other_vec);
	vector<int> vec(other_vec.begin(), other_vec.end());
*/
}

//练习9.13
void Test08()
{
	//拷贝使用的list和vector
	list<int> list1(7, 8);
	vector<int> vec2(5, 2);

	//创建的目标容器
	vector<double> vec1(list1.begin(), list1.end());
	vector<double> vec3(vec2.begin(), vec2.end());

	//验证正确性
	vector<double>::iterator it1 = vec1.begin();
	vector<double>::iterator it2 = vec3.begin();
	for (it1; it1 != vec1.end(); it1++)
	{
		cout << *it1 << endl;
	}
	for (it2; it2 != vec3.end(); it2++)
	{
		cout << *it2 << endl;
	}

}

void Test09()
{
	uint8_t  abc;
	

}
// 赋值和swap

//与内置数组不同，标准库array类型允许赋值。赋值号左右两边的运算对象必须具有相同的类型：
void Test10()
{
array<int, 10> a1 = { 0,1,2,3,4,5,6,7,8,9 }; 
array<int, 10> a2 = { 0 };  //所有元素值均为 0
a1 = a2;  //替换a1中的元素
//a2 = { 0 };   //错误：不能将一个花括号列表赋予数组

//由于右边运算对象的大小可能与左边运算对象的大小不同，因此array类型不支持assign，也不允许用花括号包围的值列表赋值
}

/*
												容器赋值运算
c1= c2           将c1中的元素替换为c2中的元素的拷贝。c1和c2必须具有相同的类型
c={a,b,c.....}	将c1中元素替换为初始化列表中元的拷贝（array不适用）

swap(c1,c2)	交换c1和c2中的元素。c1和c2必须具有相同的类型。swap通常比从c2向c1拷贝元素快的多
c1.swap(c2)


assign操作不适用于关联容器和array
seq.assign(b,e)  将seq中的元素替换为迭代器b和e 所表示的范围中的元素。迭代器b和e不能指向seq中的元素
seq.assign(il)	 将seq中的元素替换为初始化列表il中的元素
seq.assign(n,t)  将seq中的元素替换为n个值为t的元素

Warning   赋值相关运算会导致指向左边容器内部的迭代器、引用和指针失效。而swap操作将容器内容交换不会导致
指向容器的迭代器、引用和指针失效（容器类型为array和string的情况除外）

*/

//使用assign（仅顺序容器） //kael：assign 赋值方法

void Test11()
{
	list<string> names;
	vector<const char*> oldstyle;
	//names = oldstyle; //错误：容器类型不匹配

	//正确：可以将const char*转换为string
	names.assign(oldstyle.cbegin(), oldstyle.cend());

//warning   由于其旧元素被替换，因此传递给assign的迭代器不能指向调用的assign的容器？？？？？

	//assign的第二个版本接受一个整形值和一个元素值。它用指定数目且有相同给定值的元素替换容器中原有的元素：

	//等价slist1.clear；
	//后跟slist1.insert（slist1.begin(),10,"Hiya!"）;
	list<string> slist1(1); //1个元素，为空string
	slist1.assign(10, "Hiya!"); //10个元素，每个都是"Hiya！"

}

//使用swap
//swap操作交换两个相同类型容器的内容，调用swap之后，两个容器中的元素将会交换：

void Test12()
{
	vector <string> svec1(10); //10个元素的vector
	vector<string> svec2(24); //24个元素的vector
	swap(svec1, svec2);
	/*
	调用swap后，svec1将包含24个string元素，svec2将包含10个string。
	除array外，交换两个容器内容的操作保证会很快----元素本身并未交换，swap只是交换了两个容器的内部数据结构。
	*/

	//Note   除array外，swap不对任何元素进行拷贝、删除或插入操作，因此可以保证在常数时间内完成

}

//关系运算符

void Test13()
{
	vector<int> v1 = { 1,3,5,7,9,12 };
	vector<int>v2 = { 1,3,9 };
	vector<int>v3 = { 1,3,5,7 };
	vector<int>v4 = { 1,3,5,7,9,12 };

	v1 < v2;   //Ture; v1和v2在元素[2]处不同：v1[2]小于等于V2[2]
	v1 < v3;  //false; 所有元素都相等，但v3中元素数目更少
	v1 == v4; //true; 每个元素都相等，且v1 和v4大小相同
//	v1 == v2； //false； v2元素数目比v1少

}

//顺序容器操作
//顺序容器和关联容器的不容之处在于两者组织元素的方式

//向顺序容器添加元素
/*
										向顺序容器添加元素的操作
这些操作会改变容器的大小；array不支持这些操作

forward_list 有自己专有版本的insert和emplace；
forward_list 不支持push_back和emplace_back.
vector和string 不支持push_fornt 和emplace_front.

c.push_back(t)			在c的尾部创建一个值为t或由args创建的元素，返回void
c.emplace_back(args)

c.push_front(t)			在c的头部创建一个值为t或由args创建的元素，返回void
c.emplace_front(args)

c.insert(p,t)				在迭代器p指向的元素之前创建一个值为t或由args创建的元素。返回指向新添加的元素的迭代器
c.emplace(p,args)

c.insert(p,n,t)			在迭代器p指向的元素之前插入n个值为t的元素。返回指向新添加的第一个元素的迭代器；若n为0，则返回p

c.insert(p,b,e)			将迭代器b和e指定的范围内的元素插入到迭代器p指向的元素之前。b和e不能指向c中的元素。返回指向新添加的第一个元素的迭代器；
								若范围为空，则返回p


c.insert(p,il)				il是一个花括号包围的元素值列表。将这些给定值插入到迭代器p指向的元素之前。返回指向新添加的第一个元素的迭代器；
								若列表为空，则返回p

Warning   向一个vector、string或deque 插入元素会使所有指向容器的迭代器、引用和指针失效

*/

void Test14()
{
	vector<string> svec;
	list<string> slist;

	//等价于调用slist.push_front("Hello!");
	slist.insert(slist.begin(), "Hello!");

	//vector不支持push_front,但我们可以插入到begin()之前
	//警告：插入到vector末尾之外的任何位置都可能很慢
	svec.insert(svec.begin(), "Hello!");

	//将10个元素插入到svec的末尾，并将所有元素都初始化为string“Anna”
	svec.insert(svec.end(), 10, "Anna");

	vector<string> v = { "quasi","simba","frollo","scar" };

	//将v的最后两个元素添加到slist的开始位置
	slist.insert(slist.begin(), v.end() - 2, v.end());
	slist.insert(slist.end(), { "these","Words","well","go","at","the","end" });


	//运行时错误：迭代器表示要拷贝的范围，不能指向于目的位置相同的容器
	//slist.insert(slist.begin(), slist.begin(), slist.end());


}

//使用insert的返回值

void Test15()
{
	list<string> lst;
	auto iter = lst.begin();
	string wold = "a";
	while (cin>>wold)
	{
		iter = lst.insert(iter, wold);
	}
	//Note:理解这个循环式如何工作的非常重要，特别式理解这个循环为什么等价于调用push_front尤为重要
}

//使用emplace操作
/*
新标准库引入了三个新成员---emplace_front、emplace和emplace_back,这些操作构造而不是拷贝元素。这些操作分别对应push_front、insert和push_back,
允许我们将元素放置在容器头部、一个指定位置之前或容器尾部。


//假定c保存Sales_data元素

//在c的末尾构造一个Sales_data对象
//使用三个参数的Sales_data构造函数
c.emplace_back("978-0590353403",25,15.99);

//错误：没有接受三个参数的push_back版本
c.push_back("978-0590353403",25,15.99);

//正确：创建一个临时的Sales_data对象传递给push_back
c.push_back(Sales_data("978-0590353403",25,15.99))



emplace函数的参数根据元素类型而变化，参数必须于元素类型的构造函数相匹配：
//iter指向c中一个元素，其中保存了Sales_data元素
c.emplace_back(); //使用Sales_data的默认构造函数
c.emplace(iter,"999-9999999");  //使用Sales_data(string)

//使用Sales_data的接受一个ISBN、一个count和一个price的构造函数
c.emplace_front("978-0590353403",25,15.99);

Note: emplace 函数在容器中直接构造元素。传递给emplace函数的参考必须于元素类型的构造函数相匹配
*/

//练习9.18
/*
知识点：向标准容器中添加元素的方法：

1：push_back()

2：push_font()

3：emplace()

4：insert()

*/
void Test16()
{
	deque<string> deque1;
	string buf;
	while (cin >> buf)
	{
		deque1.push_back(buf);//向标准容器中添加元素
	}
	deque<string>::iterator it1 = deque1.begin();
	for (it1; it1 != deque1.end(); it1++)
	{
		cout << *it1 << endl;
	}

}

//练习9.19
void Test17()
{
	list<string> deque1;
	string buf;
	while (cin>>buf)
	{
		deque1.push_back(buf);
	}
	list<string>::iterator it1 = deque1.begin();
	for (it1;it1!=deque1.end();it1++)
	{
		cout << *it1 << endl;
	}

}

//练习9.20
void Test18()
{
	list<int> list1(5, 7);
	deque<int> deque1;
	deque<int> deque2;
	list<int>::iterator it1 = list1.begin();
	for (it1; it1 != list1.end(); it1++)
	{
		if ((*it1) % 2 == 0)
		{
			deque1.push_back(*it1);
		}
		else
		{
			deque2.push_back(*it1);
		}
	}

	deque<int>::iterator it2 = deque1.begin();
	deque<int>::iterator it3 = deque2.begin();
	cout << "偶数为：";
	for (it2; it2 != deque1.end(); it2++)
	{
		cout << *it2 << " ";
	}
	cout << endl;
	cout << "奇数为：";
	for (it3; it3 != deque2.end(); it3++)
	{
		cout << *it3 << " ";
	}

}

//练习9.22

void Tes19()
{
	/*
	知识点1：迭代器加上固定的数字指的是迭代器的增长，而不是数值的增长，此处加上iv.size()/2是正确的。

题目的意思应该是判断前半部分的元素有无与某值相等的元素，如有则在其前插入一个两倍的某值。

insert()操作有返回值，此题为无限循环，且插入元素后，mid做为一个引用会失效

	*/

	vector <int> iv;
	iv.reserve(25);// 为vector预留空间，在后面的节中可以看到
	int some_val = 10; //kael——add

	vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size() / 2;
	while (iter != mid)
		if (*mid == some_val)
			mid = iv.insert(mid, 2 * some_val);
		else
			--mid;



}


//访问元素

void Test20()
{
	array<int, 10> c = { 0,1,2,3,4,5,6,7,8,9 };
	//在解引用一个迭代器或调用front或back之前检查是否有元素
	//要确保c非空。如果容器为空，if中操作的行为将是未定义的。
	if (!c.empty())
	{
		//val 和val2是c中第一个元素值的拷贝
		auto val = *c.begin(), val2 = c.front();
		//val3和val4 是c中最后一个元素值的拷贝
		auto last = c.end();
		auto val3 = *(--last);  //不能递减forward_list迭代器
		auto val4 = c.back(); //forward_list 不支持
	}
}

/*
										在顺序容器中访问元素的操作
at和下标操作只适用于string、vector、deque和array
back 不适用于forward_list

c.back()    //返回c中尾元素的引用。若c为空，函数行为未定义
c.front()  //返回c中首元素的引用。若c为空，函数行为未定义
c[n]			//返回c中下标未n的元素的引用，n是一个无符号整形。若n>=c.size(),则函数行为未定义
c.at(n)		//返回下标未n的元素的引用。如果下标越界，则抛出一 out_of_rang异常

warning  对一个空容器调用front和back，就像使用一个越界的下标一样，是一种严重的程序设计错误

*/

//访问成员函数返回的是引用
//在容器访问元素的成员函数（即，front、back、下标和at） 返回的都是引用。如果容器是一个const对象，则返回值是const的引用

void Test21()
{
	array<int, 10> c = { 0,1,2,3,4,5,6,7,8,9 };
	if (!c.empty())
	{
		c.front() = 42;			//将42赋予c中的第一个元素
		auto&v = c.back();	//获得指向最后一个元素的引用
		v = 1024;					//改变c中的元素
		auto &v2 = c.back();	//v2不是一个引用，它是c.back()的一个拷贝
		v2 = 0;							//未改变c中的元素
	}

}

//练习9.24
//编写程序，分别使用at、下标运算符、front和begin提取一个vector中的第一个元素。在一个空vector上测试你的程序

void Test22()
{
 //知识点1：at，下表运算符，front返回的都是第一个元素的引用，而begin返回的是第一个元素的迭代器
	vector<int> vec1;
	int a = vec1.front();//terminating with uncaught exception of type std::out_of_range
	int b = vec1[0];// Segmentation fault: 11
	int c = vec1.at(0);
	int d = *vec1.begin();//需要解引用
	cout << a << " " << b << " " << c << " " << d << endl;

}

//删除元素
/*
										顺序容器的删除操作
这些操作会改变容器的大小，所以不适用于array
forward_list  有特殊版本的erase
forward_list  不支持pop_back; vector 和 string 不支持pop_front.
c.pop_back()   删除c中尾元素。若c为空，则函数行为未定义。函数返回void
c.pop_front()  删除c中首元素。若c为空，则函数行为未定义。函数返回void
c.erase(p)		删除迭代器p所指定的元素，返回一个指向被删元素的迭代器，若p指向尾元素，则返回尾后迭代器。若p是尾后迭代器，则函数行为未定义
c.erase(b,e)		删除迭代器b和e所指定范围内的元素。返回一个指向最后一个被删元素之后元素的迭代器，若e本身就是尾后迭代器，则函数也返回尾后迭代器
c.clear()		删除c中的所有元素。返回void

Warning       删除deque中除首尾元素之外的任何元素都会使所有迭代器、引用和指针失效。指向vector或string中删除点之后位置的迭代器、引用和指针都会失效

*/

//pop_front 和 pop_back成员函数
/*
   pop_front和pop_back成员函数分别删除首元素和尾元素。与vector和string不支持push_front一样，这些类型也不支持pop_front.类似的，
   forward_list不支持pop_back.与元素访问成员函数类似，不能对一个空容器执行弹出操作。

	这些操作返回void。 如果你需要弹出的元素的值，就必须在执行弹出操作之前保存它：

	while(!ilist.empty())
	{
	   process(ilist.front());  //对list的首元素进行一些处理
	   ilist.pop_front();		//完成处理后删除首元素
	}

*/

//从容器内部删除一个元素
/*
成员函数erase从容器中指定位置删除元素。我们可以删除由一个迭代器指定的单个元素，也可以删除由一对迭代器指定的范围内的所有元素。
两种形式的erase都返回指向删除的（最后一个）元素之后位置的迭代器。即，若j是i之后的元素，那么erase(i)将返回指向j的迭代器
*/

//下面的循环删除一个list中的所有奇数元素：
void Test23()
{
	list<int> lst = { 0,1,2,3,4,5,6,7,8,9 };
	auto it = lst.begin();
	while (it != lst.end())
	{
		if (*it % 2) //若元素为奇数
		{
			it = lst.erase(it); //删除此元素
		}
		else
			++it;
	}

}

//删除多个元素
//接受一对迭代器的erase版本允许我们删除一个范围内的元素：
//为了删除一个容器中的所有元素，我们即可以调用clear，也可以用begin和end获得的迭代器作为参数调用erase：

void Test24()
{
	list<int> Slist = { 0,1,2,3,4,5,6,7,8,9 };

	Slist.clear();  //删除容器中所有元素
	Slist.erase(Slist.begin(), Slist.end()); //等价调用
}


//练习9.25（page 312）
/*
知识点：容器(除array)有许多的删除元素的方法

pop_back()

pop_front()

erase()

clear()

相等：不发生删除操作

elem2为尾后迭代器：删除elem1到最后一个元素

皆为尾后迭代器：不发生删除操作

*/

//练习9.26
/*
适用下面代码定义的ia，将ia拷贝到一个vector和一个list中。使用单迭代器版本的erase从list中删除奇数元素，从vector中删除偶元素。
int ia[] ={0,1,1,2,3,5,8,13,21,55,89};
*/

void  Test25()
{
	int ia[] = { 0,1,1,2,3,5,8,13,21,55,89 };

	vector<int> vec1(ia, ia + 9);//拷贝操作
	list<int> list1(ia, ia + 9);

	vector<int>::iterator it1 = vec1.begin();//使用迭代器
	list<int>::iterator it2 = list1.begin();

	while (it1 != vec1.end())//删除操作
	{
		if ((*it1) % 2 == 0)
		{
			it1 = vec1.erase(it1);//将删除位置更新
		}
		else//若判断非偶数，则移到下一位置
		{
			++it1;
		}
	}

	while (it2 != list1.end())
	{
		if (*it2 % 2 != 0)
		{
			it2 = list1.erase(it2);//将删除位置更新
		}
		else//若判断非偶数，则移到下一位置
		{
			++it2;
		}
	}

	//验证结果
	vector<int>::iterator it3 = vec1.begin();//需要重新定义临时迭代器
	list<int>::iterator it4 = list1.begin();
	for (it3; it3 != vec1.end(); ++it3)
	{
		cout << *it3 << " ";
	}
	cout << endl;
	for (it4; it4 != list1.end(); ++it4)
	{
		cout << *it4 << " ";
	}

}

//特殊的forward_list操作
//由于这些操作与其他容器上的操作的实现方式不容（page 313），forward_list未定义insert、emplace和erase，
//而是定义了名为insert_after、emplace_after和erase_after的操作。
/*
								在forward_list 中插入或删除元素的操作
lst.before_begin()          返回指向链表首元素之前不存在的元素的迭代器。此迭代器不能解引用。cbefore_begin() 返回一个const_iterator
lst.chefore_begin()			在迭代器p之后的位置插入元素。t是一个对象，n是数量，b和e是表示范围的一对迭代器(b和e不能指向lst内)，
list.insert_after(p,t)			il是一个花括号列表。返回一个指向最后一个插入元素的迭代器。如果范围为空，则返回p。若p为尾后迭代器，则函数行为为定义
lst.insert_after(p,n,t)
lst.insert_after(p,b,e)
lst.insert_after(p,il)

emplace_after(p,args)    使用args在p指定的位置之后创建一个元素。返回一个指向这个新元素的迭代器。若p为尾后迭代器，则函数行为为定义

lst.erase_after(p)				删除p指向的位置之后的元素，或删除从b之后直到（但不包含）e之间的元素。返回一个指向被删除元素之后元素的迭代器，
lst.erase_after(b,e)			若不存在这样的元素，则返回尾后迭代器。如果p指向lst的尾元素或者是一个尾后迭代器，则函数行为未定义。

*/

//当在forward_list中添加或删除元素时，我们必须关注两个迭代器---一个指向我， 要处理的元素，另一个指向其前驱
void Test26()
{
	forward_list<int> flst = { 0,1,2,3,4,5,6,7,8,9 };
	auto prev = flst.before_begin();				//表示flst的“首元素”
	auto curr = flst.begin();							//表示flst中的第一个元素
	while (curr != flst.end())							//仍有元素要处理
	{
		if (*curr %2)											//若元素为奇数
		{
			curr = flst.erase_after(prev);			//删除它并移动curr
		}
		else
		{
			prev = curr;										//移动迭代器curr，指向下一个元素，prev指向
			++curr;											//curr之前的元素	
		}
	}

}


//练习9.28
/*
编写函数，接受一个forward_list<string> 和两个string共三个参数。函数应在链表中查找第一个string，并将第二个string插入到紧接着第一个string之后的位置。
若第一个string未在链表中，则将第二个string插入到链表未尾。
*/

void func3(forward_list<string> &a, string b, string c)
{
	forward_list<string>::iterator it1 = a.before_begin();
	forward_list<string>::iterator it2 = a.begin();

	bool flag = false;
	for (it2; it2 != a.end(); it1 = it2++)
	{
		if (*it2 == b)
		{
			a.insert_after(it2, c);
			flag = true;
		}
	}
	if (!flag)
	{
		a.insert_after(it1, c);
	}
}

void Test27()
{
	forward_list<string> list1(4, "sadi");
	string a = "sad5";
	string b = "sad";

	func3(list1, a, b);

	forward_list<string>::iterator it1 = list1.begin();
	for (it1; it1 != list1.end(); ++it1)
	{
		cout << *it1 << " ";
	}

}

//9.3.5 改变容器大小
/*
我们可以用resize来增加或缩小容器，与往常一样，array不支持resize。如果当前大小大于所要求的大小，容器后部的元素或被删除；
如果当前大小小于新大小，会将新元素添加到容器后部：

resize操作接受一个可选的元素值参数，用来初始化添加到容器中的元素。如果调用者为提供此参数，新元素进行值初始化。如果容器保存的时类类型元素，
且resize向元素添加新元素，则我们必须提供初始值，或元素类型必须提供一个默认构造函数

*/

void Test28()
{
	list<int> ilist(10, 42);   //10个int:每个的值都是42
	ilist.resize(15);				//将5个值为0添加到ilist的未尾
	ilist.resize(25, -1);			//将10个值为-1 的元素添加到ilist的未尾
	ilist.resize(5);				//从ilist未尾删除20个元素
}

/*
								顺序容器大小操作
resize 不适用于aray
c.resize(n)   调整c的大小为n给元素。若n<c.size(),则多出的元素被丢弃。若必须添加新元素，对新元素进行值初始化

c.resize(n,t)  调整c的大小为n个元素。任何新添加的元素都初始化为值t

Warning：  如果resize缩小容器，则指向被删除元素的迭代器、引用和指针都会失效；对vector、string或deque进行resize可能导致迭代器、指针和引用失效


*/

//容器操作可能使迭代器失效
/*
在向容器添加元素后：

* 如果容器使vector或string，且储存空间从新分配，则指向容器的迭代器、指针和引用都会失效。如果储存空间未从新分配，指向插入位置之前的元素的迭代器、
指针和引用仍有效，但指向插入位置之后元素的迭代器、指针和引用将会失效。
* 对于deque，插入到除首尾位置之外的任何位置都会导致迭代器、指针和引用失效。如果在首尾位置添加元素，迭代器会失效，但指向存在的元素的引用和指针
不会失效
*对于list和forward_list，指向容器的迭代器（包括尾后迭代器和首前迭代器）、指针和引用任有效。

当我们从一个容器中删除元素后，指向被删除元素的迭代器、指针和引用会失效，这应该不会令人惊讶。毕竟，这些元素都已经被销毁了。
当我们删除一个元素后：

*对于list和forward_list，指向容器其他位置的迭代器（包括尾后迭代器和首前迭代器）、引用和指针仍有效。

*对于deque，如果在首尾之外的任何位置删除元素，那么指向被删除元素外其他元素的迭代器、引用或指针也会失效。如果是删除deque的尾元素，则尾后迭代器也会失效，
但其他迭代器、引用和指针不受影响；如果是删除首元素，这些也不会受影响。

*对于vector和string，指向被删元素之前元素的迭代器、引用和指针仍有效。
注意：当我们删除元素时、指针或引用时严重的运行时错误。
*/

//编写改变容器的循环程序

//傻瓜循环，删除偶数元素，复制每个奇数元素
void Test29()
{
	vector<int> vi = { 0,1,2,3,4,5,6,7,8,9 };
	auto iter = vi.begin();     //调用begin而不是cbegin，因为我们要改变vi
	while (iter != vi.end())
	{
		if (*iter%2)
		{
			iter = vi.insert(iter, *iter); //复制当前元素
			iter += 2;	//向前移动迭代器，跳过当前元素以及插入到它之前的元素
		}
		else
		{
			iter = vi.erase(iter);    //删除偶数元素
			//不应向前移动迭代器，iter指向我们删除的元素之后的元素
		}
	}


}
/*
上述逻辑解释：
	此程序删除vector中的偶数值元素，并复制每一个奇数值元素。我们在调用insert和erase后都更新迭代器，因为两者都会是迭代器失效。

	在调用erase后，不必递增迭代器，因为erase返回的迭代器已经指向序列中下一个元素。调用insert后，需要递增迭代器两次。
	记住，insert在给定位置之前插入新元素，然后返回指向新元素的迭代器因此，在调用insert后，iter指向新插入元素，位于我们正在处理的元素之前。
	我们将迭代器递增两次，恰好越过了新添加的元素和正在处理的元素，指向下一个未处理的元素。
*/

//不要保存end返回的迭代器
/*
	当我们添加/删除vector或string的元素后，或在deque中首元素之外任何位置添加/删除元素后，原来end返回的迭代器总是会失效。
	因此，添加或删除元素的循环程序必须反复调用end，而不能在循环之前保存end返回的迭代器，一直当作容器未尾使用。

*/

void Test30()
{
	vector<int> v = { 0,1,2,3,4,5,6,7,8,9 };
	//灾难：此循环的行为是未定义的
	auto begin = v.begin(), end = v.end(); //保存尾迭代器的值是一个坏主意

	while (begin != end)
	{
		//做一些处理
		//插入新值，对begin从新赋值，否则的话它就会失效

		++begin;    //向前移动begin，因为我们想在此元素之后插入元素
		begin = v.insert(begin, 42); //插入新值
		++begin;   //向前移动begin 跳过我们刚刚加入的元素
	}


	/*
	此代码是未定义的。在很多标准库实现上，此代码会导致无限循环。问题在于我们将end操作返回的迭代器保存在一个名为end的局部变量中。
	在循环中，我们向容器中添加了一个元素，这个操作使保存在end中的迭代器失效了。这个迭代器不再指向v中任何元素，或是v中尾元素之后的位置。
	*/
}

//TIP     如果再一个循环中插入/删除deque、string或vector中的元素，不要缓存end返回的迭代器。

//必须再每次插入操作后重新调用end(),而不能在循环开始前保存它返回的迭代器:
void Test31()
{
	vector<int> v = { 0,1,2,3,4,5,6,7,8,9 };	
	auto begin = v.begin();

	//更安全的方法：在每个循环布添加/删除元素后都从新计算end
	while (begin  != v.end())
	{
		//做一些处理
		++begin;  //向前移动begin，因为我们想在此元素之后插入元素
		begin = v.insert(begin, 42);  //插入新值
		++begin; //向前移动begin，跳过我们刚刚加入的元素

	}

}

//9.4 vector对象是如何增长的
/*
当不当不获取新的内存空间时，vector和string的实现通常会分配比新的空间需求更大的内存空间。容器预留这些空间作为备用，可用来保存更多的新元素。
这样，就不需要每次添加新元素都重新分配容器的内存空间了。
虽然vector在每次重新分配内存空间时都要移动所有元素，但使用此策略后，其扩张操作通常比list和deque还要快。

*/

//管理容器的成员函数
/*
												容器大小管理操作
shrink_to_fit 只适用于vector、string和deque。
capacity和reserve只适用于vector和string。
c.shrink_to_fit()			请将capacity()减少为与size()相同大小
c.capacity()					不重新分配内存空间的话，c可以保存多少元素
c.reserve(n)					分配至少能容纳n个元素的内存空间

Note： reserve并不改变容器中元素的数量，它仅影响vector预先分配多大的内存空间


reserve：  如果需求大小大于当前容量，reserve至少分配与需求一样大的内存空间（可能更大）。调用reserve永远也不会减少容器占用的内存空间。
resize：    只改变容器中元素的数目，而不是容器的容量。我们同样不能使用resize来减少容器预留的内存空间

在新标准库中，我们可以调用shrink_to_fit来要求deque、vector或string 退回不需要的内存空间。此函数指出我们不再需要任何多余的内存空间。但是，
具体的实现可以选择忽略此请求。也就是说，调用shrink_to_fit 也并不保证一定退回内存空间。

*/


//capacity 和size
/*
理解capacity和size的区别非常重要。容器的size时指它已经保存的元素的数目；而capacity则是在不分配新的内存空间的前提下它最多可能保存多少元素。
*/
void Test32()
{
	vector<int> ivec;
	//size应该为0；capacity的值依赖于具体实现
	cout << "ivec:size:" << ivec.size() << "capacity:" << ivec.capacity() << endl;

	//向ivec添加24个元素
	for (vector<int>::size_type ix=0;ix!=24;++ix)
	{
		ivec.push_back(ix);
	}

	//size 应该为24； capaciyt应该大于等于24，具体依赖于标准库是实现
	cout << "ivec:size:" << ivec.size() << "capcity:" << ivec.capacity() << endl;


}
int main()
{

	Test25();
	system("pause");
	return 0;
}