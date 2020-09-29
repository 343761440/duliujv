#ifndef TEACHER_TOOLS_H
#define TEACHER_TOOLS_H

#include <stdio.h>
#include "student.h"
#include"teacher.h"

#define SHOW_MESSAGE(a,b,c,d,e,f,g) printf("姓名:%s 学号:%d 语文:%d 数学%d 英语:%d 密码:%s 性别:%s\n",a,b,c,d,e,f,g)

static int stu_count=0;					// 记录学生数

static int ID_max=10000;				// 学号初始位

static int out_stu=0;					// 退学人数

void show_str(const char* str,int time);		// 使字符串显示一段时间

void anykey_continue(void);				// 学生密码重置

int stu_reset(void);					// 错误提示

void tch_show_in(void);					// 在校学生显示

void tch_show_out(void);				// 退学学生显示


#endif//TEACHER_TOOLS_H
