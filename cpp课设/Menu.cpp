#include "Menu.h"

void Menu::linkman_manage(list<relationship>& relas)
{
	system("cls");
	std::cout << "你想要做什么?" << std::endl;
	int a = 1;
	std::cout << "->1.添加" << endl;
	std::cout << "  2.删除" << endl;
	std::cout << "  3.修改" << endl;
	std::cout << "  4.返回主界面" << endl;
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
				std::cout << "->1.在某人的通讯录中添加成员" << endl;
				std::cout << "  2.添加成员" << endl;
				std::cout << "  3.返回上一级界面" << endl;
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
							std::cout << "你想要在谁的通讯录加添加？输入他的名字" << endl;
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
								std::cout << "我找不到你要往通讯录添加成员的联系人" << endl;
								std::cout << "摁下任意键返回主界面" << endl;
								_getch();
								menu(relas);
							}

							std::cout << "输入新添加的成员的信息\n格式:名字 归属地 卡一 卡二\nP.S. 若没有卡二，请在卡二的位置输入\"null\"" << endl;
							string newname, newaddress, newtele1, newtele2;
							std::cin >> newname;
							std::cin >> newaddress;
							std::cin >> newtele1;
							std::cin >> newtele2;
							relationship newone(newname, newtele1, newtele2, newaddress);
							system("cls");
							(*it).contacts_add(newone);
							std::cout << "成功!!!\n摁下任意键返回主界面" << endl;
							_getch();
							menu(relas);
							
						}
						else if (i == 2)
						{
							system("cls");
							std::cout << "输入新添加的成员的信息\n格式:名字 归属地 卡一 卡二\nP.S. 若没有卡二，请在卡二的位置输入\"null\"" << endl;
							string newname, newaddress, newtele1, newtele2;
							std::cin >> newname;
							std::cin >> newaddress;
							std::cin >> newtele1;
							std::cin >> newtele2;
							relationship newone(newname, newtele1, newtele2, newaddress);
							relas.push_back(newone);
							file f;
							f.file_write(newone);
							std::cout << "成功!!!\n摁下任意键返回主界面" << endl;
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
						std::cout << "->1.在某人的通讯录中添加成员" << endl;
						std::cout << "  2.添加成员" << endl;
						std::cout << "  3.返回上一级界面" << endl;
						break;

					case 2:
						system("cls");
						std::cout << "  1.在某人的通讯录中添加成员" << endl;
						std::cout << "->2.添加成员" << endl;
						std::cout << "  3.返回上一级界面" << endl; 
						break;

					case 3:
						system("cls");
						std::cout << "  1.在某人的通讯录中添加成员" << endl;
						std::cout << "  2.添加成员" << endl;
						std::cout << "->3.返回上一级界面" << endl; 
						break;
					}
				}
			}
			else if (a == 2)
			{
				system("cls");
				int i = 1;
				std::cout << "->1.在某人的通讯录中删除成员" << endl;
				std::cout << "  2.删除成员" << endl;
				std::cout << "  3.返回上一级界面" << endl;
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
							std::cout << "你想要在谁的通讯录中删除成员？输入他的名字" << endl;
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
								std::cout << "找不到你想要删除联系人的人的名字" << endl;
								std::cout << "摁下任意键返回主界面" << endl;
								_getch();
								menu(relas);
							}
							std::cout << "输入你想要删除的成员的名字" << endl;
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
									std::cout << "找不到你想要删除联系人的人的名字" << endl;
									std::cout << "摁下任意键返回主界面" << endl;
									_getch();
									menu(relas);
								}
								else
								{
									system("cls");
									std::cout << "成功!!!\n摁下任意键返回主界面" << endl;
									relas.erase(it++);
									_getch();
								}
							}
						}
						else if (i == 2)
						{
							std::cout << "输入你想要删除的成员的名字" << endl;
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
								std::cout << "找不到你想要找的人\n摁下任意键返回主界面" << endl;
								_getch();
								menu(relas);
							}
							else
							{
								system("cls");
								std::cout << "成功!!!\n摁下任意键返回主界面" << endl;
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
						std::cout << "->1.在某人的通讯录中删除成员" << endl;
						std::cout << "  2.删除成员" << endl;
						std::cout << "  3.返回上一级界面" << endl;
						break;

					case 2:
						system("cls");
						std::cout << "  1.在某人的通讯录中删除成员" << endl;
						std::cout << "->2.删除成员" << endl;
						std::cout << "  3.返回上一级界面" << endl;
						break;

					case 3:
						system("cls");
						std::cout << "  1.在某人的通讯录中删除成员" << endl;
						std::cout << "  2.删除成员" << endl;
						std::cout << "->3.返回上一级界面" << endl;
						break;
					}

				}
				
			}
			else if (a == 3)
			{
				system("cls");
				int i = 1;
				std::cout << "->1.修改某人的通讯录中的某个成员的信息" << endl;
				std::cout << "  2.修改某人的信息" << endl;					//饶了我吧，做三个函数分别改，累死我得了//这里写的是输入旧名字改全部
				std::cout << "  3.返回上一级界面" << endl;
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
							std::cout << "你想要修改谁的通讯录成员呢？输入他的名字" << endl;
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
								std::cout << "找不到这个人" << endl;
								std::cout << "摁任意键返回主界面" << endl;
								_getch();
								menu(relas);
							}
							else
							{
								system("cls");
								string oldname, newname, newaddress, newtele1, newtele2;
								std::cout << "输入想要修改的联系人的旧名字" << endl;
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
									std::cout << "找不到这个人\n摁下任意键返回主界面" << endl;
									_getch();
									menu(relas);
								}

								std::cout << "依次输入新名字，新归属地，新卡一，新卡二\n若没有卡二，输入\"null\"" << endl;
								std::cin >> newname;
								std::cin >> newaddress;
								std::cin >> newtele1;
								std::cin >> newtele2;
								std::cout << "成功!!!\n摁下任意键返回主界面" << endl;
								
								
								
								
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
								std::cout << "成功!!!\n摁下任意键返回主界面" << endl;
								_getch();
								menu(relas);
								
							}
						}
						else if (i == 2)
						{
							system("cls");
							string oldname;
							std::cout << "输入要修改的人的旧名字" << endl;
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
								std::cout << "找不到这个人\n摁下任意键返回主界面" << endl;
								_getch();
								menu(relas);
							}

							string newname, newaddress, newtele1, newtele2;
							std::cout << "依次输入新名字，新归属地，新卡一，新卡二\n若没有卡二，输入\"null\"" << endl;
							std::cin >> newname;
							std::cin >> newaddress;
							std::cin >> newtele1;
							std::cin >> newtele2;
							std::cout << "成功!!!\n摁下任意键返回主界面" << endl;
							
							
							
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
							std::cout << "成功!!!\n摁下任意键返回主界面" << endl;
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
						std::cout << "->1.修改某人的通讯录中的某个成员的信息" << endl;
						std::cout << "  2.修改某人的信息" << endl;					//饶了我吧，做三个函数分别改，累死我得了//这里写的是输入旧名字改全部
						std::cout << "  3.返回上一级界面" << endl;
						break;

					case 2:
						system("cls");
						std::cout << "  1.修改某人的通讯录中的某个成员的信息" << endl;
						std::cout << "->2.修改某人的信息" << endl;					//饶了我吧，做三个函数分别改，累死我得了//这里写的是输入旧名字改全部
						std::cout << "  3.返回上一级界面" << endl;
						break;

					case 3:
						system("cls");
						std::cout << "  1.修改某人的通讯录中的某个成员的信息" << endl;
						std::cout << "  2.修改某人的信息" << endl;					//饶了我吧，做三个函数分别改，累死我得了//这里写的是输入旧名字改全部
						std::cout << "->3.返回上一级界面" << endl;
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
			std::cout << "你想要做什么?" << std::endl;
			std::cout << "->1.添加" << endl;
			std::cout << "  2.删除" << endl;
			std::cout << "  3.修改" << endl;
			std::cout << "  4.返回主界面" << endl;
			break;

		case 2:
			system("cls");
			std::cout << "你想要做什么?" << std::endl;
			std::cout << "  1.添加" << endl;
			std::cout << "->2.删除" << endl;
			std::cout << "  3.修改" << endl;
			std::cout << "  4.返回主界面" << endl;
			break;

		case 3:
			system("cls");
			std::cout << "你想要做什么?" << std::endl;
			std::cout << "  1.添加" << endl;
			std::cout << "  2.删除" << endl;
			std::cout << "->3.修改" << endl;
			std::cout << "  4.返回主界面" << endl;
			break;
			
		case 4:
			system("cls");
			std::cout << "你想要做什么?" << std::endl;
			std::cout << "  1.添加" << endl;
			std::cout << "  2.删除" << endl;
			std::cout << "  3.修改" << endl;
			std::cout << "->4.返回主界面" << endl;
		}
		
	}
}

