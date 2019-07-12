#define _NO_CRT_STDIO_INLINE
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <windows.h>

extern "C" {
    int __fltused;
}

bool HKLMKeyExists(LPCTSTR regSubKey, LPCTSTR regValue)
{
    LPCTSTR valueBuf[255];
    DWORD cbData = 255;

    LONG rc = RegGetValueW(
        HKEY_LOCAL_MACHINE,
        regSubKey,
        regValue,
        RRF_RT_REG_SZ,
        nullptr,
        valueBuf,
        &cbData
    );

    return rc == ERROR_SUCCESS;
}

void WinMainCRTStartup()
{
    LPCTSTR regSubKey = L"SOFTWARE\\WOW6432Node\\Company Name\\Application Name\\";
    bool rc = HKLMKeyExists(regSubKey, L"SomeValue");
    printf("%d", rc);
}
