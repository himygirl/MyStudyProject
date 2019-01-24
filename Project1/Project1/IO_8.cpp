#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;

//8.1 IO��
/*
IO�����ͺ�ͷ�ļ�

ͷ�ļ�                   ����
iostream              istream,wistream ������ȡ����
							ostream,wostream ����д������
							iostream,wiostream��д��

fstream				ifstream,wifstream ���ļ���ȡ����
							ofstream,wofstream ���ļ�д������
							fstream��wfstream��д�ļ�

sstream				istringstream��wistringstream��string��ȡ����
							ostringstream��wostringstream��stringд������
							stringstream��wstringstream��дstring

//----------------------------------------------

Ϊ��֧��ʹ�ÿ��ַ������ԣ���׼�ⶨ����һ�����ͺͶ������ٿ�wchar_t���͵����ݡ����ַ��汾�����ͺͺ�����������һ��w��ʼ��
���磬wcin��wcout��wcerr�Ƿֱ��Ӧcin��cout��cerr�Ŀ��ַ��汾����

*/

//8.1.1   IO�����޿�����ֵ
/*
ofstream out1, out2;
out1 = out2;						//���󣺲��ܶ�������ֵ
ofstream print(ofstream);	//���󣺲��ܳ�ʼ��ofstream����
out2 = print(out2);				//���ܿ���������


���ڲ��ܿ���IO�����������Ҳ���ܽ��βλ򷵻���������Ϊ�����͡�����IO�����ĺ���ͨ�������÷�ʽ���ݺͷ�������
��дһ��IO�����ı���״̬����˴��ݺͷ��ص����ò�����const�ġ�
*/

//8.1.2 ����״̬
/*
strm::iostate			strm��һ��IO���ͣ�iostate��һ�ֻ�����ص����ͣ��ṩ�˱������״̬����������
strm::badbit			strm::badbit����ָ�����ѱ���
strm::failbit			strm::failbit����ָ��һ��IO����ʧ��
strm::eofbit			strm::eofbit����ָ�����������ļ�����
strm::goodbit		strm::goodbit����ָ����δ���ڴ���״̬����ֵ��֤Ϊ��
s.eof()					����s��eofbit��λ���򷵻�true
s.fail()					����s��failbit��badit��λ���򷵻�true
s.bad()					����s��badbit��λ���򷵻�true
s.good()				����s������Ч״̬���򷵻�ture
s.clear()				����s����������״̬��λ��������״̬����Ϊ��Ч������void
s.clear(flags)			���ݸ�����flages��־λ������s�ж�Ӧ����״̬λ��λ��flages������λstrm::iostate������void
s.setstate(flags)	���ݸ�����flags��־λ������s�ж�Ӧ����״̬λ��λ��flags������λstrm::iostate������void
s.rdstate()				������s�ĵ�ǰ����״̬������ֵ����Ϊstrm::iostate


//��ѯ����״̬

badbit��ʾϵͳ�������粻�ɻָ��Ķ�д����ͨ������£�һ��badbit����λ�������޷���ʹ���ˡ��ڷ����ɻָ������failbit����λ��
��������ȡ��ֵȴ����һ���ַ��ȴ�����������ͨ���ǿ��������ģ��������Լ���ʹ�á���������ļ�����λ�ã�eofbit��failbit���ᱻ��λ��
goodbit��ֵΪ0����ʾ��δ�����������badbit��failbit��eofbit��һ������λ��������״̬��������ʧ�ܡ�




*/

//��������״̬
//��סcin�ĵ�ǰ״̬

void testIO_01()
{
auto old_state = std::cin.rdstate();   //��סcin�ĵ�ǰ״̬

std::cin.clear();								//ʹcin��Ч   //kael �������ȫ���У���ᱨ��error C3927: "->": �Ǻ���������������β�淵������

//process_input(std::cin);					//ʹ��cin
std::cin.setstate(old_state);				//��cin��Ϊԭ��״̬

}

//8.1.3�����������
/*
//ÿ�������������һ����������������������д�����ݡ�
//���»���ˢ�£�������������д������豸���ļ�����ԭ���кࣺܶ

*����������������Ϊmain������return������һ���֣�����ˢ�±�ִ�С�
*��������ʱ����Ҫˢ�»��壬�����µ����ݲ��ܼ���д�뻺����
*���ǿ���ʹ�ò�������endl����ʾˢ�»�������
*��ÿ���������֮�����ǿ����ò�����unitbuf���������ڲ�״̬������ջ�������
	Ĭ������£���cerrʱ����unitbuf�ģ����д��cerr�����ݶ�������ˢ�µġ�
*һ����������ܱ���������һ����������������£�����д����������ʱ�������������Ļ�������ˢ�¡�
���磬Ĭ������£�cin��cerr��������cout����ˣ���cin��дcerr���ᵼ��cout�Ļ�������ˢ�¡�
*/

//ˢ�����������
/*
�����Ѿ�ʹ�ù�������endl������ɻ��в�ˢ�»������Ĺ�����IO���л����������ƵĲ�������flush��ends��
flushˢ�»���������������κζ�����ַ���ends�򻺳�������һ�����ַ���Ȼ��ˢ�»�������
*/

void testIO_02()
{
	cout << "hi!" << endl;	 //���hi��һ���У�Ȼ��ˢ�»�����
	cout << "hi!" << flush;	//���hi��Ȼ��ˢ�»��������������κζ����ַ�
	cout << "hi!" << ends;	//���hi��һ�����ַ���Ȼ��ˢ�»�����

}

