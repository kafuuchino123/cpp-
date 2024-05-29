#pragma once
#include<fstream>
#include<iostream>
#include<string>
#include<algorithm>
#include<conio.h>
#include<list>
#include<vector>

using namespace std;

#define and &&
#define or ||

extern class Vec;
extern vector<Vec> vec;


/*
	
	ͳһҪ��дע�ͣ�дע�ͣ���дע�ͣ�����

	������
		������list<relationship> relas;
		׷�ӣ�����ĳ�˵���Ϣ�������ӿ�������ĳ������ĳ����ϵ��
		ɾ����ɾĳ�ˣ�ɾһ�����룬ɾĳ�˵�ĳ����ϵ��
		�޸ģ��ң���
		�飺��ĳ�ˣ����name,tele1,tele2,address����ĳ�˵���ϵ�����Ƿ���ĳ��
		���򣺸����������Ҫ����ʲô���򣬱���name��address......������
		ͳ�ƣ�ͳ�ƣ������ͳ�����ݰ�����ͬ�����ص���ϵ���ж��٣�β��Ϊ�ض�������β����ͬ�������ж��٣����
		��ʾ��Ӧ�������ĳ��ϵ�˵�������Ϣ����Ҫ���������name��addressɶ�ģ�����

	���棺
		���ۺÿ���࣬ÿһ�β���Ҫ����������ʹ���ն˻򴰿ڸɾ����
		�������ն�ʵ�֣�Ҳ�����ô���д����
		�����ʵ��Ҫ�������û������������������������һ�����棬Ӧ����ѡ�������ҷ�����һ����������棬������Ҫ��goto����
		�����溯��-->menu()

	�ļ����棺
		cpp�ļ������Ҳ��Ǻ��˽⣬��fstream����в�����Ҫ��ʵ�ֵĹ��ܣ�
			��txt�ļ�����
			���溯����׷�ӣ�ɾ�����޸Ķ�Ҫ��Ӧ���ļ�����ͬ������

			�������ǿ�Ļ������Գ���дһ����ʼ��������ÿ�����к�����ʱ���ȡ�ļ�����һ����Ӧ�ĳ�ʼ��
			�����ǳ�������ʱ��һ��ʼδ��ʼ�����������ļ��е�name��tele1��tele2��addressʲô�ĸ���������
			�ĳ�Ա

		��ûд��cpp���ļ���������������е����ѡ���д��д������д��ֱ���ڳ������涨�����������������Ϣ

	�������ܣ�
		��û�뵽��ɶ����ɶ�뷨����˵˵
*/

/*
	��ϵ��:
		name
		telephone number 1
		telephone number 2
		address
		contacts																	//��ϵ��
*/

class relationship
{
private:	
	string name;																	//Ĭ�����ֲ����ظ�
	string tele_num_1;																//��һ,�й����룬11λ��β����3λ
	string tele_num_2;																//����,����Ϊ��
	string address;																	//������
	static list<relationship> contacts;													//��ϵ��
public:

	friend ostream& operator<<(ostream& res, const relationship& r);				//����<<
	bool operator!= (relationship& other);											//����!=
	bool operator== (relationship& other);											//����==

	relationship(string n = "", string t1 = "", string t2 = "", string a = "") :name(n), tele_num_1(t1), address(a) 
	{
		if (t1 != "null" and t2 == "null")
		{
			tele_num_2 = "";
		}
		else if (t1 == "null" and t2 != "null")
		{
			tele_num_1 = t2;
			tele_num_2 = "";
		}
		else if (t1 != "null" and t2 != "null")
		{
			tele_num_1 = t1;
			tele_num_2 = t2;
		}
	}
	void contacts_initial(list<relationship>& re);									//��ϵ���б��ʼ��
	string getname();																//�����Ա����˽�г�Ա���ú������ڷ���˽�г�Ա
	string getaddress();															
	string gettele_num_1();
	string gettele_num_2();
	list<relationship> getcontacts();

	//�޸�
	void name_change(string newname);												//������
	void tele_num_1_change(string newtele);											//�Ŀ�һ
	void tele_num_2_change(string newtele);											//�Ŀ���
	void address_change(string newaddress);											//�ĵ�ַ
	void check_tele();																//��鿨һ�Ƿ�Ϊ��

	//����
	void contacts_add(relationship addone);											//������ϵ��

	//ɾ��
	void contacts_del(relationship delone);											//ɾ����ϵ��

	//��ϵ���޸�
	void contacts_change(relationship oldone, relationship contacts);				//�޸�ĳ����ϵ��
	void contacts_name_change(string oldname, string newname);						//��ĳ��ϵ�˵�����
	void contacts_tele_num_1_change(string name, string newtele);					//��ĳ��ϵ�˵Ŀ�һ
	void contacts_tele_num_2_change(string name, string newtele);					//��ĳ��ϵ�˵Ŀ���
	void contacts_address_change(string name, string newaddress);					//��ĳ��ϵ�˵Ĺ�����

	//����
	bool contacts_find(relationship findone);										//ָ������ĳ�˵�ĳ����ϵ���Ƿ����
	void contacts_find_by_name(string findname);									//����name����ĳ��ϵ�ˣ��������ϵ����Ϣ
	void contacts_find_by_address(string findaddress);								//address����
	void contacts_find_by_tele_num(string findtele_num);							//tele_num����

	//����
	static void contacts_sort_by_name();											//����name����,left==relas.begin(),right==relas.end()								
	static void contacts_sort_by_address();											//����address������������ͬ��

	//ͳ��
	void contacts_statistic_same_address(string add);								//ͳ������˵�������ϵ����ĳ�����ص����������						
	void contacts_statistic_same_finalnum(string num);								//ͳ������˵�������ϵ�˵�β����num�����������

	//��ʾ
	void contacts_pop_out();														//����ó�Ա���е���ϵ����Ϣ
	void show();																	//���������ϵ��֮�����Ϣ

	//���� һЩ��������
	static bool compare_name(relationship& a, relationship& b);
	static bool compare_address(relationship& a, relationship& b);
};

//����ͨѶ¼

list<relationship> create();

//����

void relas_add(list<relationship>& relas);															//����

//ɾ��

void relas_delete(list<relationship>& relas, string delname);										//ɾ

//�޸�

void relas_change_name(list<relationship>& relas, string oldname, string newname);					//���ݾ�������Ѱ�Ҳ������޸�

void relas_change_address(list<relationship>& relas, string name,string newaddress);				//���µ�ַ

void relas_change_tele(list<relationship>& relas, string name,string oldtele,string newtele);		//���������ԭ�������޸��º���

//����

void relas_find_by_name(list<relationship>& relas, string name);

void relas_find_by_address(list<relationship>& relas, string address);

void relas_find_by_tele_num(list<relationship>& relas, string tele);

//����

void sort_by_name(list<relationship>& relas);

void sort_by_address(list<relationship>& relas);

//ͳ��

void statistic_same_address(list<relationship>& relas, string add);

void statistic_same_finalnum(list<relationship>& relas, string num);

//��ʾ
	//���һ����ϵ������������˵���Ϣ(������ĳ�˵���ϵ��)

void pop_out(list<relationship>& relas);

