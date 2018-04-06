#pragma once

namespace nim_comp
{
class LocalHelper
{
public:
	static bool GetAppLocalVersion(int &version, std::wstring &version_flag, double *fBypass_size=NULL);

private:
	static bool devenv_;
};
}