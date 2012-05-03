#include "mainheader.h"


void main(void)
{
	load_customer();
	load_staff();
	load_account();
	load_trade();
	load_secure_pass();
	if(secure_pass==0) secure_pass=1111;
	load_rate();
	if (rate.deposit_r==0) {
		rate.deposit_r = 3;
		rate.installment_r = 4;
		rate.loan_r = 6;
	}
	load_loan();
	if (loan.loan_h==0) {
		loan.loan_h = 50000;
		loan.loan_m = 20000;
		loan.loan_l = 5000;
		creditgrade.grade_max = 10000;
		creditgrade.grade_min = 2000;
	}
	load_salary();
	if (salary.master_s	== 0) {
		salary.master_s = 8000;
		salary.chief_s = 4000;
		salary.staff_s = 2500;
	}
	sum();
	if (login()==1) { 
		while (1) {
			mainmenu_scr();
			mainmenu_sel();
		}
	}
}

void mainmenu_sel()
{
	int x;
	int y;
	int ch;
	x=7;
	y=8;
	do {
		if (ch != ESC && ch != 77) { 
			gotoxy(x, y);
			printf("▶");
			ch = getch();
			gotoxy(x, y);
			printf(" ");
		}
		if (ch == 0xE0 || ch==0) {
			ch = getch();
			switch (ch) {
			case UP:
				if (y >8) y-=2;
				break;
			case DOWN:
				if (y <18) y+=2;
				break;
			}
		} else {
			if (ch == ENTER) {
				y=wherey();
					if ( y==8 ) {
						system("cls");
						staffmenu_scr();
						staffmenu_sel();
						return ;
					} else if (y==10) {
						system("cls");
						customer_menu_scr();
						customer_menu_sel();
						return ;
					} else if (y==12) {
						system("cls");
						customer_viewsel_sel(3);
					}  else if (y==14) {
						system("cls");
						customer_viewsel_sel(4);
					} else if (y==16) {
						system("cls");
						if (secure_password()) {
							etc_menu_scr();
							etc_menu_sel();
						}
					} else if (y==18) {
						x=10;
						y=31;
						gotoxy(x, y);
						printf("프로그램을 종료합니다.");
						exit(1);

					}
			} else if (ch == ESC) exit(1);
		}
	} while (ch != ENTER && ch != ESC);
}


void date1() {
    time_t  ltime;
    struct tm *today; 
    int OldSec=0;
   
    time(&ltime);
    today = localtime(&ltime);
	gotoxy(52, 3);
    printf("%04d/%02d/%02d", today->tm_year + 1900, today->tm_mon + 1, today->tm_mday);  
}

void gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X=x;
	Cur.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Cur);
}


// 커서의 x 좌표를 조사한다.
int wherex()
{
	CONSOLE_SCREEN_BUFFER_INFO BufInfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&BufInfo);
	return BufInfo.dwCursorPosition.X;
}

// 커서의 y좌표를 조사한다.
int wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO BufInfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&BufInfo);
	return BufInfo.dwCursorPosition.Y;
}
