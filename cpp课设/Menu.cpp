#include "Menu.h"

void Menu::linkman_manage(list<relationship>& relas)
{
	system("cls");
	std::cout << "����Ҫ��ʲô?" << std::endl;
	int a = 1;
	std::cout << "->1.���" << endl;
	std::cout << "  2.ɾ��" << endl;
	std::cout << "  3.�޸�" << endl;
	std::cout << "  4.����������" << endl;
	while (true)
	{
		char c = _getch();
		if (c == UP) a--;
		else if (c == DOWN)a++;
		else if (c == 10 or c == 13)
		{
			if (a == 4)
			{
				menu(relas);
			}
			else if (a == 1)
			{
				system("cls");
				int i = 1;
				std::cout << "->1.��ĳ�˵�ͨѶ¼����ӳ�Ա" << endl;
				std::cout << "  2.��ӳ�Ա" << endl;
				std::cout << "  3.������һ������" << endl;
				while (true)
				{
					char r = _getch();
					if (r == UP)i--;
					else if (r == DOWN)i++;
					else if (r == 13 or r == 10)
					{
						if (i==3)
						{
							linkman_manage(relas);
						}
						else if (i == 1)
						{
							system("cls");
							std::cout << "����Ҫ��˭��ͨѶ¼����ӣ�������������" << endl;
							string ownername;
							std::cin >> ownername;
							list<relationship>::iterator it;
							for (it = relas.begin(); it != relas.end(); it++)
							{
								if ((*it).getname() == ownername) break;
							}
							if (it == relas.end())
							{
								system("cls");
								std::cout << "���Ҳ�����Ҫ��ͨѶ¼��ӳ�Ա����ϵ��" << endl;
								std::cout << "�������������������" << endl;
								_getch();
								menu(relas);
							}

							std::cout << "��������ӵĳ�Ա����Ϣ\n��ʽ:���� ������ ��һ ����\nP.S. ��û�п��������ڿ�����λ������\"null\"" << endl;
							string newname, newaddress, newtele1, newtele2;
							std::cin >> newname;
							std::cin >> newaddress;
							std::cin >> newtele1;
							std::cin >> newtele2;
							relationship newone(newname, newtele1, newtele2, newaddress);
							system("cls");
							(*it).contacts_add(newone);
							std::cout << "�ɹ�!!!\n�������������������" << endl;
							_getch();
							menu(relas);
							
						}
						else if (i == 2)
						{
							system("cls");
							std::cout << "��������ӵĳ�Ա����Ϣ\n��ʽ:���� ������ ��һ ����\nP.S. ��û�п��������ڿ�����λ������\"null\"" << endl;
							string newname, newaddress, newtele1, newtele2;
							std::cin >> newname;
							std::cin >> newaddress;
							std::cin >> newtele1;
							std::cin >> newtele2;
							relationship newone(newname, newtele1, newtele2, newaddress);
							relas.push_back(newone);
							file f;
							f.file_write(newone);
							std::cout << "�ɹ�!!!\n�������������������" << endl;
							_getch();
							menu(relas);
						}
					}
					if (i == 0)i = 3;
					if (i == 4)i = 1;
					switch (i)
					{
					case 1:
						system("cls");
						std::cout << "->1.��ĳ�˵�ͨѶ¼����ӳ�Ա" << endl;
						std::cout << "  2.��ӳ�Ա" << endl;
						std::cout << "  3.������һ������" << endl;
						break;

					case 2:
						system("cls");
						std::cout << "  1.��ĳ�˵�ͨѶ¼����ӳ�Ա" << endl;
						std::cout << "->2.��ӳ�Ա" << endl;
						std::cout << "  3.������һ������" << endl; 
						break;

					case 3:
						system("cls");
						std::cout << "  1.��ĳ�˵�ͨѶ¼����ӳ�Ա" << endl;
						std::cout << "  2.��ӳ�Ա" << endl;
						std::cout << "->3.������һ������" << endl; 
						break;
					}
				}
			}
			else if (a == 2)
			{
				system("cls");
				int i = 1;
				std::cout << "->1.��ĳ�˵�ͨѶ¼��ɾ����Ա" << endl;
				std::cout << "  2.ɾ����Ա" << endl;
				std::cout << "  3.������һ������" << endl;
				while (true)
				{
					char r = _getch();
					if (r == UP)i--;
					else if (r == DOWN)i++;
					else if (r == 13 or i == 10)
					{
						if (i == 3)
						{
							linkman_manage(relas);
						}
						else if (i == 1)
						{
							system("cls");
							std::cout << "����Ҫ��˭��ͨѶ¼��ɾ����Ա��������������" << endl;
							string ownername;
							std::cin >> ownername;

							list<relationship>::iterator it;
							for (it = relas.begin(); it != relas.end(); it++)
							{
								if ((*it).getname() == ownername) break;
							}
							if (it == relas.end())
							{
								system("cls");
								std::cout << "�Ҳ�������Ҫɾ����ϵ�˵��˵�����" << endl;
								std::cout << "�������������������" << endl;
								_getch();
								menu(relas);
							}
							std::cout << "��������Ҫɾ���ĳ�Ա������" << endl;
							string delname;
							std::cin >> delname;
							
							
							{
								list<relationship>::iterator in;
								for (in = (*it).getcontacts().begin(); in != (*it).getcontacts().end(); in++)
								{
									if ((*in).getname() == delname) break;
								}
								if (in == (*it).getcontacts().end())
								{
									system("cls");
									std::cout << "�Ҳ�������Ҫɾ����ϵ�˵��˵�����" << endl;
									std::cout << "�������������������" << endl;
									_getch();
									menu(relas);
								}
								else
								{
									system("cls");
									std::cout << "�ɹ�!!!\n�������������������" << endl;
									relas.erase(it++);
									_getch();
								}
							}
						}
						else if (i == 2)
						{
							std::cout << "��������Ҫɾ���ĳ�Ա������" << endl;
							string delname;
							std::cin >> delname;
							list<relationship> ::iterator it;
							for (it = relas.begin(); it != relas.end(); it++)
							{
								if ((*it).getname() == delname) break;
							}
							if (it == relas.end())
							{
								system("cls");
								std::cout << "�Ҳ�������Ҫ�ҵ���\n�������������������" << endl;
								_getch();
								menu(relas);
							}
							else
							{
								system("cls");
								std::cout << "�ɹ�!!!\n�������������������" << endl;
								file f;
								f.file_delete(*it);
								relas.erase(it++);
								_getch();
							}
						}
					}
					if (i == 4)i = 1;
					if (i == 0)i = 3;
					switch (i)
					{
					case 1:
						system("cls");
						std::cout << "->1.��ĳ�˵�ͨѶ¼��ɾ����Ա" << endl;
						std::cout << "  2.ɾ����Ա" << endl;
						std::cout << "  3.������һ������" << endl;
						break;

					case 2:
						system("cls");
						std::cout << "  1.��ĳ�˵�ͨѶ¼��ɾ����Ա" << endl;
						std::cout << "->2.ɾ����Ա" << endl;
						std::cout << "  3.������һ������" << endl;
						break;

					case 3:
						system("cls");
						std::cout << "  1.��ĳ�˵�ͨѶ¼��ɾ����Ա" << endl;
						std::cout << "  2.ɾ����Ա" << endl;
						std::cout << "->3.������һ������" << endl;
						break;
					}

				}
				
			}
			else if (a == 3)
			{
				system("cls");
				int i = 1;
				std::cout << "->1.�޸�ĳ�˵�ͨѶ¼�е�ĳ����Ա����Ϣ" << endl;
				std::cout << "  2.�޸�ĳ�˵���Ϣ" << endl;					//�����Ұɣ������������ֱ�ģ������ҵ���//����д������������ָ�ȫ��
				std::cout << "  3.������һ������" << endl;
				while (true)
				{
					char r = _getch();
					if (r == UP)i--;
					else if (r == DOWN)i++;
					else if (r == 13 or r == 10)
					{
						if (i == 3)
						{
							linkman_manage(relas);
						}
						else if (i == 1)
						{
							system("cls");
							std::cout << "����Ҫ�޸�˭��ͨѶ¼��Ա�أ�������������" << endl;
							string ownername;
							std::cin >> ownername;
							list<relationship>::iterator it;
							for (it = relas.begin(); it != relas.end(); it++)
							{
								if ((*it).getname() == ownername) break;
							}
							if (it == relas.end())
							{
								system("cls");
								std::cout << "�Ҳ��������" << endl;
								std::cout << "�����������������" << endl;
								_getch();
								menu(relas);
							}
							else
							{
								system("cls");
								string oldname, newname, newaddress, newtele1, newtele2;
								std::cout << "������Ҫ�޸ĵ���ϵ�˵ľ�����" << endl;
								std::cin >> oldname;

								list<relationship>::iterator in;
								list<relationship> findone = (*it).getcontacts();
								file f;
								
								for (in = findone.begin(); in != findone.end(); in++)
								{
									if ((*in).getname() == oldname) break;
								}
								if (in == findone.end())
								{
									std::cout << "�Ҳ��������\n�������������������" << endl;
									_getch();
									menu(relas);
								}

								std::cout << "�������������֣��¹����أ��¿�һ���¿���\n��û�п���������\"null\"" << endl;
								std::cin >> newname;
								std::cin >> newaddress;
								std::cin >> newtele1;
								std::cin >> newtele2;
								std::cout << "�ɹ�!!!\n�������������������" << endl;
								
								
								
								
								relationship oldchangeone = (*in);
								(*in).name_change(newname);
								(*in).address_change(newaddress);
								if (newtele1 != "null")
								{
									(*it).tele_num_1_change(newtele1);
									(*it).tele_num_2_change(newtele2);
								}
								else
								{
									(*it).tele_num_1_change(newtele2);
									(*it).tele_num_2_change(newtele1);
								}
								relationship changeone1 = (*in);
								(*it).contacts_change(oldchangeone, changeone1);
								f.file_change(changeone1);
								system("cls");
								std::cout << "�ɹ�!!!\n�������������������" << endl;
								_getch();
								menu(relas);
								
							}
						}
						else if (i == 2)
						{
							system("cls");
							string oldname;
							std::cout << "����Ҫ�޸ĵ��˵ľ�����" << endl;
							std::cin >> oldname;
							file f;
							list<relationship> ::iterator it;
							for (it = relas.begin(); it != relas.end(); it++)
							{
								if ((*it).getname() == oldname) break;
							}
							if (it == relas.end())
							{
								system("cls");
								std::cout << "�Ҳ��������\n�������������������" << endl;
								_getch();
								menu(relas);
							}

							string newname, newaddress, newtele1, newtele2;
							std::cout << "�������������֣��¹����أ��¿�һ���¿���\n��û�п���������\"null\"" << endl;
							std::cin >> newname;
							std::cin >> newaddress;
							std::cin >> newtele1;
							std::cin >> newtele2;
							std::cout << "�ɹ�!!!\n�������������������" << endl;
							
							
							
							system("cls");
							(*it).name_change(newname);
							(*it).address_change(newaddress);
							if (newtele1 != "null")
							{
								(*it).tele_num_1_change(newtele1);
								(*it).tele_num_2_change(newtele2);
							}
							else
							{
								(*it).tele_num_1_change(newtele2);
								(*it).tele_num_2_change(newtele1);
							}
							
							relationship changeone = (*it);
							f.file_change(changeone);
							std::cout << "�ɹ�!!!\n�������������������" << endl;
							_getch();
							menu(relas);
							
						}
					}
					if (i == 0)i = 3;
					if (i == 4)i = 1;
					switch (i)
					{
					case 1:
						system("cls");
						std::cout << "->1.�޸�ĳ�˵�ͨѶ¼�е�ĳ����Ա����Ϣ" << endl;
						std::cout << "  2.�޸�ĳ�˵���Ϣ" << endl;					//�����Ұɣ������������ֱ�ģ������ҵ���//����д������������ָ�ȫ��
						std::cout << "  3.������һ������" << endl;
						break;

					case 2:
						system("cls");
						std::cout << "  1.�޸�ĳ�˵�ͨѶ¼�е�ĳ����Ա����Ϣ" << endl;
						std::cout << "->2.�޸�ĳ�˵���Ϣ" << endl;					//�����Ұɣ������������ֱ�ģ������ҵ���//����д������������ָ�ȫ��
						std::cout << "  3.������һ������" << endl;
						break;

					case 3:
						system("cls");
						std::cout << "  1.�޸�ĳ�˵�ͨѶ¼�е�ĳ����Ա����Ϣ" << endl;
						std::cout << "  2.�޸�ĳ�˵���Ϣ" << endl;					//�����Ұɣ������������ֱ�ģ������ҵ���//����д������������ָ�ȫ��
						std::cout << "->3.������һ������" << endl;
						break;
					}
				}
			}
		}

		if (a == 0) a = 4;
		if (a == 5) a = 1;
		switch (a)
		{
		case 1:
			system("cls");
			std::cout << "����Ҫ��ʲô?" << std::endl;
			std::cout << "->1.���" << endl;
			std::cout << "  2.ɾ��" << endl;
			std::cout << "  3.�޸�" << endl;
			std::cout << "  4.����������" << endl;
			break;

		case 2:
			system("cls");
			std::cout << "����Ҫ��ʲô?" << std::endl;
			std::cout << "  1.���" << endl;
			std::cout << "->2.ɾ��" << endl;
			std::cout << "  3.�޸�" << endl;
			std::cout << "  4.����������" << endl;
			break;

		case 3:
			system("cls");
			std::cout << "����Ҫ��ʲô?" << std::endl;
			std::cout << "  1.���" << endl;
			std::cout << "  2.ɾ��" << endl;
			std::cout << "->3.�޸�" << endl;
			std::cout << "  4.����������" << endl;
			break;
			
		case 4:
			system("cls");
			std::cout << "����Ҫ��ʲô?" << std::endl;
			std::cout << "  1.���" << endl;
			std::cout << "  2.ɾ��" << endl;
			std::cout << "  3.�޸�" << endl;
			std::cout << "->4.����������" << endl;
		}
		
	}
}

