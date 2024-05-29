#pragma once
#include<windows.h>
#include"relationship.h"

#define FILENAME_NUMS 1024

class file
{
public:

						//在写界面时进行增加，删除，修改操作时顺带调用这个函数就好
						//有其他需求就改

	void file_write(relationship a);					//增加联系人
	void file_change(relationship a);					//修改联系人
	void file_delete(relationship a);					//删除联系人
};

