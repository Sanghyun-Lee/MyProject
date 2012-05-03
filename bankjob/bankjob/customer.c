#include "mainheader.h"


extern void customer_scr();
void customer_join();
extern void customer_join_sel();
extern void customer_join_scr();

void customer_join()
{
	int x=23, y=8; 
	char tempid1[7], tempid2[8], tempid[14];
	customer_cnt++;
	customer_join_scr();       
	customer[customer_cnt].code = customer_cnt;
	gotoxy(x, y);
	printf("%d", customer_cnt);

	x=7;
	y=10;
	gotoxy(x, y);
	printf("▶");

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

		if (tempi>40) {
			gotoxy(x, y);
			printf("40자 이하로 입력해주시기 바랍니다.                        ");
			continue;
		}
		if (tempi==0) {
			gotoxy(x, y);
			printf("이름을 입력해주시기 바랍니다.                             ");
			continue;
		}
		for (i=0; i<tempi; i++) {
			if (isdigit(tempchar[i])!=0) {
				gotoxy(x, y);
				printf("한글 또는 영문으로 입력해주시기 바랍니다.                 ");
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
			strcpy(customer[customer_cnt].name, tempchar); // 오타수정
			break;
		}
	}
	
	x=23;
	y=10;
	gotoxy(x, y);
	printf("%s", customer[customer_cnt].name); //오타수정

	x=7;
	y=10;
	gotoxy(x, y);
	printf(" ");
	
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
		gets(tempchar);
		tempi = strlen(tempchar);
		tempj = 0;
		y=31;
		
		if (tempi==0) {
			gotoxy(x, y);
			printf("연락처를 입력해주시기 바랍니다.                           ");
			continue;
		}
		if (tempi>11||tempi<9) {
			gotoxy(x, y);
			printf("9~11자 사이로 입력해주시기 바랍니다.                      ");
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
			customer[customer_cnt].phone = atoi(tempchar); //오타수정
			break;
		}
	}

	x=7;
	y=12;
	gotoxy(x, y);
	printf(" ");
	
	y=14;
	gotoxy(x, y);
	printf("▶");

	x=23;
	y=12;
	gotoxy(x, y);
	printf("0%.0f", customer[customer_cnt].phone);

	x=7;
	y=14;
	gotoxy(x, y);
	printf("▶");

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
			printf("주민번호를 입력해주시기 바랍니다.                         ");
			continue;
		}
		if (tempi!=13) {
			gotoxy(x, y);
			printf("13자로 입력해주시기 바랍니다.                             ");
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
		for (i=0;i<customer_cnt;i++) {
			itoa(customer[i].id1, tempid1, 10);
			itoa(customer[i].id2, tempid2, 10);
			strcpy(tempid, tempid1);
			strcat(tempid, tempid2);
			if(strcmp(tempchar, tempid)==0) {
				gotoxy(x, y);
				printf("이미 등록되어있는 회원입니다.");
				tempj++;
				break;
			}
		}
		if (tempj==0) {
			for (i=0; i<6; i++) tempid1[i] = tempchar[i];
			for (i=6; i<13; i++) tempid2[i-6] = tempchar[i];
			customer[customer_cnt].id1 = atoi(tempid1);
			customer[customer_cnt].id2 = atoi(tempid2);
			break;
		}
	}

	x=23;
	y=14;
	gotoxy(x, y);
	printf("%d-%d", customer[customer_cnt].id1, customer[customer_cnt].id2);

	x=7;
	y=14;
	gotoxy(x, y);
	printf(" ");
	
	y=16;
	gotoxy(x, y);
	printf("▶");

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
			printf("주소를 입력해주시기 바랍니다.                             ");
			continue;
		}
		if (tempi>100) {
			gotoxy(x, y);
			printf("100자 이하로 입력해주시기 바랍니다.                       ");
			continue;
		}
		strcpy(customer[customer_cnt].address, tempchar);
		break;
	}

	x=23;
	y=16;
	gotoxy(x, y);
	printf("%s", customer[customer_cnt].address);

	x=7;
	y=16;
	gotoxy(x, y);
	printf(" ");
	
	y=18;
	gotoxy(x, y);
	printf("▶");

	while(1) {
		x=10;
		y=31;
		gotoxy(x, y);
		printf("1.하(0~2000), 2중(2000~10000), 3.상(10000~)");
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
			strcpy(customer[customer_cnt].credit, "하");
			break;
		case 2:
			strcpy(customer[customer_cnt].credit, "중");
			break;
		case 3:
			strcpy(customer[customer_cnt].credit, "상");
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
	x=23;
	y=18;
	gotoxy(x,y);
	printf("%s", customer[customer_cnt].credit);
	save_customer();
	x=10;
	y=31;
	gotoxy(x, y);
	printf("저장이 완료되었습니다.                                    ");
	Sleep(1000);
	return;
}
		
