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
	//비트맵 버튼생성
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
	
	//UrlSearchDlg에서 입력받은 값으로 페이지 이동
	Explorer.Navigate(url, NULL, NULL, NULL, NULL);
	return true;
}

BOOL CUrlPadDlg::PreTranslateMessage(MSG* pMsg) 
{
	//엔터키가 눌렸을때 다이얼로그 종료 안되게하는부분
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Explorer.Refresh();
}

//뒤로가기 앞으로가기 새로고침 구현
void CUrlPadDlg::OnBnClickedBackward()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Explorer.GoBack();

}

void CUrlPadDlg::OnBnClickedForward()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Explorer.GoForward();
}

void CUrlPadDlg::OnBnClickedHome()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Explorer.GoHome();
}

void CUrlPadDlg::OnBnClickedStop()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Explorer.Stop();
}
BEGIN_EVENTSINK_MAP(CUrlPadDlg, CDialog)
	
	ON_EVENT(CUrlPadDlg, IDC_EXPLORER1, 252, CUrlPadDlg::NavigateComplete2Explorer1, VTS_DISPATCH VTS_PVARIANT)
	ON_EVENT(CUrlPadDlg, IDC_EXPLORER1, 105, CUrlPadDlg::CommandStateChangeExplorer1, VTS_I4 VTS_BOOL)
END_EVENTSINK_MAP()

void CUrlPadDlg::NavigateComplete2Explorer1(LPDISPATCH pDisp, VARIANT* URL)
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	//페이지가 이동될때 현재 URL주소를 urlAddress Editbox에 출력
	UpdateData(TRUE);
	urlAddress.SetWindowText(Explorer.get_LocationURL());
}


void CUrlPadDlg::CommandStateChangeExplorer1(long Command, BOOL Enable)
{
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
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
