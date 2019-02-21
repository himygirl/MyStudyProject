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


//һ����������һЩ�ض����Ͷ���ļ���
//9.1 ˳����������
/*
							˳����������
vector				�ɱ��С���顣֧�ֿ���������ʡ���β��֮���λ�ò����ɾ��Ԫ�ؿ��ܺ���
deque				˫�˶��С�֧�ֿ���������ʡ���ͷβλ�ò���/ɾ���ٶȺܿ�
list					˫������ֻ֧��˫��˳����ʡ���list���κ�λ�ý��в���/ɾ�������ٶȶ��ܿ�
forward_list		��������ֻ֧�ֵ���˳����ʡ��������κ�λ�ý��в���/ɾ��������궼�ܿ�
array				�̶���С���顣֧�ֿ���������ʡ�������ӻ�ɾ��Ԫ��
string				��vector���Ƶ���������ר�����ڱ����ַ���������ʿ졣��β������/ɾ���ٶȿ�


list��forward_list�������������Ŀ�����������κ�λ�õ���Ӻ�ɾ���������ܿ��١���Ϊ���ۣ�������������֧��Ԫ�ص�������ʣ�Ϊ�˷���һ��Ԫ�أ�����ֻ��
�����������������ң���vector��deque��array��ȣ������������Ķ����ڴ濪��Ҳ�ܴ�
deque��һ����Ϊ���ӵ����ݽṹ����string��vector���ƣ�deque֧�ֿ��ٵ�������ʡ���string��vectorһ������deque���м�λ����ӻ�ɾ��Ԫ�صĴ��ۣ����ܣ�
�ܸߡ����ǣ���deque��������ӻ�ɾ��Ԫ�ض��Ǻܿ�ģ���list��forward_list���ɾ��Ԫ�ص��ٶ��൱��

//������һЩѡ�������Ļ���ԭ��

*�������кܺõ�����ѡ����������������Ӧʹ��vector��
*�����ĳ����кܶ�С��Ԫ�أ��ҿռ�Ķ��⿪������Ҫ����Ҫʹ��list��forward_list
*�������Ҫ������������Ԫ�أ�Ӧʹ��vector��deque
*�������Ҫ�����������м�����ɾ��Ԫ�أ�Ӧʹ��list��forward_list
*���������Ҫ��ͷβλ�ò����ɾ��Ԫ�أ����������м�λ�ý��в����ɾ����������ʹ��deque��
*�������ֻ���ڶ�ȡ����ʱ����Ҫ�������м�λ�ò���Ԫ�أ������Ҫ�������Ԫ�أ���
---���ȣ�ȷ���Ƿ������Ҫ�������м�λ�����λ�á���������������ʱ��ͨ�����Ժ����׵���vector׷�����ݣ�
Ȼ���ڵ��ñ�׼���sort���������������е�Ԫ�أ��Ӷ��������м�λ�����Ԫ�ء�
---����������м�λ�ò���Ԫ�أ�����������׶�ʹ��list��һ��������ɣ���list�е����ݿ�����һ��vector�С�


Best Practices��
	����㲻ȷ��Ӧ��ʹ��������������ô�����ڳ�����ֻʹ��vector��list�����Ĳ�����ʹ�õ���������ʹ���±����������������ʡ�
	�������ڱ�Ҫʱѡ��ʹ��vector��list���ܷ���

	��ϰ��9.1 ����ϰ
֪ʶ��1������˳���������ص�

vector���ɱ��С��֧�ֿ���������ʣ�β���������ݺܿ�

deque��˫�˶��С�֧�ֿ���������ʣ�ͷ���������ݺܿ�

list��˫������֧��˫��˳����ʣ������κ�λ�ò���ɾ�����ݶ��ܿ�

array���̶���С���飬���ܸı��С��(ע����������ͨ���������������ǲ�һ����)

string����vector���ƣ�ר���ڱ����ַ���

֪ʶ��2����ͨ������£�ʹ��vector�Ƿǳ��õ�ѡ�����°汾�ı�׼�������Ⱦɰ汾��ܶࡣC++����Ӧ��ʹ�ñ�׼��������������ԭʼ�����ݽṹ�磺�������顣



(a)list����Ϊ������Ҫ���������м�λ�ò���Ԫ��

(b)deque����Ϊ��Ҫ��ͷ������Ԫ�ص�ɾ����dequeЧ�ʸ���

(c)vector���޾����ɾ�����������δ֪������vector�Ǹ������ѡ��


*/

/*
													��9.2����������
�������
iterator							���������͵ĵ���������
const_iterator				���Զ�ȡԪ�أ��������޸�Ԫ�صĵ���������
size_type						�޷����������ͣ��㹻��������������������������Ĵ�С
difference_type			�������������ͣ��㹻��������������֮��ľ���
value_type					Ԫ������
reference						Ԫ�ص���ֵ���ͣ���value_type&������ͬ
const_reference			Ԫ�ص�const��ֵ����

���캯��
C c��				 Ĭ�Ϲ��캯���������������array��
C c1(c2);			 ����c2�Ŀ���c1
C c(b,e);			����c����������b��eָ���ķ�Χ�ڵ�Ԫ�ؿ�����c��array��֧�֣�
C c(a,b,c......)		�б��ʼ��c

��ֵ��swap
c1 = c2				 ��c1�е�Ԫ���滻Ϊc2��Ԫ��
c1 = {a,b,c.....}	��c1�е�Ԫ���滻Ϊ�б���Ԫ��(��������array)
a.swap(b)			����a��b��Ԫ��
swap(a,b)			��a.swap(b)��Ԫ��

��С
c.size()				c��Ԫ�ص���Ŀ(��֧��forward_list)
c.max_size()		c�ɱ�������Ԫ����Ŀ
c.empty()			��c�д�����Ԫ�أ�����false�����򷵻�true

���/ɾ��Ԫ��(��������array)
ע���ڲ�ͬ�����У���Щ��������ͬ
c.insert(args)			��args�е�Ԫ�ؿ�����c
c.emplace(inits)		ʹ��inits����c�е�һ��Ԫ��
c.erase(args)			ɾ��argsָ����Ԫ��
c.clear()					ɾ��c�е�����Ԫ�أ�����void

��ϵ�����
==��!=						����������֧����ȣ����ȣ������
<,<=,>,>=				��ϵ��������������������֧�֣�

��ȡ������
c.begin(), c.end()				����ָ��c����Ԫ�غ�βԪ��֮��λ�õĵ�����
c.cbegin(),c.cengd()			����const_iterator

���������Ķ����Ա(��֧��forward_list)
revere_iterator							������Ѱַ�ĵ�����
const_reverse_iterator				�����޸�Ԫ�ص����������
c.rbegin(),c.rend()					����ָ��c��βԪ�غ���Ԫ��֮ǰλ�õĵ�����
c.crbegin(),c.crend()					����const_reverse_iterator
*/

