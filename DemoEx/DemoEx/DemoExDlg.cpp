
// DemoExDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DemoEx.h"
#include "DemoExDlg.h"
#include "afxdialogex.h"
#include "../../KoishiEx/KoishiBase.cpp"
#include "../../KoishiEx/Koishidata.cpp"
#include "../../KoishiEx/Koishifactory.cpp"
#include "../../KoishiEx/sha256.cpp"
#include "../../KoishiEx/dds.cpp"
#include "renamedialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDemoExDlg �Ի���




CDemoExDlg::CDemoExDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDemoExDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDemoExDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_e1);
	DDX_Control(pDX, IDC_EDIT2, m_e2);
	DDX_Control(pDX, IDC_EDIT3, m_e3);
	DDX_Control(pDX, IDC_LIST1, m_l1);
	DDX_Control(pDX, IDC_LIST2, m_l2);
	DDX_Control(pDX, IDC_EDIT4, m_e4);
}

BEGIN_MESSAGE_MAP(CDemoExDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL13, &CDemoExDlg::OnBnClickedCancel13)
	ON_BN_CLICKED(IDCANCEL8, &CDemoExDlg::OnBnClickedCancel8)
	ON_BN_CLICKED(IDCANCEL7, &CDemoExDlg::OnBnClickedCancel7)
	ON_BN_CLICKED(IDCANCEL4, &CDemoExDlg::OnBnClickedCancel4)
	ON_BN_CLICKED(IDCANCEL5, &CDemoExDlg::OnBnClickedCancel5)
	ON_BN_CLICKED(IDCANCEL6, &CDemoExDlg::OnBnClickedCancel6)
	ON_BN_CLICKED(IDCANCEL3, &CDemoExDlg::OnBnClickedCancel3)
	ON_BN_CLICKED(IDCANCEL14, &CDemoExDlg::OnBnClickedCancel14)
	ON_BN_CLICKED(IDCANCEL15, &CDemoExDlg::OnBnClickedCancel15)
	ON_BN_CLICKED(IDCANCEL16, &CDemoExDlg::OnBnClickedCancel16)
	ON_BN_CLICKED(IDCANCEL12, &CDemoExDlg::OnBnClickedCancel12)
	ON_BN_CLICKED(IDCANCEL2, &CDemoExDlg::OnBnClickedCancel2)
	ON_BN_CLICKED(IDCANCEL9, &CDemoExDlg::OnBnClickedCancel9)
	ON_BN_CLICKED(IDCANCEL10, &CDemoExDlg::OnBnClickedCancel10)
	ON_BN_CLICKED(IDCANCEL11, &CDemoExDlg::OnBnClickedCancel11)
	ON_BN_CLICKED(IDCANCEL, &CDemoExDlg::OnBnClickedCancel)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CDemoExDlg::OnNMClickList1)
	ON_NOTIFY(NM_CLICK, IDC_LIST2, &CDemoExDlg::OnNMClickList2)
	ON_BN_CLICKED(IDC_BUTTON1, &CDemoExDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDemoExDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDemoExDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CDemoExDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CDemoExDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CDemoExDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CDemoExDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CDemoExDlg::OnBnClickedButton8)
END_MESSAGE_MAP()


// CDemoExDlg ��Ϣ�������

BOOL CDemoExDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_l1.EasyInsertColumn(L"IMG����,150,IMG��С,80,IMGƫ����,80");
	m_l2.EasyInsertColumn(L"֡��,40,��ʽ,100,�ߴ�,80,��׼��,80,ͼ���С,80");
	m_l1.SetExtendedStyle(m_l1.GetExtendedStyle()|LVS_EX_ONECLICKACTIVATE|LVS_EX_FULLROWSELECT);
	m_l2.SetExtendedStyle(m_l2.GetExtendedStyle()|LVS_EX_ONECLICKACTIVATE|LVS_EX_FULLROWSELECT);
	m_e1.SetWindowText(L"���һ��NPK�ļ�����");
	m_e2.SetWindowText(L"���һ��IMG�ļ��������ߴ��Ѵ򿪵�NPK�ļ���ѡ��һ��IMG����");

	csd.Create(IDD_DIALOG1, this);
	csd.ShowWindow(SW_NORMAL);
	csd.para = this;
	rd.Create(IDD_DIALOG2, this);
	rd.para3 = this;
	base.set(0,0);
	csd.m_e1.SetWindowText(L"0");
	csd.m_e2.SetWindowText(L"0");
	csd.m_sp1.SetRange32(-999,999);
	csd.m_sp2.SetRange32(-999,999);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CDemoExDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CDemoExDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//////////////////////////////////////////////////////
