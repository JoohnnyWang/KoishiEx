// DlgBar.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ExRabbit.h"
#include "DlgBar.h"
#include "afxdialogex.h"


// CDlgBar �Ի���

IMPLEMENT_DYNAMIC(CDlgBar, CDialogEx)

CDlgBar::CDlgBar(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgBar::IDD, pParent)
{

}

CDlgBar::~CDlgBar()
{
}

void CDlgBar::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_title);
	DDX_Control(pDX, IDC_EDIT2, m_info);
	DDX_Control(pDX, IDC_PROGRESS1, m_pg);
}


BEGIN_MESSAGE_MAP(CDlgBar, CDialogEx)
END_MESSAGE_MAP()


// CDlgBar ��Ϣ�������


BOOL CDlgBar::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_pg.SetRange32(0,1000);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
