// CMFCAppInputDlg.cpp : 実装ファイル
//

#include "pch.h"
#include "MFCApplication3.h"
#include "CMFCAppInputDlg.h"
#include "afxdialogex.h"
#include "IAppCommand.h"
#include "CAddItemCommand.h"
#include "CEditDataCommand.h"
#include "CPerson.h"
// CMFCAppInputDlg ダイアログ

IMPLEMENT_DYNAMIC(CMFCAppInputDlg, CDialog)

CMFCAppInputDlg::CMFCAppInputDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_MFCAPPLICATION_INPUT_DIALOG, pParent)
{}

CMFCAppInputDlg::~CMFCAppInputDlg()
{}

void CMFCAppInputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BOOL CMFCAppInputDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	this->OnListDataUpdate();

	return true;
}


BEGIN_MESSAGE_MAP(CMFCAppInputDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_ADD_NEW_DATA, &CMFCAppInputDlg::OnBnClickedButtonAddNewData)
	ON_LBN_SELCHANGE(IDC_LIST_ITEM, &CMFCAppInputDlg::OnLbnSelchangeListItem)
	ON_BN_CLICKED(IDC_BUTTON_ADD_RELATION, &CMFCAppInputDlg::OnBnClickedButtonAddRelation)
	ON_BN_CLICKED(ID_UPDATE_CHANGE, &CMFCAppInputDlg::OnBnClickedUpdateChange)
END_MESSAGE_MAP()


// CMFCAppInputDlg メッセージ ハンドラー

//追加ボタンに対するイベントハンドラ
void CMFCAppInputDlg::OnBnClickedButtonAddNewData()
{
	CPerson factory;
	IAppCommand* Command = new CAddItemCommand((VOID*)(this->m_PersonInfo.GetPersonListPtr()), (VOID*)(&factory));
	DWORD DataIndex = 0;
	Command->Execute((VOID*)(&DataIndex));
	delete Command;

	this->OnListDataUpdate();
}

//リストボックスの表示内容を更新する。
void CMFCAppInputDlg::OnListDataUpdate()
{
	CListBox* PersonListBox = (CListBox*)GetDlgItem(IDC_LIST_ITEM);
	//リストボックスの内容を、全て削除する。
	PersonListBox->ResetContent();

	for (INT_PTR Index = 0; Index < this->m_PersonInfo.GetCount(); Index++) {
		CPerson* PersonItem = (CPerson*)this->m_PersonInfo.GetPerson(Index);
		CString ListItem = PersonItem->GetFamilyName() + CString(_T(" - ")) + PersonItem->GetFirstName();
		PersonListBox->AddString(ListItem);
	}
}

//リストボックスでの選択項目が変更された際のイベントハンドラ
void CMFCAppInputDlg::OnLbnSelchangeListItem()
{
	CListBox* PersonListBox = (CListBox*)GetDlgItem(IDC_LIST_ITEM);
	int CurSelIndex = PersonListBox->GetCurSel();
	CPerson* CurSelPerson = (CPerson*)this->m_PersonInfo.GetPerson(CurSelIndex);

	CEdit* TargetEdit = (CEdit*)GetDlgItem(IDC_EDIT_FAMILY_NAME);
	TargetEdit->SetWindowTextA(CurSelPerson->GetFamilyName());

	TargetEdit = (CEdit*)GetDlgItem(IDC_EDIT_FIRST_NAME);
	TargetEdit->SetWindowTextA(CurSelPerson->GetFirstName());

	TargetEdit = (CEdit*)GetDlgItem(IDC_EDIT_AGE);
	CString Age;
	Age.Format(_T("%d"), CurSelPerson->GetAge());
	TargetEdit->SetWindowTextA(Age);

	TargetEdit = (CEdit*)GetDlgItem(IDC_EDIT_SEX);
	CString Sex;
	Sex.Format(_T("%s"), CurSelPerson->GetSex() == 1 ? _T("男性") : _T("女性"));
	TargetEdit->SetWindowTextA(Sex);
}

//「関係の追加」ボタンに対するイベントハンドラ
void CMFCAppInputDlg::OnBnClickedButtonAddRelation()
{
	CListBox* PersonListBox = (CListBox*)GetDlgItem(IDC_LIST_ITEM);
	int CurSelIndex = PersonListBox->GetCurSel();
	CPerson* Item = this->m_PersonInfo.GetAt(CurSelIndex);

	//子データのコピーを生成
	CPersonInfo TargetPersonInfo;
	for (INT_PTR Index = 0; Index < Item->GetRelations().GetCount(); Index++) {
		CPerson* NewItem = new CPerson(Item->GetRelations().GetAt(Index));//ここでコピーが生成される
		TargetPersonInfo.Add(Index, NewItem);
	}

	IAppCommand* Command = new CEditDataCommand();
	CMFCAppInputDlg DialogToShow;
	DialogToShow.SetPersonInfo(TargetPersonInfo);
	INT_PTR DialogOkCancel = DialogToShow.DoModal();
	if (IDOK == DialogOkCancel) {
		const CPersonInfo& EditedPersonInfo = DialogToShow.GetPersonInfo();
		Item->CopyRelations(*(EditedPersonInfo.GetPersonListPtr()));
	}
	delete Command;
}

//個人情報のセットアップ
void CMFCAppInputDlg::SetPersonInfo(const CPersonInfo& SrcData)
{
	this->m_PersonInfo.RemoveAll();

	for (INT_PTR Index = 0; Index < SrcData.GetCount(); Index++) {
		CPerson* PersonItem = SrcData.GetAt(Index);
		this->m_PersonInfo.Add(Index, PersonItem->CreateCopy());
	}
}

void CMFCAppInputDlg::OnBnClickedUpdateChange()
{
	CListBox* PersonListBox = (CListBox*)GetDlgItem(IDC_LIST_ITEM);
	int CurSelIndex = PersonListBox->GetCurSel();
	CPerson* Item = this->m_PersonInfo.GetAt(CurSelIndex);

	CString EditWindowText;
	//苗字反映
	CEdit* EditControl = (CEdit*)GetDlgItem(IDC_EDIT_FAMILY_NAME);
	EditControl->GetWindowTextA(EditWindowText);
	Item->SetFamilyName(EditWindowText);

	//名前反映
	EditControl = (CEdit*)GetDlgItem(IDC_EDIT_FIRST_NAME);
	EditControl->GetWindowTextA(EditWindowText);
	Item->SetFirstName(EditWindowText);

	//年齢反映
	EditControl = (CEdit*)GetDlgItem(IDC_EDIT_AGE);
	EditControl->GetWindowTextA(EditWindowText);
	DWORD Age = _ttoi(EditWindowText);
	Item->SetAge(Age);

	//性別
	EditControl = (CEdit*)GetDlgItem(IDC_EDIT_SEX);
	EditControl->GetWindowTextA(EditWindowText);
	if (EditWindowText == CString(_T("男性"))) {
		Item->SetSex(CPerson::PERSON_SEX_TYPE_MALE);
	}
	else if (EditWindowText == CString(_T("女性"))) {
		Item->SetSex(CPerson::PERSON_SEX_TYPE_FEMALE);
	}
	else {
		Item->SetSex(CPerson::PERSON_SEX_TYPE_MIDDLE);
	}
}
