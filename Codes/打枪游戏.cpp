#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
void sleep_ms(const int milliseconds) { this_thread::sleep_for(std::chrono::milliseconds(milliseconds)); }

void play(const int level, const int Hs1, const int Hs2, bool &answer) {
    cout << "现在游戏难度level " << level << " 游戏开始\n";
    int my, M_fire = 1, C_fire = 1;
    while (!answer) {
        sleep_ms(250);
        srand(static_cast<int>(time(nullptr)));
        int computer = rand() % 100;
        if (computer < Hs1) computer = 1;
        else if (computer >= Hs1 && computer < Hs2) computer = 2;
        else computer = 3;
        cout << "人工智能方已做出选择，请输入：" << endl;
        cout << "你的子弹数：" << M_fire << "   人工智能子弹数：" << C_fire << endl;
        cout << "1.射击   2.格挡   3.装弹   4.退出" << endl;
        cout << "你的选择：";
        cin >> my;
        if (my == computer || my + 1 == computer && my < computer || my - 1 == computer && my > computer) {
            if (my == 1 && M_fire != 0)M_fire--;
            if (computer == 1 && C_fire != 0)C_fire--;
            if (my == 3)M_fire++;
            if (computer == 3)C_fire++;
            system("cls");
            cout << "平局！";
            sleep_ms(500);
            system("cls");
            continue;
        }
        if (my == 1 && computer == 3 && M_fire >= 1) {
            system("cls");
            cout << "你赢了";
            sleep_ms(3000);
            answer = true;
            system("cls");
            return;
        }
        if (my != 4) {
            system("cls");
            cout << "你输了";
            answer = false;
            return;
        }
        system("cls");
        cout << "拜拜！";
        answer = false;
        return;
    }
}

int main() {
    int a;
    bool answer = false;
    while (true) {
        cout << "欢迎来到 打枪 游戏：\n\n";
        cout << "   按1开始游戏" << endl;
        cout << "   按2游戏介绍" << endl;
        cout << "     按3退出" << endl;
        cin >> a;
        system("cls");
        switch (a) {
            case 1:
                for (int i = 1; i <= 9; i++) {
                    if (i <= 3) play(1, 20, 50, answer);
                    else if (i <= 6) play(2, 30, 35, answer);
                    else play(3, 40, 20, answer);
                    if (!answer)return 0;
                    answer = false;
                }
                system("cls");
                cout << "你打败了对手，游戏结束！";
                return 0;
            case 2:
                cout << "本游戏是一款用文字来模拟类似俄罗斯转盘的推测类游戏:\n\n";
                cout << "A.游戏玩法" << endl;
                cout << "   a.难度调节" << endl;
                cout << "      难度（level）,分为3等（level 1、level 2、level 3以百分数记），每过3关难度标准升级。\n";
                cout << "	     1.level 1的游戏设置" << endl;
                cout << "	        在level 1难度中，人工智能方的射击概率为20%，格挡概率为50%，装弹概率为30%。\n";
                cout << "	     2.level 2的游戏设置" << endl;
                cout << "	        在level 2难度中，人工智能方的射击概率为30%，格挡概率为35%，装弹概率为35%。\n";
                cout << "	     3.level 3的游戏设置" << endl;
                cout << "	        在level 3难度中，人工智能方的射击概率为40%，格挡概率为20%，装弹概率为40%。\n\n";
                cout << "	  b.玩家方的选择" << endl;
                cout << "	     1.射击（选项1）。" << endl;
                cout << "	     2.格挡（选项2）。" << endl;
                cout << "	     3.装弹（选项3）。\n\n";
                cout << "   c.关于游戏启动日志\n";
                cout << "      1.该游戏不会生成启动日志\n\n\n\n\n";
                cout << "按0退出：";
                while (cin >> a && a != 0) cout << "你输入的指令不合法，error s01:The cin things is not create-错误" << endl;
                system("cls");
                break;
            case 3:
                system("cls");
                cout << "拜拜！";
                return 0;
            default: ;
        }
    }
}
