#pragma once
#include <iostream>
#include <string>
#include <regex>
#include <sstream>
#include <unordered_map>
#include <locale>
#include <codecvt>

#include "MainForm.h"

extern gcroot<HarmonyWinforms::MainForm^> global_main_form;

namespace harmony
{
	// command used to shutdown terminal
	constexpr wchar_t SHUTDOWN_CMD[] = L"exit";
	// group 1 : command
	// group 2 : args
	static const std::wregex T_COMMAND(L"([a-zA-Z_]\\w*)(.*)");
	static const std::wregex T_ERROR(L"ERROR:\\s.*");
	static const std::wregex T_WARNING(L"WARNING:\\s.*");
	static const std::wregex T_MSG(L".*?:\\s+\[(.*?)\]");

	std::vector<std::wstring> split(const std::wstring& str, wchar_t delimeter);
	std::string wstr_to_str(const std::wstring& wstr);

	struct terminal
	{
		static std::unordered_map<std::wstring, bool(*)(const std::vector<std::wstring>&, std::wostream*)> commands;
		std::wstring user = L"user";
		std::wostream* output{};
		std::wstring last_command = L"";
		bool active = false;

		terminal(std::wostream* out_stream = &std::wcout);

		void start();

		void stop();

		bool execute(const std::wstring& cmd);
	};

	extern terminal global_terminal;
}
