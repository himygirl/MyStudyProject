#include <string>
#include <iostream>
#include <vector>

using namespace std;

/*
�ֲ���̬�����ڳ����ִ��·����һ�ξ������������ʱ��ʼ��������ָ��������ֹ�ű����٣�
�ڴ��ڼ伴ʹ�������ڵĺ�������ִ��Ҳ���������Ӱ�졣

*/
size_t count_calls()
{
	static size_t ctr = 0; // ���ý����󡣴�ֵ��Ȼ��Ч
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

//������������Ͷ��������������Ƚϵ�Ч�������е������ͣ�����IO�������ڣ������Ͳ�֧�ֿ���������
//�����������޸������βε�ֵʱ�����ʹ�ó������á�
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
//	test(b); //����testֻ�ܽ�����ͨstring��������const string

	 //string c  =const_cast<string>(b); //����const_castֻ�Ǹı��������ĵײ�const

	test02(b);
}

void test6_2_4()
{
	

	/*
	//������ʽ��ͬ����������print�����ǵȼ۵�
	//ÿ����������һ��const int*���͵��βΡ�
	void print(const int*);
	void print(const int[]);			 //���Կ���������������ͼ��������һ������
	void print(cosnt int[10]);		//�����ά�ȱ�ʾ�����������麬�ж��ٸ�Ԫ�أ�ʵ�ʲ�һ����
	
	int i =0, j[2] ={0,1};
	print(&i);		//��ȷ��&i��������int*
	print(j);			//��ȷ��jת����int*��ָ��j[0]

	//������ʹ������Ĵ���һ������������Ϊ�βεĺ���Ҳ����ȷ��ʹ������ʱ����Խ�硣
	*/

}

/*
c++ �������н������������������ã�����ͬ���ĵ����β�Ҳ��������������á�
��ʱ�������βΰ󶨵���Ӧ��ʵ���ϣ�Ҳ���ǰ󶨵������ϣ�
*/

//��ȷ���β�����������ã�ά�������͵�һ����
void test6_2_5(int (&arr)[10])
{
	for (auto elem:arr)
	{
		cout << elem << endl;
	}
}
/*
& arr���˵����űز�����
		f(int &arr[10])			//���󣺽�arr�����������õ�����
		f(int (&arr)[10])		//��ȷ:arr�Ǿ���10���������������������
*/

void test_6_24(const int (&ia)[10]) //���������������ǲ��Ե�(const int ia[10])���Դ�ֵ�ķ�ʽת�����飬�Ǵ���ġ�
{
	//sizeof(ia)/sizeof(ia[0])  ��ȡ�������Ԫ�ظ���
	cout << "sizeof(ia)     " << sizeof(ia)/sizeof(ia[0])<< endl;
	for (int i = 0; i<sizeof(ia);++i)
	{
		cout <<ia[i] << endl;
	}
	system("pause");
}

