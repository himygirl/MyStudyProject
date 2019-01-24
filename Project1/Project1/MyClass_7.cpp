#include <iostream>
#include <windows.h>
#include <string.h>
#include <vector>

using namespace std;

// ����this �� this��һ������ָ��

//���캯����ÿ���඼�ֱ��������Ķ��󱻳�ʼ���ķ�ʽ����ͨ��һ���򼸸�����ĳ�Ա���������������ĳ�ʼ�����̡�
//������������һ�����ǣ����캯��û�з���ֵ������֮���������������������캯�����ܱ�������const�ģ�
//�����Ǵ������һ��const����ʱ��ֱ�����캯����ɳ�ʼ���������������ȡ���䡰���������ԣ���ˣ����캯����const����Ĺ�������У���������дֵ
//ֻ�е���û�������κι��캯��ʱ���������Ż��Զ�������Ĭ�Ϲ��캯����
class p
{


};
struct Sales_data  
{
	//�����Ĺ��캯��
	Sales_data() = default;
	Sales_data(const std::string &s) :bookNo(s) {}
	/*
	��ĳ�����ݳ�Ա�����캯����ʼֵ����ʱ����������ϳ�Ĭ�Ϲ��캯����ͬ�ķ�ʽ��ʽ��ʼ����
	���飺���캯����Ӧ�����׸��ǵ����ڵĳ�ʼֵ�������¸���ֵ��ԭ����ͬ������㲻��ʹ�����ڳ�ʼֵ�������й��캯����Ӧ����ʾ��ʼ��ÿ���������͵ĳ�Ա��
	*/
	Sales_data(const std::string &s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(p*n) {}
	Sales_data(std::istream &);

	//֮ǰ���е�������Ա
	std::string isbn()const { return bookNo; }
	Sales_data& combine(const Sales_data&);
	double avg_price() const;
		std::string bookNo;
		unsigned	units_sold = 0;
		double revenue = 0.0;
};

//��Ԫ
/*
�����������������ߺ����������ķǹ��г�Ա������ʱ�ǣ�����������ߺ�����Ϊ������Ԫ��

��Ԫ��ϵ�����ڴ����ԣ�ÿ���ฺ������Լ�����Ԫ�����Ԫ������
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
	//	TestA.MyTestFriendA; //error C3867: ��MyClassTestA::MyTestFriendA��: �Ǳ�׼�﷨����ʹ�� "&" ������ָ���Ա��ָ��
	}
	MyClassTestB() {};
	~MyClassTestB() {};

private:
	void MyTestFriendB() {};
};


//��Ԫ����
//���һ�������һ�����غ���������������Ԫ������Ҫ�����麯���е�ÿһ���ֱ�������
class A
{
public:
	friend void set_show(int x, A &a);      //�ú�������Ԫ����������
private:
	int data;
};

void set_show(int x, A &a)  //��Ԫ�������壬Ϊ�˷�����A�еĳ�Ա
{
	a.data = x; //�������û�м���Ԫ���������򱨴�error C2248: ��A::data��: �޷����� private ��Ա(�ڡ�A����������)
	cout << a.data << endl;
}


//��Ԫ��
class A_02
{
public:
	friend class C_02;                         //������Ԫ�������
private:
	int data;
};

class C_02             //��Ԫ�ඨ�壬Ϊ�˷�����A�еĳ�Ա
{
public:
	void set_show(int x, A_02 &a) { a.data = x; cout << a.data << endl; }
};

//��Ԫ��Ա����

class A_03;    //���õ���Ԫ��Ա����ʱ����ע����Ԫ��������Ԫ����֮��Ļ���������������A_03������


class B_03
{
public:
	void set_show(int x, A_03 &a);             //�ú�������A����Ԫ����  //���ע�͵������class A_03, �򱨴�error C2061: �﷨����: ��ʶ����A_03��
};

class A_03
{
public:
	friend void B_03::set_show(int x, A_03 &a);   //�ú�������Ԫ��Ա����������
private:
	int data;
	void show() { cout << data << endl; }
};

void B_03::set_show(int x, A_03 &a)       //ֻ���ڶ�����A����ܶ���ú������Ͼ���������Ϊ��Ԫ��Ϊ�˷�����A�ĳ�Ա
{
	a.data = x;
	cout << a.data << endl;
}

//��Ԫ������������
/*
��ͷǳ�Ա�������������Ǳ��������ǵ���Ԫ����֮ǰ����һ�����ֵ�һ�γ�����һ����Ԫ������ʱ��������ʽ�ؼٶ��������ڵ�ǰ��������ʱ�ɼ��ġ�
Ȼ������Ԫ����һ����������ڵ�ǰ�������С�
��������������ڲ�����ú���������Ҳ����������ⲿ�ṩ��Ӧ�������Ӷ�ʹ�ú����ɼ������仰˵����ʹ���ǽ�������������Ԫ����ĳ�Ա���ø���Ԫ��������Ҳ�����Ǳ��������ģ�
*/

struct X 
{
	friend void f_03() {/*��Ԫ�������Զ���������ڲ�*/}
	//X() { f(); }  //����f��û�б�����   //����󱨴�error C3861: ��f��: �Ҳ�����ʶ��
	void g();
	 void h();
};

//void x::g() { return f(); }    //����f��û�б�����   //����� error C2653: ��x��: ������������ռ����ƣ�error C3861: ��f��: �Ҳ�����ʶ��
void f_03();							//�����Ǹ�������X�еĺ���
void X::h() { return f_03(); }	//��ȷ������f������������������


//screen��ĳ�Ա����
class Screen
{
public:
	typedef std::string::size_type pos;
	/*
	�����Ѿ��ṩ��һ�����캯�������Ա������������Զ�����Ĭ�ϵĹ��캯����������ǵ�����ҪĬ�ϵĹ��캯����������ʾ�ذ�������������
	*/
	Screen() = default; //��ΪScreen����һ�����������Ա������Ǳ���ģ�cursor�������ڳ�ʼֵ��ʼ��Ϊ0

