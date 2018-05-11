
// AddDecDlg.h : 头文件
//

#pragma once


// CAddDecDlg 对话框
class CAddDecDlg : public CDialogEx
{
// 构造
public:
	CAddDecDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_ADDDEC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBtnAdd();
	int num;
	afx_msg void OnBtnInitial();
	afx_msg void OnBtnDec();
	afx_msg void OnDisplay();
	afx_msg void OnChangeInput();
};
