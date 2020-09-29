#include <stdio.h>
#include "student.h"
#include"teacher.h"
#include"tools.h"
#include "teacher_tools.h"
//校长函数--------------------------------------------------
void mpw_c(void)//重置校长的密码
{
	system("clear");
	char pw_c[20]={};
	printf("----校长密码重置----\n");
	printf("请输入修改后的密码:\n");
	gets(pw_c);
	if(strlen(pw_c)>20) 
	{
		printf("输入格式有误！\n");
		fflush(stdout);
		usleep(500000);
		return;
	}
	strcpy(m.master_pw,pw_c);
	printf("密码修改成功!\n");
	sleep(1);
	FILE* fwp=fopen("校长登录判定.txt","w");
	fprintf(fwp,"%d %s",m.flag,m.master_pw);
	fclose(fwp);
	return;
}
void tpw_c(void)//重置教师的密码
{
	for(;;)
	{
	system("clear");
	printf("----重置教师的密码----\n");
	char pw_c[20]={};
	char c_id[20]={};
	printf("请输入要修改的教师的工号:\n");
	scanf("%s",c_id);
	for(int i=0;i<100;i++)
	{
		if(0==strcmp(tch.id[i],c_id))
		{
			printf("请输入重置后的密码:\n");
			scanf("%s",pw_c);
			if(strlen(pw_c)>20) 
			{
				printf("密码输入格式有误！\n");
				fflush(stdout);
				usleep(500000);
				return;
			}			
			strcpy(tch.key[i],pw_c);
			printf("修改成功!");
			fflush(stdout);
			usleep(500000);
	        return ;
		}
	}
	printf("工号输入错误!\n");
	sleep(1);
	return ;
	}
}
void add_t(void)//增加教师
{
	system("clear");
	printf("------增加教师------\n");
	char tch_name[20]={},tch_id[20]={},tch_sex;
	printf("请输入你要添加的教师信息:\n");
	printf("1.姓名:");
	gets(tch_name);
	for(int i=0;tch_name[i];i++)
	{
		if((tch_name[i]>='0' && tch_name[i]<='9') || i>20)
		{
			printf("输入错误!\n");
			fflush(stdout);
			usleep(500000);
			return;
		}
	}
	printf("2.性别(m代表男,w代表女):");
	scanf("%c",&tch_sex);
	if(tch_sex!='w' && tch_sex!='m')
	{
		printf("输入错误!\n");
		fflush(stdout);
		usleep(500000);
		return;
	}
	printf("3.工号:");
	scanf("%s",tch_id);
	for(int i=0;tch_id[i];i++)
	{
		if((tch_id[i]<='0' && tch_id[i]>='9') || i>20)
		{
			printf("输入错误!\n");
			fflush(stdout);
			usleep(500000);
			return;
		}
	}
	for(int i=0;i<100;i++)
	{
		if(0==strcmp(tch.id[i],tch_id))
		{
			printf("工号重复!\n");
			fflush(stdout);
			usleep(500000);
			return;
		}
		else if(tch.sex[i]!='w' && tch.sex[i]!='m')
		{
			strcpy(tch.name[i],tch_name);
			strcpy(tch.id[i],tch_id);
			tch.sex[i]=tch_sex;
			strcpy(tch.key[i],"123");
			printf("添加成功!");
			fflush(stdout);
			usleep(500000);
			return;
		}	
	}
}
void del_t(void)//删除教师
{
	int j=0;
	system("clear");
	printf("------删除教师------\n");
	char tch_name[20]={},tch_id[20]={},tch_sex;
	printf("请输入你要删除的教师信息:\n");
	printf("1.姓名:");
	gets(tch_name);
	for(int i=0;tch_name[i];i++)
	{
		if((tch_name[i]>='0' && tch_name[i]<='9')|| i>20)
		{
			printf("输入错误!\n");
			fflush(stdout);
			usleep(500000);
			return;
		}
	}
	printf("2.性别(m代表男,w代表女):");
	scanf("%c",&tch_sex);
	if(tch_sex!='w' && tch_sex!='m')
	{
		printf("输入错误!\n");
		fflush(stdout);
		usleep(500000);
		return;
	}
	printf("3.工号:");
	scanf("%s",tch_id);
	for(int i=0;tch_id[i];i++)
	{
		if((tch_id[i]<='0' && tch_id[i]>='9') || i>20)
		{
			printf("输入错误!\n");
			fflush(stdout);
			usleep(500000);
			return;
		}
	}
	for( j=0;j<100;j++)
	{
		if(strcmp(tch.name[j],tch_name)==0 && strcmp(tch.id[j],tch_id)==0)
		{
			strcpy(tch.name[j],"\0");
			strcpy(tch.id[j],"\0");
			strcpy(tch.key[j],"\0");
			tch.sex[j]='x';
			break;
		}
	}
	if(100==j)
	{
		printf("找不到!");
		fflush(stdout);
		usleep(500000);
		return;
	}
	for(int i=0;i<100;i++)//将删除教师放入离职教师中
	{
		if(l_tch.sex[i]!='w'&& l_tch.sex[i]!='m')
		{
			strcpy(l_tch.name[i],tch_name);
			strcpy(l_tch.id[i],tch_id);
			l_tch.sex[i]=tch_sex;
			printf("删除成功！");
			fflush(stdout);
			usleep(500000);
			return;
		}	
	}
}
void view_tch(void)//显示所有在职教师
{
	system("clear");
	printf("----在职教师信息---\n");
	for(int i=0;i<100;i++)
	{
		if(tch.sex[i]=='w' || tch.sex[i]=='m')
		{
			printf("姓名:%s 工号:%s 性别:",tch.name[i],tch.id[i]);
			tch.sex[i]=='w'?puts("女"):puts("男");
		}		
	}
	printf("按任意键退出.");
	switch(getch())
	{
		default: return ;
	}
}
void view_gtch(void)//显示离职教师
{
	system("clear");
	printf("----离职教师信息---\n");
	for(int i=0;i<100;i++)
	{
		if(l_tch.sex[i]=='w' || l_tch.sex[i]=='m')
		{
			printf("姓名:%s 工号:%s 性别:",l_tch.name[i],l_tch.id[i]);
			l_tch.sex[i]=='w'?puts("女"):puts("男");
		}	
	}
	printf("按任意键退出.");
	switch(getch())
	{
		default: return ;
	}
}
void teacher_file(void)//教师信息实时更新
{
	FILE* fwp=fopen("在职教师.txt","w+");
	if(NULL==fwp)
	{
		perror("fopen");
		return;
	}
	for(int i=0;i<100;i++)
	{
		if(tch.sex[i]=='w' || tch.sex[i]=='m')
		{
			fprintf(fwp,"--%d 姓名:%s 性别:%c 工号:%s 密码:%s\n",tch.num[i],tch.name[i],tch.sex[i],tch.id[i],tch.key[i]);
		}
	}
	fclose(fwp);
	FILE* fwp1=fopen("离职教师.txt","w+");
	if(NULL==fwp1)
	{
		perror("fopen");
		return;
	}
	for(int i=0;i<100;i++)
	{
		if(l_tch.sex[i]=='w' || l_tch.sex[i]=='m')
		{
			
			fprintf(fwp1,"--%d 姓名:%s 性别:%c 工号:%s",l_tch.num[i],l_tch.name[i],l_tch.sex[i],l_tch.id[i]);
		}
	}
	fclose(fwp1);
}
void lock_out_t(void)
{
	system("clear");
	char lock_id[20]={};
	printf("请输入要解锁的教师的工号：");
	scanf("%s",lock_id);
	for(int i=0;i<100;i++)
	{
		if(strcmp(tch.id[i],lock_id)==0 && tch.num[i]==-1)
		{
			tch.num[i]=1;
			printf("解锁成功！");
			fflush(stdout);
			usleep(500000);
			return;
		}
	}
	printf("输入有误！");
	fflush(stdout);
	usleep(500000);
}
//--------------------------------------------------------------------------
//学生函数-----------------------------------------------------------------------
void find(int num)//查排名
{
	system("clear");
	printf("------查看排名------\n");
	int pm =1;
	float avg=((float)stu.Chinese[num]+(float)stu.Math[num]+(float)stu.English[num])/3;//平均分
	for(int i=0;i<100;i++)//排名
	{
		if(stu.Chinese[i]+stu.Math[i]+stu.English[i]>stu.Chinese[num]+stu.Math[num]+stu.English[num])
		{
			pm++;	
		}
	}
	int max = (stu.Chinese[num]>stu.Math[num]) ? stu.Chinese[num] : stu.Math[num];//最高分，最低分
	    max = (max>stu.English[num]) ? max : stu.English[num];
	int min = (stu.Chinese[num]<stu.Math[num]) ? stu.Chinese[num] : stu.Math[num];
	    min = (min<stu.English[num]) ? min : stu.English[num];
	printf("排名:%d\n平均分:%4.1f\n最高分:%d\n最低分:%d\n",pm,avg,max,min);
	printf("按任意键继续");
	switch(getch())
	{
		default : return;
	}
}
//修改密码
void cpd(int num)
{
	system("clear");
	printf("------修改密码------\n");
	char str[10];
	printf("请输入修改后的密码:\n");
	scanf("%s",str);
	strcpy(stu.pw[num],str);
	printf("修改成功!\n");
	fflush(stdout);
	usleep(500000);
	return ;
}
//查看个人信息
void look(int num)
{
	system("clear");
	printf("------学生个人信息------\n");
	printf("姓名:%s\n性别:%c\n学号:%d\n语文:%d\n数学:%d\n英语:%d\n",stu.name[num],stu.sex[num],stu.ID[num],stu.Chinese[num],stu.Math[num],stu.English[num]);	
	printf("按任意键继续");
	switch(getch())
	{
		default : return;
	}
}

