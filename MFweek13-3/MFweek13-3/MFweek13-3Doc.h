
// MFweek13-3Doc.h : CMFweek133Doc ��Ľӿ�
//


#pragma once
#include "MFweek13-3Set.h"


class CMFweek133Doc : public CDocument
{
protected: // �������л�����
	CMFweek133Doc();
	DECLARE_DYNCREATE(CMFweek133Doc)

// ����
public:
	CMFweek133Set m_MFweek133Set;

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
	virtual ~CMFweek133Doc();
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