	Screen(pos ht, pos wd, char c) :height(ht), width(wd), contents(ht* wd, c) {}

	char get()const						//��ȡ��괦���ַ�
	{ return contents[cursor]; }		 //��ʽ����
	inline char get(pos ht, pos wd) const; //��ʽ����

	Screen &move(pos r, pos c);   //����֮ǰ����Ϊ����

private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string  contents;

};

//�ɱ����ݳ�Ա
/*
һ�� �ɱ����ݳ�Ա��Զ������const����ʹ����const����ĳ�Ա
*/

class Screen_02
{
public:
	typedef std::string::size_type pos;
	void some_member() const;

	Screen &set(char);
	Screen &set(pos, pos, char);

	char get()const						//��ȡ��괦���ַ�
	{
		return contents[cursor];
	}		 //��ʽ����
	inline char get(pos ht, pos wd) const; //��ʽ����

	Screen &move(pos r, pos c);   //����֮ǰ����Ϊ����


	private:
	mutable size_t access_ctr; //��ʹ��һ��cosnt������Ҳ�ܱ��޸�
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string  contents;
};




void Screen_02::some_member() const
{
	/*
	����some_member��һ��cosnt��Ա����������Ȼ�ܹ��ı�access_ctr��ֵ���ó�Ա�Ǹ��ɱ��Ա������κγ�Ա����������const�������ڶ��ܸı�����ֵ
	*/
	++access_ctr;     
}

//����*this �ĳ�Ա����
class Screen_03
{
public:
	typedef std::string::size_type pos;
	void some_member() const;

	Screen_03 &set(char);
	Screen_03 &set(pos, pos, char);

	char get()const						//��ȡ��괦���ַ�
	{
		return contents[cursor];
	}		 //��ʽ����
	inline char get(pos ht, pos wd) const; //��ʽ����

	Screen &move(pos r, pos c);   //����֮ǰ����Ϊ����

