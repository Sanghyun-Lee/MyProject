#pragma once
#include "explorer1.h"
#include "afxwin.h"


// CUrlPadDlg dialog
class CUrlSearchDlg;

class CUrlPadDlg : public CDialog
{
	DECLARE_DYNAMIC(CUrlPadDlg)

public:
	CUrlPadDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CUrlPadDlg();
	CString url;

// Dialog Data
	enum { IDD = IDD_URLPADDLG};

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	DECLARE_MESSAGE_MAP()
public:
	CExplorer1 Explorer;
	CButton Search;
	afx_msg void OnBnClickedSearch();
	CEdit urlAddress;
	CBitmapButton backward;
	CBitmapButton forward;
	CBitmapButton refresh;
	CBitmapButton stop;
	CBitmapButton home;
	afx_msg void OnBnClickedBackward();
	afx_msg void OnBnClickedRefresh();
	afx_msg void OnBnClickedForward();
	afx_msg void OnBnClickedHome();
	afx_msg void OnBnClickedStop();
	DECLARE_EVENTSINK_MAP()
	void NavigateComplete2Explorer1(LPDISPATCH pDisp, VARIANT* URL);
	void CommandStateChangeExplorer1(long Command, BOOL Enable);
};