void Menu::linkman_find(list<relationship>& relas)
{
	int a = 1;
	system("cls");
	std::cout << "->1.在某人的通讯录中查找" << endl;
	std::cout << "  2.查找" << endl;
	std::cout << "  3.返回上一级" << endl;
	while (true)
	{
		char c = _getch();
		if (c == UP) a--;
		else if (c == DOWN)a++;
		else if (c == 13 or c == 10)								//若输入回车键
		{
			if (a == 1)												//在某人联系人中找某人
			{
				system("cls");
				int i = 1;
				std::cout << "你想要做什么?" << endl;
				std::cout << "在这里进行选择" << endl;
				std::cout << "->1.根据姓名查找" << endl;
				std::cout << "  2.根据归属地进行查找" << endl;
				std::cout << "  3.根据电话号码进行查找" << endl;
				std::cout << "  4.返回上一级界面" << endl;
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
							std::cout << "你想要在谁的通讯录里查找？输入他的名字" << endl;
							string ownername;
							std::cin >>ownername;
							std::cout << "输入你想要查找的人的名字" << endl;
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
								std::cout << "在该通讯录中找不到这个人" << endl;
								std::cout << "摁下任意键返回主界面" << endl;
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
									std::cout << "我在这个人的通讯录中找不到这个人" << endl;
									std::cout << "摁下任意键返回主界面" << endl;
									_getch();
									menu(relas);
								}
								else
								{
									system("cls");
									std::cout << "存在" << endl;
									std::cout << "摁下任意键返回主界面" << endl;
									_getch();
									menu(relas);
								}
							}
						}
						else if (i == 2)
						{
							system("cls");
							std::cout << "你想要在谁的通讯录里找？输入他的" << endl;
							string ownername;
							std::cin >> ownername;
							std::cout << "输入你想要查找的人的归属地" << endl;
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
								std::cout << "在该通讯录中找不到这个人" << endl;
								std::cout << "摁下任意键返回主界面" << endl;
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
									std::cout << "我在这个人的通讯录里找不到这个人" << endl;
									std::cout << "摁下任意键返回主界面" << endl;
									_getch();
									menu(relas);
								}
								else
								{
									system("cls");
									std::cout << "存在" << endl;
									std::cout << "摁下任意键返回主界面" << endl;
									_getch();
									menu(relas);
								}
							}
						}
						else if (i == 3)
						{
							system("cls");
							std::cout << "你想要在谁的通讯录里找？输入他的名字" << endl;
							string ownername;
							std::cin >> ownername;
							std::cout << "输入你想要查找的电话号码" << endl;
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
								std::cout << "我在该通讯录里找不到这个人" << endl;
								std::cout << "摁下任意键返回主界面" << endl;
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
									std::cout << "我在这个人的通讯录里找不到这个人" << endl;
									std::cout << "摁下任意键返回主界面" << endl;
									_getch();
									menu(relas);
								}
								else
								{
									system("cls");
									std::cout << "存在" << endl;
									std::cout << "摁下任意键返回主界面" << endl;
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
						std::cout << "你想要做什么?" << endl;
						std::cout << "在这里进行选择" << endl;
						std::cout << "->1.根据姓名查找" << endl;
						std::cout << "  2.根据归属地进行查找" << endl;
						std::cout << "  3.根据电话号码进行查找" << endl;
						std::cout << "  4.返回上一级界面" << endl;
						break;

					case 2:
						system("cls");
						std::cout << "你想要做什么?" << endl;
						std::cout << "在这里进行选择" << endl;
						std::cout << "  1.根据姓名查找" << endl;
						std::cout << "->2.根据归属地进行查找" << endl;
						std::cout << "  3.根据电话号码进行查找" << endl;
						std::cout << "  4.返回上一级界面" << endl;
						break;

					case 3:
						system("cls");
						std::cout << "你想要做什么?" << endl;
						std::cout << "在这里进行选择" << endl;
						std::cout << "  1.根据姓名查找" << endl;
						std::cout << "  2.根据归属地进行查找" << endl;
						std::cout << "->3.根据电话号码进行查找" << endl;
						std::cout << "  4.返回上一级界面" << endl;
						break;

					case 4:
						system("cls");
						std::cout << "你想要做什么?" << endl;
						std::cout << "在这里进行选择" << endl;
						std::cout << "  1.根据姓名查找" << endl;
						std::cout << "  2.根据归属地进行查找" << endl;
						std::cout << "  3.根据电话号码进行查找" << endl;
						std::cout << "->4.返回上一级界面" << endl;
						break;
					}
				}
			}
			else if (a == 2)										//在通讯录中找某人
			{
				system("cls");
				int i = 1;
				std::cout << "你想要做什么?" << endl;
				std::cout << "在这里做出选择" << endl;
				std::cout << "->1.根据姓名查找" << endl;
				std::cout << "  2.根据归属地查找" << endl;
				std::cout << "  3.根据电话号码查找" << endl;
				std::cout << "  4.返回上一级界面" << endl;
				
				while (true)
				{
					char q = _getch();
					if (q == UP)i--;
					else if (q == DOWN)i++;
					else if(q == 13 or q == 10)
					{
						if (i == 1)									//用名字查
						{
							string findname;
							std::cout << "输入你想要查找的人的名字" << endl;
							std::cin >> findname;
							list<relationship>::iterator it;
							for (it = relas.begin(); it != relas.end(); it++)
							{
								if ((*it).getname() == findname) break;
							}
							if (it == relas.end())
							{
								system("cls");
								std::cout << "找不到这个人" << endl;
								std::cout << "摁下任意键返回主界面" << endl;
								_getch();
								menu(relas);
							}
							else
							{
								system("cls");
								std::cout << "存在" << endl;
								std::cout << "摁下任意键返回主界面" << endl;
								_getch();
								menu(relas);
							}
						}
						else if (i == 2)							//用归属地查
						{
							string findaddress;
							std::cout << "输入你想要查找的人的归属地" << endl;
							std::cin >> findaddress;
							list<relationship>::iterator it;
							for (it = relas.begin(); it != relas.end(); it++)
							{
								if ((*it).getaddress() == findaddress) break;
							}
							if (it == relas.end())
							{
								system("cls");
								std::cout << "找不到这个人" << endl;
								std::cout << "摁下任意键返回主界面" << endl;
								_getch();
								menu(relas);
							}
							else
							{
								system("cls");
								std::cout << "存在" << endl;
								std::cout << "摁下任意键返回主界面" << endl;
								_getch();
								menu(relas);
							}
						}
						else if (i == 3)							//用电话号码查
						{
							string findtele;
							std::cout << "输入你想要查找的人的电话号码" << endl;
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
								std::cout << "找不到这个人" << endl;
								std::cout << "摁下任意键返回主界面" << endl;
								_getch();
								menu(relas);
							}
							else
							{
								system("cls");
								std::cout << "存在" << endl;
								std::cout << "摁下任意键返回主界面" << endl;
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
						std::cout << "你想要做什么?" << endl;
						std::cout << "在这里做出选择" << endl;
						std::cout << "->1.根据姓名查找" << endl;
						std::cout << "  2.根据归属地查找" << endl;
						std::cout << "  3.根据电话号码查找" << endl;
						std::cout << "  4.返回上一级界面" << endl;
						break;

					case 2:
						system("cls");
						std::cout << "你想要做什么?" << endl;
						std::cout << "在这里做出选择" << endl;
						std::cout << "  1.根据姓名查找" << endl;
						std::cout << "->2.根据归属地查找" << endl;
						std::cout << "  3.根据电话号码查找" << endl;
						std::cout << "  4.返回上一级界面" << endl;
						break;

					case 3:
						system("cls");
						std::cout << "你想要做什么?" << endl;
						std::cout << "在这里做出选择" << endl;
						std::cout << "  1.根据姓名查找" << endl;
						std::cout << "  2.根据归属地查找" << endl;
						std::cout << "->3.根据电话号码查找" << endl;
						std::cout << "  4.返回上一级界面" << endl;
						break;

					case 4:
						system("cls");
						std::cout << "你想要做什么?" << endl;
						std::cout << "在这里做出选择" << endl;
						std::cout << "  1.根据姓名查找" << endl;
						std::cout << "  2.根据归属地查找" << endl;
						std::cout << "  3.根据电话号码查找" << endl;
						std::cout << "->4.返回上一级界面" << endl;
						break;
					}
				}

				
			}
			else if (a == 3)										//返回上一级界面，即menu()
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
			std::cout << "->1.在某人的通讯录中查找" << endl;
			std::cout << "  2.查找" << endl;
			std::cout << "  3.返回上一级" << endl;
			break;

		case 2:
			system("cls");
			std::cout << "  1.在某人的通讯录中查找" << endl;
			std::cout << "->2.查找" << endl;
			std::cout << "  3.返回上一级" << endl;
			break;

		case 3:
			system("cls");
			std::cout << "  1.在某人的通讯录中查找" << endl;
			std::cout << "  2.查找" << endl;
			std::cout << "->3.返回上一级" << endl;
			break;
		}
	}
}