	Screen_03  &MyConst(char,pos) const ;

private:
	mutable size_t access_ctr; //��ʹ��һ��cosnt������Ҳ�ܱ��޸�
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string  contents;
};

inline Screen_03 &Screen_03::set(char c)
{
	contents[cursor] = c;
	return *this;    //��this������Ϊ��ֵ����
}

inline Screen_03 &Screen_03::set(pos r, pos col, char ch)
{
	contents[r *width + col] = ch;
	return *this;
}
/*
һ��cosnt��Ա������������õ���ʽ����*thi����ô���ķ������ͽ��ǳ������á�
*/

/*
//����error C2511: ��Screen_03 &Screen_03::MyConst(char,Screen_03::pos)��:��Screen_03����û���ҵ����صĳ�Ա����
 Screen_03 &Screen_03::MyConst(char a, pos b)
{
	return *this;
}
*/

//����const������
//ͨ�����ֳ�Ա�����Ƿ���const�ġ����ǿ��Զ���������ء�
class Screen_04
{
public:	
	//���ݶ����Ƿ���const������display����
	Screen_04 &display(std::ostream &os) { return *this; }
	const Screen_04 &display(std::ostream &os) const { return *this; }

private:

};

/*
void test_04()
{
	Screen_04 myScreen(5, 3);
	const  Screen_04 blank(5, 3);

	myScreen.set('#').display(cout);  //���÷ǳ����汾
	blank.display(cout);						//���ó����汾

}

*/

//�������
//���ǿ��԰�������Ϊ���͵�����ʹ�ã��Ӷ�ֱ��ָ�������͡�
//���������������е�ȫ��������Żᴦ���Ա�����Ķ���

//����Ҳ���Խ��������࣬����ʱ��������
class Screen_05;     //Screen_05 �������  //�����������ʱ������ǰ�������������������������Screen_05 ����ָ��Screen��һ�������͡�
/*
����һ������˵�������Ǵ������Ķ���֮ǰ������뱻������������ܽ��������������򣬱��������޷��˽������Ķ�����Ҫ���ٴ���ռ䡣
*/
//һ��һ��������ֳ��ֺ����ͱ���Ϊ���������ˣ�����δ���壩��������������ָ�����������͵����û�ָ�룺
class  Link_screen
{
	//Screen_05 windows;   //����ʹ��δ����� class��Screen_05��
	Link_screen *next;
	Link_screen *prev;
};

//7.3.3 �ں���ϰ
/*
֪ʶ��1�����Խ��൱��һ�������������������༴ʹ��Ա������ȫ��ͬ��Ҳ���ڲ�ͬ������
֪ʶ��2�����������ָ�����������͵�ָ���������
֪ʶ��3������һ����Ķ���֮ǰ�����ȶ�����࣬�����������޷��ñ������˽⵽������Ҫ���ٿռ��
*/
class MyclassY;  //ǰ�����������û�У��ᱨ��

class MyclassX
{
	MyclassY *   MyclassTestY;  //���û��  MyclassY�� ǰ������ ����error C2143: �﷨����: ȱ�١�;��(�ڡ�*����ǰ��)


};
class MyclassY
{
	MyclassX MyclassTestX;

};


//�������Ա���������ֲ���
typedef double Money;
string bal;
class Account
{
public:
	Money balance() { return bal; }   //�ú�����return��䷵����Ϊbal�ĳ�Ա���������������� string ����
private:
	Money bal;
};


//ע�⣺��δ����Ϊ��˵�����ã�����һ�κܺõĴ���
//������ͨ������²�����Ϊ�����ͳ�Աʹ��ͬ��������

int height; //������һ�����֣��Ժ���Screen_06��ʹ��
class Screen_06
{
public:
	typedef std::string::size_type pos;
	void dummy_fcn(pos hight)
	{
		cursor = width * height;   //�ĸ�height�����ĸ�������  ��Աheight
		cursor = width * this->height; //��Աheight
		//��һ�ֱ�ʾ�ó�Ա�ķ�ʽ
		cursor = width * Screen_06::height;   //��Աheight

		cursor = width * ::height;    //�ĸ�height��  ���Ǹ�ȫ�ֵ�

		//NOTE:�������Ķ������ص��ˣ���������Ȼ�������������������������
	}

private:
	pos cursor = 0;
	pos height = 0 , width = 0;

};

//���ļ������ֵĳ��ִ�������н���

int height_07;
class Screen_07
{
public:
	typedef std::string::size_type pos_07;
	void setHeight(pos_07 var);
	pos_07 height_07 = 0;   //����������������е�height_07

};

Screen_07::pos_07 verify(Screen_07::pos_07) { Screen_07 myscreen_07; return myscreen_07.height_07; }
/*
Screen_07::pos_07 verify(Screen_07::pos_07);
kael��verifyֻ��������δ�����ʱ����ô�ڱ����ã�������������ʾ����
�������:�޷��������ⲿ���� "unsigned int __cdecl verify(unsigned int)"
*/
void Screen_07::setHeight(pos_07 var)
{
		//var:����
		//height����ĳ�Ա
		//verify:ȫ�ֺ���
	 height_07 = verify(var);  //��Ϊ����Ӧ����ȫ�ֺ���verify����verify��δ���壬���Ե�����ʾ���޷��������ⲿ���� "unsigned int __cdecl verify(unsigned int)"    
}
/*
��ע�⣬ȫ�ֺ���verify��������screen_07��Ķ���֮ǰ�ǲ��ɼ��ġ�Ȼ�������ֲ��ҵĵ����������˳�Ա��������֮ǰ��ȫ���������ڴ����У�verify������λ��setHeight�Ķ���֮ǰ����˿��Ա�����ʹ�á�

*/


//��ϰ7.34

/*
֪ʶ��1�����ֲ��ҵ�˳�����ڶ��⡢���϶���

֪ʶ��2����Ķ��崦���裺���ȱ����Ա��������ֱ����ȫ���ɼ����ٱ��뺯����

����Ա�������������ȫ��������֮��Żᱻ���壬���Կ��Ե��ú����ж�����κ�����

֪ʶ��3�������У�������Ҫ���⴦������Ƕ��������һ��ʼ�����Ҳ����������������ͬ��

�����У�����ִ���posδ����


class Screen_08
{
public:
	
	void dummy_fcn(pos hight)
	{
		cursor = width * height;   //�ĸ�height�����ĸ�������  ��Աheight
		cursor = width * this->height; //��Աheight
		//��һ�ֱ�ʾ�ó�Ա�ķ�ʽ
		cursor = width * Screen_08::height;   //��Աheight

		cursor = width * ::height;    //�ĸ�height��  ���Ǹ�ȫ�ֵ�

		//NOTE:�������Ķ������ص��ˣ���������Ȼ�������������������������
	}

private:
	pos cursor = 0;
	pos height = 0, width = 0;
	typedef std::string::size_type pos;   
};
*/

//��ϰ7.35
typedef string Type;
Type initVal();
class Exercise
{
public:
	typedef double Type;
	Type setVal(Type);
	//Type initVal();  //�޷��������ⲿ���� "public: double __thiscall Exercise::initVal(void)" (?initVal@Exercise@@QAENXZ)���÷����ں��� "public: double __thiscall Exercise::setVal(double)" (?setVal@Exercise@@QAENN@Z) �б�����
	Type initVal() { return MyType; }  //����ͨ����

private:
	int val;
	Type MyType;
};

Type Mytype02;
//Type Exercise::setVal(Type parm) //kael������ķ���Type ��ȫ�ֵ����ͣ�typedef string Type; //���뱨��:error C2556: ��Type Exercise::setVal(Exercise::Type)��: ���غ����롰Exercise::Type Exercise::setVal(Exercise::Type)��ֻ���ڷ��������ϲ�ͬ
Exercise::Type Exercise::setVal(Type parm)  
{
	val = parm + initVal();      // warning C4244: ��=��: �ӡ�Exercise::Type��ת������int�������ܶ�ʧ����

	//return  val;  
	return MyType;
	//return Mytype02;
}

//���캯����̽
//���캯���ĳ�ʼֵ��ʱ�ز�����
//�����Ա��const���������õĻ������뽫���ʼ�������Ƶģ�����Ա����ĳ���������Ҹ���û�ж���Ĭ�Ϲ��캯��ʱ��Ҳ���뽫�����Ա��ʼ����
class ConstRef
{
public:
	ConstRef(int ii);
private:
	int i;
	//const int ci;  //kael��δ��ʼ�����ᵼ�¶��幹������ʱ������ error C2789: ��ConstRef::ci��: �����ʼ�������޶����͵Ķ���
	const int ci =0;
	//int &ri;     //kael��δ��ʼ�����ᵼ�¶��幹������ʱ������ error C2530: ��ConstRef::ri��: �����ʼ������
	int &ri = i;
};

ConstRef::ConstRef(int ii)
{
	i = ii;			//��ȷ
	//ci = ii;			//���󣺲��ܸ�const��ֵ  
	//ri = i;			//����ri û����ʼ��		//

}
/*
Note: �����ԱʱConst�����ã���������ĳ��δ�ṩĬ�Ϲ��캯���������ͣ����Ǳ���ͨ�����캯����ʼ���б�Ϊ��Щ��Ա�ṩ��ֵ��

���飺ʹ�ù��캯����ʼ��
		�ںܶ����У���ʼ���͸�ֵ�������¹صײ�Ч�ʵ����⣺ǰ��ֱ�ӳ�ʼ�����ݳ�Ա���������ȳ�ʼ���ڸ�ֵ��
		����Ч�����������Ҫ���ǣ�һЩ���ݳ�Ա���뱻��ʼ���������������ʹ�ù��캯����ʼ����ϰ�ߣ������ܱ���ĳЩ�����벻���ı�������ر��������е��ຬ����Ҫ���캯����ʼ���ĳ�Աʱ��
*/

//��Ա��ʼ����˳��
//���캯����ʼֵ�б�ֻ˵�����ڳ�ʼ����Ա��ֵ�������޶���ʼ���ľ���ִ��˳��
//�������������һ����Աʱ����һ����Ա����ʼ���ģ���ô��������Ա�ĳ�ʼ��˳��ͺܹؼ��ˡ�
class XXX
{
	int i;
	int j;
public:
	//δ����ģ�i��j֮ǰ����ʼ��
	XXX(int val) :j(val), i(j) {};  //kael������ͨ���������ֳ�ʼ����ʽ�����ܻᵼ��һЩ���⣿��������
	/*
	�ӹ��캯����ʼֵ����ʽ�������·�������val��ʼ����j��Ȼ������j��ʼ��i��ʵ���ϣ�i�ȱ���ʼ������������ʼ����Ч������ͼʹ��δ�����ֵj��ʼ��i ��

	Best practices�������캯����ʼֵ��˳�����Ա������˳�򱣳�һ�¡�����������ܵĻ�����������ʹ��ĳЩ��Ա��ʼ��������Ա��
	
	*/
};

//��ϰ��7.38
/*
Sales_data(std::istream &is = std::cin) { read(is, *this); }//��Ĭ��ʵ��ֱ�Ӹ����������
*/

class MyTestClass
{
public:
	 string mystring = " ";

