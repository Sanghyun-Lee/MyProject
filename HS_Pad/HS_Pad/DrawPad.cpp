// DrawPad.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "HS_Pad.h"
#include "DrawPad.h"
#include "HS_PadDoc.h"
#include "HS_PadView.h"


// CDrawPad 대화 상자입니다.

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


// CDrawPad 메시지 처리기입니다.

void CDrawPad::OnPaint()
{
	CPaintDC dc(this); // device context for painting
 // TODO: 여기에 메시지 처리기 코드를 추가합니다.

	



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
//	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
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
//	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
//	m_drawset=false;
//	CDialog::OnMouseMove(nFlags, point);
//}