//֧��
//////////////////////////////////////////////////////
void CStrToStr(CString cstr,str &str1)  
{  
    int n = cstr.GetLength(); //���ַ����㣬str�ĳ���  
    int len = WideCharToMultiByte(CP_ACP,0,cstr,n,NULL,0,NULL,NULL);//��Byte����str����  
    char *pChStr = new char[len+1];//���ֽ�Ϊ��λ  
    WideCharToMultiByte(CP_ACP,0,cstr,n,pChStr,len,NULL,NULL);//���ֽ�ת��Ϊ���ֽڱ���  
    pChStr[len] = '\0';//��Ҫ����ĩβ������־  
  
    str1 = pChStr;  
    delete []pChStr;  
}
CString StrToCStr(str str1){
	return CString(str1.c_str());
}
CString NumToCStr(int n){
	CString s;
	s.Format(L"%d",n);
	return s;
}
CString shorten(CString str1){
	int i = str1.ReverseFind('/');
	CString s = str1.Right(str1.GetLength()-i-1);
	return s;
}
CString PtToCStr(point pt){
	CString s;
	s.Format(L"(%d��%d)",pt.get_X(), pt.get_Y());
	return s;
}
CString SzToCStr(size pt){
	CString s;
	s.Format(L"%d��%d",pt.get_W(), pt.get_H());
	return s;
}
CString FmtToCStr(colorFormat cf, IMGversion iv = V2){
	CString s;
	switch(cf){
	case ARGB8888:
		s = L"ARGB8888";
		break;
	case ARGB4444:
		s = L"ARGB4444";
		break;
	case ARGB1555:
		if(iv == V2){
			s = L"ARGB1555";
		}else{
			s = L"������ɫ";
		}
		break;
	case LINK:
		s = L"ָ��֡��";
		break;
	case DDS_DXT1:
		s = L"DDS_DXT1";
		break;
	case DDS_DXT3:
		s = L"DDS_DXT3";
		break;
	case DDS_DXT5:
		s = L"DDS_DXT5";
		break;
	default:
		s = L"��δ����";
		break;
	}
	return s;
}

void CDemoExDlg::OnBnClickedCancel13()
{
	// TODO: �����յ�NPK
	no.create();
	update1();
}


void CDemoExDlg::OnBnClickedCancel8()
{
	// TODO: ��NPK
	CString defExt = _T("NPK�ļ�(*.NPK)|*.NPK");
	CString extFilter = _T("NPK�ļ�(*.NPK)|*.NPK||");
	CFileDialog dlg(true, defExt, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,extFilter, this);
	CString fileName;
	str fn;
	if(dlg.DoModal() == IDOK){
		fileName = dlg.GetPathName();
		CStrToStr(fileName, fn);
		no.release();
		if(no.loadFile(fn)){
			MessageBox(L"��ȡ�������");
		}else{
			MessageBox(L"��ȡʧ������");
		}
		m_e1.SetWindowText(L"NPK�ļ�����"+fileName+L"\r\n�ѵ���"+NumToCStr(no.count)+"��IMG�ļ���");
		update1();
	}
}


void CDemoExDlg::OnBnClickedCancel7()
{
	// TODO: ����NPK
	CString defExt = _T("NPK�ļ�(*.NPK)|*.NPK");
	CString extFilter = _T("NPK�ļ�(*.NPK)|*.NPK||");
	CFileDialog dlg(false, defExt, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,extFilter, this);
	CString fileName;
	str fn;
	if(dlg.DoModal() == IDOK){
		fileName = dlg.GetPathName();
		CStrToStr(fileName, fn);
		if(no.saveFile(fn)){
			MessageBox(_T("�����������"));
		}else{
			MessageBox(_T("����ʧ������"));
		}
	}
}


void CDemoExDlg::OnBnClickedCancel4()
{
	// TODO: �����ⲿIMG
	CString defExt = _T("IMG�ļ�(*.IMG)|*.IMG");
	CString extFilter = _T("IMG�ļ�(*.IMG)|*.IMG||");
	CFileDialog dlg(true, defExt, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,extFilter, this);
	CString fileName;
	str fn;
	if(dlg.DoModal() == IDOK){
		fileName = dlg.GetPathName();
		CStrToStr(fileName, fn);
		IMGobject _io;
		_io.loadFile(fn);
		if(no.IMGpush(_io, fn)){
			MessageBox(L"�����������");
		}else{
			MessageBox(L"����ʧ������");
		}
		_io.release();
		update1();
	}
}


