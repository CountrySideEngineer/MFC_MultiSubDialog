#include "pch.h"
#include "CDepartment.h"

//	@brief	デフォルトコンストラクタ
CDepartment::CDepartment()
	: CSection()
	, m_Manager(CString(_T("")))
	, m_BussDesc(CString(_T("")))
	, m_NumOfMember(0)
{}

//	@brief	引数ありのコンストラクタ
//
//	@param	Name	部署名
//	@param	Explain	部署の説明
//	@param	Manager	部署長の名前
//	@param	BussDesc	仕事内容の説明
CDepartment::CDepartment(CString Name, CString Explain, CString Manager, CString BussDesc)
	: CSection(Name, Explain)
	, m_Manager(Manager)
	, m_BussDesc(BussDesc)
	, m_NumOfMember(0)
{}

//	@brief	コピーコンストラクタ
//
//	@param[in]	SrcData	コピー元データの参照
CDepartment::CDepartment(const CDepartment* SrcData)
	: CSection(SrcData)
	, m_Manager(SrcData->m_Manager)
	, m_BussDesc(SrcData->m_BussDesc)
	, m_NumOfMember(0)
{}

//	@brief	自身のコピーを生成する。
//
//	@note	自身のデータのコピーを生成する。
//			このとき詳細情報は、新たに領域を確保、そこにコピー元のデータの内容/値が
//			コピーされる。
//			そのため、新たに確保された領域の開放漏れに注意が必要。
CSection* CDepartment::CreateCopy()
{
	return new CDepartment(this);
}