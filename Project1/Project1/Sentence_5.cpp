#include <iostream>
#include <string>
#include <vector>

using namespace std;


//�����
void test_01()
{
	//����ڳ����ĳ���ط����﷨����Ҫһ����䵫���߼��ϲ���Ҫ����ʱӦ��ʹ�ÿ���䡣
	; //�����

}

//���������
void test_02()
{
	/*
	while (int i = get_num())   //ÿ�ε���ʱ��������ʼ��i
		cout << i << endl;
	i = 0; //������ѭ���ⲿ�޷�����i

*/
}

void test_03()
{
	/*
	//����ʵ�ʵ�ִ�й��̲�����������ʽ��ʾ��������else��֧ƥ���ʱ�ڲ�if���
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
		//����a b c ���� ִ��    std::cout << "ddd" << std::endl;
		//Ҳ��������д��	case 'a':case 'b':case 'c':
	case 'a':
	case 'b':
	case 'c':
		std::cout << "ddd" << std::endl;
		break;
	default:
		break;
	}

/*
//���棺����ȷ�ĳ����߼�
switch(ch){

case 'a':   ++acnt;		//�˴�Ӧ����һ��break���
cast 'e': ++ecnt;			//�˴�Ӧ����һ��break���
cast 'i': ++icnt;			//�˴�Ӧ����һ��break���

����ch��ֵ�ǡ�e������ʱ������ֱ��ִ��case'e'��ǩ����Ĵ��룬�ô����ecnt��ֵ��1.�����������򽫿�Խcase��ǩ�ı߽磬���ŵ���icnt


}


*/

}

}

void switch_08()
{
	int Mybool = 1;

	switch (Mybool)  //���myboolΪ bool���ͣ�����default��break������ʾ���л�����ж���ġ�default����ǩ���������п��ܵġ�case����ǩ��
								//��Ϊboolֻ��������������Բ���Ҫdefault
	{
	case 1:   //���ж������ʱ����Ҫ��{} ����
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
	
		case  ival: bufsize = ival * sizeof(int); break;	//����case����Ӧ���ǳ�����
		case jval: bufsize = jval * sizeof(int); break;    //����case����Ӧ���ǳ�����
		case kval: bufsize = kval * sizeof(int); break; //����case����Ӧ���ǳ�����
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

		case  ival: bufsize = ival * sizeof(int); break;	//��ȷ   ival�ǳ���
		case jval: bufsize = jval * sizeof(int); break;   
		case kval: bufsize = kval * sizeof(int); break; 
		default:
			break;
		}

	}
}

/*
//for���ͷ�еĶ��ض���
//��¼��v�Ĵ�С��������ԭ�������һ��Ԫ�غ����ѭ��
for(decltype(v.size()) i =0,sz = v.size(); i !=sz; ++i)
		v.push_back(v[i]);
*/


void dowhile_10()
{
	int a = 0;
	//��ִ�У����ж�
	do 
	{
		++a;
		std::cout << a << std::endl;
	} while (a<10);

	system("pause");
}

//5.5  ��ת��䣺  break��  continue�� goto�� return��



//5.5.1 break ���
/*
break ��为����ֹ���������while, do while,for ����swith ��䣬������Щ���֮��ĵ�һ����俪ʼ����ִ�С�
break���ֻ�ܳ����ڵ���������switch����ڲ�������Ƕ���ڴ���ѭ������������ڲ���
*/
void Mybreak_11()
{
	string buf;
	while (cin>>buf && !buf.empty())
	{
		switch (buf[0])
		{
		case '-':
			//������һ���հ�Ϊֹ
			for (auto it = buf.begin() + 1; it != buf.end();++it)
			{
				if (*it == ' ')
					break;   //#1,�뿪forѭ��
			}

			//break #1 ������Ȩת�Ƶ���� ʣ��ġ�-������:
			break;   //#2,�뿪switch���
		case '+': std::cout << "+" << std::endl; break;
		} //����switch
		//����swithc:break #2������Ȩת�Ƶ�����
	}//����while
	
}

//5.5.2 continue ���
/*
continue�����ֹ�����ѭ���еĵ�ǰ������������ʼ��һ�ε�����continue���ֻ�ܳ�����for��while��do while ѭ�����ڲ���

*/
void Mycontinue_12()
{
	string buf;
	while (cin>> buf && !buf.empty())
	{
		if (buf[0] != ' ')
		{
			continue;   //���Ŷ�ȡ��һ������
		}
		//����ִ�й��̵������˵����ǰ�����������»��߿�ʼ�ġ����Ŵ���buf...
	}

}

//5.5.3 goto���
//goto���������Ǵ�goto�����������ת��ͬһ�����ڵ���һ����䡣
//���飺��Ҫ�ڳ�����ʹ��goto��䣬��Ϊ��ʹ�ó�������������޸ġ�
void Mygoto_13()
{
		AAA: std::cout << "AAA" << std::endl;    //����ǩ��䣬������Ϊgoto��Ŀ��
		
		goto AAA;   //��ת��AAA�������ͻ�һֱִ�С�ͣ��������

	/*
	goto end;
	int ix =10; //����goto����ƹ���һ������ʼ���ı�������

	end: 
	//���󣺴˴��Ĵ�����Ҫʹ��ix������goto����ƹ�����������
	ix = 42;
	*/

		system("pause");

}

//5.6.1 throw ���ʽ
//throw ���ʽ�����ؼ���throw �ͽ�������һ�����ʽ�����б��ʽ�����;����׳����쳣���͡�
void Mythrow_14()
{
	int* aa = nullptr;
	if (aa == nullptr)
	{
		throw runtime_error("Data must refer to same ISBN");
	}
	system("pause");
}

//5.6.2  try����  
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
				throw std::runtime_error("����������Ϊ0");
			}
			cout << static_cast<double>(a) / b << endl; //���ǵ���������������С����������Ƚ�aǿ��ת��Ϊdouble���͡�
		}
		catch (runtime_error err) //err��runtime_error���һ��ʵ��
		{
			cout << err.what(); //ʵ���ĳ�Ա���������������ɱ���������
			cout<< "\n Try Again? Enter y or n" << endl;
			char c;
			cin >> c;
			if (!cin || c=='n')
			{
				break;    
			} //����˵try�Ǽ���쳣�ģ�����������쳣����throw���׳���һ���쳣��Ȼ��catch���������쳣�Ĵ���
			  //���û��catch���֣�����try����Ȼ�ᱨ��
		}
	}


	system("pause");

}

/*
<stdexcept>������쳣��

exception					 //���������
runtime_error			//ֻ��������ʱ���ܼ���������
range_error				//����ʱ�������ɵĽ���������������ֵ��Χ
overflow_error			//����ʱ���󣺼�������
underflow_error		//����ʱ���󣺼�������
logic_error				//�����߼�����
domain_error			//�߼����󣺲�����Ӧ�Ľ��ֵ������
iinvalid_argument	//�߼�������Ч����
length_error				//�߼�������ͼ����һ��������������󳤶ȵĶ���
out_of_range			//�߼�����ʹ��һ��������Ч��Χ��ֵ

*/
/*
int main() 
{

	Mytry_15();


	return 0;
}

*/