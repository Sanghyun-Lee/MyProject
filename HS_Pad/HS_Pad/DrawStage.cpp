// DrawStage.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "HS_Pad.h"
#include "DrawStage.h"


// CDrawStage

IMPLEMENT_DYNAMIC(CDrawStage, CStatic)

CDrawStage::CDrawStage()
{

}

CDrawStage::~CDrawStage()
{
}


BEGIN_MESSAGE_MAP(CDrawStage, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CDrawStage 메시지 처리기입니다.



void CDrawStage::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	
	dc.LineTo(100, 100);
	dc.MoveTo(200,200);

}
