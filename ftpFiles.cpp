#include <algorithm>
#include <iterator>
#include <vector>
#include <iostream>
#include "fileVersion.h"
#include "pathTools.h"
using namespace std;
string getPutCmd(const CFileVersion& cf)
{
	string sSrcFile = cf.m_sFilePath;
	string sDesFile = PathTools::getUnixPath(sSrcFile);
	string sCmd = "put "+sSrcFile+" "+sDesFile;
	return sCmd;
}
int main(int argc,char** argv)
{
	if(argc != 3)
	{
		cerr<<"Usage:"<<argv[0]<<" $ftpUser $ftpPassword"<<endl;
		return -1;
	}
	string sUser = argv[1];
	string sPwd = argv[2];
	vector<CFileVersion> vcf = getFileVersions(cin);
	vector<string> vsFtpCmds;
	string sLoginCmd = string("user ") + argv[1] +" "+argv[2];
	vsFtpCmds.push_back(sLoginCmd);
	vsFtpCmds.push_back("bin");
	transform(vcf.begin(),vcf.end(),back_inserter(vsFtpCmds),getPutCmd);
	copy(vsFtpCmds.begin(),vsFtpCmds.end(),ostream_iterator<string>(cout,"\n"));
}
