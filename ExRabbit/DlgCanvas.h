#pragma once


// CDlgCanvas �Ի���

class CDlgCanvas : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgCanvas)

public:
	CDlgCanvas(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgCanvas();

// �Ի�������
	enum { IDD = IDD_CANVAS_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	//afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};
