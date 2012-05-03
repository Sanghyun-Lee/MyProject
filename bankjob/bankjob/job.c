#include "mainheader.h"

void job_cus_ask(int n)
{
	int x=10, y=31;
	gotoxy(x, y);
	printf("�� ������ �½��ϱ�? (Y/N)                                 ");
	y=29;
	gotoxy(x, y);
	printf("                                                          ");
	while(1) {
		gotoxy(x, y);
		fflush(stdin);
		gets(tempchar);
		if (strcmp(tempchar, "Y")==0||strcmp(tempchar, "y")==0) {		
			y=31;
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
				for (j=0; j<tempi; j++) {
					if (isdigit(tempchar[j])==0) {
						gotoxy(x, y);
						printf("���ڷ� �Է����ֽñ� �ٶ��ϴ�.                             ");
						tempj++;
						break;
					}
				}
				for (j=0; j<tempi; j++) {
					if (isspace(tempchar[j])!=0) {
						gotoxy(x, y);
						printf("�Է³��� ���̿� ������ ���� �Է����ֽñ� �ٶ��ϴ�.       ");
						tempj++;
						break;
					}
				}
				if (tempj==0) {
					for (j=0; j<10; j++) {
						if (account[customer[n].acc[j]].number==atoi(tempchar)) {
							job_acc_view(n, j);
							if (strcmp(account[customer[n].acc[j]].type, "����ݰ���")==0) job_menu_sel1(n, j);  //����ħ
							else if (strcmp(account[customer[n].acc[j]].type, "�������")==0) job_menu_sel2(n, j);
							else if (strcmp(account[customer[n].acc[j]].type, "���ݰ���")==0) job_menu_sel3(n, j);
							return;
						}
					}
					y=31;
					gotoxy(x, y);
					printf("�ش� ���°� �����ϴ�.                                    ");
					Sleep(1000);
					return;
				}
			}
		}
		else if (strcmp(tempchar, "N")==0||strcmp(tempchar, "n")==0) {
			y=31;
			gotoxy(x, y);
			printf("��ҵǾ����ϴ�.                                           ");
			Sleep(1000);
			return;
		}
		else continue;
	}
}

void job_acc_view(int n, int k)
{
	int x=23, y=6;
	job_menu_scr();
	gotoxy(x, y);
	printf("%d", account[customer[n].acc[k]].number);  //q��ȣ
	y=7;
	gotoxy(x, y);
	printf("%s", account[customer[n].acc[k]].type); //����
	y=8;
	gotoxy(x, y);
	printf("****"); //���
	y=9;
	gotoxy(x, y);
	printf("%s", customer[n].name); //������
	y=10;
	gotoxy(x, y);
	printf("0%.0f", customer[n].phone);  //����ó
	return;
}

void job_menu_sel1(int n, int k)
{
	int x=7, y=13, ch;
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
				if (y==23) y-=6;
				else if (y >13) y-=2;
				break;
			case DOWN:
				if (y==17) y+=6;
				else if (y <25) y+=2;
				break;
			}
		} else {
			if (ch == ENTER) {
				y=wherey();
				if (y==13) {
					in_money(n, k); //����
				} else if (y==15) {
					out_money(n, k);
				}
				else if (y==17) {
					transfer(n, k);
				}
				else if (y==23) {
					trade_view(n, k);
				}
				else if (y==25) {
					money_view(n, k); //����
				}
			} else if (ch == ESC) exit(1);
		}
	} while (ch != ENTER && ch != ESC);
}

/*void job_menu_sel2(int n, int k)
{
	int x=7, y=19, ch;
	do {
		if (ch != ESC && ch != 77) { 
			gotoxy(x, y);
			printf("��");
			ch = getch();
			gotoxy(x, y);
			printf(" ");
		}
		if (ch == ENTER) {
		} 
		else if (ch == ESC) exit(1);
	} while (ch != ENTER && ch != ESC);
}*/

void job_menu_sel3(int n, int k)
{
	int x=7, y=21, ch;
	do {
		if (ch != ESC && ch != 77) { 
			gotoxy(x, y);
			printf("��");
			ch = getch();
			gotoxy(x, y);
			printf(" ");
		}
		if (ch == ENTER) {
		} 
		else if (ch == ESC) exit(1);
	} while (ch != ENTER && ch != ESC);
}

void money_view(int n, int k)
{
	int x=10, y=31;
	money_view_scr();
	gotoxy(x, y);
	printf("������ ��й�ȣ�� �Է��Ͻÿ�.                             ");  //������ n, k ����
	y=29;
	gotoxy(x, y);
	printf("                                                          ");
	gotoxy(x, y);
	fflush(stdin);
	strcpy(tempchar, "");
	for (j=0; (tempchar[j]=getch())!='\r'; j++) printf("*");
	tempchar[j] = '\0';
	if (atoi(tempchar)==account[customer[n].acc[k]].password) {
		x=23;
		y=8;
		gotoxy(x, y);
		printf("%.0f", account[customer[n].acc[k]].money);  //���⵵ n, k ����
		job_return();
	}
	else {
		y=31;
		gotoxy(x, y);
		printf("��й�ȣ�� Ʋ���ϴ�.                                      ");
		Sleep(1000);
	}
}