void CDemoExDlg::OnBnClickedCancel5()
{
	// TODO: ɾ��ѡ��IMG
	int row = m_l1.GetSelectionMark();
	if(row == -1){
		MessageBox(L"ѡ��һ��IMG����");
		return;
	}
	if(no.IMGremove(row)){
		MessageBox(L"ɾ���������");
	}else{
		MessageBox(L"ɾ��ʧ������");
	}
	update1();
}


void CDemoExDlg::OnBnClickedCancel6()
{
	// TODO: ������IMG
	int row = m_l1.GetSelectionMark();
	if(row == -1){
		MessageBox(L"ѡ��һ��IMG����");
		return;
	}
	rd.m_e1.SetWindowText(StrToCStr(no.content[row].get_imgname()));
	rd.m_e2.SetWindowText(StrToCStr(no.content[row].get_imgname()));
	rd.para = &no;
	rd.para2 = &row;
	rd.ShowWindow(SW_SHOW);
}


void CDemoExDlg::OnBnClickedCancel3()
{
	// TODO: �����յ�IMG
	io.release();
	io.create();
	m_e2.SetWindowText(L"���������δ�����IMG��~");
	update2();
}


void CDemoExDlg::OnBnClickedCancel14()
{
	// TODO: ��IMG
	CString defExt = _T("IMG�ļ�(*.IMG)|*.IMG");
	CString extFilter = _T("IMG�ļ�(*.IMG)|*.IMG||");
	CFileDialog dlg(true, defExt, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,extFilter, this);
	CString fileName,info;
	str fn;
	if(dlg.DoModal() == IDOK){
		fileName = dlg.GetPathName();
		CStrToStr(fileName, fn);
		io.release();
		if(io.loadFile(fn)){
			MessageBox(L"��ȡ�������");
		}else{
			MessageBox(L"��ȡʧ������");
		}
		info = fileName;
		m_e2.SetWindowText(info);
		update2();
	}
}


void CDemoExDlg::OnBnClickedCancel15()
{
	// TODO: ����IMG
	CString defExt = _T("IMG�ļ�(*.IMG)|*.IMG");
	CString extFilter = _T("IMG�ļ�(*.IMG)|*.IMG||");
	CFileDialog dlg(false, defExt, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,extFilter, this);
	CString fileName;
	str fn;
	if(dlg.DoModal() == IDOK){
		fileName = dlg.GetPathName();
		CStrToStr(fileName, fn);
		if(io.saveFile(fn)){
			MessageBox(_T("�����������"));
		}else{
			MessageBox(_T("����ʧ������"));
		}
	}
}


