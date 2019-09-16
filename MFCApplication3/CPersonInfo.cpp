#include "pch.h"
#include "CPersonInfo.h"

CPersonInfo::~CPersonInfo()
{
	for (INT_PTR Index = 0; Index < this->m_PersonList.GetCount(); Index++) {
		CPerson* PersonItem = this->m_PersonList.GetAt(Index);
		delete PersonItem;
	}
	this->m_PersonList.RemoveAll();
}

//新規にデータを追加する。
//新規に追加するデータは、初期データ。
void CPersonInfo::Add(DWORD DataIndex)
{
	this->Add(DataIndex, &CPerson());
}

//新規にデータを追加する。
//追加するデータは、引数で指定された値。
void CPersonInfo::Add(DWORD DataIndex, CPerson* NewPerson)
{
	this->m_PersonList.InsertAt(DataIndex, NewPerson);
}

//指定された番号の要素を返す。
CPerson* CPersonInfo::GetAt(DWORD DataIndex) const
{
	return this->m_PersonList.GetAt(DataIndex);
}

//指定された番号の情報を返す。
const CPerson* CPersonInfo::GetPerson(DWORD DataIndex)
{
	TRY {
		return this->m_PersonList.GetAt(DataIndex);
	}
	CATCH(CInvalidArgException, ex) {
		THROW(ex);
	}
	END_CATCH
}

//既存のデータを配列から削除する。
void CPersonInfo::Remove(DWORD DataIndex)
{
	CPerson* RemoveItem = this->m_PersonList.GetAt(DataIndex);
	delete RemoveItem;

	this->m_PersonList.RemoveAt(DataIndex);
}

//既存のデータをすべて削除する。
void CPersonInfo::RemoveAll()
{
	for (INT_PTR Index = 0; Index < this->m_PersonList.GetCount(); Index++) {
		CPerson* RemoveItem = this->m_PersonList.GetAt(Index);
		delete RemoveItem;
	}
	this->m_PersonList.RemoveAll();
}

//データを更新する。
void CPersonInfo::Update(DWORD DataIndex, const CPerson* NewPerson)
{
	CPerson* DstData = this->m_PersonList.GetAt(DataIndex);
	DstData->SetFamilyName(((CPerson*)NewPerson)->GetFamilyName());
	DstData->SetFirstName(((CPerson*)NewPerson)->GetFirstName());
	DstData->SetAge(((CPerson*)NewPerson)->GetAge());
	DstData->SetSex(((CPerson*)NewPerson)->GetSex());
}

//サブデータを更新する
void CPersonInfo::Update(DWORD DataIndex, const CArray<CPerson*>& NewPerson)
{
	CPerson* DstData = this->m_PersonList.GetAt(DataIndex);
	DstData->CopyRelations(NewPerson);
}