void job_return()
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

void in_money(int n, int k)
{
	int x=10, y=31;

	time_t ttime;
	struct tm *today;
	time(&ttime);
	today = localtime(&ttime);

	in_money_scr();
	gotoxy(x, y);
	printf("�Ա��Ͻ� �ݾ��� �Է��Ͻÿ�.                               ");
	
	while(1) {
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
			printf("�ݾ��� �Է����ֽñ� �ٶ��ϴ�.                             ");
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
			if (isspace(tempchar[j])!=0) {
				gotoxy(x, y);
				printf("�Է³��� ���̿� ������ ���� �Է����ֽñ� �ٶ��ϴ�.       ");
				tempj++;
				break;
			}
		}
		if (tempj==0) {
			x=23;
			y=8;
			gotoxy(x, y);
			printf("%s", tempchar);

			x=10;
			y=31;
			gotoxy(x, y);
			printf("�� ������ �½��ϱ�? (Y/N)                                 ");
			y=29;
			gotoxy(x, y);
			printf("                                                          ");
			while(1) {
				gotoxy(x, y);
				fflush(stdin);
				gets(tempchar2);
				if (strcmp(tempchar2, "Y")==0||strcmp(tempchar2, "y")==0) {
					x=10;
					y=31;
					gotoxy(x, y);
					printf("�ԱݵǾ����ϴ�.                                         "); // ���� customer[n].acc[k] ����
					account[customer[n].acc[k]].money = account[customer[n].acc[k]].money + atoi(tempchar);
					trade[trade_cnt].money = atoi(tempchar);
					trade[trade_cnt].number = customer[n].acc[k];
					strcpy(trade[trade_cnt].type, "�Ա�");
					trade[trade_cnt].day.year = today->tm_year+1900;
					trade[trade_cnt].day.month = today->tm_mon+1;
					trade[trade_cnt].day.day = today->tm_mday;
					trade_cnt++;
					save_trade();
					save_account();
					Sleep(1000);
					break;
				}
				else if (strcmp(tempchar2, "N")==0||strcmp(tempchar2, "n")==0) {
					x=10;
					y=31;
					gotoxy(x, y);
					printf("��ҵǾ����ϴ�.                                           ");
					Sleep(1000);
					break;
				}
				else continue;
			}
			break;
		}
	}
}

void out_money(int n, int k)
{
	int x=10, y=31;

	time_t ttime;
	struct tm *today;
	time(&ttime);
	today = localtime(&ttime);

	out_money_scr();
	gotoxy(x, y);
	printf("������ ��й�ȣ�� �Է��Ͻÿ�.                             "); 
	
	while(1) {
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
			if (atoi(tempchar)==account[customer[n].acc[k]].password) {
				x=10, y=31;
				gotoxy(x, y);
				printf("����Ͻ� �ݾ��� �Է��Ͻÿ�.                               ");
			
				while(1) {
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
						printf("�ݾ��� �Է����ֽñ� �ٶ��ϴ�.                             ");
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
						if (isspace(tempchar[j])!=0) {
							gotoxy(x, y);
							printf("�Է³��� ���̿� ������ ���� �Է����ֽñ� �ٶ��ϴ�.       ");
							tempj++;
							break;
						}
					}
					if (tempj==0) {
						x=23;
						y=8;
						gotoxy(x, y);
						printf("%s", tempchar);

						x=10;
						y=31;
						gotoxy(x, y);
						printf("�� ������ �½��ϱ�? (Y/N)                                 ");
						y=29;
						gotoxy(x, y);
						printf("                                                          ");
						while(1) {
							gotoxy(x, y);
							fflush(stdin);
							gets(tempchar2);
							if (strcmp(tempchar2, "Y")==0||strcmp(tempchar2, "y")==0) {
								if (account[customer[n].acc[k]].money >= atoi(tempchar)) {
									x=10;
									y=31;
									gotoxy(x, y);
									printf("��ݵǾ����ϴ�.                                         "); // ���� customer[n].acc[k] ����
									account[customer[n].acc[k]].money = account[customer[n].acc[k]].money - atoi(tempchar);
									trade[trade_cnt].money = -atoi(tempchar);
									trade[trade_cnt].number = customer[n].acc[k];
									strcpy(trade[trade_cnt].type, "���");
									trade[trade_cnt].day.year = today->tm_year+1900;
									trade[trade_cnt].day.month = today->tm_mon+1;
									trade[trade_cnt].day.day = today->tm_mday;
									trade_cnt++;
									save_trade();
									save_account();
									Sleep(1000);
									return;
								}
								else if (account[customer[n].acc[k]].money < atoi(tempchar)) {
									x=10;
									y=31;
									gotoxy(x, y);
									printf("�ܾ��� �����մϴ�.                                      ");
									Sleep(1000);
									return;
								}
							}
							else if (strcmp(tempchar2, "N")==0||strcmp(tempchar2, "n")==0) {
								x=10;
								y=31;
								gotoxy(x, y);
								printf("��ҵǾ����ϴ�.                                           ");
								Sleep(1000);
								return;
							}
							else continue;
						}
						break;
					}
				}
			}
			else {
				y=31;
				gotoxy(x, y);
				printf("��й�ȣ�� Ʋ���ϴ�.                                      ");
				Sleep(1000);
				return;
			}
		}
		else continue;
	}
}