//���пɱ��βεĺ���
/*
1.������е�ʵ��������ͬ�����Դ���һ����Ϊinitializer_list�ı�׼�����ͣ�
2.���ʵ�ε����Ͳ�ͬ�����ǿ��Ա�дһ������ĺ�����Ҳ������ν�Ŀɱ����ģ��
3.c++����һ��������β����ͣ���ʡ�Է����������������ݿɱ�������ʵ�Ρ�������Ҫע����ǣ����ֹ���һ��ֻ������c���������Ľӿڳ���


//initializer_list �βΣ�initializer_list��һ�ֱ�׼�����ͣ�ģ�����ͣ������ڱ�ʾĳ���ض����͵�ֵ�����顣
//initializer_list�����е�Ԫ����Զ�ǳ���ֵ�������޷��ı�initializer_list������Ԫ�ص�ֵ


initializer_list<T> lst; //Ĭ�ϳ�ʼ���� T����Ԫ�صĿ��б�
initializer_list<T> lst{a,b,c...}; //lst��Ԫ�������ͳ�ʼֵһ���ࣻlst��Ԫ���Ƕ�Ӧ��ʼֵ�ĸ������б��е�Ԫ����const

lst2(lst)   
lst2 = lst  //������ֵһ��initializer_list���󲻻´���б��е�Ԫ�أ�������ԭʼ�б�͸�������Ԫ��

lst.size()   //�б��е�Ԫ������
lst.begin()   //����ָ��lst�е���Ԫ�ص�ָ��
lst.end()		//����ָ��lst��βԪ����һλ�õ�ָ��
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

//ʡ�Է��β�
/*
ʡ�Է��β���Ϊ�˱���c++�������ĳЩ�����c��������õģ���Щ����ʹ������Ϊvarargs�� c ��׼�⹦�ܡ�
ͨ����ʡ�Է��ββ�Ӧ��������Ŀ�ġ���� c �������ĵ����������ʹ��varargs

��������ʡ�Է��β�Ӧ�ý�������c �� c++ ͨ�õ����͡��ر�Ӧ��ע����ǣ�����������͵Ķ����ڴ��ݸ�ʡ�Է��β�ʱ���޷���ȷ������

ʡ�Է��β�ֻ�ܳ������β��б�����һ��λ�ã�������ʽ�������������:
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

//���÷��ؾֲ���������û�ָ��
/*
������ɺ�����ռ�õĴ���ռ�Ҳ��֮���ͷŵ�����ˣ�������ֹ��ζ�žֲ����������ý�ָ������Ч���ڴ�����:
*/
// ���ش���:���������ͼ���ؾֲ�����ı���

/*
ͬ�������ؾֲ������ָ��Ҳ�Ǵ���ġ�һ��������ɣ��ֲ������ͷţ�ָ�뽫ָ��һ�������ڵĶ���
*/
const string& manip()
{
	string ret ="abc";
	if (!ret.empty())
	{
		return ret; //����:���ؾֲ����������!     //warning C4172: ���ؾֲ���������ʱ�����ĵ�ַ: ret
	}
	else
	{
		return "Empty"; //����:"Empty"ʱһ���ֲ���ʱ��    //warning C4172: ���ؾֲ���������ʱ�����ĵ�ַ: ret
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
	return str[ix];            //�ٶ�����ֵ����Ч��
}

void get_val()
{
	string s("a value");

	cout << s << endl;
	get_val(s, 0) = 'A';     //��s[0]��ֵ��ΪA
	//  shorterstring("hi","bye") ="X";		//���󣺷���ֵ�Ǹ�����
	cout << s << endl;   //���A value
}

//�б��ʼ������ֵ��
/*
�������Է��ػ����Ű�Χ��ֵ���б��������������ؽ�����˴����б�Ҳ�����Ա�ʾ�������ص���ʱ�����г�ʼ����
*/
vector<string> process()
{
	string expected = "abc";
	string actual = "def";
	if (expected.empty())
	{
		return {};				//����һ����vector����
	}
	else if (expected == actual)
	{
		return { "functionX","okay" }; //�����б��ʼ����vector����
	}
	else
	{
		return { "functionX",expected,actual };
	}
}

//�ݹ�
//����val�Ľ׳ˣ���1*2*3....*val

int factorial(int val)
{
	if (val > 1)
	{
		return factorial(val - 1)*val;
		//return factorial(val--)*val; //�ᵼ�±���
	}
	return 1;
}



//�ں���ϰ 6.32
//��ȷ�ĳ��򣬷��ص��������1~10��Ԫ��
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
		test6_33(a, ix); //�ݹ�
	}
}

//6.3.3 ��������ָ��

/*
��Ȼ���﷨����˵��Ҫ�붨��һ�����������ָ������õĺ����ȽϷ�����������һЩ�������Լ���һ����
������ֱ�ӵķ�����ʹ�����ͱ���
*/
typedef int arrT[10]; //arrT��һ�����ͱ�����������������Ǻ���10������������
//using arrT = int[10]; //arrT�ĵȼ�������

//arrT* func(int i); // func ����һ��ָ����10�������������ָ��

//����һ����������ָ��ĺ�����
int arr_01[10];     //arr_01 ��һ������10������������
int *p1[10];			//p1��һ������10��ָ�������
int(*p2)[10] = &arr_01;  //p2��һ��ָ�롣��ָ����10�����������顣

