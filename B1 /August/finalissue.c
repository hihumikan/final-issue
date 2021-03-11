//
//  finalissue.c
//  prg1
//
//  Created by hihumikan on 2020/08/09.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#define x 30
#define y 150
//予め色々なヘッダーファイル読み込ませる。
//defineはライフゲームの表示範囲 これとchar maeとchar usiroを変えることにより表示範囲を変えれる。

int main(void)
{

    int choice;                                         //タイトルでやりたいことを選ばせる
    int playerJK, compJK;                               //ジャンケン用
    int ansS1, ansS2, ansS3, ansS4, ansS5, ansS6;       //線形代数用
    int ansSS1, ansSS2, ansSS3, ansSS4, ansSS5, ansSS6; //線形代数用
    int h[4][4] = {0}, k;                               //線形代数用
    char name[11];                                      //名前
    int i = 0, j = 0, anpi = 0;                         //ライフゲーム
    char mae[30][150], usiro[30][150];                  //ライフゲーム

    printf("\n");
    printf("-----------------------------------------------------------------------\n");
    usleep(2 * 100000); //時間差表示
    printf("\x1b[45m綺麗な街に引っ越してきたら色んな可愛い子に好かれまくってる件について\x1b[49m\n");
    usleep(2 * 100000);
    printf("-----------------------------------------------------------------------\n");
    usleep(2 * 100000);
    printf("\n");
    usleep(2 * 100000);
    printf("                                       最終課題   作者:hihumikan\n"); //タイトル
    printf("\n");
    sleep(1);
    while (choice != 1)
    { //ループ
        printf("1.ゲームスタート 2.説明 3.ゲーム終了\n\n");
        printf("希望する番号を入力してね:");
        scanf("%d", &choice); //入力により選ばせる
        switch (choice)
        {
        case 1:
            printf("\nゲームを起動します...\n");
            break; //ループ脱出
        case 2:
            usleep(1 * 10000);
            printf("\n~あらすじ~\n舞台はヨーロッパ。統一感のある木組みの家と石畳の街。\n");
            usleep(1 * 10000);
            printf("高校入学を機にこの街に引っ越してきた主人公は、");
            printf("下宿先を探しつつ休憩がてら喫茶店に入ると、偶然にもそこが自分の下宿先\x1b[45mレビットハウス\x1b[49mだった！\n");
            usleep(1 * 10000);
            printf("主人公は、お世話になる家に奉仕をするという高校の方針により、\x1b[45mレビットハウス\x1b[49mの店員として、\n");
            printf("そしてレビットハウスの一人娘であるチノの“自称”兄として働くことになるのであった。\n\n");
            usleep(1 * 10000);
            printf("~ゲーム説明~\n");
            usleep(1 * 10000);
            printf("このゲームはビジュアルノベルとその他諸々()を融合したゲームです\n");
            usleep(1 * 10000);
            printf("立ちはだかる問題から君は無事エンドロールを迎えるのか！？\n\n");
            printf("------------------------------------------------------------------------------------------\n");
            continue; //ループ冒頭に戻る
        case 3:
            printf("\nゲーム終了します...\n");
            return 0; //終了させるreturn 0
        case 4:
            printf("隠しコマンドは存在しないよぉ？\n");
            continue; //ループに戻る 4を選ぶ例外コマンドをcontinueさせる
        default:
            printf("\nお兄ちゃんってばー！！ちゃんと選んでね？\n");
            continue; //例外の入力した場合
        }
        printf("\n\n名前を入力してね?(10文字以内):");
        scanf("%s", name); //%s入力
        printf("\n\nこれ以降はEnterを押して話を見てね！\n");
        rewind(stdin);
        getchar(); //enterによる文字のスクロール。ビジュアルノベル風に。
        printf("-----------------------------------------------------------------------------------------------------------------\n");
        printf("\n~エピローグ~\n");
        printf("\n\nエロゲの世界をいつまで信じていたかなんてたわいもない世間話にもならないくらいどうでもいいような話だが、\n");
        rewind(stdin);
        getchar();
        printf("それでも%sがいつまでエロゲの可愛い女の子などという想像上のもふもふしたくなるほどの美少女が現実に居ることを信じていたかというと、\n", name);
        rewind(stdin);
        getchar();
        printf("これは確信を持って言えるが最初から信じてなどいなかった。\n");
        rewind(stdin);
        getchar();
        printf("ブラウン管の画面から現れた美少女はこの世には居ないと理解していたし、\n");
        rewind(stdin);
        getchar();
        printf("記憶を辿ると同じ趣味の友達もあれが実在するとは思っていないような目つきで美少女を眺めていたように思う。\n");
        rewind(stdin);
        getchar();
        printf("現実世界でそんなトリガーハッピーな人生を送ってるヤツの存在を疑っていた。\n");
        rewind(stdin);
        getchar();
        printf("そんなことを頭の片隅でぼんやり考えながら、たいした感慨もなく高校生になった。\n");
        rewind(stdin);
        getchar();
        printf("\n下宿先へ向かう電車に乗ってる。つまらない思考を巡り巡って窓を眺めていると、いきなり、\n");
        rewind(stdin);
        getchar();
        ;
        printf("???:「ちょっとそこの君！ 時間ないからこの問題解いてて！ おねがい！ じゃあね！」\n");
        rewind(stdin);
        getchar();
        printf("見知らぬ黒いマントをまとい、顔は同じ年ぐらいであろう、顔立ちが良かった...美少女と言える! そんな女が紙を渡して帰って行った。 \n");
        rewind(stdin);
        getchar();
        printf("問題紙を見てみると...表題は...春休み課題?\n");
        rewind(stdin);
        getchar();
        printf("この女、課題やってないのか...\n");
        rewind(stdin);
        getchar();
        printf("余暇で頭と手が空いていた%sは美少女の頼みには逆えず、その課題に取り組むことにした。\n", name);
        rewind(stdin);
        getchar();
        printf("\n\n-----------------------------------------------------------------------------------------------------------------\n");
        printf("\n~第1羽:ひと目で尋常でない問題だと見抜いたよ~\n");
        usleep(2 * 10000);
        printf("\n1問目はなんだ・・？...\n");
        rewind(stdin);
        getchar();
        printf("『空欄を適当に埋めて，行列 𝐴 = [𝑎𝑐𝑏𝑑] の行列式 |𝐴| をサラス(Sarrus)の方法で求めよ』\n");
        rewind(stdin);
        getchar();
        printf("何？\n");
        rewind(stdin);
        getchar();
        printf("最初からなんて問題だしてんだ...\n");
        rewind(stdin);
        getchar();

        while (1)
        {                                    //無限ループ
            srand((unsigned int)time(NULL)); //randomにする為のおまじない
            // 2回繰り返し
            for (i = 0; i < 2; i++)
                // 2回繰り返し
                for (j = 0; j < 2; j++)
                {
                    // 二次元配列にランダムな値
                    h[i][j] = rand() % 10;
                }
            //表示
            printf("|%d  %d|\n", h[0][0], h[0][1]);
            printf("|%d  %d|\n", h[1][0], h[1][1]);
            //計算
            ansSS1 = h[0][0] * h[1][1];
            ansSS2 = h[0][1] * h[1][0];
            ansSS3 = ansSS1 - ansSS2;
            //入力
            printf("|𝐴| = + (① ) - (② ) = ③\n\n");
            printf("① は？:");
            scanf("%d", &ansS1);
            printf("\n② は？:");
            scanf("%d", &ansS2);
            printf("\n③ は？:");
            scanf("%d", &ansS3);
            //入力の計算
            ansSS1 = h[0][0] * h[1][1];
            ansSS2 = h[0][1] * h[1][0];
            ansSS3 = ansSS1 - ansSS2;
            //合否
            if (ansS1 == ansSS1 && ansS2 == ansSS2 && ansS3 == ansSS3)
            {
                break; //全て合っているならloop抜け出す
            }
            else
            {
                printf("\x1b[41m[error！！]違うよ！やりなおしてね!\x1b[49m\n\n");
                continue; //合っていない場合はloop冒頭に戻す
            }
        }

        printf("\n\x1b[42m裏には答えが載ってないが・・・これで合ってるだろう。\x1b[49m\n");
        rewind(stdin);
        getchar();
        printf("次はっと・・・\n");
        rewind(stdin);
        getchar();
        printf("『空欄を適当に埋めて，3次元の行列 𝐴 の行列式 |𝐴| をサラス(Sarrus)の方法で求めよ』\n");
        rewind(stdin);
        getchar();
        printf("ったく、めんどくせえな...\n");
        rewind(stdin);
        getchar();

        while (1)
        {                                    //無限ループ
            srand((unsigned int)time(NULL)); //ランダム
            // ３回繰り返し
            for (i = 0; i < 3; i++)
                // ３回繰り返し
                for (j = 0; j < 3; j++)
                {
                    // 二次元配列にランダムに代入
                    h[i][j] = rand() % 10;
                }
            //表示
            printf("|%d  %d  %d|\n", h[0][0], h[0][1], h[0][2]);
            printf("|%d  %d  %d|\n", h[1][0], h[1][1], h[1][2]);
            printf("|%d  %d  %d|\n", h[2][0], h[2][1], h[2][2]);
            //計算
            ansSS1 = h[0][0] * h[1][1] * h[2][2];
            ansSS2 = h[0][1] * h[1][2] * h[2][0];
            ansSS3 = h[1][0] * h[2][1] * h[0][2];

            ansSS4 = h[0][2] * h[1][1] * h[2][0];
            ansSS5 = h[0][1] * h[1][0] * h[2][2];
            ansSS6 = h[0][0] * h[1][2] * h[2][1];

            ansSS1 = ansSS1 + ansSS2 + ansSS3;
            ansSS2 = -ansSS4 - ansSS5 - ansSS6;
            ansSS3 = ansSS1 + ansSS2;
            //表示と入力
            printf("|𝐴| = + (① ) - (② ) = ③ \n\n");
            printf("① は？:");
            scanf("%d", &ansS1);
            printf("\n② は？:");
            scanf("%d", &ansS2);
            printf("\n③ は？:");
            scanf("%d", &ansS3);
            //判定
            if (ansS1 == ansSS1 && ansS2 == ansSS2 && ansS3 == ansSS3)
            {
                break; //全て合っているならループ脱出
            }
            else
            {
                printf("\x1b[41m[error！！]違うよ！やりなおしてね!\x1b[49m\n\n");
                continue; //一つでも合っていなければloop冒頭に戻る。
            }
        }

        printf("\n\x1b[42mこれも裏には答えが載ってないが・・・これで合ってるだろう。\x1b[49m\n");
        rewind(stdin);
        getchar();
        printf("簡単な計算問題とはいえ、計算量はあるから疲れてしまった。\n");
        rewind(stdin);
        getchar();
        printf("っと手を止めたその時\n");
        rewind(stdin);
        getchar();
        printf("隣にいた女子児童から\n");
        rewind(stdin);
        getchar();
        printf("女子児童:おにーちゃん！ジャンケンしよ！\n");
        rewind(stdin); //女子児童登場
        getchar();
        printf("疲れていた俺だったが、断ることをせず、\n");
        rewind(stdin);
        getchar();
        printf("「いいよ」と答えた。\n");
        rewind(stdin);
        getchar();
        printf("\n\n-----------------------------------------------------------------------------------------------------------------\n");
        printf("\n~第12羽:一目で普通じゃない女の子と見抜いたよ~\n"); //最終回
        rewind(stdin);
        getchar();

        //ここからジャンケン
        playerJK = 0; //0を代入しておく
        while (playerJK != 1)
        { //無限ループ
            printf("--ジャンケンをします、出したい手の数字を教えてください--\n");
            printf("1.グー 2.チョキ 3.パー 4.反則技\n");
            printf("出したい手:");
            scanf("%d", &playerJK); //ジャンケンを選ばせる。
            if (playerJK > 0 && playerJK < 4)
            { //4以下ならばループ脱出
                break;
            }

            if (playerJK == 4)
            { //反則技を使った場合、線形代数をやらせて、答えがあってるまでloop
                printf("女子児童:そんなこそくなマネやめようね??\n");
                rewind(stdin);
                getchar();
                printf("女子児童:反則した罰として・・・3次元の行列式求めてね❤️\n");
                rewind(stdin);
                getchar();
                printf("空欄を適当に埋めて，3次元の行列 𝐴 の行列式 |𝐴| をサラス(Sarrus)の方法で求めよ』\n");
                while (1)
                {
                    srand((unsigned int)time(NULL)); // 3回繰り返し
                    for (i = 0; i < 3; i++)          // 3回繰り返し
                        for (j = 0; j < 3; j++)
                        {
                            h[i][j] = rand() % 10;
                        }
                    printf("|%d  %d  %d|\n", h[0][0], h[0][1], h[0][2]);
                    printf("|%d  %d  %d|\n", h[1][0], h[1][1], h[1][2]);
                    printf("|%d  %d  %d|\n", h[2][0], h[2][1], h[2][2]);
                    ansSS1 = h[0][0] * h[1][1] * h[2][2];
                    ansSS2 = h[0][1] * h[1][2] * h[2][0];
                    ansSS3 = h[1][0] * h[2][1] * h[0][2];

                    ansSS4 = h[0][2] * h[1][1] * h[2][0];
                    ansSS5 = h[0][1] * h[1][0] * h[2][2];
                    ansSS6 = h[0][0] * h[1][2] * h[2][1];

                    ansSS1 = ansSS1 + ansSS2 + ansSS3;
                    ansSS2 = -ansSS4 - ansSS5 - ansSS6;
                    ansSS3 = ansSS1 + ansSS2;
                    printf("|𝐴| = + (① ) - (② ) = ③ \n\n");
                    printf("① は？:");
                    scanf("%d", &ansS1);
                    printf("\n② は？:");
                    scanf("%d", &ansS2);
                    printf("\n③ は？:");
                    scanf("%d", &ansS3);
                    if (ansS1 == ansSS1 && ansS2 == ansSS2 && ansS3 == ansSS3)
                    {
                        printf("女子児童:正解ー！おにいちゃんとジャンケンできるね❤️\n");
                        break; //loop脱出ジャンケンに戻る。
                    }
                    else
                    {
                        printf("[error！！]お兄ちゃん違う！！ちゃんと計算して！！\n\n");
                        continue; //答えが合っていない場合は最初から。
                    }
                }
                continue;
            }
            else
            { //合っていなければ
                printf("\n女子児童:ちゃんと数値選んでね❤️\n\n");
                continue; //線形代数の冒頭に戻る
            }
        }

        srand((unsigned int)time(NULL));
        compJK = rand() % 3; //３つの中から選出,あいこ、勝ちならばゲーム終了,負ければ先のプログラムに行く
        if (playerJK == compJK)
        { //あいこならばゲーム終了
            printf("女子児童:あいこだったね。。。つまんなかったしこのゲーム終了するね\n");
            return 0;
        }
        else if (playerJK == 1 && compJK == 2)
        { //プレイヤーが勝つ場合ゲーム終了
            printf("女子児童:負けたーーー！！！つまんない！！！ゲーム終了させてやる！!!\n");
            return 0;
        }
        else if (playerJK == 1 && compJK == 3)
        { //プレイヤーが負ける場合
            printf("女子児童:わーい勝った勝ったー！\n");
        }
        else if (playerJK == 2 && compJK == 1)
        { //プレイヤーが負ける場合
            printf("女子児童:わーい勝った勝ったー！\n");
        }
        else if (playerJK == 2 && compJK == 3)
        { //プレイヤーが勝つ場合ゲーム終了
            printf("女子児童:負けたーーー！！！つまんない！！！ゲーム終了させてやる！!!\n");
            return 0;
        }
        else if (playerJK == 3 && compJK == 1)
        { //プレイヤーが勝つ場合ゲーム終了
            printf("女子児童:負けたーーー！！！つまんない！！！ゲーム終了させてやる！!!\n");
            return 0;
        }
        else if (playerJK == 3 && compJK == 2)
        { //プレイヤーが負ける場合
            printf("女子児童:わーい勝った勝ったー！\n");
        }

        printf("なんなんだこいつは・・・。\n");
        rewind(stdin);
        getchar();
        printf("女子児童:ここまでよくこれたね！コメント文にしてなければの話だけど！\n");
        rewind(stdin);
        getchar();
        printf("女子児童:ここまで来れたご褒美にゲームあげるよ！やってみてね！\n");
        rewind(stdin);
        getchar();
        printf("最後だと？\n");
        rewind(stdin);
        getchar();
        printf("まだ下宿先の喫茶店を見つけてないし美少女の為に解いた線形代数はなんだったんだ\n");
        rewind(stdin);
        getchar();
        printf("これはまさか・・・次回作に持ち越しか・・・。\n");
        rewind(stdin);
        getchar();
        printf("ゲームの名前はっと・・・ライフゲーム？なんだそれは。\n");
        rewind(stdin);
        getchar();
        printf("起動してみるか...。\n");
        rewind(stdin);
        getchar();
        printf("\n\n--ライフゲームを起動しますか？起動しない場合はゲーム終了します(y=1/n=0)\n数字を入力してください:"); //ライフゲームが一番時間掛かりました。
        scanf("%d", &k);                                                                                                //yes or noを選ばせる
        if (k == 0)
        { //noならば終了
            printf("ライフゲームを起動する気力がなくなったからゲームを終了することにする。\n");
            rewind(stdin);
            getchar();
            printf("疲れたしな。\n");
            rewind(stdin);
            getchar();
            printf("可愛い美少女をもふもふ出来ないビジュアルノベルだった。\n");
            rewind(stdin);
            getchar();
            printf("もうこのまま終了すると思いきや、\n");
            rewind(stdin);
            getchar();
            printf("美少女,女子児童:ゲームをプレイしてくれてありがとう！\n");
            rewind(stdin);
            getchar();
            printf("なんというメタい発言、まぁ実際ゲームなんだがな。\n");
            rewind(stdin);
            getchar();
            printf("まぁこれの次回作はちゃんとシナリオ通りにやってくれるといいんだが...\n");
            rewind(stdin);
            getchar();
            printf("果たして、次回作など来るのだろうか。\n");
            rewind(stdin);
            getchar();
            printf("そんなことを思い浮かべながらゲームを終了させるので合った。\n");
            rewind(stdin);
            getchar();
            printf("                        おわり\n");
            return 0;
        }
        else if (k == 1)
        {
            printf("ライフゲームは以下のルールで表示されます。\n");
            printf("0の場合 周囲1マスに3つの1がある場合は1になります\n");
            printf("1の場合 周囲に2,3個の1がある場合は1を維持しつづけます。そうでなければ0になります\n");
            printf("Enterを押すことによりランダムに生成された0,1のライフゲームが開始されます。\n");
            rewind(stdin);
            getchar();
            /*ルール
生命のいない(0)ところには周囲にちょうど３個の生命(1)がある場合に新しく生命が誕生
生命がいる(1)ところは、周囲に２個、または３個の生命(1)がいる場合に、そのまま生命が残ります。 そうでない場合には死んで(0)しまいます。
*/
            srand((unsigned int)time(NULL)); //ランダムにさせるおまじない
            for (i = 0; i < x; i++)
            { //xの幅
                for (j = 0; j < y; j++)
                {                           //yの幅
                    mae[i][j] = rand() % 2; //mae[i][j]に0か1かを代入
                    //printf("%d",mae[i][j]); debug
                    usiro[i][j] = mae[i][j]; //usiroにmaeを代入
                }
                //printf("\n");//debug用
            }
            while (1)
            {                      //無限ループ
                usleep(1 * 50000); //表示遅延 これによりライフゲームの生態系を見易くする。
                for (i = 0; i < x; i++)
                {
                    for (j = 0; j < y; j++)
                    {
                        mae[i][j] = usiro[i][j]; //maeにusiroを代入,初期は互いに代入し合ってるが、後の処理で代入が必要になるため。
                        if (mae[i][j] == 1)
                        { //1ならば*を表示させるとする
                            printf("*");
                        }
                        else if (mae[i][j] == 0)
                        { //0ならば空白表示
                            printf(" ");
                        }

                        anpi = 0; //初期設定 anpiは周囲に1が存在している場合のカウンター
                        if (mae[i + 1][j + 1] == 1)
                        {
                            anpi++;
                        }
                        if (mae[i][j + 1] == 1)
                        {
                            anpi++;
                        }
                        if (mae[i + 1][j] == 1)
                        {
                            anpi++;
                        }
                        if (mae[i - 1][j - 1] == 1)
                        {
                            anpi++;
                        }
                        if (mae[i][j - 1] == 1)
                        {
                            anpi++;
                        }
                        if (mae[i - 1][j] == 1)
                        {
                            anpi++;
                        }
                        if (mae[i - 1][j + 1] == 1)
                        {
                            anpi++;
                        }
                        if (mae[i + 1][j - 1] == 1)
                        {
                            anpi++;
                        }
                        //ルールにしたがって裏側の二次元配列に生か死を代入
                        if (anpi < 2)
                        {                    //周囲に1が1個,0個ならば
                            usiro[i][j] = 0; //死ぬ
                        }
                        else if (anpi == 2)
                        {                            //ちょうど２個ならば
                            usiro[i][j] = mae[i][j]; //維持
                        }
                        else if (anpi == 3)
                        {                    //ちょうど3個ならば
                            usiro[i][j] = 1; //新たな命
                        }
                        else
                        {                    //それ以外ならば
                            usiro[i][j] = 0; //死ぬ
                        }
                    }
                    printf("\n"); //改行
                }
            }
        }
        else
        {
            return 0;
        }
    }
}