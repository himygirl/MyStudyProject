#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;

//8.1 IO类
/*
IO库类型和头文件

头文件                   类型
iostream              istream,wistream 从流读取数据
							ostream,wostream 向流写入数据
							iostream,wiostream读写流

fstream				ifstream,wifstream 从文件读取数据
							ofstream,wofstream 向文件写入数据
							fstream，wfstream读写文件

sstream				istringstream，wistringstream从string读取数据
							ostringstream，wostringstream向string写入数据
							stringstream，wstringstream读写string

//----------------------------------------------

为了支持使用宽字符的语言，标准库定义了一组类型和对象来操控wchar_t类型的数据。宽字符版本的类型和函数的名字以一个w开始。
例如，wcin、wcout和wcerr是分别对应cin、cout和cerr的宽字符版本对象。

*/

//8.1.1   IO对象无拷贝或赋值
/*
ofstream out1, out2;
out1 = out2;						//错误：不能对流对象赋值
ofstream print(ofstream);	//错误：不能初始化ofstream参数
out2 = print(out2);				//不能拷贝流对象


由于不能拷贝IO对象，因此我们也不能将形参或返回类型设置为流类型。进行IO操作的函数通常以引用方式传递和返回流。
读写一个IO对象会改变其状态，因此传递和返回的引用不能是const的。
*/

//8.1.2 条件状态
/*
strm::iostate			strm是一种IO类型，iostate是一种机器相关的类型，提供了表达条件状态的完整功能
strm::badbit			strm::badbit用来指出流已崩溃
strm::failbit			strm::failbit用来指出一个IO操作失败
strm::eofbit			strm::eofbit用来指出流到达了文件结束
strm::goodbit		strm::goodbit用来指出流未处于错误状态。此值保证为零
s.eof()					若流s的eofbit置位，则返回true
s.fail()					若流s的failbit或badit置位，则返回true
s.bad()					若流s的badbit置位，则返回true
s.good()				若流s处于有效状态，则返回ture
s.clear()				若将s中所有条件状态复位，将流的状态设置为有效。返回void
s.clear(flags)			根据给定的flages标志位，将流s中对应条件状态位复位。flages的类型位strm::iostate。返回void
s.setstate(flags)	根据给定的flags标志位，将流s中对应条件状态位置位。flags的类型位strm::iostate。返回void
s.rdstate()				返回流s的当前条件状态，返回值类型为strm::iostate


//查询流的状态

badbit表示系统级错误，如不可恢复的读写错误。通常情况下，一旦badbit被置位，流就无法再使用了。在发生可恢复错误后，failbit被置位，
如期望读取数值却读出一个字符等错误。这种问题通常是可以修正的，流还可以继续使用。如果到达文件结束位置，eofbit和failbit都会被置位。
goodbit的值为0，表示流未发生错误。如果badbit、failbit和eofbit任一个被置位，则检测流状态的条件会失败。




*/

//管理条件状态
//记住cin的当前状态

void testIO_01()
{
auto old_state = std::cin.rdstate();   //记住cin的当前状态

std::cin.clear();								//使cin有效   //kael 如果放在全局中，则会报错：error C3927: "->": 非函数声明符后不允许尾随返回类型

//process_input(std::cin);					//使用cin
std::cin.setstate(old_state);				//将cin置为原有状态

}

//8.1.3管理输出缓冲
/*
//每个输出流都管理一个缓冲区，用来保存程序读写的数据。
//导致缓冲刷新（即，数据真正写到输出设备或文件）的原因有很多：

*程序正常结束，作为main函数的return操作的一部分，缓冲刷新被执行。
*缓冲区满时，需要刷新缓冲，而后新的数据才能继续写入缓冲区
*我们可以使用操作符如endl来显示刷新缓冲区。
*在每个输出操作之后，我们可以用操作符unitbuf设置流的内部状态，来清空缓冲区。
	默认情况下，对cerr时设置unitbuf的，因此写到cerr的内容都是立即刷新的。
*一个输出流可能被关联到另一个流。在这种情况下，当读写被关联的流时，关联到的流的缓冲区被刷新。
例如，默认情况下，cin和cerr都关联到cout。因此，多cin或写cerr都会导致cout的缓冲区被刷新。
*/