void Menu::linkman_find(list<relationship>& relas)
{
	int a = 1;
	system("cls");
	std::cout << "->1.��ĳ�˵�ͨѶ¼�в���" << endl;
	std::cout << "  2.����" << endl;
	std::cout << "  3.������һ��" << endl;
	while (true)
	{
		char c = _getch();
		if (c == UP) a--;
		else if (c == DOWN)a++;
		else if (c == 13 or c == 10)								//������س���
		{
			if (a == 1)												//��ĳ����ϵ������ĳ��
			{
				system("cls");
				int i = 1;
				std::cout << "����Ҫ��ʲô?" << endl;
				std::cout << "���������ѡ��" << endl;
				std::cout << "->1.������������" << endl;
				std::cout << "  2.���ݹ����ؽ��в���" << endl;
				std::cout << "  3.���ݵ绰������в���" << endl;
				std::cout << "  4.������һ������" << endl;
				while (true)
				{
					char q = _getch();
					if (q == UP) i--;
					else if (q == DOWN)i++;
					else if (q == 10 or q == 13)
					{
						if (i == 1)
						{
							system("cls");
							std::cout << "����Ҫ��˭��ͨѶ¼����ң�������������" << endl;
							string ownername;
							std::cin >>ownername;
							std::cout << "��������Ҫ���ҵ��˵�����" << endl;
							string findname;
							std::cin >> findname;
							list<relationship> ::iterator it;
							for (it = relas.begin(); it != relas.end(); it++)
							{
								if ((*it).getname() == ownername) break;
							}
							if (it == relas.end())
							{
								system("cls");
								std::cout << "�ڸ�ͨѶ¼���Ҳ��������" << endl;
								std::cout << "�������������������" << endl;
								_getch();
								menu(relas);
							}
							else
							{
								/*system("cls");
								std::cout << "here is the info about this person" << endl;*/
								relationship one = *it;
								list<relationship> findone = one.getcontacts();
								list<relationship> ::iterator in;
								for (in = findone.begin(); in != findone.end(); in++)
								{
									if ((*in).getname() == findname)
									{
										break;
									}
								}
								if (in == findone.end())
								{
									system("cls");
									std::cout << "��������˵�ͨѶ¼���Ҳ��������" << endl;
									std::cout << "�������������������" << endl;
									_getch();
									menu(relas);
								}
								else
								{
									system("cls");
									std::cout << "����" << endl;
									std::cout << "�������������������" << endl;
									_getch();
									menu(relas);
								}
							}
						}
						else if (i == 2)
						{
							system("cls");
							std::cout << "����Ҫ��˭��ͨѶ¼���ң���������" << endl;
							string ownername;
							std::cin >> ownername;
							std::cout << "��������Ҫ���ҵ��˵Ĺ�����" << endl;
							string findaddress;
							std::cin >> findaddress;
							list<relationship> ::iterator it;
							for (it = relas.begin(); it != relas.end(); it++)
							{
								if ((*it).getname() == ownername) break;
							}
							if (it == relas.end())
							{
								system("cls");
								std::cout << "�ڸ�ͨѶ¼���Ҳ��������" << endl;
								std::cout << "�������������������" << endl;
								_getch();
								menu(relas);
							}
							else
							{
								/*system("cls");
								std::cout << "here is the info about this person" << endl;*/
								list<relationship> ::iterator in;
								for (in = (*it).getcontacts().begin(); in != (*it).getcontacts().end(); in++)
								{
									if ((*in).getaddress() == findaddress)
									{
										break;
									}
								}
								if (in == (*it).getcontacts().end())
								{
									system("cls");
									std::cout << "��������˵�ͨѶ¼���Ҳ��������" << endl;
									std::cout << "�������������������" << endl;
									_getch();
									menu(relas);
								}
								else
								{
									system("cls");
									std::cout << "����" << endl;
									std::cout << "�������������������" << endl;
									_getch();
									menu(relas);
								}
							}
						}
						else if (i == 3)
						{
							system("cls");
							std::cout << "����Ҫ��˭��ͨѶ¼���ң�������������" << endl;
							string ownername;
							std::cin >> ownername;
							std::cout << "��������Ҫ���ҵĵ绰����" << endl;
							string findtele;
							std::cin >> findtele;
							list<relationship> ::iterator it;
							for (it = relas.begin(); it != relas.end(); it++)
							{
								if ((*it).getname() == ownername) break;
							}
							if (it == relas.end())
							{
								system("cls");
								std::cout << "���ڸ�ͨѶ¼���Ҳ��������" << endl;
								std::cout << "�������������������" << endl;
								_getch();
								menu(relas);
							}
							else
							{
								/*system("cls");
								std::cout << "here is the info about this person" << endl;*/
								list<relationship> ::iterator in;
								for (in = (*it).getcontacts().begin(); in != (*it).getcontacts().end(); in++)
								{
									if ((*in).gettele_num_1() == findtele)
									{
										break;
									}
									else if ((*in).gettele_num_2() != "" and (*in).gettele_num_2() == findtele)
									{
										break;
									}
								}
								if (in == (*it).getcontacts().end())
								{
									system("cls");
									std::cout << "��������˵�ͨѶ¼���Ҳ��������" << endl;
									std::cout << "�������������������" << endl;
									_getch();
									menu(relas);
								}
								else
								{
									system("cls");
									std::cout << "����" << endl;
									std::cout << "�������������������" << endl;
									_getch();
									menu(relas);
								}
							}
						}
						else if (i == 4)
						{
							linkman_find(relas);
						}
					}
					if (i == 0)i = 4;
					if (i == 5)i = 1;
					switch (i)
					{
					case 1:
						system("cls");
						std::cout << "����Ҫ��ʲô?" << endl;
						std::cout << "���������ѡ��" << endl;
						std::cout << "->1.������������" << endl;
						std::cout << "  2.���ݹ����ؽ��в���" << endl;
						std::cout << "  3.���ݵ绰������в���" << endl;
						std::cout << "  4.������һ������" << endl;
						break;

					case 2:
						system("cls");
						std::cout << "����Ҫ��ʲô?" << endl;
						std::cout << "���������ѡ��" << endl;
						std::cout << "  1.������������" << endl;
						std::cout << "->2.���ݹ����ؽ��в���" << endl;
						std::cout << "  3.���ݵ绰������в���" << endl;
						std::cout << "  4.������һ������" << endl;
						break;

					case 3:
						system("cls");
						std::cout << "����Ҫ��ʲô?" << endl;
						std::cout << "���������ѡ��" << endl;
						std::cout << "  1.������������" << endl;
						std::cout << "  2.���ݹ����ؽ��в���" << endl;
						std::cout << "->3.���ݵ绰������в���" << endl;
						std::cout << "  4.������һ������" << endl;
						break;

					case 4:
						system("cls");
						std::cout << "����Ҫ��ʲô?" << endl;
						std::cout << "���������ѡ��" << endl;
						std::cout << "  1.������������" << endl;
						std::cout << "  2.���ݹ����ؽ��в���" << endl;
						std::cout << "  3.���ݵ绰������в���" << endl;
						std::cout << "->4.������һ������" << endl;
						break;
					}
				}
			}
			else if (a == 2)										//��ͨѶ¼����ĳ��
			{
				system("cls");
				int i = 1;
				std::cout << "����Ҫ��ʲô?" << endl;
				std::cout << "����������ѡ��" << endl;
				std::cout << "->1.������������" << endl;
				std::cout << "  2.���ݹ����ز���" << endl;
				std::cout << "  3.���ݵ绰�������" << endl;
				std::cout << "  4.������һ������" << endl;
				
				while (true)
				{
					char q = _getch();
					if (q == UP)i--;
					else if (q == DOWN)i++;
					else if(q == 13 or q == 10)
					{
						if (i == 1)									//�����ֲ�
						{
							string findname;
							std::cout << "��������Ҫ���ҵ��˵�����" << endl;
							std::cin >> findname;
							list<relationship>::iterator it;
							for (it = relas.begin(); it != relas.end(); it++)
							{
								if ((*it).getname() == findname) break;
							}
							if (it == relas.end())
							{
								system("cls");
								std::cout << "�Ҳ��������" << endl;
								std::cout << "�������������������" << endl;
								_getch();
								menu(relas);
							}
							else
							{
								system("cls");
								std::cout << "����" << endl;
								std::cout << "�������������������" << endl;
								_getch();
								menu(relas);
							}
						}
						else if (i == 2)							//�ù����ز�
						{
							string findaddress;
							std::cout << "��������Ҫ���ҵ��˵Ĺ�����" << endl;
							std::cin >> findaddress;
							list<relationship>::iterator it;
							for (it = relas.begin(); it != relas.end(); it++)
							{
								if ((*it).getaddress() == findaddress) break;
							}
							if (it == relas.end())
							{
								system("cls");
								std::cout << "�Ҳ��������" << endl;
								std::cout << "�������������������" << endl;
								_getch();
								menu(relas);
							}
							else
							{
								system("cls");
								std::cout << "����" << endl;
								std::cout << "�������������������" << endl;
								_getch();
								menu(relas);
							}
						}
						else if (i == 3)							//�õ绰�����
						{
							string findtele;
							std::cout << "��������Ҫ���ҵ��˵ĵ绰����" << endl;
							std::cin >> findtele;
							list<relationship>::iterator it;
							for (it = relas.begin(); it != relas.end(); it++)
							{
								if ((*it).gettele_num_1() == findtele)
								{
									break;
								}
								else if ((*it).gettele_num_2() != "" and (*it).gettele_num_2() == findtele)
								{
									break;
								}
							}
							if (it == relas.end())
							{
								system("cls");
								std::cout << "�Ҳ��������" << endl;
								std::cout << "�������������������" << endl;
								_getch();
								menu(relas);
							}
							else
							{
								system("cls");
								std::cout << "����" << endl;
								std::cout << "�������������������" << endl;
								_getch();
								menu(relas);
							}
						}
						else if (i == 4)
						{
							linkman_find(relas);
						}
					}
					if (i == 0)i = 4;
					if (i == 5)i = 1;
					switch (i)
					{
					case 1:
						system("cls");
						std::cout << "����Ҫ��ʲô?" << endl;
						std::cout << "����������ѡ��" << endl;
						std::cout << "->1.������������" << endl;
						std::cout << "  2.���ݹ����ز���" << endl;
						std::cout << "  3.���ݵ绰�������" << endl;
						std::cout << "  4.������һ������" << endl;
						break;

					case 2:
						system("cls");
						std::cout << "����Ҫ��ʲô?" << endl;
						std::cout << "����������ѡ��" << endl;
						std::cout << "  1.������������" << endl;
						std::cout << "->2.���ݹ����ز���" << endl;
						std::cout << "  3.���ݵ绰�������" << endl;
						std::cout << "  4.������һ������" << endl;
						break;

					case 3:
						system("cls");
						std::cout << "����Ҫ��ʲô?" << endl;
						std::cout << "����������ѡ��" << endl;
						std::cout << "  1.������������" << endl;
						std::cout << "  2.���ݹ����ز���" << endl;
						std::cout << "->3.���ݵ绰�������" << endl;
						std::cout << "  4.������һ������" << endl;
						break;

					case 4:
						system("cls");
						std::cout << "����Ҫ��ʲô?" << endl;
						std::cout << "����������ѡ��" << endl;
						std::cout << "  1.������������" << endl;
						std::cout << "  2.���ݹ����ز���" << endl;
						std::cout << "  3.���ݵ绰�������" << endl;
						std::cout << "->4.������һ������" << endl;
						break;
					}
				}

				
			}
			else if (a == 3)										//������һ�����棬��menu()
			{
				menu(relas);
			}
		}
		if (a == 0) a = 3;
		if (a == 4) a = 1;
		switch (a)
		{
		case 1:
			system("cls");
			std::cout << "->1.��ĳ�˵�ͨѶ¼�в���" << endl;
			std::cout << "  2.����" << endl;
			std::cout << "  3.������һ��" << endl;
			break;

		case 2:
			system("cls");
			std::cout << "  1.��ĳ�˵�ͨѶ¼�в���" << endl;
			std::cout << "->2.����" << endl;
			std::cout << "  3.������һ��" << endl;
			break;

		case 3:
			system("cls");
			std::cout << "  1.��ĳ�˵�ͨѶ¼�в���" << endl;
			std::cout << "  2.����" << endl;
			std::cout << "->3.������һ��" << endl;
			break;
		}
	}
}

