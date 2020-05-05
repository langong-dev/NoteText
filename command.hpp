const char con[10] = "/dev/tty";
char listname[10005][10005];
int listcount = 0;
const char vim[10] = "vim";

int keyboard(){
  return key::getkey();
}

int check(int num){
  printf("Please wait");
  if(num==72||num=='w'||num=='W')return 1;
  if(num==80||num=='s'||num=='S')return 2;
  if(num==75||num=='a'||num=='A')return 3;
  if(num==77||num=='d'||num=='D')return 4;
  if(num==10)return 10;
  else return 0; 
}
