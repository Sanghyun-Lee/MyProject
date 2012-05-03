// Hs_PadDoc.cpp : CHs_PadDoc 클래스의 구현
//

#include "stdafx.h"
#include "Hs_Pad.h"

#include "Hs_PadDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHs_PadDoc

IMPLEMENT_DYNCREATE(CHs_PadDoc, CDocument)

BEGIN_MESSAGE_MAP(CHs_PadDoc, CDocument)
END_MESSAGE_MAP()


// CHs_PadDoc 생성/소멸

CHs_PadDoc::CHs_PadDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CHs_PadDoc::~CHs_PadDoc()
{
}

BOOL CHs_PadDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CHs_PadDoc serialization

void CHs_PadDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}


// CHs_PadDoc 진단

#ifdef _DEBUG
void CHs_PadDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHs_PadDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CHs_PadDoc 명령
