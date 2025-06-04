#ifndef SPORTS_SYSTEM_H
#define SPORTS_SYSTEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#include <windows.h>
#include <conio.h>

#define STU_NUM 50           // 教学班学生人数上限
#define COURSE_NUM 10        // 一学期的课程上限
#define NAME_LEN 10          // 学生姓名（字符串）最大长度
#define POS_X1 35            // 1、菜单页，第一列所有功能输出起始位置的x坐标值；2、排序之后输出提示起点的X坐标值
#define POS_X2 40            // 输入模块的提示语句起点的X坐标值
#define POS_X3 50            // 第一次，调用输入模块或磁盘数据读入模块功能以外的其他功能，提示“系统中尚无学生成绩信息，请先输入”的起始位置的X坐标值
#define POS_X4 65            // 菜单页，第二列所有功能输出起始位置的x坐标值；
#define POS_Y 3              // 排序之后输出提示起点的Y坐标值
#define MAX_NAME_LEN 50      // 项目名称上限
#define MAX_TYPE_LEN 20      // 项目类型上限
#define MAX_LOCATION_LEN 100 // 比赛地点上限
#define MAX_CONTACT_LEN 20   // 联系方式上限
#define MAX_COLLEGE_LEN 50   // 学院名称上限
#define MAX_CLASS_LEN 30     // 班级数上限
// 运动项目结构体
typedef struct SportEvent
{
    int event_id;                    // 项目编号
    char name[MAX_NAME_LEN];         // 项目名称
    char type[MAX_TYPE_LEN];         // 项目类型(田赛/径赛)
    char gender_type[MAX_TYPE_LEN];  // 参赛类型(男子/女子)
    char time[20];                   // 比赛时间
    char location[MAX_LOCATION_LEN]; // 比赛地点
    char status[MAX_TYPE_LEN];       // 项目状态
    int max_participants;            // 报名人数上限
    int current_participants;        // 当前报名人数
    struct SportEvent *next;         // 下一个项目指针
} SportEvent;

// 学生信息结构体
typedef struct Student
{
    char student_id[20];           // 学号
    char name[MAX_NAME_LEN];       // 姓名
    char gender[10];               // 性别
    char class[MAX_CLASS_LEN];     // 班级
    char college[MAX_COLLEGE_LEN]; // 学院
    char contact[MAX_CONTACT_LEN]; // 联系方式
    struct Student *next;          // 下一个学生指针
} Student;

// 报名信息结构体
typedef struct Registration
{
    int reg_id;                // 报名编号
    char student_id[20];       // 学号
    int event_id;              // 项目编号
    char reg_time[20];         // 报名时间
    float score;               // 比赛成绩(-1表示未录入)
    struct Registration *next; // 下一个报名指针
} Registration;

// 函数声明
void init_system();
int Menu(void);                 // 操作菜单
void SetPosition(int x, int y); // 设置输出内容在控制台窗口中的起始位置
// 运动项目管理函数
// void manage_events();
void display_all_events(); // 显示所有运动项目信息
void add_event();          // 添加运动项目信息
void delete_event();       // 删除运动项目信息
void modify_event();       // 修改运动项目信息
void search_event();       // 查找运动项目信息

// 学生管理函数
// void manage_students();
void display_all_students(); // 显示所有学生信息
void add_student();          // 添加学生信息
void delete_student();       // 删除学生信息
void modify_student();       // 修改学生信息
void search_student();       // 查找学生信息

// 报名管理函数
// void manage_registrations();
void display_all_registrations(); // 显示所有报名信息
void register_student();          // 学生报名
void cancel_registration();       // 取消报名
void search_registration();       // 查找报名信息
void enter_score();               // 录入成绩

// 统计查询函数
// void statistics_menu();
void count_event_participants();    // 统计每个项目的报名人数
void count_college_participants();  // 统计每个学院的报名人数
void count_student_registrations(); // 统计每个学生的报名项目数
void query_results();               // 查询比赛成绩
void save_statistics();             // 保存统计信息到文件

// 文件操作函数
void save_all_data();
void load_all_data();
void save_events_to_file();
void load_events_from_file();
void save_students_to_file();
void load_students_from_file();
void save_registrations_to_file();
void load_registrations_from_file();

// 辅助函数
int generate_reg_id();
int is_event_full(int event_id);
int is_student_registered(char *student_id, int event_id);
void get_current_time(char *time_str);
void clear_input_buffer();

#endif