void Menu::linkman_sort(list<relationship>& relas)
{
	int a = 1;
	system("cls");
	std::cout << "->1.��ĳ�˵�ͨѶ¼������" << std::endl;
	std::cout << "  2.����" << endl;
	std::cout << "  3.������һ������" << endl;
	while (true)
	{
		char c = _getch();
		if (c == UP) a--;
		else if (c == DOWN)a++;
		else if (c == 13 or c == 10)
		{
			if (a == 1)
			{
				system("cls");
				std::cout << "����Ҫ��˭��ͨѶ¼��������������������" << endl;
				std::string findname;
				std::cin >> findname;
				list<relationship>::iterator it;
				for (it = relas.begin(); it != relas.end(); it++)
				{
					if ((*it).getname() == findname) break;
				}
				if (it == relas.end())
				{
					std::cout << "�Ҳ��������" << endl;
					std::cout << "�������������" << endl;
					_getch();
					break;
				}
				else
				{
					system("cls");
					std::cout << "->1.������������" << endl;
					std::cout << "  2.���ݹ���������" << endl;
					int b = 1;
					while (true)
					{
						char ch = _getch();
						if (ch == UP)b--;
						else if (ch == DOWN)b++;
						else if (ch == 10 or ch == 13)
						{
							if (b == 1)
							{
								(*it).contacts_sort_by_name();
								std::cout << "�ɹ�!!!\n�������������������" << endl;
								_getch();
								menu(relas);
							}
							else if (b == 2)
							{
								(*it).contacts_sort_by_address();
								std::cout << "�ɹ�!!!\n�������������������" << endl;
								_getch();
								menu(relas);
							}
						}
						if (b == 0)b = 2;
						if (b == 3)b = 1;
						switch (b)
						{
						case 1:
							system("cls");
							std::cout << "->1.������������" << endl;
							std::cout << "  2.���ݹ���������" << endl;
							break;

						case 2:
							system("cls");
							std::cout << "  1.������������" << endl;
							std::cout << "->2.���ݹ���������" << endl;
							break;
						}
					}
				}
			}
			else if (a == 2)
			{
				system("cls");
				std::cout << "->1.������������" << endl;
				std::cout << "  2.���ݹ���������" << endl;
				int r = 1;
				while (true)
				{
					char ce = _getch();
					if (ce == UP)r--;
					else if (ce == DOWN)r++;
					else if (ce == 10 or ce == 13)
					{
						if (r == 1)
						{
							sort_by_name(relas);
							std::cout << "�ɹ�!!!\n�������������������" << endl;
							_getch();
							menu(relas);
						}
						else if (r == 2)
						{
							sort_by_address(relas);
							std::cout << "�ɹ�!!!\n�������������������" << endl;
							_getch();
							menu(relas);
						}
					}
					if (r == 3)r = 1;
					if (r == 0)r = 2;
					if (r == 1)
					{
						system("cls");
						std::cout << "->1.������������" << endl;
						std::cout << "  2.���ݹ���������" << endl;
					}
					else if (r == 2)
					{
						system("cls");
						std::cout << "  1.������������" << endl;
						std::cout << "->2.���ݹ���������" << endl;
					}
				}
			}
			else if (a == 3)
			{
				menu(relas);
			}
		}
		if (a == 0) a = 3;
		if (a == 4) a = 1;
		switch (a)
		{
		case 1:
			system("cls");
			std::cout << "->1.��ĳ�˵�ͨѶ¼������" << std::endl;
			std::cout << "  2.����" << endl;
			std::cout << "  3.������һ������" << endl;
			break;

		case 2:
			system("cls");
			std::cout << "  1.��ĳ�˵�ͨѶ¼������" << std::endl;
			std::cout << "->2.����" << endl;
			std::cout << "  3.������һ������" << endl;
			break;
		case 3:
			system("cls");
			std::cout << "  1.��ĳ�˵�ͨѶ¼������" << std::endl;
			std::cout << "  2.����" << endl;
			std::cout << "->3.������һ������" << endl;
		}
	}
}

