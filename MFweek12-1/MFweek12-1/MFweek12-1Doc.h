
// MFweek12-1Doc.h : CMFweek121Doc ��Ľӿ�
//


#pragma once
#include "MFweek12-1Set.h"


class CMFweek121Doc : public CDocument
{
protected: // �������л�����
	CMFweek121Doc();
	DECLARE_DYNCREATE(CMFweek121Doc)

// ����
public:
	CMFweek121Set m_MFweek121Set;

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
	virtual ~CMFweek121Doc();
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
