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

void relationship::tele_num_2_change(string newtele)									//��֤��һ����Ϊ�գ����������뿨��֮ǰ����鿨һ�Ƿ�Ϊ��
{																						//��Ϊ�գ�newtele������һ
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

void relationship::check_tele()															//��Ϊrelationship�кܶຯ����Ĭ�Ͽ�һ�Ǵ��ڵ�
{																						//����check_tele()����ʹ�����ж����û������������Ƿ���
	if (tele_num_1 == "")																//�����ÿ�һ�����
	{																					//�绰������һ������һ���ģ���һΪ�գ��򿨶���Ϊ��
		tele_num_1 = tele_num_2;														//����������һ
		tele_num_2 = "";																//��������Ϊ��
	}
}

void relationship::contacts_change(relationship oldone, relationship contacts)
{
	list<relationship> ::iterator it;	
	for (it = this->contacts.begin(); *it != oldone; it++) {}							//�ҵ�Ҫ�޸ĵ���һ��
	(*it) = contacts;																	//�޸�
}

void relationship::contacts_name_change(string oldname, string newname)
{
	list<relationship> ::iterator it;
	for (it = this->contacts.begin(); (*it).name != oldname; it++) {}					//�ҵ�Ҫ�޸ĵ���һ��
	(*it).name = newname;																//�޸�
}

void relationship::contacts_tele_num_1_change(string name, string newtele)
{
	list<relationship> ::iterator it;
	for (it = this->contacts.begin(); (*it).name != name; it++) {}						//�ҵ�Ҫ�޸ĵ���һ��
	(*it).tele_num_1 = newtele;																//�޸�
}

void relationship::contacts_tele_num_2_change(string name, string newtele)
{
	list<relationship> ::iterator it;
	for (it = this->contacts.begin(); (*it).name != name; it++) {}						//�ҵ�Ҫ�޸ĵ���һ��
	(*it).tele_num_2 = newtele;																//�޸�
}

void relationship::contacts_address_change(string name, string newaddress)
{
	list<relationship> ::iterator it;
	for (it = this->contacts.begin(); (*it).name != name; it++) {}						//�ҵ�Ҫ�޸ĵ���һ��
	(*it).address = newaddress;																//�޸�
}

bool relationship::contacts_find(relationship findone)
{
	list <relationship> ::iterator it;
	for (it = this->contacts.begin(); it != this->contacts.end(); it++)
	{
		if ((*it) == findone)
		{
			return true;																//�ҵ�������
			break;
		}
	}
	if (it == this->contacts.end())
	{
		return false;																	//���򷵻ؼ�
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
		cout << "δ�ҵ���Ϊ " << findname << " ����ϵ�ˡ�" << endl;
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
		cout << "δ�ҵ���ַΪ " << findaddress << " ����ϵ��" << endl;
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
		cout << "δ�ҵ��绰����Ϊ " << findtele_num << " ����ϵ��" << endl;
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
	cout << "����������ĵ�ַ���� " << name << " ����ϵ���У����ַ " << add << " ��ͬ�������� " << cnt << " ��" << endl;
}

void relationship::contacts_statistic_same_finalnum(string num)
{
	system("cls");

	int cnt = 0;
	list<relationship> ::iterator it;
	for (it = this->contacts.begin(); it != this->contacts.end(); it++)
	{
		if ((*it).gettele_num_1().length() < 3 and (*it).gettele_num_2().length() < 3) continue;
		string finalstr = (*it).gettele_num_1().substr((*it).gettele_num_1().length() - 3);		//��ȡ��һ����λβ��
		if (finalstr == num)
		{
			cnt++;
			continue;
		}
		else if ((*it).gettele_num_2() != "")
		{
			finalstr = (*it).gettele_num_2().substr((*it).gettele_num_2().length() - 3);		//��ȡ��������λ
			if (finalstr == num)
			{
				cnt++;
				continue;
			}
		}
	}
	if (cnt == 0)
	{
		cout << "û���ҵ�β��Ϊ " << num << " ����ϵ��" << endl;
	}
	else
	{
		cout << "�����������β�ţ��� " << name << " ����ϵ���У���β�� " << num << " ��ͬ�������� " << cnt << " ��" << endl;
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
	cout << "����������ĵ�ַ�������ͨѶ¼�У����ַ " << add << " ��ͬ�������� " << cnt << " ��" << endl;
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
		cout << "δ�ҵ�β��Ϊ " << num << " ����ϵ��" << endl;
	}
	else
	{
		cout << "�����������β�ţ������ͨѶ¼�У���β�� " << num << " ��ͬ�������� " << cnt << " ��" << endl;
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
	contacts.push_back(addone);															//push_back����
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
	cout << "����ͨѶ¼" << endl;
	cout << "�����ΰ��� ���� ��ַ ��һ ���� ��˳���������" << endl;
	cout << "�����˳��������������ĸ�\"null\"" << endl;
	list<relationship> newlist;
	while (true)
	{
		/*system("cls");
		cout << "����ͨѶ¼" << endl;
		cout << "�����ΰ��� ���� ��ַ ��һ ���� ��˳���������" << endl;
		cout << "�������β����\"esc\"�����˳�����" << endl;*/

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
			std::cout << "��ʽ����" << endl;
			std::cout << "���ٳ���һ��" << endl;
			string newname, newaddress, tele1, tele2;
			cin >> newname;
			cin >> newaddress;
			cin >> tele1;
			cin >> tele2;
		}
		if (not(ch3 >= '0' and ch3 <= '9') and ch3 != 'n')
		{
			std::cout << "��ʽ����" << endl;
			std::cout << "���ٳ���һ��" << endl;
			string newname, newaddress, tele1, tele2;
			cin >> newname;
			cin >> newaddress;
			cin >> tele1;
			cin >> tele2;
		}



		if (newname == newaddress and tele1 == tele2 and newname == "null" and tele1 == "null") break;
		relationship newone(newname, tele1, tele2, newaddress);
		/*system("cls");
		cout << "�Ƿ�������˳�������\"esc\"��\n�����������������" << endl;
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

	cout << "������������������ַ����һ������\n�����������ڣ�����\"null\"" << endl;
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
	if (is_del == 0) cout << "δ�ҵ�����ϵ��" << endl;
	else if (is_del == 1)cout << "ɾ���ɹ�!!!" << endl;

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
		cout << "δ�ҵ�����ϵ��" << endl;
	}
	else
	{
		(*it).name_change(newname);
		cout << "�޸ĳɹ�!!!" << endl;
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
		cout << "δ�ҵ�����ϵ��" << endl;
	}
	else
	{
		(*it).address_change(newaddress);
		cout << "�޸ĳɹ�!!!" << endl;
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
		cout << "δ�ҵ�����ϵ��" << endl;
	}
	else
	{
		cout << "�޸ĳɹ�!!!" << endl;
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
			cout << "����ϵ�˲�û�����ԭ���룬�ǲ�������ˣ�" << endl;
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
		cout << "δ�ҵ���Ϊ " << name << " ����ϵ��" << endl;
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
		cout << "δ�ҵ���ַΪ " << address << " ����ϵ��" << endl;
	}
}

void relas_find_by_tele_num(list<relationship>& relas, string tele)
{
	system("cls");

	list<relationship> ::iterator it;
	for (it = relas.begin(); it != relas.end(); it++)
	{
		if ((*it).gettele_num_1() == tele) 												//����һ��Ҫ�ҵĺ�����ͬ���������˵�������Ϣ������������ϵ�ˣ�
		{
			cout << *it << endl;
			break;
		}
		else if ((*it).gettele_num_2() != "" and (*it).gettele_num_2() == tele)			//��һ��ͬ���Ϳ��Ƿ��п����������������򿴿�����Ҫ�ҵĺ����Ƿ�һ��
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
	if (r.tele_num_2 != "") res << "������"<<r.name << "\n" << "�����أ�"<<r.address << "\n" << "��һ��"<<r.tele_num_1 << "\n" << "������"<<r.tele_num_2 << "\n";
																						//��������Ϊ�գ����������ڣ�����������������
	else res << "������" << r.name << "\n" << "�����أ�" << r.address << "\n" << "��һ��" << r.tele_num_1 << "\n";
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