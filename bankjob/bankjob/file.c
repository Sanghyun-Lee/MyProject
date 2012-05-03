#include "mainheader.h"

void save_staff()
{
	FILE *fp;
	if ((fp = fopen("staff.txt", "w"))==NULL) {
		printf("staff.txt ������ ������ �ʽ��ϴ�.\n");
		exit(1);
	}
	fwrite(&staff_cnt, sizeof(staff_cnt), 1, fp);
	fwrite(staff, sizeof(staff), 1, fp);
}

void load_staff()
{
	FILE *fp;
	if ((fp = fopen("staff.txt", "r"))==NULL) {
		printf("staff.txt ������ ������ �ʽ��ϴ�.\n");
		exit(1);
	}
	fread(&staff_cnt, sizeof(staff_cnt), 1, fp);
	fread(staff, sizeof(staff), 1, fp);
}

void save_customer()
{
	FILE *fp;
	if ((fp = fopen("customer.txt", "w"))==NULL) {
		printf("customer.txt ������ ������ �ʽ��ϴ�.\n");
		exit(1);
	}
	fwrite(&customer_cnt, sizeof(customer_cnt), 1, fp);
	fwrite(customer, sizeof(customer), 1, fp);
}

void load_customer()
{
	FILE *fp;
	if ((fp = fopen("customer.txt", "r"))==NULL) {
		printf("customer.txt ������ ������ �ʽ��ϴ�.\n");
		exit(1);
	}
	fread(&customer_cnt, sizeof(customer_cnt), 1, fp);
	fread(customer, sizeof(customer), 1, fp);
}

void save_account()
{
	FILE *fp;
	if ((fp = fopen("account.txt", "w"))==NULL) {
		printf("account.txt ������ ������ �ʽ��ϴ�.\n");
		exit(1);
	}
	fwrite(&account_cnt, sizeof(account_cnt), 1, fp);
	fwrite(account, sizeof(account), 1, fp);
}

void load_account()
{
	FILE *fp;
	if ((fp = fopen("account.txt", "r"))==NULL) {
		printf("account.txt ������ ������ �ʽ��ϴ�.\n");
		exit(1);
	}
	fread(&account_cnt, sizeof(account_cnt), 1, fp);
	fread(account, sizeof(account), 1, fp);
}

void save_trade()
{
	FILE *fp;
	if ((fp = fopen("trade.txt", "w"))==NULL) {
		printf("trade.txt ������ ������ �ʽ��ϴ�.\n");
		exit(1);
	}
	fwrite(&trade_cnt, sizeof(trade_cnt), 1, fp);
	fwrite(trade, sizeof(trade), 1, fp);
}

void load_trade()
{
	FILE *fp;
	if ((fp = fopen("trade.txt", "r"))==NULL) {
		printf("trade.txt ������ ������ �ʽ��ϴ�.\n");
		exit(1);
	}
	fread(&trade_cnt, sizeof(trade_cnt), 1, fp);
	fread(trade, sizeof(trade), 1, fp);
}

////////////////////////////////////////////////////////////////

void save_secure_pass()
{
	FILE *fp;
	if ((fp = fopen("securepass.txt", "w"))==NULL) {
		printf("securepass.txt ������ ������ �ʽ��ϴ�.\n");
		exit(1);
	}
	fwrite(&secure_pass, sizeof(secure_pass), 1, fp);
}

void load_secure_pass()
{
	FILE *fp;
	
	if ((fp = fopen("securepass.txt", "r"))==NULL) {
		printf("securepass.txt ������ ������ �ʽ��ϴ�.\n");
		exit(1);
	}
	/*if (secure_pass==0) {
		secure_pass = 1111;
		save_secure_pass();
	} else {*/
		fread(&secure_pass, sizeof(secure_pass), 1, fp);
	//}
}

void save_rate()
{
	FILE *fp;
	if ((fp = fopen("rate.txt", "w"))==NULL) {
		printf("rate.txt ������ ������ �ʽ��ϴ�.\n");
		exit(1);
	}
	fwrite(&rate, sizeof(rate), 1, fp);
}

void load_rate()
{
	FILE *fp;
	
	if ((fp = fopen("rate.txt", "r"))==NULL) {
		printf("rate.txt ������ ������ �ʽ��ϴ�.\n");
		exit(1);
	}
	/*if (rate.deposit_r==0) {
		rate.deposit_r = 3;
		rate.installment_r = 4;
		rate.loan_r = 6;
		save_rate();
	} else {*/
		fread(&rate, sizeof(rate), 1, fp);
	//}
}

// �׳� ���� �ʱⰪ�� ������ �ȵǴµ� ... ���� ���� �ϸ�  ������ �� 

void save_salary()
{
	FILE *fp;
	if ((fp = fopen("salary.txt", "w"))==NULL) {
		printf("salary.txt ������ ������ �ʽ��ϴ�.\n");
		exit(1);
	}
	fwrite(&salary, sizeof(salary), 1, fp);
}

void load_salary()
{
	FILE *fp;
	
	if ((fp = fopen("salary.txt", "r"))==NULL) {
		printf("salary.txt ������ ������ �ʽ��ϴ�.\n");
		exit(1);
	}
	/*if (salary.master_s	== 0) {
		salary.master_s = 8000;
		salary.chief_s = 4000;
		salary.staff_s = 2500;
		save_salary();
	}
	else {*/
		fread(&salary, sizeof(salary), 1, fp);
	//}
}

//////////////////////////////////////////////////////////////////

void save_loan()
{
	FILE *fp;
	if ((fp = fopen("loan.txt", "w"))==NULL) {
		printf("loan.txt ������ ������ �ʽ��ϴ�.\n");
		exit(1);
	}
	fwrite(&loan, sizeof(loan), 1, fp);
	fwrite(&creditgrade, sizeof(creditgrade), 1, fp);
}

void load_loan()
{
	FILE *fp;
	
	if ((fp = fopen("loan.txt", "r"))==NULL) {
		printf("loan.txt ������ ������ �ʽ��ϴ�.\n");
		exit(1);
	}
	/*if (loan.loan_h==0) {
		loan.loan_h = 50000;
		loan.loan_m = 20000;
		loan.loan_l = 5000;
		//creditgrade.grade_max = 10000;
		//creditgrade.grade_min = 2000;
		save_loan();
	} else {*/
		fread(&loan, sizeof(loan), 1, fp);
		fread(&creditgrade, sizeof(creditgrade), 1, fp);
	//}
}

///////////////////////////////////////////////////////////////////