	 //MyTestClass(string a) ;//���캯��ֻ����δ���壺�޷��������ⲿ���� "public: __thiscall MyTestClass::MyTestClass(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >)
	 MyTestClass(string a) {};
	//MyTestClass(std::istream myIstream);
};
void test_07()
{
	MyTestClass Mytestclass02("string");
	

}

//ί�й��캯��

//��ϰ7.41
//֪ʶ��1��ί�й��캯����һ��ί�й��캯��ʹ������������������캯��ִ�����Լ��ĳ�ʼ������
class OH
{
	//kael_������������ӣ������˽⣬ί�й��캯�����ص��ǣ��Լ��ĳ�ʼ�����̣������ϡ�������������ݡ�����⡣
	OH(string s, int a, int b) :book(s), price(a), sale(b) {}   //���������캯���б�ͺ��������ȱ�ִ��
	OH() :OH("", 0, 0) {} //Ĭ�Ϲ��캯����ί�и������������캯��
	OH(istream& is) :OH() {}    //OH(istream& is) ��һ��ί�й��캯������ί�и��˹��캯��OH()


	string book;
	int price;
	int sale;

};

//֪ʶ��2�������캯��ί�и���һ�����캯��ʱ����ί�еĹ��캯���ĳ�ʼֵ�б��亯�����ȱ�ִ�У����ŲŻ�ִ�е�ί�к����ĺ�����
class OH_02
{
public:
	OH_02(string s, int a, int b) :book(s), price(a), sale(b) { cout << "OH(string s, int a, int b)" << endl; } //���������캯���б�ͺ��������ȱ�ִ��
	OH_02() :OH_02("", 0, 0) {} //Ĭ�Ϲ��캯����ί�и������������캯��
	OH_02(istream& is) :OH_02() { cout << "OH(istream& is)" << endl; } //OH_02(istream& is) ��һ��ί�й��캯������ί�и��˹��캯��OH_02()

