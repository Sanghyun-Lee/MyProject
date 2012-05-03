#pragma once


// CDrawStage

class CDrawStage : public CStatic
{
	DECLARE_DYNAMIC(CDrawStage)

public:
	CDrawStage();
	virtual ~CDrawStage();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};


