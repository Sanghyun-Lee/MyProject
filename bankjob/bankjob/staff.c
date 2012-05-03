#include "mainheader.h"

void staffmenu_sel()
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
					staff_join();
				} else if (y==10) {
					staff_viewsel_sel(1);
				}
				else if (y==12) {
					staff_viewsel_sel(2);
				}
			} else if (ch == ESC) exit(1);
		}
	} while (ch != ENTER && ch != ESC);
}

void staff_join()
{
	int x=7, y=8; //int x=23, y=8;  
	char tempid1[7], tempid2[8], tempid[14];
	time_t ttime;
	struct tm *today;
	time(&ttime);
	today = localtime(&ttime);
	staff_cnt++;
	staff_join_scr();       

	//gotoxy(x, y);
	//printf("%d", staff_cnt);

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
			strcpy(staff[staff_cnt].name, tempchar);
			break;
		}
	}
	
	x=23;
	y=8;
	gotoxy(x, y);
	printf("%s", staff[staff_cnt].name);
	
	x=7;
	gotoxy(x, y);
	printf(" ");
	
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
			if (isspace(tempchar[i])!=0) {
				gotoxy(x, y);
				printf("입력내용 사이에 공백이 없이 입력해주시기 바랍니다.       ");
				tempj++;
				break;
			}
		}
		if (tempj==0) {
			staff[staff_cnt].pass = atoi(tempchar);
			break;
		}
	}

	x=23;
	y=10;
	gotoxy(x, y);
	printf("****");

	x=7;
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
			staff[staff_cnt].phone = atoi(tempchar);
			break;
		}
	}
	
	x=23;
	y=12;
	gotoxy(x, y);
	printf("0%.0f", staff[staff_cnt].phone); // 더블 출력하는게 모지?? 일단 f해놈

	x=7;
	gotoxy(x, y);
	printf(" ");
	
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
		for (i=1;i<staff_cnt;i++) {
			itoa(staff[i].id1, tempid1, 10);
			itoa(staff[i].id2, tempid2, 10); //정상
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
			staff[staff_cnt].id1 = atoi(tempid1);
			staff[staff_cnt].id2 = atoi(tempid2);
			break;
		}
	}

	x=23;
	y=14;
	gotoxy(x, y);
	printf("%d-%d", staff[staff_cnt].id1, staff[staff_cnt].id2);

	x=7;
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
		strcpy(staff[staff_cnt].address, tempchar);
		break;
	}

	x=23;
	y=16;
	gotoxy(x, y);
	printf("%s", staff[staff_cnt].address);

	x=7;
	gotoxy(x, y);
	printf(" ");
	
	y=18;
	gotoxy(x, y);
	printf("▶");

	while(1) {
		x=10;
		y=31;
		gotoxy(x, y);
		printf("                                                          ");
		gotoxy(x, y);
		printf("1.은행장, 2.과장, 3.일반직원");
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
			strcpy(staff[staff_cnt].position, "은행장");
			break;
		case 2:
			strcpy(staff[staff_cnt].position, "과장");
			break;
		case 3:
			strcpy(staff[staff_cnt].position, "일반직원");
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
	gotoxy(x, y);
	printf("%s", staff[staff_cnt].position);
	
	x=7;
	gotoxy(x, y);
	printf(" ");
	
	y=20;
	gotoxy(x, y);
	printf("▶");

	x=10;
	y=31;
	gotoxy(x, y);
	printf("                                                          ");
	
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
			printf("입사날짜를 입력해주시기 바랍니다.                         ");
			continue;
		}
		if (tempi!=8) {
			gotoxy(x, y);
			printf("8자로 입력해주시기 바랍니다.  ex) 20081125                ");
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
			for (i=0; i<4; i++) tempchar2[i] = ' ';
			for (i=0; i<4; i++) tempchar2[i] = tempchar[i];
			staff[staff_cnt].day.year = atoi(tempchar2);
			for (i=0; i<4; i++) tempchar2[i] = ' ';
			strcpy(tempchar2, "");
			tempchar2[0] = tempchar[4];
			tempchar2[1] = tempchar[5];
			if (atoi(tempchar2)>12) {
				gotoxy(x, y);
				printf("다시 입력해주시기 바랍니다.                              ");
				continue;
			}
			staff[staff_cnt].day.month = atoi(tempchar2);
			for (i=0; i<4; i++) tempchar2[i] = ' ';
			tempchar2[0] = tempchar[6];
			tempchar2[1] = tempchar[7];
			if (atoi(tempchar2)>31) {
				gotoxy(x, y);
				printf("다시 입력해주시기 바랍니다.                              ");
				continue;
			}
			staff[staff_cnt].day.day = atoi(tempchar2);
			x=23;
			y=20;
			gotoxy(x, y);
			printf("%d %d %d", staff[staff_cnt].day.year, staff[staff_cnt].day.month, staff[staff_cnt].day.day);
			break;
		}
	}
	staff[staff_cnt].hobong = ((today->tm_year+1900)-staff[staff_cnt].day.year)+1;
	if (strcmp(staff[staff_cnt].position, "은행장")==0)
		staff[staff_cnt].salary = salary.master_s * (1+((staff[staff_cnt].hobong-1)*0.03));
	if (strcmp(staff[staff_cnt].position, "과장")==0)
		staff[staff_cnt].salary = salary.chief_s * (1+((staff[staff_cnt].hobong-1)*0.03));
	if (strcmp(staff[staff_cnt].position, "일반직원")==0)
		staff[staff_cnt].salary = salary.staff_s * (1+((staff[staff_cnt].hobong-1)*0.03));
	save_staff();
	x=10;
	y=31;
	gotoxy(x, y);
	printf("저장이 완료되었습니다.                                    ");
	Sleep(1000);
	return ;
}

