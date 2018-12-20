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


//迭代器类型
void myiterator()
{
	//一般来说我们也不知道（其实是无需知道）迭代器的精确类型。而实际上，那些拥有迭代器的标准库类型使用iterator和const iterator来表示迭代器类型：

	vector<int>::iterator  it;     //it 能读写vector<int> 的元素
	string::iterator    it2;           //it2能读写string对象中的字符

	/*
	如果vector对象或string对象是一个常量，只能使用const_iterator; 如果vector对象或string对象不是常量，那么既能使用iterator也能使用const_iterator
	
	*/
	vector<int>::const_iterator  it3;     //it3只能读元素，不能写元素
	string::const_iterator        it4;        //it4 只能读字符，不能写字符 //const_iterator和常量指针差不多


	//begin和end运算符
	vector<int> v;
	const vector<int>cv;
	auto it1_1 = v.begin();			//it1_1 的类型是vector<int>::iterator
	auto it2_1 = cv.begin();		//it2_1的类型是vvector<int>::const_iterator

	auto it3_1 = v.cbegin();    //it3_1的类型是vector<int>::const_iterator


	//结合解引用和成员访问操作
	// (*it).empty();   //解引用it，然后调用结果对象的empty成员
	// *it.empty();     //错误：试图访问it的名为empty的成员，但it是个迭代器，没有empty成员

	//但凡是使用了迭代器的循环体，都不要向迭代器所属的容器添加元素？？？？？？？
}

//3.4.4节练习
void mytest3_21()
{
	vector<int> v{ 1,2,3,4,5 };

	for (auto c =v.begin(); c !=v.end();++c)
	{
		cout << (*c)*2 << endl;
	}

	system("pause");

}

void mytest3_23()
{
	vector<int> myvectorint;
	for (int i =1;i<11;++i)
	{
		myvectorint.push_back(i);
	}

	for (auto c = myvectorint.begin();c!=myvectorint.end();++c)
	{
		std::cout << (*c) * 2 << std::endl;
	}

	system("pause");

}

//迭代器运算
/*
	iter + n   //迭代器加上一个整数值仍得到一个迭代器，迭代器指示的新位置与原来相比向前移动了若干个元素。结果迭代器或者指示容器内的一个元素，或者指示容器尾元素的下一位置。
	iter - n    //原来同上

	iter1 += n //迭代器加法的复合赋值语句，将iter1加n的结果赋给iter1
	iter1 -=n   //同上

	iter1- iter2  两个迭代器相减的结果是他们之间的距离，也就是说，将运算符右侧的迭代器向前移动差值个元素后将得到左侧的迭代器。
						参与运算的两个迭代器必须指向的是同一个容器中的元素或者尾元素的下一个元素。

	>、 >= 、<、 <=  迭代器的关系运算符，如果某迭代器指向的容器位置在另一个迭代器所指位置之前，则说前者小于后者。
									参与运算的两个迭代器必须指向的是同一个容器中的元素或者尾元素的下一个位置。

*/

//3.5  数组

//3.5.1 定义和初始化内置数组

 // a[d]  a是数组的名字，d是数组的维度。维度必须是一个常量表达式

