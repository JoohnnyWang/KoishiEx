// DlgMix.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ExRabbit.h"
#include "DlgMix.h"
#include "afxdialogex.h"


// CDlgMix �Ի���

IMPLEMENT_DYNAMIC(CDlgMix, CDialogEx)

CDlgMix::CDlgMix(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgMix::IDD, pParent)
{

}

CDlgMix::~CDlgMix()
{
}

void CDlgMix::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_e1);
	DDX_Control(pDX, IDC_LIST1, m_l1);
}


BEGIN_MESSAGE_MAP(CDlgMix, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgMix::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &CDlgMix::OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgMix ��Ϣ�������


BOOL CDlgMix::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CDlgMix::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CDlgMix::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ShowWindow(SW_HIDE);
}
