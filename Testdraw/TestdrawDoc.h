
// TestdrawDoc.h: CTestdrawDoc 类的接口
//


#pragma once
#include<vector>
using namespace std;

class CLine {
public:
	CLine() {
		m_R = 0, m_G = 0, m_B = 0, m_wide = 1;//如没有设置参数时的默认参数
	};
	~CLine() {};
	
	int m_R, m_G, m_B, m_wide;//线的基本要素
	vector <CPoint> pts,pts_point;

	void SetColor(int r, int g, int b) {
		m_R = r;
		m_G = g;
		m_B = b;
	}

	void addpt(CPoint pt) {
		pts.push_back(pt);
	}

	void delpt(int idx) {
		pts.erase(pts.begin() + idx);
	}

	void draw2D(CDC * pDC) {
		//两点之间画线
		for (int i = 0; i < pts.size(); i++) {
			pDC->MoveTo(pts[i]);
			if ((i + 1) < pts.size()) {
				pDC->LineTo(pts[i + 1]);
			}
		}
	}

	void pause(CPoint pt) {
		//暂停两点之间画线
		pts.pop_back();
	}

	void drawpoint(CDC* pDC) {
		//用一段非常小的有宽度的线段来表示点
		for (int i = 0; i < pts_point.size(); i++) {
			pDC->MoveTo(pts_point[i]);
			if ((i + 1) < pts_point.size()) {
				pDC->LineTo(pts_point[i]);
			}
		}
	}

	void addpt_point(CPoint pt) {
		pts_point.push_back(pt);
	}
};

class CHLine {
	//手绘线类
public:
	CHLine() {
		m_R = 100, m_G = 234, m_B = 0, m_wide = 3;//如没有设置参数时的默认参数
	};
	~CHLine() {};

	int m_R, m_G, m_B, m_wide;//线的基本要素
	vector <CPoint> pts;

	void SetColor(int r, int g, int b) {
		m_R = r;
		m_G = g;
		m_B = b;
	}
};


#include"Ccolorwide3.h"
class CHRLine {
	//手绘曲线类
public:
	CHRLine() {
		m_R = 100, m_G = 234, m_B = 0, m_wide = 3;//如没有设置参数时的默认参数
	};
	~CHRLine() {};

	int m_R, m_G, m_B, m_wide;//线的基本要素
	vector <CPoint> ptss;

	void SetColor(int r, int g, int b) {
		m_R = r;
		m_G = g;
		m_B = b;
	}
};


#include <afxtempl.h>
class CTestdrawDoc : public CDocument
{
protected: // 仅从序列化创建
	CTestdrawDoc() noexcept;
	DECLARE_DYNCREATE(CTestdrawDoc)

// 特性
public:
	CLine line;
	CHLine Hline;
	CHRLine HRline;

	int vex;//用于区别画不同种类的线

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~CTestdrawDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void On32771();
	afx_msg void On32772();
	afx_msg void On32773();
	afx_msg void On32776();
	afx_msg void On32774();
	afx_msg void On32775();
	afx_msg void On32777();
	afx_msg void On32778();
};
