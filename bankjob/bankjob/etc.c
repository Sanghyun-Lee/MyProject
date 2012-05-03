#include "mainheader.h"

int secure_password_input()		// 보안 비밀 번호를 입력 받는 함수 
{
	int x, y;
	int temppass;
	char temp[10];
	int i;

	x=9;
	y=9;
	gotoxy(x, y);
	printf("보안 비밀번호 입력 >> ");
	while (1) {
		x=10;
		y=29;
		gotoxy(x, y);
		printf("                                    ");
		x=10;
		y=29;
		gotoxy(x, y);
		fflush(stdin);
		strcpy(tempchar, "");
		for (i=0; (tempchar[i]=getch())!='\r'; i++) printf("*");
		tempchar[i] = '\0';
		
		tempi = strlen(tempchar);
		tempj = 0;
		y=31;
		
		if (tempi==0) {
			gotoxy(x, y);
			printf("비밀번호를 입력해주시기 바랍니다.                         ");
			continue;
		}
		if (tempi!=4) {
			gotoxy(x, y);
			printf("4자로 입력해주시기 바랍니다.                              ");
			continue;
		}
		for (i=0; i<tempi; i++) {
			if (isdigit(tempchar[i])==0) {
				gotoxy(x, y);
				printf("숫자로 입력해주시기 바랍니다.                             ");			
				tempj++;
				break;
			}
		}
		for (i=0; i<tempi; i++) {
			if (tempchar[i]==32) {
				gotoxy(x, y);
				printf("입력내용 사이에 공백이 없이 입력해주시기 바랍니다.       ");
				tempj++;
				break;
			}
		}
		itoa(secure_pass, temp, 10);
		if (tempj==0 && strcmp(temp, tempchar)==0 )  {
			x=33;
			y=9;
			gotoxy(x,y);
					
			printf("****");
			
			temppass = atoi(tempchar);
			return temppass;
		}
	}
}

int secure_password_cmp(int pass)	// 보안 비밀 번호를 비교하는 함수 
{
	if (pass == secure_pass) return 1;
	else return 0;
}	


int secure_password()	// 보안비밀 번호를 확인 하는 모듈 
{
	int x;
	int y;
	int temppass;

	base_scr();
	x=3;
	y=4;
	gotoxy(x, y);
	printf("보안비밀번호 입력");
	
	while (1) {
		temppass = secure_password_input();
		switch (secure_password_cmp(temppass)) {
		case 1:
			x=10;
			y=31;
			gotoxy(x, y);
			printf("비밀 번호가 일치하였습니다.                ");
			Sleep(1000);
			return 1;
		case 0:
			x=10;
			y=31;
			gotoxy(x, y);
			printf("다시입력 하세요.                           ");
			Sleep(1000);
			x=33;
			y=9;
			gotoxy(x, y);
			printf("                       ");
			x=10;
			y=31;
			gotoxy(x, y);
			printf("                                    ");
			x=10;
			y=29;
			gotoxy(x, y);
			printf("                                    ");
			break;
		}
	}
}

