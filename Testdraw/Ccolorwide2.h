#pragma once


// Ccolorwide2 对话框

class Ccolorwide2 : public CDialogEx
{
	DECLARE_DYNAMIC(Ccolorwide2)

public:
	Ccolorwide2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Ccolorwide2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int R;
	int G;
	int B;
	int wide;
};
