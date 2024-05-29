#include "relationship.h"

void relationship::contacts_initial(list<relationship>& re)
{
	contacts = re;
}

void relationship::name_change(string newname)
{
	name = newname;
}

void relationship::tele_num_1_change(string newtele)
{
	tele_num_1 = newtele;
}

void relationship::tele_num_2_change(string newtele)									//保证卡一不能为空，所以在填入卡二之前，检查卡一是否为空
{																						//若为空，newtele赋给卡一
	if (newtele=="null") 
	{
		tele_num_2 = "";
	}
	else if (tele_num_1 == "" or tele_num_1 == "null")
	{
		tele_num_1 = newtele;
	}
	else
	{
		tele_num_2 = newtele;
	}
		
}

void relationship::address_change(string newaddress)
{
	address = newaddress;
}

void relationship::check_tele()															//因为relationship中很多函数都默认卡一是存在的
{																						//所以check_tele()函数使用来判断在用户操作过程中是否有
	if (tele_num_1 == "")																//操作让卡一变空了
	{																					//电话号码是一定会有一个的，卡一为空，则卡二不为空
		tele_num_1 = tele_num_2;														//卡二赋给卡一
		tele_num_2 = "";																//卡二设置为空
	}
}

void relationship::contacts_change(relationship oldone, relationship contacts)
{
	list<relationship> ::iterator it;	
	for (it = this->contacts.begin(); *it != oldone; it++) {}							//找到要修改的哪一个
	(*it) = contacts;																	//修改
}

void relationship::contacts_name_change(string oldname, string newname)
{
	list<relationship> ::iterator it;
	for (it = this->contacts.begin(); (*it).name != oldname; it++) {}					//找到要修改的哪一个
	(*it).name = newname;																//修改
}

void relationship::contacts_tele_num_1_change(string name, string newtele)
{
	list<relationship> ::iterator it;
	for (it = this->contacts.begin(); (*it).name != name; it++) {}						//找到要修改的哪一个
	(*it).tele_num_1 = newtele;																//修改
}

void relationship::contacts_tele_num_2_change(string name, string newtele)
{
	list<relationship> ::iterator it;
	for (it = this->contacts.begin(); (*it).name != name; it++) {}						//找到要修改的哪一个
	(*it).tele_num_2 = newtele;																//修改
}

void relationship::contacts_address_change(string name, string newaddress)
{
	list<relationship> ::iterator it;
	for (it = this->contacts.begin(); (*it).name != name; it++) {}						//找到要修改的哪一个
	(*it).address = newaddress;																//修改
}

bool relationship::contacts_find(relationship findone)
{
	list <relationship> ::iterator it;
	for (it = this->contacts.begin(); it != this->contacts.end(); it++)
	{
		if ((*it) == findone)
		{
			return true;																//找到返回真
			break;
		}
	}
	if (it == this->contacts.end())
	{
		return false;																	//否则返回假
	}
}

void relationship::contacts_find_by_name(string findname) 
{
	system("cls");

	list<relationship>::iterator it;
	for (it = this->contacts.begin(); it != this->contacts.end(); it++)
	{
		if ((*it).getname() == findname)
		{
			cout << *it << endl;
			break;
		}
	}
	if (it == this->contacts.end()) 
	{
		cout << "未找到名为 " << findname << " 的联系人。" << endl;
	}
}


void relationship::contacts_find_by_address(string findaddress)
{
	system("cls");

	list<relationship> ::iterator it;
	for (it = this->contacts.begin(); it != contacts.end(); it++)
	{
		if ((*it).getaddress() == findaddress)
		{
			cout << *it << endl;
			break;
		}
	}
	if (it == this->contacts.end())
	{
		cout << "未找到地址为 " << findaddress << " 的联系人" << endl;
	}
}

