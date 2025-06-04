#include "sports.h"

// 全局链表头指针
SportEvent *event_head = NULL;
Student *student_head = NULL;
Registration *reg_head = NULL;

// 系统初始化
void init_system()
{
    load_all_data();
}
/*
  函数功能： 设置文字输出的起始位置
  形式参数： 文字输出起始位置的坐标x,y，int 类型
  函数返回值：void
*/
void SetPosition(int x, int y)
{
    HANDLE hOut;
    COORD pos;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(hOut, pos);
}
/*
  函数功能： 显示系统主菜单， 获取键盘用户输入的操作选项，并返回给主函数
  形式参数： 无
  函数返回值：用户键盘输入的选项，int型
*/
int Menu(void)
{
    int posy = 5;
    int option; // 保存用户输入的操作代号的变量
    int i, j;
    event_head->next = NULL;
    student_head->next = NULL;
    reg_head->next = NULL;
    SetPosition(POS_X3, posy);
    SetConsoleOutputCP(936);
    printf("运动会报名系统\n"); // 输出系统名
    // 输出系统名和功能说明之间的两行短横线
    for (i = 0; i < 2; i++)
    {
        SetPosition(POS_X1, ++posy);
        for (j = 0; j < 55; j++)
        {
            printf("-");
        }
    }
    // 输出系统支持的功能和对应的功能代号
    SetConsoleOutputCP(936);
    SetPosition(POS_X1, ++posy);
    SetConsoleOutputCP(936);
    printf("1.显示所有项目信息");
    SetPosition(POS_X4, posy);
    SetConsoleOutputCP(936);
    printf("2.添加运动项目信息");
    SetPosition(POS_X1, posy += 2);
    SetConsoleOutputCP(936);
    printf("3.删除运动项目信息");
    SetPosition(POS_X4, posy);
    SetConsoleOutputCP(936);
    printf("4.修改运动项目信息");
    SetPosition(POS_X1, posy += 2);
    SetConsoleOutputCP(936);
    printf("5.查找运动项目信息");
    SetPosition(POS_X4, posy);
    SetConsoleOutputCP(936);
    printf("6.显示所有学生信息");
    SetPosition(POS_X1, posy += 2);
    SetConsoleOutputCP(936);
    printf("7.添加学生信息");
    SetPosition(POS_X4, posy);
    SetConsoleOutputCP(936);
    printf("8.删除学生信息");
    SetPosition(POS_X1, posy += 2);
    SetConsoleOutputCP(936);
    printf("9.修改学生信息");
    SetPosition(POS_X4, posy);
    SetConsoleOutputCP(936);
    printf("10.查找学生信息");
    SetPosition(POS_X1, posy += 2);
    SetConsoleOutputCP(936);
    printf("11.学生报名");
    SetPosition(POS_X4, posy);
    SetConsoleOutputCP(936);
    printf("12.取消报名");
    SetPosition(POS_X1, posy += 2);
    SetConsoleOutputCP(936);
    printf("13.显示所有报名信息");
    SetPosition(POS_X4, posy);
    SetConsoleOutputCP(936);
    printf("14.查找报名信息");
    SetPosition(POS_X1, posy += 2);
    SetConsoleOutputCP(936);
    printf("15.录入成绩");
    SetPosition(POS_X4, posy);
    SetConsoleOutputCP(936);
    printf("16.统计每个项目的报名人数");
    SetPosition(POS_X1, posy += 2);
    SetConsoleOutputCP(936);
    printf("17.统计每个学院的报名人数");
    SetPosition(POS_X4, posy);
    SetConsoleOutputCP(936);
    printf("18.统计每个学生的报名项目数");
    SetPosition(POS_X1, posy += 2);
    SetConsoleOutputCP(936);
    printf("19.查询比赛成绩");
    SetPosition(POS_X4, posy);
    SetConsoleOutputCP(936);
    printf("20.保存统计信息到文件");
    SetPosition(POS_X1, posy += 2);
    SetConsoleOutputCP(936);
    printf("0.退出");
    // 输出系统支持的功能与输入提示语之间的两行短横线
    for (i = 0; i < 2; i++)
    {
        SetPosition(POS_X1, ++posy);
        for (j = 0; j < 55; j++)
        {
            printf("-");
        }
    }
    // 提示用户输入所要执行的功能代号
    SetPosition(POS_X1, ++posy);
    printf("请选择你想要进行的操作[0~16]: [  ]\b\b\b");
    scanf("%d", &option);
    return option;
}
void display_all_events() // 显示所有运动项目信息
{
    SportEvent *temp = event_head->next;
    while (temp != NULL)
    {
        printf("%d %s %s %s %s %s %s %d %d\n", temp->event_id, temp->name, temp->type, temp->gender_type, temp->time, temp->location, temp->status, temp->max_participants, temp->current_participants);
        temp = temp->next;
    }
}
// 添加运动项目
void add_event()
{
    SportEvent *new_event = (SportEvent *)malloc(sizeof(SportEvent));
    if (!new_event)
    {
        printf("内存分配失败!\n");
        return;
    }

    printf("\n--- 添加运动项目 ---\n");

    // 输入项目信息
    printf("请输入项目编号: ");
    scanf("%d", &new_event->event_id);
    getchar();

    printf("请输入项目名称: ");
    fgets(new_event->name, MAX_NAME_LEN, stdin);
    new_event->name[strcspn(new_event->name, "\n")] = '\0';

    printf("请输入项目类型(田赛/径赛): ");
    fgets(new_event->type, MAX_TYPE_LEN, stdin);
    new_event->type[strcspn(new_event->type, "\n")] = '\0';

    printf("请输入参赛类型(男子项目/女子项目): ");
    fgets(new_event->gender_type, MAX_TYPE_LEN, stdin);
    new_event->gender_type[strcspn(new_event->gender_type, "\n")] = '\0';

    printf("请输入比赛时间(YYYY-MM-DD HH:MM): ");
    fgets(new_event->time, 20, stdin);
    new_event->time[strcspn(new_event->time, "\n")] = '\0';

    printf("请输入比赛地点: ");
    fgets(new_event->location, MAX_LOCATION_LEN, stdin);
    new_event->location[strcspn(new_event->location, "\n")] = '\0';

    printf("请输入项目状态(报名中/已结束): ");
    fgets(new_event->status, MAX_TYPE_LEN, stdin);
    new_event->status[strcspn(new_event->status, "\n")] = '\0';

    printf("请输入报名人数上限: ");
    scanf("%d", &new_event->max_participants);
    getchar();

    new_event->current_participants = 0;
    new_event->next = NULL;

    // 添加到链表
    if (event_head->next == NULL)
    {
        event_head->next = new_event;
    }
    else
    {
        SportEvent *current = event_head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_event;
    }

    printf("\n运动项目添加成功!\n");
}
// 删除运动项目
void delete_event()
{
    printf("请输入你要删除的项目id:");
    int event_id;
    scanf("%d", &event_id);
    SportEvent *temp = event_head->next;
    SportEvent *prev = NULL;

    while (temp != NULL && temp->event_id != event_id)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        SetConsoleOutputCP(936);
        printf("没有找到该生记录!\n");
        return;
    }
    if (prev == NULL)
    {
        event_head = temp->next;
        return;
    }

    else
    {
        char ch;
        SetConsoleOutputCP(936);
        printf("%10.2f%10.2f\n");
        SetConsoleOutputCP(936);
        printf("请确认是否要删除这条记录？(Y/y, N/n):");
        getchar();
        scanf("%c", &ch);
        // 选择
        if (ch == 'Y' || ch == 'y')
        {
            prev->next = temp->next;
            free(temp);
            SetConsoleOutputCP(936);
            printf("删除完毕\n");
            return;
        }
        else if (ch == 'N' || ch == 'n')
        {
            SetConsoleOutputCP(936);
            printf("找到了这个学生的记录，但不删除\n");
            return;
        }
        else
        {
            SetConsoleOutputCP(936);
            printf("输入出错\n");
            return;
        }
    }
}
// 修改运动项目信息