void student_file(void)//学生信息实时更新
{
	FILE* fwp=fopen("在校学生信息.txt","w+");
	if(NULL==fwp)
	{
		perror("fopen");
		return;
	}
	for(int i=0;i<100;i++)
	{
		if(stu.sex[i]=='w' || stu.sex[i]=='m')
		{
			fprintf(fwp,"--%d 姓名:%s 性别:%c 学号:%d 语文:%d 数学:%d 英语:%d 密码:%s\n",stu.pd[i],stu.name[i],stu.sex[i],stu.ID[i],stu.Chinese[i],stu.Math[i],stu.English[i],stu.pw[i]);
		}
	}
	fclose(fwp);
	FILE* fwp1=fopen("退学学生.txt","w+");
	if(NULL==fwp1)
	{
		perror("fopen");
		return;
	}
	for(int i=0;i<100;i++)
	{
		if(l_stu.sex[i]=='w' || l_stu.sex[i]=='m')
		{
			
			fprintf(fwp1,"--%d 姓名:%s 性别:%c 学号:%d 语文:%d 数学:%d 英语:%d",l_stu.pd[i],l_stu.name[i],l_stu.sex[i],l_stu.ID[i],l_stu.Chinese[i],l_stu.Math[i],l_stu.English[i]);
		}
	}
	fclose(fwp1);
}