/*
�ٸ����ӣ��������func����������û��ʹ�����ͱ���
int (*func(int i)) [10];
���԰������µ�˳����������������ĺ��壺

func(int i)��������func����ʱ��Ҫһ��int���͵�ʵ�Ρ�
(*func(int i)) ��ζ�����ǿ��ԶԺ������õĽ��ִ�н����ò�����
(*func(int i))[10] ��ʾ������func�ĵ��ý��õ�һ����С��10�����顣
int (*func(int i))[10] ��ʾ�����е�Ԫ����int���͡�
*/


//ʹ��β�÷������ͣ�������kael ����̫����
void func_02()
{
	//func_01 ����һ��int���͵�ʵ�Σ�����һ��ָ�룬��ָ��ָ����10�����������顣
	auto func_01(int i)->int(*)[10];	
}

//���غ�const�β�
//һ��ӵ�ж���const���β��޷�����һ��û�ж���const���β����ֿ���:
void myfunction(int i){}
//void myfunction(const int i){}   //error C2084: ������void myfunction(int)����������  //�ᱨ��

void myfunction_02(int * i) {}
//void myfunction_02( int * const i) {}   //error C2084: ������void myfunction_02(int *)���������� //kael�����const �Ƕ���const������ i


//���ڽ������û�ָ��ĺ�����˵�������ǳ������Ƿǳ�����Ӧ���ββ�ͬ
//������4�����������غ���

void myfunction_03(int& i) {}
void myfunction_03(int i) {}

void myfunction_03(int * i) {}
void myfunction_03(const int * i) {}     //kael��ָ��const int��ָ�롣�����ǵײ�ָ��
//���飺���ֻ������Щȷʵ�ǳ����ƵĲ�������Щ����£���������ͬ��������ʹ�ó��������⡣

const string &shorterString(const string &s1, const string &s2)
{
	return s1.size() <= s2.size() ? s1 : s2;

}

string &shorterString(string& s1, string & s2)
{
	//auto &r = shorterString(s1,s2); //warning C4717: ��shorterString��: ��ݹ����пؼ�·������������������ʱ��ջ��� //kael:�������ͣ���ô�ǵ����˱��������ǵݹ顣
	auto &r = shorterString(const_cast<const string&>(s1), const_cast<const string&>(s2));
	return const_cast<string&>(r);
}

//������������
//����������ڲ����������������֣��������������������������ͬ��ʵ�塣�ڲ�ͬ�����������޷����غ�������
string read() { return ""; }
void print_02(const string& i) {}
void print_02(double i) {}
/*
����ڼ��������ʵ��֮��û���κ�һ��������ӱ��������õ���ʱ����ġ�����������������Ե�����Ϣ��
�������������غ���ʱ��Ӧ�þ�������ǿ������ת���������ʵ��Ӧ����ȷʵ��Ҫǿ������ת������˵��������Ƶ��βμ��ϲ�����
*/
void fooBar(int ival)
{
	bool read = false; //������������������read
	//string s = read();   //����read��һ��boolֵ�����Ǻ���
	//���õ�ϰ�ߣ�ͨ����˵���ھֲ���������������������һ���õ�ѡ��

	void prinprint_02(int i);			//��������������֮ǰ��print  ,//kael �����������º���
	//void prinprint_02(int i) {};		//���غ��������ǷǷ���
	//print("Value: ");   //����print(const string&) �����ص���
	print_02(ival);			//��ȷ����ǰprint(int) �ɼ�
	print_02(3.14);			//��ȷ������print(int); print(double)�����ص���

}

//6.5������;��������
//6.5.1Ĭ��ʵ��
//���ǿ���Ϊһ�������βζ���Ĭ��ֵ��������Ҫע����ǣ�һ��ĳ���βα�������Ĭ��ֵ��������������βζ�������Ĭ��ֵ
//kael��ǰ��û�£� ��ղ��С�

typedef string::size_type sz; 
string screen(sz ht = 24, sz wid = 80, char backgrnd = ' ') { return " "; }
//string screen(sz ht, sz wid , char backgrnd = ' abc') { return " "; } //error C2084: ������std::string screen(sz,sz,char)����������

//6.5.2 �������� �� constexpr����
//����˵��ֻ���������������һ�����󣬱���������ѡ������������

