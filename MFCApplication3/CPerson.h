#pragma once
class CPerson
{
public:
	enum {
		PERSON_SEX_TYPE_FEMALE = 0,
		PERSON_SEX_TYPE_MALE,
		PERSON_SEX_TYPE_MIDDLE,
		PERSON_SEX_TYPE_MAX,
	};

public:
	CPerson();
	CPerson(CString FamilyName, CString FirstName, DWORD Age, DWORD Sex);
	CPerson(const CPerson* Src);
	virtual ~CPerson();

public:	//Getter/Setter
	CString		GetFamilyName() const { return m_FamilyName; }
	void		SetFamilyName(CString FamilyName) { this->m_FamilyName = FamilyName; }
	CString		GetFirstName() const { return m_FirstName; }
	void		SetFirstName(CString FirstName) { this->m_FirstName = FirstName; }
	DWORD		GetAge() const { return m_Age; }
	const CString		GetAgeStr() const;
	void		SetAge(DWORD Age) { this->m_Age = Age; }
	DWORD		GetSex() const { return m_Sex; }
	const CString		GetSexStr() const;
	void		SetSex(DWORD Sex) { this->m_Sex = Sex; }

	CArray<CPerson*>& GetRelations() const { return (CArray<CPerson*>&)(this->m_Relations); }

public:
	virtual	VOID	AddRelations(const CPerson& relation);
	virtual VOID	CopyRelations(const CArray<CPerson*>& Src);
	virtual CPerson* CreateNewItem() { return new CPerson(); }
	virtual CPerson* CreateCopy();

protected:
	virtual VOID	ReleaseRelation();
	virtual VOID	ShowRelations();

protected:
	CString		m_FamilyName;
	CString		m_FirstName;
	DWORD		m_Age;
	DWORD		m_Sex;

	CArray<CPerson*>	m_Relations;
};

