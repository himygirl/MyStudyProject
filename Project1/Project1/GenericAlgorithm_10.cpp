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
#include <stack>
#include <numeric>
using namespace std;

//10.1 概述
//大多数算法都定义在头文件algorithm中。标准库还在头文件numeric中定义了一组数值泛型算法。

void Test_01()
{
	vector<int> vec = {42,3};
	int val = 42; //我们将查找的值
	//如果在vec中找到想要的元素，则返回结果指向它，否则返回结果为vec.cend()
	auto result = find(vec.cbegin(), vec.cend(), val);
	//报告结果
	cout << "The value" << val << (result == vec.cend() ? "is not present" : "is present") << endl;
}

//由于find操作的是迭代器，因此我们可以用同样的find函数在任何容器中查找值。例如，可以用find在一个string的list中查找一个给定的值：

void Test_02()
{
	vector<string> lst = { "a","b" };
	string val = "a value"; //我们要查找的值
	//此调用在list中查找string元素
	auto result = find(lst.cbegin(), lst.cend(), val);
	//类似的，由于指针就像内置数组上的迭代器一样，我们可以用find在数组中查找值：
	int ia[] = { 27,210,12,47,109,83 };
	int val_01 = 83;
	int* result_01 = find(begin(ia), end(ia), val_01);

}

//练习10.1
/*
头文件algorithm中定义了一个名为count的函数，它类似find，接受一对迭代器和一个值作为参数。count返回给定值在序列中出现的次数。编写程序，
读取int序列存入vector中，打印有多少个元素的值等于给定值
*/
/*
知识点：泛型算法：算法是因为其实现了一些经典算法的公共接口，排序和搜索。泛型是因为他们可以作用于不同类型的元素和多种容器类型甚至是内置数组。故称泛型算法

知识点2：基本上都定义在algorithm和numeric两个头文件中

知识点3：这些算法一般情况下只作用于迭代器之上，不对容器进行直接操作
*/

void Test_03()
{
	int a[10] = { 0,1,2,5,4,5,4,5,4,5 };
	vector<int> vec(a, a + 10);
	int value = 5;
	cout << value << "出现的次数为：" << count(vec.begin(), vec.end(), value) << endl;

}

//练习10.2：重做上一题，但读取string序列存入list中
//知识点：所谓泛型算法就是作用于容器和元素上面的一些操作的合集，在实际情况中要善于使用
void Test_04()
{
	string a[10] = { "ds","das","123","123","123","123","123","123","123","123" };
	list<string> list1(a, a + 10);
	string value = "123";
	cout << "字符串“" << value << "”出现的次数为：" << count(list1.begin(), list1.end(), value) << endl;

}

/*
关键概念：算法永远不会执行容器的操作
		泛型算法本身不会执行容器的操作，它们只会运行于迭代器之上，执行迭代器的操作。泛型算法运行于迭代器之上而不会执行容器操作的特性带来了一个令人惊讶但非常必要的编程假设:
		算法永远不会改变底层容器的大小。算法可能改变容器中保存的元素的值，也可能在容器内移动元素，但永远不会直接添加或删除元素。
如我们将在10.4.1节所看到的，标准库定义了一类特殊的迭代器，称为插入器(inserter).于普通迭代器只能遍历所绑定的容器相比，插入器能做更多的事情。但给这类迭代器赋值时，
它们会给底层的容器上执行插入操作。因此，当一个算法操作一个这样的迭代器时，迭代器可以完成向容器添加元素的效果，但算法自身永远不会做这样的操作。
*/

//10.2.1 只读算法
//一些算法只会读取其输入范围内的元素，而从不改变元素，此类算法有：find，count，accumulate,
void Test_05()
{
	vector<int> vec = {1,2,3};
	//对vec中的元素求和，和的初值时0
	int Sum = accumulate(vec.cbegin(), vec.cend(), 0);

	cout << Sum << endl;
}

//算法和元素类型
/*
accumulate 将第三个参数作为求和的起点，和蕴含着一个编程的假定：将元素类型加到和的类型上的操作必须时可行的。即，序列中元素的类型必须与第三个参数匹配，
或者能够转换为第三个参数的类型。
*/
void Test_06()
{
	vector<string> v = { "a","b" };
	string Sum = accumulate(v.cbegin(), v.cend(), string(""));

	//错误：const char* 上没有定义+运算符
	string Sum_01 = accumulate(v.cbegin(), v.cend(), "");
	/*
	错误原因：如果我们传递了一个字符串字面值，用于保存和的对象的类型将是const char* .如前所述，此类型决定了使用哪个+运算符。由于const char* 并没有+运算符，
					此调用将产生编译错误。
	*/

}

//Best Practices ：对于只读取而不改变元素的算法，通常最好使用cbegin()和cend()。
//但是，如果你计划使用算法返回的迭代器来改变元素的值，就需要使用begin()和end()的结果作为参数。

int main()
{
	Test_01();

	system("Pause");
	return 0;
}