void new_secure_pass()
{
	int x, y;
	int temppass1=0, temppass2=0;

	x=10;
	y=29;
	gotoxy(x,y);
	printf("                                             ");

	x=9, y=11;
	gotoxy(x, y);
	printf("새 보안 비밀번호 입력 >> ");
	
	while (1) {
		x=10;
		y=29;
		gotoxy(x, y);
		fflush(stdin);
		strcpy(tempchar, "");
		for (i=0; (tempchar[i]=getch())!='\r'; i++) printf("*");
		tempchar[i] = '\0';
		
		tempi = strlen(tempchar);
		tempj = 0;
		y=31;
		
		if (tempi==0) {
			gotoxy(x, y);
			printf("비밀번호를 입력해주시기 바랍니다.                         ");
		}
		if (tempi!=4) {
			gotoxy(x, y);
			printf("4자로 입력해주시기 바랍니다.                              ");
		}
		for (i=0; i<tempi; i++) {
			if (isdigit(tempchar[i])==0) {
				gotoxy(x, y);
				printf("숫자로 입력해주시기 바랍니다.                             ");			
				tempj++;
				break;
			}
		}
		for (i=0; i<tempi; i++) {
			if (tempchar[i]==32) {
				gotoxy(x, y);
				printf("입력내용 사이에 공백이 없이 입력해주시기 바랍니다.       ");
				tempj++;
				break;
			}
		}
		if (tempj==0 )  {
			x=37;
			y=11;
			gotoxy(x,y);
			
			printf("****");
			
			temppass1 = atoi(tempchar);
			break;
		}
	}
	
	x=10;
	y=29;
	gotoxy(x,y);
	printf("                                             ");

	x=9, y=13;
	gotoxy(x, y);
	printf("새 보안 비밀번호 확인 >> ");
	while (1) {
		x=10;
		y=29;
		gotoxy(x, y);
		fflush(stdin);
		strcpy(tempchar, "");
		for (i=0; (tempchar[i]=getch())!='\r'; i++) printf("*");
		tempchar[i] = '\0';
		
		tempi = strlen(tempchar);
		tempj = 0;
		y=31;
		
		if (tempi==0) {
			gotoxy(x, y);
			printf("비밀번호를 입력해주시기 바랍니다.                         ");
		}
		if (tempi!=4) {
			gotoxy(x, y);
			printf("4자로 입력해주시기 바랍니다.                              ");
		}
		for (i=0; i<tempi; i++) {
			if (isdigit(tempchar[i])==0) {
				gotoxy(x, y);
				printf("숫자로 입력해주시기 바랍니다.                             ");			
				tempj++;
				break;
			}
		}
		for (i=0; i<tempi; i++) {
			if (tempchar[i]==32) {
				gotoxy(x, y);
				printf("입력내용 사이에 공백이 없이 입력해주시기 바랍니다.       ");
				tempj++;
				break;
			}
		}
		
		if (tempj==0 )  {
			x=37;
			y=13;
			gotoxy(x,y);
			
			printf("****");
			
			temppass2 = atoi(tempchar);
			break;
		}
	}
	
	x=10;
	y=31;
	gotoxy(x, y);
	if (temppass1 == temppass2) {
		printf("보안 비밀번호가 변경되었습니다.                               ");
		secure_pass =temppass1;
		save_secure_pass();
		Sleep(1000);
	} else {
		printf("새 보안 비밀번호가 일치하지 않습니다.                         ");
		Sleep(1000);
	}
}

void secure_password_change()
{
	int temppass;
	int x, y;
	base_scr();

	x=3;
	y=4;
	gotoxy(x, y);
	printf("보안 비밀 번호 수정");
	
	while (1) {
		temppass = secure_password_input();
		switch (secure_password_cmp(temppass)) {
		case 1:
			x=10;
			y=31;
			gotoxy(x, y);
			printf("비밀 번호가 일치하였습니다.                ");
			Sleep(1000);
			new_secure_pass();
			return ;
		case 0:
			x=10;
			y=31;
			gotoxy(x, y);
			printf("다시입력 하세요.                           ");
			Sleep(1000);
			x=33;
			y=9;
			gotoxy(x, y);
			printf("                       ");
			x=10;
			y=31;
			gotoxy(x, y);
			printf("                                    ");
			x=10;
			y=29;
			gotoxy(x, y);
			printf("                                    ");
			continue;
		}
	}
}

