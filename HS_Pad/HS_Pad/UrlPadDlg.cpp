// UrlPadDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Hs_Pad.h"
#include "UrlPadDlg.h"


// CUrlPadDlg dialog

IMPLEMENT_DYNAMIC(CUrlPadDlg, CDialog)

CUrlPadDlg::CUrlPadDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUrlPadDlg::IDD, pParent)
{
}

CUrlPadDlg::~CUrlPadDlg()
{
}

void CUrlPadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EXPLORER1, Explorer);
	DDX_Control(pDX, IDC_Search, Search);
	DDX_Control(pDX, IDC_URLADDRESS, urlAddress);
	DDX_Control(pDX, IDC_BACKWARD, backward);
	DDX_Control(pDX, IDC_FORWARD, forward);
	DDX_Control(pDX, IDC_REFRESH, refresh);
	DDX_Control(pDX, IDC_HOME, home);
	DDX_Control(pDX, IDC_STOP, stop);
}


BEGIN_MESSAGE_MAP(CUrlPadDlg, CDialog)
	ON_BN_CLICKED(IDC_Search, &CUrlPadDlg::OnBnClickedSearch)
	ON_BN_CLICKED(IDC_BACKWARD, &CUrlPadDlg::OnBnClickedBackward)
	ON_BN_CLICKED(IDC_REFRESH, &CUrlPadDlg::OnBnClickedRefresh)
	ON_BN_CLICKED(IDC_FORWARD, &CUrlPadDlg::OnBnClickedForward)
	ON_BN_CLICKED(IDC_HOME, &CUrlPadDlg::OnBnClickedHome)
	ON_BN_CLICKED(IDC_STOP, &CUrlPadDlg::OnBnClickedStop)
END_MESSAGE_MAP()


// CUrlPadDlg message handlers

BOOL CUrlPadDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	//GetDlgItem(IDC_EXPLORER1)->MoveWindow(100,10,m_cx,m_cy);
	//��Ʈ�� ��ư����
	backward.LoadBitmaps(IDB_BITMAP5, IDB_BITMAP6, NULL, IDB_BITMAP11);
	backward.SizeToContent();

	forward.LoadBitmaps(IDB_BITMAP7, IDB_BITMAP8, NULL, IDB_BITMAP12);
	forward.SizeToContent();

	refresh.LoadBitmaps(IDB_BITMAP9, IDB_BITMAP10, NULL, NULL);
	refresh.SizeToContent();

	stop.LoadBitmaps(IDB_BITMAP15, IDB_BITMAP16, NULL, IDB_BITMAP17);
	stop.SizeToContent();

	home.LoadBitmaps(IDB_BITMAP13, IDB_BITMAP14, NULL, NULL);
	home.SizeToContent();
	
	//UrlSearchDlg���� �Է¹��� ������ ������ �̵�
	Explorer.Navigate(url, NULL, NULL, NULL, NULL);
	return true;
}

BOOL CUrlPadDlg::PreTranslateMessage(MSG* pMsg) 
{
	//����Ű�� �������� ���̾�α� ���� �ȵǰ��ϴºκ�
    if(pMsg->message == WM_KEYDOWN){
        if(pMsg->wParam == VK_RETURN){
			OnBnClickedSearch();
            return TRUE;
		}else if(pMsg->wParam == VK_ESCAPE){
			return TRUE;
		}
	}
    return CDialog::PreTranslateMessage(pMsg);
}

void CUrlPadDlg::OnBnClickedSearch()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	urlAddress.GetWindowText(url);
	Explorer.Navigate(url, NULL, NULL, NULL, NULL);
}


void CUrlPadDlg::OnBnClickedRefresh()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Explorer.Refresh();
}

//�ڷΰ��� �����ΰ��� ���ΰ�ħ ����
void CUrlPadDlg::OnBnClickedBackward()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Explorer.GoBack();

}

void CUrlPadDlg::OnBnClickedForward()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Explorer.GoForward();
}

void CUrlPadDlg::OnBnClickedHome()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Explorer.GoHome();
}

void CUrlPadDlg::OnBnClickedStop()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Explorer.Stop();
}
BEGIN_EVENTSINK_MAP(CUrlPadDlg, CDialog)
	
	ON_EVENT(CUrlPadDlg, IDC_EXPLORER1, 252, CUrlPadDlg::NavigateComplete2Explorer1, VTS_DISPATCH VTS_PVARIANT)
	ON_EVENT(CUrlPadDlg, IDC_EXPLORER1, 105, CUrlPadDlg::CommandStateChangeExplorer1, VTS_I4 VTS_BOOL)
END_EVENTSINK_MAP()

void CUrlPadDlg::NavigateComplete2Explorer1(LPDISPATCH pDisp, VARIANT* URL)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	//�������� �̵��ɶ� ���� URL�ּҸ� urlAddress Editbox�� ���
	UpdateData(TRUE);
	urlAddress.SetWindowText(Explorer.get_LocationURL());
}


void CUrlPadDlg::CommandStateChangeExplorer1(long Command, BOOL Enable)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	switch(Command)
    {
     case CSC_NAVIGATEFORWARD:
        // m_ctlForward is a CButton type
        forward.EnableWindow(Enable);
        break;

     case CSC_NAVIGATEBACK:
        backward.EnableWindow(Enable);
        break;

     default:
        break;
     }

}
