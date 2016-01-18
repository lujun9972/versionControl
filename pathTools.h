#ifndef __PATHTOOLS_H__
#define __PATHTOOLS_H
#include <string>
using std::string;
namespace PathTools
{
    const char cUnixSep = '/';
    const char cWinSep = '\\';
    string combinePath(const string& sLeftDir,const string& sRightPath,char cCurSysSep = cWinSep);
    string getDirFromPath(const string& sPath,char cCurSysSep = cWinSep);
    string getCurSysPath(const string& sOtherSysPath,const char cOtherSysSep,const char cCurSysSep);
    string getUnixPath(const string& sWinPath);
	string getWinPath(const string& sUnixPath);
}

#endif
