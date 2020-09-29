#include <stdio.h>
#include<string.h>
#include"master.h"
#include"system.h"
#include"tools.h"
//校长登录函数
void master(void)
{
	for(;;)
	{
		char m_password[10]={},pw[10]={};
		system("clear");
		printf("------欢迎来到校长管理系统------\n");
		if(1!=m.flag && -1!=m.flag)//判断是否第一次登录
		{
			printf("第一次登录请修改密码:");
			gets(m_password);
			strcpy(m.master_pw,m_password);
			m.flag=1;
			printf("密码修改成功!\n");
		}
		FILE* fwp=fopen("校长登录判定.txt","w");
		fprintf(fwp,"%d %s",m.flag,m.master_pw);
		fclose(fwp);
		printf("请输入密码:");
		gets(pw);
		if(strcmp(pw,m.master_pw)==0)
		{
			printf("登录成功!\n");
			sleep(1);		
			master_show();
			return;
		}
		else
		{
			printf("密码错误!请重新输入!\n");
			sleep(1);
		}
	}
}
void master_show(void)//校长界面显示函数
{
for(;;)
{
	system("clear");
	printf("-------校长的系统--------\n");
	printf("1.重置自己的密码\n");
	printf("2.重置教师的密码\n");
	printf("3.添加教师\n");
	printf("4.删除教师\n");
	printf("5.显示所有在职教师\n");
	printf("6.显示所有离职教师\n");
	printf("7.解锁教师\n");
	printf("8.退出系统\n");
	switch(getch())
	{
		case '1':mpw_c();break;//修改校长的密码
		case '2':tpw_c();teacher_file();break;//重置教师密码
		case '3':add_t();teacher_file();break;//增加教师
		case '4':del_t();teacher_file();break;//删除教师
		case '5':view_tch();break;//显示在职教师
		case '6':view_gtch();break;//显示离职教师
		case '7':lock_out_t();teacher_file();break;//解锁教师
		case '8':return ;//退出系统
	}
	
	}
}
