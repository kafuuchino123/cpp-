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
	
	统一要求，写注释！写注释！！写注释！！！

	函数：
		建立：list<relationship> relas;
		追加：增加某人的信息，或增加卡二，或某人增加某个联系人
		删除：删某人，删一个号码，删某人的某个联系人
		修改：找，改
		查：找某人，输出name,tele1,tele2,address；找某人的联系人中是否有某人
		排序：根据输入决定要基于什么排序，比如name，address......再排序
		统计：统计，输出，统计内容包括相同归属地的联系人有多少，尾号为特定数，或尾号相同的人数有多少，输出
		显示：应该是输出某联系人的所有信息，或要求输出所有name，address啥的，不懂

	界面：
		美观好看简洁，每一次操作要进行清屏，使得终端或窗口干净简洁
		可以用终端实现，也可以用窗口写界面
		界面的实现要求允许用户误操作，即我在主界面点进了一个界面，应该有选项允许我返回上一界面或主界面，尽量不要用goto函数
		主界面函数-->menu()

	文件储存：
		cpp文件储存我不是很了解，用fstream库进行操作，要求实现的功能：
			用txt文件储存
			上面函数的追加，删除，修改都要对应与文件储存同步进行

			如果能力强的话，可以尝试写一个初始化函数，每次运行函数的时候读取文件进行一个相应的初始化
			，就是程序运行时把一开始未初始化的链表用文件中的name，tele1，tele2，address什么的赋给链表中
			的成员

		我没写过cpp的文件操作，可能这个有点困难。能写就写，不能写就直接在程序里面定义张三李四王五的信息

	其他功能：
		我没想到有啥，有啥想法可以说说
*/

/*
	联系人:
		name
		telephone number 1
		telephone number 2
		address
		contacts																	//联系人
*/

class relationship
{
private:	
	string name;																	//默认名字不会重复
	string tele_num_1;																//卡一,中国号码，11位，尾号是3位
	string tele_num_2;																//卡二,允许为空
	string address;																	//归属地
	static list<relationship> contacts;													//联系人
public:

	friend ostream& operator<<(ostream& res, const relationship& r);				//重载<<
	bool operator!= (relationship& other);											//重载!=
	bool operator== (relationship& other);											//重载==

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
	void contacts_initial(list<relationship>& re);									//联系人列表初始化
	string getname();																//五个成员均是私有成员，该函数用于访问私有成员
	string getaddress();															
	string gettele_num_1();
	string gettele_num_2();
	list<relationship> getcontacts();

	//修改
	void name_change(string newname);												//改名字
	void tele_num_1_change(string newtele);											//改卡一
	void tele_num_2_change(string newtele);											//改卡二
	void address_change(string newaddress);											//改地址
	void check_tele();																//检查卡一是否为空

	//增加
	void contacts_add(relationship addone);											//增加联系人

	//删除
	void contacts_del(relationship delone);											//删除联系人

	//联系人修改
	void contacts_change(relationship oldone, relationship contacts);				//修改某个联系人
	void contacts_name_change(string oldname, string newname);						//改某联系人的名字
	void contacts_tele_num_1_change(string name, string newtele);					//改某联系人的卡一
	void contacts_tele_num_2_change(string name, string newtele);					//改某联系人的卡二
	void contacts_address_change(string name, string newaddress);					//改某联系人的归属地

	//查找
	bool contacts_find(relationship findone);										//指定查找某人的某个联系人是否存在
	void contacts_find_by_name(string findname);									//根据name查找某联系人，输出该联系人信息
	void contacts_find_by_address(string findaddress);								//address查找
	void contacts_find_by_tele_num(string findtele_num);							//tele_num查找

	//排序
	static void contacts_sort_by_name();											//根据name排序,left==relas.begin(),right==relas.end()								
	static void contacts_sort_by_address();											//根据address排序，下面两个同理

	//统计
	void contacts_statistic_same_address(string add);								//统计这个人的所有联系人是某归属地的人数并输出						
	void contacts_statistic_same_finalnum(string num);								//统计这个人的所有联系人的尾号是num的人数并输出

	//显示
	void contacts_pop_out();														//输出该成员所有的联系人信息
	void show();																	//输出除了联系人之外的信息

	//其他 一些辅助函数
	static bool compare_name(relationship& a, relationship& b);
	static bool compare_address(relationship& a, relationship& b);
};

//建立通讯录

list<relationship> create();

//增加

void relas_add(list<relationship>& relas);															//增加

//删除

void relas_delete(list<relationship>& relas, string delname);										//删

//修改

void relas_change_name(list<relationship>& relas, string oldname, string newname);					//依据旧名字来寻找并进行修改

void relas_change_address(list<relationship>& relas, string name,string newaddress);				//改新地址

void relas_change_tele(list<relationship>& relas, string name,string oldtele,string newtele);		//依据输入的原号码来修改新号码

//查找

void relas_find_by_name(list<relationship>& relas, string name);

void relas_find_by_address(list<relationship>& relas, string address);

void relas_find_by_tele_num(list<relationship>& relas, string tele);

//排序

void sort_by_name(list<relationship>& relas);

void sort_by_address(list<relationship>& relas);

//统计

void statistic_same_address(list<relationship>& relas, string add);

void statistic_same_finalnum(list<relationship>& relas, string num);

//显示
	//输出一个联系人链表的所有人的信息(不包括某人的联系人)

void pop_out(list<relationship>& relas);

