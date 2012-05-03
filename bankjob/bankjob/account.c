#include "mainheader.h"

void account_cus_ask(int n)
{
	int x=10, y=31;
	gotoxy(x, y);
	printf("�� ������ �½��ϱ�? (Y/N)                                 ");
	while(1) {
		y=29;
		gotoxy(x, y);
		printf("                                                          ");
		gotoxy(x, y);
		fflush(stdin);
		gets(tempchar);
		if (strcmp(tempchar, "Y")==0||strcmp(tempchar, "y")==0) {
			accountmenu_scr();
			accountmenu_sel(n); //10
			return;
		}
		else if (strcmp(tempchar, "N")==0||strcmp(tempchar, "n")==0) {
			y=31;
			gotoxy(x, y);
			printf("��ҵǾ����ϴ�.                                           ");
			Sleep(1000);
			return;
		}
		else {
			y=31;
			gotoxy(x, y);
			printf("Y / N�� �Է����ּ���.                                     ");
			continue;
		}
	}
}

void accountmenu_sel(int n)
{
	int x;
	int y;
	int ch;
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
				if (y <12) y+=2;
				break;
			}
		} else {
			if (ch == ENTER) {
				y=wherey();
				if ( y==8 ) {
					account_join(n); // 10
				} else if (y==10) {
					account_view_sel(n, 1);
					//account_return();
				} else if (y==12) {
					account_view_sel(n, 2);
					//account_ask();
				}
			} else if (ch == ESC) exit(1);
		}
	} while (ch != ENTER && ch != ESC);
}

void account_join(int n)
{
	int x=23, y=8;  
	account_cnt++;
	account_join_scr();
	account[account_cnt].number = 1841100000 + account_cnt;		// 18411 �� ���� ?
	gotoxy(x, y);
	printf("%d", account[account_cnt].number); // 10

	x=7;
	y=10;
	gotoxy(x, y);
	printf("��");
	while(1) {
		x=10;
		y=31;
		gotoxy(x, y);
		printf("1.����ݰ���, 2.���ݰ���, 3.�������                      ");
		y=29;
		gotoxy(x, y);
		printf("                                                          ");
		gotoxy(x, y);
		fflush(stdin);
		gets(tempchar);
		if (strlen(tempchar)==0) {
			x=10;
			y=31;
			gotoxy(x, y);
			printf("�ο��� ��ȣ�� �Է����ֽñ� �ٶ��ϴ�.                      ");
			Sleep(1000);
			continue;
		}
		switch(atoi(tempchar)) {
		case 1:
			strcpy(account[account_cnt].type, "����ݰ���");
			break;
		case 2:
			strcpy(account[account_cnt].type, "���ݰ���");
			break;
		case 3:
			strcpy(account[account_cnt].type, "�������");
			break;
		default:
			x=10;
			y=31;
			gotoxy(x, y);
			printf("�ο��� ��ȣ�� �Է����ֽñ� �ٶ��ϴ�.                      ");
			Sleep(1000);
			continue;
		}
		break;
	}

	y=31;
	gotoxy(x, y);
	printf("                                                          ");
	
	x=23;
	y=10;
	gotoxy(x, y);
	printf("%s", account[account_cnt].type);
	
	x=7;
	y=10;
	gotoxy(x, y);
	printf(" ");

	x=7;
	y=12;
	gotoxy(x, y);
	printf("��");

	while(1) {
		x=10;
		y=29;
		gotoxy(x, y);
		printf("                                                          ");

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
			printf("���� ��й�ȣ�� �Է����ֽñ� �ٶ��ϴ�.                    ");
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
		if (tempj==0) {
			account[account_cnt].password = atoi(tempchar);
			break;
		}
	}
	x=23;
	y=12;
	gotoxy(x, y);
	printf("****");

	x=7;
	y=12;
	gotoxy(x, y);
	printf(" ");

	for (i=0; i<10; i++) {
		if (customer[n].acc[i]==0) {
			customer[n].acc[i]=account_cnt;
			break;
		}
	}
	save_customer();
	save_account();
	x=10;
	y=31;
	gotoxy(x, y);
	printf("������ �Ϸ�Ǿ����ϴ�.                                    ");
	Sleep(1000);
	return ;
}