void Menu::linkman_statistic(list<relationship>& relas)
{
	system("cls");
	int a = 1;
	std::cout << "->1.Ϊĳ�˵�ͨѶ¼��ͳ��" << endl;
	std::cout << "  2.��ͳ��" << endl;
	std::cout << "  3.������һ������" << endl;
	while (true)
	{
		char c = _getch();
		if (c == UP)a--;
		else if (c == DOWN)a++;
		else if (c == 10 or c == 13)
		{
			if (a == 1)
			{
				system("cls");
				std::string findname;
				std::cout << "��������˵�����" << endl;
				std::cin >> findname;
				list<relationship> ::iterator it;
				for (it = relas.begin(); it != relas.end(); it++)
				{
					if ((*it).getname() == findname) break;
				}
				if (it == relas.end())
				{
					std::cout << "�Ҳ��������" << endl;
					std::cout << "�����������" << endl;
					_getch();
					break;
				}
				else
				{
					system("cls");
					std::cout << "->1.����λβ����ͬ����������ͳ��" << endl;
					std::cout << "  2.����ͬ�����ص�������ͳ��" << endl;
					int cnt = 1;
					while (true)
					{
						char cr = _getch();
						if (cr == UP)cnt--;
						else if (cr == DOWN)cnt++;
						else if (cr == 10 or cr == 13)
						{
							if (cnt == 1)
							{
								string num;
								std::cout << "��������λβ��" << endl;
								std::cin >> num;
								(*it).contacts_statistic_same_finalnum(num);
								std::cout << "�ɹ�!!!\n�������������������" << endl;
								_getch();
								menu(relas);
							}
							else if (cnt == 2)
							{
								string address;
								std::cout << "���������" << endl;
								std::cin >> address;
								(*it).contacts_statistic_same_address(address);
								std::cout << "�ɹ�!!!\n�������������������" << endl;
								_getch();
								menu(relas);
							}
						}
						if (cnt == 3)cnt = 1;
						if (cnt == 0)cnt = 2;
						if (cnt == 1)
						{
							system("cls");
							std::cout << "->1.����λβ����ͬ����������ͳ��" << endl;
							std::cout << "  2.����ͬ�����ص�������ͳ��" << endl;
						}
						else if (cnt == 2)
						{
							system("cls");
							std::cout << "  1.����λβ����ͬ����������ͳ��" << endl;
							std::cout << "->2.����ͬ�����ص�������ͳ��" << endl;
						}
					}
				}
			}
			else if (a == 3)
			{
				menu(relas);
			}
			else if (a == 2)
			{
				system("cls");
				int tr = 1;
				std::cout << "->1.����λβ����ͬ����������ͳ��" << endl;
				std::cout << "  2.����ͬ�����ص�������ͳ��" << endl;
				while (true)
				{
					char ty = _getch();
					if (ty == UP)tr--;
					else if (ty == DOWN)tr++;
					else if (ty == 13 or ty == 10)
					{
						if (tr == 1)
						{
							string num;
							std::cout << "��������λβ��" << endl;
							cin >> num;
							statistic_same_finalnum(relas, num);
							std::cout << "�ɹ�!!!\n�������������������" << endl;
							_getch();
							menu(relas);
						}
						else if (tr == 2)
						{
							string address;
							std::cout << "���������" << endl;
							cin >> address;
							statistic_same_address(relas, address);
							std::cout << "�ɹ�!!!\n�������������������" << endl;
							_getch();
							menu(relas);
						}
					}
					if (tr == 3)tr = 1;
					if (tr == 0)tr = 2;
					if (tr == 1)
					{
						system("cls");
						std::cout << "->1.����λβ����ͬ����������ͳ��" << endl;
						std::cout << "  2.����ͬ�����ص�������ͳ��" << endl;
					}
					else if (tr == 2)
					{
						system("cls");
						std::cout << "  1.����λβ����ͬ����������ͳ��" << endl;
						std::cout << "->2.����ͬ�����ص�������ͳ��" << endl;
					}
				}
			}
		}
		if (a == 4)a = 1;
		if (a == 0)a = 3;
		switch (a)
		{
		case 1:
			system("cls");
			std::cout << "->1.Ϊĳ�˵�ͨѶ¼��ͳ��" << endl;
			std::cout << "  2.��ͳ��" << endl;
			std::cout << "  3.������һ������" << endl;
			break;
		case 2:
			system("cls");
			std::cout << "  1.Ϊĳ�˵�ͨѶ¼��ͳ��" << endl;
			std::cout << "->2.��ͳ��" << endl;
			std::cout << "  3.������һ������" << endl;
			break;
		case 3:
			system("cls");
			std::cout << "  1.Ϊĳ�˵�ͨѶ¼��ͳ��" << endl;
			std::cout << "  2.��ͳ��" << endl;
			std::cout << "->3.������һ������" << endl;
			break;
		}
	}
}

