#include "mainheader.h"

void name()
{
	int x, y;
	gotoxy(10, 31);
	printf("�̸��� �Է��ϼ���.                                     ");
	while(1) {
		x=10;
		y=29;
		gotoxy(x, y);
		printf("                                                          ");

		gotoxy(x, y);
		fflush(stdin);
		gets(na);
		tempi = strlen(na);
		tempj = 0;
		y=31;

		if (tempi>40) {
			gotoxy(x, y);
			printf("40�� ���Ϸ� �Է����ֽñ� �ٶ��ϴ�.                        ");
			continue;
		}
		if (tempi==0) {
			gotoxy(x, y);
			printf("�̸��� �Է����ֽñ� �ٶ��ϴ�.                             ");
			continue;
		}
		for (i=0; i<tempi; i++) {
			if (isdigit(na[i])!=0) {
				gotoxy(x, y);
				printf("�ѱ� �Ǵ� �������� �Է����ֽñ� �ٶ��ϴ�.                 ");
				tempj++;
				break;
			}
		}
		for (i=0; i<tempi; i++) {
			if (isspace(na[i])!=0) {
				gotoxy(x, y);
				printf("�Է³��� ���̿� ������ ���� �Է����ֽñ� �ٶ��ϴ�.       ");
				tempj++;
				break;
			}
		}
		if (tempj==0) {
			gotoxy(30, 14);
			printf("%s", na);
			break;
		}
	}
}
	
void password()
{
    int i, x, y;
	gotoxy(10, 31);
	printf("                                                          ");
	gotoxy(10, 31);
    printf("��й�ȣ �Է�>> ");
	while(1) {
		x=10;
		y=29;
		gotoxy(x, y);
		printf("                                                          ");

		gotoxy(x, y);
		fflush(stdin);
		for (i=0; (pa[i]=getch())!='\r'; i++) printf("*");
		pa[i] = '\0';

		tempi = strlen(pa);
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
			if (isdigit(pa[i])==0) {
				gotoxy(x, y);
				printf("���ڷ� �Է����ֽñ� �ٶ��ϴ�.                             ");
				tempj++;
				break;
			}
		}
		for (i=0; i<tempi; i++) {
			if (isspace(pa[i])!=0) {
				gotoxy(x, y);
				printf("�Է³��� ���̿� ������ ���� �Է����ֽñ� �ٶ��ϴ�.       ");
				tempj++;
				break;
			}
		}
		if (tempj==0) {
			break;
		}
	}
}

int passcmp()
{
	for (j=1; j<=staff_cnt; j++) {
		if (strcmp(staff[j].name, na)==0) {
			if (staff[j].pass==atoi(pa)) {
				return 1;
			}
		}
	}
	return 0;
}

int login()
{
	int count=0;
	system("cls");
		login_scr();
	if (staff_cnt == 0) { 
		gotoxy(10, 31);
		printf("��ϵ� ������� �����ϴ�.                                ");
		Sleep(3000);
		staff_join();
	}
	while(1) {
		system("cls");
		login_scr();
		name();
		gotoxy(10, 29);
		printf("                                             ");
		password();
		if (!passcmp()) {
			gotoxy(10, 31);
			printf("��ġ���� �ʾҽ��ϴ�.                                     ");
			count ++;
			Sleep(1000);
			if (count == 3) {
				return 0;
			}
		} else {
			gotoxy(10, 31);
			printf("��ġ�Ͽ����ϴ�.                                          ");
			Sleep(1000);
			return 1;
		}
	}
}
