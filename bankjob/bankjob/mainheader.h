#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define TRUE 1
#define FALSE 0
#define max_member 1000
#define max_staff 1000
#define max_account 1000
#define max_trade 10000
#define ENTER 13 
#define ESC 27
#define UP 72
#define DOWN 80

typedef struct date {  
	int year;
	int month;
	int day;
} date;

typedef struct install{		// 적금 정보에 대한 정보 
	char during_month[10];
	char cost[15];
	int num;
}install;

struct account {
	int number;   // 계좌 번호
	double money;
	char type[11];
	int password;  // char password[5];
	install installment;
	date term;
} account[max_account];

struct staff {
	//int code;			// 은행원 번호
	char name[41];		// 이름 
	double phone;		// 전화 번호 char phone[12];		// 전화 번호
	int id1;
	int id2;		// 주민등록 번호 char id[14];
	char address[101];	// 주소 
	double salary;			// 연봉
	int hobong;         // 호봉
	int pass;		// 비밀번호 char pass[5];
	char position[9];
	date day;           // 입사날짜
} staff[max_staff]; 

struct cous {
	int code;			// 고객 번호
	char name[41];		// 이름 
	double phone;		// 전화 번호 char phone[12];	
	int id1;
	int id2;		// 주민등록 번호 char id[14];
	char address[101];	// 주소 
	char credit[5];		// 신용등급 (상중하)
	int acc[10];	// 계좌 
} customer[max_member]; // 오타수정

struct trade {
	int number;
	double money;
	char type[15];
	date day;
} trade[max_trade];

struct r {
	double installment_r;		// 적금 이자율
	char ins_r[10];
	double loan_r;				// 대출 이자율 
	char lo_r[10];
	double deposit_r;			// 예금 이자율
	char dep_r[10];
}rate;

struct sala{
	int master_s; // 은행장 연봉
	int chief_s; // 과장 연봉
	char ch_s[15];
	int staff_s; //일반 직원 연봉
	char sta_s[15];
}salary;

struct lo{
	int loan_h; // 대출 한도 상
	char lo_h[15];
	int loan_m; // 대출 한도 중
	char lo_m[15];
	int loan_l; // 대출 한도 하
	char lo_l[15];
}loan;

struct creditgr{
	int grade_min; // 신용등급 연봉 중 최소값
	char gr_min[15];
	int grade_max; // 신용등급 연봉 중 최대값
	char gr_max[15];
}creditgrade;

int staff_cnt, customer_cnt, account_cnt, trade_cnt; // 오타수정
int i, j, tempi, tempj, tempk; // 임시변수들
char tempchar[101], tempchar2[101], tempchar3[101]; // 임시변수
int secure_pass;			// 보안 비밀번호 
int temparray[10];
char na[10], pa[10];


void gotoxy(int x, int y);
int wherex();
int wherey();
int login();
void login_scr();
void name();
void password();
int passcmp();
void date1();
void mainmenu_scr();
void mainmenu_sel();
void staffmenu_scr();
void staffmenu_sel();

void staff_join();
void staff_join_scr();
void staff_edit(int n);
void staff_delete(int n);
void staff_viewsel_scr();
void staff_view_scr();
void staff_view(int n);
void staff_viewsel_sel(int z);
void staff_ask(int n); 
void staff_return();

void save_staff(); // 추가
void load_staff(); // 추가
void save_customer(); // 추가
void load_customer(); // 추가
void save_account(); // 추가
void load_account(); // 추가
void save_trade();
void load_trade();

void save_secure_pass();
void load_secure_pass();
void save_rate();
void load_rate();
void save_salary();
void load_salary();
void save_loan();
void load_loan();
void save_creditgrade();
void load_creditgrade();

void customer_scr(); //오타수정
void customer_join(); //오타수정
void customer_join_sel(); //오타수정
void customer_join_scr(); //오타수정
void customer_menu_scr();
void customer_menu_sel();
void customer_viewsel_sel(int z);
void customer_view(int n);
void customer_view_scr();
void customer_viewsel_scr();
void customer_return();
void customer_ask();
void customer_edit(int n);
void customer_delete(int n);

void accountmenu_scr();
void accountmenu_sel(int n);
void account_join(int n);
void account_join_scr();
void account_view(int n, int k, int z); //
void account_view_scr();
void account_edit(int n, int k); //
void account_delete(int n, int k); //
void account_cus_ask(int n);
void account_view_sel(int n, int z);
void account_return();
void account_ask(int n, int k); //

void job_cus_ask(int n);
void job_menu_sel1(int n, int k); //
void job_menu_sel2(int n, int k);
void job_menu_sel3(int n, int k);
void job_menu_scr();
void job_acc_view(int n, int k); //
void job_return();

void money_view(int n, int k); //
void money_view_scr();
void in_money(int n, int k); //
void in_money_scr();
void out_money(int n, int k);
void out_money_scr();
void transfer(int n, int k);
void transfer_scr();
void trade_view(int n, int k);
void trade_view_scr();
void trade_view_ask_scr();
void installment_sel_scr(); // 신상
void installment_sel(int n, int k); // 신상
void creat_installment(int n, int k); // 신상
void input_installment(int n, int k); // 신상
void cancelation_installment(int n, int k); // 신상
void installment_view(int n, int k); // 신상

void base_scr();
int secure_password();	// 보안비밀 번호를 확인 하는 모듈 
int secure_password_input();
int secure_password_cmp(int pass);
void etc_menu_sel();	 // 기타 메뉴를 선택 하는 함수  
void etc_menu_scr();
void rate_change();		// 이자율 설정 하는 함수 
void salary_change();
void loan_change();
void creditgrade_change();

int dayminus(int n);
void sum();
int sumday(date tempday);

void lend_menu_scr();
void lend_scr();
void lend_repay_scr();
void lend_view_scr();
void lend_menu_sel(int n, int k);
void lend(int n, int k);
void lend_repay(int n, int k);
void lend_view(int n, int k);