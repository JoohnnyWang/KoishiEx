// DlgCanvas.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ExRabbit.h"
#include "DlgCanvas.h"
#include "afxdialogex.h"
#include "ExRabbitDlg.h"

// CDlgCanvas �Ի���

IMPLEMENT_DYNAMIC(CDlgCanvas, CDialogEx)

CDlgCanvas::CDlgCanvas(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgCanvas::IDD, pParent)
{

}

CDlgCanvas::~CDlgCanvas()
{
}

void CDlgCanvas::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgCanvas, CDialogEx)
	
END_MESSAGE_MAP()




