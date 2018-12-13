#include<iostream>
#include<fstream>
#include<cassert>
#include<string>

using namespace std;

//1.逐行读入
void readTxt01(string file)
{
	ifstream infile;                //ifstream 是从硬件到内存。
	/*
	//string 转char的方法。
	const char* mychar = filePath.data();
	const char* mychar = filePath.c_str();
	
	char* p =const_cast<char*>(a.c_str());
	
	*/
	infile.open(file.data());   //将文件流对象与文件连接起来。

	assert(infile.is_open()); //若失败，则输出错误消息，并终止程序运行


	string s;
	//getline 每次读入一整行，直至到达文件末尾。
	while (getline(infile,s)) 
	{
		cout << s << endl;
	}

	infile.close();   //关闭文件输入流

	system("pause");
}

//2.逐个字符读入（忽略空格与回车）
void readTest02(string file)
{

	ifstream infile;
	infile.open(file.data());   //将文件流对象与文件连接起来。
	assert(infile.is_open()); //若失败，则输出错误消息，并终止程序运行

	char c;
	while (!infile.eof())
	{
		infile >> c;
		cout << c << endl;
	}

	infile.close();
	system("pause");
}

//3.逐个字符读入（包括空格与回车）
void readTest03(string file)
{

	ifstream infile;
	infile.open(file.data());   //将文件流对象与文件连接起来。
	assert(infile.is_open()); //若失败，则输出错误消息，并终止程序运行

	char c;
	infile >> noskipws;
	while (!infile.eof())
	{
		infile >> c;
		cout << c << endl;
	}

	infile.close();  //关闭文件输入流
	system("pause");
}

void Mystring()
{

	string s8 = string(10,'c'); //拷贝初始化，s8的内容是cccccccccc
	string s2 = "Value";
	string s3("Value");

	s2.empty();

	string mystring02 = "abc";
	int aa = mystring02.size();  //如果一条表达式中，已经有了size()函数就不要使用int了，这样可以避免混用int和unsigned可能带来的问题。
	auto cc = mystring02.size(); //size() 返回的是size_type类型数据。返回的是一个无符号整型数。

	string mytest;
	mytest = mystring02[0];
	char mytestchar = 'ab';
	std::cout << aa << std::endl;

	system("pause");
}

//字符与字符串的区别
void MyCharString()
{
	char mychar = 'abcd';			//输出取最后一个字符，字符对应assic码表。

	
	const char* ptr = "HelloWorld";

	// char* ptr01 = "HellowWorld01"; //错误：无法从“const char [14]”转换为“char *”

	char ptr02[] = { 'H','E','\0' };  //输出HE，但这里是3个字节。  0是二进制的0

	char ptr03[] = "hello";   //这里是6个字节

	std::cout <<"mychar    "<< mychar << std::endl;
	std::cout << ptr << "           " << ptr02 << "     " << ptr03 << std::endl;
	printf("%d \n", 'c');           //当做整数打印  输出99   这里的99就是assic码表，对应的十进制数值。
	printf("%c \n", 'c');           //当作字符来答应。
	printf("%d \n", 'c' + 7);   //当做整数打印  输出106

	int a = 'c';						//输出99   这里的99就是assic码表，对应的十进制数值
	std::cout << a << std::endl;


	//malloc 对应free ,    new对应delete

	system("pause");
}

	//动态内存分配
void  MyAllocatedMemory()
{
	//malloc 对应free ,    new对应delete   具体区别浏览：https://www.cnblogs.com/zhanjxcom/p/5766844.html

	//char* str_data = malloc(10); //报错：从“void*”到指向非“void”的指针的强制转换要求显式类型强制转换
	char* str_data = (char*)malloc(10);  //malloc 返回的是void* 所以这里需要（char*） 显性转化。 （10）代表开辟了10字节的内存。当你往里头存入11个字节，就会有1个字节无
															//家可归，而直接“住进邻居家”！造成的结果是后面的内存中原有数据内容全部被清空（kael疑问。“住进邻居家”的意思是内存泄露吗？）

	str_data[0] = 'H';
	str_data[1] = 'e';

	 const char* scr = "HelloWord";
	 for (size_t i = 0; i < 10; i++)
	 {
		 str_data[i] = scr[i];
	 }

	 str_data[10] = 0;   //'\10'   kael疑问：加这一句的意思是？？？？？
	 printf("%s \n", str_data);

	 free(str_data);

	system("pause");
}