void etc_menu_sel()	 // 기타 메뉴를 선택 하는 함수  
{
	int x;
	int y;
	int ch;
	x= 3;
	y =4;
	gotoxy(x, y);
	printf("기타 메뉴");
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
					secure_password_change();	// 보안 비밀번호
				} else if (y==10) {
					printf("2\n");
					// 은행입출금 내역 조회
				} else if (y==12) {
					rate_change();	// 이자율 설정
				} else if (y==14) {
					salary_change();	// 연봉 설정
				} else if (y==16) {
					loan_change();	// 대출 한도 설정
				} else if (y==18) {
					creditgrade_change();	// 신용등급설정
				}

			} else if (ch == ESC) exit(1);
		}
	} while (ch != ENTER && ch != ESC);
}
////////////////////////////////////////////////////////
void rate_change()
{	
	base_scr();
	gotoxy(3, 4);
	printf("이자율 설정");
	
	gotoxy(9, 9);
	printf("현재의 이자율  예금 -> %.2f", rate.deposit_r);
	
	gotoxy(24, 10);
	printf("적금 -> %.2f", rate.installment_r );
	
	gotoxy(24, 11);
	printf("대출 -> %.2f", rate.loan_r);
	
	gotoxy(9, 14);
	printf("수정할 이자율  예금 -> ");
	gotoxy(10, 31);
	printf("예금에 대한 이자율을 입력하세요.");
	while (1) {
		gotoxy(10, 29);
		fflush(stdin);
		gets(rate.dep_r);
		tempi = strlen(rate.dep_r);
		tempj = 0;
		if (tempi==0) {
			gotoxy(10, 31);
			printf("이자율을 입력해주시기 바랍니다.                           ");
			continue;
		}
		for (i=0; i<tempi; i++) {
			if (isdigit(rate.dep_r[i])==0) {
				gotoxy(10, 31);
				printf("숫자로 입력해주시기 바랍니다.                            ");
				tempj++;
				break;
			}
		}
		for (i=0; i<tempi; i++) {
			if (isspace(rate.dep_r[i])!=0) {
				gotoxy(10, 31);
				printf("입력내용 사이에 공백이 없이 입력해주시기 바랍니다.       ");
				tempj++;
				break;
			}
		}
		if (tempj==0) {
			rate.deposit_r = atof(rate.dep_r);
			break;
		}
		else {
			gotoxy(10, 29);
			printf("                                                   ");
			continue;
		}
	}
	gotoxy(10, 29);
	printf("                                                        ");
	gotoxy(32, 14);
	printf("%.2f", rate.deposit_r);
	
	gotoxy(10, 31);
	printf("                                                        ");
	
	gotoxy(24, 15);
	printf("적금 -> ");
	gotoxy(10, 31);
	printf("적금에 대한 이자율을 입력하세요.");
	
	while (1) {
		gotoxy(10, 29);
		fflush(stdin);
		gets(rate.ins_r);
		tempi = strlen(rate.ins_r);
		tempj = 0;
		if (tempi==0) {
			gotoxy(10, 31);
			printf("이자율을 입력해주시기 바랍니다.                           ");
			continue;
		}
		for (i=0; i<tempi; i++) {
			if (isdigit(rate.ins_r[i])==0) {
				gotoxy(10, 31);
				printf("숫자로 입력해주시기 바랍니다.                            ");
				tempj++;
				break;
			}
		}
		for (i=0; i<tempi; i++) {
			if (isspace(rate.ins_r[i])!=0) {
				gotoxy(10, 31);
				printf("입력내용 사이에 공백이 없이 입력해주시기 바랍니다.       ");
				tempj++;
				break;
			}
		}
		if (tempj==0) {
			rate.installment_r = atof(rate.ins_r);
			break;
		}
		else {
			gotoxy(10, 29);
			printf("                                                   ");
			continue;
		}
	}
	
	gotoxy(10, 29);
	printf("                                                        ");
	gotoxy(32, 15);
	printf("%.2f", rate.installment_r);
	gotoxy(10, 31);
	printf("                                                        ");
	
	gotoxy(24, 16) ;
	printf("대출 ->");
	gotoxy(10, 31);
	printf("대출에 대한 이자율을 입력하세요.");
	while (1) {
		gotoxy(10, 29);
		fflush(stdin);
		gets(rate.lo_r);
		tempi = strlen(rate.lo_r);
		tempj = 0;
		if (tempi==0) {
			gotoxy(10, 31);
			printf("이자율을 입력해주시기 바랍니다.                           ");
			continue;
		}
		for (i=0; i<tempi; i++) {
			if (isdigit(rate.lo_r[i])==0) {
				gotoxy(10, 31);
				printf("숫자로 입력해주시기 바랍니다.                            ");
				tempj++;
				break;
			}
		}
		for (i=0; i<tempi; i++) {
			if (isspace(rate.lo_r[i])!=0) {
				gotoxy(10, 31);
				printf("입력내용 사이에 공백이 없이 입력해주시기 바랍니다.       ");
				tempj++;
				break;
			}
		}
		if (tempj==0) {
			rate.loan_r = atof(rate.lo_r);
			break;
		}
		else {
			gotoxy(10, 29);
			printf("                                                   ");
			continue;
		}
	}
	gotoxy(10, 29);
	printf("                                                        ");
	gotoxy(32, 16);
	printf("%.2f", rate.loan_r);
	gotoxy(10, 31);
	printf("수정이 완료되었습니다.                                   ");
	Sleep(1000);
	
	save_rate();
}