void Menu::linkman_show(list<relationship>& relas)
{

	int a = 1;
	system("cls");
	std::cout << "->1.��ʾĳ�˵�������ϵ����Ϣ" << endl;
	std::cout << "  2.��ʾͨѶ¼" << endl;
	std::cout << "  3.��ʾĳ�˵���Ϣ��������ͨѶ¼��Ϣ��" << endl;
	std::cout << "  4.������һ������" << endl;
	while (true)
	{
		char c = _getch();
		if (c == UP)a--;
		else if (c == DOWN)a++;
		else if (c == 13 or c == 10)
		{
			if (a == 1)
			{
				system("cls");
				string findname;
				std::cout << "��������Ҫ��ʾ��ϵ�˵��˵�����" << endl;
				cin >> findname;
				list<relationship>::iterator it;
				for (it = relas.begin(); it != relas.end(); it++)
				{
					if ((*it).getname() == findname) break;
				}
				if (it == relas.end())
				{
					std::cout << "�Ҳ��������" << endl;
					std::cout << "�������������" << endl;
					_getch();
					menu(relas);
				}
				else
				{
					(*it).contacts_pop_out();
					std::cout << "�������������" << endl;
					_getch();
					menu(relas);
				}
			}
			else if (a == 2)
			{
				system("cls");

				pop_out(relas);
				std::cout << "\n\n�������������" << endl;
				_getch();
				menu(relas);
			}
			else if (a == 4)
			{
				menu(relas);
			}
			else if (a == 3)
			{
				system("cls");
				string findname;
				std::cout << "��������Ҫ��ʾ��ϵ�˵��˵�����" << endl;
				cin >> findname;
				list<relationship>::iterator it;
				for (it = relas.begin(); it != relas.end(); it++)
				{
					if ((*it).getname() == findname) break;
				}
				if (it == relas.end())
				{
					std::cout << "�Ҳ��������" << endl;
					std::cout << "�������������" << endl;
					_getch();
					menu(relas);
				}
				else
				{
					(*it).show();
					std::cout << "�������������" << endl;
					_getch();
					menu(relas);
				}
			}
		}
		if (a == 5)a = 1;
		if (a == 0)a = 4;
		switch (a)
		{
		case 1:
			system("cls");
			std::cout << "->1.��ʾĳ�˵�������ϵ����Ϣ" << endl;
			std::cout << "  2.��ʾͨѶ¼" << endl;
			std::cout << "  3.��ʾĳ�˵���Ϣ��������ͨѶ¼��Ϣ��" << endl;
			std::cout << "  4.������һ������" << endl;
			break;

		case 2:
			system("cls");
			std::cout << "  1.��ʾĳ�˵�������ϵ����Ϣ" << endl;
			std::cout << "->2.��ʾͨѶ¼" << endl;
			std::cout << "  3.��ʾĳ�˵���Ϣ��������ͨѶ¼��Ϣ��" << endl;
			std::cout << "  4.������һ������" << endl;
			break;

		case 3:
			system("cls");
			std::cout << "  1.��ʾĳ�˵�������ϵ����Ϣ" << endl;
			std::cout << "  2.��ʾͨѶ¼" << endl;
			std::cout << "->3.��ʾĳ�˵���Ϣ��������ͨѶ¼��Ϣ��" << endl;
			std::cout << "  4.������һ������" << endl;
			break;
		case 4:
			system("cls");
			std::cout << "  1.��ʾĳ�˵�������ϵ����Ϣ" << endl;
			std::cout << "  2.��ʾͨѶ¼" << endl;
			std::cout << "  3.��ʾĳ�˵���Ϣ��������ͨѶ¼��Ϣ��" << endl;
			std::cout << "->4.������һ������" << endl;
			break;
		}
	}
}



