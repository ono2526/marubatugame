#include<stdio.h>

int input(char, char);
int judge(char);

char line1[9]="    789\n",
     line2[9]="    456\n",
     line3[9]="    123\n";

int win1=0,win2=0;

void main(){
	
	int play,i;
    char c,turn;
start:
	turn='o';
    printf("○×ゲーム\n");
	for(i=0;i<3;i++){
	   line1[i] = ' ';
	   line2[i] = ' ';
	   line3[i] = ' ';
	}
    printf("%s%s%s\n",line1,line2,line3);

	
    while(1){
      while(1){
        if(turn=='o')printf("○先手：数字キーで指定");
        else printf("×後手：数字キーで指定");
        scanf("%c%*[^\n]",&c);getchar();
        if(input(c,turn))printf("もう一度入力してください");
        else break;
      }
      printf("%s%s%s\n",line1,line2,line3);
	  if(judge(turn)){
		  printf("1Pの勝利数……%d回\n",win1);
		  printf("2Pの勝利数……%d回\n",win2);
		  printf("もう一度プレイしますか？\n再プレイ…1,終了…0\n");
		  scanf("%d",&play);
		  if(play == 0){
			  return;
		  }else{
			  goto start;
		      return;
		  }
	  }
      if(turn=='o')turn='x';
      else turn='o';
    }
}

int input(char c, char piece){
  int flg=0;
  switch(c){
    case '1': if(line3[0]==' ')line3[0]=piece ;else flg=1;break;
    case '2': if(line3[1]==' ')line3[1]=piece ;else flg=1;break;
    case '3': if(line3[2]==' ')line3[2]=piece ;else flg=1;break;
    case '4': if(line2[0]==' ')line2[0]=piece ;else flg=1;break;
    case '5': if(line2[1]==' ')line2[1]=piece ;else flg=1;break;
    case '6': if(line2[2]==' ')line2[2]=piece ;else flg=1;break;
    case '7': if(line1[0]==' ')line1[0]=piece ;else flg=1;break;
    case '8': if(line1[1]==' ')line1[1]=piece ;else flg=1;break;
    case '9': if(line1[2]==' ')line1[2]=piece ;else flg=1;break;
    default : flg=1;
  }
  return flg;
}

int judge(char piece){
  if(line3[0]==piece &&line3[1]==piece &&line3[2]==piece ||
     line2[0]==piece &&line2[1]==piece &&line2[2]==piece ||
     line1[0]==piece &&line1[1]==piece &&line1[2]==piece ||
     line3[0]==piece &&line2[0]==piece &&line1[0]==piece ){
     if(piece=='o'){
		 printf("○　先手の勝ち\n");
		 win1 += 1;
		 return 1;
	 }else{
		 printf("○　後手の勝ち\n");
		 win2 += 1;
		 return 1;
	 }
  }
  else if(
     line3[1]==piece &&line2[1]==piece &&line1[1]==piece ||
     line3[2]==piece &&line2[2]==piece &&line1[2]==piece ||
     line3[0]==piece &&line2[1]==piece &&line1[2]==piece ||
     line3[2]==piece &&line2[1]==piece &&line1[0]==piece ){
     if(piece=='o'){
		 printf("○　先手の勝ち\n");
		 win1 += 1;
		 return 1;
	 }else{
		 printf("×　後手の勝ち\n");
		 win2 += 1;
		 return 1;
	 }
  }
  else if(line1[0]!=' '&&line1[1]!=' '&&line1[2]!=' '&&
          line2[0]!=' '&&line2[1]!=' '&&line2[2]!=' '&&
          line3[0]!=' '&&line3[1]!=' '&&line3[2]!=' '){
     printf("引き分け\n");return 1;}
  return 0;
}

