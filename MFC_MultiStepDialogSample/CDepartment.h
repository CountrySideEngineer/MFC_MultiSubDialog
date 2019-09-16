#pragma once
#include "CSection.h"
class CDepartment :
	public CSection
{
public:
	CDepartment();
	CDepartment(CString Name, CString Explain, CString Manager, CString BussDesc);
	CDepartment(const CDepartment* SrcData);
	virtual ~CDepartment() {}

public:
	virtual	CSection* CreateCopy();

public:
	CString GetManager() const { return (const CString)this->m_Manager; }
	void SetManager(CString Manager) { this->m_Manager = Manager; }
	CString GetBussDesc() const { return (const CString)this->m_BussDesc; }
	void SetBussDesc(CString BussDesc) { this->m_BussDesc = BussDesc; }
	DWORD GetNumOfMember() const { return CSection::m_SectionDetail.GetCount(); }

protected:
	CString	m_Manager;
	CString	m_BussDesc;
	DWORD	m_NumOfMember;
};

