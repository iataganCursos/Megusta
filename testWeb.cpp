#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdarg>
#include <string>
#include <fstream>
#include <windows.h>
#include <wininet.h>

void rPrintln(const char *message, ...){
  if(message == NULL) {
    printf("\n");
  }
  else {
    va_list args;
    va_start(args, message);
    vprintf(message, args);
    va_end(args);
    printf("\n");
  }
}

char *rOpenFileWeb(const char *url) {
    const char* agent = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36";
    HINTERNET hInternet = InternetOpenA(agent, INTERNET_OPEN_TYPE_DIRECT, NULL, NULL, 0);
    if (!hInternet) {
        return NULL;
    }
    HINTERNET hUrl = InternetOpenUrlA(hInternet, url, NULL, 0, INTERNET_FLAG_RELOAD, 0);
    if (!hUrl) {
        InternetCloseHandle(hInternet);
        return NULL;
    }
    char buffer[1024];
    DWORD bytesRead;
    std::string content;
    while (InternetReadFile(hUrl, buffer, sizeof(buffer), &bytesRead) && bytesRead > 0) {
        content.append(buffer, bytesRead);
    }
    InternetCloseHandle(hUrl);
    InternetCloseHandle(hInternet);
    if (content.empty()) {
        return NULL;
    }
    char* result = (char*)malloc(content.size() + 1);
    if (!result) {
        return NULL;
    }
    strcpy(result, content.c_str());
    printf("200 OK\n");
    return result;
}
int main(){
        rPrintln(rOpenFileWeb("https://www.ouka.com.br/meu_arquivo.txt"));
        return 0;
}
// g++ testWeb.cpp -o testWeb.exe -lm -lwininet
// sudo apt install mingw-w64