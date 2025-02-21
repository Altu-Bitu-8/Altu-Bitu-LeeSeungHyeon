// 요요 시뮬레이션

#include <iostream>
#include <cmath>

using namespace std;

// 다이어트 전 상태
struct Stat {
    int Weight;
    int BMR;
    int Thr;
};

// 다이어트 목표
struct Plan {
    int Dur;
    int Intake;
    int Act;
};

// 고려하지 않은 경우
bool not_Concerned(Stat& stat, const Plan& plan) {
    for (int i = 1; i <= plan.Dur; i++) {
        stat.Weight += plan.Intake - (stat.BMR + plan.Act);
        if (stat.Weight <= 0) {
            cout << "Danger Diet" << endl;
            return false;
        }
    }
    cout << stat.Weight << " " << stat.BMR << endl;
    return true;
}

// 고려한 경우
bool Concerned(Stat& stat, const Plan& plan, int not_Concerned_BMR) {
    for (int i = 1; i <= plan.Dur; i++) {
        int weightChange = plan.Intake - (stat.BMR + plan.Act);
        stat.Weight += weightChange;

        if (stat.Weight <= 0) {
            cout << "Danger Diet" << endl;
            return false;
        }

        if (abs(weightChange) > stat.Thr) {
            if (weightChange < 0) {
                stat.BMR += (weightChange - 1) / 2;
            }
            else {
                stat.BMR += (weightChange + 1) / 2;
            }
        }


        if (stat.BMR <= 0) {
            cout << "Danger Diet" << endl;
            return false;
        }
    }

    if (stat.BMR < not_Concerned_BMR) {
        cout << stat.Weight << " " << stat.BMR << " " << "YOYO" << endl;
    }
    else {
        cout << stat.Weight << " " << stat.BMR << " " << "NO" << endl;
    }
    return true;
}

int main() {
    Stat stat;
    Plan plan;

    // 다이어트 전 상태 입력
    cin >> stat.Weight >> stat.BMR >> stat.Thr;
    // 목표 설정
    cin >> plan.Dur >> plan.Intake >> plan.Act;

    if (stat.Weight > 0 && stat.BMR > 0) {
        Stat stat_not_concerned = stat;
        Stat stat_concerned = stat;

        if (not_Concerned(stat_not_concerned, plan)) {
            Concerned(stat_concerned, plan, stat_not_concerned.BMR);
        }
    }

    return 0;
}