//��������Χ
/*
һ����������Χ��һ�Ե�������ʾ�������������ֱ�ָ��ͬһ�������е�Ԫ�ػ�����βԪ��֮���λ�á�������������ͨ������Ϊbegin��end��
������first��last(������Щ��)�����Ǳ����������Ԫ�ص�һ����Χ��
		����Ԫ�ط�Χ����Ϊ��պ����䣬���׼��ѧ����Ϊ
		[begin,end)
��ʾ��Χ��begin��ʼ����end֮ǰ������������begin��end����ָ����ͬ��������end������beginָ����ͬ��λ�ã�������ָ��begin֮ǰ��λ�á�


*/

//��ϰ9.3
/*
֪ʶ��1���������£�

������ָ��ͬһ�������������һ��Ԫ��֮���λ��

���Է�������beginֱ��end

֪ʶ��2��������ָ���Ԫ�ط�Χ����պ����䣬ע��endָ��������һ��Ԫ��֮���λ��
*/

//��ϰ9.4,��д����������һ��ָ��vector<int>�ĵ�������һ��intֵ��������������ָ���ķ�Χ�в��Ҹ�����ֵ������һ������ֵ��ָ���Ƿ��ҵ�

bool find1(vector<int>::iterator a, vector<int>::iterator b, int c)//������������ҪŪ���
{
	for (a; a != b; a++)
	{
		if (*a == c)//����������н����ò���
		{
			return true;
		}
	}
	return false;
}

void Test()
{

	vector<int> vec(20);//��������ָ�������С����֪��end��ָ��
	vec[0] = 4;
	vec[1] = 5;
	vec[2] = 2;
	vec[3] = 8;
	vec[4] = 9;
	vec[5] = 6;
	vec[6] = 7;//ʹ��VS1010����֧���б��ʼ��������
	int find_member = 1;
	if (find1(vec.begin(), vec.end(), find_member))
	{
		cout << "We have found it" << endl;
	}
	else
		cout << "Sorry,there is no " << find_member << " in the range" << endl;

}

//��ϰ9.4����д��һ��ĺ���������һ��������ָ���ҵ���Ԫ�ء�ע�⣬������봦��δ�ҵ�����ֵ�������

vector<int>::iterator find2(vector<int>::iterator a, vector<int>::iterator b, int c)//������������ҪŪ���
{
	for (a; a != b; a++)
	{
		if (*a == c)//����������н����ò���
		{
			return a;
		}
	}
	return b;//δ�ҵ���������������һ��������
}

void Test02()
{
	vector<int> vec(20);//��������ָ�������С����֪��end��ָ��
	vec[0] = 4;
	vec[1] = 5;
	vec[2] = 2;
	vec[3] = 8;
	vec[4] = 9;
	vec[5] = 6;
	vec[6] = 7;//ʹ��VS1010����֧���б��ʼ��������
	int find_member = 1;
	if (find2(vec.begin(), vec.end(), find_member) != vec.end())
	{
		cout << "We have found it" << endl;
	}
	else
		cout << "Sorry,there is no " << find_member << " in the range" << endl;
}


//��ϰ9.6
/*
��������кδ�����Ӧ������޸�����

list<int>	lst1;
list<int>::iterator iter1 = lst1.begin(), iter2 = lst1.end();

while(iter1<iter2){}

��
������֮���޴���С�ںŵıȽ�
��������������ͬһ�����ڲ���ֱ�ӱȽϣ���������kael���ʣ�����ͬһ����������
while(*iter1<*iter2){}

*/

//��ϰ9.7
//Ϊ������ int ��vector�е�Ԫ�أ�Ӧ��ʹ��ʲô���ͣ�
//vector<int>::size_type   //size_typeָ�����޷�����������

//��ϰ9.8��
//Ϊ�˶�ȡstring��list�е�Ԫ�أ�Ӧ��ʹ��ʲô���ͣ����д��list���ָ�ʹ��ʲô���ͣ�
//֪ʶ�㣺����д�Ĳ�ͬ�����Ҫд�򷵻صı�Ȼ������const iterator
/*
list<string>::iterator || list<string>::const_iterator  //������
list<string>::iterator //д����
*/

//9.2.3 begin �� end ��Ա
/*
����c��ͷ�ĺ������Ǳ����ع��ġ�Ҳ����˵��ʵ������������Ϊbegin�ĳ�Ա��һ����const��Ա������������const_iterator���͡���һ���Ƿǳ�����Ա��
����������iterator���͡�rbegin��end��rend��������ơ������Ƕ�һ���ǳ������������Щ��Աʱ���õ����Ƿ���iterator�İ汾��
ֻ���ڶ�һ��const���������Щ����ʱ���Ż�õ�һ��const�汾����constָ����������ƣ����Խ�һ����ͨ��iteratorת��Ϊ��Ӧ��const_iterator,��֮���С�

*/
void Test03()
{
	list<string> a = { "Milton","Shakespeare","Austen" };
	auto it1 = a.begin(); //list<string>::iterator
	auto it2 = a.rbegin(); //list<string>::reverse_iterator
	auto it3 = a.cbegin(); //list<string>::const_iterator
	auto it4 = a.crbegin(); // list<string>::const_reverse_iterator

//��ʽָ������
	list<string>::iterator  it5 = a.begin();
	list<string>::const_iterator it6 = a.begin();
	//��iterator����cosnt_iterator������a������
	auto it7 = a.begin();  //����a��constʱ��it7��const_iterator
	auto it8 = a.cbegin(); //it8��cosnt_iterator

	/*
	��auto��begin��end���ʹ��ʱ����õĵ����������������������ͣ���������Ҫ���ʹ�õ�����������ɡ�
	����c��ͷ�İ汾���ǿ��Ի��const_iterator�ģ�����������������ʱʲô��
	*/
}
//Best Pratices   �� ������Ҫ����ʱ��Ӧʹ��cbegin��cend��

