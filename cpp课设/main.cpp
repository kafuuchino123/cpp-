#include"relationship.h"
#include"file.h"
#include"Menu.h"

/*
									通讯录管理系统
*/

/*
									main函数里是测试用例
*/

#define MAX_NUMS 10

/*
	一些改进
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
	v[0].name = "默认通讯录";

	int rr = 1;
	std::cout << "是否使用默认的通讯录？" << endl;
	std::cout << "->1.是" << endl;
	std::cout << "  2.否(这将会需要你自己创建联系人链表)" << endl;
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
				std::cout << "成功！！！摁下任意键进入系统！！！" << endl;
				_getch();
				m.menu(v[0].lst);
				break;
			}
			else if (rr == 2)
			{
				relas = create();
				v[1].lst = relas;
				v[1].name = "新建通讯录1";
				list<relationship> ::iterator it;
				for (it = relas.begin(); it != relas.end(); it++)
				{
					f.file_write(*it);
				}
				cout << "创建成功!!!" << endl;
				cout << "摁下任意键进入主界面" << endl;
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
			std::cout << "是否使用默认的通讯录？" << endl;
			std::cout << "->1.是" << endl;
			std::cout << "  2.否(这将会需要你自己创建联系人链表)" << endl;
		}
		else if (rr == 2)
		{
			system("cls");
			std::cout << "是否使用默认的通讯录？" << endl;
			std::cout << "  1.是" << endl;
			std::cout << "->2.否(这将会需要你自己创建联系人链表)" << endl;
		}
	}
	

	
	//namedWindow("通讯录管理系统", WINDOW_NORMAL);
	
	

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
	initial_relas(relas, others);													//初始化

	list<relationship> ::iterator it = relas.begin();

	
	string name((*it).getname());													//测试
	string address((*it).getaddress());		
	string tele1((*it).gettele_num_1());
	string tele2((*it).gettele_num_2());
	cout << name << "\n" << address << "\n" << tele1 << "\n" << tele2 << endl;		//done
																					//初始化和get函数没问题
	cout << (*it).getaddress() << endl;
	(*it).address_change("北京");
	cout << (*it).getaddress() << endl;												//成员地址修改没问题
																					//done
	cout << (*it).getname() << endl;
	(*it).name_change("王五");
	cout << (*it).getname() << endl;												//成员名字修改没问题
																					//done
	cout << (*it).gettele_num_1() << " ";
	cout << (*it).gettele_num_2() << endl;											//tele1修改没问题
	(*it).tele_num_1_change("00000000");											//done
	(*it).tele_num_2_change("9876543210");				
	cout << (*it).gettele_num_1() << " ";											//tele2有值时修改没问题							
	cout << (*it).gettele_num_2() << endl;											//done
	

	
	cout << endl;
	list<relationship> test;
	relationship a("李四", "10", "", "上海");
	a.contacts_initial(others);
	test.push_back(a);
	list<relationship> ::iterator i = test.begin();
	cout << (*i).gettele_num_1() << " ";
	cout << (*i).gettele_num_2() << endl;											//tele2无值时不输出
	(*i).tele_num_2_change("new_tele2");											//可以直接change修改或赋值
	cout << (*i).gettele_num_2() << "\n" << endl;									//done
	

	
	cout << endl;																	//成员pop out函数没问题
	(*it).contacts_pop_out();														//done
	

	
	cout << endl;																	//外部pop out函数没问题
	pop_out(relas);																	//done
	

	
	relationship ikun("IKUN", "8848_884866", "", "上海");
	if ((*it).contacts_find(ikun) == true) cout << "有ikun作为联系人！" << endl;	//contacts_find()没问题,成功返回真值
	else cout << "没有" << endl;
	relationship fakeikun("ikun", "123456789", "", "沈阳");
	if (!(*it).contacts_find(fakeikun)) cout << "假ikun" << endl;					//假ikun返回假，没问题
	else cout << "真ikun" << endl;													//done
	
	

	
	relas_find_by_name(relas, "张三");
	relas_find_by_name(relas, "王五");												//relas_find_by_name()没问题
	

	
	relas_find_by_address(relas, "沈阳");
	relas_find_by_address(relas, "北京");											//relas_find_by_address()没问题
	

	
	relas_find_by_tele_num(relas, "1008611");
	relas_find_by_tele_num(relas, "9876543210");
	relas_find_by_tele_num(test, "10");												//relas_find_by_tele_num()没问题
	

	
	(*it).contacts_find_by_name("IKUN");											
	(*it).contacts_find_by_name("KUNKUN");
	(*it).contacts_find_by_address("沈阳");
	(*it).contacts_find_by_address("背景");
	(*it).contacts_find_by_tele_num("9876543210");									//成员函数find()没问题
	(*it).contacts_find_by_tele_num("8848_884866");									//done
	

	
	(*it).contacts_add(a);
	(*i).show();																	//contacts_add()没问题
	(*it).contacts_pop_out();														//done
	

	
	it++;
	relationship b("张三", "1008611", "10086", "沈阳");
	b.contacts_initial(others);
	(*it).contacts_del(relationship("IKUN","8848_884866","","上海"));				//没问题
	(*it).contacts_pop_out();														//done
	
	

	
	(*it).contacts_pop_out();
	(*it).contacts_statistic_same_address("上海");
	(*it).contacts_statistic_same_address("青海");									//done
	
	
	
	(*it).show();
	(*it).contacts_pop_out();
	(*it).contacts_statistic_same_finalnum("333");									//没问题
	
	
	statistic_same_address(relas, "沈阳");
	statistic_same_address(relas, "shenyang");										//没问题

	statistic_same_finalnum(relas, "775");											//没问题

	//sort部分检查

	{
		
		pop_out(relas);
		sort_by_name(relas);															//sort_by_name没问题
		pop_out(relas);
		
		sort_by_address(relas);
		pop_out(relas);																	//sort_by_address没问题
		

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
	relationship a("1", "17840652775", "15078062851", "沈阳");
	relationship b("7", "17840652775", "15078062851", "沈阳");
	relationship c("9", "17840652775", "15078062851", "沈阳");
	relationship d("9", "17840652775", "15078062851", "沈阳");
	relationship e("4", "17840652775", "15078062851", "沈阳");
	relationship f("6", "17840652775", "15078062851", "北京");
	relationship g("2", "17840652775", "15078062851", "北京");
	relationship h("5", "17840652775", "15078062851", "北京");
	relationship i("3", "17840652775", "15078062851", "北京");
	relationship p("蔡徐坤", "17840652775", "null", "鸡窝");

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
	string name="IKUN", t1="8848_884866", t2="", a="上海";
	relationship r1(name, t1, t2, a);
	name = "KUNKUN"; t1 = "789"; t2 = "66666666666"; a = "沈阳";
	relationship r2(name, t1, t2, a);
	others.push_back(r1);
	others.push_back(r2);
	*/
	
	others.push_back(relationship("5_黑粉", "8848_884866", "10086116666", "f"));
	others.push_back(relationship("6_黑粉", "8848_884866", "10086116666", "i"));
	others.push_back(relationship("0_黑粉", "8848_884866", "10086116666", "h"));
	others.push_back(relationship("1_黑粉", "8848_884866", "10086116666", "a"));
	others.push_back(relationship("4_黑粉", "8848_884866", "10086116666", "g"));
	others.push_back(relationship("3_黑粉", "8848_884866", "10086116666", "j"));
	others.push_back(relationship("9_黑粉", "8848_884866", "10086116666", "c"));
	others.push_back(relationship("2_黑粉", "8848_884866", "10086116666", "b"));
	others.push_back(relationship("8_黑粉", "8848_884866", "10086116666", "e"));
	others.push_back(relationship("7_黑粉", "8848_884866", "10086116666", "d"));

}