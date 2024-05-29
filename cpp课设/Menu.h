#pragma once
//#include<opencv2/opencv.hpp>
#include<easyx.h>	
#include<graphics.h>
#include<conio.h>
#include<cstdlib>
#include"tchar.h"
#include"relationship.h"
#include"file.h"

#define UP 'w'											//UP¼ü
#define DOWN 's'										//DOWN¼ü

extern class Vec;
extern vector<Vec> vec;

//using namespace cv;

class Menu
{
public:
	void linkman_manage(list<relationship>& relas);
	void linkman_find(list<relationship>& relas);
	void linkman_sort(list<relationship>& relas);
	void linkman_statistic(list<relationship>& relas);
	void linkman_show(list<relationship>& relas);
	void menu(list<relationship>& relas);
};