void account_view_sel(int n, int z)
{
	int x=10, y=31;
	gotoxy(x, y);
	printf("��ȸ�Ͻ� ���¹�ȣ�� �Է��ϼ���.                          ");

	while(1) {
		x=10;
		y=29;
		gotoxy(x, y);
		printf("                                                          ");
			
		gotoxy(x, y);
		fflush(stdin);
		gets(tempchar);
		tempi = strlen(tempchar);
		tempj = 0;
		y=31;
					
		if (tempi==0) {
			gotoxy(x, y);
			printf("���¹�ȣ�� �Է����ֽñ� �ٶ��ϴ�.                         ");
			continue;
		}
		if (tempi!=10) {
			gotoxy(x, y);
			printf("10�ڷ� �Է����ֽñ� �ٶ��ϴ�.                             ");
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
			if (isspace(tempchar[i])!=0) {
				gotoxy(x, y);
				printf("�Է³��� ���̿� ������ ���� �Է����ֽñ� �ٶ��ϴ�.       ");
				tempj++;
				break;
			}
		}
		if (tempj==0) {
			for (i=0; i<10; i++) {
				if (account[customer[n].acc[i]].number==atoi(tempchar)) {
					account_view(n, i, z);
					return;
				}
			}
			y=31;
			gotoxy(x, y);
			printf("�ش� ���°� �����ϴ�.                                    ");
			Sleep(1000);
		}
	}
}

void account_view(int n, int k, int z)
{
	int x=23, y=8;
	account_view_scr();
	gotoxy(x, y);
	printf("%d", account[customer[n].acc[k]].number);  //q��ȣ
	y=10;
	gotoxy(x, y);
	printf("%s", account[customer[n].acc[k]].type); //����
	y=12;
	gotoxy(x, y);
	printf("****"); //���
	y=14;
	gotoxy(x, y);
	printf("%s", customer[n].name); //������
	y=16;
	gotoxy(x, y);
	printf("0%.0f", customer[n].phone);  //����ó
	if (z==1) account_return();
	else if (z==2) account_ask(n, k);
	return;
}

void account_return()
{
	int x=10, y=31;
	gotoxy(x, y);
	printf("0.���θ޴�                              ");
	while(1) {
		y=29;
		gotoxy(x, y);
		printf("                                                          ");
		gotoxy(x, y);
		fflush(stdin);
		scanf("%d", &tempi);
		gotoxy(x, y);
		printf("                                                          ");
		switch(tempi) {
		case 0:
			return;
			break;
		default:
			continue;
		}
		break;
	}
}

void account_ask(int n, int k) 
{
	int x=10, y=31;
	gotoxy(x, y);
	printf("1.����, 2.����, 0.���θ޴�                              ");

	while(1) {
		y=29;
		gotoxy(x, y);
		printf("                                                          ");
		gotoxy(x, y);
		fflush(stdin);
		scanf("%d", &tempi);
		gotoxy(x, y);
		printf("                                                          ");
		switch(tempi) {
		case 1:
			account_edit(n, k);
			break;
		case 2:
			account_delete(n, k);
			break;
		case 0:
			return;
			break;
		default:
			continue;
		}
		break;
	}
}

