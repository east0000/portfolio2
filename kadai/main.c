#include "parameter.h"//parameter．hを読み込む


//関数定義
void input(DATA * data, char * filename1, char * filename2, char * filename3); 
int analysis(DATA * data);
void output(DATA * data, int c); 
  
  
int main(int argc, char *argv[]){//argcは実行時の引数の数。*argv[]は引数文字列の配列へのポインタ
  if(argc != 4){//コマンドライン引数が4でなければエラー。今回はmain.cとdic.txt,gra.txt,text.txtが必要なので4つ
    printf("main filename.txt.\n");
    exit(1);
  }

  //変数の定義
  //ファイル名
  char file1[MAX_NAME];
  char file2[MAX_NAME];
  char file3[MAX_NAME];
  //構造体データ
  DATA Data[MAX_DATA];
  
  int count;
  
  if((strcpy(file1, argv[1])) == NULL || (strcpy(file2, argv[2])) == NULL || (strcpy(file3,argv[3])) == NULL) exit(1); //strcpyは第２引数を第１引数にコピーする。ファイル名取得
  //argv[1]はコマンドライン第二引数。

  //ファイルのデータ取得
  input(Data, file1, file2, file3);
  //形態素解析
  count = analysis(Data);//形態素解析を済ませ、かつ形態素解析の結果を含んだ配列の要素数を返す。
  
  output(Data,count);

  return 0;
}