	string book;
	int price;
	int sale;
};
//Best Practices :����������������캯������ô���Ҳ�ṩһ��Ĭ�Ϲ��캯����



/*
//��Ĺ��캯���ڳ�ʼ����Աʱ�����������ַ�����
��ʽһ��

CSomeClass::CSomeClass()
{

	x = 0;

	y = 1;

}

��ʽ����

CSomeClass::CSomeClass() : x(0), y(1)
{
}

��ʽһ���ǿ��Գ�Ϊ��ֵ��ʼ����ͨ���ں������ڽ��и�ֵ��ʼ����

��ʽ�����ǳ�Ϊ�б��ʼ������ð�ź�ʹ�ó�ʼ���б���г�ʼ����

�����ַ�ʽ����Ҫ�������ڣ�
�����ں������г�ʼ��, �������е����ݳ�Ա�������ڴ�ռ��Ž��еġ�

�������ʹ�õڶ��ַ�����
*/

//Note ����ͨ��һ��ʵ�ε��õĹ��캯��������һ���ӹ��캯���Ĳ�����������������ʽת���Ĺ���


//���ƹ��캯�������������ʽת��
//��Ҫ����ʽת���ĳ����������У����ǿ���ͨ�������캯������Ϊexplicit������ֹ��
class Sales_data_02 
{
public:
	Sales_data_02() = default;
	Sales_data_02(const std::string &s, unsigned n, double p) :bookNo(s), units_sold(n), revenue(p*n) {}