//��ϰ9.10
//����4������ֱ�ʱʲô����
void Test04()
{
	vector<int> v1;						
	const vector<int> v2;		

	//auto it1 = v1.begin(),it2 = v2.begin(); // error C3538: ���������б��У���auto������ʼ���Ƶ�Ϊͬһ����
	auto it1 = v1.begin();	//vector<int>::iterator
	auto it2 = v2.begin();		//const vector<int>::iterator
	auto it3 = v1.cbegin();		//vector<int>::const_iterator
	auto it4 = v2.cbegin();		//const vector<int>::cosnt_iterator
}

//��������ͳ�ʼ��
/*
ÿ���������Ͷ�������һ��Ĭ�Ϲ��캯������array֮�⣬����������Ĭ�Ϲ��캯�����ᴴ��һ��ָ�����͵Ŀ��������Ҷ����Խ���ָ��������С��Ԫ�س�ʼֵ�Ĳ���


																	��������ͳ�ʼ��
C c�� Ĭ�Ϲ��캯�������C��һ��array����c��Ԫ�ذ�Ĭ�Ϸ�ʽ��ʼ��������cΪ��

C c1(c2)   c1��ʼ��Ϊc2�Ŀ�����c1��c2��������ͬ����(�������Ǳ�������ͬ���������ͣ��ұ��������ͬ��Ԫ�����ͣ�����array���ͣ����߻����������ͬ��С)
C c1 = c2				

C c{a,b,c...}	c��ʼ��Ϊ��ʼ���б���Ԫ�صĿ������б���Ԫ�ص����ͱ�����C��Ԫ���������ݡ�����array���ͣ��б���Ԫ����Ŀ������ڻ�С��array�Ĵ�С��
C c={a,b,c...}					�κ���©��Ԫ�ض�����ֵ��ʼ��

C c(b,e)		c��ʼ��Ϊ������b��eָ����Χ�е�Ԫ�صĿ�������Χ��Ԫ�ص����ͱ�����C��Ԫ����������(array������)

ֻ��˳������(������array)�Ĺ��캯�����ܽ��ܴ�С����
C seq(n)		seq ����n��Ԫ�أ���ЩԪ�ؽ�����ֵ��ʼ�����˹��캯����explicit�ġ�(string ������)
C seq(n,t)		seq����n����ʼ��Ϊֵt��Ԫ��
*/

void Test05()
{
	list<string> authors = { "Milton","Shakespeare","Austen" };
	vector<const char*> articles = { "a", "an","the" };

	list<string> list2(authors); //��ȷ������ƥ��
	//deque<string> authList(authors); //�����������Ͳ�ƥ��
	//vector<string> words(authors);  //�����������Ͳ�ƥ��
	//��ȷ�����Խ�const char* Ԫ��ת��Ϊstring
	forward_list<string> words(articles.begin(), articles.end());

}

//Note��ֻ��˳�������Ĺ��캯���Ž��ܴ�С������������������֧��

//ֵ��ע����ǣ���Ȼ���ǲ��ܶ������������;�ϲ���������ֵ��������array���޴�����:
void Test06()
{
	int digs[10] = {0,1,2,3,4,5,6,7,8,9}; 
	//int cpy[10] = digs;    //�����������鲻֧�ֿ�����ֵ
	array<int,10> digits = { 0,1,2,3,4,5,6,7,8,9};
	array<int, 10> copy = digits;   //��ȷ��ֻҪ����ƥ�伴�Ϸ�

}

//��ϰ9.11
//��6�ִ����ͳ�ʼ��vector����ķ�����ÿһ�ֶ�����һ��ʵ��������ÿ��vector����ʲôֵ
void Test07()
{
//ע��C++11�±�׼��vector��ʼ���ķ���(����array����ı�׼������������)
/*
	vector<int> vec;
	vector<int> vec(10);
	vector<int> vec(10, 1);
	vector<int> vec{ 1,2,3,4,5 };
	vector<int> vec(other_vec);
	vector<int> vec(other_vec.begin(), other_vec.end());
*/
}

