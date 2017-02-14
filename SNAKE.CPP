#include <iostream.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>

#define MAX_X 80         //maximum horizontal coordinate of screen
#define MIN_X 1          //minimum horizontal coordinate of screen
#define MAX_Y 49         //maximum vertical coordinate of screen(set this to 1 less than the actual value for your screen)
#define MIN_Y 1          //minimum vertical coordinate of screen
#define ARR_X (MAX_X - MIN_X + 2)
#define ARR_Y (MAX_Y - MIN_Y + 2) //dimensions of pos_key matrix


char pos_key[ARR_X][ARR_Y];  //matrix corresponding to every position on the screen

void keystroke();          //function which receives and maps keystrokes and decides the corresponding movement
void adjustxy(int&, int&); //helps in swapping screen sides when snake reaches one edge of screen
void movehead(int, int);
void movetail(char [ARR_X][ARR_Y]);
void addfood();
int checkfood();           //checks if snake has eate food or not
int checkdie();            //checks if snake has bitten itself or not
void printgameover();      //terminates game if checkdie() is true
char getdir();             //converts arrow key input to alphabets

int x=(MAX_X - MIN_X + 1)/2, y=(MAX_Y - MIN_Y + 1)/2;       //head coordinates
int x1, y1;   //tail coordinates
int x2, y2;   //food coordinates
int snaklen = 1;
int frame_width = 150;   //sets default game speed


void main()
{
///////WELCOME SCREEN//////////
	int choice;
	char choice2;
	flag3:
	for(int l=0; l<ARR_X; ++l)
	{
		for(int m=0; m<ARR_Y; ++m)
		{
			pos_key[l][m]='k';
		}
	}
	clrscr();
	gotoxy((MAX_X - MIN_X + 1)/2 - 10, (MAX_Y - MIN_Y + 1)/2 - 6);
	cout<<"********************";
	gotoxy((MAX_X - MIN_X + 1)/2 - 10, (MAX_Y - MIN_Y + 1)/2 - 4);
	cout<<"****SNAKE XENZIA****";
	gotoxy((MAX_X - MIN_X + 1)/2 - 10, (MAX_Y - MIN_Y + 1)/2 - 2);
	cout<<"********************";
	gotoxy((MAX_X - MIN_X + 1)/2 - 10, (MAX_Y - MIN_Y + 1)/2);
	cout<<"1. Play";
	gotoxy((MAX_X - MIN_X + 1)/2 - 10, (MAX_Y - MIN_Y + 1)/2 + 1);
	cout<<"2. Controls";
	gotoxy((MAX_X - MIN_X + 1)/2 - 10, (MAX_Y - MIN_Y + 1)/2 + 2);
	cout<<"3. Options";
	gotoxy((MAX_X - MIN_X + 1)/2 - 10, (MAX_Y - MIN_Y + 1)/2 + 3);
	cout<<"4. Exit";
	gotoxy((MAX_X - MIN_X + 1)/2 - 10, (MAX_Y - MIN_Y + 1)/2 + 4);
	cout<<"Enter your choice: ";
	cin>>choice;
	switch (choice)
	{
		case 1 :
			clrscr();
			x=(MAX_X - MIN_X + 1)/2, y=(MAX_Y - MIN_Y + 1)/2;
			addfood();
			keystroke();
			break;
		case 2 :
			clrscr();
			gotoxy((MAX_X - MIN_X + 1)/2 - 3, (MAX_Y - MIN_Y + 1)/2 - 3);
			cout<<"CONTROLS";
			gotoxy((MAX_X - MIN_X + 1)/2 - 15, (MAX_Y - MIN_Y + 1)/2 - 1);
			cout<<"1. Esc - Exits the game while playing";
			gotoxy((MAX_X - MIN_X + 1)/2 - 15, (MAX_Y - MIN_Y + 1)/2 + 1);
			cout<<"2. Arrow keys to move the snake";
			gotoxy((MAX_X - MIN_X + 1)/2 - 15, (MAX_Y - MIN_Y + 1)/2 + 3);
			cout<<"Press any key to return to the previous menu...";
			getch();
			goto flag3;
			break;
		case 3 :
			flag4:
			clrscr();
			gotoxy((MAX_X - MIN_X + 1)/2 - 3, (MAX_Y - MIN_Y + 1)/2 - 6);
			cout<<"OPTIONS";
			gotoxy((MAX_X - MIN_X + 1)/2 - 8, (MAX_Y - MIN_Y + 1)/2 - 4);
			cout<<"1. Set difficulty level: ";
			gotoxy((MAX_X - MIN_X + 1)/2 - 5, (MAX_Y - MIN_Y + 1)/2 - 3);
			cout<<"1.1 Easy";
			gotoxy((MAX_X - MIN_X + 1)/2 - 5, (MAX_Y - MIN_Y + 1)/2 - 2);
			cout<<"1.2 Medium";
			gotoxy((MAX_X - MIN_X + 1)/2 - 5, (MAX_Y - MIN_Y + 1)/2 - 1);
			cout<<"1.3 Hard";
			gotoxy((MAX_X - MIN_X + 1)/2 - 8, (MAX_Y - MIN_Y + 1)/2 + 1);
			cout<<"2. Set screen size";
			gotoxy((MAX_X - MIN_X + 1)/2 - 8, (MAX_Y - MIN_Y + 1)/2 + 2);
			cout<<"3. Back to main menu";
			gotoxy((MAX_X - MIN_X + 1)/2 - 8, (MAX_Y - MIN_Y + 1)/2 + 4);
			cout<<"Enter your choice: ";
			cin>>choice2;
			switch (choice2)
			{
				case '1':
					gotoxy((MAX_X - MIN_X + 1)/2 - 16, (MAX_Y - MIN_Y + 1)/2 + 4);
					cout<<"Enter the subchoice (enter invalid";
					gotoxy((MAX_X - MIN_X + 1)/2 - 16, (MAX_Y - MIN_Y + 1)/2 + 5);
					cout<<" input to go back): 1.";
					cin>>choice2;
					switch(choice2)
					{
						case '1':
							frame_width=150;
							gotoxy((MAX_X - MIN_X + 1)/2 - 16, (MAX_Y - MIN_Y + 1)/2 + 6);
							cout<<"The difficulty level is now set to 'Easy'";
							getch();
							goto flag4;
						case '2':
							frame_width=100;
							gotoxy((MAX_X - MIN_X + 1)/2 - 16, (MAX_Y - MIN_Y + 1)/2 + 6);
							cout<<"The difficulty level is now set to 'Medium'";
							getch();
							goto flag4;
						case '3':
							frame_width=50;
							gotoxy((MAX_X - MIN_X + 1)/2 - 16, (MAX_Y - MIN_Y + 1)/2 + 6);
							cout<<"The difficulty level is now set to 'Hard'";
							getch();
							goto flag4;
						default :
							goto flag4;
					}
				case '2':
					clrscr();
					cout<<"UNDER CONSTRUCTION";
					cout<<"\nYou'll have to set screen size by modifying the source code.";
					cout<<"\nNot at all sorry for the inconvenience:-|";
					cout<<"\nPress any key to continue...";
					getch();
					goto flag4;
				case '3':
					goto flag3;
				default:
					goto flag4;

			}

			break;
		case 4 :
			clrscr();
			gotoxy((MAX_X - MIN_X + 1)/2 - 19, (MAX_Y - MIN_Y + 1)/2);
			cout<<"Are you sure you want to exit? (y/n): ";
			cin>>choice2;
			if(choice2=='y' || choice2=='Y')
			{
				exit(0);
			}
			else
			{
				goto flag3;
			}
			break;
	}
	goto flag3;
  /////END OF WELCOME SCREEN/////
  /////END OF MAIN/////
}