void relationship::contacts_find_by_tele_num(string findtele_num)
{
	system("cls");

	list<relationship>::iterator it;
	for (it = this->contacts.begin(); it != this->contacts.end(); it++)
	{
		if ((*it).gettele_num_1() == findtele_num)
		{
			cout << *it << endl;
			break;
		}
		else if ((*it).gettele_num_2() != "" and (*it).gettele_num_2() == findtele_num)
		{
			cout << *it << endl;
			break;
		}
	}
	if (it == this->contacts.end())
	{
		cout << "未找到电话号码为 " << findtele_num << " 的联系人" << endl;
	}
}

void relationship::contacts_sort_by_name()
{
	contacts.sort(relationship::compare_name);
}

void relationship::contacts_sort_by_address()
{
	contacts.sort(relationship::compare_address);
}

void relationship::contacts_statistic_same_address(string add)
{
	system("cls");

	int cnt = 0;
	list<relationship> ::iterator it;
	for (it = this->contacts.begin(); it != this->contacts.end(); it++)
	{
		if ((*it).address == add) cnt++;
	}
	cout << "根据您输入的地址，在 " << name << " 的联系人中，与地址 " << add << " 相同的人数有 " << cnt << " 人" << endl;
}

void relationship::contacts_statistic_same_finalnum(string num)
{
	system("cls");

	int cnt = 0;
	list<relationship> ::iterator it;
	for (it = this->contacts.begin(); it != this->contacts.end(); it++)
	{
		if ((*it).gettele_num_1().length() < 3 and (*it).gettele_num_2().length() < 3) continue;
		string finalstr = (*it).gettele_num_1().substr((*it).gettele_num_1().length() - 3);		//读取卡一后三位尾号
		if (finalstr == num)
		{
			cnt++;
			continue;
		}
		else if ((*it).gettele_num_2() != "")
		{
			finalstr = (*it).gettele_num_2().substr((*it).gettele_num_2().length() - 3);		//读取卡二后三位
			if (finalstr == num)
			{
				cnt++;
				continue;
			}
		}
	}
	if (cnt == 0)
	{
		cout << "没有找到尾号为 " << num << " 的联系人" << endl;
	}
	else
	{
		cout << "根据您输入的尾号，在 " << name << " 的联系人中，与尾号 " << num << " 相同的人数有 " << cnt << " 人" << endl;
	}

}

void relationship::contacts_pop_out()
{
	system("cls");

	list<relationship> ::iterator it;
	for (it = this->contacts.begin(); it != this->contacts.end(); it++)
	{
		cout << *it;
		cout << "\n";
	}
}

void relationship::show()
{
	system("cls");

	cout << name << "\n" << address << "\n" << tele_num_1 << "\n" << tele_num_2 << endl;
}

bool relationship::compare_name(relationship& a, relationship& b)
{
	return (a.getname()) < (b.getname());
}

bool relationship::compare_address(relationship& a, relationship& b)
{
	return (a.getaddress()) < (b.getaddress());
}

void sort_by_name(list<relationship>& relas)
{
	relas.sort([](relationship& a, relationship& b)
		{
			return a.getname() < b.getname();
		});
}

void sort_by_address(list<relationship>& relas)
{
	relas.sort([](relationship& a, relationship& b)
		{
			return a.getaddress() < b.getaddress();
		});
}

void statistic_same_address(list<relationship>& relas, string add)
{
	system("cls");

	int cnt = 0;
	list<relationship> ::iterator it;
	for (it = relas.begin(); it != relas.end(); it++)
	{
		if ((*it).getaddress() == add) cnt++;
	}
	cout << "根据您输入的地址，在这份通讯录中，与地址 " << add << " 相同的人数有 " << cnt << " 人" << endl;
}

void statistic_same_finalnum(list<relationship>& relas, string num)
{
	system("cls");

	int cnt = 0;
	list<relationship> ::iterator it;
	for (it = relas.begin(); it != relas.end(); it++)
	{
		if ((*it).gettele_num_1().length() < 3 and (*it).gettele_num_2().length()<3) continue;
		string finalstr = (*it).gettele_num_1().substr((*it).gettele_num_1().length() - 3);
		if (finalstr == num)
		{
			cnt++;
		}
		else if ((*it).gettele_num_2() != "")
		{
			finalstr = (*it).gettele_num_2().substr((*it).gettele_num_2().length() - 3);
			if (finalstr == num)
			{
				cnt++;
			}
		}

	}
	if (cnt == 0)
	{
		cout << "未找到尾号为 " << num << " 的联系人" << endl;
	}
	else
	{
		cout << "根据您输入的尾号，在这份通讯录中，与尾号 " << num << " 相同的人数有 " << cnt << " 人" << endl;
	}
}

