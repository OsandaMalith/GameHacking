#include "stdafx.h"
 
#include <stdio.h>
#include <tchar.h>
#include <windows.h>
 
#define start 0x1005340
#define end 0x10056A0
 
int _tmain(int argc, _TCHAR* argv[]) {
    DWORD dwProcessId = 0;
    DWORD dwRead = 0;
    HWND window = FindWindow(NULL, L"Minesweeper");
    if (window == NULL)
        return wprintf(L"[-] Failed to find Minesweeper process");
 
    GetWindowThreadProcessId(window, &dwProcessId);
    HANDLE process =  OpenProcess(PROCESS_VM_READ, FALSE, dwProcessId);
 
    DWORD size = end - start;
 
    LPBYTE buffer = (LPBYTE)malloc(size);
    if (buffer == NULL)
        return wprintf(L"[-] Failed to allocated memory");
 
    while (true) {
        wprintf(L"[+] Minesweeper Dirty hack\n");
        wprintf(L"[+] Author: @OsandaMalith\n");
        wprintf(L"[+] Website: https://osandamalith.com\n\n");
 
        BOOL ret = ReadProcessMemory(process, (LPVOID)start, buffer, size,
            &dwRead);
        if (ret == NULL) return wprintf(L"[-] Failed to read memory");
         
        BYTE field = NULL;
 
 
        for (size_t i = 0, j = 0; i < size; i++, j++) {
            if (j == 0x20) {
                puts("");
                j = 0;
            }
            printf("%c", buffer[i]);
        }
        Sleep(1500);
 
        system("cls");
    }
    return 0;
}
