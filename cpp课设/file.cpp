#include "file.h"

void file::file_write(relationship a)
{
	string filename = a.getname();
	filename.append(".txt");
	ofstream outfile(filename);
	if (!outfile.is_open())
	{
		cerr << "创建文件失败:(";
		return;
	}
	if (a.gettele_num_2() == "")
	{
		outfile << a.getname() << "\n" << a.getaddress() << "\n" << a.gettele_num_1() << "\n";
	}
	else
	{
		outfile << a.getname() << "\n" << a.getaddress() << "\n" << a.gettele_num_1() << "\n" << a.gettele_num_2() << "\n";
	}
	outfile.close();
}

void file::file_change(relationship a)
{
	string filename = a.getname();
	filename.append(".txt");
	ofstream outfile(filename);
	if (!outfile.is_open())
	{
		cerr << "修改文件失败:(";
		return;
	}
	if (a.gettele_num_2() == "")
	{
		outfile << a.getname() << "\n" << a.getaddress() << "\n" << a.gettele_num_1() << "\n";
	}
	else
	{
		outfile << a.getname() << "\n" << a.getaddress() << "\n" << a.gettele_num_1() << "\n" << a.gettele_num_2() << "\n";
	}
	outfile.close();
}

void file::file_delete(relationship a)
{
	string filename = a.getname();
	filename.append(".txt");
	const char* filepath = filename.c_str();
	if (DeleteFileA(filepath))
	{
		//cout << "成功删除文件！" << endl;
	}
	else
	{
		cerr << "删除文件时出错......" << GetLastError() << endl;
	}
}
