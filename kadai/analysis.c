#include "parameter.h"

int analysis(DATA * data){

  int i,k,n;
  int counter = 0;
  int flag;//構文解析できたとき、ループを抜け、次の文字列の解析に向かうために使う。
  
  strcpy(data[0].r, "start");//startを代入

  //strcmpは文字列同士を比較。第一引数＞第二引数で正、逆で負、イコールで0
  
  //NULLはファイルの最後まで来たという合図であり、ループ終了の合図となる
  for(i = 0; (strcmp(data[i].fifth, "NULL")!= 0) && (strcmp(data[i].fifth, ".")!= 0) && (i < MAX_DATA); i++){//テキストの文字列と形態素解析結果が連動
    flag = 0;//1のときループを抜けるため、ここでリセット
    for(k = 0; (strcmp(data[k].first, "NULL")!= 0) && (k < MAX_DATA); k++){//data[k].firstとdata[k].secondが連動。単語辞書部分
      for(n = 0; (strcmp(data[n].third, "NULL") != 0) && (n < MAX_DATA); n++){//data[n].thirdとdata[n].fourthが連動。文法規則部分
        //例：テキストのIと単語辞書のIが一致かつ形態素解析結果のstartと文法規則の遷移前の品詞startが一致かつIの単語辞書の品詞NOUNと文法規則の遷移後の品詞NOUNが一致した場合のみ合格
        if( (strcmp(data[i].fifth, data[k].first ))== 0){
          if((strcmp(data[i].r, data[n].third)) == 0){
            if((strcmp(data[k].second, data[n].fourth)) == 0){   
              strcpy(data[i+1].r , data[k].second);//単語の品詞を形態素解析結果に代入         
              counter++;//このカウンターは最後にendを付け足すとき、解析結果の出力に必要
              flag = 1;//flagが1のとき、break文でループを抜けられる。
            }
          }
        }
       if(flag == 1)
         break;
      }
      if(flag == 1)
        break;
    }  
  }
  counter++;
  strcpy(data[counter].r, "end");//endを代入
  
  return counter;
}