//��ϰ9.13
void Test08()
{
	//����ʹ�õ�list��vector
	list<int> list1(7, 8);
	vector<int> vec2(5, 2);

	//������Ŀ������
	vector<double> vec1(list1.begin(), list1.end());
	vector<double> vec3(vec2.begin(), vec2.end());

	//��֤��ȷ��
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
// ��ֵ��swap

//���������鲻ͬ����׼��array��������ֵ����ֵ���������ߵ����������������ͬ�����ͣ�
void Test10()
{
array<int, 10> a1 = { 0,1,2,3,4,5,6,7,8,9 }; 
array<int, 10> a2 = { 0 };  //����Ԫ��ֵ��Ϊ 0
a1 = a2;  //�滻a1�е�Ԫ��
//a2 = { 0 };   //���󣺲��ܽ�һ���������б�������

//�����ұ��������Ĵ�С����������������Ĵ�С��ͬ�����array���Ͳ�֧��assign��Ҳ�������û����Ű�Χ��ֵ�б�ֵ
}

/*
												������ֵ����
c1= c2           ��c1�е�Ԫ���滻Ϊc2�е�Ԫ�صĿ�����c1��c2���������ͬ������
c={a,b,c.....}	��c1��Ԫ���滻Ϊ��ʼ���б���Ԫ�Ŀ�����array�����ã�

swap(c1,c2)	����c1��c2�е�Ԫ�ء�c1��c2���������ͬ�����͡�swapͨ���ȴ�c2��c1����Ԫ�ؿ�Ķ�
c1.swap(c2)


assign�����������ڹ���������array
seq.assign(b,e)  ��seq�е�Ԫ���滻Ϊ������b��e ����ʾ�ķ�Χ�е�Ԫ�ء�������b��e����ָ��seq�е�Ԫ��
seq.assign(il)	 ��seq�е�Ԫ���滻Ϊ��ʼ���б�il�е�Ԫ��
seq.assign(n,t)  ��seq�е�Ԫ���滻Ϊn��ֵΪt��Ԫ��

Warning   ��ֵ�������ᵼ��ָ����������ڲ��ĵ����������ú�ָ��ʧЧ����swap�������������ݽ������ᵼ��
ָ�������ĵ����������ú�ָ��ʧЧ����������Ϊarray��string��������⣩

*/

//ʹ��assign����˳�������� //kael��assign ��ֵ����

void Test11()
{
	list<string> names;
	vector<const char*> oldstyle;
	//names = oldstyle; //�����������Ͳ�ƥ��

	//��ȷ�����Խ�const char*ת��Ϊstring
	names.assign(oldstyle.cbegin(), oldstyle.cend());

//warning   �������Ԫ�ر��滻����˴��ݸ�assign�ĵ���������ָ����õ�assign����������������

	//assign�ĵڶ����汾����һ������ֵ��һ��Ԫ��ֵ������ָ����Ŀ������ͬ����ֵ��Ԫ���滻������ԭ�е�Ԫ�أ�

	//�ȼ�slist1.clear��
	//���slist1.insert��slist1.begin(),10,"Hiya!"��;
	list<string> slist1(1); //1��Ԫ�أ�Ϊ��string
	slist1.assign(10, "Hiya!"); //10��Ԫ�أ�ÿ������"Hiya��"

}

//ʹ��swap
//swap��������������ͬ�������������ݣ�����swap֮�����������е�Ԫ�ؽ��ύ����

void Test12()
{
	vector <string> svec1(10); //10��Ԫ�ص�vector
	vector<string> svec2(24); //24��Ԫ�ص�vector
	swap(svec1, svec2);
	/*
	����swap��svec1������24��stringԪ�أ�svec2������10��string��
	��array�⣬���������������ݵĲ�����֤��ܿ�----Ԫ�ر���δ������swapֻ�ǽ����������������ڲ����ݽṹ��
	*/

	//Note   ��array�⣬swap�����κ�Ԫ�ؽ��п�����ɾ��������������˿��Ա�֤�ڳ���ʱ�������

}

//��ϵ�����

void Test13()
{
	vector<int> v1 = { 1,3,5,7,9,12 };
	vector<int>v2 = { 1,3,9 };
	vector<int>v3 = { 1,3,5,7 };
	vector<int>v4 = { 1,3,5,7,9,12 };

	v1 < v2;   //Ture; v1��v2��Ԫ��[2]����ͬ��v1[2]С�ڵ���V2[2]
	v1 < v3;  //false; ����Ԫ�ض���ȣ���v3��Ԫ����Ŀ����
	v1 == v4; //true; ÿ��Ԫ�ض���ȣ���v1 ��v4��С��ͬ
//	v1 == v2�� //false�� v2Ԫ����Ŀ��v1��

}

//˳����������
//˳�������͹��������Ĳ���֮������������֯Ԫ�صķ�ʽ

//��˳���������Ԫ��
/*
										��˳���������Ԫ�صĲ���
��Щ������ı������Ĵ�С��array��֧����Щ����

forward_list ���Լ�ר�а汾��insert��emplace��
forward_list ��֧��push_back��emplace_back.
vector��string ��֧��push_fornt ��emplace_front.

c.push_back(t)			��c��β������һ��ֵΪt����args������Ԫ�أ�����void
c.emplace_back(args)

c.push_front(t)			��c��ͷ������һ��ֵΪt����args������Ԫ�أ�����void
c.emplace_front(args)

c.insert(p,t)				�ڵ�����pָ���Ԫ��֮ǰ����һ��ֵΪt����args������Ԫ�ء�����ָ������ӵ�Ԫ�صĵ�����
c.emplace(p,args)

c.insert(p,n,t)			�ڵ�����pָ���Ԫ��֮ǰ����n��ֵΪt��Ԫ�ء�����ָ������ӵĵ�һ��Ԫ�صĵ���������nΪ0���򷵻�p

c.insert(p,b,e)			��������b��eָ���ķ�Χ�ڵ�Ԫ�ز��뵽������pָ���Ԫ��֮ǰ��b��e����ָ��c�е�Ԫ�ء�����ָ������ӵĵ�һ��Ԫ�صĵ�������
								����ΧΪ�գ��򷵻�p


c.insert(p,il)				il��һ�������Ű�Χ��Ԫ��ֵ�б�����Щ����ֵ���뵽������pָ���Ԫ��֮ǰ������ָ������ӵĵ�һ��Ԫ�صĵ�������
								���б�Ϊ�գ��򷵻�p

Warning   ��һ��vector��string��deque ����Ԫ�ػ�ʹ����ָ�������ĵ����������ú�ָ��ʧЧ

*/

void Test14()
{
	vector<string> svec;
	list<string> slist;

	//�ȼ��ڵ���slist.push_front("Hello!");
	slist.insert(slist.begin(), "Hello!");

	//vector��֧��push_front,�����ǿ��Բ��뵽begin()֮ǰ
	//���棺���뵽vectorĩβ֮����κ�λ�ö����ܺ���
	svec.insert(svec.begin(), "Hello!");

	//��10��Ԫ�ز��뵽svec��ĩβ����������Ԫ�ض���ʼ��Ϊstring��Anna��
	svec.insert(svec.end(), 10, "Anna");

	vector<string> v = { "quasi","simba","frollo","scar" };

	//��v���������Ԫ����ӵ�slist�Ŀ�ʼλ��
	slist.insert(slist.begin(), v.end() - 2, v.end());
	slist.insert(slist.end(), { "these","Words","well","go","at","the","end" });


	//����ʱ���󣺵�������ʾҪ�����ķ�Χ������ָ����Ŀ��λ����ͬ������
	//slist.insert(slist.begin(), slist.begin(), slist.end());


}

//ʹ��insert�ķ���ֵ

void Test15()
{
	list<string> lst;
	auto iter = lst.begin();
	string wold = "a";
	while (cin>>wold)
	{
		iter = lst.insert(iter, wold);
	}
	//Note:������ѭ��ʽ��ι����ķǳ���Ҫ���ر�ʽ������ѭ��Ϊʲô�ȼ��ڵ���push_front��Ϊ��Ҫ
}

//ʹ��emplace����
/*
�±�׼�������������³�Ա---emplace_front��emplace��emplace_back,��Щ������������ǿ���Ԫ�ء���Щ�����ֱ��Ӧpush_front��insert��push_back,
�������ǽ�Ԫ�ط���������ͷ����һ��ָ��λ��֮ǰ������β����


//�ٶ�c����Sales_dataԪ��

//��c��ĩβ����һ��Sales_data����
//ʹ������������Sales_data���캯��
c.emplace_back("978-0590353403",25,15.99);

//����û�н�������������push_back�汾
c.push_back("978-0590353403",25,15.99);

//��ȷ������һ����ʱ��Sales_data���󴫵ݸ�push_back
c.push_back(Sales_data("978-0590353403",25,15.99))



emplace�����Ĳ�������Ԫ�����Ͷ��仯������������Ԫ�����͵Ĺ��캯����ƥ�䣺
//iterָ��c��һ��Ԫ�أ����б�����Sales_dataԪ��
c.emplace_back(); //ʹ��Sales_data��Ĭ�Ϲ��캯��
c.emplace(iter,"999-9999999");  //ʹ��Sales_data(string)

//ʹ��Sales_data�Ľ���һ��ISBN��һ��count��һ��price�Ĺ��캯��
c.emplace_front("978-0590353403",25,15.99);

Note: emplace ������������ֱ�ӹ���Ԫ�ء����ݸ�emplace�����Ĳο�������Ԫ�����͵Ĺ��캯����ƥ��
*/

//��ϰ9.18
/*
֪ʶ�㣺���׼���������Ԫ�صķ�����

1��push_back()

2��push_font()

3��emplace()

4��insert()

*/
void Test16()
{
	deque<string> deque1;
	string buf;
	while (cin >> buf)
	{
		deque1.push_back(buf);//���׼���������Ԫ��
	}
	deque<string>::iterator it1 = deque1.begin();
	for (it1; it1 != deque1.end(); it1++)
	{
		cout << *it1 << endl;
	}

}

//��ϰ9.19
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

//��ϰ9.20
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
	cout << "ż��Ϊ��";
	for (it2; it2 != deque1.end(); it2++)
	{
		cout << *it2 << " ";
	}
	cout << endl;
	cout << "����Ϊ��";
	for (it3; it3 != deque2.end(); it3++)
	{
		cout << *it3 << " ";
	}

}