void salary_change()
{
	base_scr();
	gotoxy(3, 4);
	printf("연봉 설정");
	
	gotoxy(9, 9);
	printf("현재의 은행장 연봉 -> %d", salary.master_s);
	gotoxy(9, 10);
	printf("일반 과장 연봉     -> %d", salary.chief_s );
	gotoxy(9, 11);
	printf("일반 직원 연봉     -> %d", salary.staff_s );
	
	gotoxy(9, 14);
	printf("수정할 과장 연봉   -> ");
	gotoxy(10, 31);
	printf("수정할 과장 연봉을 입력하세요.");
	while (1) {
		gotoxy(10, 29);
		fflush(stdin);
		gets(salary.ch_s);
		tempi = strlen(salary.ch_s);
		tempj = 0;
		if (tempi==0) {
			gotoxy(10, 31);
			printf("연봉을 입력해주시기 바랍니다.                             ");
			continue;
		}
		for (i=0; i<tempi; i++) {
			if (isdigit(salary.ch_s[i])==0) {
				gotoxy(10, 31);
				printf("숫자로 입력해주시기 바랍니다.                            ");
				tempj++;
				break;
			}
		}
		for (i=0; i<tempi; i++) {
			if (isspace(salary.ch_s[i])!=0) {
				gotoxy(10, 31);
				printf("입력내용 사이에 공백이 없이 입력해주시기 바랍니다.       ");
				tempj++;
				break;
			}
		}
		if (tempj==0) {
			salary.chief_s = atoi(salary.ch_s);
			break;
		}
		else {
			gotoxy(10, 29);
			printf("                                                   ");
			continue;
		}
	}
	gotoxy(10, 29);
	printf("                                                        ");
	gotoxy(10, 31);
	printf("                                                        ");
	gotoxy(32, 14);

	printf("%d", salary.chief_s);
	gotoxy(9, 15);
	printf("일반 직원 연봉 -> ");
	gotoxy(10, 31);
	printf("수정할 직원 연봉을 입력하세요.");
	while (1) {
		gotoxy(10, 29);
		fflush(stdin);
		gets(salary.sta_s);
		tempi = strlen(salary.sta_s);
		tempj = 0;
		if (tempi==0) {
			gotoxy(10, 31);
			printf("연봉을 입력해주시기 바랍니다.                             ");
			continue;
		}
		for (i=0; i<tempi; i++) {
			if (isdigit(salary.sta_s[i])==0) {
				gotoxy(10, 31);
				printf("숫자로 입력해주시기 바랍니다.                            ");
				tempj++;
				break;
			}
		}
		for (i=0; i<tempi; i++) {
			if (isspace(salary.sta_s[i])!=0) {
				gotoxy(10, 31);
				printf("입력내용 사이에 공백이 없이 입력해주시기 바랍니다.       ");
				tempj++;
				break;
			}
		}
		if (tempj==0) {
			salary.staff_s = atoi(salary.sta_s);
			break;
		}
		else {
			gotoxy(10, 29);
			printf("                                                   ");
			continue;
		}
	}
	gotoxy(10, 29);
	printf("                                                        ");
	gotoxy(32, 15);
	printf("%d", salary.staff_s);
	gotoxy(10, 31);
	printf("수정이 완료되었습니다.                                   ");
	Sleep(1000);

	save_salary();
}

