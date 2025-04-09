#include <iostream> 
#include <vector>   
#include <deque>    

using namespace std; 

typedef vector<deque<int>> cards; // cards라는 새로운 타입을 정의 (deque의 벡터)
const int DO = 0, SU = 1;         // 두 플레이어를 나타내는 상수

/** 승리 판단하기 */
string judge(cards& deck) { // 각 플레이어의 덱 크기에 따라 승자를 결정하는 함수
    int do_deck = deck[DO].size(), su_deck = deck[SU].size(); // 도도와 수연의 덱 크기를 가져옴
    if (do_deck > su_deck) { // 도도의 덱이 더 크면
        return "do";
    } else if (do_deck < su_deck) { // 수연의 덱이 더 크면
        return "su";
    }
    return "dosu"; // 덱 크기가 같으면 무승부
}

/** 그라운드에서 덱으로 카드 옮기기 */
void groundToDeck(deque<int>& deck, deque<int>& ground) { // 그라운드의 카드를 덱으로 옮기는 함수
    while (!ground.empty()) { // 그라운드가 비어있지 않을 때까지 반복
        deck.push_back(ground.back()); // 그라운드의 마지막 카드를 덱 뒤로 추가
        ground.pop_back(); // 그라운드에서 마지막 카드 제거
    }
}

/** 종을 쳤을 때 */
void ringTheBell(int player, cards& deck, cards& ground) { // 종을 치는 상황을 처리하는 함수
    groundToDeck(deck[player], ground[!player]); // 상대방의 그라운드 카드를 본인의 덱으로 이동
    groundToDeck(deck[player], ground[player]);  // 자신의 그라운드 카드를 본인의 덱으로 이동
}

/** 종을 울릴 수 있는 사람 판단 */
int whoCanRingTheBell(cards& deck, cards& ground) { // 종을 칠 수 있는지 판단하는 함수
    if (!ground[DO].empty() && ground[DO].front() == 5) { // 도도의 그라운드 맨 위 카드가 5일 때
        return DO;
    } else if (!ground[SU].empty() && ground[SU].front() == 5) { // 수연의 그라운드 맨 위 카드가 5일 때
        return SU;
    } else if (!ground[DO].empty() && !ground[SU].empty() && (ground[DO].front() + ground[SU].front() == 5)) { // 두 그라운드 카드 합이 5일 때
        return SU;
    }
    return -1; // 아무도 종을 칠 수 없을 때
}

/** 게임 진행 */
string game(int m, cards& deck, cards& ground) { // 게임을 진행하는 함수
    bool turn = DO; // 도도가 먼저 시작
    while (m--) { // m번 만큼 라운드를 반복
        ground[turn].push_front(deck[turn].front()); // 덱의 맨 위 카드를 그라운드로 옮김
        deck[turn].pop_front(); // 덱에서 맨 위 카드 제거
        if (deck[turn].empty()) { // 현재 플레이어의 덱이 비어있으면 게임 종료
            break;
        }

        int bell = whoCanRingTheBell(deck, ground); // 종을 칠 수 있는지 확인
        if (bell != -1) { // 종을 칠 수 있는 경우
            ringTheBell(bell, deck, ground); // 종을 치고 카드 이동 처리
        }
        turn = !turn; // 턴을 다른 플레이어로 변경
    }
    return judge(deck); // 승자를 판단하여 반환
}

/** 메인 함수 */
int main() {
    int n, m, card1, card2; // n: 초기 카드 수, m: 게임 라운드 수, card1 & card2: 각 플레이어의 카드 값
    cards deck(2), ground(2); // 두 플레이어의 덱과 그라운드 (0: 도도, 1: 수연)

    //카드 데이터 받기
    cin >> n >> m; // 카드 수와 게임 라운드 수 입력
    while (n--) { // n번 만큼 반복하여 카드 입력
        cin >> card1 >> card2; // 도도와 수연의 카드 값을 입력
        deck[DO].push_front(card1); // 도도의 카드 덱에 추가
        deck[SU].push_front(card2); // 수연의 카드 덱에 추가
    }

    //게임 결과 출력
    cout << game(m, deck, ground); // 게임을 실행하고 결과를 출력

    return 0; 
}
