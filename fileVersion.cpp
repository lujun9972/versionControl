#include <iostream>
#include <algorithm>
#include <iterator>
#include "fileVersion.h"
using namespace std;
CFileVersion::CFileVersion(string sFilePath,int iVersion):m_sFilePath(sFilePath),m_iVersion(iVersion)
{
}
bool operator<(const CFileVersion& aObj,const CFileVersion& cObj)
{
    return (aObj.m_sFilePath<cObj.m_sFilePath) ||(aObj.m_sFilePath == cObj.m_sFilePath && aObj.m_iVersion < cObj.m_iVersion);
}

bool operator>(const CFileVersion& aObj,const CFileVersion& cObj)
{
    return (aObj.m_sFilePath>cObj.m_sFilePath) ||(aObj.m_sFilePath == cObj.m_sFilePath && aObj.m_iVersion > cObj.m_iVersion);
}
istream& operator>>(istream& is,CFileVersion& cObj)
{
    is>>cObj.m_sFilePath;
    is>>cObj.m_iVersion;
    return is;
}

ostream& operator<<(ostream& os,const CFileVersion& cObj)
{
    os<<cObj.m_sFilePath<<"\t";
    os<<cObj.m_iVersion<<endl;
    return os;
}

vector<CFileVersion> getFileVersions(istream& is)
{
    vector<CFileVersion> vcf;
    copy(istream_iterator<CFileVersion>(is),istream_iterator<CFileVersion>(),back_inserter(vcf));
    return vcf;
}
/*
int main()
{
    CFileVersion a[2];
    for(int i = 0;i < sizeof(a)/sizeof(a[0]);++i)
    {
	cin >>a[i];
    }
    sort(a,a+2);
    copy(a,a+2,ostream_iterator<CFileVersion>(cout));
}
*/
