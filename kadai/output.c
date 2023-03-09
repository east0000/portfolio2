#include "parameter.h"

/*
出力画面例
           I          saw        a          girl       with       a          telescope  .			
|          |          |          |          |          |          |          |          |
start      NOUN       VERB       DET        NOUN       PREP       DET        NOUN       end     

|の数などはanalysis.cのcounterを使って調整する。それがint c。一回構文解析が済むごとにcounterが+1され、最後のendを追加するときにも+1されるため、例だとcounterは8となる
*/
void output(DATA * data, int c){//出力する構造体のポインタと、rの格納数

  int i;
  printf("           ");//スペース11個.startのぶんを開ける
  for(i = 0; i < c; i++){
    printf("%-11s",data[i].fifth);//左詰め出力
  }
  printf("\n");
  
  for(i = 0; i < c+1; i++){//c+1なのは、start部分も描写しないといけないから。
    printf("|          ");//|とスペース10個
  }
  
  printf("\n");
  
  for(i = 0; i < c+1; i++){
    printf("%-11s",data[i].r);//左詰め出力
  }
} 