inline const string & testInline(const string &s1, const string & s2)
{
	return s1.size() <= s2.size() ? s1 : s2;
}
/*
һ����˵���������������Ż���ģ��С������ֱ�ӡ�Ƶ�����õĺ������ܶ����������֧�������ݹ麯����
*/

//constexpr ����   ��ָ�����ڳ������ʽ�ĺ�����
//���ص�Լ��: �����ķ������ͼ������βε����Ͷ�������ֵ���ͣ����Һ������б�������ֻ��һ��return ��䣺
constexpr int new_sz() { return 42; }
constexpr int foo = new_sz();   //��ȷ��foo��һ���������ʽ

//��������constexpr�����ķ���ֵ����һ��������
//���arg �ǳ������ʽ����scale(arg)Ҳ�ǳ������ʽ
constexpr size_t scale(size_t  cnt) { return new_sz()*cnt; }
//��scale��ʵ���ǳ������ʽʱ�����ķ���ֵҲʱ����ֵ����֮��Ȼ��
int arr[scale(2)];   //��ȷ:scale(2)�ǳ������ʽ
int i = 2;				//i ���ǳ������ʽ
//int a2[scale(i)];     //����:scale(i)���ǳ������ʽ

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
//assert���ԭ�Ͷ�����<assert.h>�У�����������������������ش�������ֹ����ִ�С�
void testAssert()
{
	FILE *fp;
	//�������ʾ����Ϊ�߰汾��vs���ڰ�ȫ���ϣ����˵���������:https://blog.csdn.net/xiaojinzichen/article/details/47322061
	//error C4996: 'fopen': This function or variable may be unsafe. Consider using fopen_s instead. To disable deprecation, use _CRT_SECURE_NO_WARNINGS. See online help for details.
	//fp = fopen("d:/test.txt", "w"); //�Կ�д�ķ�ʽ��һ���ļ�����������ھô���һ��ͬ���ļ�
	fopen_s(&fp,"d:/test.txt", "w");
	assert(fp);    //�������ﲻ�����
	fclose(fp);

	//fp = fopen("noexitfile.txt", "r");   //��ֻ����ʽ��һ���ļ�����������ھô��ļ�ʧ��
	fopen_s(&fp,"noexitfile.txt", "r");
	assert(fp);				//�����������
	fclose(fp);				//������Զ��ִ�в�������
}

//#define MYTEST 3  //���治��Ҫ�� ��
void testIndef()
{
	//��� MYTEST δ���壬��ִ��#ifndef ��   #endif֮��Ĵ��룬���������MYTEST,��ִֻ��   #endif �Ĵ���
#ifndef MYTEST001   //����"if not defined"�ļ�д
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
	f(2.56, 42);  //���Ϸ��� 42Ϊ int
	
	����:
	��f��: 2 �����������Ƶ�ת��
		�����ǡ�void f(double,double)����    ��void f(int,int)��, ����ƥ������б�(double, int)��ʱ	
		kael: ��Ϊ ���� f ������������������	void f(int a, int b) {};    void f(double a, double b= 3.14) {}; ���������ԣ����ǲ����˶����ԡ�
		//��ɶ����Ե��õ�ԭ�����ں���ƥ��ʱ�������������ṩ��ƥ��һ���ã��������Ҳ���Ψһ�����ƥ�䡣
		���ȥ��һ������ô���������ȷ�ġ���Ϊ���¸��
		��ѡ����:����ƥ��ĵ�һ����ѡ�����ε��õ����غ������������еĺ�������Ϊ��ѡ����
		���к���:����ʵ��������Ӻ�ѡ��������ѡ���ܱ���ʵ�ε��õĺ������˴�ѡ���ĺ�������Ϊ���к�����
	*/
	f(42);
	f(42, 0);
	f(2.56, 3.14);

}

//����ָ�� ������ָ��ָ����Ǻ������Ƕ���

//pfָ��һ���������ú����Ĳ���������const string�����ã�����ֵ��bool����
bool(*pf)(const string& a, const string & b); //��*pf�����űز����٣�δ��ʼ�� //kael ������һ��ָ������ָ��

//ʹ�ú���ָ��
bool lengthCompare(const string& a, const string & b) {return true; }

