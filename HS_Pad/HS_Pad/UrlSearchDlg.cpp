// UrlSearchDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Hs_Pad.h"
#include "UrlSearchDlg.h"
#include "Hs_PadDoc.h"
#include "Hs_PadVIew.h"
#include "UrlPadDlg.h"

// CUrlSearchDlg dialog

IMPLEMENT_DYNAMIC(CUrlSearchDlg, CDialog)

CUrlSearchDlg::CUrlSearchDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUrlSearchDlg::IDD, pParent)
{
}

CUrlSearchDlg::~CUrlSearchDlg()
{
}

void CUrlSearchDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ADDRESS, urlAddress);
}


BEGIN_MESSAGE_MAP(CUrlSearchDlg, CDialog)
	
	ON_BN_CLICKED(IDC_URLSEARCH, &CUrlSearchDlg::OnBnClickedUrlsearch)
END_MESSAGE_MAP()


// CUrlSearchDlg message handlers

BOOL CUrlSearchDlg::PreTranslateMessage(MSG* pMsg) 
{
    if(pMsg->message == WM_KEYDOWN){
		if(pMsg->wParam == VK_RETURN){
			OnBnClickedUrlsearch();
            return TRUE;
		}else if(pMsg->wParam == VK_ESCAPE){
			return TRUE;
		}
	}
    return CDialog::PreTranslateMessage(pMsg);
}


void CUrlSearchDlg::OnBnClickedUrlsearch()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	UrlPadDlg = new CUrlPadDlg();
	urlAddress.GetWindowText(UrlPadDlg->url);
	UrlPadDlg->Create(IDD_URLPADDLG, this);
	UrlPadDlg->ShowWindow(SW_SHOW);
}
