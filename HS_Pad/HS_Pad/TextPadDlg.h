#pragma once
#include "afxwin.h"


// CTextPadDlg dialog
class CHs_PadView;

class CTextPadDlg : public CDialog
{
	DECLARE_DYNAMIC(CTextPadDlg)

public:
	CTextPadDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTextPadDlg();
	CHs_PadView *m_pView;
	CFont font;
	LOGFONT log;
	COLORREF color;
	CFontDialog fontDlg;

// Dialog Data
	enum { IDD = IDD_TEXTPADDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedSavebtn();
	afx_msg void OnBnClickedLoadbtn();
	afx_msg void OnBnClickedFontsetbtn();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CBitmapButton saveBtn;
	CBitmapButton loadBtn;
	CBitmapButton fontset;
	CEdit textpad;
	CBitmapButton newBtn;
	afx_msg void OnBnClickedNewbtn();
};