//unitbuf������
/*
�������ÿ�����������ˢ�»����������ǿ���ʹ��unitbuf���ݷ������������ڽ�������ÿ��д����֮�󶼽���һ��flush������
��nounitbuf���ݷ�����������ʹ��ָ�ʹ��������ϵͳ����Ļ���ˢ�»��ƣ�
*/

void testIO_03()
{
	cout << unitbuf;			//������������󶼻�����ˢ�»�����
	//�κ����������ˢ�£��޻���
	cout << nounitbuf;		//�ص������Ļ��巽ʽ

}

//��������������
//��һ����������������һ�������ʱ���κ���ͼ����������ȡ���ݵĲ���������ˢ�¹������������
//���Ǽȿ��Խ�һ��istream�����������һ��ostream��Ҳ���Խ�һ��otream��������һ��ostream:

void TestIO_04()
{
	cin.tie(&cout);		//	����ʱ����չʾ����׼�⽫cin��cout������һ��
	//old_tieָ��ǰ������cin����������еĻ���
	ostream* old_tie = cin.tie(nullptr); //cin����������������
	//��cin��cerr�������ⲻ��һ�������⣬��ΪcinӦ�ù�����cout
	cin.tie(&cerr);			//��ȡcin��ˢ��cerr������cout
	cin.tie(old_tie);			//�ؽ�cin��cout�����������

	/*
	ÿ����ͬʱ��������һ�����������������ͬʱ������ͬһ��ostream��
	*/

}

//8.2 �ļ��������
/*
ͷ�ļ�fstream����������������֧���ļ�IO:ifstream��һ�������ļ���ȡ���ݣ�ofstream��һ�������ļ�д�����ݣ��Լ�fstream���Զ�д���ļ���

												fstream���еĲ���
fstream fstrm;			����һ��δ�󶨵��ļ�����fstream��ͷ�ļ�fstream�ж����һ������
fstream fstrm(s);		����һ��stream��������Ϊs���ļ���s������string���ͣ�������һ��ָ��C����ַ�����ָ�롣��Щ���캯������explicit�ġ�
								Ĭ�ϵ��ļ�ģʽmode������fstream������

fstream fstrm(s,mode);	��ǰһ�����캯�����ƣ�����ָ��mode���ļ�
fstrm.open(s)					����Ϊs���ļ��������ļ���fstrm�󶨡�s������һ��string��һ��ָ��C����ַ�����ָ�롣
										Ĭ�ϵ��ļ�mode������fstream�����͡�����void��
fstrm.close()						�ر���fstrm���ļ�������void
fstrm.is_open()					����һ��boolֵ��ָ����fstrm�������ļ��Ƿ�ɹ�������δ�ر�

*/
//8.2.1  ʹ���ļ�������
//֪ʶ�㣺�ļ��Ķ�������д,�����ļ�������open��close������֮��������򿪶�����дģʽ
//ofstream�Ǵ��ڴ浽Ӳ�̣�ifstream�Ǵ�Ӳ�̵��ڴ棬��ʵ��ν������������ڴ�ռ�

/*
void test_05()
{
	string infile;  //�����ļ���
	ifstream in(infile); //ifstream������һ��������in���ļ�������������ʼ�����ļ��ж�ȡ����
	if (in)		//������ؼ��Ķ�ȡ�Ƿ�ɹ������ɺ�ϰ�ߣ�
	{
		//......
	}
	else
	{
		cerr << "cannot open this file:" << infile << endl;
	}

	in.close(); //�ر��ļ�
	string mystring = infile + ".copy";
	//const char* mychar01 = mystring.data();
	 char* mychar = (char*)mystring.data();
	in.open(mychar); //�ر��ļ��󣬲ſ��Դ���һ���ļ�

	ofstream out; //ofstream �����κ��ļ�������ֻ������һ�������out���ļ�����

	if (out)
	{
	}
	else
	{
		cerr << "sorry" << endl;
	}

	out.open(mychar);
	// ��һ��fstream��������ʱ��close�������Զ�����
}
*/


void test_06()
{
	//�����ļ�������open��close������֮��������򿪶�����дģʽ
	string infile = "1.txt"; //�����ļ���
	vector<string> vec;   //����һ��vector
	
	ifstream in(infile);   //ifstream ������һ��������in���ļ�������������ʼ�����ļ��ж�ȡ����
	if (in) //����ļ��Ķ�ȡ�Ƿ�ɹ�����������ϰ��
	{
		string buf;
		while (getline(in,buf)) //ÿ�ж�������ķ���������getline
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

	

	/*�����ļ�������open��close������֮��������򿪶�����дģʽ*/
	string infile = "1.txt";//�����ļ�����ע����Ҫ���ڵ�ǰĿ¼��
	vector<string> vec;//����һ��vector
	ifstream in(infile);//ifstream������һ��������in(�ļ���)��������ʼ�����ļ��ж�ȡ����
	if (in)//����ļ��Ķ�ȡ�Ƿ�ɹ�,�������õ�ϰ�ߣ�
	{
		string buf;
		while (in >> buf)//ÿ�����ʵĶ������룬�Զ��Կո�Ϊ���
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


int main()
{

	system("pause");
	return 0;
}