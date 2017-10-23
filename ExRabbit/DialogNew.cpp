// DialogNew.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ExRabbit.h"
#include "DialogNew.h"
#include "afxdialogex.h"
#include "ExRabbitDlg.h"

// CDialogNew �Ի���

IMPLEMENT_DYNAMIC(CDialogNew, CDialogEx)

CDialogNew::CDialogNew(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialogNew::IDD, pParent)
{

}

CDialogNew::~CDialogNew()
{
}

void CDialogNew::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, m_ch1);
	DDX_Control(pDX, IDC_CHECK2, m_ch2);
	DDX_Control(pDX, IDC_CHECK3, m_ch3);
	DDX_Control(pDX, IDC_CHECK4, m_ch4);
	DDX_Control(pDX, IDC_CHECK7, m_ch5);
	DDX_Control(pDX, IDC_CHECK8, m_ch6);
	DDX_Control(pDX, IDC_EDIT1, m_ed1);
}


BEGIN_MESSAGE_MAP(CDialogNew, CDialogEx)
	ON_BN_CLICKED(IDC_CHECK1, &CDialogNew::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &CDialogNew::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK3, &CDialogNew::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK4, &CDialogNew::OnBnClickedCheck4)
	ON_BN_CLICKED(IDC_CHECK7, &CDialogNew::OnBnClickedCheck7)
	ON_BN_CLICKED(IDC_CHECK8, &CDialogNew::OnBnClickedCheck8)
	ON_BN_CLICKED(IDOK, &CDialogNew::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CDialogNew::OnBnClickedCancel)
END_MESSAGE_MAP()


// CDialogNew ��Ϣ�������


void CDialogNew::OnBnClickedCheck1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_ch1.SetCheck(true);
	m_ch2.SetCheck(false);
	m_ch3.SetCheck(false);
	m_ch4.SetCheck(false);
	m_ch5.SetCheck(false);
	m_ch6.SetCheck(false);
	CString info = L"�½�һ��NPK�ļ���\r\n";
	info += L"�½�һ���������κ�IMG��NPK�ļ�������Ҫ�����������Ҫ���ⲿIMG�ļ���";
	m_ed1.SetWindowText(info);
}


void CDialogNew::OnBnClickedCheck2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_ch1.SetCheck(false);
	m_ch2.SetCheck(true);
	m_ch3.SetCheck(false);
	m_ch4.SetCheck(false);
	m_ch5.SetCheck(false);
	m_ch6.SetCheck(false);
	CString info = L"�½�һ��ƴ�Ϸ�����\r\n";
	info += L"ƴ�Ϸ�����������NPK��һ�ֽṹ����ͬ���ǣ�ϵͳ�������ڲ�IMGΪͼ�㣬�Ӷ�����IMG˳����ʾ������ͼ��\r\n";
	info += L"��������IMG��������ÿ��ͼ�����Ϣ��Ȼ��ͨ�������ȷ�����ƴ�ϵ�Ч����\r\n";
	m_ed1.SetWindowText(info);
}


void CDialogNew::OnBnClickedCheck3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_ch1.SetCheck(false);
	m_ch2.SetCheck(false);
	m_ch3.SetCheck(true);
	m_ch4.SetCheck(false);
	m_ch5.SetCheck(false);
	m_ch6.SetCheck(false);
	CString info = L"�½�һ���汾��Ϊ2��IMG�ļ���\r\n";
	info += L"V2�����ó̶�����IMG�ļ������Դ洢�������͵�ͼƬ����ռ�ռ�ϴ�\r\n";
	info += L"������ʹ��V2����ͼ����ӡ��滻��ƴ�ϵȲ��������ҳ����Ǽ��������������������ص��£�ִ����һ���ɹ��ġ�\r\n";
	info += L"����������һ��V2��IMG�ļ�������Ҫ���������ͼ�ļ���";
	m_ed1.SetWindowText(info);
}


void CDialogNew::OnBnClickedCheck4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_ch1.SetCheck(false);
	m_ch2.SetCheck(false);
	m_ch3.SetCheck(false);
	m_ch4.SetCheck(true);
	m_ch5.SetCheck(false);
	m_ch6.SetCheck(false);
	CString info = L"�½�һ���汾��Ϊ4��IMG�ļ���\r\n";
	info += L"V4��ʱװ���õ�IMG�ļ����Ե�ɫ��������ʽ�洢ͼ��\r\n";
	info += L"������ʹ��V4������ɫ�༭�Ȳ����������ͼ����Ҳͬ��֧�֣���������ͼ��ɫ����Ļ����ִ��ʧ�ܡ�\r\n";
	info += L"����������һ��V4��IMG�ļ�������Ҫ���������ͼ�ļ��͵�ɫ����Ϣ�����ǽ�����ʹ��������ʽ�����ͼ��";
	m_ed1.SetWindowText(info);
}


