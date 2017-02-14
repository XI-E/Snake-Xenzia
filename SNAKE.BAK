#include <iostream.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>

#define max_x 80
#define min_x 1
#define max_y 50
#define min_y 1
#define arr_x (max_x - min_x + 2)
#define arr_y (max_y - min_y + 2)


char pos_key[arr_x][arr_y];

void keystroke();
void adjustxy(int&, int&);
void movehead(int, int);
void movetail(char [arr_x][arr_y]);
void addfood();
int checkfood();
int checkdie();
void printgameover();

int x=(max_x - min_x + 1)/2, y=(max_y - min_y + 1)/2;       //head coordinates
int x1, y1;   //tail coordinates
int x2, y2;   //food coordinates
int snaklen = 1;
int frame_width = 150;


void main()
{
///////WELCOME SCREEN//////////
	int choice;
	char choice2;
	flag3:
	for(int l=0; l<arr_x; ++l)
	{
		for(int m=0; m<arr_y; ++m)
		{
			pos_key[l][m]='k';
		}
	}
	clrscr();
	gotoxy((max_x - min_x + 1)/2 - 10, (max_y - min_y + 1)/2 - 6);
	cout<<"********************";
	gotoxy((max_x - min_x + 1)/2 - 10, (max_y - min_y + 1)/2 - 4);
	cout<<"****SNAKE XENZIA****";
	gotoxy((max_x - min_x + 1)/2 - 10, (max_y - min_y + 1)/2 - 2);
	cout<<"********************";
	gotoxy((max_x - min_x + 1)/2 - 10, (max_y - min_y + 1)/2);
	cout<<"1. Play";
	gotoxy((max_x - min_x + 1)/2 - 10, (max_y - min_y + 1)/2 + 1);
	cout<<"2. Controls";
	gotoxy((max_x - min_x + 1)/2 - 10, (max_y - min_y + 1)/2 + 2);
	cout<<"3. Options";
	gotoxy((max_x - min_x + 1)/2 - 10, (max_y - min_y + 1)/2 + 3);
	cout<<"4. Exit";
	gotoxy((max_x - min_x + 1)/2 - 10, (max_y - min_y + 1)/2 + 4);
	cout<<"Enter your choice: ";
	cin>>choice;
	switch (choice)
	{
		case 1 :
			clrscr();
			x=(max_x - min_x + 1)/2, y=(max_y - min_y + 1)/2;
			addfood();
			keystroke();
			break;
		case 2 :
			clrscr();
			gotoxy((max_x - min_x + 1)/2 - 3, (max_y - min_y + 1)/2 - 3);
			cout<<"CONTROLS";
			gotoxy((max_x - min_x + 1)/2 - 15, (max_y - min_y + 1)/2 - 1);
			cout<<"1. Esc - Exits the game while playing";
			gotoxy((max_x - min_x + 1)/2 - 15, (max_y - min_y + 1)/2 + 1);
			cout<<"2. 'w', 'a', 's', 'd' to move the snake";
			gotoxy((max_x - min_x + 1)/2 - 15, (max_y - min_y + 1)/2 + 3);
			cout<<"Press any key to return to the previous menu...";
			getch();
			goto flag3;
			break;
		case 3 :
			flag4:
			clrscr();
			gotoxy((max_x - min_x + 1)/2 - 3, (max_y - min_y + 1)/2 - 6);
			cout<<"OPTIONS";
			gotoxy((max_x - min_x + 1)/2 - 8, (max_y - min_y + 1)/2 - 4);
			cout<<"1. Set difficulty level: ";
			gotoxy((max_x - min_x + 1)/2 - 5, (max_y - min_y + 1)/2 - 3);
			cout<<"1.1 Easy";
			gotoxy((max_x - min_x + 1)/2 - 5, (max_y - min_y + 1)/2 - 2);
			cout<<"1.2 Medium";
			gotoxy((max_x - min_x + 1)/2 - 5, (max_y - min_y + 1)/2 - 1);
			cout<<"1.3 Hard";
			gotoxy((max_x - min_x + 1)/2 - 8, (max_y - min_y + 1)/2 + 1);
			cout<<"2. Set screen size";
			gotoxy((max_x - min_x + 1)/2 - 8, (max_y - min_y + 1)/2 + 2);
			cout<<"3. Back to main menu";
			gotoxy((max_x - min_x + 1)/2 - 8, (max_y - min_y + 1)/2 + 4);
			cout<<"Enter your choice: ";
			cin>>choice2;
			switch (choice2)
			{
				case '1':
					gotoxy((max_x - min_x + 1)/2 - 16, (max_y - min_y + 1)/2 + 4);
					cout<<"Enter the subchoice (enter invalid";
					gotoxy((max_x - min_x + 1)/2 - 16, (max_y - min_y + 1)/2 + 5);
					cout<<" input to go back): 1.";
					cin>>choice2;
					switch(choice2)
					{
						case '1':
							frame_width=150;
							gotoxy((max_x - min_x + 1)/2 - 16, (max_y - min_y + 1)/2 + 6);
							cout<<"The difficulty level is now set to 'Easy'";
							getch();
							goto flag4;
						case '2':
							frame_width=100;
							gotoxy((max_x - min_x + 1)/2 - 16, (max_y - min_y + 1)/2 + 6);
							cout<<"The difficulty level is now set to 'Medium'";
							getch();
							goto flag4;
						case '3':
							frame_width=50;
							gotoxy((max_x - min_x + 1)/2 - 16, (max_y - min_y + 1)/2 + 6);
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
			gotoxy((max_x - min_x + 1)/2 - 19, (max_y - min_y + 1)/2);
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


}

void keystroke()
{
	flag:
	char c0, c=getch();
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
					y==max_y ? pos_key[x][min_y] : pos_key[x][y+1] = 'w';
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
					y==min_y ? pos_key[x][max_y] : pos_key[x][y-1] = 's';
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
					x==max_x ? pos_key[min_x][y] : pos_key[x+1][y] = 'a';
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
					x==min_x ? pos_key[max_x][y] : pos_key[x-1][y] = 'd';
					movetail(pos_key);
					printgameover();
					delay(frame_width);
				}while(!kbhit());
				break;
		}
		c0=getch();
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
	if (y == max_y + 1)
		y=min_y;
	else if (y == min_y - 1)
		y=max_y;
		if (x == max_x + 1)
		x=min_x;
	else if (x == min_x - 1)
		x=max_x;
//	gotoxy(x, y);
//	cout<<"@";//<<x<<", "<<y;
	return;
}
void movehead (int x, int y)
{
	gotoxy(x, y);
	cout<<"@";
//	delay(500);
}

void movetail (char pos_key[arr_x][arr_y])
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
//		delay(500);
		return;


}
void addfood()
{
	do
	{
		randomize();
		x2 = random(max_x - min_x + 1) + min_x;
		y2 = random(max_y - min_y + 1) + min_y;
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
				gotoxy((max_x - min_x + 1)/2 - 5 , (max_y - min_y + 1)/2);
				cout<<"GAME OVER!!";
				delay(400);
				clrscr();
				delay(600);
				++k;
			}while(k<=4);
			gotoxy((max_x - min_x + 1)/2 - 5 , (max_y - min_y + 1)/2);
			cout<<"GAME OVER!!";
			gotoxy((max_x - min_x + 1)/2 - 12 , (max_y - min_y + 1)/2 + 1);
			cout<<"Press any key to exit...";
			getch();
			main();
		}
}