void CDemoExDlg::OnBnClickedCancel16()
{
	// TODO: ת���汾
	switch(io.version){
	case V2:
		if(IDOK==MessageBox(L"����ת��ΪV4����������")){
			CString defExt = _T("IMG�ļ�(*.IMG)|*.IMG");
			CString extFilter = _T("IMG�ļ�(*.IMG)|*.IMG||");
			CFileDialog dlg(false, defExt, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,extFilter, this);
			CString fileName;
			str fn;
			if(dlg.DoModal() == IDOK){
				fileName = dlg.GetPathName();
				CStrToStr(fileName, fn);
				IMGobject _io;
				if(io.convertTo(V4,_io)){
					if(_io.saveFile(fn)){
						MessageBox(_T("����ΪV4�汾������"));
					}else{
						MessageBox(L"����ʧ��������");
					}
				}else{
					MessageBox(_T("ת��ʧ����������ɫ����̫��������"));
				}
				_io.release();
			}
		}
		break;
	case V4:
		if(IDOK==MessageBox(L"����ת��ΪV2����������")){
			CString defExt = _T("IMG�ļ�(*.IMG)|*.IMG");
			CString extFilter = _T("IMG�ļ�(*.IMG)|*.IMG||");
			CFileDialog dlg(false, defExt, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,extFilter, this);
			CString fileName;
			str fn;
			if(dlg.DoModal() == IDOK){
				fileName = dlg.GetPathName();
				CStrToStr(fileName, fn);
				IMGobject _io;
				if(io.convertTo(V2,_io)){
					if(_io.saveFile(fn)){
						MessageBox(_T("����ΪV2�汾������"));
					}else{
						MessageBox(L"����ʧ��������");
					}
				}else{
					MessageBox(_T("ת��ʧ��������"));
				}
				_io.release();
			}
		}
		break;
	case V6:
		switch(MessageBox(L"�����ת��ΪV2�������ת��ΪV4����ȡ��������\r\nע��V6ת����V2����V4��ת���ɺܶ��ļ�����������",L"ѯ����",MB_YESNOCANCEL)){
		case IDYES:
			{
				CString defExt = _T("IMG�ļ�(*.IMG)|*.IMG");
				CString extFilter = _T("IMG�ļ�(*.IMG)|*.IMG||");
				CFileDialog dlg(false, defExt, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,extFilter, this);
				CString fileName,tempName;
				str fn;
				if(dlg.DoModal() == IDOK){
					fileName = dlg.GetPathName();
					IMGobject _io;
					int clct = io.paletteData.getCount();
					for(int i = 0;i<clct;i++){
						io.convertTo(V2,_io,i);
						tempName = fileName.Left(fileName.GetLength()-4) + L"("+NumToCStr(i+1)+L").IMG";
						CStrToStr(tempName, fn);
						_io.saveFile(fn);
						_io.release();
					}
					MessageBox(L"�洢��"+NumToCStr(clct)+L"��V2�ļ�����");
				}
			}
			break;
		case IDNO:
			{
				CString defExt = _T("IMG�ļ�(*.IMG)|*.IMG");
				CString extFilter = _T("IMG�ļ�(*.IMG)|*.IMG||");
				CFileDialog dlg(false, defExt, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,extFilter, this);
				CString fileName,tempName;
				str fn;
				if(dlg.DoModal() == IDOK){
					fileName = dlg.GetPathName();
					IMGobject _io;
					int clct = io.paletteData.getCount();
					for(int i = 0;i<clct;i++){
						io.convertTo(V4,_io,i);
						tempName = fileName.Left(fileName.GetLength()-4) + L"("+NumToCStr(i+1)+L").IMG";
						CStrToStr(tempName, fn);
						_io.saveFile(fn);
						_io.release();
					}
					MessageBox(L"�洢��"+NumToCStr(clct)+L"��V4�ļ�����");
				}
			}
			break;
		default:
			break;
		}
		break;
	default:
		MessageBox(L"������ʶ������汾�ۣ�");
		break;
	}
}


void CDemoExDlg::OnBnClickedCancel12()
{
	// TODO: ��ȡ����PNG
	CString defExt = _T("pngͼ��(*.png)|*.png");
	CString extFilter = _T("pngͼ��(*.png)|*.png||");
	CFileDialog dlg(false, defExt, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,extFilter, this);
	CString fileName, tempName;
	str fn;
	int i,j;
	if(dlg.DoModal() == IDOK){
		fileName = dlg.GetPathName();
		matrix _mat;
		if(io.version == V2 || io.version == V4 || io.version == V5){
			for(i=0;i<io.count;i++){
				io.PICextract(i, _mat);
				tempName = fileName.Left(fileName.GetLength()-4) + L"-ID"+NumToCStr(i)+L".png";
				CStrToStr(tempName, fn);
				_mat.makePNG(fn);
				_mat.release();
			}
			MessageBox(_T("��ȡ�������"));
		}
		if(io.version == V6){
			int clct = io.paletteData.getCount();
			if(MessageBox(_T("���IMG��V6��������")+NumToCStr(clct)+L"����ɫ������������������")==IDOK){
				for(i = 0;i<clct;i++){
					for(j=0;j<io.count;j++){
						io.PICextract(j, _mat, i);
						tempName = fileName.Left(fileName.GetLength()-4) + L"("+NumToCStr(i+1)+L")-ID"+NumToCStr(j)+L".png";
						CStrToStr(tempName, fn);
						_mat.makePNG(fn);
						_mat.release();
					}
				}
				MessageBox(_T("��ȡ�������"));
			}else{
				return;
			}
		}
	}
}