void keystroke()
{
	flag:
	char c0, c=getdir();
	switch(c)
	{
		case 'w':
			x1=x;
			y1=y+1;
			break;
		case 's':
			x1=x;
			y1=y-1;
			break;
		case 'a':
			x1=x+1;
			y1=y;
			break;
		case 'd':
			x1=x-1;
			y1=y;
			break;
		default :
			goto flag;
	}
	pos_key[x1][y1]=c;
	flag2:
		switch(c)
		{
			case 'w':
				do
				{
					y--;
					adjustxy(x, y);
					movehead(x, y);
					y==MAX_Y ? pos_key[x][MIN_Y] : pos_key[x][y+1] = 'w';
					movetail(pos_key);
					printgameover();
					delay(frame_width);
				}while(!kbhit());
				break;
			case 's':
				do
				{
					y++;
					adjustxy(x, y);
					movehead(x, y);
					y==MIN_Y ? pos_key[x][MAX_Y] : pos_key[x][y-1] = 's';
					movetail(pos_key);
					printgameover();
					delay(frame_width);
				}while(!kbhit());
				break;
			case 'a':
				do
				{
					x--;
					adjustxy(x, y);
					movehead(x, y);
					x==MAX_X ? pos_key[MIN_X][y] : pos_key[x+1][y] = 'a';
					movetail(pos_key);
					printgameover();
					delay(frame_width);
				}while(!kbhit());
				break;
			case 'd':
				do
				{
					x++;
					adjustxy(x, y);
					movehead(x, y);
					x==MIN_X ? pos_key[MAX_X][y] : pos_key[x-1][y] = 'd';
					movetail(pos_key);
					printgameover();
					delay(frame_width);
				}while(!kbhit());
				break;
		}
		c0=getdir();
		//to ignore opposite direction keystroke and any other keystroke
		if(c0==27)
		{
			return;
		}
		else
		{
			switch (c)
			{
				case 'w':
					if (c0=='a' || c0=='d')
					{
						c=c0;
						goto flag2;
					}
					else
					{
						goto flag2;
					}
					break;
				case 's':
					if (c0=='a' || c0=='d')
					{
						c=c0;
						goto flag2;
					}
					else
					{
						goto flag2;
					}
					break;
				case 'a':
					if (c0=='w' || c0=='s')
					{
						c=c0;
						goto flag2;
					}
					else
					{
						goto flag2;
					}
					break;
				case 'd':
					if (c0=='w' || c0=='s')
					{
						c=c0;
						goto flag2;
					}
					else
					{
						goto flag2;
					}
					break;
			}
		}

}
void adjustxy(int &x, int &y)
{
	if (y == MAX_Y + 1)
		y=MIN_Y;
	else if (y == MIN_Y - 1)
		y=MAX_Y;
		if (x == MAX_X + 1)
		x=MIN_X;
	else if (x == MIN_X - 1)
		x=MAX_X;
//	gotoxy(x, y);
//	cout<<"@";//<<x<<", "<<y;   //for testing purposes
	return;
}
void movehead (int x, int y)
{
	gotoxy(x, y);
	cout<<"@";
//	delay(500);                //for testing purposes
}