	//Note��������explicit�ؼ����������캯��ʱ������ֻ����ֱ�ӳ�ʼ������ʽʹ�á����ң����������������Զ�ת��������ʹ�øù��캯����
	explicit Sales_data_02(const std::string &s) :bookNo(s) {}
	explicit Sales_data_02(std::istream&);
	explicit Sales_data_02(string c, int a);
private:
	string bookNo;
	unsigned units_sold;
	double revenue;

};
/*
//page ��265
//��ʱ��û���κι��캯����������ʽ�ع��� Sales_data_02 ����֮ǰ�������÷����޷�ͨ�����룺
item.combine(null_book);   //����string ���캯����explicit��
item.combine(cin);				//����istream���캯����explicit��
*/

//Ϊת����ʽ��ʹ�ù��캯��
/*
page ��265
���ܱ��������Ὣexplicit�Ĺ��캯��������ʽת�����̣��������ǿ���ʹ�������Ĺ��캯����ʽ��ǿ�ƽ���ת����

//��ȷ:ʵ����һ����ʽ�����Sales_data����
item.combine(Sales_data(null_book));

//��ȷ��static_cast ����ʹ��expicit �Ĺ��캯��
item.combine(static_cast<Sales_data>(cin));

*/

//7.5.5 �ۺ���
/*
�ۺ��ࣨaggregate class��ʹ���û�����ֱ�ӷ������Ա�����Ҿ�������ĳ�ʼ���﷨��ʽ����һ����������������ʱ������˵��ʱ�ۺϵģ�
*���г�Ա����public�ġ�
*û�ж����κι��캯����
*û�����ڳ�ʼֵ
*û�л��࣬Ҳû��virtual����

*/

//���磬���������һ���ۺ��ࣺ
struct Data
{
	int ival;
	string s;
};

//vall.ival =0 ; vall.s =string("Anna")
Data vall = { 0,"Anna" }; //���ǿ����ṩһ���������������ĳ�Ա��ʼ���б���������ʼ���ۺ�������ݳ�Ա��

//���󣺲���ʹ�á�Anna����ʼ��ival��Ҳ����ʹ��1024 ��ʼ�� s
//Data val2 = {"Anna", 0}; //��ʼֵ��˳�������������˳��һ��

/*
�����ʼֵ�б��е�Ԫ�ظ���������ĳ�Ա�������򿿺�ĳ�Ա��ֵ��ʼ������ʼ���б��Ԫ�ظ������Բ��ܳ�����ĳ�Ա������

ֵ��ע����ǣ���ʽ�س�ʼ����Ķ���ĳ�Ա�����������Ե�ȱ�㣺

*Ҫ��������г�Ա����Public��
*����ȷ��ʼ��ÿ�������ÿ����Ա�����ν���������û�������������ߣ�����Ϊ�û�����������ĳ����ʼֵ�������ṩһ����ǡ���ĳ�ʼֵ�����������ĳ�ʼ�����̿ӳ���ζ�����׳���
*��ӻ���ɾ��һ����Ա�Ժ����еĳ�ʼ����䶼��Ҫ����

*/

//7.5.6  ����ֵ������
/*
���ݳ�Ա��������ֵ���͵ľۺ���������ֵ�����ࡣ���һ���಻�Ǿۺ��࣬������������Ҫ����Ҳ��һ������ֵ�����ࣺ
*���ݳ�Ա������������ֵ����
*��������ٺ���һ��constexpr���캯��
*���һ�����ݳ�Ա�������ڳ�ʼֵ�����������ͳ�Ա�ĳ�ʼֵ������һ���������ʽ�����������Ա����ĳ�������ͣ����ʼֵ����ʹ�ó�Ա�Լ���consexpr���캯����
*�����ʹ������������Ĭ�϶��壬�ó�Ա����������Ķ���

*/


//constexpr ���캯����һ����˵Ӧ���ǿյġ�����ͨ��ǰ�ùؼ���constexpr�Ϳ�������һ��constexpr���캯��
//constexpr���캯�������ʼ���������ݳ�Ա����ʼֵ����ʹ��constexpr���캯����������һ���������ʽ��

class Debug
{
	constexpr Debug(bool b = true) :hw(b), io(b), other(b) {}
	constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) {}
	constexpr bool any() { return hw || io || other; }

