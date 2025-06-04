#include "sports.h"

int main()
{
    int option;
    system("mode con cols=130 lines=60"); // 设置控制台窗口大小
    init_system();                        // 初始化系统数据
    system("color 0E");
    while (1)
    {
        system("cls"); // 清屏
        option = Menu();
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
            stat_event_participants();
            break;
        case 17:
            stat_college_participants();
            break;
        case 18:
            stat_student_event_count();
            break;
        case 19:
            query_scores();
            break;
        case 20:
            save_all_data();
            printf("统计信息已保存到文件！\n");
            break;
        case 0:
            save_all_data();
            SetPosition(0, 10);
            printf("退出！\n");
            return 0;
        default:
            SetPosition(0, 10);
            printf("无效选择，请重新输入！\n");
            break;
        }
        printf("\n按任意键返回主菜单...");
        getchar();
        getchar();
    }
    return 0;
}