#include <iostream>
#include <string>
#include <vector>

using namespace std;

void test()
{
	int i_01 = 0, j_02 = 0, k = 0;   //��ʼ�������Ǹ�ֵ

	int ival, jval;
	ival = jval = 0;    //��ȷ��������ֵΪ0

	//�����͵ݼ������

	int i = 0, j;
	//ǰ�õĵ����������������ã����õĵ�������������ú��㡣�ݼ�һ��
	j = ++i;        //j = 1,i =1 :ǰ�ð汾�õ�����֮���ֵ
	j = i++;		//j=1��i=2	:���ð汾�õ�����֮ǰ��ֵ��
/*
���飺���Ǳ��룬�����õ����ݼ�������ĺ��ð汾��
		��������ʹ��ǰ�ð汾��ϰ�ߣ������������������ܵ����⣬���Ҹ���Ҫ����д���Ĵ�������ϱ�̵ĳ��ԡ�
*/

	vector <int>v = {0,1,2,3};
	auto pbeg = v.begin();
	//���Ԫ��ֱ��������һ����ֵΪֹ
	while (pbeg !=v.end() && *pbeg >=0)
	{
		std::cout << *pbeg++ << std::endl;   //�����ǰֵ����pbeg��ǰ�ƶ�һ��Ԫ�ء�
	}

	string s("some string");
	for (auto it = s.begin();it !=s.end() && !isspace(*it); ++it)
	{
		*it = toupper(*it);   //����ǰ�ַ��ĳɴ�д��ʽ
	}
/*
	//��ѭ������Ϊ��δ����ģ�
	while (beg !=s.end() && !isspace(*beg))
	{
					*beg = toupper(*beg++);    //���󣺸ø�ֵ���δ����
	}
	//�������ڣ���ֵ������������˵���������õ���beg�������Ҳ��������󻹸ı���beg��ֵ�����Ըø�ֵ�����δ����ġ�
	//�༭�����ܰ�����������һ��˼·����ñ��ʽ��
	*beg  = toupper(*beg);			   //�����������ֵ
	*(beg + 1) = toupper(*beg);		//���������ֵ��ֵ
*/


}

void test4_19()
{
	int test = 3;
	

	for (int* ptr = &test;ptr !=0; *ptr++)		//ptr��ǰ�ƶ�
	{		
	//	std::cout << ptr << std::endl;   //kael_����ı䣬��Ϊ*ptr++
	//	std::cout << *ptr << std::endl; //kael_���ָ����ָ�Ķ��󡣶���ı䡣��Ϊ*ptr++
	//	std::cout << &ptr << std::endl; //kael_��ptr�ĵ�ַ�� ��Ϊptr���ָ��ĵ�ַһֱû�иı䣬�ı����ptr���ָ��ָ��ĵ�ַ��
	}
		int* ptr02 = &test;
	if (ptr02 !=0 && *ptr02++)
	{
		//ptr02 �Ƿ�Ϊ0.   *ptr02 �Ƿ�Ϊ0.���õĵ�������������ú���
	}
	int ival = 1;
	if (ival++ && ival)
	{
		//�ж�ival��ival+1 ����ֵ�Ƿ񶼷�0
	}

	vector<int> vec(2, 4);

	//������Щû��ָ��ִ��˳����������˵��������ʽָ��  �޸�ͬһ������  �������������󲢲���δ�������Ϊ��
	if (vec[ival++]<=vec[ival])
	{
		//��������ᵼ�±�������Ϊ��ֵ˳��һ������Ϊc++ ֻҪ�����������������ֵ˳��>=��������  
		//���ֱַ����߼���&&��  �߼���||��  ������������� �Ͷ���  ��
	}


	system("pause");
}

//��Ա���������

void test_4_6()
{
	//���������ȡ������һ����Ա�����ʽptr->�ȼ���(*ptr).mem;

	string s1 = "a string", *p = &s1;
	auto n = s1.size();		//����string ����S1 ��size��Ա
	n = (*p).size();				//����p��ָ�����size��Ա,  ������������ȼ����ڵ������
	//����p��size��Ա��Ȼ�������size�Ľ��
	//*p.size();    //����p��һ��ָ�룬��û����δsize�ĳ�Ա
	n = p->size();				//�ȼ���(*p).size()

/*
��ͷ�����������һ��ָ�����͵�������󣬽����һ����ֵ����������ֳ����������
�����Ա�����Ķ�������ֵ����ô�������ֵ�������������Ա�����Ķ�������ֵ����ô�������ֵ��

*/
}

//��ϰ4.20

void test4_20()
{
	/*
	ָ����C����������еĶ�����
	����������C++������еģ�ָ����������Ч�ʸߡ����������ܸ��ḻһЩ����������ǿ��һЩ����
	c++��stl����ܶ��㷨���ǻ��ڵ������ģ�һ�����㷨�Ĳ������Դ���ָ����Ϊ������ʹ��
	*/

	/*
	vector<string>::iteratior iter;
	*iter ++;				//�Ϸ��� �ȶ�iter��1���ٷ���iterָ���ֵ
	(*iter)++;				//���Ϸ�������iterָ���ֵΪstring ++ ����������
	*iter.empty();		//���Ϸ���iter��һ��ָ�룬û��empty�����ĳ�Ա
	iter->empty();		//�Ϸ����ж�iter��ָ��ֵ�Ƿ�Ϊ��
	++*iter;				//���Ϸ���*iter���Եõ�iter��ָ���ַ����������ַ�����û��++������
	iter++ ->empty(); //�Ϸ��������ж�iter˵ָ���ֵ�Ƿ�Ϊ�գ��ٶ�iter��1
		
	*/

}