//��ϰ9.22

void Tes19()
{
	/*
	֪ʶ��1�����������Ϲ̶�������ָ���ǵ���������������������ֵ���������˴�����iv.size()/2����ȷ�ġ�

��Ŀ����˼Ӧ�����ж�ǰ�벿�ֵ�Ԫ��������ĳֵ��ȵ�Ԫ�أ�����������ǰ����һ��������ĳֵ��

insert()�����з���ֵ������Ϊ����ѭ�����Ҳ���Ԫ�غ�mid��Ϊһ�����û�ʧЧ

	*/

	vector <int> iv;
	iv.reserve(25);// ΪvectorԤ���ռ䣬�ں���Ľ��п��Կ���
	int some_val = 10; //kael����add

	vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size() / 2;
	while (iter != mid)
		if (*mid == some_val)
			mid = iv.insert(mid, 2 * some_val);
		else
			--mid;



}


//����Ԫ��

void Test20()
{
	array<int, 10> c = { 0,1,2,3,4,5,6,7,8,9 };
	//�ڽ�����һ�������������front��back֮ǰ����Ƿ���Ԫ��
	//Ҫȷ��c�ǿա��������Ϊ�գ�if�в�������Ϊ����δ����ġ�
	if (!c.empty())
	{
		//val ��val2��c�е�һ��Ԫ��ֵ�Ŀ���
		auto val = *c.begin(), val2 = c.front();
		//val3��val4 ��c�����һ��Ԫ��ֵ�Ŀ���
		auto last = c.end();
		auto val3 = *(--last);  //���ܵݼ�forward_list������
		auto val4 = c.back(); //forward_list ��֧��
	}
}

/*
										��˳�������з���Ԫ�صĲ���
at���±����ֻ������string��vector��deque��array
back ��������forward_list

c.back()    //����c��βԪ�ص����á���cΪ�գ�������Ϊδ����
c.front()  //����c����Ԫ�ص����á���cΪ�գ�������Ϊδ����
c[n]			//����c���±�δn��Ԫ�ص����ã�n��һ���޷������Ρ���n>=c.size(),������Ϊδ����
c.at(n)		//�����±�δn��Ԫ�ص����á�����±�Խ�磬���׳�һ out_of_rang�쳣

warning  ��һ������������front��back������ʹ��һ��Խ����±�һ������һ�����صĳ�����ƴ���

*/

//���ʳ�Ա�������ص�������
//����������Ԫ�صĳ�Ա����������front��back���±��at�� ���صĶ������á����������һ��const�����򷵻�ֵ��const������

void Test21()
{
	array<int, 10> c = { 0,1,2,3,4,5,6,7,8,9 };
	if (!c.empty())
	{
		c.front() = 42;			//��42����c�еĵ�һ��Ԫ��
		auto&v = c.back();	//���ָ�����һ��Ԫ�ص�����
		v = 1024;					//�ı�c�е�Ԫ��
		auto &v2 = c.back();	//v2����һ�����ã�����c.back()��һ������
		v2 = 0;							//δ�ı�c�е�Ԫ��
	}

}

//��ϰ9.24
//��д���򣬷ֱ�ʹ��at���±��������front��begin��ȡһ��vector�еĵ�һ��Ԫ�ء���һ����vector�ϲ�����ĳ���

void Test22()
{
 //֪ʶ��1��at���±��������front���صĶ��ǵ�һ��Ԫ�ص����ã���begin���ص��ǵ�һ��Ԫ�صĵ�����
	vector<int> vec1;
	int a = vec1.front();//terminating with uncaught exception of type std::out_of_range
	int b = vec1[0];// Segmentation fault: 11
	int c = vec1.at(0);
	int d = *vec1.begin();//��Ҫ������
	cout << a << " " << b << " " << c << " " << d << endl;

}

