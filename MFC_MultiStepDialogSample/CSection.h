#pragma once
class CSection
{
public:
	CSection();
	CSection(CString Name, CString Explain);
	CSection(const CSection* SrcData);
	virtual ~CSection();

public:
	virtual VOID	AddDetail(const CSection* DetailSrc);
	virtual CSection* CreateCopy();
	virtual VOID	CopyDetail(const CArray<CSection*>& SrcData);

public:
	CString GetName() const { return this->m_Name; }
	void SetName(CString Name) { this->m_Name = Name; }
	CString GetExplain() const { return (const CString&)(this->m_Explain); }
	void SetExplain(CString Explain) { this->m_Explain = Explain; }
	CArray<CSection*>& GetDetail() const { return (CArray<CSection*>&)(this->m_SectionDetail); }

protected:
	virtual VOID	Release();

protected:
	CString		m_Name;
	CString		m_Explain;
	
	CArray<CSection*>	m_SectionDetail;
};