void Myarray_3_5_1()
{
	unsigned cnt = 42;   //不是常量表达式,  //kael理解：因为这个值可能改变。
	constexpr unsigned sz = 42;    //常量表达式，//声明为constexpr的一定是一个常量表达式
	int arr[10];							//含有10个整数的数组
	int *parrot[sz];						//含有42个整型指针的数组
	//string bad[cnt];					//错误：cnt不是常量表达式
	//string  strs[get_size()];			//当get_size是constexpr时正确；否则失败

	/*
	默认情况下，数组的元素被默认初始化。
	和内置类型的变量一样，如果在函数内部定义了某种内置类型的数组，那么默认初始化会令数组含有未定义的值。
	定义数组的时候必须指定数组的类型，不允许用auto关键字由初始值的列表推断类型。另外和vector一样，数组的元素应为对象，因此不存在引用的数组。
	*/
	const  unsigned sz_01 = 3;
	int ial[sz] = { 0,1,2 };      //含有3个元素的数组，元素值分别时0，1，2
	int a2[] = { 0,1,2 };        //维度是3的数组
	int a3[5] = { 0,1,2 };      //等价于a3[] ={0，1，2，0，0}
	string a4[3] = { "hi","bye" };    //等价于a4[] ={“hi”,"bye",""}
	//int a5[2] = { 0,1,2 };            //错误：初始值过多

	//字符数组的特殊性
	char  a1_01[] = { 'c','+','+' };         //列表初始化，没有空字符
	char  a2_01[] = { 'c','+','+','\0' };   //列表初始化，含有显式的空字符
	char  a3_01[] = "C++";                //自动添加表示字符串结束的空字符
	//const  char a4_01[6] = "Daniel";  //错误：没有空间可存放空字符。//编译提示:error C2117: “a4_01”: 数组界限溢出 
	/*
	字符串字面值的结尾处还有一个空字符，这个空字符也会像其他字符一样被拷贝到字符数组中去。
	*/

	int a[] = { 0,1,2 }; //含有3个整数的数组
//	int a2[] = a;        //错误: 不允许使用一个数组初始化另一个数组
//a2 = a；            //错误: 不能把一个数组直接赋值给另一个数组
	/*
	一些编辑器支持数组的赋值，这就是所谓的编辑器扩展。但一般来说，最好避免使用非标准特性，因为含有非标准特性的程序的很可能在其他编辑器上无法正常工作。	
	*/


	//理解复杂的数组声明

	int *ptrs[10];              //ptrs是含有10个整型指针的数组
	//int &refs[10] =/*?*/;  //错误:不存在引用的数组
	int(*parray)[10] = &arr;   //parray指向一个含有10个整数的数组
	int(&arrRef)[10] = arr;     //arrRef引用一个含有10个整数的数组

	int *(&arry)[10] = ptrs;	//arry  是数组的引用，该数组含有10个指针。
}

void testFor()
{
	for (int a=0; a<=5;++a)
	{
		std::cout << "++a---------"<<a << std::endl;
	}

	for (int a = 0; a <= 5; a++)
	{
		std::cout << "a++---------" << a << std::endl;
	}
	system("pause");
}

//指针和数组
//使用数组的时候 ，编译器一般会把它转换成指针。

void pointAndArray()
{
	string nums[] = { "one","two","three" };   //数组的元素是string对象
	string *p = &nums[0];								//p指向nums的第一个元素

	//在大多数表达式中，使用数组类型的对象其实是使用一个指向该数组首元素的指针
	//数组还有一个特性：在很多用到数组名字的地方，编译器都会自动地将其替换为一个指向数组首元素的指针:
	string *p2 = nums;           //等价于p2  = &nums[0]

	int ia[] = { 0,1,2,3,4,5,6,7,8,9 };     //ia  是一个含有10个整数的数组
	auto ia2(ia);             //ia2 是一个整型指针，指向ia的第一个元素
	//ia2 = 42；				//错误：ia2是一个指针，不能用int值给指针赋值

//	auto ia2(&ia[0]);     //显然ia2 的类型是int* //error C2040: “ia2”:“auto”与“int *”的间接寻址级别不同

	//当使用decltype关键字时，上述转换不会发生，decltype（ia）返回的类型是由10个整数构成的数组

	decltype(ia) ia3 = { 0,1,2,3,4,5,6,7,8,9 };
	//ia3 = p;          //错误：不能用整型指针给数组赋值
	//ia3[4] = i;       //正确:把i的值赋给ia3的一个元素

	//指针也是迭代器
	//vector 和string 的迭代器支持的运算，数组的指针全都支持。

	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
	int *p_03 = arr; //p指向arr的第一个元素
	++p_03;      //p指向arr[1]

	//就像尾后迭代器一样，尾后指针也不指向具体的元素。因此，不能对尾后指针执行解引用或递增的操作。
	int *e = &arr[10];  //指向arr尾元素的下一位置的指针。

	int *beg = begin(ia);     //指向ia首元素的指针
	int *last = end(ia);		//指向arr尾元素的下一位置的指针


	//pbeg指向arr的首元素，pend指向arr尾元素的下一位置
	int *pbeg = begin(arr), *pend = end(arr);

	//寻找第一个负值元素，如果已经检查完全部元素，则结束循环
	while (pbeg != pend && *pbeg >=0)    //*出现在表达式中，是一个解引用符。得到指向pbeg的对象。
	{
		++pbeg;
	}
}