//刷新输出缓冲区
/*
我们已经使用过操作符endl，它完成换行并刷新缓冲区的工作。IO库中还有两个类似的操作符：flush和ends。
flush刷新缓冲区，但不输出任何额外的字符；ends向缓冲区插入一个空字符，然后刷新缓冲区：
*/

void testIO_02()
{
	cout << "hi!" << endl;	 //输出hi和一个行，然后刷新缓冲区
	cout << "hi!" << flush;	//输出hi，然后刷新缓冲区，不附加任何额外字符
	cout << "hi!" << ends;	//输出hi和一个空字符，然后刷新缓冲区

}

//unitbuf操作符
/*
如果想在每次输入操作后都刷新缓冲区，我们可以使用unitbuf操纵符。它告诉流在接下来的每次写操作之后都进行一次flush操作。
而nounitbuf操纵符则重置流，使其恢复使用正常的系统管理的缓冲刷新机制：
*/

void testIO_03()
{
	cout << unitbuf;			//所有输出操作后都会立即刷新缓冲区
	//任何输出都立即刷新，无缓冲
	cout << nounitbuf;		//回到正常的缓冲方式

}

//关联输入和输出流
//当一个输入流被关联到一个输出流时，任何试图从输入流读取数据的操作都会先刷新关联的输出流。
//我们既可以将一个istream对象关联到另一个ostream，也可以将一个otream关联到另一个ostream:

void TestIO_04()
{
	cin.tie(&cout);		//	仅仅时用来展示：标准库将cin和cout关联在一起
	//old_tie指向当前关联到cin的流（如果有的话）
	ostream* old_tie = cin.tie(nullptr); //cin不再与其他流关联
	//将cin与cerr关联；这不是一个好主意，因为cin应该关联到cout
	cin.tie(&cerr);			//读取cin会刷新cerr而不是cout
	cin.tie(old_tie);			//重建cin和cout间的正常关联

	/*
	每个流同时最多关联到一个流，但多个流可以同时关联到同一个ostream。
	*/

}

//8.2 文件输入输出
/*
头文件fstream定义了三个类型来支持文件IO:ifstream从一个给定文件读取数据，ofstream向一个给定文件写入数据，以及fstream可以读写给文件。

												fstream特有的操作
fstream fstrm;			创建一个未绑定的文件流。fstream是头文件fstream中定义的一个类型
fstream fstrm(s);		创建一个stream，并打开名为s的文件。s可以是string类型，或者是一个指向C风格字符串的指针。这些构造函数都是explicit的。
								默认的文件模式mode依赖于fstream的类型

fstream fstrm(s,mode);	与前一个构造函数类似，但按指定mode打开文件
fstrm.open(s)					打开名为s的文件，并将文件与fstrm绑定。s可以是一个string或一个指向C风格字符串的指针。
										默认的文件mode依赖于fstream的类型。返回void。
fstrm.close()						关闭于fstrm绑定文件。返回void
fstrm.is_open()					返回一个bool值，指出与fstrm关联的文件是否成功打开且尚未关闭

*/
//8.2.1  使用文件流对象
//知识点：文件的读入与重写,两种文件流皆有open和close函数，之后视情况打开读或者写模式
//ofstream是从内存到硬盘，ifstream是从硬盘到内存，其实所谓的流缓冲就是内存空间

