#include <algorithm>
#include <iterator>
#include "pathTools.h"
using namespace std;
namespace PathTools
{
    string combinePath(const string& sLeftDir,const string& sRightPath,char cCurSysSep)
    {
	if(sLeftDir[sLeftDir.size() -1] != cCurSysSep)
	{
	    return sLeftDir + cCurSysSep + sRightPath;
	}
	return sLeftDir + sRightPath;
    }
    string getDirFromPath(const string& sPath,char cCurSysSep)
    {
	if(sPath[sPath.size()-1] == cCurSysSep)
	{
	    return sPath;
	}
	string::size_type iPos = sPath.find_last_of(cCurSysSep);
	if(iPos == string::npos)
	{
	    string tmp(".");
	    tmp.push_back(cCurSysSep);
	    return tmp;
	}
	return sPath.substr(0,iPos);
    }

    string getCurSysPath(const string& sOtherSysPath,const char cOtherSysSep,const char cCurSysSep)
    {
	string sCurSysPath;
	replace_copy(sOtherSysPath.begin(),sOtherSysPath.end(),back_inserter(sCurSysPath),cOtherSysSep,cCurSysSep);
	return sCurSysPath;
    }
    string getUnixPath(const string& sWinPath)
	{
		return getCurSysPath(sWinPath,cWinSep,cUnixSep);
	}
	string getWinPath(const string& sUnixPath)
	{
		return getCurSysPath(sUnixPath,cUnixSep,cWinSep);
	}
}