//指针运算
void point_02()
{
	constexpr size_t sz = 5;
	int arr[sz] = { 1,2,3,4,5 };
	int *ip = arr;				//等价于int *ip =&arr[0];
	int *ip2 = ip + 4;		//ip2指向arr的尾元素arr[4]

	//正确：arr 转换成指向它首元素的指针；p指向arr尾元素的下一个位置

	int *p = arr + sz;     //使用警告：不要解引用！
	int *ip2_02 = ip + 4;		//ip2指向arr的尾元素arr[4]

	/*
	只要两个指针指向同一个数组的元素，或者指向该数组的尾元素的下一个位置，就能利用关系运算符对其进行比较。
	如果两个指针分别指向不相关的对象，则不能比较它们；	
	*/

	int ia[] = { 0,2,4,6,8 };	//含有5个整数的数组
	//表达式*（ia+4）计算ia前进4个元素后的新地址，解引用该结果指针的效果等价于表达式ia[4]
	int last = *(ia + 4);		//正确:把last，初始化成8，也就是ia[4]的值

	last = *ia + 4;    //正确： last = 4 等价于ia[0]+4

	/*
	在很多情况下使用数组的名字其实用的是一个指向数组首元素的指针。一个典型的例子是当对数组使用下标运算符时，编译器会自动执行上述转换操作。
	*/

	int i = ia[2];		 //ia 转换成指向数组首元素的指针
							//ia[2] 得到（ia+2）所指的元素
	int *p_02 = ia;		//p指向ia的首元素
	i = *(p_02 + 2);		//等价于i = ia[2]

	//只要指针指向的时数组中的元素（或者数组中尾元素的下一位置），都可以执行下标运算：
	int *p_01 = &ia[2];    //p指向索引为2的元素
	int j = p_01[1];			//p[1]等价于 *（P+1）,就是ia[3]表示的那个元素

	//标准库类型限定使用的下标必须是无符号类型，而内置的下标运算无此要求，下面的例子很好的说明了这一点。
	int k = p_01[-2];        //p[-2]是ia[0]表示的那个元素。
}

void point_03()
{
	//假定p1和p2 指向同一个数组中的元素，则下面程序的功能是说明？
	//答：p1，p2为指针，相减为其地址相减，因为指向的是同一元素，地址相同，因此p1地址不变，只要P1，P2合法，这个语句就是合法

	//p1 += p2 - p1;

}

//练习3_35
void point_04()
{
	int MyArrayInt[] = { 0,1,2,3,4,5,6,7,8,9 };
	int *myint = MyArrayInt;
	for (int i =0; i <10;++i)
	{
		*myint = 0;		//解引用设置元素值
		myint++;			//指针移动
	}

	for (int i = 0; i < 10; ++i)
	{
		std::cout << MyArrayInt[i] << std::endl;

	}

	system("pause");

}

//练习_3.5.3
//比较数组相等，先比较数组的大小，再比较数组的每一个元素。vector的比较，直接判断是否相等即可。
void point_05_array()
{
	int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int b[10] = { 0,1,2,3,4,5,6,7,8,9 };

	int myflag = 0;
	if (sizeof(a) == sizeof(b))
	{
		for (int i =0;i<10;i++)
		{
			if (a[i] == b[i])
			{
				myflag++;
			}
		}
	}

	if (myflag == 10)
	{
		cout << "Equal" << endl;
	}
	else
	{
		cout << "Not Equal" << endl;
	}

}

void point_05_vector()
{
	int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int b[10] = { 0,1,2,3,4,5,6,7,8,9 };
	vector<int> v1(a, a + 10);
	vector<int>v2(b, b + 10);

	int myflag = 0;
	if (sizeof(a) == sizeof(b))
	{
		for (int i=0;i<10;i++)
		{
			if (a[i] == b[i])
			{
				myflag++;
			}
		}
	}

	if (v1 ==v2)
	{
		std::cout << "Equal" << std::endl;
	}
	else
	{
		std::cout << "Not Equal" << std::endl;
	}
}