void movetail (char pos_key[ARR_X][ARR_Y])
{
	if(checkfood()!=0)
	{
		++snaklen;
		addfood();
		return;
	}
	else if (checkfood()==0)
	{
		switch(pos_key[x1][y1])
		{
			case 'w':
				pos_key[x1][y1]=' ';
				y1--;
				adjustxy(x1, y1);
				gotoxy(x1, y1);
				cout<<" ";
				break;
			case 's':
				pos_key[x1][y1]=' ';
				y1++;
				adjustxy(x1, y1);
				gotoxy(x1, y1);
				cout<<" ";
				break;
			case 'a':
				pos_key[x1][y1]=' ';
				x1--;
				adjustxy(x1, y1);
				gotoxy(x1, y1);
				cout<<" ";
				break;
			case 'd':
				pos_key[x1][y1]=' ';
				x1++;
				adjustxy(x1, y1);
				gotoxy(x1, y1);
				cout<<" ";
				break;

		}

	}
//		delay(500);    //for testing purposes
		return;


}
void addfood()
{
	do
	{
		randomize();
		x2 = random(MAX_X - MIN_X + 1) + MIN_X;
		y2 = random(MAX_Y - MIN_Y + 1) + MIN_Y;
	}while(x2==x && y2==y || (pos_key[x2][y2]=='w' || pos_key[x2][y2]=='s' ||
									 pos_key[x2][y2]=='a' || pos_key[x2][y2]=='d'   ));
	gotoxy(x2, y2);
	cout<<"@";
	return;

}
int checkfood()
{
	if(x==x2 && y==y2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int checkdie()
{
	if(pos_key[x][y]=='w' || pos_key[x][y]=='s' ||
		pos_key[x][y]=='a' || pos_key[x][y]=='d'   )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void printgameover()
{
	if(checkdie()!=0)
		{
			int k=1;
			delay(frame_width);
			do
			{
				gotoxy((MAX_X - MIN_X + 1)/2 - 5 , (MAX_Y - MIN_Y + 1)/2);
				cout<<"GAME OVER!!";
				delay(400);
				clrscr();
				delay(600);
				++k;
			}while(k<=4);
			gotoxy((MAX_X - MIN_X + 1)/2 - 5 , (MAX_Y - MIN_Y + 1)/2);
			cout<<"GAME OVER!!";
			gotoxy((MAX_X - MIN_X + 1)/2 - 8 , (MAX_Y - MIN_Y + 1)/2 + 1);
			cout<<"Final Score: "<<snaklen*10;
			gotoxy((MAX_X - MIN_X + 1)/2 - 12 , (MAX_Y - MIN_Y + 1)/2 + 2);
			cout<<"Press any key to exit...";
			getch();
			main();
		}
}
char getdir()
{
	char ch = getch();
	if(ch==0)
	{
		ch=getch();
		switch(ch)
		{
			case 'H':
				return 'w';
			case 'P':
				return 's';
			case 'K':
				return 'a';
			case 'M':
				return 'd';
			default :
				return 'x';
		}
	}
	else if(ch==27)
	{
		return ch;
	}
	else
	{
		return 'x';
	}
}