string::size_type sumLength(const string&, const string&);
bool cstringCompare(const char*, const char *);
void testfunctionPoint()
{

	pf = 0; //��ȷ��pf ��ָ���κκ���
//	pf = sumLength;  //���󣺷������Ͳ�ƥ��
//	pf = cstringCompare; //�����β����Ͳ�ƥ��
pf = lengthCompare;		//pf ָ����ΪlengthCompare�ĺ���
pf = &lengthCompare;   //�ȼ۵ĸ�ֵ��䣺ȡ��ַ���ǿ�ѡ��

bool b1 = pf("hello", "goodbye");							//����lengthCompare����
bool b2 = (*pf)("hello", "goodbye");						//һ���ȼ۵ĵ���
bool b3 = lengthCompare("hello", "goodbye");		//��һ���ȼ۵ĵ���
}

//���غ�����ָ��

void ff_02(int* a) {};
void ff_02(unsigned int a) {};
void(*pf1)(unsigned int) = ff_02;   //pf1 ָ��ff(unsigned)

//void(*pf2)(int) = ff_02;    //����û���κ�һ��ff����β��б�ƥ��
//double(*pf3)(int *) = ff_02; //����ff_02 ��pf3  �ķ������Ͳ�ƥ��

//����ָ���β�
//�βο�����ָ������ָ�롣��ʱ���βο������Ǻ������ͣ�ʵ����ȴ��ָ��ʹ��:

//�������β��Ǻ������ͣ������Զ���ת����ָ������ָ��
void useBigger(const string & s1, const string& s2, bool pf_03(const string&, const string &)) {};

//�ȼ۵���������ʽ�ؽ��βζ����ָ������ָ��
void useBigger(const string &s1, const string &s2, bool(*pf_03(const string &, const string &))) {};

void testUseBigger() {

 string a = "a";
 string b = "b";
//���ǿ���ֱ�ӰѺ�����Ϊʵ��ʹ�ã���ʱ�����Զ�ת����ָ��
useBigger(a, b, lengthCompare);

}

//���ͱ�����decltype�������Ǽ�ʹ���˺���ָ��Ĵ���:
//Func �� Func2�Ǻ�������
typedef bool func(const string&, const string&);
typedef decltype(lengthCompare) Func2;   //�ȼ۵�����

//FuncP �� FuncP2 ��ָ������ָ��
typedef bool(*FuncP)(const string&, const string&);
typedef decltype(lengthCompare) *FuncP2;   //�ȼ۵�����

//-----��auto��decltype���ں���ָ������
string::size_type sumLength(const string&, const string&);
string::size_type largerLength(const string&, const string&);
//�������βε�ȡֵ��getFun��������ָ��SumLength����largerLength��ָ��
decltype (sumLength) *getFcn(const string&);
/*
����getFunΨһ��Ҫע��ĵط��ǣ��μǵ����ǽ�decltype������ĳ������ʱ�������غ��������Ͳ���ָ�����͡���ˣ�������ʽ�ؼ���* �Ա���������Ҫ����ָ�룬���Ǻ�����


*/

/*
int main()
{
	int array_a[10] = {1,2,3,4,5,6,7,8,9,10};
	int array_b[9] = { 1,2,3,4,5,6,7,8,9 };
	//Test_6_1_1();
//	test_6_24(array_b); //�޷��ӡ�int [9]��ת��Ϊ��const int [10]��
	//test_6_24(array_a); //���ֻ���Ǵ�СΪ10��Ԫ�ص�����
	//error_msg02();
	//test_6_27({ 1,2,3 });

	//std::cout << manip() << endl;  //kael : �������쳣�����±�����
	//std::cout << manip_02() << endl; //kael :��������õ�ʱ���������������ã�����ԭ����ֵ�Ƿ����٣�����û��Ӱ�졣���Բ�������������

	
	//std::cout << factorial(5) << std::endl; //kael: ������ܵ�ֵ����������forѭ��һ�����ݹ�һ�Σ����һ�Ρ�


	string abc = "abc";
	string def = "def";
	
	std::cout << shorterString(abc, def) << std::endl;


	testIndef();
	system("pause");
	return 0;
}

*/