void customer_menu_sel()
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
					customer_join();
				} else if (y==10) {
					customer_viewsel_sel(1);
				}
				else if (y==12) {
					customer_viewsel_sel(2);
				}
			} else if (ch == ESC) exit(1);
		}
	} while (ch != ENTER && ch != ESC);
}

void customer_viewsel_sel(int z)
{
	int x;
	int y;
	int ch;
	customer_viewsel_scr();
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
				if (y <10) y+=2;
				break;
			}
		} else {
			if (ch == ENTER) {
				y=wherey();
					if ( y==8 ) {
						x=10;
						y=31;
						gotoxy(x, y);
						printf("이름을 입력하시오.                                        ");
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

							if (tempi>40) {
								gotoxy(x, y);
								printf("40자 이하로 입력해주시기 바랍니다.                        ");
								continue;
							}
							if (tempi==0) {
								gotoxy(x, y);
								printf("이름을 입력해주시기 바랍니다.                             ");
								continue;
							}
							for (i=0; i<tempi; i++) {
								if (isdigit(tempchar[i])!=0) {
									gotoxy(x, y);
									printf("한글 또는 영문으로 입력해주시기 바랍니다.                 ");
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
								for (i=1; i<=customer_cnt; i++) {
									if (strcmp(tempchar, customer[i].name)==0) {
										customer_view(i); // i=정상
										if (z==1) customer_return(); // i=10
										else if (z==2) customer_ask(i);
										else if (z==3) account_cus_ask(i);
										else if (z==4) job_cus_ask(i);
										return;
									}
								}
								y=31;
								gotoxy(x, y);
								printf("이름에 해당되는 고객이 없습니다.                        ");
								Sleep(1000);
								return ;
							}
						}
					} else if (y==10) {
						x=10;
						y=31;
						gotoxy(x, y);
						printf("전화번호를 입력하시오.                                    ");
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
								printf("연락처를 입력해주시기 바랍니다.                           ");
								continue;
							}
							if (tempi>11||tempi<9) {
								gotoxy(x, y);
								printf("9~11자 사이로 입력해주시기 바랍니다.                      ");
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
								for (i=1; i<=customer_cnt; i++) {
									if (atoi(tempchar)==customer[i].phone) {
										customer_view(i);
										if (z==1) customer_return();
										else if (z==2) customer_ask(i);
										else if (z==3) account_cus_ask(i);
										else if (z==4) job_cus_ask(i);
										return;
									}
								}
								y=31;
								gotoxy(x, y);
								printf("전화번호에 해당되는 고객이 없습니다.                    ");
								Sleep(1000);
								return ;
							}
						}
						return ;
					}
			} else if (ch == ESC) exit(1);
		}
	} while (ch != ENTER && ch != ESC);
}

void customer_view(int n)
{
	int x=23, y=8;
	customer_view_scr();
	gotoxy(x, y);
	printf("%d", customer[n].code);
	y=10;
	gotoxy(x, y);
	printf("%s", customer[n].name);
	y=12;
	gotoxy(x, y);
	printf("0%.0f", customer[n].phone);
	y=14;
	gotoxy(x, y);
	printf("%d-%d", customer[n].id1, customer[n].id2);
	y=16;
	gotoxy(x, y);
	printf("%s", customer[n].address);
	y=18;
	gotoxy(x, y);
	printf("%s", customer[n].credit);
	y=20;
	gotoxy(x, y);
	for (j=0; j<10; j++) {
		if (customer[n].acc[j]!=0) {
			printf("%d %s", account[customer[n].acc[j]].number, account[customer[n].acc[j]].type);
			y++;
			gotoxy(x, y);
		}
	}
	return;
}

void customer_return()
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

void customer_ask(int n) 
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
			customer_edit(n);
			break;
		case 2:
			customer_delete(n);
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

