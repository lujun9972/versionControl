#ifndef __FILEVERSION_H__
#define __FILEVERSION_H__                                     
#include <string>
#include <iostream>
#include <vector>
using std::string;
using std::istream;
using std::ostream;
using std::vector;
using std::cin;
struct CFileVersion
{
    string m_sFilePath;
    int m_iVersion;
    CFileVersion(string sFilepath="",int iVersion=1);
};
bool operator<(const CFileVersion& aObj,const CFileVersion& cObj);
bool operator>(const CFileVersion& aObj,const CFileVersion& cObj);
istream& operator>>(istream& is,CFileVersion& cObj);
ostream& operator<<(ostream& os,const CFileVersion& cObj);

vector<CFileVersion> getFileVersions(istream& is = cin);
#endif
