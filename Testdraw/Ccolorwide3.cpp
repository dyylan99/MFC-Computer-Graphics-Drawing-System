// Ccolorwide3.cpp: 实现文件
//

#include "pch.h"
#include "Testdraw.h"
#include "Ccolorwide3.h"
#include "afxdialogex.h"


// Ccolorwide3 对话框

IMPLEMENT_DYNAMIC(Ccolorwide3, CDialogEx)

Ccolorwide3::Ccolorwide3(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	, R(0)
	, G(0)
	, B(0)
	, wide(0)
{

}

Ccolorwide3::~Ccolorwide3()
{
}

void Ccolorwide3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, R);
	DDX_Text(pDX, IDC_EDIT2, G);
	DDX_Text(pDX, IDC_EDIT3, B);
	DDX_Text(pDX, IDC_EDIT4, wide);
}


BEGIN_MESSAGE_MAP(Ccolorwide3, CDialogEx)
END_MESSAGE_MAP()


// Ccolorwide3 消息处理程序
