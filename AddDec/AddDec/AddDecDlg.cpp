
// AddDecDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "AddDec.h"
#include "AddDecDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CAddDecDlg 对话框



CAddDecDlg::CAddDecDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CAddDecDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAddDecDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAddDecDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_BN_CLICKED(IDC_Btn_Add, &CAddDecDlg::OnBtnAdd)
	ON_BN_CLICKED(IDC_Btn_Initial, &CAddDecDlg::OnBtnInitial)
	ON_BN_CLICKED(IDC_Btn_Dec, &CAddDecDlg::OnBtnDec)
	ON_STN_CLICKED(IDC_Display, &CAddDecDlg::OnDisplay)
	ON_EN_CHANGE(IDC_Input, &CAddDecDlg::OnChangeInput)
END_MESSAGE_MAP()


// CAddDecDlg 消息处理程序

BOOL CAddDecDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CAddDecDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CAddDecDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CAddDecDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAddDecDlg::OnBtnAdd()
{
	// TODO:  在此添加控件通知处理程序代码
	num++;
	UpdateData(TRUE);//刷新控件值到对应的变量，通常用于输入时，此处该句可去除
	CString Strtemp;
	Strtemp.Format("%d", num); //将加 1 或减 1 运算后的 NumberDisplay 变量
	//转换成十进制字符
	GetDlgItem(IDC_Display)->SetWindowText(Strtemp);//在 IDC_Display 处输出显示；
	// 上句也可写成 SetDlgItemText(IDC_Display, Strtemp);
	UpdateData(FALSE);//将变量刷新到控件显示，通常用于输出
}


void CAddDecDlg::OnBtnInitial()
{
	// TODO:  在此添加控件通知处理程序代码
	num = 0;
	UpdateData(TRUE);//刷新控件值到对应的变量，通常用于输入时，此处该句可去除
	CString Strtemp;
	Strtemp.Format("%d", num); //将加 1 或减 1 运算后的 NumberDisplay 变量
	//转换成十进制字符
	GetDlgItem(IDC_Display)->SetWindowText(Strtemp);//在 IDC_Display 处输出显示；
	// 上句也可写成 SetDlgItemText(IDC_Display, Strtemp);
	UpdateData(FALSE);//将变量刷新到控件显示，通常用于输出
}


void CAddDecDlg::OnBtnDec()
{
	// TODO:  在此添加控件通知处理程序代码
	num--;
	UpdateData(TRUE);//刷新控件值到对应的变量，通常用于输入时，此处该句可去除
	CString Strtemp;
	Strtemp.Format("%d", num); //将加 1 或减 1 运算后的 NumberDisplay 变量
	//转换成十进制字符
	GetDlgItem(IDC_Display)->SetWindowText(Strtemp);//在 IDC_Display 处输出显示；
	// 上句也可写成 SetDlgItemText(IDC_Display, Strtemp);
	UpdateData(FALSE);//将变量刷新到控件显示，通常用于输出
}


void CAddDecDlg::OnDisplay()
{
	// TODO:  在此添加控件通知处理程序代码
	
}


void CAddDecDlg::OnChangeInput()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
	CString Strtemp;//定义字符串变量
	UpdateData(TRUE);// 刷新控件值到对应的变量
	//从 IDC_EDIT_Input 编辑框获得字符给 Strtemp
	GetDlgItem(IDC_Input)->GetWindowText(Strtemp);
	num = atoi(Strtemp); //Strtemp 转换成整数给 NumberDisplay
	//继续在静态文本 IDC_Display 处显示 NumberDisplay
	Strtemp.Format("%d", num); //将变量转换成十进制字符
	GetDlgItem(IDC_Display)->SetWindowText(Strtemp);//在 IDC_Display 处输出显示；
	UpdateData(FALSE);// 将变量刷新到控件进行显示
}