//ɾ��Ԫ��
/*
										˳��������ɾ������
��Щ������ı������Ĵ�С�����Բ�������array
forward_list  ������汾��erase
forward_list  ��֧��pop_back; vector �� string ��֧��pop_front.
c.pop_back()   ɾ��c��βԪ�ء���cΪ�գ�������Ϊδ���塣��������void
c.pop_front()  ɾ��c����Ԫ�ء���cΪ�գ�������Ϊδ���塣��������void
c.erase(p)		ɾ��������p��ָ����Ԫ�أ�����һ��ָ��ɾԪ�صĵ���������pָ��βԪ�أ��򷵻�β�����������p��β���������������Ϊδ����
c.erase(b,e)		ɾ��������b��e��ָ����Χ�ڵ�Ԫ�ء�����һ��ָ�����һ����ɾԪ��֮��Ԫ�صĵ���������e�������β�������������Ҳ����β�������
c.clear()		ɾ��c�е�����Ԫ�ء�����void

Warning       ɾ��deque�г���βԪ��֮����κ�Ԫ�ض���ʹ���е����������ú�ָ��ʧЧ��ָ��vector��string��ɾ����֮��λ�õĵ����������ú�ָ�붼��ʧЧ

*/

//pop_front �� pop_back��Ա����
/*
   pop_front��pop_back��Ա�����ֱ�ɾ����Ԫ�غ�βԪ�ء���vector��string��֧��push_frontһ������Щ����Ҳ��֧��pop_front.���Ƶģ�
   forward_list��֧��pop_back.��Ԫ�ط��ʳ�Ա�������ƣ����ܶ�һ��������ִ�е���������

	��Щ��������void�� �������Ҫ������Ԫ�ص�ֵ���ͱ�����ִ�е�������֮ǰ��������

	while(!ilist.empty())
	{
	   process(ilist.front());  //��list����Ԫ�ؽ���һЩ����
	   ilist.pop_front();		//��ɴ����ɾ����Ԫ��
	}

*/

//�������ڲ�ɾ��һ��Ԫ��
/*
��Ա����erase��������ָ��λ��ɾ��Ԫ�ء����ǿ���ɾ����һ��������ָ���ĵ���Ԫ�أ�Ҳ����ɾ����һ�Ե�����ָ���ķ�Χ�ڵ�����Ԫ�ء�
������ʽ��erase������ָ��ɾ���ģ����һ����Ԫ��֮��λ�õĵ�������������j��i֮���Ԫ�أ���ôerase(i)������ָ��j�ĵ�����
*/

//�����ѭ��ɾ��һ��list�е���������Ԫ�أ�
void Test23()
{
	list<int> lst = { 0,1,2,3,4,5,6,7,8,9 };
	auto it = lst.begin();
	while (it != lst.end())
	{
		if (*it % 2) //��Ԫ��Ϊ����
		{
			it = lst.erase(it); //ɾ����Ԫ��
		}
		else
			++it;
	}

}

//ɾ�����Ԫ��
//����һ�Ե�������erase�汾��������ɾ��һ����Χ�ڵ�Ԫ�أ�
//Ϊ��ɾ��һ�������е�����Ԫ�أ����Ǽ����Ե���clear��Ҳ������begin��end��õĵ�������Ϊ��������erase��

void Test24()
{
	list<int> Slist = { 0,1,2,3,4,5,6,7,8,9 };

	Slist.clear();  //ɾ������������Ԫ��
	Slist.erase(Slist.begin(), Slist.end()); //�ȼ۵���
}


//��ϰ9.25��page 312��
/*
֪ʶ�㣺����(��array)������ɾ��Ԫ�صķ���

pop_back()

pop_front()

erase()

clear()

��ȣ�������ɾ������

elem2Ϊβ���������ɾ��elem1�����һ��Ԫ��

��Ϊβ���������������ɾ������

*/

//��ϰ9.26
/*
����������붨���ia����ia������һ��vector��һ��list�С�ʹ�õ��������汾��erase��list��ɾ������Ԫ�أ���vector��ɾ��żԪ�ء�
int ia[] ={0,1,1,2,3,5,8,13,21,55,89};
*/

