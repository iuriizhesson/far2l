#pragma once
#include <string>
#include <vector>
#include <unistd.h>

class VTCompletor
{
	int _pipe_stdin, _pipe_stdout;
	pid_t _pid;

	void Stop();
	bool EnsureStarted();
	
	bool TalkWithShell(const std::string &cmd, std::string &reply, const char *tabs);
	
	public:
	VTCompletor();
	~VTCompletor();

	bool ExpandCommand(std::string &cmd);
	
	bool GetPossibilities(const std::string &cmd, std::vector<std::string> &possibilities);
	
};
