// DrawPad.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "HS_Pad.h"
#include "DrawPad.h"
#include "HS_PadDoc.h"
#include "HS_PadView.h"


// CDrawPad ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CDrawPad, CDialog)

CDrawPad::CDrawPad(CWnd* pParent /*=NULL*/)
		: CDialog(CDrawPad::IDD, pParent)
{
}


void CDrawPad::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDrawPad, CDialog)
	ON_WM_PAINT()
//	ON_WM_LBUTTONDOWN()
//	ON_WM_LBUTTONUP()
//	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// CDrawPad �޽��� ó�����Դϴ�.

void CDrawPad::OnPaint()
{
	CPaintDC dc(this); // device context for painting
 // TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.

	



}

//void CDrawPad::OnLButtonDown(UINT nFlags, CPoint point)
//{
//	
//	m_drawset = true;
//	pnt = point;
//	CDialog::OnLButtonDown(nFlags, point);
//}
//
//void CDrawPad::OnLButtonUp(UINT nFlags, CPoint point)
//{
//	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
//	if(m_drawset){
//		
//		CRect r;
//		GetDlgItem(IDC_STAGE)->GetWindowRect(r);
//		
//		dc->MoveTo(pnt);
//		dc->LineTo(point);
//		pnt = point;
//	}
//	CDialog::OnLButtonUp(nFlags, point);
//}
//
//void CDrawPad::OnMouseMove(UINT nFlags, CPoint point)
//{
//	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
//	m_drawset=false;
//	CDialog::OnMouseMove(nFlags, point);
//}