void transfer(int n, int k)
{
	int x=10, y=31, q;
	char tempchar3[5], tempchar4[2];
	
	time_t ttime;
	struct tm *today;
	time(&ttime);
	today = localtime(&ttime);

	transfer_scr();
	gotoxy(x, y);
	printf("��ü�Ͻ� ���¹�ȣ�� �Է��ϼ���.                           ");
	y=29;
	gotoxy(x, y);
	printf("                                                          ");
	while(1) {
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
		for (j=0; j<tempi; j++) {
			if (isdigit(tempchar[j])==0) {
				gotoxy(x, y);
				printf("���ڷ� �Է����ֽñ� �ٶ��ϴ�.                             ");
				tempj++;
				break;
			}
		}
		for (j=0; j<tempi; j++) {
			if (isspace(tempchar[j])!=0) {
				gotoxy(x, y);
				printf("�Է³��� ���̿� ������ ���� �Է����ֽñ� �ٶ��ϴ�.       ");
				tempj++;
				break;
			}
		}
		if (tempj==0) {
			for (i=0; i<=account_cnt; i++) {
				if (account[i].number==atoi(tempchar)) {
					q=i;
					x=23;
					y=8;
					gotoxy(x, y);
					printf("%s", tempchar);
					y=10;
					gotoxy(x, y);
					for (j=0; j<=customer_cnt; j++) {
						for (tempi=0; tempi<10; tempi++) {
							if (customer[j].acc[tempi]==(atoi(tempchar)-1841100000)) {
								printf("%s\n", customer[j].name);
								tempj=999;
								break;
							}
						}
						if (tempj==999) break;
					}
					x=10;
					y=31;
					gotoxy(x, y);
					printf("��ü�Ͻ� �ݾ��� �Է��ϼ���.                               ");

					while(1) {
						y=29;
						gotoxy(x, y);
						printf("                                                          ");
									
						gotoxy(x, y);
						fflush(stdin);
						gets(tempchar2);
						tempi = strlen(tempchar2);
						tempj = 0;
						y=31;
											
						if (tempi==0) {
							gotoxy(x, y);
							printf("�ݾ��� �Է����ֽñ� �ٶ��ϴ�.                             ");
							continue;
						}
						for (j=0; j<tempi; j++) {
							if (isdigit(tempchar2[j])==0) {
								gotoxy(x, y);
								printf("���ڷ� �Է����ֽñ� �ٶ��ϴ�.                             ");
								tempj++;
								break;
							}
						}
						for (j=0; j<tempi; j++) {
							if (isspace(tempchar2[j])!=0) {
								gotoxy(x, y);
								printf("�Է³��� ���̿� ������ ���� �Է����ֽñ� �ٶ��ϴ�.       ");
								tempj++;
								break;
							}
						}
						if (tempj==0) {
							if (account[customer[n].acc[k]].money>=atoi(tempchar2)) {
								x=23;
								y=12;
								gotoxy(x, y);
								printf("%s", tempchar2);
								
								x=10;
								y=31;
								gotoxy(x, y);
								printf("������ ��й�ȣ�� �Է��Ͻÿ�.                             "); 
								y=29;
								gotoxy(x, y);
								printf("                                                          ");
								gotoxy(x, y);
								fflush(stdin);
								strcpy(tempchar3, "");
								for (j=0; (tempchar3[j]=getch())!='\r'; j++) printf("*");
								tempchar3[j] = '\0';
								if (atoi(tempchar3)==account[customer[n].acc[k]].password) {
									x=10;
									y=31;
									gotoxy(x, y);
									printf("�� ������ �½��ϱ�? (Y/N)                                 ");
									y=29;
									gotoxy(x, y);
									printf("                                                          ");
									while(1) {
										gotoxy(x, y);
										fflush(stdin);
										gets(tempchar4);
										if (strcmp(tempchar4, "Y")==0||strcmp(tempchar4, "y")==0) {
											x=10;
											y=31;
											gotoxy(x, y);
											printf("��ü �Ǿ����ϴ�.                                        "); 
												account[customer[n].acc[k]].money = account[customer[n].acc[k]].money - atoi(tempchar2);
												account[q].money = account[q].money + atoi(tempchar2);
												trade[trade_cnt].money = -atoi(tempchar2);
												trade[trade_cnt].number = customer[n].acc[k];
												strcpy(trade[trade_cnt].type, "������ü(����)");
												trade[trade_cnt].day.year = today->tm_year+1900;
												trade[trade_cnt].day.month = today->tm_mon+1;
												trade[trade_cnt].day.day = today->tm_mday;
												trade_cnt++;
												trade[trade_cnt].money = atoi(tempchar2);
												trade[trade_cnt].number = q;
												strcpy(trade[trade_cnt].type, "������ü(����)");
												trade[trade_cnt].day.year = today->tm_year+1900;
												trade[trade_cnt].day.month = today->tm_mon+1;
												trade[trade_cnt].day.day = today->tm_mday;
												trade_cnt++;
												save_trade();
												save_account();
												Sleep(1000);
												return;
										}
										else if (strcmp(tempchar4, "N")==0||strcmp(tempchar4, "n")==0) {
											x=10;
											y=31;
											gotoxy(x, y);
											printf("��ҵǾ����ϴ�.                                           ");
											Sleep(1000);
											return;
										}
										else continue;
									}
									break;
								}
							}
							else if (account[customer[n].acc[k]].money<atoi(tempchar2)) {
								x=10;
								y=31;
								gotoxy(x, y);
								printf("�ܾ��� �����մϴ�.                                      ");
								Sleep(1000);
								return;
							}
						}
					}
				}
			}
		}
		y=31;
		gotoxy(x, y);
		printf("�ش� ���°� �����ϴ�.                                    ");
		Sleep(1000);
		return;
	}
}

