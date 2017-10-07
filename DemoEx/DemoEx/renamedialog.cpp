// renamedialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DemoEx.h"
#include "renamedialog.h"
#include "afxdialogex.h"
#include "DemoExDlg.h"

// renamedialog �Ի���

IMPLEMENT_DYNAMIC(renamedialog, CDialogEx)

renamedialog::renamedialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(renamedialog::IDD, pParent)
{

}

renamedialog::~renamedialog()
{
}

void renamedialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_e1);
	DDX_Control(pDX, IDC_EDIT2, m_e2);
}


BEGIN_MESSAGE_MAP(renamedialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &renamedialog::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &renamedialog::OnBnClickedCancel)
END_MESSAGE_MAP()


// renamedialog ��Ϣ�������

extern void CStrToStr(CString cstr,str &str1);
void renamedialog::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	NPKobject* no = (NPKobject*)para;
	int i = *(int*)para2;
	CDemoExDlg* dlg = (CDemoExDlg*)para3;
	str fn;
	CString cs;
	m_e2.GetWindowText(cs);
	CStrToStr(cs, fn);
	no->IMGrename(i, fn);
	ShowWindow(SW_HIDE);
	dlg->update1();
}


void renamedialog::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ShowWindow(SW_HIDE);
}