void modify_event()
{
    printf("请输入你要修改的项目id:");
    int event_id;
    scanf("%d", &event_id);
    SportEvent *temp = event_head->next;
    SportEvent *prev = NULL;

    while (temp != NULL && temp->event_id != event_id)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        SetConsoleOutputCP(936);
        printf("没有找到该项目记录!\n");
        return;
    }
    if (prev == NULL)
    {
        event_head = temp->next;
        return;
    }

    else
    {
        char ch;
        SetConsoleOutputCP(936);
        printf("%10.2f%10.2f\n");
        SetConsoleOutputCP(936);
        printf("请确认是否要修改这条记录?(Y/y, N/n):");
        getchar();
        scanf("%c", &ch);
        // 选择
        if (ch == 'Y' || ch == 'y')
        {
            printf("请输入需要修改的信息,1为项目名称,2为项目类型,3为参赛类型,4为比赛时间,5为比赛地点,6为项目状态,7为报名人数上限\n");
            int choice;
            scanf("%d", &choice);
            getchar(); // 清除换行符
            switch (choice)
            {
            case 1:
                printf("请输入新的项目名称: ");
                fgets(temp->name, MAX_NAME_LEN, stdin);
                temp->name[strcspn(temp->name, "\n")] = '\0';
                break;

            case 2:
                printf("请输入新的项目类型(田赛/径赛):");
                fgets(temp->type, MAX_TYPE_LEN, stdin);
                temp->type[strcspn(temp->type, "\n")] = '\0';
                break;
            case 3:
                printf("请输入新的参赛类型(男子项目/女子项目):");
                fgets(temp->gender_type, MAX_TYPE_LEN, stdin);
                temp->gender_type[strcspn(temp->gender_type, "\n")] = '\0';
                break;
            case 4:
                printf("请输入新的比赛时间(YYYY-MM-DD HH:MM):");
                fgets(temp->time, 20, stdin);
                temp->time[strcspn(temp->time, "\n")] = '\0';
                break;
            case 5:
                printf("请输入新的比赛地点:");
                fgets(temp->location, MAX_LOCATION_LEN, stdin);
                temp->location[strcspn(temp->location, "\n")] = '\0';
                break;
            case 6:
                printf("请输入新的项目状态(报名中/已结束):");
                fgets(temp->status, MAX_TYPE_LEN, stdin);
                temp->status[strcspn(temp->status, "\n")] = '\0';
                break;
            case 7:
                printf("请输入新的报名人数上限:");
                scanf("%d", &temp->max_participants);
                getchar(); // 清除换行符
                break;
            default:
                SetConsoleOutputCP(936);
                printf("无效选择!\n");
            }
            SetConsoleOutputCP(936);
            printf("修改完毕\n");
            return;
        }
        else if (ch == 'N' || ch == 'n')
        {
            SetConsoleOutputCP(936);
            printf("找到了这个学生的记录，但不修改\n");
            return;
        }
        else
        {
            SetConsoleOutputCP(936);
            printf("输入出错\n");
            return;
        }
    }
}