//字符串比较符号：==  , !=, < , <=, >, >=
void CompareString()
{
	string str = "Hello";
	string phrase001 = "HelloWorld";
	string slang = "Hiya";

	string phrase002 = "Helloworld";
	string phrase003 = "Hello world";

	/*
	字符大小比较的两条原则：
	1.如果两个string对象的长度不同，而较短string对象的每个字符都与较长string对象对应位置上的字符，就说较短string对象小于较长对象；
	2.如果两个string对象在某些对应的位置上不一致，则string对象比较多结果其实是string对象中第一对相异字符比较的结果。
	
	
	*/

	string str_phrase001;
	str > phrase001 ? str_phrase001 = "max:str" : str_phrase001 = "max:phrase001";   //输出：max:phrase001

	string phrase001_phrase002;
	phrase001 > phrase002 ? phrase001_phrase002 = "max:phrase001" : phrase001_phrase002 = "max::phrase002";  //输出：max::phrase002

	string phrase001_phrase002001;
	phrase001 == phrase002 ? phrase001_phrase002001 = "==" : phrase001_phrase002001 = "!=";  //输出：!=

	string phrase002_phrase003;
	phrase003 > phrase002 ? phrase002_phrase003 = "max:phrase003" : phrase002_phrase003 = "max:phrase002"; //输出：max:phrase002

	string bb = "b";
	string cc = "c";

	string bb_cc;
	bb > cc ? bb_cc = "max:bb" : bb_cc = "max:cc"; // 输出:max:cc   //kael认为：字符的比较，是依据ASCII码的十进制大小来的。

	std::cout << bb_cc << std::endl;

	system("pause");
}

//字符串与字面值相加
void StringAdd()
{
	string s1 = "hello", s2 = "world\n";
	string s3 = s1 + ',' + s2 + '\n';

	string s4 = s1 + ",";
	//string s5 = "hello" + ",";				//错误：两个运算对象都不是string
	string s6 = s1 + "," + "world";
	//string s7 = "hello" + "," + s2;		//不能把字面值直接相加
	
	string s8 = string("hello") + string("c");					
	char b = 'b';
	char c = 'c';
	const char *test = "hello";
	//const char* p = "hello" + 'b' ;			//s8  输出orld,  原因是b的assic码表的值是：98，所以"hello"地址移动了98位的地址，取了5个字节：orld0（最后一个是0）
	const char* p = "hello" + 98;				//s8  输出orld,  原因是b的assic码表的值是：98，所以"hello"地址移动了98位的地址，取了5个字节：orld0（最后一个是0）			
	const char* q = "hello" + 'c';			//s8  输出rld


	std::cout <<"s3------" <<s3 << "  -----s4------" << s4 << " -------s6----- " << s6 << "------s8-----" << s8 <<"----p-----"<<p<< std::endl;
	system("pause");
}


//字符串转string类型
string CharToStr(char * contentChar)
{
	string tempStr;
	//‘\0’是一个“空字符”常量，它表示一个字符串的结束，它的ASCII码值为0。注意它与空格' '（ASCII码值为32）及'0'（ASCII码值为48）不一样的。
	for (int i = 0;contentChar[i] !='\0'; i++)
	{
		tempStr += contentChar[i];

	}
	return tempStr;

}


//删除指定行数据
void DelLineData(string FilePath,int lineNum)
{
	ifstream in;
	in.open(FilePath.data());

	string strFileData = "";
	int line = 1;
	char lineData[1024] = {0};
	
	//总思路：重组字符， 替换要删除的那行为“\n”
	while (in.getline(lineData,sizeof(lineData)))  //LineData 得到每行字符。
	{
		std::cout << lineData << std::endl;
		if (line==lineNum)   //line++ 当相等的时候，替代那一行，为“\n”，
		{
			strFileData += "\n";
		}
		else
		{
			strFileData += CharToStr(lineData);
			strFileData += "\n";
		}
		line++;
	}

	in.close();

	ofstream out;  //ofstream是从内存到硬盘
	out.open(FilePath.data());

	//Flush是将缓冲区的内容写入文件，并清空。缓冲区是4k的内容，够4k了，就会自动写入文件，不够的话就需要flush一下，如果不flush的话，文件的最后有可能会少一些内容
	out.flush();
	out << strFileData; //string 写入out
	
	out.close();

	system("pause");
}

//按行，  修改.text文件
void ModityFile(string filePath,int lineNum,string content)
{
	ifstream in;
	char line[1024] = {'\0'};  //[] 下标运算符
	in.open(filePath.data());
	int i = 0;
	string tempStr;

	//总思路：重组，替换
	while (in.getline(line,sizeof(line)))
	{
		i++;
		if (lineNum !=i)
		{
			tempStr += CharToStr(line);
		}
		else
		{
			char* p = const_cast<char*>(content.c_str());//通过const_cast运算符，只能将const type*转换为type*，将const type&转换为type&
			tempStr += CharToStr(p);
		}
		tempStr += '\n';
	}

	in.close();
	ofstream out;
	out.open(filePath.data());
	out.flush();
	out << tempStr;
	out.close();
}

