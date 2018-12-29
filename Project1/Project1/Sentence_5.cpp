#include <iostream>
#include <string>
#include <vector>

using namespace std;


//空语句
void test_01()
{
	//如果在程序的某个地方，语法上需要一条语句但是逻辑上不需要，此时应该使用空语句。
	; //空语句

}

//语句作用域
void test_02()
{
	/*
	while (int i = get_num())   //每次迭代时创建并初始化i
		cout << i << endl;
	i = 0; //错误：在循环外部无法访问i

*/
}

void test_03()
{
	/*
	//错误：实际的执行过程并非像缩进格式显示的那样；else分支匹配的时内层if语句
	if (grade % 10 >= 3)
		if (grade % 10 > 7)
			lettergrade += '+';

	else lettergrade += '-';

*/

}

void test_04()
{
	int a = 3;
	int b[] = {0,1,2};
	if (a = sizeof(b) )
	{
		std::cout << a << std::endl;
	}
	system("pause");
}

void test_05()
{
	if (int a =0)
	{
		std::cout << a << std::endl;
	}
	else
	{
		std::cout << 1 << std::endl;
	}
	system("pause");
}

//switch
void switch_06()
{
	char ch= ' ';
	while (cin >> ch)
	{
	switch (ch)
	{
	case 'a': std::cout << 'a' << std::endl;break;
	case 'b': std::cout << 'b' << std::endl; break;

	default:
		break;
	}
}
}


void switch_07()
{
	char ch = ' ';

	while (cin>>ch)
	{	
	switch (ch)
	{
		//输入a b c 都会 执行    std::cout << "ddd" << std::endl;
		//也可以这样写：	case 'a':case 'b':case 'c':
	case 'a':
	case 'b':
	case 'c':
		std::cout << "ddd" << std::endl;
		break;
	default:
		break;
	}

/*
//警告：不正确的程序逻辑
switch(ch){

case 'a':   ++acnt;		//此处应该有一条break语句
cast 'e': ++ecnt;			//此处应该有一条break语句
cast 'i': ++icnt;			//此处应该有一条break语句

假设ch的值是‘e’。此时，程序直接执行case'e'标签后面的代码，该代码把ecnt的值加1.接下来，程序将跨越case标签的边界，接着递增icnt


}


*/

}

}

void switch_08()
{
	int Mybool = 1;

	switch (Mybool)  //如果mybool为 bool类型，加上default：break；会提示：切换语句有多余的“default”标签；给定所有可能的“case”标签。
								//因为bool只有两种情况，所以不需要default
	{
	case 1:   //当有多条语句时，需要用{} 语句块
	{
		int a = 3;
		int & b = a;

		std::cout << b << std::endl;	
	}
	break;

	case 2:
	{
		string a = "aa";
		string &b = a;
		std::cout << b << std::endl;
	}

	break;  
	default:
		break;
	}
	system("pause");
}

void switch_09()
{
	/*
	unsigned ival = 512, jval = 1024, kval = 4096;
	unsigned bufsize;
	unsigned swt =0;
	while (cin >> swt) {
	
		switch (swt)
		{
	
		case  ival: bufsize = ival * sizeof(int); break;	//错误。case后面应该是常量。
		case jval: bufsize = jval * sizeof(int); break;    //错误。case后面应该是常量。
		case kval: bufsize = kval * sizeof(int); break; //错误。case后面应该是常量。
		default:
			break;
		}

	}
*/
	const unsigned ival = 512, jval = 1024, kval = 4096;
	unsigned bufsize;
	unsigned swt = 0;
	while (cin >> swt) {

		switch (swt)
		{

		case  ival: bufsize = ival * sizeof(int); break;	//正确   ival是常量
		case jval: bufsize = jval * sizeof(int); break;   
		case kval: bufsize = kval * sizeof(int); break; 
		default:
			break;
		}

	}
}

/*
//for语句头中的多重定义
//记录下v的大小，当到达原来的最后一个元素后结束循环
for(decltype(v.size()) i =0,sz = v.size(); i !=sz; ++i)
		v.push_back(v[i]);
*/