// 查找运动项目信息
void search_event()
{
    printf("请输入你要查找的项目id:");
    int event_id;
    scanf("%d", &event_id);
    SportEvent *temp = event_head->next;

    while (temp != NULL && temp->event_id != event_id)
    {
        
        temp = temp->next;
    }
    if (temp == NULL)
    {
        SetConsoleOutputCP(936);
        printf("没有找到该项目记录!\n");
        return;
    }

    else
    {
        {
            printf("%d %s %s %s %s %s %s %d %d\n", temp->event_id, temp->name, temp->type, temp->gender_type, temp->time, temp->location, temp->status, temp->max_participants, temp->current_participants);
        }
    }
}
// 学生管理菜单
// void manage_students()
// {
//     int choice;
//     do
//     {
//         system("clear || cls");
//         printf("\n===== 学生信息管理 =====\n");
//         printf("1. 显示所有学生\n");
//         printf("2. 添加学生信息\n");
//         printf("3. 删除学生信息\n");
//         printf("4. 修改学生信息\n");
//         printf("5. 查找学生信息\n");
//         printf("0. 返回主菜单\n");
//         printf("请选择: ");
//         scanf("%d", &choice);
//         clear_input_buffer();

//         switch (choice)
//         {
//         case 1:
//             display_all_students();
//             break;
//         case 2:
//             add_student();
//             break;
//         case 3:
//             delete_student();
//             break;
//         case 4:
//             modify_student();
//             break;
//         case 5:
//             search_student();
//             break;
//         case 0:
//             return;
//         default:
//             printf("无效选择!\n");
//         }
//         printf("\n按任意键继续...");
//         getchar();
//     } while (choice != 0);
// }