void pop_out(list<relationship>& relas)
{
	system("cls");

	list<relationship> ::iterator it;
	for (it = relas.begin(); it != relas.end(); it++)
	{
		cout << *it;
		cout << endl;
	}
}


void relationship::contacts_add(relationship addone)
{
	contacts.push_back(addone);															//push_back增加
}

void relationship::contacts_del(relationship delone)
{
	list<relationship> ::iterator it = this->contacts.begin();
	while (it != this->contacts.end())
	{
		if (*it == delone)
		{
			this->contacts.erase(it++);
		}
		else it++;
	}
}

list<relationship> create()
{
	system("cls");
	cout << "建立通讯录" << endl;
	cout << "请依次按照 姓名 地址 卡一 卡二 的顺序进行输入" << endl;
	cout << "若欲退出创建，请输入四个\"null\"" << endl;
	list<relationship> newlist;
	while (true)
	{
		/*system("cls");
		cout << "建立通讯录" << endl;
		cout << "请依次按照 姓名 地址 卡一 卡二 的顺序进行输入" << endl;
		cout << "在输入结尾摁下\"esc\"键以退出创建" << endl;*/

		string newname, newaddress, tele1, tele2;
		cin >> newname;
		cin >> newaddress;
		cin >> tele1;
		cin >> tele2;

		char ch1 = newaddress[0];
		char ch2 = tele1[0];
		char ch3 = tele2[0];
		if (not(ch2 >= '0' and ch2 <= '9'))
		{
			std::cout << "格式错误" << endl;
			std::cout << "请再尝试一遍" << endl;
			string newname, newaddress, tele1, tele2;
			cin >> newname;
			cin >> newaddress;
			cin >> tele1;
			cin >> tele2;
		}
		if (not(ch3 >= '0' and ch3 <= '9') and ch3 != 'n')
		{
			std::cout << "格式错误" << endl;
			std::cout << "请再尝试一遍" << endl;
			string newname, newaddress, tele1, tele2;
			cin >> newname;
			cin >> newaddress;
			cin >> tele1;
			cin >> tele2;
		}



		if (newname == newaddress and tele1 == tele2 and newname == "null" and tele1 == "null") break;
		relationship newone(newname, tele1, tele2, newaddress);
		/*system("cls");
		cout << "是否继续？退出请摁下\"esc\"键\n否则摁下其他任意键" << endl;
		char quit = _getch();
		if (quit == 27)break;
		else if (quit == 10 or quit == 13)
			system("cls");*/
		newlist.push_back(newone);
	}
	return newlist;
}

void relas_add(list<relationship>& relas)
{
	system("cls");

	cout << "请依次输入姓名，地址，卡一，卡二\n若卡二不存在，输入\"null\"" << endl;
	string newname, newaddress, newtele1, newtele2;
	cin >> newname >> newaddress >> newtele1 >> newtele2;
	relationship newone(newname, newaddress, newtele1, newtele2);
	relas.push_back(newone);
}

void relas_delete(list<relationship>& relas, string delname)
{
	int is_del = 0;
	list<relationship>::iterator it;
	for (it = relas.begin(); it != relas.end();)
	{
		if ((*it).getname() == delname)
		{
			relas.erase(it++);
			is_del = 1;
		}
		else it++;
	}
	if (is_del == 0) cout << "未找到该联系人" << endl;
	else if (is_del == 1)cout << "删除成功!!!" << endl;

}

void relas_change_name(list<relationship>& relas, string oldname, string newname)
{
	system("cls");

	list<relationship> ::iterator it;
	for (it = relas.begin(); it != relas.end(); it++)
	{
		if ((*it).getname() == oldname) break;
	}
	if (it == relas.end())
	{
		cout << "未找到该联系人" << endl;
	}
	else
	{
		(*it).name_change(newname);
		cout << "修改成功!!!" << endl;
	}
}

