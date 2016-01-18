#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <sstream>
#include <ctime>
#include "fileVersion.h"
using namespace std;
static char szTag[50+1];
static string sComment;
bool isFileExist(const string& sFilePath)
{
  ifstream ifs(sFilePath.c_str());
  return ifs.good();
}
void cvsCommit(const CFileVersion& cObj)
{
    ostringstream os;
    os<< "cvs commit -m \"ver:" <<cObj.m_iVersion<<sComment<<"\" "<<cObj.m_sFilePath;
    string sCVSCommander = os.str();
    cout<<sCVSCommander<<endl;

    os.str("");  //clear the ostringstream
    os<< "cvs tag " <<szTag<<" "<<cObj.m_sFilePath;
    sCVSCommander = os.str();
    cout<<sCVSCommander<<endl;
}

void getComment()
{
	//ifstream ifs("d:/workcvs_170/cnaps2/server/comment.txt");
	ifstream ifs("comment.txt");
	if(!ifs)
	{
		cerr<<"打开comment.txt失败"<<endl;
		exit(-1);
	}

	while(ifs)
	{
		string sLine;
		ifs>>sLine;
		sComment = sComment + " " + sLine;
	}
}
void genTag()
{
	memset(szTag,'\0',sizeof(szTag));
	time_t now;
	time(&now);
	strftime(szTag,sizeof(szTag)-1,"CNAPS2_%Y%m%d-%H%M%S",localtime(&now));
}
int main()
{
	genTag();
	getComment();
    vector<CFileVersion> vcf = getFileVersions(cin);
//    copy(istream_iterator<CFileVersion>(cin),istream_iterator<CFileVersion>(),back_inserter(vcf));
    for_each(vcf.begin(),vcf.end(),cvsCommit);
    return 0;
}