// 显示所有学生信息
void display_all_students()
{
    Student *temp = student_head->next;
    if (temp == NULL)
    {
        printf("没有学生信息!\n");
        return;
    }
    printf("\n--- 所有学生信息 ---\n");
    printf("学号\t姓名\t性别\t班级\t学院\t联系方式\n");
    while (temp != NULL)
    {
        printf("%s\t%s\t%s\t%s\t%s\t%s\n", temp->student_id, temp->name, temp->gender, temp->class, temp->college, temp->contact);
        temp = temp->next;
    }
}

// 添加学生信息
void add_student()
{
    Student *new_student = (Student *)malloc(sizeof(Student));
    if (!new_student)
    {
        printf("内存分配失败!\n");
        return;
    }

    printf("\n--- 添加学生信息 ---\n");

    printf("请输入学号: ");
    fgets(new_student->student_id, 20, stdin);
    new_student->student_id[strcspn(new_student->student_id, "\n")] = '\0';

    printf("请输入姓名: ");
    fgets(new_student->name, MAX_NAME_LEN, stdin);
    new_student->name[strcspn(new_student->name, "\n")] = '\0';

    printf("请输入性别: ");
    fgets(new_student->gender, 10, stdin);
    new_student->gender[strcspn(new_student->gender, "\n")] = '\0';

    printf("请输入班级: ");
    fgets(new_student->class, MAX_CLASS_LEN, stdin);
    new_student->class[strcspn(new_student->class, "\n")] = '\0';

    printf("请输入学院: ");
    fgets(new_student->college, MAX_COLLEGE_LEN, stdin);
    new_student->college[strcspn(new_student->college, "\n")] = '\0';

    printf("请输入联系方式: ");
    fgets(new_student->contact, MAX_CONTACT_LEN, stdin);
    new_student->contact[strcspn(new_student->contact, "\n")] = '\0';

    new_student->next = NULL;

    // 添加到链表
    if (student_head->next == NULL)
    {
        student_head->next = new_student;
    }
    else
    {
        Student *current = student_head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_student;
    }

    printf("\n学生信息添加成功!\n");
}
// 报名管理菜单
// void manage_registrations()
// {
//     int choice;
//     do
//     {
//         system("clear || cls");
//         printf("\n===== 报名管理 =====\n");
//         printf("1. 显示所有报名\n");
//         printf("2. 学生报名\n");
//         printf("3. 取消报名\n");
//         printf("4. 查找报名\n");
//         printf("5. 录入成绩\n");
//         printf("0. 返回主菜单\n");
//         printf("请选择: ");
//         scanf("%d", &choice);
//         clear_input_buffer();
//
//         switch (choice)
//         {
//         case 1:
//             display_all_registrations();
//             break;
//         case 2:
//             register_student();
//             break;
//         case 3:
//             cancel_registration();
//             break;
//         case 4:
//             search_registration();
//             break;
//         case 5:
//             enter_score();
//             break;
//         case 0:
//             return;
//         default:
//             printf("无效选择!\n");
//         }
//         printf("\n按任意键继续...");
//         getchar();
//     } while (choice != 0);
// }