	void set_io(bool b) { io = b; }
	void set_hw(bool b) { hw = b; }
	void set_other(bool b) { hw = b; }

private:
	bool hw;				  //Ӳ�����󣬶���IO����  ��
	bool io;				//IO����  ��
	bool other;			//��������	��



};


//7.6  ��ľ�̬��Ա

//�е�ʱ������Ҫ����һЩ��Ա���౾��ֱ����أ�����������ĸ������󱣳ֹ�����
/*
*��ľ�̬��Ա�������κζ���֮�⣬�����в������κ��뾲̬���ݳ�Ա�йص����ݡ���ˣ�ÿ��Accout���󽫰����������ݳ�Ա��owner��amout��
ֻ����һ��interestRate���������������Account������

*���Ƶģ���̬��Ա����Ҳ�����κζ������һ�����ǲ�����thisָ�롣��Ϊ�������̬��Ա��������������const�ģ���������Ҳ������static��������ʹ��thisָ�롣
��һ���Ƽ�������this����ʽʹ�ã�Ҳ�Ե��÷Ǿ�̬��Ա����ʽʹ����Ч��

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
	//static double initRate(); //kael��������û�У�double Account_02::interestRate = initRate(); �޷��������ⲿ���� "private: static double Account_02::interestRate" 
	static double initRate() { return interestRate; }  //kael�����û��double Account_02::interestRate = initRate();�� ����֣��޷��������ⲿ���� "private: static double Account_02::interestRate"
};

//ʹ����ľ�̬��Ա

void test_08() {
Account_02 ac1;
Account_02*ac2 = &ac1;
double r;
r = Account_02::rate();    //ʹ����������������ʾ�̬��Ա

r = ac1.rate();					//ͨ��Account�Ķ��������
r = ac2->rate();				//ͨ��ָ��Account�����ָ��
}

//���徲̬��Ա
//��������ⲿ���徲̬��Աʱ�������ظ�static�ؼ��֣��ùؼ���ֻ����������ڲ���������䣺
void Account_02::rate(double newrate)
{
	interestRate = newrate;
}
//Note:  ��������г�Աһ����������ָ�����ⲿ�ľ�̬��Աʱ������ָ����Ա������������static�ؼ�����ֻ���������ڲ�����������С�

/*
��Ϊ��̬���ݳ�Ա����������κ�һ�������������ǲ������ڴ�����Ķ���ʱ������ġ�����ζ�����ǲ�������Ĺ��캯����ʼ���ġ�����һ����˵�����ǲ���������ڲ�
��ʼ����̬��Ա���෴�ģ�����������ⲿ����ͳ�ʼ��ÿ����̬��Ա������������һ����һ����̬���ݳ�Աֻ�ܶ���һ�Ρ�
		������ȫ�ֱ�������̬���ݳ�Ա�������κκ���֮�⡣���һ���������壬�ͽ�һֱ�����ڳ�����������������С�
*/

