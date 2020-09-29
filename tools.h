#ifndef TOOLS_H
#define TOOLS_H
#include"getch.h"
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include<string.h>
typedef struct mas//校长结构体
{
	char master_pw[10];//校长密码
	int flag;//是否第一次登陆
}mas;
mas m;//定义结构变量
typedef struct teacher//在职教师结构体
{
	char name[100][20];//姓名
	char sex[100];//性别
	char key[100][10];//密码
	char id[100][20];//工号
	int num[100];//是否第一次登录
	}teacher;
teacher tch;//定义结构变量
typedef struct l_teacher//离职教师结构体
{
	char name[100][20];//姓名
	char sex[100];//性别
	char key[100][10];//密码
	char id[100][20];//工号
	int num[100];////账号状态（０代表第一次登录，１代表正常状态，-1代表锁定状态）
	}l_teacher;
l_teacher l_tch;//定义结构变量
typedef struct Student//在校学生结构体
{
	char name[100][20];//姓名
	char sex[100];//性别
	char pw[100][10];//密码
	int  ID[100];//学号	
	int pd[100];//账号状态（０代表第一次登录，１代表正常状态，-1代表锁定状态）
	int Chinese[100];//语文成绩
	int Math[100];//数学成绩
	int English[100];//英语成绩
}Student;
Student stu;//定义结构变量
typedef struct l_Student//退学学生结构体
{
	char name[100][20];//姓名
	char sex[100];//性别
	char pw[100][10];//密码
	int  ID[100];//学号
	int pd[100];//账号状态（０代表第一次登录，１代表正常状态，-1代表锁定状态）
	int Chinese[100];//语文成绩
	int Math[100];//数学成绩
	int English[100];//英语成绩
}l_Student;
l_Student l_stu;//定义结构变量
void mpw_c(void);//校长密码重置
void tpw_c(void);//教师密码重置
void add_t(void);//增加教师
void del_t(void);//删除教师
void view_tch(void);//显示在职教师
void view_gtch(void);//显示离职教师
void master_show(void);//校长系统界面显示
void teacher_file(void);//教师文件信息更新
void lock_out_t(void);//解锁锁定学生.

void stu_add(void);//增加学生
void stu_del(void);//删除学生
void stu_modify(void);//修改学生信息
void stu_find(void);//查找学生
void stu_score(void);//录入学生成绩
void stu_add2(void);//批量导入学生
void stu_score2(void);//批量导入学生成绩
void student_file(void);//学生文件信息更新
int stu_reset(void);//学生密码重置
void tch_show_in(void);//显示在校学生
void tch_show_out(void);//显示退学学生
void lock_out(void);
void find(int num);//查成绩
void cpd(int num);//修改密码
void look(int num);//查看学生个人信息
#endif//TOOLS_H
