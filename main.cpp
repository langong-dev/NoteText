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
  
  /*
  for(int i = 0;i < listcount; i ++){
    cout << listname[i] << endl;
  }
  */
  int pos = listcount;
  printf(" ---Normal---\n\n");  
  while( true ){
    listcount = 0;
    system("cp ~/LanGongNoteText/list ./");
    freopen("list","r",stdin);
    /*for( int i = 0;i < listcount; i ++ ){
      char t[100000];
      scanf("%s",t);
    }*/
    //while(cin >> listname[listcount])listcount++;
    while( scanf("%s",listname[listcount]) != EOF )listcount ++;
    freopen(con,"r",stdin);
    system("rm -f list");
    //sleep(1);
    
    //system("clear");
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
    if( pos == listcount + 1 ){
      printf(" \033[4mExit\033[0m\n");
    }
    else{
      printf(" Exit\n");      
    }
    printf("\n Press Up and Down to choose a Note to write.\n");
    int pes = check(keyboard());
    if(pes == 1){
      system("clear");
      if( pos == 0 ){
        printf(" ---Error---\n Out of the filed!\n");
      }
      else{
        printf(" ---Normal---\n\n");
        pos --;
      }
      continue;
    }
    if(pes == 2){
      system("clear");
      if( pos == listcount + 1 ){
        printf(" ---Error---\n Out of the filed!\n");
      }
      else{
        printf(" ---Normal---\n\n");
        pos ++;
      }
      continue;
    }
    if( pes == 10 ){
      if( pos == listcount + 1 ){
        system("clear");
        break;
      }
      else if( pos == listcount ){
        /*
        char a[1000];
        string b;
        printf("\n Please input filename.\n");
        //scanf("%s",a);
        //cin >> a;
        //getline( cin, b );
        char c;
        int x = 0;
        while( true ){//scanf("%c",c) != EOF ){
          a[ x ++ ] = check(keyboard());
          printf("%c",a[x - 1]);
          if( a[x-1] == '\n' )break;
        }
        a[x]='\0';
        char bs[10005];
        strcpy( bs, "clear && echo -n > ~/LanGongNoteText/" );
        strcat( bs, a );
        strcat( bs, ".md" );
        system( bs );
        */
        system("bash creat.sh && clear");
        //break;
      }
      else{
        system("clear");
        char dobash[1000];
        strcpy( dobash, vim );
        strcat( dobash, " ~/LanGongNoteText/" );
        strcat( dobash, listname[pos] );
        strcat( dobash, ".md" );
        system( dobash );
        //break;
      }
      printf(" ---Normal---\n\n");
    }
  }
}