//////////////////////////////////////////////////////


void loan_change()
{
	int x, y;
	base_scr();
	x = 3;
	y = 4;
	gotoxy(x, y);
	printf("대출 한도 설정");
	
	x=9;
	y=9;
	gotoxy(x, y);
	printf("현재의 신용등급 하 대출한도 -> %d", loan.loan_l);
	x=16;
	y=10;
	gotoxy(x, y);
	printf("신용등급 중 대출한도 -> %d", loan.loan_m );
	x=16;
	y=11;
	gotoxy(x, y);
	printf("신용등급 상 대출한도 -> %d", loan.loan_h );
	
	
	x=9;
	y=14;
	gotoxy(x, y);
	printf("수정할 신용등급 하 대출한도 -> ");
	gotoxy(10, 31);
	printf("수정할 신용등급 하 대출한도를 입력하세요.");
	while (1) {
		gotoxy(10, 29);
		printf("                                                   ");
		gotoxy(10, 29);
		fflush(stdin);
		gets(loan.lo_l);
		tempi = strlen(loan.lo_l);
		tempj = 0;
		if (tempi==0) {
			gotoxy(10, 31);
			printf("대출한도를 입력해주시기 바랍니다.                         ");
			continue;
		}
		for (i=0; i<tempi; i++) {
			if (isdigit(loan.lo_l[i])==0) {
				gotoxy(10, 31);
				printf("숫자로 입력해주시기 바랍니다.                            ");
				tempj++;
				break;
			}
		}
		for (i=0; i<tempi; i++) {
			if (isspace(loan.lo_l[i])!=0) {
				gotoxy(10, 31);
				printf("입력내용 사이에 공백이 없이 입력해주시기 바랍니다.       ");
				tempj++;
				break;
			}
		}
		if (tempj==0) {
			loan.loan_l = atoi(loan.lo_l);
			break;
		}
		else {
			gotoxy(10, 29);
			printf("                                                   ");
			continue;
		}
	}
	
	gotoxy(10, 29);
	printf("                                                        ");
	gotoxy(10, 31);
	printf("                                                        ");
	gotoxy(40, 14);
	printf("%d", loan.loan_l);

	x=16;
	y=15;
	gotoxy(x, y);
	printf("신용등급 중 대출한도 -> ");
	gotoxy(10, 31);
	printf("수정할 신용등급 중 대출한도를 입력하세요.");
	while (1) {
		gotoxy(10, 29);
		printf("                                                   ");
		gotoxy(10, 29);
		fflush(stdin);
		gets(loan.lo_m);
		tempi = strlen(loan.lo_m);
		tempj = 0;
		if (tempi==0) {
			gotoxy(10, 31);
			printf("대출한도를 입력해주시기 바랍니다.                         ");
			continue;
		}
		for (i=0; i<tempi; i++) {
			if (isdigit(loan.lo_m[i])==0) {
				gotoxy(10, 31);
				printf("숫자로 입력해주시기 바랍니다.                            ");
				tempj++;
				break;
			}
		}
		for (i=0; i<tempi; i++) {
			if (isspace(loan.lo_m[i])!=0) {
				gotoxy(10, 31);
				printf("입력내용 사이에 공백이 없이 입력해주시기 바랍니다.       ");
				tempj++;
				break;
			}
		}
		if (tempj==0) {
			if(loan.loan_l>atoi(loan.lo_m)) {
				gotoxy(10, 31);
				printf("다시 입력해 주세요.                                      ");
				continue;
			}
			loan.loan_m = atoi(loan.lo_m);
			break;
		}
		else {
			gotoxy(10, 29);
			printf("                                                   ");
			continue;
		}
	}

	gotoxy(10, 29);
	printf("                                                        ");
	gotoxy(10, 31);
	printf("                                                        ");
	gotoxy(40, 15);
	printf("%d", loan.loan_m);
	
	x=16;
	y=16;
	gotoxy(x, y);
	printf("신용등급 상 대출한도 -> ");
	gotoxy(10, 31);
	printf("수정할 신용등급 상 대출한도를 입력하세요.");
	while (1) {
		gotoxy(10, 29);
		printf("                                                   ");
		gotoxy(10, 29);
		fflush(stdin);
		gets(loan.lo_h);
		tempi = strlen(loan.lo_h);
		tempj = 0;
		if (tempi==0) {
			gotoxy(10, 31);
			printf("대출한도를 입력해주시기 바랍니다.                         ");
			continue;
		}
		for (i=0; i<tempi; i++) {
			if (isdigit(loan.lo_h[i])==0) {
				gotoxy(10, 31);
				printf("숫자로 입력해주시기 바랍니다.                            ");
				tempj++;
				break;
			}
		}
		for (i=0; i<tempi; i++) {
			if (isspace(loan.lo_h[i])!=0) {
				gotoxy(10, 31);
				printf("입력내용 사이에 공백이 없이 입력해주시기 바랍니다.       ");
				tempj++;
				break;
			}
		}
		if (tempj==0) {
			if(loan.loan_m>atoi(loan.lo_h)) {
				gotoxy(10, 31);
				printf("다시 입력해 주세요.                                      ");
				continue;
			}
			loan.loan_h = atoi(loan.lo_h);
			break;
		}
		else {
			gotoxy(10, 29);
			printf("                                                   ");
			continue;
		}
	}
	gotoxy(10, 29);
	printf("                                                        ");
	gotoxy(40, 16);
	printf("%d", loan.loan_h);
	gotoxy(10, 31);
	printf("수정이 완료되었습니다.                                   ");
	Sleep(1000);
	save_loan();
}