void trade_view(n, k)
{
	int x=7, y=8, ch;
	trade_view_ask_scr();
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
				if (y <16) y+=2;
				break;
			}
		} else {
			if (ch == ENTER) {
				y=wherey();
				if (y==8) {
					trade_view_scr();
					y=8;
					gotoxy(x, y);
					for (i=0; i<trade_cnt; i++) {
						if (trade[i].number==customer[n].acc[k]&&dayminus(i)<=7) {
							printf("%d�� %d�� %d��    %s    %.0f\n", trade[i].day.year, trade[i].day.month, trade[i].day.day, trade[i].type, trade[i].money);
							y++;
							gotoxy(x, y);
						}
					}
					job_return();
				} else if (y==10) {
					trade_view_scr();
					y=8;
					gotoxy(x, y);
					for (i=0; i<trade_cnt; i++) {
						if (trade[i].number==customer[n].acc[k]&&dayminus(i)<=14) {
							printf("%d�� %d�� %d��    %s    %.0f\n", trade[i].day.year, trade[i].day.month, trade[i].day.day, trade[i].type, trade[i].money);
							y++;
							gotoxy(x, y);
						}
					}
					job_return();
				}
				else if (y==12) {
					trade_view_scr();
					y=8;
					gotoxy(x, y);
					for (i=0; i<trade_cnt; i++) {
						if (trade[i].number==customer[n].acc[k]&&dayminus(i)<=30) {
							printf("%d�� %d�� %d��    %s    %.0f\n", trade[i].day.year, trade[i].day.month, trade[i].day.day, trade[i].type, trade[i].money);
							y++;
							gotoxy(x, y);
						}
					}
					job_return();				}
				else if (y==14) {
					trade_view_scr();
					y=8;
					gotoxy(x, y);
					for (i=0; i<trade_cnt; i++) {
						if (trade[i].number==customer[n].acc[k]&&dayminus(i)<=90) {
							printf("%d�� %d�� %d��    %s    %.0f\n", trade[i].day.year, trade[i].day.month, trade[i].day.day, trade[i].type, trade[i].money);
							y++;
							gotoxy(x, y);
						}
					}
					job_return();				}
				else if (y==16) {
					trade_view_scr();
					y=8;
					gotoxy(x, y);
					for (i=0; i<trade_cnt; i++) {
						if (trade[i].number==customer[n].acc[k]&&dayminus(i)<=365) {
							printf("%d�� %d�� %d��    %s    %.0f\n", trade[i].day.year, trade[i].day.month, trade[i].day.day, trade[i].type, trade[i].money);
							y++;
							gotoxy(x, y);
						}
					}
					job_return();				}
			} else if (ch == ESC) exit(1);
		}
	} while (ch != ENTER && ch != ESC);
}



void installment_sel(int n, int k)
{
	int x;
	int y;
	int ch;
	installment_sel_scr();
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
				if (y <16) y+=2;
				break;
			}
		} else {
			if (ch == ENTER) {
				y=wherey();
				if ( y==8 ) {
					system("cls");
					creat_installment(n, k);	// ���� ����
					return ;
				} else if (y==10) {
					system("cls");
					input_installment(n, k);	// ���ݾ� �Ա�
					return ;
				} else if (y==12) {
					system("cls");
					// ���� ���� 
					installment_view(n, k);
				}  else if (y==14) {
					system("cls");
					cancelation_installment(n, k);
						// �����޴�  
				} else if (y == 16) {
					system("cls");
				}
			} else if (ch == ESC) exit(1);
		}
	} while (ch != ENTER && ch != ESC);
}
///////////////////////////////////////////////////////////