//���岢��ʼ��һ����̬��Ա
double Account_02::interestRate = initRate();
/*
����������䶨������ΪinterestRate �Ķ��󣬸ö���ʱ��Account�ľ�̬��Ա��������ʱdouble����������ʼ��������������ʣ�ಿ�־Ͷ�λ�����������֮���ˡ�
��ˣ����ǿ���ֱ��ʹ��initRate������ע�⣺��ȻinitRateʱ˽�еģ�����Ҳ��������ʼ��interestRate����������Ա�Ķ���һ����interestRate�Ķ���Ҳ���Է������˽�г�Ա��

*/

/*
TIP��Ҫ��ȷ������ֻ����һ�Σ���õķ����ǰѾ�̬��Ա�Ķ��������������������Ķ������ͬһ���ļ��С�

*/


//��̬��Ա�����ڳ�ʼ��
/*
Best Practices ����ʹһ��������̬���ݳ�Ա�����ڲ�����ʼ���ˣ�ͨ�������ҲӦ��������ⲿ����һ�¸ó�Ա
*/

//��̬��Ա������ĳЩ����������ͨ��Ա����

//��̬���ݳ�Ա�����Ϳ��Ծ����������������͡����Ǿ�̬���ݳ�Ա�������ƣ�ֻ����������������ָ������ã�
class Bar 
{
private:
	static  Bar mem1;  //��ȷ����̬��Ա�����ǲ���ȫ����
	Bar*  mem2;				//��ȷ��ָ���Ա�����ǲ���ȫ����
	//Bar mem3;				//�������ݳ�Ա��������ȫ����
	/*
��Ķ��������Ҳ��������һ���ֿ���
���ӣ�

class CSys;

������������Ϊǰ������������CSys��˵��������֮��Ͷ���֮ǰ������Ϊ����ȫ���͡�
	
	*/
};
//��̬��Ա����ͨ��Ա������һ�����������ǿ���ʹ�þ�̬��Ա��ΪĬ��ʵ�Σ�
class Screen_8
{
public:
	//Bkground ��ʾһ���������Ժ���ľ�̬��Ա
	Screen_8& clear(char = bkground);

private:
	static const char bkground;
};

//��ϰ��7.56
/*
֪ʶ��1����ľ�̬��Ա���ó�Աֻ������ı����йأ�����������Ķ����йأ�����static�ؼ��ּ����������䲻���κ�ʵ��������󶨣�����������Ȼ����ʹ������������������ʾ�̬��Ա��
֪ʶ��2��static�������ڲ������ⲿ����ʱ������static.������һ��ȫ�ֱ��������ʼֵ�����ǳ������ʽ��
֪ʶ��3����̬��Ա�������κζ��������Ϳ������������������͡����Ǿ�̬��Աֻ������Ϊ�����ָ�������

*/






/*
�Ǿ�̬���ݳ�Ա������ΪĬ��ʵ�Σ���Ϊ����ֵ�������ڶ����һ���֣���ô���Ľ�����޷������ṩһ�������Ա���л�ȡ��Ա��ֵ�����ս���������
*/


/*

int main()
{
	OH_02 myoh_02; //��������OH_02��ִ�й��캯����ʼ�����Ӷ������OH(string s, int a, int b)

	system("pause");
}

*/