// 删除学生信息
void delete_student()
{
    printf("请输入你要删除的学生学号:");
    char student_id[20];
    fgets(student_id, 20, stdin);
    student_id[strcspn(student_id, "\n")] = '\0';

    Student *temp = student_head->next;
    Student *prev = NULL;

    while (temp != NULL && strcmp(temp->student_id, student_id) != 0)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        SetConsoleOutputCP(936);
        printf("没有找到该学生记录!\n");
        return;
    }
    if (prev == NULL)
    {
        student_head->next = temp->next;
        free(temp);
        return;
    }

    else
    {
        char ch;
        SetConsoleOutputCP(936);
        printf("%10.2f%10.2f\n");
        SetConsoleOutputCP(936);
        printf("请确认是否要删除这条记录？(Y/y, N/n):");
        getchar();
        scanf("%c", &ch);
        if (ch == 'Y' || ch == 'y')
        {
            prev->next = temp->next;
            free(temp);
            SetConsoleOutputCP(936);
            printf("删除完毕\n");
            return;
        }
        else if (ch == 'N' || ch == 'n')
        {
            SetConsoleOutputCP(936);
            printf("找到了这个学生的记录，但不删除\n");
            return;
        }
        else
        {
            SetConsoleOutputCP(936);
            printf("输入出错\n");
            return;
        }
    }
}

// 修改学生信息
void modify_student()
{
    printf("请输入你要修改的学生学号:");
    char student_id[20];
    fgets(student_id, 20, stdin);
    student_id[strcspn(student_id, "\n")] = '\0';

    Student *temp = student_head->next;
    Student *prev = NULL;

    while (temp != NULL && strcmp(temp->student_id, student_id) != 0)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        SetConsoleOutputCP(936);
        printf("没有找到该学生记录!\n");
        return;
    }
    if (prev == NULL)
    {
        student_head->next = temp->next;
        free(temp);
        return;
    }

    else
    {
        char ch;
        SetConsoleOutputCP(936);
        printf("%10.2f%10.2f\n");
        SetConsoleOutputCP(936);
        printf("请确认是否要修改这条记录?(Y/y, N/n):");
        getchar();
        scanf("%c", &ch);
        if (ch == 'Y' || ch == 'y')
        {
            printf("请输入需要修改的信息,1为姓名,2为性别,3为班级,4为学院,5为联系方式\n");
            int choice;
            scanf("%d", &choice);
            getchar(); // 清除换行符
            switch (choice)
            {
            case 1:
                printf("请输入新的姓名: ");
                fgets(temp->name, MAX_NAME_LEN, stdin);
                temp->name[strcspn(temp->name, "\n")] = '\0';
                break;

            case 2:
                printf("请输入新的性别: ");
                fgets(temp->gender, 10, stdin);
                temp->gender[strcspn(temp->gender, "\n")] = '\0';
                break;
            case 3:
                printf("请输入新的班级: ");
                fgets(temp->class, MAX_CLASS_LEN, stdin);
                temp->class[strcspn(temp->class, "\n")] = '\0';
                break;
            case 4:
                printf("请输入新的学院: ");
                fgets(temp->college, MAX_COLLEGE_LEN, stdin);
                temp->college[strcspn(temp->college, "\n")] = '\0';
                break;
            case 5:
                printf("请输入新的联系方式: ");
                fgets(temp->contact, MAX_CONTACT_LEN, stdin);
                temp->contact[strcspn(temp->contact, "\n")] = '\0';
                break;
            default:
                SetConsoleOutputCP(936);
                printf("无效选择!\n");
                return;
            }
            SetConsoleOutputCP(936);
            printf("修改完毕\n");
            return;
        }
        else if (ch == 'N' || ch == 'n')
        {
            SetConsoleOutputCP(936);
            printf("找到了这个学生的记录，但不修改\n");
            return;
        }
        else
        {
            SetConsoleOutputCP(936);
            printf("输入出错\n");
            return;
        }
    }
}

