
// TestdrawView.h: CTestdrawView 类的接口
//

#pragma once


class CTestdrawView : public CView
{
protected: // 仅从序列化创建
	CTestdrawView() noexcept;
	DECLARE_DYNCREATE(CTestdrawView)

// 特性
public:
	CTestdrawDoc* GetDocument() const;
	
	//圆的
	bool m_bLButtonDown;
	bool m_bErase;
	CPen* pGrayPen;
	CPen* pLinePen;
	CPoint old_center;
	CPoint m_pStart;
	int nRadius;
	
	//手绘直线的
	int m_Dragging;
	HCURSOR m_HCross;
	CPoint m_PointOld;
	CPoint m_PointOrigin;

	//手绘曲线的
	CPoint m_StartPoint;


// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CTestdrawView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // TestdrawView.cpp 中的调试版本
inline CTestdrawDoc* CTestdrawView::GetDocument() const
   { return reinterpret_cast<CTestdrawDoc*>(m_pDocument); }
#endif