void Menu::linkman_sort(list<relationship>& relas)
{
	int a = 1;
	system("cls");
	std::cout << "->1.对某人的通讯录做排序" << std::endl;
	std::cout << "  2.排序" << endl;
	std::cout << "  3.返回上一级界面" << endl;
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
				std::cout << "你想要对谁的通讯录进行排序？输入他的名字" << endl;
				std::string findname;
				std::cin >> findname;
				list<relationship>::iterator it;
				for (it = relas.begin(); it != relas.end(); it++)
				{
					if ((*it).getname() == findname) break;
				}
				if (it == relas.end())
				{
					std::cout << "找不到这个人" << endl;
					std::cout << "摁下任意键返回" << endl;
					_getch();
					break;
				}
				else
				{
					system("cls");
					std::cout << "->1.根据姓名排序" << endl;
					std::cout << "  2.根据归属地排序" << endl;
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
								std::cout << "成功!!!\n摁下任意键返回主界面" << endl;
								_getch();
								menu(relas);
							}
							else if (b == 2)
							{
								(*it).contacts_sort_by_address();
								std::cout << "成功!!!\n摁下任意键返回主界面" << endl;
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
							std::cout << "->1.根据姓名排序" << endl;
							std::cout << "  2.根据归属地排序" << endl;
							break;

						case 2:
							system("cls");
							std::cout << "  1.根据姓名排序" << endl;
							std::cout << "->2.根据归属地排序" << endl;
							break;
						}
					}
				}
			}
			else if (a == 2)
			{
				system("cls");
				std::cout << "->1.根据姓名排序" << endl;
				std::cout << "  2.根据归属地排序" << endl;
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
							std::cout << "成功!!!\n摁下任意键返回主界面" << endl;
							_getch();
							menu(relas);
						}
						else if (r == 2)
						{
							sort_by_address(relas);
							std::cout << "成功!!!\n摁下任意键返回主界面" << endl;
							_getch();
							menu(relas);
						}
					}
					if (r == 3)r = 1;
					if (r == 0)r = 2;
					if (r == 1)
					{
						system("cls");
						std::cout << "->1.根据姓名排序" << endl;
						std::cout << "  2.根据归属地排序" << endl;
					}
					else if (r == 2)
					{
						system("cls");
						std::cout << "  1.根据姓名排序" << endl;
						std::cout << "->2.根据归属地排序" << endl;
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
			std::cout << "->1.对某人的通讯录做排序" << std::endl;
			std::cout << "  2.排序" << endl;
			std::cout << "  3.返回上一级界面" << endl;
			break;

		case 2:
			system("cls");
			std::cout << "  1.对某人的通讯录做排序" << std::endl;
			std::cout << "->2.排序" << endl;
			std::cout << "  3.返回上一级界面" << endl;
			break;
		case 3:
			system("cls");
			std::cout << "  1.对某人的通讯录做排序" << std::endl;
			std::cout << "  2.排序" << endl;
			std::cout << "->3.返回上一级界面" << endl;
		}
	}
}

