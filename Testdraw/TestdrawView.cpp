
// TestdrawView.cpp: CTestdrawView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Testdraw.h"
#endif

#include "TestdrawDoc.h"
#include "TestdrawView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestdrawView

IMPLEMENT_DYNCREATE(CTestdrawView, CView)

BEGIN_MESSAGE_MAP(CTestdrawView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CTestdrawView 构造/析构

CTestdrawView::CTestdrawView() noexcept
{
	// TODO: 在此处添加构造代码


	//圆的
	pGrayPen = new CPen(0, 1, RGB(100, 100, 100));
	pLinePen = new CPen(0, 1, RGB(250, 0, 0));   //在这里修改画出的圆的边缘的颜色！！！

	//手绘线的
	m_Dragging = 0;
	m_HCross = AfxGetApp()->LoadStandardCursor(IDC_CROSS);//载入标准的十字光标

}

CTestdrawView::~CTestdrawView()
{
}

BOOL CTestdrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CTestdrawView 绘图

void CTestdrawView::OnDraw(CDC* pDC)
{
	CTestdrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	if (pDoc->vex == 1) {
		CPen nPen(PS_SOLID, pDoc->line.m_wide, RGB(pDoc->line.m_R, pDoc->line.m_G, pDoc->line.m_B));//设置画笔参数
		CPen* oldPen = pDC->SelectObject(&nPen);//设置新画笔
		pDoc->line.draw2D(pDC);//画一条从刚才的点到新点的点的直线
		pDC->SelectObject(oldPen);//还原画笔
	};
	
	if (pDoc->vex == 2) {
		CPen nPen(PS_SOLID, 10, RGB(255, 255, 0));
		CPen* oldPen = pDC->SelectObject(&nPen);
		pDoc->line.drawpoint(pDC);

		pDC->SelectObject(oldPen);//还原画笔
	};
}


// CTestdrawView 打印

BOOL CTestdrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CTestdrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CTestdrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CTestdrawView 诊断

#ifdef _DEBUG
void CTestdrawView::AssertValid() const
{
	CView::AssertValid();
}

void CTestdrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestdrawDoc* CTestdrawView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestdrawDoc)));
	return (CTestdrawDoc*)m_pDocument;
}
#endif //_DEBUG


// CTestdrawView 消息处理程序


void CTestdrawView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonDown(nFlags, point);
	CTestdrawDoc * pDoc = GetDocument();
	if (pDoc->vex == 1) {
		pDoc->line.addpt(point);
	}
	if (pDoc->vex == 2) {
		pDoc->line.addpt_point(point);
	}
	if (pDoc->vex == 3) {
		m_bLButtonDown = TRUE; // 设左鼠标键按下为真
		m_pStart = point;
		SetCapture(); // 设置鼠标捕获
	}
	if (pDoc->vex == 4) {
		::SetCursor(m_HCross);//这一句能防止左键单击的时候，保持鼠标样式不变
		m_PointOrigin = point;
		m_PointOld = point;
		SetCapture();//捕获鼠标，充分控制鼠标
		m_Dragging = 1;
		RECT Rect;
		GetClientRect(&Rect);//取得窗口当前显示坐标
		ClientToScreen(&Rect);//转换为屏幕坐标
		::ClipCursor(&Rect);//限定光标在指定矩形了吗
		CView::OnLButtonDown(nFlags, point);
	}

	if (pDoc->vex == 5) {
		m_StartPoint = point; //用来保存画线起始点的位置，即鼠标左键第一次按下时的位置，类型为CPoint
	}


	Invalidate();
}



void CTestdrawView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CView::OnRButtonDown(nFlags, point);
	CTestdrawDoc* pDoc = GetDocument();
	if (pDoc->vex == 1) {
		pDoc->line.addpt(point);
		pDoc->line.pause(point);
	}
	Invalidate();
}