//教师函数--------------------------------------------------------------------------
void stu_add(void)//添加学生
{                
	system("clear");//超额警告
	if(stu_count>=100)
	{
		printf("超出学生人数限制。");
		return;
	}	
	int i=0;
	while(stu.sex[i]) i++;
	for(;;)
	{
		system("clear");
		printf("请输入学生姓名\n");
		scanf("%s",stu.name[i]);//检测输入
		if(strlen(stu.name[i])>20)
		{
			printf("姓名过长，请重新输入\n");
			fflush(stdout);
			usleep(500000);
			return;	
		}
		printf("请输入学生性别(“m”为男,“w”为女)\n");
		scanf(" %c",&stu.sex[i]);
		if('m'!=stu.sex[i] && 'w'!=stu.sex[i])
		{
			printf("性别输入有误，请重新输入\n");
			fflush(stdout);
			usleep(500000);
			return;
		}
		break;
	}
	for(int i=0;i<100;i++)//自动生成学号
	{
		if(0!=stu.ID[i] && stu.ID[i]>ID_max) ID_max=stu.ID[i];
		if(l_stu.sex[i]=='w' || l_stu.sex[i]=='m') out_stu++;
	}
	stu.ID[i]=ID_max+out_stu+1;
	stu_count++;
	strcpy(stu.pw[i],"123");//初始化学生密码为123
	printf("添加成功。\n");
	fflush(stdout);
	usleep(500000);
	return;
}
void stu_del(void)//删除学生
{
	for(;;)
	{
		system("clear");
		int i=0;					//比对信息
		int key;
		printf("请输入要删除的学生学号：");
		scanf("%d",&key);
		do
		{
			if (stu.sex[i])
			{
				if(stu.ID[i]==key)
				{
					break;
				}
			}
		}while(++i<100);
		if(i<100)
		{
			int key1;
			printf("请再输入一遍，确认要删除的学生学号：");
			scanf("%d",&key1);
			if(key==key1)
			{		
				printf("删除%s的信息成功。\n",stu.name[i]);
				fflush(stdout);
				usleep(500000);
				l_stu.sex[i]=stu.sex[i];//记录退学学生的信息。
				l_stu.ID[i]=stu.ID[i];
				strcpy(l_stu.name[i],stu.name[i]);
				l_stu.Chinese[i]=stu.Chinese[i];
				l_stu.English[i]=stu.English[i];
				l_stu.Math[i]=stu.Math[i];
				stu.sex[i]=0;
				stu.ID[i]=0;
				strcpy(stu.name[i],"\0");
				stu.Chinese[i]=0;
				stu.English[i]=0;
				stu.Math[i]=0;
				stu.pd[i]=0;
				strcpy(stu.pw[i],"\0");
				stu_count--;			
				printf("按任意键继续");
				switch(getch())
				{
					default : return;
				}
			}
		}
		else
		{
			printf("没有此学生。");
			fflush(stdout);
			usleep(500000);
			return ;	
		}
	}
}
void stu_find(void)//查找学生
{
	system("clear");
	char name[20]={};
	int ID,i=0,j=0;								
	printf("1.按姓名查找\n");//两种方法分类查找
	printf("2.按学号查找\n");
	switch(getch())
	{
		case '1':
			printf("请输入姓名:");
			scanf("%s",name);	
			for(i=0;i<100;i++)
			{
				if(stu.sex[i]&&(strcmp(stu.name[i],name)==0))
				{
					printf("%s %s %d 语文：%d 数学：%d 英语：%d\n",stu.name[i],'w'==stu.sex[i]?"女":"男",stu.ID[i],stu.Chinese[i],stu.Math[i],stu.English[i]);	
				}	
			}
			break;
		case '2':
			printf("请输入学号:");
			scanf("%d",&ID);
			for(j=0;j<100;j++)
			{
				if(stu.sex[j]&&stu.ID[j]==ID)
				{
					printf("姓名:%s 性别:%s 学号:%d 语文：%d 数学：%d 英语：%d\n",stu.name[j],'w'==stu.sex[i]?"女":"男",stu.ID[j],stu.Chinese[j],stu.Math[j],stu.English[j]);	
				}	
			}
			break;
	}
	stdin->_IO_read_ptr=stdin->_IO_read_end;
	printf("按任意键继续");
	switch(getchar())
	{
		default : return;
	}
}
void stu_modify(void)//修改学生信息
{
	for(;;)
	{
		system("clear");
		char key[20]={};//比对信息。
		printf("输入修改的学生姓名：");
		scanf("%s",key);
		int i=0,stu_Chinese,stu_Math,stu_English;
		for(i=0;i<100;i++)
		{
			if(stu.sex[i]&&0==strcmp(stu.name[i],key))
			{
				printf("输入修改后的信息（姓名、性别、语文、数学和英语成绩：");
				scanf("%s %c %d %d %d",stu.name[i],stu.sex+i,&stu_Chinese,&stu_Math,&stu_English);
				if(stu_Chinese>100 || stu_Chinese<0 || stu_Math>100 || stu_Math<0 || stu_English>100 || stu_English<0)
				{
					printf("成绩输入有误!\n");
					fflush(stdout);
					usleep(500000);
					return;
				}
				stu.Chinese[i]=stu_Chinese;
				stu.Math[i]=stu_Math;
				stu.English[i]=stu_English;
				printf("修改成功。\n");
				fflush(stdout);
				usleep(500000);
				return;
			}
		}
		printf("未找到此学生。\n");
		fflush(stdout);
		usleep(500000);
		return ;
	}
}
void stu_score(void)//录入成绩
{
	system("clear");
	char key[20]={};
	int id=0;
	printf("输入录入成绩的学生姓名和学号：");
	scanf("%s %d",key,&id);
	int i=0,stu_Chinese,stu_Math,stu_English;
	for(i=0;i<100;i++)
	{
		if(stu.sex[i]&&0==strcmp(stu.name[i],key) && id==stu.ID[i])
		{
			for(;;)
			{
				system("clear");
				printf("输入需要录入的成绩(语文 数学 英语)：");
			scanf("%d%d%d",&stu_Chinese,&stu_Math,&stu_English);
				if(stu_Chinese>100 || stu_Chinese<0 || stu_Math>100 || stu_Math<0 || stu_English>100 || stu_English<0)
				{
				printf("成绩输入有误，请再次输入\n");
				fflush(stdout);
				usleep(500000);
				return;
				}
				break;
			}
			stu.Chinese[i]=stu_Chinese;
			stu.Math[i]=stu_Math;
			stu.English[i]=stu_English;
			printf("录入%s成绩成功。\n",stu.name[i]);
			fflush(stdout);
			usleep(500000);
			return;
		}
	}
	printf("未找到此学生。\n");
	fflush(stdout);
	usleep(500000);

}
void stu_add2(void)//批量导入学生信息
{
	system("clear");
	printf("请输入文件路径");
	char filename[100];
	scanf("%s",filename);				//信息来源文件
	FILE *fp=fopen(filename,"r");
	if(fp==NULL)
	{
		printf("路径有误");
		fflush(stdout);
		usleep(500000);	
		return;	
	}
	int i =0;
	while(!feof(fp))
	{	
		while(stu.sex[i]) i++;
		fscanf(fp,"%s %c\n",stu.name[i],&stu.sex[i]);
		if(stu.sex[i]!='w' && stu.sex[i]!='m' )
		{
			printf("文件信息有误，导入中止！\n");
			fflush(stdout);
			usleep(500000);	
			return;
			}
		for(int i=0;i<100;i++)
		{
			if(stu.ID[i]!=0 && stu.ID[i]>ID_max)
			{
				ID_max=stu.ID[i];
			}
		}
		stu.ID[i]=ID_max+out_stu+1;//自动生成学号
		stu_count++;	
		if(stu_count>=100)
		{
			printf("超出学生人数限制。");
			fflush(stdout);
			usleep(500000);			
			return;
		}	
		strcpy(stu.pw[i],"123");
	}	
	fclose(fp);
	printf("录入完成！\n");
	fflush(stdout);
	usleep(500000);
	return;
}
void stu_score2(void)//批量导入学生成绩
{
	printf("请输入文件路径");
	char filename[100];
	scanf("%s",filename);
	FILE *fp=fopen(filename,"r");
	if(fp==NULL)
	{
		printf("路径有误");
		fflush(stdout);
		usleep(500000);		
		return;		
	}
	int i=0;
	char name[100][20]={};
	while(!feof(fp))
	{	
		int j=0;
		fscanf(fp,"%s",name[i]);
		while(0!=strcmp(name[i],stu.name[j]) && j<100)j++;			
		if(j==100)
		{
			printf("姓名有误！\n");
			fflush(stdout);
			usleep(500000);	
			return;
		}
		else
		{
		fscanf(fp,"%d%d%d",&stu.Chinese[j],&stu.Math[j],&stu.English[j]);
			if(stu.Chinese[i]>100 || stu.Chinese[i]<0 || stu.Math[i]>100 || stu.Math[i]<0 || stu.English[i]>100 || stu.English[i]<0)
			{
				printf("成绩输入有误，导入中止！\n");
				fflush(stdout);
				usleep(500000);	
				return;
			}
		}
		i++;	
	}
	printf("录入完成！\n");
	fflush(stdout);
	usleep(500000);	
	return;	
}
void lock_out(void)//解锁锁定的学生函数
{
	system("clear");
	int lock_id=0;
	printf("请输入要解锁的学生的学号：");
	scanf("%d",&lock_id);
	for(int i=0;i<100;i++)
	{
		if(stu.ID[i]==lock_id && stu.pd[i]==-1)
		{
			stu.pd[i]=1;//学生账号状态置为１,代表正常状态.
			printf("解锁成功！");
			fflush(stdout);
			usleep(500000);
			return;
		}
	}
	printf("输入有误！");
	fflush(stdout);
	usleep(500000);
}
