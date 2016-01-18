#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <sstream>
#include "fileVersion.h"
using namespace std;
void updateSVN(const CFileVersion& cObj)
{
    ostringstream os;
    os<< "svn update -r" <<cObj.m_iVersion<<" "<<cObj.m_sFilePath;
    string sSVNCommander = os.str();
    cout<<sSVNCommander<<endl;
}
int main()
{
    vector<CFileVersion> vcf = getFileVersions(cin);
    //copy(istream_iterator<CFileVersion>(cin),istream_iterator<CFileVersion>(),back_inserter(vcf));
    for_each(vcf.begin(),vcf.end(),updateSVN);
    return 0;
}