//λ������������ɣ�
/*
~ λ��
<< ����
>>����
&	λ��
^ λ���
|	λ��
*/

//4.9   sizeof�����


void  MySizeof_4_28()
{
	/*
	sizeof������������ϵͳΪ����()��(������ʱ����()Ҳ��)�����͡������ȷ�����ڴ�ռ���ֽ���
	��16λintƽ̨����2��
	��32λintƽ̨����4��
	��64λintƽ̨����8
	*/
	std::cout << sizeof(int) << std::endl;  //int���4 //������������д�ͺ���
	std::cout << sizeof(string) << std::endl;

	system("pause");
}
struct Sales_data
{

};
void  MySizeof_4_29()
{
	/*
	sizeof(type)
	sizeof expr
	*/

	Sales_data data, *p; 
	sizeof(Sales_data);				//����Sales_data���͵Ķ�����ռ�õĿռ��С
	sizeof data;							//data�����͵Ĵ�С����sizeof(Sales_data)
	sizeof p;								//ָ����ռ�õĿռ��С
	sizeof *p;								//p��ָ���͵Ŀռ��С����sizeof(Sales_data)
	//sizeof data.revenue;			//Sales_data��revenue��Ա��Ӧ���͵Ĵ�С
	//sizeof Sales_data::revenue;	//��һ�ֻ�ȡrevenue��С�ķ�ʽ��

	int x[10];
	int *p_02 = x;
	std::cout << sizeof(x) << std::endl;			 //���40     kael��������������Ԫ�ش�С�ĺ͡�4*10
	std::cout << sizeof(*x) << std::endl;			//���4    kael��xָ���ֵ�Ĵ�С
	std::cout << sizeof(p_02) << std::endl;		//���4		kael��p_02���ָ��Ĵ�С
	std::cout << sizeof(*p_02) << std::endl;		//���4    kael:   p_02ָ���ֵ�Ĵ�С
	

	system("pause");
}

void  MySizeof_4_30()
{
	/*
	sizeof x +y				�ȼ���		(sizeof x)  +y;
	sizeof p->mem[i]		 �ȼ���		sizeof(p->mem[i]);
	sizeof a <b               �ȼ���		(sizeof a)<b;
	
	
	*/
}

//����ת��

void TypeConversion()
{
	/*
	bool		flag;
	short	sval;
	int		 ival;
	long		 lval;
	float		fval;
	char		cval;
	unsigned short usval;
	unsigned int	uival;
	unsigned long ulval;
	double				 dval;

	3.14159L + 'a'; //'a'������int��Ȼ���int ֵת����long double
	dval + ival;		//ivalת����double
	dval + fval;		//fvalת����double
	ival = dval;		//dvalת���ɣ��г�С�����ֺ�int
	flag = dval;		//���dval��0����flag��false��������true
	cval + fval;		//cval������int��Ȼ���intֵת����float
	sval + cval;		//sval��cval��������int
	cval + lval;       //cvalת����long
	ival + ulval;		//ivalת���� unsigned long
	usval + ival;		//����unsigned short��int��ռ�ռ�Ĵ�С��������
	uival + lval;		//����unsigned int ��long ��ռ�տռ�Ĵ�С����ת��
*/
}

void TypeConversion_02()
{
	int i;
	const int &j = i;		//�ǳ���ת���� const int ������
	const int *p = &i;		//�ǳ����ĵ�ַת����const�ĵ�ַ
	//int &r = j, *q = p; //���󣺲�����constת���ɷǳ���
}
void test_4_35()
{
	char cval;
	int ival = 1;
	unsigned int ui = 2;
	float fval;
	double dval = 3;

	cval = 'a' + 3;
	fval = ui - ival * 1.0;
	dval = ui * fval;
	cval = ival + fval + dval;

}

//ת��

void TypeConversion_03()
{
	const char* pc =" hellow world";
	
	//char *q = static_cast<char*>(pc);// ����static_cast ����ת����const����
	string mystring = static_cast<string>(pc); //��ȷ���ַ�������ֵת����string����
	//string mystring02 = const_cast<string>(pc);  //����const_castֻ�ı䳣�����ԡ�//kael��const_castֻ�Ǹı��������ĵײ�const
	char *p = const_cast<char*>(pc);  //��ȷ������ͨ��pдֵ��δ�������Ϊ��//kael ����Ϊpc��const�Ƕ���const����const_castֻ�ı��������ĵײ�const��
	/*
	�����������һ��������ʹ��const_castǿ��ת������ȡдȨ���ǺϷ���Ϊ��Ȼ�����������һ����������ʹ��const_castִ��д�����ͻ����δ����ĺ����
	
	*/
	

	//reinterpret_cast �����������ڻ�����Ҫ��ȫ��ʹ�ã�������漰�����ͺͱ�����ʵ��ת���Ĺ��̶��ǳ��˽⡣
	int a = 3;
	int *ip =&a ;
	//���Ǳ����μ�pc��ָ����ʵ������һ��int�����ַ����������pc������ͨ���ַ�ָ��ʹ�þͿ���������ʱ��������
	char *pc_02 = reinterpret_cast<char*>(ip);

}

/*
int main()
{
	//test4_19();
	//MySizeof_4_28();
	//MySizeof_4_29();
	test_4_35();
	return 0;
}

*/