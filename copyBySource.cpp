#include <algorithm>
#include <iterator>
#include <vector>
#include <set>
#include "fileVersion.h"
#include "pathTools.h"
using std::string;
using std::cout;
using std::endl;
using std::cerr;
using std::set;
class CCopyBySource
{
    public:
    CCopyBySource(const string& sSrcDir,const string& sDesDir)
    {
	//统一转换为UNIX格式,并且最后带有/
	m_sSrcDir = PathTools::getWinPath(sSrcDir);
	m_sDesDir = PathTools::getWinPath(sDesDir);
	if(m_sSrcDir[m_sSrcDir.size() - 1] != PathTools::cWinSep)
	{
	    m_sSrcDir.push_back(PathTools::cWinSep);
	}
	if(m_sDesDir[m_sDesDir.size() - 1] != PathTools::cWinSep)
	{
	    m_sDesDir.push_back(PathTools::cWinSep);
	}
    }
    void doCopy(string sSourceFile)
	{
		sSourceFile = PathTools::getWinPath(sSourceFile);
		string sAbsSrcFile = PathTools::combinePath(m_sSrcDir,sSourceFile);
		string sAbsDesFile = PathTools::combinePath(m_sDesDir,sSourceFile);
		string sAbsSrcDir = PathTools::getDirFromPath(sAbsDesFile);
		if(ssMdedDirs.find(sAbsSrcDir) == ssMdedDirs.end())
		{
			string sMkdirCmd = "mkdir " + sAbsSrcDir;
			cout<<sMkdirCmd<<endl;
			ssMdedDirs.insert(sAbsSrcDir);
		}
		string sCopyCmd = "copy /y "+sAbsSrcFile + " "+sAbsDesFile;
		cout<<sCopyCmd<<endl;
	}
    void operator()(const CFileVersion& cFileVersion)
    {
	doCopy(cFileVersion.m_sFilePath);
    }
    private:
    string m_sSrcDir;
    string m_sDesDir;
	set<string> ssMdedDirs;
};
int main(int argc,char** argv)
{
    if(3 != argc)
    {
	cerr<<"用法为："<<argv[0]<<" 源目录 目的源 文本源"<<endl;
	return -1;
    }
    string sSrcDir = argv[1];
    string sDesDir = argv[2];
    //string sSourceFile = argv[3];

    vector<CFileVersion> vcf = getFileVersions(cin);
    for_each(vcf.begin(),vcf.end(),CCopyBySource(sSrcDir,sDesDir));
}
