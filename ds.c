#include<stdio.h>
#include<ncurses.h>
#include<string.h>


char Login_Register()
{
    
    printw("Do you want to login or register?\n");
    printw("L for Login and R for Register\n");
    char input;
    scanw("%c",&input);
    if(input=='L' || input=='l')
    {
      return 'L';
      printw("Congratulations!\n");
    }
    else
    {
         if(input=='R' || input=='r')
         {
            return 'R';
         }
         else
         {
            clear();
            printf("You entered wrong input!\n");
            return 'E';
         }
    }
}
void Register()
{
//password 
char username[100];
//
char* Password=(char*)malloc(100*sizeof(char));
//
char* again_Password=(char*)malloc(100*sizeof(char));
//
char email[50];
//
//Username
printw("Please enter your username:\n");
scanw("%s",username);
//Password
while(1)
{
printw("Please enter correct password!\n");
printw("It should have an Uppercase, a lowercase, a number and minimum length 7\n");
scanw("%s",Password);
int big=0;
int small=0;
int ragham=0;
        for (int i = 0; i < strlen(Password); i++)
        { 
        if(Password[i]>= 65 && Password[i]<=90)
        {
        big++;
        }
         else if(Password[i]>=97 && Password[i]<=122)
        {
        small++;
        }
        else if(Password[i]>=48 && Password[i]<=57)
        {
        ragham++;
        }
        }
        if(big==0 || small==0 || ragham==0 || strlen(Password)<7)
        {
            clear();
           printw("You entered wrong Password!\n");
        }
        else
        {
            clear();
            break;
        }
}

//Password_again
while(1)
{
printw("Please enter your Password again:\n");
scanw("%s",again_Password);
   if(strcmp(Password,again_Password)==0)
   {
     clear();
    break;
   }
   else
   {
      clear();
      printw("It is not the same as previous Password. Please enter it again!\n");
   }
}
 //Email
 while(1)
 {
    int atsign=0;
 printw("Please enter your E_mail:\n");
 scanw("%s",email);
   for (int  i = 0; i < strlen(email); i++)
   {
     if(email[i]==64)
     {
        atsign++;
     }
   }
   if(atsign==0)
   {
    clear();
       printw("You enteted wrong email!\n");
   }
    else
    {
       break;
    }
}
}
int main()
{
    initscr();
    char Khorooji=Login_Register();
    while(1)
    {
        Khorooji=Login_Register();
        if(Khorooji=='R' || Khorooji=='L')
        {
            printf("Congratulations!\n");
            break;
        }
    }
    if(Khorooji=='L')
    {
        Login();
    }
    if(Khorooji=='R')
    {
        Register();
    }
    char c=getch();
    refresh();
    endwin();
    return 0;
}