/*
void test_05()
{
	string infile;  //代表文件名
	ifstream in(infile); //ifstream定义了一个输入流in（文件流），它被初始化从文件中读取数据
	if (in)		//检查我呢见的读取是否成功，养成好习惯！
	{
		//......
	}
	else
	{
		cerr << "cannot open this file:" << infile << endl;
	}

	in.close(); //关闭文件
	string mystring = infile + ".copy";
	//const char* mychar01 = mystring.data();
	 char* mychar = (char*)mystring.data();
	in.open(mychar); //关闭文件后，才可以打开另一个文件

	ofstream out; //ofstream 不与任何文件关联，只定义了一个输出流out（文件流）

	if (out)
	{
	}
	else
	{
		cerr << "sorry" << endl;
	}

	out.open(mychar);
	// 当一个fstream对象被销毁时，close函数被自动调用
}
*/


void test_06()
{
	//两种文件流皆有open和close函数，之后视情况打开读或者写模式
	string infile = "1.txt"; //代表文件名
	vector<string> vec;   //声明一个vector
	
	ifstream in(infile);   //ifstream 定义了一个输入流in（文件流），它被初始化从文件中读取数据
	if (in) //检查文件的读取是否成功，养成良好习惯
	{
		string buf;
		while (getline(in,buf)) //每行独立输入的方法，利用getline
		{
			vec.push_back(buf);
		}
	}
	else
	{
		cerr << "cannot open this file:" << infile << endl;
	}
	for (unsigned int i =0; i<vec.size(); ++i)
	{
		cout << vec[i] << endl;
	}

}

void test_07(int argc, char** argv)
{

	

	/*两种文件流皆有open和close函数，之后视情况打开读或者写模式*/
	string infile = "1.txt";//代表文件名，注意需要放在当前目录下
	vector<string> vec;//声明一个vector
	ifstream in(infile);//ifstream定义了一个输入流in(文件流)，它被初始化从文件中读取数据
	if (in)//检查文件的读取是否成功,养成良好的习惯！
	{
		string buf;
		while (in >> buf)//每个单词的独立输入，自动以空格为间隔
		{
			vec.push_back(buf);
		}
	}
	else
	{
		cerr << "cannot open this file: " << infile << endl;
	}
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << endl;
	}

}

//8.2.2 文件模式
/*
每个流都有一个关联的文件模式，用来指出如何使用文件。
															文件模式
in						以读方式打开
out					以写方式打开
app					每次写操作前均定位到文件末尾
ate					打开文件后立即定位到文件末尾
trunc				截断文件
binary				以二进制方式进行IO


指定文件模式有如下限制：

*只可以对ofstream 或 fstream 对象设定out模式
*只可以对ifstream  或 fstream 对象设定in 模式
*只有当out 也被设定时才可设定trunc模式
*只要trunc没被设定，就可以设定app模式。在app模式下，即使没有显式指定out模式，文件也总是以输出方式被打开
*默认情况下，即使我们没有指定trunc，以out模式打开的文件也被截断。为了保留以out模式打开的文件内容，我们必须同时指定app模式，
这样只会将数据追加写到文件末尾；或者同时指定in模式，即打开文件同时进行读写操作
*ate 和 binary 模式可用于任何类型的文件流对象，且可以与其他任何文件模式组合使用。

每个文件流类型都定义了一个默认的文件模式，当我们未指定文件模式时，就使用此默认模式。与ifstream关联的文件默认以in模式打开；
与ofstream关联的文件默认以out模式打开；与fstream关联的文件默认以in和out模式打开

*/

//以out模式打开文件会丢失已有数据
//默认情况下，哦我们打开一个ofstream时，文件的内容会被丢弃。阻止一个ofstream清空给定文件内容的方法时同时指定app模式：

void TestIO_08()
{
//在这几条与语句中，filel都被截断
	ofstream out("filel"); //隐含以输出模式打开文件并截断文件
	ofstream out2("filel", ofstream::out); //隐含地截断文件
	ofstream out3("filel", ofstream::out | ofstream::trunc);	
	
	//为了保留文件内容，我们必须显式指定app模式
	ofstream app("filel2", ofstream::app);	//隐含为输出模式
	ofstream app2("fliel2", ofstream::out | ofstream::app);

	//Warning   保留被ofstream打开的文件中已有数据的唯一方法是显式指定app或in模式
}