void creat_installment(int n, int k)  // ���� ������ ������ ��� ���� ���� ���� ��� .....��
{
	time_t ttime;
	struct tm *today;
	time(&ttime);
	today = localtime(&ttime);
	
	base_scr();
	gotoxy(3, 4);
	printf("���� ����");
	
	gotoxy(10, 8);
	printf("���� �ݾ� -> ");

	gotoxy(10, 10);
	printf("���� �Ⱓ -> ");

	gotoxy(10, 31);
	printf("�����Ͻ� �ݾ��� �Է��Ͻÿ�.                               ");
	gotoxy(24, 8);
	while (1) {
		fflush(stdin);
		gotoxy(10, 29);
		gets(account[customer[n].acc[k]].installment.cost);
		tempi = strlen(account[customer[n].acc[k]].installment.cost);
		tempj = 0;
		
		if (tempi==0) {
			gotoxy(10, 31);
			printf("�ݾ��� �Է����ֽñ� �ٶ��ϴ�.                             ");
			continue;
		}
		for (j=0; j<tempi; j++) {
			if (isdigit(account[customer[n].acc[k]].installment.cost[j])==0) {
				gotoxy(10, 31);
				printf("���ڷ� �Է����ֽñ� �ٶ��ϴ�.                             ");
				tempj++;
				break;
			}
		}
		for (j=0; j<tempi; j++) {
			if (isspace(account[customer[n].acc[k]].installment.cost[j])!=0) {
				gotoxy(10, 31);
				printf("�Է³��� ���̿� ������ ���� �Է����ֽñ� �ٶ��ϴ�.       ");
				tempj++;
				break;
			}
		}
		if (tempj==0) {
			gotoxy(24 , 8);
			printf("%s", account[customer[n].acc[k]].installment.cost);
			break;
		} 
	}
	gotoxy(10, 29);
	printf("                                                     ");
	gotoxy(10, 31);
	printf("���� �Ⱓ(����)�� �Է��Ͻÿ�.                               ");
	while (1) {
		fflush(stdin);
		gotoxy(10, 29);
		gets(account[customer[n].acc[k]].installment.during_month);
		tempi = strlen(account[customer[n].acc[k]].installment.during_month);
		tempk = 0;
		if (tempi==0) {
			gotoxy(10, 31);
			printf("�ݾ��� �Է����ֽñ� �ٶ��ϴ�.                             ");
			continue;
		}
		for (j=0; j<tempi; j++) {
			if (isdigit(account[customer[n].acc[k]].installment.during_month[j])==0) {
				gotoxy(10, 31);
				printf("���ڷ� �Է����ֽñ� �ٶ��ϴ�.                             ");
				tempk++;
				break;
			}
		}
		for (j=0; j<tempi; j++) {
			if (isspace(account[customer[n].acc[k]].installment.during_month[j])!=0) {
				gotoxy(10, 31);
				printf("�Է³��� ���̿� ������ ���� �Է����ֽñ� �ٶ��ϴ�.       ");
				tempk++;
				break;
			}
		}
		if (tempk==0) {
			gotoxy(24 , 10);
			printf("%s", account[customer[n].acc[k]].installment.during_month);
			break;
		}
	}
	if (tempj==0 && tempk==0) {
		gotoxy(10 ,31);
		printf("�� ������ �½��ϱ�? (Y/N)                                 ");
		gotoxy(10, 29);
		printf("                                                          ");
		while(1) {
			gotoxy(10, 29);
			fflush(stdin);
			gets(tempchar2);
			if (strcmp(tempchar2, "Y")==0||strcmp(tempchar2, "y")==0) {
				gotoxy(10, 31);
				printf("������ �����Ǿ����ϴ�.                                  "); // ���� customer[n].acc[k] ����
		
				strcpy(trade[trade_cnt].type, "���ݰ���");

				trade[trade_cnt].day.year = today->tm_year+1900;
				trade[trade_cnt].day.month = today->tm_mon+1;
				printf("%d", trade[trade_cnt].day.month);
				trade[trade_cnt].day.day = today->tm_mday;
				trade_cnt++;
				save_trade();
				save_account();
				Sleep(1000);
				break;
			}
			else if (strcmp(tempchar2, "N")==0||strcmp(tempchar2, "n")==0) {
				gotoxy(10, 31);
				printf("��ҵǾ����ϴ�.                                           ");
				Sleep(1000);
				break;
			}
			else continue;
		}
	}
}

