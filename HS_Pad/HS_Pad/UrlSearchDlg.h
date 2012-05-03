#pragma once
#include "afxwin.h"


// CUrlSearchDlg dialog
class CHs_PadView;
class CUrlPadDlg;

class CUrlSearchDlg : public CDialog
{
	DECLARE_DYNAMIC(CUrlSearchDlg)

public:
	CUrlSearchDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CUrlSearchDlg();
	CHs_PadView *m_pView;
	CUrlPadDlg *UrlPadDlg;

// Dialog Data
	enum { IDD = IDD_URLSEARCHDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	DECLARE_MESSAGE_MAP()
public:
	CEdit urlAddress;
	afx_msg void OnBnClickedUrlsearch();
protected:

};
