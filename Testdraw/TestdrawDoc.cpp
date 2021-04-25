
// TestdrawDoc.cpp: CTestdrawDoc 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "Testdraw.h"
#endif

#include "TestdrawDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CTestdrawDoc

IMPLEMENT_DYNCREATE(CTestdrawDoc, CDocument)

BEGIN_MESSAGE_MAP(CTestdrawDoc, CDocument)
	ON_COMMAND(ID_32771, &CTestdrawDoc::On32771)
	ON_COMMAND(ID_32772, &CTestdrawDoc::On32772)
	ON_COMMAND(ID_32773, &CTestdrawDoc::On32773)
	ON_COMMAND(ID_32776, &CTestdrawDoc::On32776)
	ON_COMMAND(ID_32774, &CTestdrawDoc::On32774)
	ON_COMMAND(ID_32775, &CTestdrawDoc::On32775)
	ON_COMMAND(ID_32777, &CTestdrawDoc::On32777)
	ON_COMMAND(ID_32778, &CTestdrawDoc::On32778)
END_MESSAGE_MAP()


// CTestdrawDoc 构造/析构

CTestdrawDoc::CTestdrawDoc() noexcept
{
	// TODO: 在此添加一次性构造代码

}

CTestdrawDoc::~CTestdrawDoc()
{
}

BOOL CTestdrawDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// CTestdrawDoc 序列化

void CTestdrawDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO:  在此添加存储代码
	}
	else
	{
		// TODO:  在此添加加载代码
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CTestdrawDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CTestdrawDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CTestdrawDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CTestdrawDoc 诊断

#ifdef _DEBUG
void CTestdrawDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTestdrawDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CTestdrawDoc 命令

#include"Ccolorwide.h"
void CTestdrawDoc::On32771()
{
	// TODO: 在此添加命令处理程序代码
	Ccolorwide dlg;
	if (dlg.DoModal() != IDOK)return;
	dlg.DoModal();

	line.SetColor(dlg.R, dlg.G, dlg.B);
	line.m_wide = dlg.wide;
}


void CTestdrawDoc::On32772()
{
	// TODO: 在此添加命令处理程序代码
	vex = 1;
}


void CTestdrawDoc::On32773()
{
	// TODO: 在此添加命令处理程序代码
	vex = 2;
}


void CTestdrawDoc::On32776()
{
	// TODO: 在此添加命令处理程序代码
	vex = 3;
}

#include"Ccolorwide2.h"
void CTestdrawDoc::On32774()
{
	// TODO: 在此添加命令处理程序代码
	Ccolorwide2 dlg;
	if (dlg.DoModal() != IDOK)return;
	dlg.DoModal();

	Hline.SetColor(dlg.R, dlg.G, dlg.B);
	Hline.m_wide = dlg.wide;
}


void CTestdrawDoc::On32775()
{
	// TODO: 在此添加命令处理程序代码
	vex = 4;
}


void CTestdrawDoc::On32777()
{
	// TODO: 在此添加命令处理程序代码
	
	Ccolorwide3 dlg;
	if (dlg.DoModal() != IDOK)return;
	dlg.DoModal();

	HRline.SetColor(dlg.R, dlg.G, dlg.B);
	HRline.m_wide = dlg.wide;
	
}


void CTestdrawDoc::On32778()
{
	// TODO: 在此添加命令处理程序代码
	vex = 5;
}