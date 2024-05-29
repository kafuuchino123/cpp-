#include"relationship.h"
#include"file.h"
#include"Menu.h"

/*
									ͨѶ¼����ϵͳ
*/

/*
									main�������ǲ�������
*/

#define MAX_NUMS 10

/*
	һЩ�Ľ�
*/

class Vec {
public:
	list<relationship> lst;
	string name;
};

vector<Vec> v(10);

list<relationship>
relationship::contacts;
file f;



void initial_relas(list<relationship>& relas, list<relationship>& others);
void initial_others(list<relationship>& others);

int main()
{
	Menu m;

	list<relationship> relas;
	list<relationship> others;

	initial_others(others);
	initial_relas(relas, others);
	v[0].lst = relas;
	v[0].name = "Ĭ��ͨѶ¼";

	int rr = 1;
	std::cout << "�Ƿ�ʹ��Ĭ�ϵ�ͨѶ¼��" << endl;
	std::cout << "->1.��" << endl;
	std::cout << "  2.��(�⽫����Ҫ���Լ�������ϵ������)" << endl;
	while (true)
	{
		char cf = _getch();
		if (cf == UP)rr--;
		else if (cf == DOWN)rr++;
		else if (cf == 10 or 13)
		{
			if (rr == 1)
			{
				system("cls");
				std::cout << "�ɹ��������������������ϵͳ������" << endl;
				_getch();
				m.menu(v[0].lst);
				break;
			}
			else if (rr == 2)
			{
				relas = create();
				v[1].lst = relas;
				v[1].name = "�½�ͨѶ¼1";
				list<relationship> ::iterator it;
				for (it = relas.begin(); it != relas.end(); it++)
				{
					f.file_write(*it);
				}
				cout << "�����ɹ�!!!" << endl;
				cout << "�������������������" << endl;
				_getch();
				m.menu(v[1].lst);
				break;
			}
		}
		if (rr == 3)rr = 1;
		if (rr == 0)rr = 2;
		if (rr == 1)
		{
			system("cls");
			std::cout << "�Ƿ�ʹ��Ĭ�ϵ�ͨѶ¼��" << endl;
			std::cout << "->1.��" << endl;
			std::cout << "  2.��(�⽫����Ҫ���Լ�������ϵ������)" << endl;
		}
		else if (rr == 2)
		{
			system("cls");
			std::cout << "�Ƿ�ʹ��Ĭ�ϵ�ͨѶ¼��" << endl;
			std::cout << "  1.��" << endl;
			std::cout << "->2.��(�⽫����Ҫ���Լ�������ϵ������)" << endl;
		}
	}
	

	
	//namedWindow("ͨѶ¼����ϵͳ", WINDOW_NORMAL);
	
	

	/*
	
	file f;
	for (int i = 0; i < MAX_NUMS-8; i++)
	{
		string name;
		string tele1;
		string tele2;
		string address;
		cin >> name >> address >> tele1 >> tele2;
		relationship a(name, tele1, tele2, address);
		relas.push_back(a);
		f.file_write(a);
	}
	*/

	/*
	list<relationship> relas;
	list<relationship> others;
	initial_others(others);
	initial_relas(relas, others);													//��ʼ��

	list<relationship> ::iterator it = relas.begin();

	
	string name((*it).getname());													//����
	string address((*it).getaddress());		
	string tele1((*it).gettele_num_1());
	string tele2((*it).gettele_num_2());
	cout << name << "\n" << address << "\n" << tele1 << "\n" << tele2 << endl;		//done
																					//��ʼ����get����û����
	cout << (*it).getaddress() << endl;
	(*it).address_change("����");
	cout << (*it).getaddress() << endl;												//��Ա��ַ�޸�û����
																					//done
	cout << (*it).getname() << endl;
	(*it).name_change("����");
	cout << (*it).getname() << endl;												//��Ա�����޸�û����
																					//done
	cout << (*it).gettele_num_1() << " ";
	cout << (*it).gettele_num_2() << endl;											//tele1�޸�û����
	(*it).tele_num_1_change("00000000");											//done
	(*it).tele_num_2_change("9876543210");				
	cout << (*it).gettele_num_1() << " ";											//tele2��ֵʱ�޸�û����							
	cout << (*it).gettele_num_2() << endl;											//done
	

	
	cout << endl;
	list<relationship> test;
	relationship a("����", "10", "", "�Ϻ�");
	a.contacts_initial(others);
	test.push_back(a);
	list<relationship> ::iterator i = test.begin();
	cout << (*i).gettele_num_1() << " ";
	cout << (*i).gettele_num_2() << endl;											//tele2��ֵʱ�����
	(*i).tele_num_2_change("new_tele2");											//����ֱ��change�޸Ļ�ֵ
	cout << (*i).gettele_num_2() << "\n" << endl;									//done
	

	
	cout << endl;																	//��Աpop out����û����
	(*it).contacts_pop_out();														//done
	

	
	cout << endl;																	//�ⲿpop out����û����
	pop_out(relas);																	//done
	

	
	relationship ikun("IKUN", "8848_884866", "", "�Ϻ�");
	if ((*it).contacts_find(ikun) == true) cout << "��ikun��Ϊ��ϵ�ˣ�" << endl;	//contacts_find()û����,�ɹ�������ֵ
	else cout << "û��" << endl;
	relationship fakeikun("ikun", "123456789", "", "����");
	if (!(*it).contacts_find(fakeikun)) cout << "��ikun" << endl;					//��ikun���ؼ٣�û����
	else cout << "��ikun" << endl;													//done
	
	

	
	relas_find_by_name(relas, "����");
	relas_find_by_name(relas, "����");												//relas_find_by_name()û����
	

	
	relas_find_by_address(relas, "����");
	relas_find_by_address(relas, "����");											//relas_find_by_address()û����
	

	
	relas_find_by_tele_num(relas, "1008611");
	relas_find_by_tele_num(relas, "9876543210");
	relas_find_by_tele_num(test, "10");												//relas_find_by_tele_num()û����
	

	
	(*it).contacts_find_by_name("IKUN");											
	(*it).contacts_find_by_name("KUNKUN");
	(*it).contacts_find_by_address("����");
	(*it).contacts_find_by_address("����");
	(*it).contacts_find_by_tele_num("9876543210");									//��Ա����find()û����
	(*it).contacts_find_by_tele_num("8848_884866");									//done
	

	
	(*it).contacts_add(a);
	(*i).show();																	//contacts_add()û����
	(*it).contacts_pop_out();														//done
	

	
	it++;
	relationship b("����", "1008611", "10086", "����");
	b.contacts_initial(others);
	(*it).contacts_del(relationship("IKUN","8848_884866","","�Ϻ�"));				//û����
	(*it).contacts_pop_out();														//done
	
	

	
	(*it).contacts_pop_out();
	(*it).contacts_statistic_same_address("�Ϻ�");
	(*it).contacts_statistic_same_address("�ຣ");									//done
	
	
	
	(*it).show();
	(*it).contacts_pop_out();
	(*it).contacts_statistic_same_finalnum("333");									//û����
	
	
	statistic_same_address(relas, "����");
	statistic_same_address(relas, "shenyang");										//û����

	statistic_same_finalnum(relas, "775");											//û����

	//sort���ּ��

	{
		
		pop_out(relas);
		sort_by_name(relas);															//sort_by_nameû����
		pop_out(relas);
		
		sort_by_address(relas);
		pop_out(relas);																	//sort_by_addressû����
		

		(*it).contacts_sort_by_name();
		(*it).contacts_pop_out();
		(*it).contacts_sort_by_address();
		(*it).contacts_pop_out();

	}

	*/
	return 0;
}