void account_edit(int n, int k)
{
	int x=7, y=10;
	int ch;
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
				if (y >10) 
					y-=2;
				break;
			case DOWN:
				if (y <12) 
					y+=2;
				break;
			}
		} else {
			if (ch == ENTER) {
				y=wherey();
					if ( y==12 ) {
						x=10;
						y=31;
						gotoxy(x, y);
						printf("������ ��й�ȣ�� �Է��Ͻÿ�.                             ");
						y=29;
						gotoxy(x, y);
						printf("                                                          ");
						gotoxy(x, y);
						fflush(stdin);
						strcpy(tempchar, "");
						for (j=0; (tempchar[j]=getch())!='\r'; j++) printf("*");
						tempchar[j] = '\0';
						if (atoi(tempchar)==account[customer[n].acc[k]].password) {
							y=31;
							gotoxy(x, y);
							printf("���ο� ��й�ȣ�� �Է��Ͻÿ�.                             ");
							while(1) {
								if(tempi==999) return;
								y=29;
								gotoxy(x, y);
								printf("                                                          ");

								gotoxy(x, y);
								fflush(stdin);
								strcpy(tempchar, "");
								for (j=0; (tempchar[j]=getch())!='\r'; j++) printf("*");
								tempchar[j] = '\0';

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
								for (j=0; j<tempi; j++) {
									if (isdigit(tempchar[j])==0) {
										gotoxy(x, y);
										printf("���ڷ� �Է����ֽñ� �ٶ��ϴ�.                             ");			
										tempj++;
										break;
									}
								}
								for (j=0; j<tempi; j++) {
									if (tempchar[j]==32) {
										gotoxy(x, y);
										printf("�Է³��� ���̿� ������ ���� �Է����ֽñ� �ٶ��ϴ�.       ");
										tempj++;
										break;
									}
								}
								if (tempj==0) {
									y=31;
									gotoxy(x, y);
									printf("�ٽ��ѹ� ��й�ȣ�� �Է��Ͻÿ�.                           ");
									while(1) {
										y=29;
										gotoxy(x, y);
										printf("                                                          ");

										gotoxy(x, y);
										fflush(stdin);
										strcpy(tempchar2, "");
										for (i=0; (tempchar2[i]=getch())!='\r'; i++) printf("*");
										tempchar2[i] = '\0';

										tempi = strlen(tempchar2);
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
											if (isdigit(tempchar2[i])==0) {
												gotoxy(x, y);
												printf("���ڷ� �Է����ֽñ� �ٶ��ϴ�.                             ");			
												tempj++;
												break;
											}
										}
										for (i=0; i<tempi; i++) {
											if (isspace(tempchar2[i])!=0) {
												gotoxy(x, y);
												printf("�Է³��� ���̿� ������ ���� �Է����ֽñ� �ٶ��ϴ�.       ");
												tempj++;
												break;
											}
										}
										if (tempj==0) {
											if (strcmp(tempchar, tempchar2)==0) {
												account[customer[n].acc[k]].password = atoi(tempchar);
												save_account();
												y=31;
												gotoxy(x, y);
												printf("������ �Ϸ�Ǿ����ϴ�.                                    ");
												Sleep(1000);
												account_view(n, k, 2);
												tempi=999;
												break;
											}
											else {
												y=31;
												gotoxy(x, y);
												printf("��й�ȣ�� Ʋ�Ƚ��ϴ�.                                    ");
												Sleep(1000);
												account_view(n, k, 2);
												tempi=999;
												break;
											}
										}
									}
								}
							}
						}
						else {
							y=31;
							gotoxy(x, y);
							printf("��й�ȣ�� Ʋ���ϴ�.                                      ");
							Sleep(1000);
						}
					} else if (y==10) {
						x=10;
						y=31;
						gotoxy(x, y);
						printf("1.����ݰ���, 2.���ݰ���, 3.�������");

						while(1) {
							y=29;
							gotoxy(x, y);
							printf("                                                          ");
							gotoxy(x, y);
							fflush(stdin);
							scanf("%d", &tempi);
							
							switch(tempi) {
							case 1:
								strcpy(account[customer[n].acc[k]].type, "����ݰ���");
								break;
							case 2:
								strcpy(account[customer[n].acc[k]].type, "���ݰ���");
								break;
							case 3:
								strcpy(account[customer[n].acc[k]].type, "�������");
								break;
							default:
								continue;
							}
							break;
						}
						save_account();
						y=31;
						gotoxy(x, y);
						printf("������ �Ϸ�Ǿ����ϴ�.                                    ");
						Sleep(1000);
						account_view(n, k, 2);
						break;
					}
			} else if (ch == ESC) exit(1);		
		}
	} while (ch != ENTER && ch != ESC);
}

void account_delete(int n, int k)
{
	int x=10, y=31;
	if (account[customer[n].acc[k]].money!=0) {
			gotoxy(x, y);
			printf("������ �� �����ϴ�.                                       ");
			Sleep(2000);
			return;
	}
	gotoxy(x, y);
	printf("�����Ͻðڽ��ϱ�? (Y/N)                                   ");
	while(1) {
		y=29;
		gotoxy(x, y);
		printf("                                                          ");
		gotoxy(x, y);
		fflush(stdin);
		gets(tempchar);
		if (strcmp(tempchar, "Y")==0||strcmp(tempchar, "y")==0) {
			account[customer[n].acc[k]].number = 0;
			strcpy(account[customer[n].acc[k]].type, "");
			account[customer[n].acc[k]].password=0;
			customer[n].acc[k] = 0;
			save_account();
			save_customer();
			y=31;
			gotoxy(x, y);
			printf("������ �Ϸ�Ǿ����ϴ�.                                    ");
			Sleep(1000);
			return;
		}
		else if (strcmp(tempchar, "N")==0||strcmp(tempchar, "n")==0) {
			y=31;
			gotoxy(x, y);
			printf("������ ��ҵǾ����ϴ�.                                    ");
			Sleep(1000);
			return;
		}
		else {
			y=31;
			gotoxy(x, y);
			printf("Y / N�� �Է����ּ���.                                     ");
			continue;
		}
	}
}