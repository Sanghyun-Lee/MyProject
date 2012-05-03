// TextPadDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Hs_Pad.h"
#include "TextPadDlg.h"
#include "Hs_PadDoc.h"
#include "Hs_PadView.h"

// CTextPadDlg dialog

IMPLEMENT_DYNAMIC(CTextPadDlg, CDialog)

CTextPadDlg::CTextPadDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTextPadDlg::IDD, pParent)
{

}

CTextPadDlg::~CTextPadDlg()
{
}

void CTextPadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SAVEBTN, saveBtn);
	DDX_Control(pDX, IDC_LOADBTN, loadBtn);
	DDX_Control(pDX, IDC_EDIT1, textpad);
	DDX_Control(pDX, IDC_FONTSETBTN, fontset);
	DDX_Control(pDX, IDC_NEWBTN, newBtn);
}


BEGIN_MESSAGE_MAP(CTextPadDlg, CDialog)
	ON_BN_CLICKED(IDC_SAVEBTN, &CTextPadDlg::OnBnClickedSavebtn)
	ON_BN_CLICKED(IDC_LOADBTN, &CTextPadDlg::OnBnClickedLoadbtn)
	ON_BN_CLICKED(IDC_FONTSETBTN, &CTextPadDlg::OnBnClickedFontsetbtn)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_NEWBTN, &CTextPadDlg::OnBnClickedNewbtn)
END_MESSAGE_MAP()


// CTextPadDlg message handlers

BOOL CTextPadDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	GetFont()->GetLogFont(&log);

//이미지 버튼을 위한 설정
	
	saveBtn.LoadBitmaps(IDB_BITMAP1, IDB_BITMAP2, NULL, NULL);
	saveBtn.SizeToContent();

	loadBtn.LoadBitmaps(IDB_BITMAP3, IDB_BITMAP4, NULL, NULL);
	loadBtn.SizeToContent();

	fontset.LoadBitmaps(IDB_BITMAP18, IDB_BITMAP19, NULL, NULL);
	fontset.SizeToContent();

	newBtn.LoadBitmaps(IDB_BITMAP33, IDB_BITMAP34, NULL, NULL);
	newBtn.SizeToContent();

	return true;
}

BOOL CTextPadDlg::PreTranslateMessage(MSG *pMsg)
{
	//엔터키를 입력할때 줄바꿈을 하는 부분 
	//엔터키 입력시 다이얼로그 종료 안되게하는 부분
	if((pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN) || 
		(pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE)){
			if(pMsg->wParam == VK_RETURN){
				if(GetFocus() == GetDlgItem(IDC_EDIT1)){
					((CEdit*)GetDlgItem(IDC_EDIT1))->ReplaceSel("\r\n");
					return true;
				}
			}
			return true;
	}
	return CDialog::PreTranslateMessage(pMsg);
}

void CTextPadDlg::OnBnClickedSavebtn()
{
	// TODO: Add your control notification handler code here
	//CFileDialog를 숨긴파일 읽지않고, 
	//같은 이름의 파일이 있을시 물어보는 옵션으로 열기
	char szFilter[] = "(*.txt) | All Files(*.*)|*.*||";
	CFileDialog dlg(FALSE, "txt", "*.txt",
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT  , szFilter);
	
	if(IDOK == dlg.DoModal()){
		CString strPathName = dlg.GetPathName();

		CStdioFile fp;
		CFileException e;
		
		if(!fp.Open(strPathName,CFile::modeWrite|CFile::modeCreate, &e)) {
			e.ReportError();
			return;
		}

		UpdateData(TRUE);
		CString str;
		textpad.GetWindowText(str);
		str.Replace("\r\n", "\n");

		fp.WriteString(str);
		fp.Close();
	}
}

void CTextPadDlg::OnBnClickedLoadbtn()
{
	// TODO: Add your control notification handler code here
	char szFilter[] = "(*.txt) | All Files(*.*)|*.*||";
	CFileDialog dlg(TRUE, "txt", "*.txt", OFN_HIDEREADONLY, szFilter);
	if(IDOK == dlg.DoModal()){
		CString strPathName = dlg.GetPathName();
		
		CStdioFile fp;
		CFileException e;
		
		if(!fp.Open(strPathName, CFile::modeRead, &e)) {
			e.ReportError();
			return;
		}

		CString str = "";
		CString tmp = "";
		
		while(fp.ReadString(tmp)){
			str += tmp;
			str += "\r\n";
		}
		UpdateData(FALSE);
		textpad.SetWindowText(str);
		fp.Close();
	}
}

void CTextPadDlg::OnBnClickedFontsetbtn()
{
	// TODO: Add your control notification handler code here
	CFontDialog dlg;
	
	//CFontDialog로 현재 폰트 변경
	if(dlg.DoModal() == IDOK){
		color = dlg.GetColor();
		dlg.GetCurrentFont(&log);
		font.DeleteObject();
		font.CreateFontIndirect(&log);
		GetDlgItem(IDC_EDIT1)->SetFont(&font);
	}
}

HBRUSH CTextPadDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  Change any attributes of the DC here

	//폰트색을 변경하는 부분
	int nRet = pWnd->GetDlgCtrlID();
	if(nRet == IDC_EDIT1){
		pDC->SetTextColor(color);
	}

	// TODO:  Return a different brush if the default is not desired
	return hbr;
}

void CTextPadDlg::OnBnClickedNewbtn()
{
	// TODO: Add your control notification handler code here
	textpad.SetSel(0, -1,TRUE);
	textpad.Clear();
}
