
// MFweek13-1Doc.h : CMFweek131Doc ��Ľӿ�
//


#pragma once
#include "MFweek13-1Set.h"


class CMFweek131Doc : public CDocument
{
protected: // �������л�����
	CMFweek131Doc();
	DECLARE_DYNCREATE(CMFweek131Doc)

// ����
public:
	CMFweek131Set m_MFweek131Set;

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CMFweek131Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
