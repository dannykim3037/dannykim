/*#define DEBUG*/
#include <iostream>
#include <conio.h>
#include <Windows.h>

// game_state == 0
int print_title_screen()
{
    std::cout << "***************************************" << std::endl;
    std::cout << "*                                     *" << std::endl;
    std::cout << "*             지렁이 게임             *" << std::endl;
    std::cout << "*            (Snake Bite)             *" << std::endl;
#ifdef DEBUG
    std::cout << "*          - 디버그 모드 -            *" << std::endl;
#else
    std::cout << "*                                     *" << std::endl;
#endif
    std::cout << "* 1. 게임 시작                        *" << std::endl;
    std::cout << "* 2. 게임 설명                        *" << std::endl;
    std::cout << "* 3. 게임 랭킹 보기                   *" << std::endl;
    std::cout << "* 4. 게임 종료(Esc)                   *" << std::endl;
    std::cout << "*                                     *" << std::endl;
    std::cout << "***************************************" << std::endl;
        

    return 0;
}

void gotoxy(int x, int y)
{
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int print_gmae_screen(int stage_width, int stage_height)
{ 
    for (int i = 1; i <= 36; i++) {
        for (int j = 1; j <= 9; j++) {
            gotoxy(i, j);
            printf(" ");
        }
    }

    return 0;
}
// game_state == 2
int print_introduction_screen()
{
    std::cout << "***************************************" << std::endl;
    std::cout << "*              게임 설명              *" << std::endl;
    std::cout << "*                                     *" << std::endl;
    std::cout << "*    타이틀 화면으로 돌아가기(Y/N)    *" << std::endl;
    std::cout << "***************************************" << std::endl;
    return 0;
}
int main()
{
    int game_state =0;
    int game_running = '1';
    
    while (game_running)
    {
        char key = '0';
        switch (game_state)
        {
        case 0: print_title_screen();
            key = _getch();
            switch (key)
            {
            case '1': 
                break;
            case '2': 
                game_state = 2;  
                break;
            case '3':
                break;
            case '4': 
                game_running = '0'; 
                break;
            case 27 : 
                game_running = '0';
                break;
            default:
                break;
            }
        case 1: print_gmae_screen(10,10);
            key = _getch();
        case 2: print_introduction_screen();
            key = _getch();
            switch (key)
            {
            case 'Y':
                game_state = 0;
                break;
            case 'N' : 
                break;
            case 'y':
                game_state = 0;
                break;
            case 'n':
                break;
            default:
                break;
            }
            break;

        default:
            break;
        }
        
       
    }
    

    return 0;
}