//3.6  多维数组
//严格来说，c++语言中没有多维数组，通常所说的多维数组其实是数组的数组

void MultidimensionalArray()
{
	int ia[3][4];   //大小为3的数组，每个元素是含有4个整数的数组

	//大小为10的数组，它的每个元素都是大小为20的数组，
	//这些数组的元素是含有30个整数的数组。
	int  arr[10][20][30] = { 0 }; //将所有元素初始化为0

	//多维数组的初始化
	int ia_01[3][4] =
	{                                   //三个元素，每个元素都是大小为4的数组
		{0,1,2,3},					//第1行的初始化
		{4,5,6,7},					//第2行的初始化
		{8,9,10,11}				//第3行的初始化	
	};

	//没有标识每行的花括号，与上面的初始化语句是等价的
	int  ia_02[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };

	//显式地初始化每行的首元素,其他未列出的元素执行默认值初始化。
	int ix[3][4] = { {0},{4},{8}};

	//显式地初始化第1行，其他元素执行值初始化
	int ix_02[3][4] = { 0,3,6,9 };


	//多维数组的下标引用

	//用arr的首元素为ia最后一行的最后一个元素赋值。
	/*
	首先通过索引0得到最外层的数组，它是一个大小为20的（多维）数组；接着获取这20个元素数组的第一个元素，
	得到一个大小为30的一维数组；最后再取出其中的第一个元素。
	*/
	ia[2][3] = arr[0][0][0];  

	//把row定义成一个含有4个整数的数组的引用，然后将其绑定到ia的第2行。
	int(&row)[4] = ia[1];  //把row绑定到ia的第二个4元素数组上。
}


//使用范围for语句处理多维数组
void MultidimensionalArray_02()
{
	size_t cnt = 0;
	int  ia[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
	for (auto &row:ia)              //对于外层数组的每一个元素
		for (auto &col : row)		//对于内层数组的每一个元素
		{
			col = cnt;						//将下一个值赋给该元素
			++cnt;							//将cnt加1
		}
	/*
	//报错:未找到可调用的“begin”函数(针对类型“int *”)
	//未找到可调用的“end”函数(针对类型“int *”)
		for (auto row:ia)              
		for (auto col : row)		
		{
			col = cnt;						
			++cnt;							
		}
	//解释：因为row不是引用类型，所以编译器初始化row时会自动将这些数组形式的元素（和其他类型的数组一样）转换成指向该数组内首元素的指针。
	//这样得到的row的类型是int*，显然内层的循环就不合法了，编译器将试图在一个int*内遍历，这显然和程序的初衷相去甚远。
	*/

	//！！！要使用范围for语句处理多维数组，除了最内层的循环外，其他所有循环的控制变量都应该时引用类型。

}

//指针和多维数组。    ！！！定义指向多维数组的指针时，千万别忘了这个多维数组实际是数组的数组。
void PointAndMultidimensionalArray_02()
{
	//因为多维数组实际上是数组的数组，所有由多维数组转换的来的指针，实际上是指向第一个内层数组的指针：
	int ia[3][4];			 //大小为3的数组，每个元素是含有4个整数的数组
	int(*p)[4] = ia;		//p指向含有4个整数的数组
	p = &ia[2];			//p指向ia的尾元素。

	int *ip[4];  //整型指针的数组
	int(*ip_02)[4]; //指向含有4个整数的数组


	//通过使用auot或者decltype就能尽可能地避免在数组前面加上一个指针类型了：


	//输出ia中每个元素的值，每个内层数组各占一行
	//p指向含有4个整数的数组
	for (auto p  =ia;p!=ia+3;++p)
	{
		for (auto q = *p; q!=*p+4;++q)
		{
			cout << *q << '   ';
		}
	}
	cout << endl;


	//上述for循环的另一种写法

	//p指向ia的第一个数组
	for (auto p = begin(ia); p != end(ia); ++p)
	{
		//p指向内层数组的首元素
		for (auto q =begin(*p); q!= end(*p);++q)
		{
			cout << *q << '   ';   //输出q所指的整数值
		}
	}
	cout << endl;
}

/*
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
	//myvector04();
	//mytest3_21();
	//mytest3_23();
	//testFor();
	point_04();
	return 0;
}
*/