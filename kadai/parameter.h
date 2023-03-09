//ヘッダーファイル
#include <stdio.h>
#include <string.h>//文字列関数を要するために必要
#include <stdlib.h>//一般ユーティリティー

#define MAX_NAME 1000//ファイル名の文字数の上限
#define MAX_DATA 1000//データ数の上限
#define MAX_STR 1000//データ内の文字列の文字数の上限

typedef struct Data{//typedefにより構造体struct型がDATA型で使用できるようになり、変数Dataを宣言
  char first[MAX_STR];//単語
  char second[MAX_STR];//単語の品詞
  char third[MAX_STR];//文法
  char fourth[MAX_STR];//文法
  char fifth[MAX_STR];//テキストの単語を格納
  char r[MAX_DATA];//形態素解析結果を格納
} DATA;//DATA型

