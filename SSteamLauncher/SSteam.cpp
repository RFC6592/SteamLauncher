#include "SSteam.h"


// https://steamdb.info/app/730/graphs/
// Lancement de Cs:Go (Id : 730)

void SSteam::StartSteam(bool _bigPicture)
{
    LLogStatus logStatus;

    WCHAR startupCL[MAX_PATH * 2];
    STARTUPINFO startup_inf;
    PROCESS_INFORMATION process_inf;

    if (_bigPicture) wsprintfW(startupCL, L"%s -bigpicture", _g_steamInstallationPath);
    else wsprintfW(startupCL, L"%s -applaunch 730", _g_steamInstallationPath);


    ZeroMemory(&startup_inf, sizeof(startup_inf));
    startup_inf.cb = sizeof(startup_inf);
    ZeroMemory(&process_inf, sizeof(process_inf));



    if (CreateProcessW(NULL, startupCL, NULL, NULL, FALSE, 0, NULL, NULL, &startup_inf, &process_inf))
        Log("Launching Counter-Strike: Global Offensive ...", logStatus.Success);
    else
        Log("Failed to start Steam : ", logStatus.Error);

}

bool SSteam::FindSteam() {
    DWORD bufferSize = sizeof(_g_steamInstallationPath);
    return RegGetValue(HKEY_CURRENT_USER, L"Software\\Valve\\Steam", L"SteamExe", RRF_RT_REG_SZ, NULL, _g_steamInstallationPath, &bufferSize) == ERROR_SUCCESS ? true : false;
}

void SSteam::Log(std::string _message, int _logType)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);;

    SYSTEMTIME st, lt;

    GetSystemTime(&st);
    GetLocalTime(&lt);

    SetConsoleTextAttribute(hConsole, 9);
    std::cout << "[" << st.wHour << ":" << st.wMinute << ":" << st.wSecond << "]";

    SetConsoleTextAttribute(hConsole, _logType);
    std::cout << _message << std::endl;

    SetConsoleTextAttribute(hConsole, 15);
}