void Menu::linkman_statistic(list<relationship>& relas)
{
	system("cls");
	int a = 1;
	std::cout << "->1.为某人的通讯录做统计" << endl;
	std::cout << "  2.做统计" << endl;
	std::cout << "  3.返回上一级界面" << endl;
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
				std::cout << "输入这个人的名字" << endl;
				std::cin >> findname;
				list<relationship> ::iterator it;
				for (it = relas.begin(); it != relas.end(); it++)
				{
					if ((*it).getname() == findname) break;
				}
				if (it == relas.end())
				{
					std::cout << "找不到这个人" << endl;
					std::cout << "摁任意键返回" << endl;
					_getch();
					break;
				}
				else
				{
					system("cls");
					std::cout << "->1.对三位尾号相同的人数进行统计" << endl;
					std::cout << "  2.对相同归属地的人数做统计" << endl;
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
								std::cout << "输入这三位尾号" << endl;
								std::cin >> num;
								(*it).contacts_statistic_same_finalnum(num);
								std::cout << "成功!!!\n摁下任意键返回主界面" << endl;
								_getch();
								menu(relas);
							}
							else if (cnt == 2)
							{
								string address;
								std::cout << "输入归属地" << endl;
								std::cin >> address;
								(*it).contacts_statistic_same_address(address);
								std::cout << "成功!!!\n摁下任意键返回主界面" << endl;
								_getch();
								menu(relas);
							}
						}
						if (cnt == 3)cnt = 1;
						if (cnt == 0)cnt = 2;
						if (cnt == 1)
						{
							system("cls");
							std::cout << "->1.对三位尾号相同的人数进行统计" << endl;
							std::cout << "  2.对相同归属地的人数做统计" << endl;
						}
						else if (cnt == 2)
						{
							system("cls");
							std::cout << "  1.对三位尾号相同的人数进行统计" << endl;
							std::cout << "->2.对相同归属地的人数做统计" << endl;
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
				std::cout << "->1.对三位尾号相同的人数进行统计" << endl;
				std::cout << "  2.对相同归属地的人数做统计" << endl;
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
							std::cout << "输入这三位尾号" << endl;
							cin >> num;
							statistic_same_finalnum(relas, num);
							std::cout << "成功!!!\n摁下任意键返回主界面" << endl;
							_getch();
							menu(relas);
						}
						else if (tr == 2)
						{
							string address;
							std::cout << "输入归属地" << endl;
							cin >> address;
							statistic_same_address(relas, address);
							std::cout << "成功!!!\n摁下任意键返回主界面" << endl;
							_getch();
							menu(relas);
						}
					}
					if (tr == 3)tr = 1;
					if (tr == 0)tr = 2;
					if (tr == 1)
					{
						system("cls");
						std::cout << "->1.对三位尾号相同的人数进行统计" << endl;
						std::cout << "  2.对相同归属地的人数做统计" << endl;
					}
					else if (tr == 2)
					{
						system("cls");
						std::cout << "  1.对三位尾号相同的人数进行统计" << endl;
						std::cout << "->2.对相同归属地的人数做统计" << endl;
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
			std::cout << "->1.为某人的通讯录做统计" << endl;
			std::cout << "  2.做统计" << endl;
			std::cout << "  3.返回上一级界面" << endl;
			break;
		case 2:
			system("cls");
			std::cout << "  1.为某人的通讯录做统计" << endl;
			std::cout << "->2.做统计" << endl;
			std::cout << "  3.返回上一级界面" << endl;
			break;
		case 3:
			system("cls");
			std::cout << "  1.为某人的通讯录做统计" << endl;
			std::cout << "  2.做统计" << endl;
			std::cout << "->3.返回上一级界面" << endl;
			break;
		}
	}
}

