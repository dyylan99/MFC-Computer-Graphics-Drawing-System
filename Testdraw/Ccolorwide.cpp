// Ccolorwide.cpp: 实现文件
//

#include "pch.h"
#include "Testdraw.h"
#include "Ccolorwide.h"
#include "afxdialogex.h"


// Ccolorwide 对话框

IMPLEMENT_DYNAMIC(Ccolorwide, CDialogEx)

Ccolorwide::Ccolorwide(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, R(0)
	, G(0)
	, B(0)
	, wide(0)
{

}

Ccolorwide::~Ccolorwide()
{
}

void Ccolorwide::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, R);
	DDX_Text(pDX, IDC_EDIT2, G);
	DDX_Text(pDX, IDC_EDIT3, B);
	DDX_Text(pDX, IDC_EDIT4, wide);
}


BEGIN_MESSAGE_MAP(Ccolorwide, CDialogEx)
END_MESSAGE_MAP()


// Ccolorwide 消息处理程序
