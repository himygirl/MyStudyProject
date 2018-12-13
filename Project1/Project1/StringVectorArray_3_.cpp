#include<iostream>
#include<fstream>
#include<cassert>
#include<string>

using namespace std;

//1.���ж���
void readTxt01(string file)
{
	ifstream infile;                //ifstream �Ǵ�Ӳ�����ڴ档
	/*
	//string תchar�ķ�����
	const char* mychar = filePath.data();
	const char* mychar = filePath.c_str();
	
	char* p =const_cast<char*>(a.c_str());
	
	*/
	infile.open(file.data());   //���ļ����������ļ�����������

	assert(infile.is_open()); //��ʧ�ܣ������������Ϣ������ֹ��������


	string s;
	//getline ÿ�ζ���һ���У�ֱ�������ļ�ĩβ��
	while (getline(infile,s)) 
	{
		cout << s << endl;
	}

	infile.close();   //�ر��ļ�������

	system("pause");
}

//2.����ַ����루���Կո���س���
void readTest02(string file)
{

	ifstream infile;
	infile.open(file.data());   //���ļ����������ļ�����������
	assert(infile.is_open()); //��ʧ�ܣ������������Ϣ������ֹ��������

	char c;
	while (!infile.eof())
	{
		infile >> c;
		cout << c << endl;
	}

	infile.close();
	system("pause");
}

//3.����ַ����루�����ո���س���
void readTest03(string file)
{

	ifstream infile;
	infile.open(file.data());   //���ļ����������ļ�����������
	assert(infile.is_open()); //��ʧ�ܣ������������Ϣ������ֹ��������

	char c;
	infile >> noskipws;
	while (!infile.eof())
	{
		infile >> c;
		cout << c << endl;
	}

	infile.close();  //�ر��ļ�������
	system("pause");
}

void Mystring()
{

	string s8 = string(10,'c'); //������ʼ����s8��������cccccccccc
	string s2 = "Value";
	string s3("Value");

	s2.empty();

	string mystring02 = "abc";
	int aa = mystring02.size();  //���һ�����ʽ�У��Ѿ�����size()�����Ͳ�Ҫʹ��int�ˣ��������Ա������int��unsigned���ܴ��������⡣
	auto cc = mystring02.size(); //size() ���ص���size_type�������ݡ����ص���һ���޷�����������

	string mytest;
	mytest = mystring02[0];
	char mytestchar = 'ab';
	std::cout << aa << std::endl;

	system("pause");
}

//�ַ����ַ���������
void MyCharString()
{
	char mychar = 'abcd';			//���ȡ���һ���ַ����ַ���Ӧassic���

	
	const char* ptr = "HelloWorld";

	// char* ptr01 = "HellowWorld01"; //�����޷��ӡ�const char [14]��ת��Ϊ��char *��

	char ptr02[] = { 'H','E','\0' };  //���HE����������3���ֽڡ�  0�Ƕ����Ƶ�0

	char ptr03[] = "hello";   //������6���ֽ�

	std::cout <<"mychar    "<< mychar << std::endl;
	std::cout << ptr << "           " << ptr02 << "     " << ptr03 << std::endl;
	printf("%d \n", 'c');           //����������ӡ  ���99   �����99����assic�����Ӧ��ʮ������ֵ��
	printf("%c \n", 'c');           //�����ַ�����Ӧ��
	printf("%d \n", 'c' + 7);   //����������ӡ  ���106

	int a = 'c';						//���99   �����99����assic�����Ӧ��ʮ������ֵ
	std::cout << a << std::endl;


	//malloc ��Ӧfree ,    new��Ӧdelete

	system("pause");
}

	//��̬�ڴ����
void  MyAllocatedMemory()
{
	//malloc ��Ӧfree ,    new��Ӧdelete   �������������https://www.cnblogs.com/zhanjxcom/p/5766844.html

	//char* str_data = malloc(10); //�����ӡ�void*����ָ��ǡ�void����ָ���ǿ��ת��Ҫ����ʽ����ǿ��ת��
	char* str_data = (char*)malloc(10);  //malloc ���ص���void* ����������Ҫ��char*�� ����ת���� ��10����������10�ֽڵ��ڴ档��������ͷ����11���ֽڣ��ͻ���1���ֽ���
															//�ҿɹ飬��ֱ�ӡ�ס���ھӼҡ�����ɵĽ���Ǻ�����ڴ���ԭ����������ȫ������գ�kael���ʡ���ס���ھӼҡ�����˼���ڴ�й¶�𣿣�

	str_data[0] = 'H';
	str_data[1] = 'e';

	 const char* scr = "HelloWord";
	 for (size_t i = 0; i < 10; i++)
	 {
		 str_data[i] = scr[i];
	 }

	 str_data[10] = 0;   //'\10'   kael���ʣ�����һ�����˼�ǣ���������
	 printf("%s \n", str_data);

	 free(str_data);

	system("pause");
}

//�ַ����ȽϷ��ţ�==  , !=, < , <=, >, >=
void CompareString()
{
	string str = "Hello";
	string phrase001 = "HelloWorld";
	string slang = "Hiya";

	string phrase002 = "Helloworld";
	string phrase003 = "Hello world";

	/*
	�ַ���С�Ƚϵ�����ԭ��
	1.�������string����ĳ��Ȳ�ͬ�����϶�string�����ÿ���ַ�����ϳ�string�����Ӧλ���ϵ��ַ�����˵�϶�string����С�ڽϳ�����
	2.�������string������ĳЩ��Ӧ��λ���ϲ�һ�£���string����Ƚ϶�����ʵ��string�����е�һ�������ַ��ȽϵĽ����
	
	
	*/

	string str_phrase001;
	str > phrase001 ? str_phrase001 = "max:str" : str_phrase001 = "max:phrase001";   //�����max:phrase001

	string phrase001_phrase002;
	phrase001 > phrase002 ? phrase001_phrase002 = "max:phrase001" : phrase001_phrase002 = "max::phrase002";  //�����max::phrase002

	string phrase001_phrase002001;
	phrase001 == phrase002 ? phrase001_phrase002001 = "==" : phrase001_phrase002001 = "!=";  //�����!=

	string phrase002_phrase003;
	phrase003 > phrase002 ? phrase002_phrase003 = "max:phrase003" : phrase002_phrase003 = "max:phrase002"; //�����max:phrase002

	string bb = "b";
	string cc = "c";

	string bb_cc;
	bb > cc ? bb_cc = "max:bb" : bb_cc = "max:cc"; // ���:max:cc   //kael��Ϊ���ַ��ıȽϣ�������ASCII���ʮ���ƴ�С���ġ�

	std::cout << bb_cc << std::endl;

	system("pause");
}

//�ַ���������ֵ���
void StringAdd()
{
	string s1 = "hello", s2 = "world\n";
	string s3 = s1 + ',' + s2 + '\n';

	string s4 = s1 + ",";
	//string s5 = "hello" + ",";				//��������������󶼲���string
	string s6 = s1 + "," + "world";
	//string s7 = "hello" + "," + s2;		//���ܰ�����ֱֵ�����
	
	string s8 = string("hello") + string("c");					
	char b = 'b';
	char c = 'c';
	const char *test = "hello";
	//const char* p = "hello" + 'b' ;			//s8  ���orld,  ԭ����b��assic����ֵ�ǣ�98������"hello"��ַ�ƶ���98λ�ĵ�ַ��ȡ��5���ֽڣ�orld0�����һ����0��
	const char* p = "hello" + 98;				//s8  ���orld,  ԭ����b��assic����ֵ�ǣ�98������"hello"��ַ�ƶ���98λ�ĵ�ַ��ȡ��5���ֽڣ�orld0�����һ����0��			
	const char* q = "hello" + 'c';			//s8  ���rld


	std::cout <<"s3------" <<s3 << "  -----s4------" << s4 << " -------s6----- " << s6 << "------s8-----" << s8 <<"----p-----"<<p<< std::endl;
	system("pause");
}