void Menu::linkman_show(list<relationship>& relas)
{

	int a = 1;
	system("cls");
	std::cout << "->1.显示某人的所有联系人信息" << endl;
	std::cout << "  2.显示通讯录" << endl;
	std::cout << "  3.显示某人的信息（不包括通讯录信息）" << endl;
	std::cout << "  4.返回上一级界面" << endl;
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
				std::cout << "输入你想要显示联系人的人的名字" << endl;
				cin >> findname;
				list<relationship>::iterator it;
				for (it = relas.begin(); it != relas.end(); it++)
				{
					if ((*it).getname() == findname) break;
				}
				if (it == relas.end())
				{
					std::cout << "找不到这个人" << endl;
					std::cout << "摁下任意键返回" << endl;
					_getch();
					menu(relas);
				}
				else
				{
					(*it).contacts_pop_out();
					std::cout << "摁下任意键返回" << endl;
					_getch();
					menu(relas);
				}
			}
			else if (a == 2)
			{
				system("cls");

				pop_out(relas);
				std::cout << "\n\n摁下任意键返回" << endl;
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
				std::cout << "输入你想要显示联系人的人的名字" << endl;
				cin >> findname;
				list<relationship>::iterator it;
				for (it = relas.begin(); it != relas.end(); it++)
				{
					if ((*it).getname() == findname) break;
				}
				if (it == relas.end())
				{
					std::cout << "找不到这个人" << endl;
					std::cout << "摁下任意键返回" << endl;
					_getch();
					menu(relas);
				}
				else
				{
					(*it).show();
					std::cout << "摁下任意键返回" << endl;
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
			std::cout << "->1.显示某人的所有联系人信息" << endl;
			std::cout << "  2.显示通讯录" << endl;
			std::cout << "  3.显示某人的信息（不包括通讯录信息）" << endl;
			std::cout << "  4.返回上一级界面" << endl;
			break;

		case 2:
			system("cls");
			std::cout << "  1.显示某人的所有联系人信息" << endl;
			std::cout << "->2.显示通讯录" << endl;
			std::cout << "  3.显示某人的信息（不包括通讯录信息）" << endl;
			std::cout << "  4.返回上一级界面" << endl;
			break;

		case 3:
			system("cls");
			std::cout << "  1.显示某人的所有联系人信息" << endl;
			std::cout << "  2.显示通讯录" << endl;
			std::cout << "->3.显示某人的信息（不包括通讯录信息）" << endl;
			std::cout << "  4.返回上一级界面" << endl;
			break;
		case 4:
			system("cls");
			std::cout << "  1.显示某人的所有联系人信息" << endl;
			std::cout << "  2.显示通讯录" << endl;
			std::cout << "  3.显示某人的信息（不包括通讯录信息）" << endl;
			std::cout << "->4.返回上一级界面" << endl;
			break;
		}
	}
}