void dowhile_10()
{
	int a = 0;
	//先执行，再判断
	do 
	{
		++a;
		std::cout << a << std::endl;
	} while (a<10);

	system("pause");
}

//5.5  跳转语句：  break，  continue， goto， return。



//5.5.1 break 语句
/*
break 语句负责终止离它最近的while, do while,for 或者swith 语句，并从这些语句之后的第一条语句开始继续执行。
break语句只能出现在迭代语句或者switch语句内部（包括嵌套在此类循环里的语句或块的内部）
*/
void Mybreak_11()
{
	string buf;
	while (cin>>buf && !buf.empty())
	{
		switch (buf[0])
		{
		case '-':
			//处理到第一个空白为止
			for (auto it = buf.begin() + 1; it != buf.end();++it)
			{
				if (*it == ' ')
					break;   //#1,离开for循环
			}

			//break #1 将控制权转移到这里， 剩余的‘-’处理:
			break;   //#2,离开switch语句
		case '+': std::cout << "+" << std::endl; break;
		} //结束switch
		//结束swithc:break #2将控制权转移到这里
	}//结束while
	
}

//5.5.2 continue 语句
/*
continue语句终止最近的循环中的当前迭代并立即开始下一次迭代。continue语句只能出现在for，while和do while 循环的内部。

*/
void Mycontinue_12()
{
	string buf;
	while (cin>> buf && !buf.empty())
	{
		if (buf[0] != ' ')
		{
			continue;   //接着读取下一个输入
		}
		//程序执行过程到了这里？说明当前的输入是以下划线开始的。接着处理buf...
	}

}

//5.5.3 goto语句
//goto语句的作用是从goto语句无条件跳转到同一函数内的另一条语句。
//建议：不要在程序中使用goto语句，因为它使得程序即难理解又难修改。
void Mygoto_13()
{
		AAA: std::cout << "AAA" << std::endl;    //带标签语句，可以作为goto的目标
		
		goto AAA;   //跳转到AAA；这样就会一直执行。停不下来。

	/*
	goto end;
	int ix =10; //错误：goto语句绕过了一个带初始化的变量定义

	end: 
	//错误：此处的代码需要使用ix，但是goto语句绕过了它的声明
	ix = 42;
	*/

		system("pause");

}

//5.6.1 throw 表达式
//throw 表达式包含关键字throw 和紧随其后的一个表达式，其中表达式的类型就是抛出的异常类型。
void Mythrow_14()
{
	int* aa = nullptr;
	if (aa == nullptr)
	{
		throw runtime_error("Data must refer to same ISBN");
	}
	system("pause");
}

//5.6.2  try语句块  
void Mytry_15()
{
	int  a;
	int b;
	while (cin>>a>>b)
	{
		try
		{
			if (b==0)
			{
				throw std::runtime_error("被除数不能为0");
			}
			cout << static_cast<double>(a) / b << endl; //考虑到不可以整除产生小数的情况，先将a强制转换为double类型。
		}
		catch (runtime_error err) //err是runtime_error类的一个实例
		{
			cout << err.what(); //实例的成员函数，返回内容由编译器决定
			cout<< "\n Try Again? Enter y or n" << endl;
			char c;
			cin >> c;
			if (!cin || c=='n')
			{
				break;    
			} //简单来说try是检测异常的，如果产生了异常，就throw（抛出）一个异常，然后被catch到，进行异常的处理
			  //如果没有catch部分，仅有try，仍然会报错。
		}
	}


	system("pause");

}

/*
<stdexcept>定义的异常类

exception					 //最常见的问题
runtime_error			//只有在运行时才能检测出的问题
range_error				//运行时错误：生成的结果超出了有意义的值域范围
overflow_error			//运行时错误：计算上溢
underflow_error		//运行时错误：计算上溢
logic_error				//程序逻辑错误
domain_error			//逻辑错误：参数对应的结果值不存在
iinvalid_argument	//逻辑错误：无效参数
length_error				//逻辑错误：试图创建一个超出该类型最大长度的对象
out_of_range			//逻辑错误：使用一个超出有效范围的值

*/
/*
int main() 
{

	Mytry_15();


	return 0;
}

*/