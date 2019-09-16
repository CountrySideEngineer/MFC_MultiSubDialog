#include "pch.h"
#include "CDepartment.h"

//	@brief	�f�t�H���g�R���X�g���N�^
CDepartment::CDepartment()
	: CSection()
	, m_Manager(CString(_T("")))
	, m_BussDesc(CString(_T("")))
	, m_NumOfMember(0)
{}

//	@brief	��������̃R���X�g���N�^
//
//	@param	Name	������
//	@param	Explain	�����̐���
//	@param	Manager	�������̖��O
//	@param	BussDesc	�d�����e�̐���
CDepartment::CDepartment(CString Name, CString Explain, CString Manager, CString BussDesc)
	: CSection(Name, Explain)
	, m_Manager(Manager)
	, m_BussDesc(BussDesc)
	, m_NumOfMember(0)
{}

//	@brief	�R�s�[�R���X�g���N�^
//
//	@param[in]	SrcData	�R�s�[���f�[�^�̎Q��
CDepartment::CDepartment(const CDepartment* SrcData)
	: CSection(SrcData)
	, m_Manager(SrcData->m_Manager)
	, m_BussDesc(SrcData->m_BussDesc)
	, m_NumOfMember(0)
{}

//	@brief	���g�̃R�s�[�𐶐�����B
//
//	@note	���g�̃f�[�^�̃R�s�[�𐶐�����B
//			���̂Ƃ��ڍ׏��́A�V���ɗ̈���m�ہA�����ɃR�s�[���̃f�[�^�̓��e/�l��
//			�R�s�[�����B
//			���̂��߁A�V���Ɋm�ۂ��ꂽ�̈�̊J���R��ɒ��ӂ��K�v�B
CSection* CDepartment::CreateCopy()
{
	return new CDepartment(this);
}