void Menu::menu(list<relationship>& relas)
{	
	system("cls");
	int choice = 1;
							//文本
	string welcome_text = "欢迎来到通讯录管理系统！你想要执行什么操作呢?";
	string tips = "\t通过 \""; tips += UP; tips += "\" 或 \""; tips += DOWN; tips += "\" 来决定你的选择";
	string esc_text = "P.S. 摁下“enter”以选择选项，摁下 “esc”键以退出系统";
	/*string choice_create = "  1.Build an address book(abandoned)";
	std::string to_choice_create = "->1.Build an address book(abandoned)";*/
	string choice_manage = "  1.管理通讯录";						//包含追加，删除，修改
	string to_choice_manage = "->1.管理通讯录";
	string choice_find = "  2.在通讯录中查看是否有某人";
	string to_choice_find = "->2.在通讯录中查看是否有某人";
	string choice_sort = "  3.排序你的通讯录";
	string to_choice_sort = "->3.排序你的通讯录";
	string choice_statistics = "  4.在通讯录做统计";
	string to_choice_statistics = "->4.在通讯录做统计";
	string choice_show = "  5.显示某项信息";
	string to_choice_show = "->5.显示某项信息";
	
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
		if (key == UP) choice--;												//UP键
		else if (key == DOWN) choice++;											//DOWN键
		else if (key == 13 or key == 10)
		{
			switch (choice)
			{
			//case 1:
			//	std::cout << "创建联系人" << endl;								//done
			//	create();
			//	menu(relas);
			//	break;
			case 1:
				std::cout << "管理联系人" << endl;								//done
				linkman_manage(relas);
				menu(relas);
				break;

			case 2:
				std::cout << "查找联系人" << endl;								//done
				linkman_find(relas);
				menu(relas);
				break;

			case 3:
				std::cout << "排序联系人" << endl;								//done
				linkman_sort(relas);
				menu(relas);
				break;

			case 4:
				std::cout << "统计联系人" << endl;								//done
				linkman_statistic(relas);
				menu(relas);
				break;

			case 5:
				std::cout << "显示联系人" << endl;								//done
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