void relas_change_address(list<relationship>& relas,string name, string newaddress)
{
	system("cls");

	list<relationship>::iterator it;
	for (it = relas.begin(); it != relas.end(); it++)
	{
		if ((*it).getname() == name) break;
	}
	if (it == relas.end())
	{
		cout << "未找到该联系人" << endl;
	}
	else
	{
		(*it).address_change(newaddress);
		cout << "修改成功!!!" << endl;
	}
}

void relas_change_tele(list<relationship>& relas,string name, string oldtele,string newtele)
{
	system("cls");

	list<relationship>::iterator it;
	for (it = relas.begin(); it != relas.end(); it++)
	{
		if ((*it).getname() == name)break;
	}
	if (it == relas.end())
	{
		cout << "未找到该联系人" << endl;
	}
	else
	{
		cout << "修改成功!!!" << endl;
		if ((*it).gettele_num_1() == oldtele)
		{
			(*it).tele_num_1_change(newtele);
		}
		else if ((*it).gettele_num_2() == oldtele)
		{
			(*it).tele_num_2_change(newtele);
		}
		else
		{
			cout << "该联系人并没有这个原号码，是不是输错了？" << endl;
		}
	}
}

void relas_find_by_name(list<relationship>& relas, string name)
{
	system("cls");

	list<relationship>::iterator it;
	for (it = relas.begin(); it != relas.end(); it++)
	{
		if ((*it).getaddress() == name)
		{
			cout << *it << endl;
			break;
		}
	}
	if (it == relas.end())
	{
		cout << "未找到名为 " << name << " 的联系人" << endl;
	}
}

void relas_find_by_address(list<relationship>& relas, string address)
{
	system("cls");

	list<relationship>::iterator it;
	for (it = relas.begin(); it != relas.end(); it++)
	{
		if ((*it).getaddress() == address)
		{
			cout << *it << endl;
			break;
		}
	}
	if (it == relas.end())
	{
		cout << "未找到地址为 " << address << " 的联系人" << endl;
	}
}

void relas_find_by_tele_num(list<relationship>& relas, string tele)
{
	system("cls");

	list<relationship> ::iterator it;
	for (it = relas.begin(); it != relas.end(); it++)
	{
		if ((*it).gettele_num_1() == tele) 												//若卡一与要找的号码相同，输出这个人的所有信息（除了他的联系人）
		{
			cout << *it << endl;
			break;
		}
		else if ((*it).gettele_num_2() != "" and (*it).gettele_num_2() == tele)			//卡一不同，就看是否有卡二，若卡二存在则看卡二与要找的号码是否一致
		{
			cout << *it << endl;
			break;
		}
	}
}

string relationship::getname()
{
	return name;
}

string relationship::getaddress()
{
	return address;
}

string relationship::gettele_num_1()
{
	return tele_num_1;
}

string relationship::gettele_num_2()
{
	return tele_num_2;
}

list<relationship> relationship::getcontacts()
{
	list<relationship> newlist = this->contacts;
	return newlist;
}

ostream& operator<<(ostream& res, const relationship& r)
{
	if (r.tele_num_2 != "") res << "姓名："<<r.name << "\n" << "归属地："<<r.address << "\n" << "卡一："<<r.tele_num_1 << "\n" << "卡二："<<r.tele_num_2 << "\n";
																						//卡二允许为空，若卡二存在，输出卡二，否则不输出
	else res << "姓名：" << r.name << "\n" << "归属地：" << r.address << "\n" << "卡一：" << r.tele_num_1 << "\n";
	return res;
}

bool relationship::operator!=(relationship& other)
{
	if (other.name == name and other.address == address and other.tele_num_1 == tele_num_1 and tele_num_2 == tele_num_2) return false;
	else return true;
}

bool relationship::operator==(relationship& other)
{
	if (other.name == name and other.address == address and other.tele_num_1 == tele_num_1 and tele_num_2 == tele_num_2) return true;
	else return false;
}