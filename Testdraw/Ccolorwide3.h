#pragma once


// Ccolorwide3 对话框

class Ccolorwide3 : public CDialogEx
{
	DECLARE_DYNAMIC(Ccolorwide3)

public:
	Ccolorwide3(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Ccolorwide3();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
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
