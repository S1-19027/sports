#include "sports.h"

// 声明外部变量 event_head 和 student_head
extern SportEvent *event_head;
extern Student *student_head;

int main()
{
    int option;
    int first_event = 1, first_student = 1; // 标记是否已添加过项目和学生
    system("mode con cols=130 lines=60");   // 设置控制台窗口大小
        
    // 添加登录验证
    login_system();
    
    init_system();                          // 初始化系统数据
    system("color 0E");
    SetConsoleOutputCP(65001);
    while (1)
    {
        SetConsoleOutputCP(65001);
        system("cls"); // 清屏
        option = Menu();

        // 判断是否需要先添加项目或学生
        if ((option >= 3 && option <= 5 || option == 11 || option == 13 || option == 14 || option == 15 || option == 16 || option == 17 || option == 18 || option == 19 || option == 20) && (event_head->next == NULL))
        {
            SetConsoleOutputCP(65001);
            system("cls");
            printf("系统中尚无项目信息，请先输入！\n");
            system("pause");
            continue;
        }
        if ((option >= 8 && option <= 10 || option == 11 || option == 13 || option == 14 || option == 15 || option == 17 || option == 18 || option == 19 || option == 20) && (student_head->next == NULL))
        {
            SetConsoleOutputCP(65001);
            system("cls");
            printf("系统中尚无学生信息，请先输入！\n");
            system("pause");
            continue;
        }
        system("cls"); // 清屏
        switch (option)
        {
        case 1:
            display_all_events();
            break;
        case 2:
            add_event();
            break;
        case 3:
            delete_event();
            break;
        case 4:
            modify_event();
            break;
        case 5:
            search_event();
            break;
        case 6:
            display_all_students();
            break;
        case 7:
            add_student();
            break;
        case 8:
            delete_student();
            break;
        case 9:
            modify_student();
            break;
        case 10:
            search_student();
            break;
        case 11:
            register_student();
            break;
        case 12:
            cancel_registration();
            break;
        case 13:
            display_all_registrations();
            break;
        case 14:
            search_registration();
            break;
        case 15:
            enter_score();
            break;
        case 16:
            count_event_participants();
            break;
        case 17:
            count_college_participants();
            break;
        case 18:
            count_student_registrations();
            break;
        case 19:
            query_results();
            break;
        case 20:
            save_statistics();
            printf("统计信息已保存到文件！\n");
            break;
        case 0:
            SetPosition(0, 10);
            printf("退出！\n");
            exit(0);
        default:
            SetPosition(0, 10);
            printf("无效选择，请重新输入！\n");
            break;
            system("pause");
        }
        getchar(); // 等待用户输入
    }

    return 0;
}
