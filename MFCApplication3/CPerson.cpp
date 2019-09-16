#include "pch.h"
#include "CPerson.h"

//�f�t�H���g�R���X�g���N�^
CPerson::CPerson()
	: m_FamilyName(_T(""))
	, m_FirstName(_T(""))
	, m_Age(0)
	, m_Sex(PERSON_SEX_TYPE_MIDDLE)
{
	this->m_Relations.RemoveAll();
}

//	@brief	��������̃R���X�g���N�^
//
//	@param	FamilyName	�c��
//	@param	FirstName	���O
//	@param	Age	�N��
//	@param	Sex	����
CPerson::CPerson(CString FamilyName, CString FirstName, DWORD Age, DWORD Sex)
	: m_FamilyName(FamilyName)
	, m_FirstName(FirstName)
	, m_Age(Age)
	, m_Sex(Sex)
{
	this->m_Relations.RemoveAll();
}

//	@brief	�R�s�[�R���X�g���N�^
//	@param[in]	Src	�R�s�[����CPerson�I�u�W�F�N�g�ւ̃|�C���^
CPerson::CPerson(const CPerson* Src)
{
	this->m_FamilyName = Src->m_FamilyName;
	this->m_FirstName = Src->m_FirstName;
	this->m_Age = Src->m_Age;
	this->m_Sex = Src->m_Sex;

	this->CopyRelations((const CArray<CPerson*>&)(Src->m_Relations));
}

///<summary>
///�f�X�g���N�^
///</summary>
CPerson::~CPerson()
{
	this->ReleaseRelation();
}

VOID CPerson::AddRelations(const CPerson& relation)
{
	this->m_Relations.Add(new CPerson(&relation));
}

VOID CPerson::ShowRelations()
{
	for (INT_PTR index = 0; index < this->m_Relations.GetCount(); index++) {
		CPerson* relation = this->m_Relations.GetAt(index);
		_tprintf(_T("FamilyName = ") + relation->m_FamilyName + _T("\r\n"));
		_tprintf(_T("FirstName = ") + relation->m_FirstName + _T("\r\n"));
		_tprintf(_T("Age =%d\r\n"), relation->m_Age);
		_tprintf(_T("Sex =%d\r\n"), relation->m_Sex);
		_tprintf(_T("Address = 0x%016p\r\n"), relation);
	}
}

//���g�̃R�s�[�𐶐�����B
CPerson* CPerson::CreateCopy()
{
	return new CPerson(this);
}

VOID CPerson::CopyRelations(const CArray<CPerson*>& Src)
{
	this->ReleaseRelation();

	for (INT_PTR index = 0; index < Src.GetCount(); index++) {
		CPerson* srcItem = Src.GetAt(index);
		CPerson* newItem = new CPerson(srcItem);//�����ŁA�ċN�Ăяo���ɂȂ�̂Œ��ӂ��K�v�I
		this->m_Relations.Add(newItem);
	}
}

//���g�̕ێ����Ă���֌W���J������B
VOID CPerson::ReleaseRelation()
{
	for (INT_PTR index = 0; index < this->m_Relations.GetCount(); index++) {
		CPerson* relation = this->m_Relations.GetAt(index);
		delete relation;
	}
	this->m_Relations.RemoveAll();
}

//�N��𕶎���ŕԂ�
const CString CPerson::GetAgeStr() const 
{
	CString AgeString;
	AgeString.Format(_T("%d"), this->m_Age);

	return AgeString;
}

const CString CPerson::GetSexStr() const
{
	CString SexString;
	if (this->m_Sex == PERSON_SEX_TYPE_MALE) {
		SexString = CString(_T("�j��"));
	}
	else if (this->m_Sex == PERSON_SEX_TYPE_FEMALE) {
		SexString = CString(_T("����"));
	}
	else {
		SexString = CString(_T("���̑�"));
	}
	return SexString;
}