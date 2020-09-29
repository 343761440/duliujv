#include <stdio.h>
#include <string.h>
#include "student.h"
#include"tools.h"
//进入学生界面
void run_stu(void)
{
	int num1,snum=0;//num1学号,snum判断该学号在结构体中的位置
	system("clear");
	int cnt=0; //登录次数
	char num2[10];//密码
	printf("---欢迎进入学生管理系统!---\n");
	printf("输入学号:\n");
	scanf("%d",&num1);

	//判断输入的学号输入是否合法
	for(int i=0;i<100;i++)
	{
		if(num1 != stu.ID[snum])
		{	
			snum++;
		}
		else if(num1 == stu.ID[snum])
		{
			break;	
		}
	}
	if(snum == 100 && num1 != stu.ID[99])
	{
		printf("学号输入错误!\n");
		sleep(1);
		return;
	}
	printf("输入密码:\n");
	scanf("%s",num2);

	//判定账号是否被锁
	if(-1 == stu.pd[snum])
	{
		printf("账号被锁定，请寻找老师解锁!\n");
		sleep(1);
		return;
	}
	for(;;)
	{
	if(2 == cnt)
	{
		printf("三次输入密码错误，请寻找教师!\n");
		sleep(1);
		stu.pd[snum]=-1;
		return ;
	}
	//密码判定是否正确
	if(strcmp(stu.pw[snum],num2)==0)
	{
		printf("登录成功!\n");
		fflush(stdout);
		usleep(500000);
		break;	
	}
	else
	{
		printf("密码错误,重新输入密码:\n");
		scanf("%s",num2);
		cnt++;
	}
	}

	//判定是否是第一次输入密码
	if(0 == stu.pd[snum])
	{
		char str[10];
		printf("重置密码，请输入新密码:\n");
		scanf("%s",str);
		strcpy(stu.pw[snum],str);
		stu.pd[snum]=1;	
	}

for(;;)
{
	system("clear");
	printf("1.查询排名\n");
	printf("2.修改密码\n");
	printf("3.查看个人信息\n");
	printf("4.退出学生系统\n");
	switch(getch())
	{
		case '1':find(snum);break;	
		case '2':cpd(snum);break;	
		case '3':look(snum);break;
		case '4':return ;	
	}
}

}