void Mystring02()
{
	string mystring("hello world");

	//拷贝
	for (auto c : mystring)
	{
		c = 'a';
	}
	
	//引用
	for (auto &c : mystring)
	{
		c = 'a';
	}

	std::cout << mystring << std::endl;
	system("pause");
}

//判定字符的方法
void  mychar02()
{
	char c = 'c';

	isalnum(c);		//当c是字面或者数字时为真
	isalpha(c);		//当c是字面时为真
	iscntrl(c);		//当c是控制字符时为真
	isdigit(c);		//当c是数字时为真
	isgraph(c);		//当c不是空格但可以打印时为真
	islower(c);		//当c是小写字母时为真
	isprint(c);		//当c是可打印字符时为真（即c是空格或者c具有可视形式）
	ispunct(c);		//当c是标点符号时为真（即c不是控制字符、数字、字母、可打印空白中的一种）
	isspace(c);		//当c是空白时为真（即c时空格、横向制表符、纵向制表符、回车符、换行符、进纸符中的一种）
	isupper(c);		//当c是大写字母时为真
	isxdigit(c);    //当c是十六进制数字时为真
	tolower(c);		//如果c是大写字母，输出对应的小写字母；否则原样输出c
	toupper(c);		//如果c是小写字母，输出对应的大写字母；否则原样输出c




}

//十进制转换为十六进制
void Change10to15()
{
	const string hexdigits = "0123456789ABCDEF";

	string result;
	string::size_type n;
	while (cin>>n)
	{
		if (n<hexdigits.size())
		{
			result += hexdigits[n]; //如果小于15，则替换对应的字符
		}
	}

	std::cout << "Your hex number is:" << result << std::endl;

	//string s;
	//std::cout << s[0] << std::endl; //不合法。因为s为空，虽然编译通过，但不合法。

	/*
	const string s = "keep out!";
	for(auto &c:s)//合法，但c是   const char& 不允许改变它的值。
	{
	//......
	}
	
	
	
	*/

	system("pause");
}

//标准库类型vector,     vector 是一个类模板。
#include<vector>

void Myvecto() {

	//vector能容纳绝大多数类型的对象作为其元素，但是因为引用不是对象，所以不存在包含引用的vector。
vector <int> iec;							 //ivec 保存int类型的对象；
vector <vector<string>> file;		//该向量的元素是vector对象

/*
初始化vector对象的方法
vector<T> v1                          v1是一个空vector，它潜在的元素是T类型的，执行默认初始化
vector<T> v2(v1)						v2中包含又v1所有元素的副本
vector<T> v2= v1					等价于v2（v1），v2中包含有v1所有元素的副本
vector<T>v3(n,val)					v3包含了n个重复的元素，每个元素的值都是val
vector<T>v4(n)						v4包含了n个重复地执行了值初始化的对象
vector<T>v5{a,b,c,.....}				v5包含了初始值个数的元素，每个元素被赋予相应的初始化。
vector<T>v5 ={a,b,c....}

*/

vector<int> ivec;                  //初始化状态为空
//在此处给ivec3 添加一些值
vector<int> ivec2(ivec);       //把ivec的元素拷贝给ivec2
vector<int> ivec3 = ivec;     //把ivec的元素拷贝给ivec3
//vector<string> svec(ivec2)  //错误：svec的元素是string对象，不是int

vector<string> articles = { "a","an","the" };
vector<string> v1_01{ "a","an","the" };//列表初始化

//如果提供的是初始元素的列表，则只能把初始化都放在花括号里进行列表初始化，而不能放在圆括号里：
//vector<string> v2("a", "an", "the"); //错误


//创建指定数量的元素
vector<int> ivec02(10, -1);				 //10个int类型的元素，每个都被初始化为-1
vector<string> svec02(10, "hi!");	//10个string类型的元素，每个都被初始化为“hi！”

vector<int> ivec03(10);					//10个元素，每个都初始化为0
vector<string> svec04(10);				//10个元素，每个都是空string对象。

//如果只提供了元素的数量而没有设定初始值，只能使用直接初始化：
//vector<int> vi = 10;                   //错误：必须使用直接初始化的形式指定向量大小。

//列表初始值还是元素数量？
//某些情况下，初始化的真实含义依赖于传递初始值时用的是花括号还是圆括号。
vector<int> v1(10);			//v1有101个元素，每个的值都是0
vector<int>v2{ 10 };		//v2有1个元素，该元素的值是10

vector<int> v3(10, 1);		//v3有10个元素，每个的值都是1
vector<int> v4{ 10,1 };		//v4有2个元素，值分别是10和1

vector<string> v5{ "hi" };   //列表初始化：v5有一个元素
//vector<string> v6("hi");		//错误：不能使用字符串字面值构建vector对象

//如果初始化时使用了花括号的形式，但是提供的值有不能用来列表初始化，就要考虑用这样的值来构造vector对象了。
vector<string> v7{ 10 };			//v7  有10个默认初始化的元素
vector<string>v8{ 10,"hi" };    //v8有10个值为”hi“ 的元素

}