void CDialogNew::OnBnClickedCheck7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_ch1.SetCheck(false);
	m_ch2.SetCheck(false);
	m_ch3.SetCheck(false);
	m_ch4.SetCheck(false);
	m_ch5.SetCheck(true);
	m_ch6.SetCheck(false);
	CString info = L"�½�һ���汾��Ϊ5��IMG�ļ���\r\n";
	info += L"V5�Ǵ󲿷ּ�����Ч���õ�IMG�ļ�����DDS��ʽ�洢��ͼ�������������÷�ʽת����ÿ��ͼƬ֡��Сͼ��\r\n";
	info += L"������ʹ��V5�ļ�����DDS������������ʹ���ֳɵ�DDS��ͼ������ӡ��滻����������֧�ֽ�PNG��ͼת��ΪDDS��������ʧ�棬Ӧ���á�\r\n";
	info += L"����������һ��V5��IMG�ļ�������Ҫ�������DDS��ͼ����ͨ����������DDS����Լ���Χ��������ͨ��֡��ͼ��";
	m_ed1.SetWindowText(info);
}


void CDialogNew::OnBnClickedCheck8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_ch1.SetCheck(false);
	m_ch2.SetCheck(false);
	m_ch3.SetCheck(false);
	m_ch4.SetCheck(false);
	m_ch5.SetCheck(false);
	m_ch6.SetCheck(true);
	CString info = L"�½�һ���汾��Ϊ6��IMG�ļ���\r\n";
	info += L"V6������������ͬ����ɫ�岻ͬ������V4��϶��ɵ�����壬���㷺Ӧ���ڶ�����ɫ�汾��ʱװ�ļ���\r\n";
	info += L"������ʹ��V6�ļ�������ɫ������������ʽ��V4���ƣ�ʹ��V6����������һ��V4��ͬ��״����ͬ��ɫ��ʽ��IMG��\r\n";
	info += L"����������һ��V6��IMG�ļ�������Ҫ���������ɫ��������������V4������������������Ч�����⣬������ʹ�������ͼ���ܡ�";
	m_ed1.SetWindowText(info);
}


void CDialogNew::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CExRabbitDlg*dlg = (CExRabbitDlg*)GetParent();
	if(m_ch1.GetCheck()){
		dlg->no.release();
		dlg->no.create();
		dlg->fileNPKname = L"��δ�����NPK";
		dlg->fileOpen = true;
		dlg->updateIMGlist();
	}else if(m_ch2.GetCheck()){
		//ʩ����
		MessageBox(L"ʩ����");
	}else if(m_ch3.GetCheck()){
		dlg->no.release();
		dlg->no.create();
		dlg->io.Release();
		dlg->io.Create(V2);
		dlg->fileIMGname = L"new.img";
		dlg->fileNPKname = L"��ʱNPK";
		dlg->fileOpen = true;
		dlg->no.IMGpush(dlg->io, "new.img");
		dlg->switchIMGver(dlg->io.version);
		dlg->updateIMGlist();
		dlg->updatePIClist();
		dlg->updateCLRlist();
		dlg->updateDDSlist();
		dlg->updateNPKInfo();
		dlg->updateIMGInfo();
		dlg->updatePICInfo();
	}else if(m_ch4.GetCheck()){
		dlg->no.release();
		dlg->no.create();
		dlg->io.Release();
		dlg->io.Create(V4);
		dlg->fileIMGname = L"new.img";
		dlg->fileNPKname = L"��ʱNPK";
		dlg->fileOpen = true;
		dlg->no.IMGpush(dlg->io, "new.img");
		dlg->switchIMGver(dlg->io.version);
		dlg->updateIMGlist();
		dlg->updatePIClist();
		dlg->updateCLRlist();
		dlg->updateDDSlist();
		dlg->updateNPKInfo();
		dlg->updateIMGInfo();
		dlg->updatePICInfo();
	}else if(m_ch5.GetCheck()){
		dlg->no.release();
		dlg->no.create();
		dlg->io.Release();
		dlg->io.Create(V5);
		dlg->fileIMGname = L"new.img";
		dlg->fileNPKname = L"��ʱNPK";
		dlg->fileOpen = true;
		dlg->no.IMGpush(dlg->io, "new.img");
		dlg->switchIMGver(dlg->io.version);
		dlg->updateIMGlist();
		dlg->updatePIClist();
		dlg->updateCLRlist();
		dlg->updateDDSlist();
		dlg->updateNPKInfo();
		dlg->updateIMGInfo();
		dlg->updatePICInfo();
	}else if(m_ch6.GetCheck()){
		dlg->no.release();
		dlg->no.create();
		dlg->io.Release();
		dlg->io.Create(V6);
		dlg->fileIMGname = L"new.img";
		dlg->fileNPKname = L"��ʱNPK";
		dlg->fileOpen = true;
		dlg->no.IMGpush(dlg->io, "new.img");
		dlg->switchIMGver(dlg->io.version);
		dlg->updateIMGlist();
		dlg->updatePIClist();
		dlg->updateCLRlist();
		dlg->updateDDSlist();
		dlg->updateNPKInfo();
		dlg->updateIMGInfo();
		dlg->updatePICInfo();
	}
	dlg->m_lIMG.SetSelectionMark(0);
	dlg->crtIMGid = 0;
	ShowWindow(SW_HIDE);
}


void CDialogNew::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ShowWindow(SW_HIDE);
}
