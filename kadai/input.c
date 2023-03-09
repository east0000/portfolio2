#include "parameter.h"

void input(DATA * data, char * filename1, char * filename2, char * filename3){

  int i;

  FILE *fp1;//ファイル構造のポインタ作成。stdio.hに構造体が含まれている
  FILE *fp2;
  FILE *fp3;

  char fi[MAX_STR];//単語辞書(dic.txt)の左側の文字列を取得
  char se[MAX_STR];//単語辞書の右側の文字列を取得
  char th[MAX_STR];//文法規則(gra.txt)の左側の文字列を取得
  char fo[MAX_STR];//文法規則の右側の文字列を取得
  char fif[MAX_STR];//テキスト(text.txt)を取得

  //3つのファイルを開く
  if((fp1 = fopen(filename1, "r")) == NULL || (fp2 = fopen(filename2, "r")) == NULL || (fp3 = fopen(filename3, "r")) == NULL){
    printf("you can't open file\n");
    exit(1);
  }

  //ファイルの最後まで行くと、ファイルから文字を読み込めなくなりEOFを返す。そのときになったらループ終了。i < MAX_DATAは保険であり、読み込むデータがあまりに大きすぎるとき強制終了する。
  for(i = 0; (((fscanf(fp1,"%s\t%s\n", fi, se)) != EOF) && (i < MAX_DATA)) ; i++){//\tはtab分横にずらす。つまり、頭を合わせられる。%sは文字列を受け取る。
    strcpy(data[i].first, fi);//第２引数を第１引数にコピー。つまり、ファイルの文字列をdata構造体にコピー
    strcpy(data[i].second, se);
    //配列名は配列の最初のアドレスを示している。つまり、配列はポインタで作られている。そのため、ポインタは配列のように扱うことができる。それが*が不要な理由である。
    //次のループでは、変数は上書きされる。
  }

    //終端記号をつける
  strcpy(data[i].first,"NULL");
  strcpy(data[i].second,"NULL");

  for(i = 0; (((fscanf(fp2,"%s\t%s\n", th, fo)) != EOF) && (i < MAX_DATA)) ; i++){
    strcpy(data[i].third, th);
    strcpy(data[i].fourth, fo);
  }

  //終端記号をつける
  strcpy(data[i].third,"NULL");
  strcpy(data[i].fourth,"NULL");
  
  //テキストの文字を読み取る。
  for(i = 0; (((fscanf(fp3,"%s\n", fif)) != EOF) && (i < MAX_DATA)) ; i++){
    strcpy(data[i].fifth, fif);
  }
  
  strcpy(data[i].fifth,"NULL");
  
  //ファイルを閉じる
  fclose(fp1);
  fclose(fp2);
  fclose(fp3);

}
