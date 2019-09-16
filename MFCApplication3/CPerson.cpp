#include "pch.h"
#include "CPerson.h"

//デフォルトコンストラクタ
CPerson::CPerson()
	: m_FamilyName(_T(""))
	, m_FirstName(_T(""))
	, m_Age(0)
	, m_Sex(PERSON_SEX_TYPE_MIDDLE)
{
	this->m_Relations.RemoveAll();
}

//	@brief	引数ありのコンストラクタ
//
//	@param	FamilyName	苗字
//	@param	FirstName	名前
//	@param	Age	年齢
//	@param	Sex	性別
CPerson::CPerson(CString FamilyName, CString FirstName, DWORD Age, DWORD Sex)
	: m_FamilyName(FamilyName)
	, m_FirstName(FirstName)
	, m_Age(Age)
	, m_Sex(Sex)
{
	this->m_Relations.RemoveAll();
}

//	@brief	コピーコンストラクタ
//	@param[in]	Src	コピー元のCPersonオブジェクトへのポインタ
CPerson::CPerson(const CPerson* Src)
{
	this->m_FamilyName = Src->m_FamilyName;
	this->m_FirstName = Src->m_FirstName;
	this->m_Age = Src->m_Age;
	this->m_Sex = Src->m_Sex;

	this->CopyRelations((const CArray<CPerson*>&)(Src->m_Relations));
}

///<summary>
///デストラクタ
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

//自身のコピーを生成する。
CPerson* CPerson::CreateCopy()
{
	return new CPerson(this);
}

VOID CPerson::CopyRelations(const CArray<CPerson*>& Src)
{
	this->ReleaseRelation();

	for (INT_PTR index = 0; index < Src.GetCount(); index++) {
		CPerson* srcItem = Src.GetAt(index);
		CPerson* newItem = new CPerson(srcItem);//ここで、再起呼び出しになるので注意が必要！
		this->m_Relations.Add(newItem);
	}
}

//自身の保持している関係を開放する。
VOID CPerson::ReleaseRelation()
{
	for (INT_PTR index = 0; index < this->m_Relations.GetCount(); index++) {
		CPerson* relation = this->m_Relations.GetAt(index);
		delete relation;
	}
	this->m_Relations.RemoveAll();
}

//年齢を文字列で返す
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
		SexString = CString(_T("男性"));
	}
	else if (this->m_Sex == PERSON_SEX_TYPE_FEMALE) {
		SexString = CString(_T("女性"));
	}
	else {
		SexString = CString(_T("その他"));
	}
	return SexString;
}