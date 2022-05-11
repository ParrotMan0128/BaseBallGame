#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    
    srand((unsigned int)time(0));

    int iArray[9] = {};
    int iInput[3] = {};

    int iStrike;
    int iBall;
    int iGameCount = 1;

    for (int i = 0; i < 9; i++) {

        iArray[i] = i + 1;

    }

    int iTemp, idx1, idx2;

    for (int i = 0; i < 100; i++) {

        idx1 = rand() % 9;
        idx2 = rand() % 9;

        iTemp = iArray[idx1];
        iArray[idx1] = iArray[idx2];
        iArray[idx2] = iTemp;

    }

    cout << "──────────────────────────────\n";
    cout << "[!] \t*\t*\t*\n";
    cout << "──────────────────────────────\n";

    while (true) {

        cout << "[ " << iGameCount << "회 ]" << "1 ~ 9 사이의 숫자 3개를 차례대로 입력해주세요(ex) 1 2 3) (0: 종료) | ";
        cin >> iInput[0] >> iInput[1] >> iInput[2];

        if ( (iInput[0] == 0) || (iInput[1] == 0) || (iInput[2] == 0) ) {

            cout << "[!] 게임을 종료합니다." << endl;
            break;

        } else if ( (iInput[0] == iInput[1]) || (iInput[1] == iInput[2]) || (iInput[0] == iInput[2]) ) {

            cout << "[!] 중복된 숫자를 입력하셨습니다." << endl;
            continue;

        } else if ( (iInput[0] > 9) || (iInput[0] < 0) || (iInput[1] > 9) || (iInput[1] < 0) || (iInput[2] > 9) || (iInput[2] < 0) ) {

            cout << "[!] 잘못된 숫자를 입력하셨습니다." << endl;
            continue;
       
        } else {
            
            iStrike = iBall = 0;

            for (int i = 0; i < 3; i++) {

                for (int j = 0; j < 3; j++) {

                    if (iInput[i] == iArray[j]) {

                        if (i == j) {

                            iStrike++;

                        } else {

                            iBall++;

                        }

                        break;

                    }
                }
            }

            if (iStrike < 3) {

                cout << iStrike << " Strike | " << iBall << " Ball" << endl;

                iGameCount++;

                continue;

            } else {

                cout << "──────────────────────────────\n";
                cout << "[★] 모든 숫자를 맞췄습니다!" << endl;
                cout << "──────────────────────────────\n";
                break;

            }

        }
    }

    return 0;

}
