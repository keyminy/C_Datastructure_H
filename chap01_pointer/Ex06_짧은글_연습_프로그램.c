#include <stdio.h>
#include <stdlib.h> //rand, srand, system
#include <string.h> //strlen
#include <time.h> //time, clock
#include <conio.h> //_getch //���۸� ������� �ʴ� ����� �Լ�(�Է��� ���� ���Ͱ� �ʿ����.)

#pragma warning (disable : 4996)

#define ANSWER_LEN      255
#define QUESTION_NUM    10

int main()
{
    const char* question[QUESTION_NUM] = {
        "All greatness is unconscious, or it is little and naught",
        "Life is an incurable disease",
        "Variety's the very spice of life",
        "No man is the wiser for his learning",
        "Love is a sickness full of wees, all remedies refusing",
        "Be great in act, as you have been in thought",
        "A rose is sweeter in the bud than full blown",
        "Genius must be born, and never can be taught",
        "Custom reconciles us to everything",
        "The happiest women, like the happiest nations, have no history"
    };
    char answer[ANSWER_LEN];
    int cnt;
    double accuracy;
    char isExit; // �ڵ� ���Ῡ�� ����

    srand((unsigned int)time(NULL));

    while (1) {
        system("cls"); //ȭ�� �����
        cnt = 0; //���� �ݺ����� �ʱ�ȭ �ǰ�
        int rad = rand() % 10; // 0~9
        printf("%s\n", question[rad]);
        gets_s(answer,ANSWER_LEN);

        //for (int i = 0; i < ANSWER_LEN; i++) {
        //    for (int j = 0; question[rad][j]!='\0'; j++) {
        //        if (answer[i] == question[rad][j]) {
        //            cnt++;
        //        }
        //    }
        //}
        for (int i = 0; i < answer[i] != '\0'; i++) {
            // �� �̰� ���� ������.
            if (answer[i] == question[rad][i]) {
                cnt++;
            }
        }
        accuracy = (double)cnt / strlen(question[rad]) * 100;
        printf("���� : %d\n", cnt);
        printf("��Ȯ�� : %.2f%%\n", accuracy);
        // �Ͻ� ���
        printf("\n\n\t\t��� �Ϸ���(�ƹ�Ű) / �����Ϸ��� (Q/q)�� �Է� �ϼ��� : ");
        isExit = _getch(); // �� ���� �Է��Լ�, ���۸� ������� ����(Enter��� ���ʿ�)
        //system("pause");
        if (isExit == 'Q' || isExit == 'q') {
            break; // �ݺ��� Ż��
        }
    }

    return 0;
}