void customer_edit(int n)
{
	int x=7, y=10, ch;
	char tempid1[7], tempid2[8], tempid[14];
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
				if (y <18) 
					y+=2;
				break;
			}
		} else {
			if (ch == ENTER) {
				y=wherey();
					if ( y==10 ) {
						x=10;
						y=31;
						gotoxy(x, y);
						printf("새로운 이름을 입력하시오.                                 ");
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

							if (tempi>40) {
								gotoxy(x, y);
								printf("40자 이하로 입력해주시기 바랍니다.                        ");
								continue;
							}
							if (tempi==0) {
								gotoxy(x, y);
								printf("이름을 입력해주시기 바랍니다.                             ");
								continue;
							}
							for (i=0; i<tempi; i++) {
								if (isdigit(tempchar[i])!=0) {
									gotoxy(x, y);
									printf("한글 또는 영문으로 입력해주시기 바랍니다.                 ");
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
								strcpy(customer[n].name, tempchar);
								save_customer();
								y=31;
								gotoxy(x, y);
								printf("수정이 완료되었습니다.                                    ");
								Sleep(1000);
								customer_view(n);
								customer_ask(n);
								break;
							}
						}
					} else if (y==12) {
						x=10;
						y=31;
						gotoxy(x, y);
						printf("새로운 연락처를 입력하시오.                               ");
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
								printf("연락처를 입력해주시기 바랍니다.                           ");
								continue;
							}
							if (tempi>11||tempi<9) {
								gotoxy(x, y);
								printf("9~11자 사이로 입력해주시기 바랍니다.                      ");
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
								customer[n].phone = atoi(tempchar);
								save_customer();
								y=31;
								gotoxy(x, y);
								printf("수정이 완료되었습니다.                                    ");
								Sleep(1000);
								customer_view(n);
								customer_ask(n);
								break;
							}
						}
					} else if (y==14) {
						x=10;
						y=31;
						gotoxy(x, y);
						printf("새로운 주민번호를 입력하시오.                             ");
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
								printf("주민번호를 입력해주시기 바랍니다.                         ");
								continue;
							}
							if (tempi!=13) {
								gotoxy(x, y);
								printf("13자로 입력해주시기 바랍니다.                             ");
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
							for (i=0;i<customer_cnt;i++) {
								itoa(customer[i].id1, tempid1, 10);
								itoa(customer[i].id2, tempid2, 10);
								strcpy(tempid, tempid1);
								strcat(tempid, tempid2);
								if(strcmp(tempchar, tempid)==0) {
									gotoxy(x, y);
									printf("이미 등록되어있는 회원입니다.");
									tempj++;
									break;
								}
							}
							if (tempj==0) {
								for (i=0; i<6; i++) tempid1[i] = tempchar[i];
								for (i=6; i<13; i++) tempid2[i-6] = tempchar[i];
								customer[n].id1 = atoi(tempid1);
								customer[n].id2 = atoi(tempid2);
								save_customer();
								y=31;
								gotoxy(x, y);
								printf("수정이 완료되었습니다.                                    ");
								Sleep(1000);
								customer_view(n);
								customer_ask(n);
								break;
							}
						}
					} else if (y==16) {
						x=10;
						y=31;
						gotoxy(x, y);
						printf("새로운 주소를 입력하시오.                                 ");
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
								printf("주소를 입력해주시기 바랍니다.                             ");
								continue;
							}
							if (tempi>100) {
								gotoxy(x, y);
								printf("100자 이하로 입력해주시기 바랍니다.                       ");
								continue;
							}
							strcpy(customer[n].address, tempchar);
							save_customer();
							y=31;
							gotoxy(x, y);
							printf("수정이 완료되었습니다.                                    ");
							Sleep(1000);
							customer_view(n);
							customer_ask(n);
							break;
						}
					} else if (y==18) {
						x=10;
						y=31;
						gotoxy(x, y);
						printf("1.하(0~2000), 2중(2000~10000), 3.상(10000~)");

						while(1) {
							y=29;
							gotoxy(x, y);
							printf("                                                          ");
							gotoxy(x, y);
							fflush(stdin);
							scanf("%d", &tempi);
							
							switch(tempi) {
							case 1:
								strcpy(customer[n].credit, "하");
								break;
							case 2:
								strcpy(customer[n].credit, "중");
								break;
							case 3:
								strcpy(customer[n].credit, "상");
								break;
							default:
								continue;
							}
							break;
						}
						save_customer();
						y=31;
						gotoxy(x, y);
						printf("수정이 완료되었습니다.                                    ");
						Sleep(1000);
						customer_view(n);
						customer_ask(n);
						break;
					}
			} else if (ch == ESC) exit(1);		
		}
	} while (ch != ENTER && ch != ESC);
}

void customer_delete(int n)
{
	int x=10, y=31;
	for (i=0; i<10; i++) {
		if (customer[n].acc[i]!=0) {
			gotoxy(x, y);
			printf("계좌가 남아있는 고객은 삭제할 수 없습니다.                ");
			Sleep(2000);
			return;
		}
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
			customer[n].code = 0;
			strcpy(customer[n].name, "");
			customer[n].phone = 0;
			customer[n].id1 = 0;
			customer[n].id2 = 0;
			strcpy(customer[n].address, "");
			strcpy(customer[n].credit, "");
			for (i=0; i<10; i++) customer[n].acc[i]=0;
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
