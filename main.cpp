#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<climits>
#include<fstream>
#include<curses.h>
#include<unistd.h>
using namespace std;
#include"getkeyboard.hpp"
#include"command.hpp"

int main()
{
  printf("Hello! Welcome to LanGong NoteText Editer!\n");
  sleep(1);
  printf("Loading...\n");
  sleep(1);
  system("clear");
  system("cp ~/LanGongNoteText/list ./");
  freopen("list","r",stdin);
  while(cin >> listname[listcount])listcount++;
  freopen(con,"r",stdin);
  system("rm -f list");
  /*
  for(int i = 0;i < listcount; i ++){
    cout << listname[i] << endl;
  }
  */
  int pos = listcount;
  while( true ){
    system("clear");
    printf(" Your Note : \n\n");
    for( int i = 0; i < listcount; i ++ )
    {
      if( pos == i ){
        printf(" \033[4m%s\033[0m\n",listname[i]);
      }
      else{
        printf(" %s\n",listname[i]);
      }
    }
    if( pos == listcount ){
      printf(" \033[4mCreat a new note\033[0m\n");
    }
    else{
      printf(" Creat a new note\n");
    }
    printf("\n Press Up and Down to choose a Note to write.\n");
    int pes = check(keyboard());
    if(pes == 1){
      if( pos == 0 ){
        printf("\n ---Error---\n Out of the filed!\n");
      }
      else{
        printf("\n ---Normal---\n\n");
        pos --;
      }
      continue;
    }
    if(pes == 2){
      if( pos == listcount ){
        printf("\n ---Error---\n Out of the filed!\n");
      }
      else{
        printf("\n ---Normal---\n\n");
        pos ++;
      }
      continue;
    }
    if( pes == 10 ){
      if( pos == listcount ){
        char a[1000];
        string b;
        printf("\n Please input filename.\n");
        scanf("%s",a);
        //cin >> a;
        //getline( cin, b );
        char bs[10005];
        strcpy( bs, "clear && echo > ~/LanGongNoteText/" );
        strcat( bs, a );
        strcat( bs, ".md" );
        system( bs );
        break;
      }
      else{
        system("clear");
        char dobash[1000];
        strcpy( dobash, vim );
        strcat( dobash, " ~/LanGongNoteText/" );
        strcat( dobash, listname[pos] );
        strcat( dobash, ".md" );
        system( dobash );
        break;
      }
    }
  }
}
