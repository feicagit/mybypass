#pragma once
#include <string>
#include <map>

#define DEMO_GLOBAL_APP_KEY		"68d2a68a1176727198194fd001aa470b" //6f49e3f759ccd47810b445444eebc090 std::string app_key = "68d2a68a1176727198194fd001aa470b";//flyfly

class QString
{
public:
	static std::string GetGUID();
	static std::string GetMd5(const std::string& input);
	static void NIMFreeBuf(void *data);
};

class QPath
{
public:
	static std::wstring GetAppPath(); //获取exe所在目录，最后有"\\"
	static std::wstring GetUserAppDataDir(const std::string& app_account);
	static std::wstring GetLocalAppDataDir();
	static std::wstring GetNimAppDataDir(); // "...Local\\Netease\\Nim\\"
};

class QCommand
{
public:
	static void ParseCommand(const std::wstring &cmd);
	static bool AppStartWidthCommand(const std::wstring &app, const std::wstring &cmd);
	static bool RestartApp(const std::wstring &cmd);
	static std::wstring Get(const std::wstring &key);
	static void Set(const std::wstring &key, const std::wstring &value);
	static void Erase(const std::wstring &key);
private:
	static std::map<std::wstring,std::wstring> key_value_;
};