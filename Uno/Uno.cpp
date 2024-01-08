// Uno.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//
#include"Card.h"
#include"Player.h"
#include "Shoe.h"
#include <iostream>
using namespace std;
static Player* CreatePlayer()
{
    // 一人は必ず生成
    char name[32];
    cin >> name;
    return new Player(name);

    do
    {
        int select = 0;
        cout << "プレーヤーを追加しますか？\n"
            << "１．はい　２．いいえ" << flush;
        cin >> select;

        if (select == 1)
        {
            cin >> name;
            char name[32];
            return new Player(name);
        }
        else if (select == 2)
        {
            break;
        }
    } while (true);
}

int main()
{
    srand(time(NULL));
    int StartNum=0;
    int turn = 1;
    bool Reverse = false;
    Shoe shoe;
    Player p1("Player1");
    Player p2("Player2");
    Player p3("Player3");
    Player p4("Player4");

    Player playerList[] = { p1, p2, p3, p4 };
    do
    {

        cout << "最初のカードの枚数を十枚以内で決めてください" << flush;
        cin >> StartNum;
    } while (StartNum>10);
    for (int i = 0; i < 4; ++i)
    {
        for (int D = 1; D <= StartNum; D++) {
            playerList[i].DeawCard(shoe);
        }
    }
    for (int i = 0; i < 4; ++i)
    {
        playerList[i].ShowHand();
    }
    do
    {
        if (Reverse == false) {
            turn++;
            if (turn == 5) {
                turn = 1;
            }
        }
        else if (Reverse == true) {
            turn--;
            if (turn == 0) {
                turn = 4;
            }
        }
        playerList[turn - 1].Game(shoe);
    } while (p1.fin!=true||p2.fin != true|| p3.fin != true|| p4.fin != true);
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
