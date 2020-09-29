#include <stdio.h>
#include<stdlib.h>
#include"master.h"
#include"getch.h"
#include"system.h"
#include"student.h"
#include"teacher.h"
#include"tools.h"
void Run_system(void)//系统运行
{
	FILE* frp=fopen("校长登录判定.txt","r+");
	if(NULL==frp)
	{
		perror("fopen");
		return;
	}
	rewind(frp);
	fscanf(frp,"%d %s",&m.flag,m.master_pw);//校长继承上次登录状态
	fclose(frp);
		
	FILE* fwp=fopen("在职教师.txt","a+");
	rewind(fwp);
	for(int i=0;i<100;i++)//教师继承上次修改状态
	{		
		fscanf(fwp,"--%d 姓名:%s 性别:%c 工号:%s 密码:%s\n",&tch.num[i],tch.name[i],&tch.sex[i],tch.id[i],tch.key[i]);			
	}
	fclose(fwp);
	FILE* fwp1=fopen("离职教师.txt","a+");
	rewind(fwp1);
	for(int i=0;i<100;i++)//离职教师获取上次修改状态
	{	
		fscanf(fwp1,"--%d 姓名:%s 性别:%c 工号:%s",&l_tch.num[i],l_tch.name[i],&l_tch.sex[i],l_tch.id[i]);	
			
	}
	fclose(fwp1);
	
	FILE* fwp2=fopen("在校学生信息.txt","a+");
	rewind(fwp2);
	for(int i=0;i<100;i++)//在校学生继承上次修改状态
	{
			
		fscanf(fwp2,"--%d 姓名:%s 性别:%c 学号:%d 语文:%d 数学:%d 英语:%d 密码:%s\n",&stu.pd[i],stu.name[i],&stu.sex[i],&stu.ID[i],&stu.Chinese[i],&stu.Math[i],&stu.English[i],stu.pw[i]);		
		
	}
	fclose(fwp2);
	FILE* fwp3=fopen("退学学生.txt","a+");
	rewind(fwp3);
	for(int i=0;i<100;i++)//退学学生获取上次修改状态
	{			
		fscanf(fwp3,"--%d 姓名:%s 性别:%c 学号:%d 语文:%d 数学:%d 英语:%d",&l_stu.pd[i],l_stu.name[i],&l_stu.sex[i],&l_stu.ID[i],&l_stu.Chinese[i],&l_stu.Math[i],&l_stu.English[i]);	
			
	}
	fclose(fwp3);
	for(;;)
	{
		system("clear");
			
		printf("<－－－－欢迎来到学生管理系统－－－－>\n");
		printf("|　　　　　　请选择登录　　　　　　  |\n");
		printf("|            1.学生                  |\n|            2.老师                  |\n|            3.校长                  |\n|            4.退出                  |\n");
		printf("<－－－－－－－－－－－－－－－－－－>\n");
		switch(getch())
		{
			case '1': run_stu();student_file();break;
			case '2': tch_sign();teacher_file();break;
			case '3': master();break; 
			case '4': return;
		}
		
		
	}
}