//�ַ���תstring����
string CharToStr(char * contentChar)
{
	string tempStr;
	//��\0����һ�������ַ�������������ʾһ���ַ����Ľ���������ASCII��ֵΪ0��ע������ո�' '��ASCII��ֵΪ32����'0'��ASCII��ֵΪ48����һ���ġ�
	for (int i = 0;contentChar[i] !='\0'; i++)
	{
		tempStr += contentChar[i];

	}
	return tempStr;

}


//ɾ��ָ��������
void DelLineData(string FilePath,int lineNum)
{
	ifstream in;
	in.open(FilePath.data());

	string strFileData = "";
	int line = 1;
	char lineData[1024] = {0};
	
	//��˼·�������ַ��� �滻Ҫɾ��������Ϊ��\n��
	while (in.getline(lineData,sizeof(lineData)))  //LineData �õ�ÿ���ַ���
	{
		std::cout << lineData << std::endl;
		if (line==lineNum)   //line++ ����ȵ�ʱ�������һ�У�Ϊ��\n����
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

	ofstream out;  //ofstream�Ǵ��ڴ浽Ӳ��
	out.open(FilePath.data());

	//Flush�ǽ�������������д���ļ�������ա���������4k�����ݣ���4k�ˣ��ͻ��Զ�д���ļ��������Ļ�����Ҫflushһ�£������flush�Ļ����ļ�������п��ܻ���һЩ����
	out.flush();
	out << strFileData; //string д��out
	
	out.close();

	system("pause");
}

//���У�  �޸�.text�ļ�
void ModityFile(string filePath,int lineNum,string content)
{
	ifstream in;
	char line[1024] = {'\0'};  //[] �±������
	in.open(filePath.data());
	int i = 0;
	string tempStr;

	//��˼·�����飬�滻
	while (in.getline(line,sizeof(line)))
	{
		i++;
		if (lineNum !=i)
		{
			tempStr += CharToStr(line);
		}
		else
		{
			char* p = const_cast<char*>(content.c_str());//ͨ��const_cast�������ֻ�ܽ�const type*ת��Ϊtype*����const type&ת��Ϊtype&
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

	//����
	for (auto c : mystring)
	{
		c = 'a';
	}
	
	//����
	for (auto &c : mystring)
	{
		c = 'a';
	}

	std::cout << mystring << std::endl;
	system("pause");
}

//�ж��ַ��ķ���
void  mychar02()
{
	char c = 'c';

	isalnum(c);		//��c�������������ʱΪ��
	isalpha(c);		//��c������ʱΪ��
	iscntrl(c);		//��c�ǿ����ַ�ʱΪ��
	isdigit(c);		//��c������ʱΪ��
	isgraph(c);		//��c���ǿո񵫿��Դ�ӡʱΪ��
	islower(c);		//��c��Сд��ĸʱΪ��
	isprint(c);		//��c�ǿɴ�ӡ�ַ�ʱΪ�棨��c�ǿո����c���п�����ʽ��
	ispunct(c);		//��c�Ǳ�����ʱΪ�棨��c���ǿ����ַ������֡���ĸ���ɴ�ӡ�հ��е�һ�֣�
	isspace(c);		//��c�ǿհ�ʱΪ�棨��cʱ�ո񡢺����Ʊ���������Ʊ�����س��������з�����ֽ���е�һ�֣�
	isupper(c);		//��c�Ǵ�д��ĸʱΪ��
	isxdigit(c);    //��c��ʮ����������ʱΪ��
	tolower(c);		//���c�Ǵ�д��ĸ�������Ӧ��Сд��ĸ������ԭ�����c
	toupper(c);		//���c��Сд��ĸ�������Ӧ�Ĵ�д��ĸ������ԭ�����c




}

//ʮ����ת��Ϊʮ������
void Change10to15()
{
	const string hexdigits = "0123456789ABCDEF";

	string result;
	string::size_type n;
	while (cin>>n)
	{
		if (n<hexdigits.size())
		{
			result += hexdigits[n]; //���С��15�����滻��Ӧ���ַ�
		}
	}

	std::cout << "Your hex number is:" << result << std::endl;

	//string s;
	//std::cout << s[0] << std::endl; //���Ϸ�����ΪsΪ�գ���Ȼ����ͨ���������Ϸ���

	/*
	const string s = "keep out!";
	for(auto &c:s)//�Ϸ�����c��   const char& ������ı�����ֵ��
	{
	//......
	}
	
	
	
	*/

	system("pause");
}

//��׼������vector,     vector ��һ����ģ�塣
#include<vector>

void Myvecto() {

	//vector�����ɾ���������͵Ķ�����Ϊ��Ԫ�أ�������Ϊ���ò��Ƕ������Բ����ڰ������õ�vector��
vector <int> iec;							 //ivec ����int���͵Ķ���
vector <vector<string>> file;		//��������Ԫ����vector����

/*
��ʼ��vector����ķ���
vector<T> v1                          v1��һ����vector����Ǳ�ڵ�Ԫ����T���͵ģ�ִ��Ĭ�ϳ�ʼ��
vector<T> v2(v1)						v2�а�����v1����Ԫ�صĸ���
vector<T> v2= v1					�ȼ���v2��v1����v2�а�����v1����Ԫ�صĸ���
vector<T>v3(n,val)					v3������n���ظ���Ԫ�أ�ÿ��Ԫ�ص�ֵ����val
vector<T>v4(n)						v4������n���ظ���ִ����ֵ��ʼ���Ķ���
vector<T>v5{a,b,c,.....}				v5�����˳�ʼֵ������Ԫ�أ�ÿ��Ԫ�ر�������Ӧ�ĳ�ʼ����
vector<T>v5 ={a,b,c....}

*/

vector<int> ivec;                  //��ʼ��״̬Ϊ��
//�ڴ˴���ivec3 ���һЩֵ
vector<int> ivec2(ivec);       //��ivec��Ԫ�ؿ�����ivec2
vector<int> ivec3 = ivec;     //��ivec��Ԫ�ؿ�����ivec3
//vector<string> svec(ivec2)  //����svec��Ԫ����string���󣬲���int

vector<string> articles = { "a","an","the" };
vector<string> v1_01{ "a","an","the" };//�б��ʼ��

//����ṩ���ǳ�ʼԪ�ص��б���ֻ�ܰѳ�ʼ�������ڻ�����������б��ʼ���������ܷ���Բ�����
//vector<string> v2("a", "an", "the"); //����


//����ָ��������Ԫ��
vector<int> ivec02(10, -1);				 //10��int���͵�Ԫ�أ�ÿ��������ʼ��Ϊ-1
vector<string> svec02(10, "hi!");	//10��string���͵�Ԫ�أ�ÿ��������ʼ��Ϊ��hi����

vector<int> ivec03(10);					//10��Ԫ�أ�ÿ������ʼ��Ϊ0
vector<string> svec04(10);				//10��Ԫ�أ�ÿ�����ǿ�string����

//���ֻ�ṩ��Ԫ�ص�������û���趨��ʼֵ��ֻ��ʹ��ֱ�ӳ�ʼ����
//vector<int> vi = 10;                   //���󣺱���ʹ��ֱ�ӳ�ʼ������ʽָ��������С��

//�б��ʼֵ����Ԫ��������
//ĳЩ����£���ʼ������ʵ���������ڴ��ݳ�ʼֵʱ�õ��ǻ����Ż���Բ���š�
vector<int> v1(10);			//v1��101��Ԫ�أ�ÿ����ֵ����0
vector<int>v2{ 10 };		//v2��1��Ԫ�أ���Ԫ�ص�ֵ��10

vector<int> v3(10, 1);		//v3��10��Ԫ�أ�ÿ����ֵ����1
vector<int> v4{ 10,1 };		//v4��2��Ԫ�أ�ֵ�ֱ���10��1

vector<string> v5{ "hi" };   //�б��ʼ����v5��һ��Ԫ��
//vector<string> v6("hi");		//���󣺲���ʹ���ַ�������ֵ����vector����

//�����ʼ��ʱʹ���˻����ŵ���ʽ�������ṩ��ֵ�в��������б��ʼ������Ҫ������������ֵ������vector�����ˡ�
vector<string> v7{ 10 };			//v7  ��10��Ĭ�ϳ�ʼ����Ԫ��
vector<string>v8{ 10,"hi" };    //v8��10��ֵΪ��hi�� ��Ԫ��

}

//��vector���������Ԫ��
//�Ƽ�����һ���յĵ�vector��Ȼ����ӡ���������Ԫ�ص�ֵ��һ����
void VectorAdd()
{
	vector<int> v2;			//��vector����
	for (int i = 0; i != 10; ++i)
		v2.push_back(i);		//���ΰ�����ֵ����v2β��   //push_back�����һ��ֵ����vector�����βԪ�ء�ѹ����push���� vector����ġ�β�ˣ�back������


	string word;
	vector<string> text;         //��vector����
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
//vector ֧�ֵĲ���

v.empty()		              //���v�������κ�Ԫ�أ������棺���򷵻ؼ�
v.size()						//����v��Ԫ�صĸ���
v.pushe_back(t)		//��v��β�����һ��ֵΪt��Ԫ��
v[n]							//����v�е�n��λ���ϡ�Ԫ�ص����á�
v1=v2						//��v2��Ԫ�صĿ����滻v1�е�Ԫ��
v1={a,b,c.....}				//���б���Ԫ�صĿ����滻v1�е�Ԫ��
v1 == v2					//v1��v2��ȵ��ҽ������ǵ�Ԫ��������ͬ�Ҷ�Ӧλ�õ�Ԫ��ֵ����ͬ
v1!=v2
 
 <,<=,>,>=				����˼�壬���ֵ�˳����бȽϡ�

*/

//�����ֶ�
//��10��Ϊһ��������ͳ�Ƴɼ���������0~9,10~19,....,90~99,100
void FractionSegmentation()
{
	vector<unsigned> scores(11, 0);  //11�������Σ�ȫ����ʼ����0

	unsigned grade;
	while (cin>>grade)                       //��ȡ�ɼ�
	{
		if (grade<=100)						//ֻ������Ч�ĳɼ�
		{
			++scores[grade / 10];			//����Ӧ�����εļ���ֵ��1
		}
	}

	for (auto c : scores)
	{
		std::cout << c << std::endl;
	}
	system("pause");
}

//�������±���ʽ���Ԫ��
//vector�����Լ�string���󣩵��±�����������ڷ����Ѵ��ڵ�Ԫ�أ��������������Ԫ�ء�
void myvector03()
{
	vector<int> ivec; //��vector����

	for (decltype(ivec.size()) ix = 0; ix != 10; ++ix) {
	
	//			ivec[ix] = ix;//���ش���ivec����������Ԫ��
		ivec.push_back(ix);  //��ȷ�����һ����Ԫ�أ���Ԫ�ص�ֵʱix��
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

	//�������Ϊ�գ���begin��end���ص���ͬһ��������������β���������
	auto a = myvector.begin(), b = myvector.end();    //a��b��������ͬ����Ϊ iterator����������
	if (a==b)
	{

	}

	system("pause");

	/*
	*iter ���ص�����iter��ָԪ�ص�����
	iter->mem			  ������iter����ȡ��Ԫ�ص���Ϊmem�ĳ�Ա���ȼ��ڣ�*iter��.mem
	++iter					  ��iterָʾ�����е���һ��Ԫ��
	--iter					  ��iterָʾ�����е���һ��Ԫ��
	iter1 ==iter2			�ж������������Ƿ���ȣ�����ȣ����������������ָʾ����ͬһ��ԭʼ����
	iter1 ��= iter2		 ������ͬһ��������β�������������ȣ���֮������ȡ�



	*/

}


int main()
{

	//Mystring();
	
	//readTxt01("H:/����Ⱦ�ӿ�.txt");   //ע��б��
	//readTest02("H:/����Ⱦ�ӿ�.txt");
	//readTest03("H:/����Ⱦ�ӿ�.txt");

	//MyCharString();
	//MyAllocatedMemory();
	//CompareString();
	//StringAdd();
	//DelLineData("H:/����Ⱦ�ӿ�.txt",1);
	//ModityFile("H:/����Ⱦ�ӿ�.txt",1,"hello world");
	//Mystring02();
	//Change10to15();
	//VectorAdd02();
	//FractionSegmentation();
	myvector04();
	return 0;
}