// ��� �ùķ��̼�

#include <iostream>
#include <cmath>

using namespace std;

// ���̾�Ʈ �� ����
struct Stat {
    int Weight;
    int BMR;
    int Thr;
};

// ���̾�Ʈ ��ǥ
struct Plan {
    int Dur;
    int Intake;
    int Act;
};

// ������� ���� ���
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

// ����� ���
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

    // ���̾�Ʈ �� ���� �Է�
    cin >> stat.Weight >> stat.BMR >> stat.Thr;
    // ��ǥ ����
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