void input_installment(int n, int k)
{
	time_t ttime;
	struct tm *today;
	time(&ttime);
	today = localtime(&ttime);
	
	base_scr();
	gotoxy(3, 4);
	printf("���ݾ� �Է�");
	/////��¥ �Ѵ޵��ΰɷ� ���ߵ� ...��// ������ ���翡�� ó���� ���� ������ 12�� ���ؼ� �� ...
	gotoxy(3, 6);
	printf("%d", trade[trade_cnt].day.month);
	if (((today->tm_mon+1) - (trade[trade_cnt].day.month)) > 2 ) {
		cancelation_installment(n, k);
		return ;
	}
	gotoxy(3, 6);
	printf("%d ",(today->tm_mon+1));
	printf("%d ",trade[trade_cnt].day.month);// ��� ���� �ȵ�
	printf("%d ",((today->tm_mon+1) - (trade[trade_cnt].day.month)) );
	if (((today->tm_mon+1) - (trade[trade_cnt].day.month)) < 0) {
		if (((today->tm_mon+13) - (trade[trade_cnt].day.month)) >2 ) {
			cancelation_installment(n, k);
			return ;
		} else {
			in_money_scr();
			gotoxy(10, 31);
			printf("�Ա��Ͻ� ���� �ݾ��� %s �Դϴ�. �Ա��Ͻðڽ��ϱ�? (y/n)  ", account[customer[n].acc[k]].installment.cost);
			gotoxy(10, 29);
			printf("                                                          ");
			while(1) {
				fflush(stdin);
				gets(tempchar2);
				if (strcmp(tempchar2, "Y")==0||strcmp(tempchar2, "y")==0) {
					gotoxy(10, 31);
					printf("�ԱݵǾ����ϴ�.                                         "); // ���� customer[n].acc[k] ����
					account[customer[n].acc[k]].installment.num++;
					account[customer[n].acc[k]].money = account[customer[n].acc[k]].money + atoi(account[customer[n].acc[k]].installment.cost);
					trade[trade_cnt].money = atoi(account[customer[n].acc[k]].installment.cost);
					trade[trade_cnt].number = customer[n].acc[k];
					strcpy(trade[trade_cnt].type, "�Ա�");
					////////////////////////////////////////////////////
					trade[trade_cnt].day.year = today->tm_year+1900;
					trade[trade_cnt].day.month = today->tm_mon+1;
					trade[trade_cnt].day.day = today->tm_mday;
					/////////////////////////////////////////////////
					trade_cnt++;
					save_trade();
					save_account();
					Sleep(1000);
					break;
				} else if (strcmp(tempchar2, "N")==0||strcmp(tempchar2, "n")==0) {
					gotoxy(10, 31);
					printf("��ҵǾ����ϴ�.                                           ");
					Sleep(1000);
					break;
				} else continue;
			}
		}
	}
}

void installment_view(int n, int k)
{
	
	base_scr();
	gotoxy(3, 4);
	printf("���� ��ȸ");


	gotoxy(10, 31);
	printf("������ ��й�ȣ�� �Է��Ͻÿ�.                             ");  //������ n, k ����
	gotoxy(10, 29);
	printf("                                                          ");
	gotoxy(10, 29);
	fflush(stdin);
	strcpy(tempchar, "");
	for (j=0; (tempchar[j]=getch())!='\r'; j++) printf("*");
	tempchar[j] = '\0';
	if (atoi(tempchar)==account[customer[n].acc[k]].password) {
		gotoxy(23, 8);
		printf("%d", account[customer[n].acc[k]].money);  //���⵵ n, k ����
		gotoxy(23, 10);
		printf("%d�� %d�� %d��\n", account[customer[n].acc[k]].term.year, account[customer[n].acc[k]].term.month, account[customer[n].acc[k]].term.day);
		job_return();
	}
	else {
		gotoxy(10 ,31);
		printf("��й�ȣ�� Ʋ���ϴ�.                                      ");
		Sleep(1000);
	}
}

void cancelation_installment(int n, int k)
{
	base_scr();

	gotoxy(7, 10);
	printf("%s ���� ������ �ؾ� �Ǿ����ϴ�.", customer[n].name);
	gotoxy(7, 12);
	printf("�ؾ� �� ��ȯ �ݾ��� %d �Դϴ�.", atoi(account[customer[n].acc[k]].installment.cost)*(account[customer[n].acc[k]].installment.num) );
}
	
void job_menu_sel2(int n, int k)
{
	int x=7, y=19, ch;
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
				if (y==23) y-=4;
				else if (y >19) y-=2;
				break;
			case DOWN:
				if (y==19) y+=4;
				else if (y <25) y+=2;
				break;
			}
		} else {
			if (ch == ENTER) {
				y=wherey();
				if (y==19) {
					lend_menu_sel(n, k);
				}
				else if (y==23) {
					trade_view(n, k);
				}
				else if (y==25) {
					money_view(n, k); 
				}
			} else if (ch == ESC) exit(1);
		} 
		if (ch == ESC) exit(1);
	} while (ch != ENTER && ch != ESC);
}

void lend_menu_sel(int n, int k)
{
	int x=7, y=8, ch;
	lend_menu_scr();
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
					lend(n, k);
				} else if (y==10) {
					lend_repay(n, k);
				} else if (y==12) {
					lend_view(n, k);
				}					
			} else if (ch == ESC) exit(1);
		}
	} while (ch != ENTER && ch != ESC);
}

