#ifndef __AX_URL_H__
#define __AX_URL_H__

#include "axUtils.h"
#include <curl/curl.h>

namespace ax
{
    class Url
    {
    public:
        Url();
        
        ~Url();

        void AddUrlOption(const int& opt, const std::string& opt_str);

        std::string GetUrlData(const std::string& url);

    private:
        CURL* _curl;
        CURLcode _curl_res;

        static size_t writefunc(void* ptr, size_t size,
                                size_t nmemb, std::string s);
    };
}


// class axUrlApi
// {
// public:
//     inline static axUrlApi* GetInstance()
//     {
//         return _url_api == nullptr ? _url_api = new axUrlApi() : _url_api;
//     }
    
//     std::string GetUrlData(const std::string& url);
    
//     static size_t writefunc(void* ptr, size_t size,
//                             size_t nmemb, std::string s);
    
// private:
//     axUrlApi();
//     ~axUrlApi();
    
//     static axUrlApi* _url_api;
//     CURL* _curl;
//     CURLcode res;
// };

#endif // __AX_URL_H__