void staff_viewsel_sel(int z)
{
	int x;
	int y;
	int ch;
	staff_viewsel_scr();
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
								for (i=1; i<=staff_cnt; i++) {
									if (strcmp(tempchar, staff[i].name)==0) {
										if (secure_password()) {
											staff_view(i);
										}
										if (z==1) staff_return();
										else if (z==2) staff_ask(i);
										return;
									}
								}
								y=31;
								gotoxy(x, y);
								printf("이름에 해당되는 은행원이 없습니다.                        ");
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
								for (i=1; i<=staff_cnt; i++) {
									if (atoi(tempchar)==staff[i].phone) {
										if (secure_password()) {
											staff_view(i);
										}
										if (z==1) staff_return();
										else if (z==2) staff_ask(i);
										return;
									}
								}
								y=31;
								gotoxy(x, y);
								printf("전화번호에 해당되는 은행원이 없습니다.                    ");
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

void staff_view(int n)
{
	int x=23, y=8;
	staff_view_scr();
	gotoxy(x, y);
	printf("%s", staff[n].name);
	y=10;
	gotoxy(x, y);
	printf("****");
	y=12;
	gotoxy(x, y);
	printf("0%.0f", staff[n].phone);
	y=14;
	gotoxy(x, y);
	printf("%d-%d", staff[n].id1, staff[n].id2);
	y=16;
	gotoxy(x, y);
	printf("%s", staff[n].address);
	y=18;
	gotoxy(x, y);
	printf("%s", staff[n].position);
	y=20;
	gotoxy(x, y);
	printf("%d", staff[n].hobong);
	y=22;
	gotoxy(x, y);
	printf("%.0f", staff[n].salary);
	y=24;
	gotoxy(x, y);
	printf("%d년 %d월 %d일", staff[n].day.year, staff[n].day.month, staff[n].day.day);
}

void staff_return()
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

void staff_ask(int n) 
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
			staff_edit(n);
			break;
		case 2:
			staff_delete(n);
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

void staff_edit(int n)
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
					if (y==16) y-=4;
					else y-=2;
				break;
			case DOWN:
				if (y <18) 
					if (y==12) y+=4;
					else y+=2;
				break;
			}
		} else {
			if (ch == ENTER) {
				y=wherey();
					if ( y==10 ) {
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
						for (i=0; (tempchar[i]=getch())!='\r'; i++) printf("*");
						tempchar[i] = '\0';
						if (atoi(tempchar)==staff[n].pass) {
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
									if (isspace(tempchar[i])!=0) {
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
												staff[n].pass = atoi(tempchar);
												save_staff();
												y=31;
												gotoxy(x, y);
												printf("수정이 완료되었습니다.                                    ");
												Sleep(1000);
												staff_view(n);
												staff_ask(n);
												tempi=999;
												break;
											}
											else {
												y=31;
												gotoxy(x, y);
												printf("비밀번호가 틀렸습니다.                                    ");
												Sleep(1000);
												staff_view(n);
												staff_ask(n);
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
								staff[n].phone = atoi(tempchar);
								save_staff();
								y=31;
								gotoxy(x, y);
								printf("수정이 완료되었습니다.                                    ");
								Sleep(1000);
								staff_view(n);
								staff_ask(n);
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
							strcpy(staff[n].address, tempchar);
							save_staff();
							y=31;
							gotoxy(x, y);
							printf("수정이 완료되었습니다.                                    ");
							Sleep(1000);
							staff_view(n);
							staff_ask(n);
							break;
						}
					} else if (y==18) {
						while(1) {
							x=10;
							y=31;
							gotoxy(x, y);
							printf("                                                          ");
							gotoxy(x, y);
							printf("1.은행장, 2.과장, 3.일반직원");
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
								strcpy(staff[n].position, "은행장");
								break;
							case 2:
								strcpy(staff[n].position, "과장");
								break;
							case 3:
								strcpy(staff[n].position, "일반직원");
								break;
							default:
								x=10;
								y=31;
								gotoxy(x, y);
								printf("부여된 번호를 입력해주시기 바랍니다.                      ");
								Sleep(1000);
								continue;
							}
							save_staff();
							y=31;
							gotoxy(x, y);
							printf("수정이 완료되었습니다.                                    ");
							Sleep(1000);
							staff_view(n);
							staff_ask(n);
							break;
						}
					}
			} else if (ch == ESC) exit(1);		
		}
	} while (ch != ENTER && ch != ESC);
}

void staff_delete(int n)
{
	int x=10, y=31;
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
			//staff[n].code = 0;
			strcpy(staff[n].name, "");
			staff[n].phone = 0;
			staff[n].id1 = 0;
			staff[n].id2 = 0;
			strcpy(staff[n].address, "");
			staff[n].salary = 0;
			staff[n].hobong = 0;
			staff[n].pass = 0;
			strcpy(staff[n].position, "");
			staff[n].day.year = 0;
			staff[n].day.month = 0;
			staff[n].day.day = 0;
			save_staff();
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