void lend_view(int n, int k)
{
	int x=10, y=31;
	lend_view_scr();
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
		x=23;
		y=8;
		gotoxy(x, y);
		printf("%d", account[customer[n].acc[k]].money); 
		y=10;
		gotoxy(x, y);
		load_account();
		printf("%d�� %d������\n", account[customer[n].acc[k]].term.year, account[customer[n].acc[k]].term.month);
		job_return();
	}
	else {
		y=31;
		gotoxy(x, y);
		printf("��й�ȣ�� Ʋ���ϴ�.                                      ");
		Sleep(1000);
		
	}
}

void lend(int n, int k)
{
	int x=10, y=31, lend_max;
	
	time_t ttime;
	struct tm *today;
	time(&ttime);
	today = localtime(&ttime);
	
	lend_scr();
	gotoxy(x, y);
	load_account();
	
	if(account[customer[n].acc[k]].term.year!=0&&
		(account[customer[n].acc[k]].term.year < today->tm_year+1900 ||
		(account[customer[n].acc[k]].term.year == today->tm_year+1900 &&
		account[customer[n].acc[k]].term.month < today->tm_mon+1)))
		strcpy(customer[n].credit, "�ſ�ҷ�");		
	
	if (strcmp(customer[n].credit, "�ſ�ҷ�")==0){
		y=31;
		gotoxy(x, y);		
		printf("%s�� ������ �� �� �����ϴ�.", customer[n].credit);
		Sleep(2000);
	}
	else if(account[customer[n].acc[k]].money!=0){
		y=31;
		gotoxy(x, y);
		printf("�̹� ������ �ϼ̽��ϴ�.                ");
		Sleep(3000);
		lend_menu_sel(n, k);
	}
	
	if (strcmp(customer[n].credit, "��")==0)
		lend_max=loan.loan_l;
	else if (strcmp(customer[n].credit, "��")==0)
		lend_max=loan.loan_m;
	else if (strcmp(customer[n].credit, "��")==0)
		lend_max=loan.loan_h;
	
	
	printf("�����Ͻ� �ݾ��� �Է��Ͻÿ�.                     ");
	
	while(1) {
		y=29;
		gotoxy(x, y);
		
		
		fflush(stdin);
		gets(tempchar);
		tempi = strlen(tempchar);
		tempj = 0;
		y=31;
		
		if (tempi==0) {
			gotoxy(x, y);
			printf("�ݾ��� �Է����ֽñ� �ٶ��ϴ�.          ");
			continue;
		}
		if(lend_max<atoi(tempchar)) {
			gotoxy(x, y);
			printf("�ſ��� %s�� %d���� ������ �����մϴ�.        ", customer[n].credit, lend_max);
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
			if (isspace(tempchar[j])!=0) {
				gotoxy(x, y);
				printf("�Է³��� ���̿� ������ ���� �Է����ֽñ� �ٶ��ϴ�.       ");
				tempj++;
				break;
			}
		}
		if (tempj==0) 
			break;
	}
	
	x=23;
	y=8;
	gotoxy(x, y);
	printf("%s", tempchar);
	
	x=10;
	y=31;
	gotoxy(x, y);
	printf("���� �Ⱓ�� �Է��Ͻÿ�.(����:��)                  ");
	while(1) {
		y=29;
		gotoxy(x, y);
		printf("                                                          ");
		
		gotoxy(x, y);
		fflush(stdin);
		gets(tempchar3);
		tempi = strlen(tempchar3);
		tempj = 0;
		y=31;
		
		if (tempi==0) {
			gotoxy(x, y);
			printf("���� �Ⱓ�� �Է����ֽñ� �ٶ��ϴ�.                           ");
			continue;
		}
		if (tempi>3||tempi<1) {
			gotoxy(x, y);
			printf("1~3�� ���̷� �Է����ֽñ� �ٶ��ϴ�.                      ");
			continue;
		}
		if (atoi(tempchar3)>120) {
			gotoxy(x, y);
			printf("1~120���� ���̷� �Է����ֽñ� �ٶ��ϴ�.                      ");
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
			if (isspace(tempchar[j])!=0) {
				gotoxy(x, y);
				printf("�Է³��� ���̿� ������ ���� �Է����ֽñ� �ٶ��ϴ�.       ");
				tempj++;
				break;
			}
		}
		if (tempj==0) 
			break;
	}
	x=23;
	y=10;
	gotoxy(x, y);
	printf("%s", tempchar3);
	
	if (tempj==0) {
		x=10;
		y=31;
		gotoxy(x, y);
		printf("�� ������ �½��ϱ�? (Y/N)                                 ");
		y=29;
		gotoxy(x, y);
		printf("                                                          ");
		while(1) {
			gotoxy(x, y);
			fflush(stdin);
			gets(tempchar2);
			if (strcmp(tempchar2, "Y")==0||strcmp(tempchar2, "y")==0) {
				x=10;
				y=31;
				gotoxy(x, y);
				printf("����Ǿ����ϴ�.                                         ");
				account[customer[n].acc[k]].money = account[customer[n].acc[k]].money - atoi(tempchar);//1��..0                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
				account[customer[n].acc[k]].term.year = today->tm_year+1900 + ((atoi(tempchar3)+today->tm_mon+1)/12);
				account[customer[n].acc[k]].term.month = (atoi(tempchar3)+today->tm_mon+1)%12;
				trade[trade_cnt].money = -atoi(tempchar);
				trade[trade_cnt].number = customer[n].acc[k];
				strcpy(trade[trade_cnt].type, "����");
				trade[trade_cnt].day.year = today->tm_year+1900;
				trade[trade_cnt].day.month = today->tm_mon+1;
				trade[trade_cnt].day.day = today->tm_mday;
				trade_cnt++;
				save_trade();
				save_account();
				Sleep(1000);
				break;
				
			}
			else if (strcmp(tempchar2, "N")==0||strcmp(tempchar2, "n")==0) {
				x=10;
				y=31;
				gotoxy(x, y);
				printf("��ҵǾ����ϴ�.                                           ");
				Sleep(1000);
				break;
			}
		}
	}
}