void Menu::menu(list<relationship>& relas)
{	
	system("cls");
	int choice = 1;
							//�ı�
	string welcome_text = "��ӭ����ͨѶ¼����ϵͳ������Ҫִ��ʲô������?";
	string tips = "\tͨ�� \""; tips += UP; tips += "\" �� \""; tips += DOWN; tips += "\" ���������ѡ��";
	string esc_text = "P.S. ���¡�enter����ѡ��ѡ����� ��esc�������˳�ϵͳ";
	/*string choice_create = "  1.Build an address book(abandoned)";
	std::string to_choice_create = "->1.Build an address book(abandoned)";*/
	string choice_manage = "  1.����ͨѶ¼";						//����׷�ӣ�ɾ�����޸�
	string to_choice_manage = "->1.����ͨѶ¼";
	string choice_find = "  2.��ͨѶ¼�в鿴�Ƿ���ĳ��";
	string to_choice_find = "->2.��ͨѶ¼�в鿴�Ƿ���ĳ��";
	string choice_sort = "  3.�������ͨѶ¼";
	string to_choice_sort = "->3.�������ͨѶ¼";
	string choice_statistics = "  4.��ͨѶ¼��ͳ��";
	string to_choice_statistics = "->4.��ͨѶ¼��ͳ��";
	string choice_show = "  5.��ʾĳ����Ϣ";
	string to_choice_show = "->5.��ʾĳ����Ϣ";
	
	std::cout << welcome_text << endl;
	std::cout << tips << endl;
	//std::cout << "\n" << to_choice_create << endl;
	std::cout << "\n"<<to_choice_manage << endl;
	std::cout << choice_find << endl;
	std::cout << choice_sort << endl;
	std::cout << choice_statistics << endl;
	std::cout << choice_show << "\n" << endl;
	std::cout << esc_text << endl;

	while (true)
	{
		char key = _getch();
		if (key == UP) choice--;												//UP��
		else if (key == DOWN) choice++;											//DOWN��
		else if (key == 13 or key == 10)
		{
			switch (choice)
			{
			//case 1:
			//	std::cout << "������ϵ��" << endl;								//done
			//	create();
			//	menu(relas);
			//	break;
			case 1:
				std::cout << "������ϵ��" << endl;								//done
				linkman_manage(relas);
				menu(relas);
				break;

			case 2:
				std::cout << "������ϵ��" << endl;								//done
				linkman_find(relas);
				menu(relas);
				break;

			case 3:
				std::cout << "������ϵ��" << endl;								//done
				linkman_sort(relas);
				menu(relas);
				break;

			case 4:
				std::cout << "ͳ����ϵ��" << endl;								//done
				linkman_statistic(relas);
				menu(relas);
				break;

			case 5:
				std::cout << "��ʾ��ϵ��" << endl;								//done
				linkman_show(relas);
				menu(relas);
				break;
			}
			break;
		}
		else if (key == 27) std::exit(0);
		if (choice == 0) choice = 5;
		if (choice == 6) choice = 1;
		switch (choice)
		{
		//case 1:
		//	system("cls");
		//	std::cout << welcome_text << endl;
		//	std::cout << tips << endl;
		//	//std::cout << "\n" << to_choice_create << endl;
		//	std::cout << "\n"<<choice_manage << endl;
		//	std::cout << choice_find << endl;
		//	std::cout << choice_sort << endl;
		//	std::cout << choice_statistics << endl;
		//	std::cout << choice_show << "\n" << endl;
		//	std::cout << esc_text << endl;
		//	break;
		case 1:
			system("cls");
			std::cout << welcome_text << endl;
			std::cout << tips << endl;
			//std::cout << "\n" << choice_create << endl;
			std::cout << "\n" << to_choice_manage << endl;
			std::cout << choice_find << endl;
			std::cout << choice_sort << endl;
			std::cout << choice_statistics << endl;
			std::cout << choice_show << "\n" << endl;
			std::cout << esc_text << endl;
			break;
		case 2:
			system("cls");
			std::cout << welcome_text << endl;
			std::cout << tips << endl;
			//std::cout << "\n" << choice_create << endl;
			std::cout << "\n" << choice_manage << endl;
			std::cout << to_choice_find << endl;
			std::cout << choice_sort << endl;
			std::cout << choice_statistics << endl;
			std::cout << choice_show << "\n" << endl;
			std::cout << esc_text << endl;
			break;

		case 3:
			system("cls");
			std::cout << welcome_text << endl;
			std::cout << tips << endl;
			//std::cout << "\n" << choice_create << endl;
			std::cout << "\n" << choice_manage << endl;
			std::cout << choice_find << endl;
			std::cout << to_choice_sort << endl;
			std::cout << choice_statistics << endl;
			std::cout << choice_show << "\n" << endl;
			std::cout << esc_text << endl;
			break;

		case 4:
			system("cls");
			std::cout << welcome_text << endl;
			std::cout << tips << endl;
			//std::cout << "\n" << choice_create << endl;
			std::cout << "\n" << choice_manage << endl;
			std::cout << choice_find << endl;
			std::cout << choice_sort << endl;
			std::cout << to_choice_statistics << endl;
			std::cout << choice_show << "\n" << endl;
			std::cout << esc_text << endl;
			break;

		case 5:
			system("cls");
			std::cout << welcome_text << endl;
			std::cout << tips << endl;
			//std::cout << "\n" << choice_create << endl;
			std::cout << "\n" << choice_manage << endl;
			std::cout << choice_find << endl;
			std::cout << choice_sort << endl;
			std::cout << choice_statistics << endl;
			std::cout << to_choice_show << "\n" << endl;
			std::cout << esc_text << endl;
			break;
		}
	}
}
