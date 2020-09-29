#include <stdio.h>
#include <stdlib.h>
#include "tools.h"
#include "teacher.h"
#include "teacher_tools.h"

void stu_add_all()
{
	system("clear");
	printf("按1：手动添加\n按2：批量导入\n按3：返回\n");
	switch(getch())
	{
		case '1': stu_add(); student_file(); break;
		case '2': stu_add2(); student_file(); break;
		case '3': break;
	}
}

void stu_score_all()
{
	system("clear");
	printf("按1：手动添加\n按2：批量导入\n按3：返回\n");
	switch(getch())
	{			
		case '1': stu_score();student_file(); break;
		case '2': stu_score2();student_file(); break;
		case '3': break;
	}
}

int tch_chance[100]={0};	// 检测教师密码错误登录机会

void if_success(int i,const char* key)		// 判断登录是否成功
{
	if(-1==tch[i].num)
	{
		show_str("该账户已锁定，请找校长解锁",0.5);
		return ;
	}
	else
	{
		if(tch_chance[i]<3)
		{
			if(0==strcmp(key,tch[i].key))
			{
				show_str("登录成功",1);
				if(tch[i].num!=1) change(i);
				tch_chance[i]=0;
				tch_show();
				return;				
			}
			else
			{
				show_str("密码错误",0.5);
				tch_chance[i]++;
				if(0==2-tch_chance[i]) tch[i].num=-1;
			}
		}
	}
}

void change(int i)		// 第一次登录时修改密码
{
	system("clear");
	printf("----------教师管理系统----------\n");
	printf("第一次登录，请修改密码\n");
	char n[10];
	printf("请输入修改后密码\n");
	scanf("%s",n);
	printf("修改成功！\n");
	strcpy(tch[i].key,n);
	tch[i].num=1;
	show_str("修改成功！",0.5);
	}
void tch_sign(void)		// 教师登录界面
{
	for(;;)
	{
		system("clear");
		printf("----------教师管理系统----------\n");
		printf("请输入工号\n");
		char key[10],id[20];
		scanf("%s",id);
		printf("请输入密码\n");
		stdin->_IO_read_ptr = stdin->_IO_read_end;
		gets(key);
		int i=0;
		while(0!=strcmp(tch[i].id,id) && i<100)
		{
			i++;
		}
		if(100==i)
		{
			show_str("该工号不存在，请重新输入",0.5);
			return ;
		}
		else
		{
			if_success(i,key);
		}
	}
}

void system_show(void)		// 清屏，展示教师管理界面
{
	system("clear");
	printf("----------教师管理系统----------\n");
	printf("1.添加学生\n");
	printf("2.删除学生\n");
	printf("3.查找学生\n");
	printf("4.修改学生信息\n");
	printf("5.录入学生成绩\n");
	printf("6.重置学生密码\n");
	printf("7.显示所有在校学生信息\n");
	printf("8.显示所有退出学生信息\n");
	printf("9.解锁学生账号\n");
	printf("q.退出\n");
	printf("请选择:\n");
}
void tch_show()			// 教师端功能连接
{
for(;;)
{
	system_show();
	switch(getch())
	{
		case '1': stu_add_all();break;
		case '2': stu_del();student_file();break;
		case '3': stu_find();break;
		case '4': stu_modify(); student_file(); break;
		case '5': stu_score_all();break;
		case '6': while(0==stu_reset()){}; student_file(); break;
		case '7': tch_show_in();student_file(); break;
		case '8': tch_show_out();student_file(); break;
		case '9': lock_out();student_file(); break;
		case 'q': return;	
	}
}
}

	

