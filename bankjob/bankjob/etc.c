#include "mainheader.h"

int secure_password_input()		// ���� ��� ��ȣ�� �Է� �޴� �Լ� 
{
	int x, y;
	int temppass;
	char temp[10];
	int i;

	x=9;
	y=9;
	gotoxy(x, y);
	printf("���� ��й�ȣ �Է� >> ");
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
			printf("��й�ȣ�� �Է����ֽñ� �ٶ��ϴ�.                         ");
			continue;
		}
		if (tempi!=4) {
			gotoxy(x, y);
			printf("4�ڷ� �Է����ֽñ� �ٶ��ϴ�.                              ");
			continue;
		}
		for (i=0; i<tempi; i++) {
			if (isdigit(tempchar[i])==0) {
				gotoxy(x, y);
				printf("���ڷ� �Է����ֽñ� �ٶ��ϴ�.                             ");			
				tempj++;
				break;
			}
		}
		for (i=0; i<tempi; i++) {
			if (tempchar[i]==32) {
				gotoxy(x, y);
				printf("�Է³��� ���̿� ������ ���� �Է����ֽñ� �ٶ��ϴ�.       ");
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

int secure_password_cmp(int pass)	// ���� ��� ��ȣ�� ���ϴ� �Լ� 
{
	if (pass == secure_pass) return 1;
	else return 0;
}	


int secure_password()	// ���Ⱥ�� ��ȣ�� Ȯ�� �ϴ� ��� 
{
	int x;
	int y;
	int temppass;

	base_scr();
	x=3;
	y=4;
	gotoxy(x, y);
	printf("���Ⱥ�й�ȣ �Է�");
	
	while (1) {
		temppass = secure_password_input();
		switch (secure_password_cmp(temppass)) {
		case 1:
			x=10;
			y=31;
			gotoxy(x, y);
			printf("��� ��ȣ�� ��ġ�Ͽ����ϴ�.                ");
			Sleep(1000);
			return 1;
		case 0:
			x=10;
			y=31;
			gotoxy(x, y);
			printf("�ٽ��Է� �ϼ���.                           ");
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
	printf("�� ���� ��й�ȣ �Է� >> ");
	
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
			printf("��й�ȣ�� �Է����ֽñ� �ٶ��ϴ�.                         ");
		}
		if (tempi!=4) {
			gotoxy(x, y);
			printf("4�ڷ� �Է����ֽñ� �ٶ��ϴ�.                              ");
		}
		for (i=0; i<tempi; i++) {
			if (isdigit(tempchar[i])==0) {
				gotoxy(x, y);
				printf("���ڷ� �Է����ֽñ� �ٶ��ϴ�.                             ");			
				tempj++;
				break;
			}
		}
		for (i=0; i<tempi; i++) {
			if (tempchar[i]==32) {
				gotoxy(x, y);
				printf("�Է³��� ���̿� ������ ���� �Է����ֽñ� �ٶ��ϴ�.       ");
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
	printf("�� ���� ��й�ȣ Ȯ�� >> ");
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
			printf("��й�ȣ�� �Է����ֽñ� �ٶ��ϴ�.                         ");
		}
		if (tempi!=4) {
			gotoxy(x, y);
			printf("4�ڷ� �Է����ֽñ� �ٶ��ϴ�.                              ");
		}
		for (i=0; i<tempi; i++) {
			if (isdigit(tempchar[i])==0) {
				gotoxy(x, y);
				printf("���ڷ� �Է����ֽñ� �ٶ��ϴ�.                             ");			
				tempj++;
				break;
			}
		}
		for (i=0; i<tempi; i++) {
			if (tempchar[i]==32) {
				gotoxy(x, y);
				printf("�Է³��� ���̿� ������ ���� �Է����ֽñ� �ٶ��ϴ�.       ");
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
		printf("���� ��й�ȣ�� ����Ǿ����ϴ�.                               ");
		secure_pass =temppass1;
		save_secure_pass();
		Sleep(1000);
	} else {
		printf("�� ���� ��й�ȣ�� ��ġ���� �ʽ��ϴ�.                         ");
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
	printf("���� ��� ��ȣ ����");
	
	while (1) {
		temppass = secure_password_input();
		switch (secure_password_cmp(temppass)) {
		case 1:
			x=10;
			y=31;
			gotoxy(x, y);
			printf("��� ��ȣ�� ��ġ�Ͽ����ϴ�.                ");
			Sleep(1000);
			new_secure_pass();
			return ;
		case 0:
			x=10;
			y=31;
			gotoxy(x, y);
			printf("�ٽ��Է� �ϼ���.                           ");
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

void etc_menu_sel()	 // ��Ÿ �޴��� ���� �ϴ� �Լ�  
{
	int x;
	int y;
	int ch;
	x= 3;
	y =4;
	gotoxy(x, y);
	printf("��Ÿ �޴�");
	x=7;
	y=8;
	do {
		if (ch != ESC && ch != 77) { 
			gotoxy(x, y);
			printf("��");
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
					secure_password_change();	// ���� ��й�ȣ
				} else if (y==10) {
					printf("2\n");
					// ��������� ���� ��ȸ
				} else if (y==12) {
					rate_change();	// ������ ����
				} else if (y==14) {
					salary_change();	// ���� ����
				} else if (y==16) {
					loan_change();	// ���� �ѵ� ����
				} else if (y==18) {
					creditgrade_change();	// �ſ��޼���
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
	printf("������ ����");
	
	gotoxy(9, 9);
	printf("������ ������  ���� -> %.2f", rate.deposit_r);
	
	gotoxy(24, 10);
	printf("���� -> %.2f", rate.installment_r );
	
	gotoxy(24, 11);
	printf("���� -> %.2f", rate.loan_r);
	
	gotoxy(9, 14);
	printf("������ ������  ���� -> ");
	gotoxy(10, 31);
	printf("���ݿ� ���� �������� �Է��ϼ���.");
	while (1) {
		gotoxy(10, 29);
		fflush(stdin);
		gets(rate.dep_r);
		tempi = strlen(rate.dep_r);
		tempj = 0;
		if (tempi==0) {
			gotoxy(10, 31);
			printf("�������� �Է����ֽñ� �ٶ��ϴ�.                           ");
			continue;
		}
		for (i=0; i<tempi; i++) {
			if (isdigit(rate.dep_r[i])==0) {
				gotoxy(10, 31);
				printf("���ڷ� �Է����ֽñ� �ٶ��ϴ�.                            ");
				tempj++;
				break;
			}
		}
		for (i=0; i<tempi; i++) {
			if (isspace(rate.dep_r[i])!=0) {
				gotoxy(10, 31);
				printf("�Է³��� ���̿� ������ ���� �Է����ֽñ� �ٶ��ϴ�.       ");
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
	printf("���� -> ");
	gotoxy(10, 31);
	printf("���ݿ� ���� �������� �Է��ϼ���.");
	
	while (1) {
		gotoxy(10, 29);
		fflush(stdin);
		gets(rate.ins_r);
		tempi = strlen(rate.ins_r);
		tempj = 0;
		if (tempi==0) {
			gotoxy(10, 31);
			printf("�������� �Է����ֽñ� �ٶ��ϴ�.                           ");
			continue;
		}
		for (i=0; i<tempi; i++) {
			if (isdigit(rate.ins_r[i])==0) {
				gotoxy(10, 31);
				printf("���ڷ� �Է����ֽñ� �ٶ��ϴ�.                            ");
				tempj++;
				break;
			}
		}
		for (i=0; i<tempi; i++) {
			if (isspace(rate.ins_r[i])!=0) {
				gotoxy(10, 31);
				printf("�Է³��� ���̿� ������ ���� �Է����ֽñ� �ٶ��ϴ�.       ");
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
	printf("���� ->");
	gotoxy(10, 31);
	printf("���⿡ ���� �������� �Է��ϼ���.");
	while (1) {
		gotoxy(10, 29);
		fflush(stdin);
		gets(rate.lo_r);
		tempi = strlen(rate.lo_r);
		tempj = 0;
		if (tempi==0) {
			gotoxy(10, 31);
			printf("�������� �Է����ֽñ� �ٶ��ϴ�.                           ");
			continue;
		}
		for (i=0; i<tempi; i++) {
			if (isdigit(rate.lo_r[i])==0) {
				gotoxy(10, 31);
				printf("���ڷ� �Է����ֽñ� �ٶ��ϴ�.                            ");
				tempj++;
				break;
			}
		}
		for (i=0; i<tempi; i++) {
			if (isspace(rate.lo_r[i])!=0) {
				gotoxy(10, 31);
				printf("�Է³��� ���̿� ������ ���� �Է����ֽñ� �ٶ��ϴ�.       ");
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
	printf("������ �Ϸ�Ǿ����ϴ�.                                   ");
	Sleep(1000);
	
	save_rate();
}

void salary_change()
{
	base_scr();
	gotoxy(3, 4);
	printf("���� ����");
	
	gotoxy(9, 9);
	printf("������ ������ ���� -> %d", salary.master_s);
	gotoxy(9, 10);
	printf("�Ϲ� ���� ����     -> %d", salary.chief_s );
	gotoxy(9, 11);
	printf("�Ϲ� ���� ����     -> %d", salary.staff_s );
	
	gotoxy(9, 14);
	printf("������ ���� ����   -> ");
	gotoxy(10, 31);
	printf("������ ���� ������ �Է��ϼ���.");
	while (1) {
		gotoxy(10, 29);
		fflush(stdin);
		gets(salary.ch_s);
		tempi = strlen(salary.ch_s);
		tempj = 0;
		if (tempi==0) {
			gotoxy(10, 31);
			printf("������ �Է����ֽñ� �ٶ��ϴ�.                             ");
			continue;
		}
		for (i=0; i<tempi; i++) {
			if (isdigit(salary.ch_s[i])==0) {
				gotoxy(10, 31);
				printf("���ڷ� �Է����ֽñ� �ٶ��ϴ�.                            ");
				tempj++;
				break;
			}
		}
		for (i=0; i<tempi; i++) {
			if (isspace(salary.ch_s[i])!=0) {
				gotoxy(10, 31);
				printf("�Է³��� ���̿� ������ ���� �Է����ֽñ� �ٶ��ϴ�.       ");
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
	printf("�Ϲ� ���� ���� -> ");
	gotoxy(10, 31);
	printf("������ ���� ������ �Է��ϼ���.");
	while (1) {
		gotoxy(10, 29);
		fflush(stdin);
		gets(salary.sta_s);
		tempi = strlen(salary.sta_s);
		tempj = 0;
		if (tempi==0) {
			gotoxy(10, 31);
			printf("������ �Է����ֽñ� �ٶ��ϴ�.                             ");
			continue;
		}
		for (i=0; i<tempi; i++) {
			if (isdigit(salary.sta_s[i])==0) {
				gotoxy(10, 31);
				printf("���ڷ� �Է����ֽñ� �ٶ��ϴ�.                            ");
				tempj++;
				break;
			}
		}
		for (i=0; i<tempi; i++) {
			if (isspace(salary.sta_s[i])!=0) {
				gotoxy(10, 31);
				printf("�Է³��� ���̿� ������ ���� �Է����ֽñ� �ٶ��ϴ�.       ");
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
	printf("������ �Ϸ�Ǿ����ϴ�.                                   ");
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
	printf("���� �ѵ� ����");
	
	x=9;
	y=9;
	gotoxy(x, y);
	printf("������ �ſ��� �� �����ѵ� -> %d", loan.loan_l);
	x=16;
	y=10;
	gotoxy(x, y);
	printf("�ſ��� �� �����ѵ� -> %d", loan.loan_m );
	x=16;
	y=11;
	gotoxy(x, y);
	printf("�ſ��� �� �����ѵ� -> %d", loan.loan_h );
	
	
	x=9;
	y=14;
	gotoxy(x, y);
	printf("������ �ſ��� �� �����ѵ� -> ");
	gotoxy(10, 31);
	printf("������ �ſ��� �� �����ѵ��� �Է��ϼ���.");
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
			printf("�����ѵ��� �Է����ֽñ� �ٶ��ϴ�.                         ");
			continue;
		}
		for (i=0; i<tempi; i++) {
			if (isdigit(loan.lo_l[i])==0) {
				gotoxy(10, 31);
				printf("���ڷ� �Է����ֽñ� �ٶ��ϴ�.                            ");
				tempj++;
				break;
			}
		}
		for (i=0; i<tempi; i++) {
			if (isspace(loan.lo_l[i])!=0) {
				gotoxy(10, 31);
				printf("�Է³��� ���̿� ������ ���� �Է����ֽñ� �ٶ��ϴ�.       ");
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
	printf("�ſ��� �� �����ѵ� -> ");
	gotoxy(10, 31);
	printf("������ �ſ��� �� �����ѵ��� �Է��ϼ���.");
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
			printf("�����ѵ��� �Է����ֽñ� �ٶ��ϴ�.                         ");
			continue;
		}
		for (i=0; i<tempi; i++) {
			if (isdigit(loan.lo_m[i])==0) {
				gotoxy(10, 31);
				printf("���ڷ� �Է����ֽñ� �ٶ��ϴ�.                            ");
				tempj++;
				break;
			}
		}
		for (i=0; i<tempi; i++) {
			if (isspace(loan.lo_m[i])!=0) {
				gotoxy(10, 31);
				printf("�Է³��� ���̿� ������ ���� �Է����ֽñ� �ٶ��ϴ�.       ");
				tempj++;
				break;
			}
		}
		if (tempj==0) {
			if(loan.loan_l>atoi(loan.lo_m)) {
				gotoxy(10, 31);
				printf("�ٽ� �Է��� �ּ���.                                      ");
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
	printf("�ſ��� �� �����ѵ� -> ");
	gotoxy(10, 31);
	printf("������ �ſ��� �� �����ѵ��� �Է��ϼ���.");
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
			printf("�����ѵ��� �Է����ֽñ� �ٶ��ϴ�.                         ");
			continue;
		}
		for (i=0; i<tempi; i++) {
			if (isdigit(loan.lo_h[i])==0) {
				gotoxy(10, 31);
				printf("���ڷ� �Է����ֽñ� �ٶ��ϴ�.                            ");
				tempj++;
				break;
			}
		}
		for (i=0; i<tempi; i++) {
			if (isspace(loan.lo_h[i])!=0) {
				gotoxy(10, 31);
				printf("�Է³��� ���̿� ������ ���� �Է����ֽñ� �ٶ��ϴ�.       ");
				tempj++;
				break;
			}
		}
		if (tempj==0) {
			if(loan.loan_m>atoi(loan.lo_h)) {
				gotoxy(10, 31);
				printf("�ٽ� �Է��� �ּ���.                                      ");
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
	printf("������ �Ϸ�Ǿ����ϴ�.                                   ");
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
	printf("�ſ� ��� ����");
	
	x=9;
	y=9;
	gotoxy(x, y);
	printf("������ �ſ��� �� ���� -> %d����", creditgrade.grade_min);
	x=16;
	y=10;
	gotoxy(x, y);
	printf("�ſ��� �� ���� -> %d ~ %d", creditgrade.grade_min, creditgrade.grade_max);
	x=16;
	y=11;
	gotoxy(x, y);
	printf("�ſ��� �� ���� -> %d�̻�", creditgrade.grade_max);
	
	x=9;
	y=14;
	gotoxy(x, y);
	printf("������ �ſ��� �� ���� �ּҰ� -> ");
	gotoxy(10, 31);
	printf("������ �ſ��� �� ���� �ּҰ��� �Է��ϼ���.");
	while (1) {
		gotoxy(10, 29);
		fflush(stdin);
		gets(creditgrade.gr_min);
		tempi = strlen(creditgrade.gr_min);
		tempj = 0;
		if (tempi==0) {
			gotoxy(10, 31);
			printf("�����ѵ��� �Է����ֽñ� �ٶ��ϴ�.                         ");
			continue;
		}
		for (i=0; i<tempi; i++) {
			if (isdigit(creditgrade.gr_min[i])==0) {
				gotoxy(10, 31);
				printf("���ڷ� �Է����ֽñ� �ٶ��ϴ�.                            ");
				tempj++;
				break;
			}
		}
		for (i=0; i<tempi; i++) {
			if (isspace(creditgrade.gr_min[i])!=0) {
				gotoxy(10, 31);
				printf("�Է³��� ���̿� ������ ���� �Է����ֽñ� �ٶ��ϴ�.       ");
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
	printf("�ſ��� �� ���� �ִ밪 -> ");
	gotoxy(10, 31);
	printf("������ �ſ��� �� ���� �ִ밪�� �Է��ϼ���.");
	while (1) {
		gotoxy(10, 29);
		fflush(stdin);
		gets(creditgrade.gr_max);
		tempi = strlen(creditgrade.gr_max);
		tempj = 0;
		if (tempi==0) {
			gotoxy(10, 31);
			printf("�����ѵ��� �Է����ֽñ� �ٶ��ϴ�.                         ");
			continue;
		}
		for (i=0; i<tempi; i++) {
			if (isdigit(creditgrade.gr_max[i])==0) {
				gotoxy(10, 31);
				printf("���ڷ� �Է����ֽñ� �ٶ��ϴ�.                            ");
				tempj++;
				break;
			}
		}
		for (i=0; i<tempi; i++) {
			if (isspace(creditgrade.gr_max[i])!=0) {
				gotoxy(10, 31);
				printf("�Է³��� ���̿� ������ ���� �Է����ֽñ� �ٶ��ϴ�.       ");
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
	printf("������ �Ϸ�Ǿ����ϴ�.                                   ");
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
			strcpy(trade[trade_cnt].type, "����");
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