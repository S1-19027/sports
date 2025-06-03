#include "sports.h"

// 全局链表头指针
SportEvent *event_head = NULL;
Student *student_head = NULL;
Registration *reg_head = NULL;

// 系统初始化
void init_system() {
    load_all_data();
}

// 主菜单
void main_menu() {
    int choice;
    do {
        system("clear || cls");
        printf("\n===== 运动会报名系统 =====\n");
        printf("1. 运动项目管理\n");
        printf("2. 学生信息管理\n");
        printf("3. 报名管理\n");
        printf("4. 统计查询\n");
        printf("5. 保存数据\n");
        printf("0. 退出系统\n");
        printf("请选择: ");
        scanf("%d", &choice);
        clear_input_buffer();

        switch(choice) {
            case 1: manage_events(); break;
            case 2: manage_students(); break;
            case 3: manage_registrations(); break;
            case 4: statistics_menu(); break;
            case 5: save_all_data(); break;
            case 0: 
                save_all_data();
                printf("系统数据已保存，即将退出...\n");
                exit(0);
            default: printf("无效选择!\n");
        }
    } while(choice != 0);
}
// 运动项目管理菜单
void manage_events() {
    int choice;
    do {
        system("clear || cls");
        printf("\n===== 运动项目管理 =====\n");
        printf("1. 显示所有运动项目\n");
        printf("2. 添加运动项目\n");
        printf("3. 删除运动项目\n");
        printf("4. 修改运动项目\n");
        printf("5. 查找运动项目\n");
        printf("0. 返回主菜单\n");
        printf("请选择: ");
        scanf("%d", &choice);
        clear_input_buffer();

        switch(choice) {
            case 1: display_all_events(); break;
            case 2: add_event(); break;
            case 3: delete_event(); break;
            case 4: modify_event(); break;
            case 5: search_event(); break;
            case 0: return;
            default: printf("无效选择!\n");
        }
        printf("\n按任意键继续...");
        getchar();
    } while(choice != 0);
}

// 添加运动项目
void add_event() {
    SportEvent *new_event = (SportEvent *)malloc(sizeof(SportEvent));
    if (!new_event) {
        printf("内存分配失败!\n");
        return;
    }

    printf("\n--- 添加运动项目 ---\n");
    
    // 输入项目信息
    printf("请输入项目编号: ");
    scanf("%d", &new_event->event_id);
    clear_input_buffer();
    
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
    clear_input_buffer();
    
    new_event->current_participants = 0;
    new_event->next = NULL;

    // 添加到链表
    if (event_head == NULL) {
        event_head = new_event;
    } else {
        SportEvent *current = event_head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_event;
    }
    
    printf("\n运动项目添加成功!\n");
}
// 学生管理菜单
void manage_students() {
    int choice;
    do {
        system("clear || cls");
        printf("\n===== 学生信息管理 =====\n");
        printf("1. 显示所有学生\n");
        printf("2. 添加学生信息\n");
        printf("3. 删除学生信息\n");
        printf("4. 修改学生信息\n");
        printf("5. 查找学生信息\n");
        printf("0. 返回主菜单\n");
        printf("请选择: ");
        scanf("%d", &choice);
        clear_input_buffer();

        switch(choice) {
            case 1: display_all_students(); break;
            case 2: add_student(); break;
            case 3: delete_student(); break;
            case 4: modify_student(); break;
            case 5: search_student(); break;
            case 0: return;
            default: printf("无效选择!\n");
        }
        printf("\n按任意键继续...");
        getchar();
    } while(choice != 0);
}

// 添加学生信息
void add_student() {
    Student *new_student = (Student *)malloc(sizeof(Student));
    if (!new_student) {
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
    if (student_head == NULL) {
        student_head = new_student;
    } else {
        Student *current = student_head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_student;
    }
    
    printf("\n学生信息添加成功!\n");
}
// 报名管理菜单
void manage_registrations() {
    int choice;
    do {
        system("clear || cls");
        printf("\n===== 报名管理 =====\n");
        printf("1. 显示所有报名\n");
        printf("2. 学生报名\n");
        printf("3. 取消报名\n");
        printf("4. 查找报名\n");
        printf("5. 录入成绩\n");
        printf("0. 返回主菜单\n");
        printf("请选择: ");
        scanf("%d", &choice);
        clear_input_buffer();

        switch(choice) {
            case 1: display_all_registrations(); break;
            case 2: register_student(); break;
            case 3: cancel_registration(); break;
            case 4: search_registration(); break;
            case 5: enter_score(); break;
            case 0: return;
            default: printf("无效选择!\n");
        }
        printf("\n按任意键继续...");
        getchar();
    } while(choice != 0);
}

// 学生报名
void register_student() {
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
    while (student != NULL) {
        if (strcmp(student->student_id, student_id) == 0) {
            break;
        }
        student = student->next;
    }
    
    if (student == NULL) {
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
    while (event != NULL) {
        if (event->event_id == event_id) {
            break;
        }
        event = event->next;
    }
    
    if (event == NULL) {
        printf("该项目编号不存在!\n");
        return;
    }
    
    // 检查项目是否已满
    if (event->current_participants >= event->max_participants) {
        printf("该项目报名人数已满!\n");
        return;
    }
    
    // 检查学生是否已报名该项目
    if (is_student_registered(student_id, event_id)) {
        printf("该学生已报名此项目!\n");
        return;
    }
    
    // 检查性别是否符合
    if (strcmp(event->gender_type, "男子项目") == 0 && strcmp(student->gender, "男") != 0) {
        printf("该项目只允许男生报名!\n");
        return;
    }
    
    if (strcmp(event->gender_type, "女子项目") == 0 && strcmp(student->gender, "女") != 0) {
        printf("该项目只允许女生报名!\n");
        return;
    }
    
    // 创建报名记录
    Registration *new_reg = (Registration *)malloc(sizeof(Registration));
    if (!new_reg) {
        printf("内存分配失败!\n");
        return;
    }
    
    new_reg->reg_id = generate_reg_id();
    strcpy(new_reg->student_id, student_id);
    new_reg->event_id = event_id;
    get_current_time(new_reg->reg_time);
    new_reg->score = -1;  // -1表示成绩未录入
    new_reg->next = NULL;
    
    // 添加到链表
    if (reg_head == NULL) {
        reg_head = new_reg;
    } else {
        Registration *current = reg_head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_reg;
    }
    
    // 更新项目报名人数
    event->current_participants++;
    
    printf("\n报名成功! 报名编号: %d\n", new_reg->reg_id);
}