#include<stdio.h>

int input(char, char);
int judge(char);

char line1[9]="    789\n",
     line2[9]="    456\n",
     line3[9]="    123\n";

main()
{
    char c,turn='o';
    printf("���~�Q�[��\n");
    printf("%s%s%s\n",line1,line2,line3);

  while(1){
    while(1){
      if(turn=='o')printf("�����F�����L�[�Ŏw��");
      else printf("�~���F�����L�[�Ŏw��");
      scanf("%c%*[^\n]",&c);getchar();
      if(input(c,turn))printf("������x���͂��Ă�������");
      else break;
    }
    printf("%s%s%s\n",line1,line2,line3);
    if(judge(turn))return;
    if(turn=='o')turn='x';
    else turn='o';
  }
}

int input(char c, char piece)
{
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

int judge(char piece)
{
  if(line3[0]==piece &&line3[1]==piece &&line3[2]==piece ||
     line2[0]==piece &&line2[1]==piece &&line2[2]==piece ||
     line1[0]==piece &&line1[1]==piece &&line1[2]==piece ||
     line3[0]==piece &&line2[0]==piece &&line1[0]==piece ){
     if(piece=='o'){printf("���@���̏���\n");return 1;}
     else{printf("���@���̏���\n");return 1;}
  }
  else if(
     line3[1]==piece &&line2[1]==piece &&line1[1]==piece ||
     line3[2]==piece &&line2[2]==piece &&line1[2]==piece ||
     line3[0]==piece &&line2[1]==piece &&line1[2]==piece ||
     line3[2]==piece &&line2[1]==piece &&line1[0]==piece ){
     if(piece=='o'){printf("���@���̏���\n");return 1;}
     else{printf("�~�@���̏���\n");return 1;}
  }
  else if(line1[0]!=' '&&line1[1]!=' '&&line1[2]!=' '&&
          line2[0]!=' '&&line2[1]!=' '&&line2[2]!=' '&&
          line3[0]!=' '&&line3[1]!=' '&&line3[2]!=' '){
     printf("��������\n");return 1;}
  return 0;
}

