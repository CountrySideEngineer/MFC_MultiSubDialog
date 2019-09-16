#include "pch.h"
#include "CSection.h"

//	@brief	�f�t�H���g�R���X�g���N�^
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

//	@brief	�R�s�[�R���X�g���N�^
//
//	@param[in]	SrcData	�R�s�[���f�[�^�̎Q��
CSection::CSection(const CSection* SrcData)
	: m_Name(SrcData->m_Name)
	, m_Explain(SrcData->m_Explain)
{
	this->CopyDetail(SrcData->m_SectionDetail);
}

//	@brief	�f�X�g���N�^
CSection::~CSection()
{
	for (INT_PTR Index = 0; Index < this->m_SectionDetail.GetCount(); Index++) {
		CSection* Item = this->m_SectionDetail.GetAt(Index);
		delete Item;
	}
	this->m_SectionDetail.RemoveAll();
}

//	@brief	�ڍ׏���ǉ����܂��B
//
//	@param[in]	DetailInfo	�ǉ�����ڍ׏��ւ̃|�C���^
//	@note	�ǉ�����ڍ׏��́A�����Ŏw�肳�ꂽ�|�C���^�ł͂Ȃ��A�֐����ŐV���Ɋm�ۂ���
//			�̈�ւ̃|�C���^�B
//			���̂��߁A�����Ŏw�肵�����e�́A�Ăяo�����ŊǗ�/�J�����邱�ƁB
VOID CSection::AddDetail(const CSection* DetailSrc)
{
	this->m_SectionDetail.Add(((CSection*)DetailSrc)->CreateCopy());
}

//	@brief	�ڍ׏����R�s�[����B
//
//	@param[in]	�R�s�[���̏ڍ׏��̎Q��
//	@note	�ڍ׏��́A�|�C���^�`���Ŋi�[����Ă���B
//			CopyDetail()�ł́A���̃|�C���^�̃A�h���X���R�s�[����̂ł͂Ȃ��A�V���ɗ̈���m�ۂ��A
//			�����ɃR�s�[���̃f�[�^�̓��e/�l���R�s�[����B
VOID CSection::CopyDetail(const CArray<CSection*>& SrcData)
{
	this->Release();

	for (INT_PTR Index = 0; Index < SrcData.GetCount(); Index++) {
		CSection* Item = SrcData.GetAt(Index);
		CSection* NewItem = Item->CreateCopy();	//�ċN�Ăяo������
		this->m_SectionDetail.Add(NewItem);
	}
}

//	@brief	�I�u�W�F�N�g�̃R�s�[�𐶐�����B
//
//	@note	���g�̃f�[�^�̃R�s�[�𐶐�����B
//			���̂Ƃ��ڍ׏��́A�V���ɗ̈���m�ہA�����ɃR�s�[���̃f�[�^�̓��e/�l��
//			�R�s�[�����B
//			���̂��߁A�V���Ɋm�ۂ��ꂽ�̈�̊J���R��ɒ��ӂ��K�v�B
CSection* CSection::CreateCopy()
{
	return new CSection(this);
}

//	@brief	�ڍ׏������ׂč폜����B
//
//	@note	�ڍ׏��́A�|�C���^�`���Ŋi�[����Ă���B���̂��߁A���̗̈���J�������B
VOID CSection::Release()
{
	for (INT_PTR Index = 0; Index < this->m_SectionDetail.GetCount(); Index++) {
		CSection* Item = this->m_SectionDetail.GetAt(Index);
		delete Item;
	}
	this->m_SectionDetail.RemoveAll();
}