void CTestdrawView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CTestdrawDoc* pDoc = GetDocument();
	if (pDoc->vex == 3) {
		if (m_bLButtonDown == TRUE) {
			CDC* pDC = GetDC();// 获取设备上下文        
			pDC->SelectObject(pGrayPen);// 选取灰色笔
			pDC->SelectStockObject(NULL_BRUSH);
			pDC->SetROP2(R2_XORPEN);// 设置为异或绘图方式
			if (m_bErase) {// need to erase
				pDC->Ellipse(old_center.x - nRadius, old_center.y - nRadius,
					old_center.x + nRadius, old_center.y + nRadius);
			}

			else// 需要擦除为假
				m_bErase = TRUE;// 设需要擦除为真
			CPoint center;
			center.x = (float(m_pStart.x + point.x)) / 2;
			center.y = (float(m_pStart.y + point.y)) / 2;
			nRadius = sqrt((double)(point.y - m_pStart.y) * (point.y - m_pStart.y) +
				(point.x - m_pStart.x) * (point.x - m_pStart.x)) / 2;
			pDC->Ellipse(center.x - nRadius, center.y - nRadius,
				center.x + nRadius, center.y + nRadius);
			old_center = center;
			ReleaseDC(pDC);// 释放设备上下文
		}
	}

	if (pDoc->vex == 4) {
		::SetCursor(m_HCross);
		if (m_Dragging)
		{
			CClientDC ClientDC(this);
			ClientDC.SetROP2(R2_NOT);//逆转当前屏幕颜色来画线的绘图方式
			ClientDC.MoveTo(m_PointOrigin);
			ClientDC.LineTo(m_PointOld);//擦去上一次的线
			ClientDC.MoveTo(m_PointOrigin);
			ClientDC.LineTo(point);//绘制这一次的临时线
			m_PointOld = point;
		}
	}

	if (pDoc->vex == 5) {
		if (nFlags == MK_LBUTTON) //判断鼠标左键是否按下，如果按下，则移动时画线
		{
			CClientDC pDC(this);
			pDC.MoveTo(m_StartPoint);
			pDC.LineTo(point);
			m_StartPoint = point; //将画线的起点移动到鼠标移动后的点
		}
	}

	CView::OnMouseMove(nFlags, point);
}


void CTestdrawView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CTestdrawDoc* pDoc = GetDocument();
	if (pDoc->vex == 3) {
		//圆的
		ReleaseCapture();
		if (m_bLButtonDown) {
			CDC* pDC = GetDC(); // 获取设备上下文
		pDC->SelectStockObject(NULL_BRUSH);
		pDC->SelectObject(pLinePen); // 选择笔
		pDC->SetROP2(R2_COPYPEN); // 设置为覆盖绘图方式
		CPoint center; // 圆心
		//calculate the center
		center.x = (float(m_pStart.x + point.x)) / 2;
		center.y = (float(m_pStart.y + point.y)) / 2;
		// nRadius is a class member, double
		nRadius = sqrt(double(point.y - m_pStart.y) * (point.y - m_pStart.y) +
			(point.x - m_pStart.x) * (point.x - m_pStart.x)) / 2;
		pDC->Ellipse(center.x - nRadius, center.y - nRadius, center.x + nRadius, center.y + nRadius);
		ReleaseDC(pDC);// 释放设备上下文
		m_bLButtonDown = FALSE;// 重设左鼠标键按下为假
		m_bErase = FALSE;// 重需要擦除为假
		}
	}

	if (pDoc->vex == 4) {
		//手绘直线的
		if (m_Dragging)
		{
			m_Dragging = 0;
			::ReleaseCapture();//结束捕获鼠标
			::ClipCursor(NULL);//解锁鼠标
			CClientDC ClientDC(this);
			ClientDC.SetROP2(R2_NOT);
			ClientDC.MoveTo(m_PointOrigin);
			ClientDC.LineTo(m_PointOld);//擦去上一次的临时线
			ClientDC.SetROP2(R2_COPYPEN);//缺省绘图模式，像素为画笔颜色
			ClientDC.MoveTo(m_PointOrigin);
			ClientDC.LineTo(point);//绘制固定线
		}
	}

	if (pDoc->vex == 5) {
		CDC pDC;
		CPen pen(PS_SOLID, pDoc->HRline.m_wide, RGB(pDoc->HRline.m_R, pDoc->HRline.m_G, pDoc->HRline.m_B)); //建立一个画笔类对象，构造时设置画笔属性
		pDC.m_hDC = ::GetDC(m_hWnd);
		pDC.SelectObject(&pen);
		pDC.MoveTo(m_StartPoint);
		pDC.LineTo(point);
		::ReleaseDC(m_hWnd, pDC.m_hDC);
	}

	CView::OnLButtonUp(nFlags, point);
}
