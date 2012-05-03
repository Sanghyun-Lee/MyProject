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

typedef struct install{		// ���� ������ ���� ���� 
	char during_month[10];
	char cost[15];
	int num;
}install;

struct account {
	int number;   // ���� ��ȣ
	double money;
	char type[11];
	int password;  // char password[5];
	install installment;
	date term;
} account[max_account];

struct staff {
	//int code;			// ����� ��ȣ
	char name[41];		// �̸� 
	double phone;		// ��ȭ ��ȣ char phone[12];		// ��ȭ ��ȣ
	int id1;
	int id2;		// �ֹε�� ��ȣ char id[14];
	char address[101];	// �ּ� 
	double salary;			// ����
	int hobong;         // ȣ��
	int pass;		// ��й�ȣ char pass[5];
	char position[9];
	date day;           // �Ի糯¥
} staff[max_staff]; 

struct cous {
	int code;			// �� ��ȣ
	char name[41];		// �̸� 
	double phone;		// ��ȭ ��ȣ char phone[12];	
	int id1;
	int id2;		// �ֹε�� ��ȣ char id[14];
	char address[101];	// �ּ� 
	char credit[5];		// �ſ��� (������)
	int acc[10];	// ���� 
} customer[max_member]; // ��Ÿ����

struct trade {
	int number;
	double money;
	char type[15];
	date day;
} trade[max_trade];

struct r {
	double installment_r;		// ���� ������
	char ins_r[10];
	double loan_r;				// ���� ������ 
	char lo_r[10];
	double deposit_r;			// ���� ������
	char dep_r[10];
}rate;

struct sala{
	int master_s; // ������ ����
	int chief_s; // ���� ����
	char ch_s[15];
	int staff_s; //�Ϲ� ���� ����
	char sta_s[15];
}salary;

struct lo{
	int loan_h; // ���� �ѵ� ��
	char lo_h[15];
	int loan_m; // ���� �ѵ� ��
	char lo_m[15];
	int loan_l; // ���� �ѵ� ��
	char lo_l[15];
}loan;

struct creditgr{
	int grade_min; // �ſ��� ���� �� �ּҰ�
	char gr_min[15];
	int grade_max; // �ſ��� ���� �� �ִ밪
	char gr_max[15];
}creditgrade;

int staff_cnt, customer_cnt, account_cnt, trade_cnt; // ��Ÿ����
int i, j, tempi, tempj, tempk; // �ӽú�����
char tempchar[101], tempchar2[101], tempchar3[101]; // �ӽú���
int secure_pass;			// ���� ��й�ȣ 
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

void save_staff(); // �߰�
void load_staff(); // �߰�
void save_customer(); // �߰�
void load_customer(); // �߰�
void save_account(); // �߰�
void load_account(); // �߰�
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

void customer_scr(); //��Ÿ����
void customer_join(); //��Ÿ����
void customer_join_sel(); //��Ÿ����
void customer_join_scr(); //��Ÿ����
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
void installment_sel_scr(); // �Ż�
void installment_sel(int n, int k); // �Ż�
void creat_installment(int n, int k); // �Ż�
void input_installment(int n, int k); // �Ż�
void cancelation_installment(int n, int k); // �Ż�
void installment_view(int n, int k); // �Ż�

void base_scr();
int secure_password();	// ���Ⱥ�� ��ȣ�� Ȯ�� �ϴ� ��� 
int secure_password_input();
int secure_password_cmp(int pass);
void etc_menu_sel();	 // ��Ÿ �޴��� ���� �ϴ� �Լ�  
void etc_menu_scr();
void rate_change();		// ������ ���� �ϴ� �Լ� 
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