//每次调用open时都会确定文件模式
//对于一个给定流，没当打开一个文件时，都可以改变其文件模式。
void TestIO_09()
{
ofstream out;		//未指定文件打开模式
out.open("screatchpad");   //模式隐含设置未输出和截断  
/*
文件隐式地以out模式打开。通常情况下out模式意味着同时使用trunc模式。因此，当前目录下名为scratchpad的文件的内容将被清空。
当打开名为scratchpad的文件的内容将被清空。当打开名为precious的文件时，我们指定了append模式。文件中已有的数据都得以保留，
所有写操作都在文件末尾进行。
*/

out.close();  //关闭out，以便我们将其用于其他文件
out.open("precious", ofstream::app);	//	模式为输出和追加
out.close();
}


//8.3 string流
/*
istringstream从string读取数据，ostringstream向string写入数据，而头文件stringstream即可从string读数据也可向string写书。

													stringstream特有的操作
sstream strm(s)；		strm是一个未绑定的stringstream对象。sstream是头文件sstream中定义的一个类型
sstream strm(s);			strm是一个sstream对象，保存string s的一个拷贝。此构造函数是explicit的
strm.str()						返回strm所保存的string的拷贝
strm.str(s)					将string s拷贝到strm中。返回void

*/

//练习8.9
istream&  func(istream& is)
{
	string buf;
	while (is>>buf)
	{
		std::cout << buf << std::endl;
	}
	is.clear();
	return is;
}

void TestIO_10()
{
	//两种文件流皆open和close函数，之后视情况打开读会或者写模式
	string infile = "1.txt";   //代表文件名
	vector<string> vec;    //声明一个vector
	ifstream in(infile);		//ifstream定义了一个输入流in（文件流），它被初始化从文件中读取数据
	istringstream iss("hello");
	func(iss);
	if (in) //检查文件的读写是否成功
	{
		string buf;
			while(in>>buf)
		{
				vec.push_back(buf);
		}
	}
	else
	{
		cerr << "cannot open this file:" << infile << endl;
	}
	for (int i =0;i<vec.size();++i)
	{
		cout << vec[i] << endl;
	}

}

//练习8.10
void TestIO_11()
{
	/*两种文件流皆有open和close函数，之后视情况打开读或者写模式*/
	string infile = "1.txt";//代表文件名
	vector<string> vec;//声明一个vector
	ifstream in(infile);//ifstream定义了一个输入流in(文件流)，它被初始化从文件中读取数据 

	if (in)//检查文件的读取是否成功,养成良好的习惯！
	{
		string buf;
		while (getline(in, buf))//每个单词的独立输入，自动以空格为间隔
		{
			vec.push_back(buf);
		}
	}
	else
	{
		cerr << "cannot open this file: " << infile << endl;
	}
	for (int i = 0; i < vec.size(); ++i)
	{
		istringstream iss(vec[i]);//将istringstream与vec[i]相绑定
		string word;
		while (iss >> word)
			cout << word << endl;
	}

}

//将参数定义为&引用：在使用时无需进行赋值，省去很多空间与时间。定义为const：在函数内部不允许对参数进行修改


/*
C++使用标准库类来处理面向流的输入和输出：
*iostream 处理控制台IO
*fstream 处理命名文件IO
*stringstream完成内存string的IO

类fstream和stringstream都是继承自类iostream的。输入类都继承自istream，输出类都继承自ostream。因此，可以在istream对象上执行的操作，
也可在ifstream或istringstream对象上执行。继承自ostream的输出类也有类似情况。





*/
/*
int main()
{

	system("pause");
	return 0;
}

*/