void initial_relas(list<relationship> &relas, list<relationship>& others)
{
	relationship a("1", "17840652775", "15078062851", "����");
	relationship b("7", "17840652775", "15078062851", "����");
	relationship c("9", "17840652775", "15078062851", "����");
	relationship d("9", "17840652775", "15078062851", "����");
	relationship e("4", "17840652775", "15078062851", "����");
	relationship f("6", "17840652775", "15078062851", "����");
	relationship g("2", "17840652775", "15078062851", "����");
	relationship h("5", "17840652775", "15078062851", "����");
	relationship i("3", "17840652775", "15078062851", "����");
	relationship p("������", "17840652775", "null", "����");

	a.contacts_initial(others);
	b.contacts_initial(others);
	c.contacts_initial(others);
	d.contacts_initial(others);
	e.contacts_initial(others);
	f.contacts_initial(others);
	g.contacts_initial(others);
	h.contacts_initial(others);
	i.contacts_initial(others);
	p.contacts_initial(others);


	relas.push_back(a);
	relas.push_back(b);
	relas.push_back(c);
	relas.push_back(d);
	relas.push_back(e);
	relas.push_back(f);
	relas.push_back(g);
	relas.push_back(h);
	relas.push_back(i);
	relas.push_back(p);

}

void initial_others(list<relationship>& others)
{
	/*
	string name="IKUN", t1="8848_884866", t2="", a="�Ϻ�";
	relationship r1(name, t1, t2, a);
	name = "KUNKUN"; t1 = "789"; t2 = "66666666666"; a = "����";
	relationship r2(name, t1, t2, a);
	others.push_back(r1);
	others.push_back(r2);
	*/
	
	others.push_back(relationship("5_�ڷ�", "8848_884866", "10086116666", "f"));
	others.push_back(relationship("6_�ڷ�", "8848_884866", "10086116666", "i"));
	others.push_back(relationship("0_�ڷ�", "8848_884866", "10086116666", "h"));
	others.push_back(relationship("1_�ڷ�", "8848_884866", "10086116666", "a"));
	others.push_back(relationship("4_�ڷ�", "8848_884866", "10086116666", "g"));
	others.push_back(relationship("3_�ڷ�", "8848_884866", "10086116666", "j"));
	others.push_back(relationship("9_�ڷ�", "8848_884866", "10086116666", "c"));
	others.push_back(relationship("2_�ڷ�", "8848_884866", "10086116666", "b"));
	others.push_back(relationship("8_�ڷ�", "8848_884866", "10086116666", "e"));
	others.push_back(relationship("7_�ڷ�", "8848_884866", "10086116666", "d"));

}