#pragma once
#include<windows.h>
#include"relationship.h"

#define FILENAME_NUMS 1024

class file
{
public:

						//��д����ʱ�������ӣ�ɾ�����޸Ĳ���ʱ˳��������������ͺ�
						//����������͸�

	void file_write(relationship a);					//������ϵ��
	void file_change(relationship a);					//�޸���ϵ��
	void file_delete(relationship a);					//ɾ����ϵ��
};