void lend_repay(int n, int k)
{
	int x=10, y=31;
	
	time_t ttime;
	struct tm *today;
	time(&ttime);
	today = localtime(&ttime);
	
	lend_repay_scr();
	gotoxy(x, y);
	
	if(account[customer[n].acc[k]].money==0)
	{
		printf("�����Ͻ� �ݾ��� �����ϴ�.                              ");
		Sleep(3000);
		lend_menu_sel(n, k);
	}
	
	printf("��й�ȣ�� �Է��Ͻÿ�.                        ");
	while(1) {
		strcpy(pa, "");
		for (i=0; (pa[i]=getch())!='\r'; i++) printf("*");
		pa[i] = '\0';
		tempi = strlen(pa);
		tempj = 0;
		
		if (tempi==0) {
			gotoxy(10, 31);
			printf("��й�ȣ�� �Է����ֽñ� �ٶ��ϴ�.                         ");
			continue;
		}
		if (tempi!=4) {
			gotoxy(10, 31);
			printf("4�ڷ� �Է����ֽñ� �ٶ��ϴ�.                              ");
			continue;
		}
		
		
		for (i=0; i<tempi; i++) {
			if (isdigit(tempchar[i])==0) {
				gotoxy(10, 31);
				printf("���ڷ� �Է����ֽñ� �ٶ��ϴ�.                             ");
				tempj++;
				break;
			}
		}
		for (i=0; i<tempi; i++) {
			if (tempchar[i]==32) {
				gotoxy(10, 31);
				printf("�Է³��� ���̿� ������ ���� �Է����ֽñ� �ٶ��ϴ�.       ");
				tempj++;
				break;
			}
		}
		
		break;
	}
	
	
	printf("��ȯ �ݾ��� �Է��Ͻÿ�.                               ");
	
	while(1) {
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
			printf("�ݾ��� �Է����ֽñ� �ٶ��ϴ�.                             ");
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
			if (isspace(tempchar[j])!=0) {
				gotoxy(x, y);
				printf("�Է³��� ���̿� ������ ���� �Է����ֽñ� �ٶ��ϴ�.       ");
				tempj++;
				break;
			}
		}
		
		
		if(account[customer[n].acc[k]].money+atoi(tempchar)<=0)
		{
			if (tempj==0) {
				x=23;
				y=8;
				gotoxy(x, y);
				printf("%s", tempchar);
				
				x=10;
				y=31;
				gotoxy(x, y);
				printf("�� ������ �½��ϱ�? (Y/N)                                 ");
				y=29;
				gotoxy(x, y);
				printf("                                                          ");
				while(1) {
					gotoxy(x, y);
					fflush(stdin);
					gets(tempchar2);
					if (strcmp(tempchar2, "Y")==0||strcmp(tempchar2, "y")==0) {
						x=10;
						y=31;
						gotoxy(x, y);
						printf("��ȯ�Ǿ����ϴ�.                                         "); // ���� customer[n].acc[k] ����
						account[customer[n].acc[k]].money = account[customer[n].acc[k]].money + atoi(tempchar);
						trade[trade_cnt].money = atoi(tempchar);
						trade[trade_cnt].number = customer[n].acc[k];
						strcpy(trade[trade_cnt].type, "��ȯ");
						trade[trade_cnt].day.year = today->tm_year+1900;
						trade[trade_cnt].day.month = today->tm_mon+1;
						trade[trade_cnt].day.day = today->tm_mday;
						trade_cnt++;
						save_trade();
						save_account();
						Sleep(1000);
						break;
					}
					else if (strcmp(tempchar2, "N")==0||strcmp(tempchar2, "n")==0) {
						x=10;
						y=31;
						gotoxy(x, y);
						printf("��ҵǾ����ϴ�.                                           ");
						Sleep(1000);
						continue;
					}
					else continue;
				}
				break;
			}
		}
		else
		{	
			x=10;
			y=31;
			gotoxy(x, y);
			printf("�Է��Ͻ� �ݾ��� �����Ͻ� �ݾ׺��� �����ϴ�.   ");
			continue;
		}
		break;		
	}
}