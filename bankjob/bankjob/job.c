#include "mainheader.h"

void job_cus_ask(int n)
{
	int x=10, y=31;
	gotoxy(x, y);
	printf("위 사항이 맞습니까? (Y/N)                                 ");
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
			printf("조회하실 계좌번호를 입력하세요.                          ");

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
					printf("계좌번호를 입력해주시기 바랍니다.                         ");
					continue;
				}
				if (tempi!=10) {
					gotoxy(x, y);
					printf("10자로 입력해주시기 바랍니다.                             ");
					continue;
				}
				for (j=0; j<tempi; j++) {
					if (isdigit(tempchar[j])==0) {
						gotoxy(x, y);
						printf("숫자로 입력해주시기 바랍니다.                             ");
						tempj++;
						break;
					}
				}
				for (j=0; j<tempi; j++) {
					if (isspace(tempchar[j])!=0) {
						gotoxy(x, y);
						printf("입력내용 사이에 공백이 없이 입력해주시기 바랍니다.       ");
						tempj++;
						break;
					}
				}
				if (tempj==0) {
					for (j=0; j<10; j++) {
						if (account[customer[n].acc[j]].number==atoi(tempchar)) {
							job_acc_view(n, j);
							if (strcmp(account[customer[n].acc[j]].type, "입출금계좌")==0) job_menu_sel1(n, j);  //개고침
							else if (strcmp(account[customer[n].acc[j]].type, "대출계좌")==0) job_menu_sel2(n, j);
							else if (strcmp(account[customer[n].acc[j]].type, "적금계좌")==0) job_menu_sel3(n, j);
							return;
						}
					}
					y=31;
					gotoxy(x, y);
					printf("해당 계좌가 없습니다.                                    ");
					Sleep(1000);
					return;
				}
			}
		}
		else if (strcmp(tempchar, "N")==0||strcmp(tempchar, "n")==0) {
			y=31;
			gotoxy(x, y);
			printf("취소되었습니다.                                           ");
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
	printf("%d", account[customer[n].acc[k]].number);  //q번호
	y=7;
	gotoxy(x, y);
	printf("%s", account[customer[n].acc[k]].type); //종류
	y=8;
	gotoxy(x, y);
	printf("****"); //비번
	y=9;
	gotoxy(x, y);
	printf("%s", customer[n].name); //예금주
	y=10;
	gotoxy(x, y);
	printf("0%.0f", customer[n].phone);  //연락처
	return;
}

void job_menu_sel1(int n, int k)
{
	int x=7, y=13, ch;
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
					in_money(n, k); //정상
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
					money_view(n, k); //정상
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
			printf("▶");
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
			printf("▶");
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
	printf("계좌의 비밀번호를 입력하시오.                             ");  //여까지 n, k 정상
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
		printf("%.0f", account[customer[n].acc[k]].money);  //여기도 n, k 정상
		job_return();
	}
	else {
		y=31;
		gotoxy(x, y);
		printf("비밀번호가 틀립니다.                                      ");
		Sleep(1000);
	}
}

