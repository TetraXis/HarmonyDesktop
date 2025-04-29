#include "terminal.h"

harmony::terminal harmony::global_terminal{};


gcroot<HarmonyWinforms::MainForm^> global_main_form{};

std::vector<std::wstring> harmony::split(const std::wstring& str, wchar_t delimeter)
{
	std::vector<std::wstring> result{};
	std::wistringstream iss(str);
	std::wstring elem{};

	while (std::getline(iss, elem, delimeter))
	{
		if (elem != L"")
		{
			result.emplace_back(elem);
		}
	}

	return result;
}

std::string harmony::wstr_to_str(const std::wstring& wstr)
{
	using convert_typeX = std::codecvt_utf8<wchar_t>;
	std::wstring_convert<convert_typeX, wchar_t> converterX;

	return converterX.to_bytes(wstr);
}

harmony::terminal::terminal(std::wostream* out_stream) : output(out_stream)
{

}

void harmony::terminal::start()
{
	active = true;

	while (active)
	{
		std::wcout << user << L"> ";
		std::getline(std::wcin, last_command);
		execute(last_command);
	}
}

void harmony::terminal::stop()
{
	active = false;
}

bool harmony::terminal::execute(const std::wstring& cmd)
{
	std::wstring command{};
	std::wstring args{};
	std::wsmatch match{};

	if (!std::regex_match(cmd, match, T_COMMAND))
	{
		(*output) << L"ERROR: terminal> Could not recognize \"" << cmd << L"\" as valid command.\n";
		return false;
	}

	command = match.str(1);
	args = match.str(2);

	if (command == SHUTDOWN_CMD)
	{
		stop();
		return true;
	}

	if (!commands.count(command))
	{
		(*output) << L"ERROR: terminal> Name \"" << command << L"\" was not recognized as known command.\n";
		return false;
	}

	return commands[command](split(args, L' '), output);
}