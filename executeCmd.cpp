#include <algorithm>
#include <iterator>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <functional>
using std::for_each;
using std::system;
using std::istream;
using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;
using std::istream_iterator;
using std::mem_fun_ref;
using std::back_inserter;
struct CCommander
{
    string m_sCmd;
    void show() const
    {
	cout<<m_sCmd<<endl;
    }
    int execute() const
    {
		show();
		return system(m_sCmd.c_str());
    }
};
istream& operator>>(istream& is,CCommander& cCmd)
{
    getline(is,cCmd.m_sCmd);
    return is;
}
int main()
{
    vector<CCommander> vc;
    copy(istream_iterator<CCommander>(cin),istream_iterator<CCommander>(),back_inserter(vc));
    for_each(vc.begin(),vc.end(),mem_fun_ref(&CCommander::execute));
}