void CDemoExDlg::OnBnClickedCancel2()
{
	// TODO: ������ͼ֡
	if(io.version != V2 && io.version != V4){
		MessageBox(L"ֻ֧��V2��V4�Ĳ�����ͼ��������");
		return;
	}
	CString defExt = _T("pngͼ��(*.png)|*.png");
	CString extFilter = _T("pngͼ��(*.png)|*.png||");
	CFileDialog dlg(true, defExt, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,extFilter, this);
	CString fileName,info;
	str fn;
	if(dlg.DoModal() == IDOK){
		fileName = dlg.GetPathName();
		CStrToStr(fileName, fn);
		matrix _mat;
		stream _s;
		PICinfo _po;
		_mat.loadPNG(fn);
		if(!io.PICpreprocess(_mat, _s, _po)){
			MessageBox(L"ʧ����������������ɫ̫����������");
		}else{
			if(io.PICpush(_po, _s)){
				MessageBox(L"����ɹ�����������Ҫ�Լ����������֡������");
			}else{
				MessageBox(L"ʧ���������������������");
			}
		}
		_s.release();
		_mat.release();
		update2();
	}
}


void CDemoExDlg::OnBnClickedCancel9()
{
	// TODO: �滻��ͼ
	int row = m_l2.GetSelectionMark();
	if(row == -1){
		MessageBox(L"ѡ��һ֡����");
		return;
	}
	if(io.version != V2 && io.version != V4){
		MessageBox(L"ֻ֧��V2��V4���滻��ͼ��������");
		return;
	}
	CString defExt = _T("pngͼ��(*.png)|*.png");
	CString extFilter = _T("pngͼ��(*.png)|*.png||");
	CFileDialog dlg(true, defExt, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,extFilter, this);
	CString fileName,info;
	str fn;
	if(dlg.DoModal() == IDOK){
		fileName = dlg.GetPathName();
		CStrToStr(fileName, fn);
		matrix _mat;
		stream _s;
		PICinfo _po;
		_mat.loadPNG(fn);
		io.PICInfo(row, _po);
		if(!io.PICpreprocess(_mat, _s, _po)){
			MessageBox(L"ʧ����������������ɫ̫����������");
		}else{
			if(io.PICreplace(row, _po, _s)){
				MessageBox(L"�滻�ɹ�����������Ҫ�Լ����������֡������");
			}else{
				MessageBox(L"ʧ���������������������");
			}
		}
		_s.release();
		_mat.release();
		update2();
	}
}


void CDemoExDlg::OnBnClickedCancel10()
{
	// TODO: ɾ��ѡ��֡
	int row = m_l2.GetSelectionMark();
	if(row == -1){
		MessageBox(L"ѡ��һ֡����");
		return;
	}
	if(io.PICremove(row)){
		MessageBox(L"ɾ���������");
	}else{
		MessageBox(L"ɾ��ʧ������");
	}
	update2();
}


void CDemoExDlg::OnBnClickedCancel11()
{
	// TODO: ��ȡPNG
	int row = m_l2.GetSelectionMark();
	if(row == -1){
		MessageBox(L"ѡ��һ֡����");
		return;
	}
	CString defExt = _T("pngͼ��(*.png)|*.png");
	CString extFilter = _T("pngͼ��(*.png)|*.png||");
	CFileDialog dlg(false, defExt, NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,extFilter, this);
	CString fileName, tempName;
	str fn;
	if(dlg.DoModal() == IDOK){
		fileName = dlg.GetPathName();
		CStrToStr(fileName, fn);
		matrix _mat;
		if(io.version == V2 || io.version == V4 || io.version == V5){
			io.PICextract(row, _mat);
			if(_mat.makePNG(fn)){
				MessageBox(_T("��ȡ�������"));
			}else{
				MessageBox(_T("��ȡʧ������"));
			}
			_mat.release();
		}
		if(io.version == V6){
			int clct = io.paletteData.getCount();
			if(MessageBox(_T("���IMG��V6��������")+NumToCStr(clct)+L"����ɫ������������������")==IDOK){
				for(int i = 0;i<clct;i++){
					io.PICextract(row, _mat, i);
					tempName = fileName.Left(fileName.GetLength()-4) + L"("+NumToCStr(i+1)+L").png";
					CStrToStr(tempName, fn);
					_mat.makePNG(fn);
					_mat.release();
				}
				MessageBox(_T("��ȡ�������"));
			}else{
				return;
			}
		}
	}
}


void CDemoExDlg::OnBnClickedCancel()
{
	// TODO: �˳�
	CDialogEx::OnCancel();
}



