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

//�V�K�Ƀf�[�^��ǉ�����B
//�V�K�ɒǉ�����f�[�^�́A�����f�[�^�B
void CPersonInfo::Add(DWORD DataIndex)
{
	this->Add(DataIndex, &CPerson());
}

//�V�K�Ƀf�[�^��ǉ�����B
//�ǉ�����f�[�^�́A�����Ŏw�肳�ꂽ�l�B
void CPersonInfo::Add(DWORD DataIndex, CPerson* NewPerson)
{
	this->m_PersonList.InsertAt(DataIndex, NewPerson);
}

//�w�肳�ꂽ�ԍ��̗v�f��Ԃ��B
CPerson* CPersonInfo::GetAt(DWORD DataIndex) const
{
	return this->m_PersonList.GetAt(DataIndex);
}

//�w�肳�ꂽ�ԍ��̏���Ԃ��B
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

//�����̃f�[�^��z�񂩂�폜����B
void CPersonInfo::Remove(DWORD DataIndex)
{
	CPerson* RemoveItem = this->m_PersonList.GetAt(DataIndex);
	delete RemoveItem;

	this->m_PersonList.RemoveAt(DataIndex);
}

//�����̃f�[�^�����ׂč폜����B
void CPersonInfo::RemoveAll()
{
	for (INT_PTR Index = 0; Index < this->m_PersonList.GetCount(); Index++) {
		CPerson* RemoveItem = this->m_PersonList.GetAt(Index);
		delete RemoveItem;
	}
	this->m_PersonList.RemoveAll();
}

//�f�[�^���X�V����B
void CPersonInfo::Update(DWORD DataIndex, const CPerson* NewPerson)
{
	CPerson* DstData = this->m_PersonList.GetAt(DataIndex);
	DstData->SetFamilyName(((CPerson*)NewPerson)->GetFamilyName());
	DstData->SetFirstName(((CPerson*)NewPerson)->GetFirstName());
	DstData->SetAge(((CPerson*)NewPerson)->GetAge());
	DstData->SetSex(((CPerson*)NewPerson)->GetSex());
}

//�T�u�f�[�^���X�V����
void CPersonInfo::Update(DWORD DataIndex, const CArray<CPerson*>& NewPerson)
{
	CPerson* DstData = this->m_PersonList.GetAt(DataIndex);
	DstData->CopyRelations(NewPerson);
}
