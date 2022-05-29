#pragma once

#include <windows.h>
#include <iostream>
#include <stdlib.h>

class SSteam
{
  
private:
    WCHAR _g_steamInstallationPath[MAX_PATH];

public:
    bool FindSteam();
    void StartSteam(bool _bigPicture);
    void Log(std::string _message, int _logType);
};


struct LLogStatus
{
    int Success = 2;
    int Error = 4;
    int Info = 11;
};