// 查找学生信息
void search_student()
{
    printf("请输入你要查找的学生学号:");
    char student_id[20];
    fgets(student_id, 20, stdin);
    student_id[strcspn(student_id, "\n")] = '\0';

    Student *temp = student_head->next;

    while (temp != NULL && strcmp(temp->student_id, student_id) != 0)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        SetConsoleOutputCP(936);
        printf("没有找到该学生记录!\n");
        return;
    }

    printf("\n--- 学生信息 ---\n");
    printf("学号: %s\n", temp->student_id);
    printf("姓名: %s\n", temp->name);
    printf("性别: %s\n", temp->gender);
    printf("班级: %s\n", temp->class);
    printf("学院: %s\n", temp->college);
    printf("联系方式: %s\n", temp->contact);
    printf("\n");
}



// 学生报名
void register_student()
{
    char student_id[20];
    int event_id;

    printf("\n--- 学生报名 ---\n");

    // 显示所有学生
    printf("\n所有学生列表:\n");
    display_all_students();

    printf("\n请输入学号: ");
    fgets(student_id, 20, stdin);
    student_id[strcspn(student_id, "\n")] = '\0';

    // 检查学生是否存在
    Student *student = student_head;
    while (student != NULL)
    {
        if (strcmp(student->student_id, student_id) == 0) // 学生存在
        {
            break;
        }
        student = student->next;
    }

    if (student == NULL)
    {
        printf("该学号不存在!\n");
        return;
    }

    // 显示所有运动项目
    printf("\n所有运动项目列表:\n");
    display_all_events();

    printf("\n请输入项目编号: ");
    scanf("%d", &event_id);
    clear_input_buffer();

    // 检查项目是否存在
    SportEvent *event = event_head;
    while (event != NULL)
    {
        if (event->event_id == event_id)
        {
            break;
        }
        event = event->next;
    }

    if (event == NULL)
    {
        printf("该项目编号不存在!\n");
        return;
    }

    // 检查项目是否已满
    if (event->current_participants >= event->max_participants)
    {
        printf("该项目报名人数已满!\n");
        return;
    }

    // 检查学生是否已报名该项目
    if (is_student_registered(student_id, event_id))
    {
        printf("该学生已报名此项目!\n");
        return;
    }

    // 检查性别是否符合
    if (strcmp(event->gender_type, "男子项目") == 0 && strcmp(student->gender, "男") != 0)
    {
        printf("该项目只允许男生报名!\n");
        return;
    }

    if (strcmp(event->gender_type, "女子项目") == 0 && strcmp(student->gender, "女") != 0)
    {
        printf("该项目只允许女生报名!\n");
        return;
    }

    // 创建报名记录
    Registration *new_reg = (Registration *)malloc(sizeof(Registration));
    if (!new_reg)
    {
        printf("内存分配失败!\n");
        return;
    }

    new_reg->reg_id = generate_reg_id();
    strcpy(new_reg->student_id, student_id);
    new_reg->event_id = event_id;
    get_current_time(new_reg->reg_time);
    new_reg->score = -1; // -1表示成绩未录入
    new_reg->next = NULL;

    // 添加到链表
    if (reg_head == NULL)
    {
        reg_head = new_reg;
    }
    else
    {
        Registration *current = reg_head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_reg;
    }

    // 更新项目报名人数
    event->current_participants++;

    printf("\n报名成功! 报名编号: %d\n", new_reg->reg_id);
}