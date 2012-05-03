#include "mainheader.h"

void account_cus_ask(int n)
{
	int x=10, y=31;
	gotoxy(x, y);
	printf("위 사항이 맞습니까? (Y/N)                                 ");
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
			printf("취소되었습니다.                                           ");
			Sleep(1000);
			return;
		}
		else {
			y=31;
			gotoxy(x, y);
			printf("Y / N을 입력해주세요.                                     ");
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
	account[account_cnt].number = 1841100000 + account_cnt;		// 18411 은 뭐냐 ?
	gotoxy(x, y);
	printf("%d", account[account_cnt].number); // 10

	x=7;
	y=10;
	gotoxy(x, y);
	printf("▶");
	while(1) {
		x=10;
		y=31;
		gotoxy(x, y);
		printf("1.입출금계좌, 2.적금계좌, 3.대출계좌                      ");
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
			printf("부여된 번호를 입력해주시기 바랍니다.                      ");
			Sleep(1000);
			continue;
		}
		switch(atoi(tempchar)) {
		case 1:
			strcpy(account[account_cnt].type, "입출금계좌");
			break;
		case 2:
			strcpy(account[account_cnt].type, "적금계좌");
			break;
		case 3:
			strcpy(account[account_cnt].type, "대출계좌");
			break;
		default:
			x=10;
			y=31;
			gotoxy(x, y);
			printf("부여된 번호를 입력해주시기 바랍니다.                      ");
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
	printf("▶");

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
			printf("계좌 비밀번호를 입력해주시기 바랍니다.                    ");
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
	printf("저장이 완료되었습니다.                                    ");
	Sleep(1000);
	return ;
}

void account_view_sel(int n, int z)
{
	int x=10, y=31;
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
		for (i=0; i<tempi; i++) {
			if (isdigit(tempchar[i])==0) {
				gotoxy(x, y);
				printf("숫자로 입력해주시기 바랍니다.                             ");
				tempj++;
				break;
			}
		}
		for (i=0; i<tempi; i++) {
			if (isspace(tempchar[i])!=0) {
				gotoxy(x, y);
				printf("입력내용 사이에 공백이 없이 입력해주시기 바랍니다.       ");
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
			printf("해당 계좌가 없습니다.                                    ");
			Sleep(1000);
		}
	}
}

void account_view(int n, int k, int z)
{
	int x=23, y=8;
	account_view_scr();
	gotoxy(x, y);
	printf("%d", account[customer[n].acc[k]].number);  //q번호
	y=10;
	gotoxy(x, y);
	printf("%s", account[customer[n].acc[k]].type); //종류
	y=12;
	gotoxy(x, y);
	printf("****"); //비번
	y=14;
	gotoxy(x, y);
	printf("%s", customer[n].name); //예금주
	y=16;
	gotoxy(x, y);
	printf("0%.0f", customer[n].phone);  //연락처
	if (z==1) account_return();
	else if (z==2) account_ask(n, k);
	return;
}

void account_return()
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

void account_ask(int n, int k) 
{
	int x=10, y=31;
	gotoxy(x, y);
	printf("1.수정, 2.삭제, 0.메인메뉴                              ");

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
			printf("▶");
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
						printf("기존의 비밀번호를 입력하시오.                             ");
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
							printf("새로운 비밀번호를 입력하시오.                             ");
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
									printf("비밀번호를 입력해주시기 바랍니다.                         ");
									continue;
								}
								if (tempi!=4) {
									gotoxy(x, y);
									printf("4자로 입력해주시기 바랍니다.                              ");
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
									if (tempchar[j]==32) {
										gotoxy(x, y);
										printf("입력내용 사이에 공백이 없이 입력해주시기 바랍니다.       ");
										tempj++;
										break;
									}
								}
								if (tempj==0) {
									y=31;
									gotoxy(x, y);
									printf("다시한번 비밀번호를 입력하시오.                           ");
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
											printf("비밀번호를 입력해주시기 바랍니다.                         ");
											continue;
										}
										if (tempi!=4) {
											gotoxy(x, y);
											printf("4자로 입력해주시기 바랍니다.                              ");
											continue;
										}
										for (i=0; i<tempi; i++) {
											if (isdigit(tempchar2[i])==0) {
												gotoxy(x, y);
												printf("숫자로 입력해주시기 바랍니다.                             ");			
												tempj++;
												break;
											}
										}
										for (i=0; i<tempi; i++) {
											if (isspace(tempchar2[i])!=0) {
												gotoxy(x, y);
												printf("입력내용 사이에 공백이 없이 입력해주시기 바랍니다.       ");
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
												printf("수정이 완료되었습니다.                                    ");
												Sleep(1000);
												account_view(n, k, 2);
												tempi=999;
												break;
											}
											else {
												y=31;
												gotoxy(x, y);
												printf("비밀번호가 틀렸습니다.                                    ");
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
							printf("비밀번호가 틀립니다.                                      ");
							Sleep(1000);
						}
					} else if (y==10) {
						x=10;
						y=31;
						gotoxy(x, y);
						printf("1.입출금계좌, 2.적금계좌, 3.대출계좌");

						while(1) {
							y=29;
							gotoxy(x, y);
							printf("                                                          ");
							gotoxy(x, y);
							fflush(stdin);
							scanf("%d", &tempi);
							
							switch(tempi) {
							case 1:
								strcpy(account[customer[n].acc[k]].type, "입출금계좌");
								break;
							case 2:
								strcpy(account[customer[n].acc[k]].type, "적금계좌");
								break;
							case 3:
								strcpy(account[customer[n].acc[k]].type, "대출계좌");
								break;
							default:
								continue;
							}
							break;
						}
						save_account();
						y=31;
						gotoxy(x, y);
						printf("수정이 완료되었습니다.                                    ");
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
			printf("삭제할 수 없습니다.                                       ");
			Sleep(2000);
			return;
	}
	gotoxy(x, y);
	printf("삭제하시겠습니까? (Y/N)                                   ");
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
			printf("삭제가 완료되었습니다.                                    ");
			Sleep(1000);
			return;
		}
		else if (strcmp(tempchar, "N")==0||strcmp(tempchar, "n")==0) {
			y=31;
			gotoxy(x, y);
			printf("삭제가 취소되었습니다.                                    ");
			Sleep(1000);
			return;
		}
		else {
			y=31;
			gotoxy(x, y);
			printf("Y / N을 입력해주세요.                                     ");
			continue;
		}
	}
}