
// MFCweek11Doc.h : CMFCweek11Doc ��Ľӿ�
//


#pragma once
#include "MFCweek11Set.h"


class CMFCweek11Doc : public CDocument
{
protected: // �������л�����
	CMFCweek11Doc();
	DECLARE_DYNCREATE(CMFCweek11Doc)

// ����
public:
	CMFCweek11Set m_MFCweek11Set;

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
	virtual ~CMFCweek11Doc();
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
