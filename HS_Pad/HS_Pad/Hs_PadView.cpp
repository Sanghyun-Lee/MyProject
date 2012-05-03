// Hs_PadView.cpp : CHs_PadView 클래스의 구현
//

#include "stdafx.h"
#include "Hs_Pad.h"

#include "Hs_PadDoc.h"
#include "Hs_PadView.h"
#include "TextPadDlg.h"
#include "UrlSearchDlg.h"
#include "DrawPadDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHs_PadView

IMPLEMENT_DYNCREATE(CHs_PadView, CView)

BEGIN_MESSAGE_MAP(CHs_PadView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_URL, &CHs_PadView::OnUrl)
	ON_COMMAND(ID_TEXTPAD, &CHs_PadView::OnTextpad)
	ON_COMMAND(ID_DRAWPAD, &CHs_PadView::OnDrawpad)
END_MESSAGE_MAP()

// CHs_PadView 생성/소멸

CHs_PadView::CHs_PadView()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	UrlSearchDlg = NULL;
	TextPadDlg = NULL;
	DrawPadDlg = NULL;
}

CHs_PadView::~CHs_PadView()
{
}

BOOL CHs_PadView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CHs_PadView 그리기

void CHs_PadView::OnDraw(CDC* /*pDC*/)
{
	CHs_PadDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CHs_PadView 인쇄

BOOL CHs_PadView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CHs_PadView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CHs_PadView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CHs_PadView 진단

#ifdef _DEBUG
void CHs_PadView::AssertValid() const
{
	CView::AssertValid();
}

void CHs_PadView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHs_PadDoc* CHs_PadView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHs_PadDoc)));
	return (CHs_PadDoc*)m_pDocument;
}
#endif //_DEBUG


// CHs_PadView 메시지 처리기

void CHs_PadView::OnUrl()
{
	// TODO: Add your command handler code here
	UrlSearchDlg = new CUrlSearchDlg();
	UrlSearchDlg->m_pView = this;
	UrlSearchDlg->Create(IDD_URLSEARCHDLG);
	UrlSearchDlg->ShowWindow(SW_SHOW);
	
}

void CHs_PadView::OnTextpad()
{
	// TODO: Add your command handler code here
	TextPadDlg = new CTextPadDlg();
	TextPadDlg->m_pView = this;
	TextPadDlg->Create(IDD_TEXTPADDLG);
	TextPadDlg->ShowWindow(SW_SHOW);
}

void CHs_PadView::OnDrawpad()
{
	// TODO: Add your command handler code here
	DrawPadDlg = new CDrawPadDlg();
	DrawPadDlg->m_pView = this;
	DrawPadDlg->Create(IDD_DRAWPADDLG);
	DrawPadDlg->ShowWindow(SW_SHOW);
}
