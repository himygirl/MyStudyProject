
//�������Ա�׼���ͷ�ļ�ʱ��ҲӦ����<> ��Χͷ�ļ��������ڲ����ڱ�׼���ͷ�ļ������á�����Χ��

//���Ͻ������£�
//include<XX.h>��ʾ�ڱ�׼��������(���üӾ���·��)
//include"..\XX.h"��ʾ��ָ���ļ�����(��Ҫ��·��(���Ի���Զ���)
#include<iostream>

//�����ռ���԰������Ǳ��ⲻ��������ֶ����ͻ���Լ�ʹ�ÿ�����ͬ���ֵ��µĳ�ͻ��
//��׼�ⶨ����������ֶ��������ռ�std�С�
using namespace std;



/*
void MyIostreamTest()
{

	//std::cout << "Enter  two numbers:" << std::endl; //�ȼ�����������
	std::cout << "Enter  two numbers:";
	std::cout << std::endl;

	int a = 0, b = 0;
	//cin��istream���Ͷ����������Ҳ����Ϊ ��׼���롣
	std::cin >> a >> b;

	//cout ��ostream���͵Ķ��󣬴˶���Ҳ����Ϊ  ��׼���
	//endl�� ����һ������Ϊ ���ݷ�  ��������ֵ��  д��endl��Ч���ǽ�����ǰ�У��������豸�����Ļ�������buffer���е�����ˢ���豸�С�
	//����ˢ�²������Ա�֤��ĿǰΪֹ�������������������������д��������У������ǽ�ͣ�����ڴ��еȴ�д������
	std::cout << a << "+" << b << "is " << a + b << std::endl;

	system("pause");



	*
	*
	*
	*
	*
	*


}

void MyIostreamTest_04()
{
	std::cout << "Enter  two numbers:";
	std::cout << std::endl;

	int v1 = 0, v2 = 0;
	std::cin >> v1 >> v2;
	std::cout << "The sum of" << v1;
    std::cout << std::endl;

	system("pause");

}

void Myfor()
{
	int a = 0;

	for (int i = 0; i < 5; i++)
	{
		//a = a + i;
		std::cout << i << std::endl;
		//pritn  0 1 2 3 4
	}

	for (int i = 0; i < 5; ++i)
	{
		//a = a + i;
		std::cout << i << std::endl;
		//pritn  0 1 2 3 4
	}

	int b = 1;
	for (int i = 0; i < 5; ++i)
	{
		
		b++;
		std::cout << b << std::endl;
		//pritn  2 3 4 5 6
	}


	int c = 1;
	for (int i = 0; i < 5; ++i)
	{

		++c;
		std::cout << c << std::endl;
		//pritn  2 3 4 5 6
	}

	system("pause");
}

void myWhile()
{
	int sum = 0, val = 1;
	while (val<5)
	{
		std::cout <<"begin:"<< val << std::endl;
		// print 1 2 3 4 
		sum += val;
		++val;
		std::cout <<"end:" <<val << std::endl;
		// print 2 3 4 5 6
	}
	system("pause");
	
}

//
void MyTest()
{
	int MyTestsum = 0, val = 0;
	//������ʹ��һ��istream������Ϊ����ʱ����Ч���Ǽ������״̬�����������Ч�ģ�����δ����������ô���ɹ����������ļ���������
	//��������Ч���루��������ֵ����һ����������istream�����״̬���Ϊ��Ч��
	while (std::cin >> val)
	{
		MyTestsum += val;
		
	}
	//��������󣬰�CTRL + Z�������ļ��������ķ�����Ȼ��Enter���Ż������
	std::cout << MyTestsum << std::endl;

}

void MyIf()
{
	int currVal = 0, val = 0;

	//if ֻ���жϵ�һ����Ϊ��Чֵ
	if (std::cin >>currVal)
	{
		int cnt = 1;
		while (std::cin >>val)
		{
			if (val==currVal)
			{
				++cnt;
			}
			else
			{
				std::cout << currVal << "  occurs  " << cnt << "  times  " << std::endl;
				currVal = val;
				cnt = 1;
			}	
		}

		int b = 4;
		std::cout << currVal << "  occurs  " << cnt << "  times  " << std::endl; //��Ϊ�������䣬�߲���else�������
	}
	// �������飺 42 42 42 42 42 55 55 62 100 100 100
}

void test001()
{
	int a = 0;
	while (a<3)
	{
		a++;
	}

	int b = 2;


}



int main()
{
	//MyIostreamTest(); //���������������ϰ
	//MyIostreamTest_04();

	//Myfor();
	//myWhile();
	//MyTest();
	MyIf();
	//test001();




	system("pause");
	return 0;

}
*/