///////////////////////////////////////////////////////////////


void creditgrade_change()
{
	int x, y;
	base_scr();
	x = 3;
	y=4;
	gotoxy(x, y);
	printf("신용 등급 설정");
	
	x=9;
	y=9;
	gotoxy(x, y);
	printf("현재의 신용등급 하 연봉 -> %d이하", creditgrade.grade_min);
	x=16;
	y=10;
	gotoxy(x, y);
	printf("신용등급 중 연봉 -> %d ~ %d", creditgrade.grade_min, creditgrade.grade_max);
	x=16;
	y=11;
	gotoxy(x, y);
	printf("신용등급 상 연봉 -> %d이상", creditgrade.grade_max);
	
	x=9;
	y=14;
	gotoxy(x, y);
	printf("수정할 신용등급 중 연봉 최소값 -> ");
	gotoxy(10, 31);
	printf("수정할 신용등급 중 연봉 최소값을 입력하세요.");
	while (1) {
		gotoxy(10, 29);
		fflush(stdin);
		gets(creditgrade.gr_min);
		tempi = strlen(creditgrade.gr_min);
		tempj = 0;
		if (tempi==0) {
			gotoxy(10, 31);
			printf("대출한도를 입력해주시기 바랍니다.                         ");
			continue;
		}
		for (i=0; i<tempi; i++) {
			if (isdigit(creditgrade.gr_min[i])==0) {
				gotoxy(10, 31);
				printf("숫자로 입력해주시기 바랍니다.                            ");
				tempj++;
				break;
			}
		}
		for (i=0; i<tempi; i++) {
			if (isspace(creditgrade.gr_min[i])!=0) {
				gotoxy(10, 31);
				printf("입력내용 사이에 공백이 없이 입력해주시기 바랍니다.       ");
				tempj++;
				break;
			}
		}
		if (tempj==0) {
			creditgrade.grade_min = atoi(creditgrade.gr_min);
			break;
		}
		else {
			gotoxy(10, 29);
			printf("                                                   ");
			continue;
		}
	}
	gotoxy(10, 29);
	printf("                                                        ");
	gotoxy(10, 31);
	printf("                                                        ");
	gotoxy(43, 14);
	printf("%d", creditgrade.grade_min);

	x=16;
	y=15;
	gotoxy(x, y);
	printf("신용등급 중 연봉 최대값 -> ");
	gotoxy(10, 31);
	printf("수정할 신용등급 중 연봉 최대값을 입력하세요.");
	while (1) {
		gotoxy(10, 29);
		fflush(stdin);
		gets(creditgrade.gr_max);
		tempi = strlen(creditgrade.gr_max);
		tempj = 0;
		if (tempi==0) {
			gotoxy(10, 31);
			printf("대출한도를 입력해주시기 바랍니다.                         ");
			continue;
		}
		for (i=0; i<tempi; i++) {
			if (isdigit(creditgrade.gr_max[i])==0) {
				gotoxy(10, 31);
				printf("숫자로 입력해주시기 바랍니다.                            ");
				tempj++;
				break;
			}
		}
		for (i=0; i<tempi; i++) {
			if (isspace(creditgrade.gr_max[i])!=0) {
				gotoxy(10, 31);
				printf("입력내용 사이에 공백이 없이 입력해주시기 바랍니다.       ");
				tempj++;
				break;
			}
		}
		if (tempj==0) {
			creditgrade.grade_max = atoi(creditgrade.gr_max);
			break;
		}
		else {
			gotoxy(10, 29);
			printf("                                                   ");
			continue;
		}
	}
	gotoxy(10, 29);
	printf("                                                        ");
	gotoxy(43, 15);
	printf("%d", creditgrade.grade_max);
	gotoxy(10, 31);
	printf("수정이 완료되었습니다.                                   ");
	Sleep(1000);
	
	save_loan();
}