void CDemoExDlg::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	int row = pNMListView->iItem;
	if(row>=0){
		CString info;
		io.release();
		no.IMGextract(row, io);
		info = StrToCStr(no.content[row].get_imgname()) + L" �������NPK��";
		m_e2.SetWindowText(info);
		update2();
	}
	*pResult = 0;
}


void CDemoExDlg::OnNMClickList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	draw();
	update3();
	*pResult = 0;
}

void CDemoExDlg::update1(){
	m_l1.DeleteAllItems();
	for(int i = 0;i<no.count;i++){
		m_l1.EasyInsertItem(shorten(StrToCStr(no.content[i].get_imgname()))+L","+NumToCStr(no.content[i].get_imgsize())+L","+NumToCStr(no.content[i].get_imgoffset()));
	}
}
void CDemoExDlg::update2(){
	CString info = L"";
	info += L"�汾��"+NumToCStr(io.version)+L"\r\n";
	info += L"֡����"+NumToCStr(io.count)+L"\r\n";
	info += L"�������С��"+NumToCStr(io.indexSize)+L"\r\n";
	if(io.version == V4){
		info += L"��ɫ���"+NumToCStr(io.paletteData[0].size());
	}
	if(io.version == V6){
		info += L"��ɫ��Ϸ���������"+NumToCStr(io.paletteData.getCount());
		csd.m_c1.ResetContent();
		for(int i = 0;i<io.paletteData.getCount();i++){
			csd.m_c1.AddString(L"����"+NumToCStr(i+1));
		}
		if(io.paletteData.getCount()>0){
			csd.m_c1.SetCurSel(0);
			csd.m_c1.EnableWindow(true);
		}
	}else{
		csd.m_c1.ResetContent();
		csd.m_c1.AddString(L"��V6������");
		csd.m_c1.EnableWindow(false);
		csd.m_c1.SetCurSel(0);
	}
	m_e3.SetWindowText(info);
	m_l2.DeleteAllItems();
	for(int i = 0;i<io.count;i++){
		info = L"";
		info += NumToCStr(i)+L",";
		info += FmtToCStr(io.content[i].get_format(), io.version);
		if(io.content[i].get_format() == LINK){
			info += L":"+ NumToCStr(io.content[i].get_linkTo());
		}
		info += L",";
		info += SzToCStr(io.content[i].get_picSize())+L",";
		info += PtToCStr(io.content[i].get_basePt())+L",";
		info += NumToCStr(io.content[i].get_dataSize());
		m_l2.EasyInsertItem(info);
	}
}
void CDemoExDlg::update3(){
	int row = m_l2.GetSelectionMark();
	if(row == -1){
		return;
	}
	CString info = L"";
	info += L"��׼�㣺(";
	info += NumToCStr(io.content[row].get_basePt().get_X())+L",";
	info += NumToCStr(io.content[row].get_basePt().get_Y())+L")\r\n";
	info += L"֡��";
	info += NumToCStr(io.content[row].get_frmSize().get_W())+L"��";
	info += NumToCStr(io.content[row].get_frmSize().get_H());
	m_e4.SetWindowText(info);
}
void CDemoExDlg::draw(){
	int row = m_l2.GetSelectionMark();
	if(row == -1){
		return;
	}

	int i,j,tx,ty;
	CImage img;

	matrix mat, canvas;
	color clr;
	canvas.allocate(240,240);
	canvas.fill(color(0xff,0x33,0x33,0x33));

	PICinfo po;
	io.PICInfo(row, po);
	io.PICextract(row, mat, csd.m_c1.GetCurSel());
	if(csd.m_ch1.GetCheck()){
		for(i=0;i<240;i++){
			for(j=0;j<240;j++){
				tx = i-po.get_basePt().get_X()-base.get_X();	//��ʵ����
				ty = j-po.get_basePt().get_Y()-base.get_Y();	//��������
				if(tx<mat.getRowCount() && ty<mat.getColumnCount()){
					clr = mat.getElem(tx,ty);
					clr.mixWith(canvas.getElem(i,j),LAY);
					canvas.setElem(i, j, clr);
				}
			}
		}
	}else{
		for(i=0;i<240;i++){
			for(j=0;j<240;j++){
				if(i<mat.getRowCount() && j<mat.getColumnCount()){
					clr = mat.getElem(i,j);
					clr.mixWith(canvas.getElem(i,j),LAY);
					canvas.setElem(i, j, clr);
				}
			}
		}
	}

	int clct,cp;
	if(io.version == V4){
		clct = io.paletteData[0].size();
		for(i=237;i<240;i++){
			for(j=0;j<clct;j++){
				canvas.setElem(i, 240-3*clct+3*j+0, io.paletteData[0][j]);
				canvas.setElem(i, 240-3*clct+3*j+1, io.paletteData[0][j]);
				canvas.setElem(i, 240-3*clct+3*j+2, io.paletteData[0][j]);
			}
		}
	}
	if(io.version == V6){
		cp = io.paletteData.getCount();
		for(i=0;i<cp;i++){
			clct = io.paletteData[csd.m_c1.GetCurSel()].size();
			for(j=0;j<clct;j++){
				canvas.setElem(240-3*cp+3*i+0, 240-3*clct+3*j+0, io.paletteData[i][j]);
				canvas.setElem(240-3*cp+3*i+0, 240-3*clct+3*j+1, io.paletteData[i][j]);
				canvas.setElem(240-3*cp+3*i+0, 240-3*clct+3*j+2, io.paletteData[i][j]);
				canvas.setElem(240-3*cp+3*i+1, 240-3*clct+3*j+0, io.paletteData[i][j]);
				canvas.setElem(240-3*cp+3*i+1, 240-3*clct+3*j+1, io.paletteData[i][j]);
				canvas.setElem(240-3*cp+3*i+1, 240-3*clct+3*j+2, io.paletteData[i][j]);
				canvas.setElem(240-3*cp+3*i+2, 240-3*clct+3*j+0, io.paletteData[i][j]);
				canvas.setElem(240-3*cp+3*i+2, 240-3*clct+3*j+1, io.paletteData[i][j]);
				canvas.setElem(240-3*cp+3*i+2, 240-3*clct+3*j+2, io.paletteData[i][j]);
			}
		}
	}
	img.Create(240, 240, 32);
	UCHAR* pst = (UCHAR*)img.GetBits();
	int pit = img.GetPitch();

	for(i=0;i<240;i++){
		for(j=0;j<240;j++){
			*(pst + pit*j + 4*i + 0) = canvas[j][i].get_B();
			*(pst + pit*j + 4*i + 1) = canvas[j][i].get_G();
			*(pst + pit*j + 4*i + 2) = canvas[j][i].get_R();
		}
	}
	img.Draw(csd.GetDC()->m_hDC,5,5);
	img.Destroy();
	mat.release();
	canvas.release();
}


void CDemoExDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int row = m_l2.GetSelectionMark();
	if(row == -1){
		return;
	}
	io.PICparaModify(row, BASEX, io.content[row].get_basePt().get_X()-1);
	draw();
	update3();
}


void CDemoExDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int row = m_l2.GetSelectionMark();
	if(row == -1){
		return;
	}
	io.PICparaModify(row, BASEX, io.content[row].get_basePt().get_X()+1);
	draw();
	update3();
}


void CDemoExDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int row = m_l2.GetSelectionMark();
	if(row == -1){
		return;
	}
	io.PICparaModify(row, BASEY, io.content[row].get_basePt().get_Y()-1);
	draw();
	update3();
}


void CDemoExDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
		int row = m_l2.GetSelectionMark();
	if(row == -1){
		return;
	}
	io.PICparaModify(row, BASEY, io.content[row].get_basePt().get_Y()+1);
	draw();
	update3();
}


void CDemoExDlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int row = m_l2.GetSelectionMark();
	if(row == -1){
		return;
	}
	io.PICparaModify(row, FRAMEW, io.content[row].get_frmSize().get_W()+1);
	draw();
	update3();
}


void CDemoExDlg::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int row = m_l2.GetSelectionMark();
	if(row == -1){
		return;
	}
	io.PICparaModify(row, FRAMEW, io.content[row].get_frmSize().get_W()-1);
	draw();
	update3();
}


void CDemoExDlg::OnBnClickedButton7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int row = m_l2.GetSelectionMark();
	if(row == -1){
		return;
	}
	io.PICparaModify(row, FRAMEH, io.content[row].get_frmSize().get_H()+1);
	draw();
	update3();
}


void CDemoExDlg::OnBnClickedButton8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int row = m_l2.GetSelectionMark();
	if(row == -1){
		return;
	}
	io.PICparaModify(row, FRAMEH, io.content[row].get_frmSize().get_H()-1);
	draw();
	update3();
}
