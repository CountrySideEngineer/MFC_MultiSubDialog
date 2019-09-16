#pragma once
#include "CPerson.h"

class CPersonInfo
{
public:
	CPersonInfo() {}
	~CPersonInfo();

public:
	void Add(DWORD DataIndex);
	void Add(DWORD DataIndex, CPerson* NewPerson);
	const CPerson* GetPerson(DWORD DataIndex);
	void Remove(DWORD DataIndex);
	void RemoveAll();
	void Update(DWORD DataIndex,  const CPerson* NewPerson);
	void Update(DWORD DataIndex, const CArray<CPerson*>& NewPerson);

	INT_PTR GetCount() const { return this->m_PersonList.GetCount(); }
	CPerson* GetAt(DWORD DataIndex) const;

	CArray<CPerson*>* GetPersonListPtr() const { return (CArray<CPerson*>*)(&this->m_PersonList); }

protected:
	CArray<CPerson*> m_PersonList;
};