//////////////////////////////////////////////////////

int dayminus(int n)
{
	time_t ttime;
	date a;
	int day=0, tradeday=0;
	int d[13] = {0 , 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31};
	struct tm *today;
	time(&ttime);
	today = localtime(&ttime);
	a.year = trade[n].day.year;
	a.month = trade[n].day.month;
	a.day = trade[n].day.day;
	for (j=1; j<a.year%2000; j++) tradeday = tradeday + 365;
	for (j=1; j<(today->tm_year+1900)%2000; j++) day = day + 365;
	for (j=1; j<a.month; j++) tradeday = tradeday + d[j];
	for (j=1; j<today->tm_mon+1; j++) day = day + d[j];
	tradeday = tradeday + a.day;
	day = day + today->tm_mday;
	return day - tradeday;
}

////////////////////////////////////////////////////////////

int sumday(date tempday)
{
	time_t ttime;
	int tomonth=0, month=0;
	struct tm *today;
	time(&ttime);
	today = localtime(&ttime);
	for (tempi=1; tempi<tempday.year%2000; tempi++) month = month + 12;
	for (tempi=1; tempi<(today->tm_year+1900)%2000; tempi++) tomonth = tomonth + 12;
	month = month + tempday.month;
	tomonth = tomonth + today->tm_mon+1;
	return tomonth - month;
}

void sum()
{
	int x;
	date tempday;
	time_t ttime;
	struct tm *today;
	time(&ttime);
	today = localtime(&ttime);
	for (i=1; i<=account_cnt; i++) {
		for (j=0; j<trade_cnt; j++) if ((account[i].number-1841100000)==trade[j].number) tempday = trade[j].day;
		x = sumday(tempday);
		for (tempi=1; tempi<=x; tempi++) {
			trade[trade_cnt].money = (account[i].money * (1+rate.deposit_r/100))-account[i].money;
			trade[trade_cnt].number = account[i].number-1841100000;
			strcpy(trade[trade_cnt].type, "이자");
			trade[trade_cnt].day.year = today->tm_year+1900;
			trade[trade_cnt].day.month = tempday.month+tempi;
			if (tempday.month+tempi>12) trade[trade_cnt].day.month = trade[trade_cnt].day.month - 12;
			trade[trade_cnt].day.day = 1;
			trade_cnt++;
			account[i].money = account[i].money * (1+rate.deposit_r/100);			
			save_trade();
			save_account();
		}
	}
}