void  Test25()
{
	int ia[] = { 0,1,1,2,3,5,8,13,21,55,89 };

	vector<int> vec1(ia, ia + 9);//��������
	list<int> list1(ia, ia + 9);

	vector<int>::iterator it1 = vec1.begin();//ʹ�õ�����
	list<int>::iterator it2 = list1.begin();

	while (it1 != vec1.end())//ɾ������
	{
		if ((*it1) % 2 == 0)
		{
			it1 = vec1.erase(it1);//��ɾ��λ�ø���
		}
		else//���жϷ�ż�������Ƶ���һλ��
		{
			++it1;
		}
	}

	while (it2 != list1.end())
	{
		if (*it2 % 2 != 0)
		{
			it2 = list1.erase(it2);//��ɾ��λ�ø���
		}
		else//���жϷ�ż�������Ƶ���һλ��
		{
			++it2;
		}
	}

	//��֤���
	vector<int>::iterator it3 = vec1.begin();//��Ҫ���¶�����ʱ������
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

//�����forward_list����
//������Щ���������������ϵĲ�����ʵ�ַ�ʽ���ݣ�page 313����forward_listδ����insert��emplace��erase��
//���Ƕ�������Ϊinsert_after��emplace_after��erase_after�Ĳ�����
/*
								��forward_list �в����ɾ��Ԫ�صĲ���
lst.before_begin()          ����ָ��������Ԫ��֮ǰ�����ڵ�Ԫ�صĵ��������˵��������ܽ����á�cbefore_begin() ����һ��const_iterator
lst.chefore_begin()			�ڵ�����p֮���λ�ò���Ԫ�ء�t��һ������n��������b��e�Ǳ�ʾ��Χ��һ�Ե�����(b��e����ָ��lst��)��
list.insert_after(p,t)			il��һ���������б�����һ��ָ�����һ������Ԫ�صĵ������������ΧΪ�գ��򷵻�p����pΪβ���������������ΪΪ����
lst.insert_after(p,n,t)
lst.insert_after(p,b,e)
lst.insert_after(p,il)

emplace_after(p,args)    ʹ��args��pָ����λ��֮�󴴽�һ��Ԫ�ء�����һ��ָ�������Ԫ�صĵ���������pΪβ���������������ΪΪ����

lst.erase_after(p)				ɾ��pָ���λ��֮���Ԫ�أ���ɾ����b֮��ֱ��������������e֮���Ԫ�ء�����һ��ָ��ɾ��Ԫ��֮��Ԫ�صĵ�������
lst.erase_after(b,e)			��������������Ԫ�أ��򷵻�β������������pָ��lst��βԪ�ػ�����һ��β���������������Ϊδ���塣

*/

//����forward_list����ӻ�ɾ��Ԫ��ʱ�����Ǳ����ע����������---һ��ָ���ң� Ҫ�����Ԫ�أ���һ��ָ����ǰ��
void Test26()
{
	forward_list<int> flst = { 0,1,2,3,4,5,6,7,8,9 };
	auto prev = flst.before_begin();				//��ʾflst�ġ���Ԫ�ء�
	auto curr = flst.begin();							//��ʾflst�еĵ�һ��Ԫ��
	while (curr != flst.end())							//����Ԫ��Ҫ����
	{
		if (*curr %2)											//��Ԫ��Ϊ����
		{
			curr = flst.erase_after(prev);			//ɾ�������ƶ�curr
		}
		else
		{
			prev = curr;										//�ƶ�������curr��ָ����һ��Ԫ�أ�prevָ��
			++curr;											//curr֮ǰ��Ԫ��	
		}
	}

}


//��ϰ9.28
/*
��д����������һ��forward_list<string> ������string����������������Ӧ�������в��ҵ�һ��string�������ڶ���string���뵽�����ŵ�һ��string֮���λ�á�
����һ��stringδ�������У��򽫵ڶ���string���뵽����δβ��
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

//9.3.5 �ı�������С
/*
���ǿ�����resize�����ӻ���С������������һ����array��֧��resize�������ǰ��С������Ҫ��Ĵ�С�������󲿵�Ԫ�ػ�ɾ����
�����ǰ��СС���´�С���Ὣ��Ԫ����ӵ������󲿣�

resize��������һ����ѡ��Ԫ��ֵ������������ʼ����ӵ������е�Ԫ�ء����������Ϊ�ṩ�˲�������Ԫ�ؽ���ֵ��ʼ����������������ʱ������Ԫ�أ�
��resize��Ԫ�������Ԫ�أ������Ǳ����ṩ��ʼֵ����Ԫ�����ͱ����ṩһ��Ĭ�Ϲ��캯��

*/

void Test28()
{
	list<int> ilist(10, 42);   //10��int:ÿ����ֵ����42
	ilist.resize(15);				//��5��ֵΪ0��ӵ�ilist��δβ
	ilist.resize(25, -1);			//��10��ֵΪ-1 ��Ԫ����ӵ�ilist��δβ
	ilist.resize(5);				//��ilistδβɾ��20��Ԫ��
}

/*
								˳��������С����
resize ��������aray
c.resize(n)   ����c�Ĵ�СΪn��Ԫ�ء���n<c.size(),������Ԫ�ر������������������Ԫ�أ�����Ԫ�ؽ���ֵ��ʼ��

c.resize(n,t)  ����c�Ĵ�СΪn��Ԫ�ء��κ�����ӵ�Ԫ�ض���ʼ��Ϊֵt

Warning��  ���resize��С��������ָ��ɾ��Ԫ�صĵ����������ú�ָ�붼��ʧЧ����vector��string��deque����resize���ܵ��µ�������ָ�������ʧЧ


*/

//������������ʹ������ʧЧ
/*
�����������Ԫ�غ�

* �������ʹvector��string���Ҵ���ռ���·��䣬��ָ�������ĵ�������ָ������ö���ʧЧ���������ռ�δ���·��䣬ָ�����λ��֮ǰ��Ԫ�صĵ�������
ָ�����������Ч����ָ�����λ��֮��Ԫ�صĵ�������ָ������ý���ʧЧ��
* ����deque�����뵽����βλ��֮����κ�λ�ö��ᵼ�µ�������ָ�������ʧЧ���������βλ�����Ԫ�أ���������ʧЧ����ָ����ڵ�Ԫ�ص����ú�ָ��
����ʧЧ
*����list��forward_list��ָ�������ĵ�����������β�����������ǰ����������ָ�����������Ч��

�����Ǵ�һ��������ɾ��Ԫ�غ�ָ��ɾ��Ԫ�صĵ�������ָ������û�ʧЧ����Ӧ�ò������˾��ȡ��Ͼ�����ЩԪ�ض��Ѿ��������ˡ�
������ɾ��һ��Ԫ�غ�

*����list��forward_list��ָ����������λ�õĵ�����������β�����������ǰ�������������ú�ָ������Ч��

*����deque���������β֮����κ�λ��ɾ��Ԫ�أ���ôָ��ɾ��Ԫ��������Ԫ�صĵ����������û�ָ��Ҳ��ʧЧ�������ɾ��deque��βԪ�أ���β�������Ҳ��ʧЧ��
�����������������ú�ָ�벻��Ӱ�죻�����ɾ����Ԫ�أ���ЩҲ������Ӱ�졣

*����vector��string��ָ��ɾԪ��֮ǰԪ�صĵ����������ú�ָ������Ч��
ע�⣺������ɾ��Ԫ��ʱ��ָ�������ʱ���ص�����ʱ����
*/

//��д�ı�������ѭ������

//ɵ��ѭ����ɾ��ż��Ԫ�أ�����ÿ������Ԫ��
void Test29()
{
	vector<int> vi = { 0,1,2,3,4,5,6,7,8,9 };
	auto iter = vi.begin();     //����begin������cbegin����Ϊ����Ҫ�ı�vi
	while (iter != vi.end())
	{
		if (*iter%2)
		{
			iter = vi.insert(iter, *iter); //���Ƶ�ǰԪ��
			iter += 2;	//��ǰ�ƶ���������������ǰԪ���Լ����뵽��֮ǰ��Ԫ��
		}
		else
		{
			iter = vi.erase(iter);    //ɾ��ż��Ԫ��
			//��Ӧ��ǰ�ƶ���������iterָ������ɾ����Ԫ��֮���Ԫ��
		}
	}


}
/*
�����߼����ͣ�
	�˳���ɾ��vector�е�ż��ֵԪ�أ�������ÿһ������ֵԪ�ء������ڵ���insert��erase�󶼸��µ���������Ϊ���߶����ǵ�����ʧЧ��

	�ڵ���erase�󣬲��ص�������������Ϊerase���صĵ������Ѿ�ָ����������һ��Ԫ�ء�����insert����Ҫ�������������Ρ�
	��ס��insert�ڸ���λ��֮ǰ������Ԫ�أ�Ȼ�󷵻�ָ����Ԫ�صĵ�������ˣ��ڵ���insert��iterָ���²���Ԫ�أ�λ���������ڴ����Ԫ��֮ǰ��
	���ǽ��������������Σ�ǡ��Խ��������ӵ�Ԫ�غ����ڴ����Ԫ�أ�ָ����һ��δ�����Ԫ�ء�
*/

//��Ҫ����end���صĵ�����
/*
	���������/ɾ��vector��string��Ԫ�غ󣬻���deque����Ԫ��֮���κ�λ�����/ɾ��Ԫ�غ�ԭ��end���صĵ��������ǻ�ʧЧ��
	��ˣ���ӻ�ɾ��Ԫ�ص�ѭ��������뷴������end����������ѭ��֮ǰ����end���صĵ�������һֱ��������δβʹ�á�

*/

void Test30()
{
	vector<int> v = { 0,1,2,3,4,5,6,7,8,9 };
	//���ѣ���ѭ������Ϊ��δ�����
	auto begin = v.begin(), end = v.end(); //����β��������ֵ��һ��������

	while (begin != end)
	{
		//��һЩ����
		//������ֵ����begin���¸�ֵ������Ļ����ͻ�ʧЧ

		++begin;    //��ǰ�ƶ�begin����Ϊ�������ڴ�Ԫ��֮�����Ԫ��
		begin = v.insert(begin, 42); //������ֵ
		++begin;   //��ǰ�ƶ�begin �������Ǹոռ����Ԫ��
	}


	/*
	�˴�����δ����ġ��ںܶ��׼��ʵ���ϣ��˴���ᵼ������ѭ���������������ǽ�end�������صĵ�����������һ����Ϊend�ľֲ������С�
	��ѭ���У������������������һ��Ԫ�أ��������ʹ������end�еĵ�����ʧЧ�ˡ��������������ָ��v���κ�Ԫ�أ�����v��βԪ��֮���λ�á�
	*/
}

//TIP     �����һ��ѭ���в���/ɾ��deque��string��vector�е�Ԫ�أ���Ҫ����end���صĵ�������

//������ÿ�β�����������µ���end(),��������ѭ����ʼǰ���������صĵ�����:
void Test31()
{
	vector<int> v = { 0,1,2,3,4,5,6,7,8,9 };	
	auto begin = v.begin();

	//����ȫ�ķ�������ÿ��ѭ�������/ɾ��Ԫ�غ󶼴��¼���end
	while (begin  != v.end())
	{
		//��һЩ����
		++begin;  //��ǰ�ƶ�begin����Ϊ�������ڴ�Ԫ��֮�����Ԫ��
		begin = v.insert(begin, 42);  //������ֵ
		++begin; //��ǰ�ƶ�begin���������Ǹոռ����Ԫ��

	}

}

//9.4 vector���������������
/*
����������ȡ�µ��ڴ�ռ�ʱ��vector��string��ʵ��ͨ���������µĿռ����������ڴ�ռ䡣����Ԥ����Щ�ռ���Ϊ���ã�����������������Ԫ�ء�
�������Ͳ���Ҫÿ�������Ԫ�ض����·����������ڴ�ռ��ˡ�
��Ȼvector��ÿ�����·����ڴ�ռ�ʱ��Ҫ�ƶ�����Ԫ�أ���ʹ�ô˲��Ժ������Ų���ͨ����list��deque��Ҫ�졣

*/

//���������ĳ�Ա����
/*
												������С�������
shrink_to_fit ֻ������vector��string��deque��
capacity��reserveֻ������vector��string��
c.shrink_to_fit()			�뽫capacity()����Ϊ��size()��ͬ��С
c.capacity()					�����·����ڴ�ռ�Ļ���c���Ա������Ԫ��
c.reserve(n)					��������������n��Ԫ�ص��ڴ�ռ�

Note�� reserve�����ı�������Ԫ�ص�����������Ӱ��vectorԤ�ȷ�������ڴ�ռ�


reserve��  ��������С���ڵ�ǰ������reserve���ٷ���������һ������ڴ�ռ䣨���ܸ��󣩡�����reserve��ԶҲ�����������ռ�õ��ڴ�ռ䡣
resize��    ֻ�ı�������Ԫ�ص���Ŀ������������������������ͬ������ʹ��resize����������Ԥ�����ڴ�ռ�

���±�׼���У����ǿ��Ե���shrink_to_fit��Ҫ��deque��vector��string �˻ز���Ҫ���ڴ�ռ䡣�˺���ָ�����ǲ�����Ҫ�κζ�����ڴ�ռ䡣���ǣ�
�����ʵ�ֿ���ѡ����Դ�����Ҳ����˵������shrink_to_fit Ҳ������֤һ���˻��ڴ�ռ䡣

*/


//capacity ��size
/*
���capacity��size������ǳ���Ҫ��������sizeʱָ���Ѿ������Ԫ�ص���Ŀ����capacity�����ڲ������µ��ڴ�ռ��ǰ�����������ܱ������Ԫ�ء�
*/
void Test32()
{
	vector<int> ivec;
	//sizeӦ��Ϊ0��capacity��ֵ�����ھ���ʵ��
	cout << "ivec:size:" << ivec.size() << "capacity:" << ivec.capacity() << endl;

	//��ivec���24��Ԫ��
	for (vector<int>::size_type ix=0;ix!=24;++ix)
	{
		ivec.push_back(ix);
	}

	//size Ӧ��Ϊ24�� capaciytӦ�ô��ڵ���24�����������ڱ�׼����ʵ��
	cout << "ivec:size:" << ivec.size() << "capcity:" << ivec.capacity() << endl;


}
int main()
{

	Test25();
	system("pause");
	return 0;
}