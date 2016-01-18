#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include "fileVersion.h"
using namespace std;
vector<CFileVersion> getFileVersionsFromFile(const string& sFilePath)
{
    ifstream ifs(sFilePath.c_str());
    vector<CFileVersion> vFileVersion;
    if(ifs)
    {
	copy(istream_iterator<CFileVersion>(ifs),istream_iterator<CFileVersion>(),back_inserter(vFileVersion));
    }
    return vFileVersion;
}

bool isUniqueFileVersion(const CFileVersion& a,const CFileVersion& b)
{
    return a.m_sFilePath == b.m_sFilePath;
}
int main()
{
    //vector<CFileVersion> vcf = getFileVersionsFromFile("fileVersion.list");
    vector<CFileVersion> vcf = getFileVersions(cin);
    sort(vcf.begin(),vcf.end(),greater<CFileVersion>());
    vcf.erase(unique(vcf.begin(),vcf.end(),isUniqueFileVersion),vcf.end());
    copy(vcf.begin(),vcf.end(),ostream_iterator<CFileVersion>(cout));
}
