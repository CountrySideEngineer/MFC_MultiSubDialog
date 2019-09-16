#include "pch.h"
#include "CSection.h"

//	@brief	デフォルトコンストラクタ
CSection::CSection()
	: m_Name(_T(""))
	, m_Explain(_T(""))
{
	this->Release();
}

CSection::CSection(CString Name, CString Explain)
	: m_Name(Name)
	, m_Explain(Explain)
{
	this->Release();
}

//	@brief	コピーコンストラクタ
//
//	@param[in]	SrcData	コピー元データの参照
CSection::CSection(const CSection* SrcData)
	: m_Name(SrcData->m_Name)
	, m_Explain(SrcData->m_Explain)
{
	this->CopyDetail(SrcData->m_SectionDetail);
}

//	@brief	デストラクタ
CSection::~CSection()
{
	for (INT_PTR Index = 0; Index < this->m_SectionDetail.GetCount(); Index++) {
		CSection* Item = this->m_SectionDetail.GetAt(Index);
		delete Item;
	}
	this->m_SectionDetail.RemoveAll();
}

//	@brief	詳細情報を追加します。
//
//	@param[in]	DetailInfo	追加する詳細情報へのポインタ
//	@note	追加する詳細情報は、引数で指定されたポインタではなく、関数内で新たに確保した
//			領域へのポインタ。
//			そのため、引数で指定した内容は、呼び出し元で管理/開放すること。
VOID CSection::AddDetail(const CSection* DetailSrc)
{
	this->m_SectionDetail.Add(((CSection*)DetailSrc)->CreateCopy());
}

//	@brief	詳細情報をコピーする。
//
//	@param[in]	コピー元の詳細情報の参照
//	@note	詳細情報は、ポインタ形式で格納されている。
//			CopyDetail()では、このポインタのアドレスをコピーするのではなく、新たに領域を確保し、
//			そこにコピー元のデータの内容/値をコピーする。
VOID CSection::CopyDetail(const CArray<CSection*>& SrcData)
{
	this->Release();

	for (INT_PTR Index = 0; Index < SrcData.GetCount(); Index++) {
		CSection* Item = SrcData.GetAt(Index);
		CSection* NewItem = Item->CreateCopy();	//再起呼び出し発生
		this->m_SectionDetail.Add(NewItem);
	}
}

//	@brief	オブジェクトのコピーを生成する。
//
//	@note	自身のデータのコピーを生成する。
//			このとき詳細情報は、新たに領域を確保、そこにコピー元のデータの内容/値が
//			コピーされる。
//			そのため、新たに確保された領域の開放漏れに注意が必要。
CSection* CSection::CreateCopy()
{
	return new CSection(this);
}

//	@brief	詳細情報をすべて削除する。
//
//	@note	詳細情報は、ポインタ形式で格納されている。そのため、この領域も開放される。
VOID CSection::Release()
{
	for (INT_PTR Index = 0; Index < this->m_SectionDetail.GetCount(); Index++) {
		CSection* Item = this->m_SectionDetail.GetAt(Index);
		delete Item;
	}
	this->m_SectionDetail.RemoveAll();
}