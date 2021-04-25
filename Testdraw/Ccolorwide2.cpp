// Ccolorwide2.cpp: 实现文件
//

#include "pch.h"
#include "Testdraw.h"
#include "Ccolorwide2.h"
#include "afxdialogex.h"


// Ccolorwide2 对话框

IMPLEMENT_DYNAMIC(Ccolorwide2, CDialogEx)

Ccolorwide2::Ccolorwide2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, R(0)
	, G(0)
	, B(0)
	, wide(0)
{

}

Ccolorwide2::~Ccolorwide2()
{
}

void Ccolorwide2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, R);
	DDX_Text(pDX, IDC_EDIT2, G);
	DDX_Text(pDX, IDC_EDIT3, B);
	DDX_Text(pDX, IDC_EDIT4, wide);
}


BEGIN_MESSAGE_MAP(Ccolorwide2, CDialogEx)
END_MESSAGE_MAP()


// Ccolorwide2 消息处理程序
