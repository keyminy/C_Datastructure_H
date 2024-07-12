#include <stdio.h>
#include <stdlib.h> //rand, srand, system
#include <string.h> //strlen
#include <time.h> //time, clock
#include <conio.h> //_getch //버퍼를 사용하지 않는 입출력 함수(입력의 끝에 엔터가 필요없다.)

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
    char isExit; // 코드 종료여부 선택

    srand((unsigned int)time(NULL));

    while (1) {
        system("cls"); //화면 지우기
        cnt = 0; //문제 반복마다 초기화 되게
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
            // 왜 이걸 생각 못했지.
            if (answer[i] == question[rad][i]) {
                cnt++;
            }
        }
        accuracy = (double)cnt / strlen(question[rad]) * 100;
        printf("갯수 : %d\n", cnt);
        printf("정확도 : %.2f%%\n", accuracy);
        // 일시 대기
        printf("\n\n\t\t계속 하려면(아무키) / 종료하려면 (Q/q)를 입력 하세요 : ");
        isExit = _getch(); // 한 글자 입력함수, 버퍼를 사용하지 않음(Enter사용 불필요)
        //system("pause");
        if (isExit == 'Q' || isExit == 'q') {
            break; // 반복문 탈출
        }
    }

    return 0;
}