void job_return()
{
	int x=10, y=31;
	gotoxy(x, y);
	printf("0.메인메뉴                              ");
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
	printf("입금하실 금액을 입력하시오.                               ");
	
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
			printf("금액을 입력해주시기 바랍니다.                             ");
			continue;
		}
		for (j=0; j<tempi; j++) {
			if (isdigit(tempchar[j])==0) {
				gotoxy(x, y);
				printf("숫자로 입력해주시기 바랍니다.                             ");
				tempj++;
				break;
			}
		}
		for (j=0; j<tempi; j++) {
			if (isspace(tempchar[j])!=0) {
				gotoxy(x, y);
				printf("입력내용 사이에 공백이 없이 입력해주시기 바랍니다.       ");
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
			printf("위 사항이 맞습니까? (Y/N)                                 ");
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
					printf("입금되었습니다.                                         "); // 정상 customer[n].acc[k] 정상
					account[customer[n].acc[k]].money = account[customer[n].acc[k]].money + atoi(tempchar);
					trade[trade_cnt].money = atoi(tempchar);
					trade[trade_cnt].number = customer[n].acc[k];
					strcpy(trade[trade_cnt].type, "입금");
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
					printf("취소되었습니다.                                           ");
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
	printf("계좌의 비밀번호를 입력하시오.                             "); 
	
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
		if (tempj==0) {
			if (atoi(tempchar)==account[customer[n].acc[k]].password) {
				x=10, y=31;
				gotoxy(x, y);
				printf("출금하실 금액을 입력하시오.                               ");
			
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
						printf("금액을 입력해주시기 바랍니다.                             ");
						continue;
					}
					for (j=0; j<tempi; j++) {
						if (isdigit(tempchar[j])==0) {
							gotoxy(x, y);
							printf("숫자로 입력해주시기 바랍니다.                             ");
							tempj++;
							break;
						}
					}
					for (j=0; j<tempi; j++) {
						if (isspace(tempchar[j])!=0) {
							gotoxy(x, y);
							printf("입력내용 사이에 공백이 없이 입력해주시기 바랍니다.       ");
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
						printf("위 사항이 맞습니까? (Y/N)                                 ");
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
									printf("출금되었습니다.                                         "); // 정상 customer[n].acc[k] 정상
									account[customer[n].acc[k]].money = account[customer[n].acc[k]].money - atoi(tempchar);
									trade[trade_cnt].money = -atoi(tempchar);
									trade[trade_cnt].number = customer[n].acc[k];
									strcpy(trade[trade_cnt].type, "출금");
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
									printf("잔액이 부족합니다.                                      ");
									Sleep(1000);
									return;
								}
							}
							else if (strcmp(tempchar2, "N")==0||strcmp(tempchar2, "n")==0) {
								x=10;
								y=31;
								gotoxy(x, y);
								printf("취소되었습니다.                                           ");
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
				printf("비밀번호가 틀립니다.                                      ");
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
	printf("이체하실 계좌번호를 입력하세요.                           ");
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
			printf("계좌번호를 입력해주시기 바랍니다.                         ");
			continue;
		}
		if (tempi!=10) {
			gotoxy(x, y);
			printf("10자로 입력해주시기 바랍니다.                             ");
			continue;
		}
		for (j=0; j<tempi; j++) {
			if (isdigit(tempchar[j])==0) {
				gotoxy(x, y);
				printf("숫자로 입력해주시기 바랍니다.                             ");
				tempj++;
				break;
			}
		}
		for (j=0; j<tempi; j++) {
			if (isspace(tempchar[j])!=0) {
				gotoxy(x, y);
				printf("입력내용 사이에 공백이 없이 입력해주시기 바랍니다.       ");
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
					printf("이체하실 금액을 입력하세요.                               ");

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
							printf("금액을 입력해주시기 바랍니다.                             ");
							continue;
						}
						for (j=0; j<tempi; j++) {
							if (isdigit(tempchar2[j])==0) {
								gotoxy(x, y);
								printf("숫자로 입력해주시기 바랍니다.                             ");
								tempj++;
								break;
							}
						}
						for (j=0; j<tempi; j++) {
							if (isspace(tempchar2[j])!=0) {
								gotoxy(x, y);
								printf("입력내용 사이에 공백이 없이 입력해주시기 바랍니다.       ");
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
								printf("계좌의 비밀번호를 입력하시오.                             "); 
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
									printf("위 사항이 맞습니까? (Y/N)                                 ");
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
											printf("이체 되었습니다.                                        "); 
												account[customer[n].acc[k]].money = account[customer[n].acc[k]].money - atoi(tempchar2);
												account[q].money = account[q].money + atoi(tempchar2);
												trade[trade_cnt].money = -atoi(tempchar2);
												trade[trade_cnt].number = customer[n].acc[k];
												strcpy(trade[trade_cnt].type, "계좌이체(보냄)");
												trade[trade_cnt].day.year = today->tm_year+1900;
												trade[trade_cnt].day.month = today->tm_mon+1;
												trade[trade_cnt].day.day = today->tm_mday;
												trade_cnt++;
												trade[trade_cnt].money = atoi(tempchar2);
												trade[trade_cnt].number = q;
												strcpy(trade[trade_cnt].type, "계좌이체(받음)");
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
											printf("취소되었습니다.                                           ");
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
								printf("잔액이 부족합니다.                                      ");
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
		printf("해당 계좌가 없습니다.                                    ");
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
							printf("%d년 %d월 %d일    %s    %.0f\n", trade[i].day.year, trade[i].day.month, trade[i].day.day, trade[i].type, trade[i].money);
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
							printf("%d년 %d월 %d일    %s    %.0f\n", trade[i].day.year, trade[i].day.month, trade[i].day.day, trade[i].type, trade[i].money);
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
							printf("%d년 %d월 %d일    %s    %.0f\n", trade[i].day.year, trade[i].day.month, trade[i].day.day, trade[i].type, trade[i].money);
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
							printf("%d년 %d월 %d일    %s    %.0f\n", trade[i].day.year, trade[i].day.month, trade[i].day.day, trade[i].type, trade[i].money);
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
							printf("%d년 %d월 %d일    %s    %.0f\n", trade[i].day.year, trade[i].day.month, trade[i].day.day, trade[i].type, trade[i].money);
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
				if (y <16) y+=2;
				break;
			}
		} else {
			if (ch == ENTER) {
				y=wherey();
				if ( y==8 ) {
					system("cls");
					creat_installment(n, k);	// 적금 생성
					return ;
				} else if (y==10) {
					system("cls");
					input_installment(n, k);	// 적금액 입금
					return ;
				} else if (y==12) {
					system("cls");
					// 적금 해지 
					installment_view(n, k);
				}  else if (y==14) {
					system("cls");
					cancelation_installment(n, k);
						// 이전메뉴  
				} else if (y == 16) {
					system("cls");
				}
			} else if (ch == ESC) exit(1);
		}
	} while (ch != ENTER && ch != ESC);
}
///////////////////////////////////////////////////////////

void creat_installment(int n, int k)  // 적금 에대한 정보를 어디 따가 저장 할지 고민 .....ㅋ
{
	time_t ttime;
	struct tm *today;
	time(&ttime);
	today = localtime(&ttime);
	
	base_scr();
	gotoxy(3, 4);
	printf("적금 개설");
	
	gotoxy(10, 8);
	printf("적금 금액 -> ");

	gotoxy(10, 10);
	printf("적금 기간 -> ");

	gotoxy(10, 31);
	printf("적금하실 금액을 입력하시오.                               ");
	gotoxy(24, 8);
	while (1) {
		fflush(stdin);
		gotoxy(10, 29);
		gets(account[customer[n].acc[k]].installment.cost);
		tempi = strlen(account[customer[n].acc[k]].installment.cost);
		tempj = 0;
		
		if (tempi==0) {
			gotoxy(10, 31);
			printf("금액을 입력해주시기 바랍니다.                             ");
			continue;
		}
		for (j=0; j<tempi; j++) {
			if (isdigit(account[customer[n].acc[k]].installment.cost[j])==0) {
				gotoxy(10, 31);
				printf("숫자로 입력해주시기 바랍니다.                             ");
				tempj++;
				break;
			}
		}
		for (j=0; j<tempi; j++) {
			if (isspace(account[customer[n].acc[k]].installment.cost[j])!=0) {
				gotoxy(10, 31);
				printf("입력내용 사이에 공백이 없이 입력해주시기 바랍니다.       ");
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
	printf("적금 기간(개월)을 입력하시오.                               ");
	while (1) {
		fflush(stdin);
		gotoxy(10, 29);
		gets(account[customer[n].acc[k]].installment.during_month);
		tempi = strlen(account[customer[n].acc[k]].installment.during_month);
		tempk = 0;
		if (tempi==0) {
			gotoxy(10, 31);
			printf("금액을 입력해주시기 바랍니다.                             ");
			continue;
		}
		for (j=0; j<tempi; j++) {
			if (isdigit(account[customer[n].acc[k]].installment.during_month[j])==0) {
				gotoxy(10, 31);
				printf("숫자로 입력해주시기 바랍니다.                             ");
				tempk++;
				break;
			}
		}
		for (j=0; j<tempi; j++) {
			if (isspace(account[customer[n].acc[k]].installment.during_month[j])!=0) {
				gotoxy(10, 31);
				printf("입력내용 사이에 공백이 없이 입력해주시기 바랍니다.       ");
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
		printf("위 사항이 맞습니까? (Y/N)                                 ");
		gotoxy(10, 29);
		printf("                                                          ");
		while(1) {
			gotoxy(10, 29);
			fflush(stdin);
			gets(tempchar2);
			if (strcmp(tempchar2, "Y")==0||strcmp(tempchar2, "y")==0) {
				gotoxy(10, 31);
				printf("적금이 개설되었습니다.                                  "); // 정상 customer[n].acc[k] 정상
		
				strcpy(trade[trade_cnt].type, "적금개설");

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
				printf("취소되었습니다.                                           ");
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
	printf("적금액 입력");
	/////날짜 한달뒤인걸로 봐야되 ...ㅋ// 개월은 현재에서 처음을 빼서 음수면 12를 더해서 빼 ...
	gotoxy(3, 6);
	printf("%d", trade[trade_cnt].day.month);
	if (((today->tm_mon+1) - (trade[trade_cnt].day.month)) > 2 ) {
		cancelation_installment(n, k);
		return ;
	}
	gotoxy(3, 6);
	printf("%d ",(today->tm_mon+1));
	printf("%d ",trade[trade_cnt].day.month);// 요거 저장 안됨
	printf("%d ",((today->tm_mon+1) - (trade[trade_cnt].day.month)) );
	if (((today->tm_mon+1) - (trade[trade_cnt].day.month)) < 0) {
		if (((today->tm_mon+13) - (trade[trade_cnt].day.month)) >2 ) {
			cancelation_installment(n, k);
			return ;
		} else {
			in_money_scr();
			gotoxy(10, 31);
			printf("입금하실 적금 금액은 %s 입니다. 입금하시겠습니까? (y/n)  ", account[customer[n].acc[k]].installment.cost);
			gotoxy(10, 29);
			printf("                                                          ");
			while(1) {
				fflush(stdin);
				gets(tempchar2);
				if (strcmp(tempchar2, "Y")==0||strcmp(tempchar2, "y")==0) {
					gotoxy(10, 31);
					printf("입금되었습니다.                                         "); // 정상 customer[n].acc[k] 정상
					account[customer[n].acc[k]].installment.num++;
					account[customer[n].acc[k]].money = account[customer[n].acc[k]].money + atoi(account[customer[n].acc[k]].installment.cost);
					trade[trade_cnt].money = atoi(account[customer[n].acc[k]].installment.cost);
					trade[trade_cnt].number = customer[n].acc[k];
					strcpy(trade[trade_cnt].type, "입금");
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
					printf("취소되었습니다.                                           ");
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
	printf("적금 조회");


	gotoxy(10, 31);
	printf("계좌의 비밀번호를 입력하시오.                             ");  //여까지 n, k 정상
	gotoxy(10, 29);
	printf("                                                          ");
	gotoxy(10, 29);
	fflush(stdin);
	strcpy(tempchar, "");
	for (j=0; (tempchar[j]=getch())!='\r'; j++) printf("*");
	tempchar[j] = '\0';
	if (atoi(tempchar)==account[customer[n].acc[k]].password) {
		gotoxy(23, 8);
		printf("%d", account[customer[n].acc[k]].money);  //여기도 n, k 정상
		gotoxy(23, 10);
		printf("%d년 %d월 %d일\n", account[customer[n].acc[k]].term.year, account[customer[n].acc[k]].term.month, account[customer[n].acc[k]].term.day);
		job_return();
	}
	else {
		gotoxy(10 ,31);
		printf("비밀번호가 틀립니다.                                      ");
		Sleep(1000);
	}
}

void cancelation_installment(int n, int k)
{
	base_scr();

	gotoxy(7, 10);
	printf("%s 님의 적금이 해약 되었습니다.", customer[n].name);
	gotoxy(7, 12);
	printf("해약 후 반환 금액은 %d 입니다.", atoi(account[customer[n].acc[k]].installment.cost)*(account[customer[n].acc[k]].installment.num) );
}
	
void job_menu_sel2(int n, int k)
{
	int x=7, y=19, ch;
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
	printf("계좌의 비밀번호를 입력하시오.                             "); 
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
		printf("%d년 %d월까지\n", account[customer[n].acc[k]].term.year, account[customer[n].acc[k]].term.month);
		job_return();
	}
	else {
		y=31;
		gotoxy(x, y);
		printf("비밀번호가 틀립니다.                                      ");
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
		strcpy(customer[n].credit, "신용불량");		
	
	if (strcmp(customer[n].credit, "신용불량")==0){
		y=31;
		gotoxy(x, y);		
		printf("%s는 대출을 할 수 없습니다.", customer[n].credit);
		Sleep(2000);
	}
	else if(account[customer[n].acc[k]].money!=0){
		y=31;
		gotoxy(x, y);
		printf("이미 대출을 하셨습니다.                ");
		Sleep(3000);
		lend_menu_sel(n, k);
	}
	
	if (strcmp(customer[n].credit, "하")==0)
		lend_max=loan.loan_l;
	else if (strcmp(customer[n].credit, "중")==0)
		lend_max=loan.loan_m;
	else if (strcmp(customer[n].credit, "상")==0)
		lend_max=loan.loan_h;
	
	
	printf("대출하실 금액을 입력하시오.                     ");
	
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
			printf("금액을 입력해주시기 바랍니다.          ");
			continue;
		}
		if(lend_max<atoi(tempchar)) {
			gotoxy(x, y);
			printf("신용등급 %s는 %d까지 대출이 가능합니다.        ", customer[n].credit, lend_max);
			continue;
		}
		
		for (j=0; j<tempi; j++) {
			if (isdigit(tempchar[j])==0) {
				gotoxy(x, y);
				printf("숫자로 입력해주시기 바랍니다.                             ");
				tempj++;
				break;
			}
		}
		for (j=0; j<tempi; j++) {
			if (isspace(tempchar[j])!=0) {
				gotoxy(x, y);
				printf("입력내용 사이에 공백이 없이 입력해주시기 바랍니다.       ");
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
	printf("대출 기간을 입력하시오.(단위:월)                  ");
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
			printf("대출 기간을 입력해주시기 바랍니다.                           ");
			continue;
		}
		if (tempi>3||tempi<1) {
			gotoxy(x, y);
			printf("1~3자 사이로 입력해주시기 바랍니다.                      ");
			continue;
		}
		if (atoi(tempchar3)>120) {
			gotoxy(x, y);
			printf("1~120개월 사이로 입력해주시기 바랍니다.                      ");
			continue;
		}
		for (j=0; j<tempi; j++) {
			if (isdigit(tempchar[j])==0) {
				gotoxy(x, y);
				printf("숫자로 입력해주시기 바랍니다.                             ");
				tempj++;
				break;
			}
		}
		for (j=0; j<tempi; j++) {
			if (isspace(tempchar[j])!=0) {
				gotoxy(x, y);
				printf("입력내용 사이에 공백이 없이 입력해주시기 바랍니다.       ");
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
		printf("위 사항이 맞습니까? (Y/N)                                 ");
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
				printf("대출되었습니다.                                         ");
				account[customer[n].acc[k]].money = account[customer[n].acc[k]].money - atoi(tempchar);//1로..0                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
				account[customer[n].acc[k]].term.year = today->tm_year+1900 + ((atoi(tempchar3)+today->tm_mon+1)/12);
				account[customer[n].acc[k]].term.month = (atoi(tempchar3)+today->tm_mon+1)%12;
				trade[trade_cnt].money = -atoi(tempchar);
				trade[trade_cnt].number = customer[n].acc[k];
				strcpy(trade[trade_cnt].type, "대출");
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
				printf("취소되었습니다.                                           ");
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
		printf("대출하신 금액이 없습니다.                              ");
		Sleep(3000);
		lend_menu_sel(n, k);
	}
	
	printf("비밀번호를 입력하시오.                        ");
	while(1) {
		strcpy(pa, "");
		for (i=0; (pa[i]=getch())!='\r'; i++) printf("*");
		pa[i] = '\0';
		tempi = strlen(pa);
		tempj = 0;
		
		if (tempi==0) {
			gotoxy(10, 31);
			printf("비밀번호를 입력해주시기 바랍니다.                         ");
			continue;
		}
		if (tempi!=4) {
			gotoxy(10, 31);
			printf("4자로 입력해주시기 바랍니다.                              ");
			continue;
		}
		
		
		for (i=0; i<tempi; i++) {
			if (isdigit(tempchar[i])==0) {
				gotoxy(10, 31);
				printf("숫자로 입력해주시기 바랍니다.                             ");
				tempj++;
				break;
			}
		}
		for (i=0; i<tempi; i++) {
			if (tempchar[i]==32) {
				gotoxy(10, 31);
				printf("입력내용 사이에 공백이 없이 입력해주시기 바랍니다.       ");
				tempj++;
				break;
			}
		}
		
		break;
	}
	
	
	printf("상환 금액을 입력하시오.                               ");
	
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
			printf("금액을 입력해주시기 바랍니다.                             ");
			continue;
		}
		for (j=0; j<tempi; j++) {
			if (isdigit(tempchar[j])==0) {
				gotoxy(x, y);
				printf("숫자로 입력해주시기 바랍니다.                             ");
				tempj++;
				break;
			}
		}
		for (j=0; j<tempi; j++) {
			if (isspace(tempchar[j])!=0) {
				gotoxy(x, y);
				printf("입력내용 사이에 공백이 없이 입력해주시기 바랍니다.       ");
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
				printf("위 사항이 맞습니까? (Y/N)                                 ");
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
						printf("상환되었습니다.                                         "); // 정상 customer[n].acc[k] 정상
						account[customer[n].acc[k]].money = account[customer[n].acc[k]].money + atoi(tempchar);
						trade[trade_cnt].money = atoi(tempchar);
						trade[trade_cnt].number = customer[n].acc[k];
						strcpy(trade[trade_cnt].type, "상환");
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
						printf("취소되었습니다.                                           ");
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
			printf("입력하신 금액이 대출하신 금액보다 많습니다.   ");
			continue;
		}
		break;		
	}
}