//向vector对象中添加元素
//推荐创建一个空的的vector，然后添加。除非所有元素的值都一样。
void VectorAdd()
{
	vector<int> v2;			//空vector对象
	for (int i = 0; i != 10; ++i)
		v2.push_back(i);		//依次把整数值放在v2尾部   //push_back负责把一个值当成vector对象的尾元素”压到（push）“ vector对象的”尾端（back）“。


	string word;
	vector<string> text;         //空vector对象
	while (cin >> word) {
		text.push_back(word);
	}

}

void VectorAdd02() {

	int Test;
	vector<int> Myint;
	while (cin>>Test)
	{
		Myint.push_back(Test);

	}

	for (int i = 0; i < Myint.size(); ++i)   
	{
		std::cout << Myint[i] << std::endl;
	}	

	system("pause");
}
/*
//vector 支持的操作

v.empty()		              //如果v不含有任何元素，返回真：否则返回假
v.size()						//返回v中元素的个数
v.pushe_back(t)		//向v的尾端添加一个值为t的元素
v[n]							//返回v中第n个位置上”元素的引用“
v1=v2						//用v2中元素的拷贝替换v1中的元素
v1={a,b,c.....}				//用列表中元素的拷贝替换v1中的元素
v1 == v2					//v1和v2相等当且仅当它们的元素数量相同且对应位置的元素值都相同
v1!=v2
 
 <,<=,>,>=				顾名思义，以字典顺序进行比较。

*/

//分数分段
//以10分为一个分数段统计成绩的数量：0~9,10~19,....,90~99,100
void FractionSegmentation()
{
	vector<unsigned> scores(11, 0);  //11个分数段，全都初始化的0

	unsigned grade;
	while (cin>>grade)                       //读取成绩
	{
		if (grade<=100)						//只处理有效的成绩
		{
			++scores[grade / 10];			//将对应分数段的记数值加1
		}
	}

	for (auto c : scores)
	{
		std::cout << c << std::endl;
	}
	system("pause");
}

//不能用下标形式添加元素
//vector对象（以及string对象）的下标运算符可用于访问已存在的元素，而不能用于添加元素。
void myvector03()
{
	vector<int> ivec; //空vector对象

	for (decltype(ivec.size()) ix = 0; ix != 10; ++ix) {
	
	//			ivec[ix] = ix;//严重错误：ivec不包含任务元素
		ivec.push_back(ix);  //正确：添加一个新元素，该元素的值时ix。
	}
	
}

void myvector04()
{
	string mystring = "abc";

	for (auto c :mystring)
	{
		char myc = toupper(c);
		std::cout << myc << std::endl;
	}


	vector<string> myvector= { "A","b" };

	//如果容器为空，则begin和end返回的是同一个迭代器，都是尾后迭代器。
	auto a = myvector.begin(), b = myvector.end();    //a和b的类型相同，都为 iterator（迭代器）
	if (a==b)
	{

	}

	system("pause");

	/*
	*iter 返回迭代器iter所指元素的引用
	iter->mem			  解引用iter并获取该元素的名为mem的成员，等价于（*iter）.mem
	++iter					  令iter指示容器中的下一个元素
	--iter					  令iter指示容器中的上一个元素
	iter1 ==iter2			判断两个迭代器是否相等（不相等），如果两个迭代器指示的是同一个原始或者
	iter1 ！= iter2		 它们是同一个容器的尾后迭代器，则相等；反之，不相等。



	*/

}


int main()
{

	//Mystring();
	
	//readTxt01("H:/云渲染接口.txt");   //注意斜杠
	//readTest02("H:/云渲染接口.txt");
	//readTest03("H:/云渲染接口.txt");

	//MyCharString();
	//MyAllocatedMemory();
	//CompareString();
	//StringAdd();
	//DelLineData("H:/云渲染接口.txt",1);
	//ModityFile("H:/云渲染接口.txt",1,"hello world");
	//Mystring02();
	//Change10to15();
	//VectorAdd02();
	//FractionSegmentation();
	myvector04();
	return 0;
}