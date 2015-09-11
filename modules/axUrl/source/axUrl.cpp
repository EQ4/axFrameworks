#include "axUrl.h"

ax::Url::Url()
{
    _curl = curl_easy_init();
}

ax::Url::~Url()
{
    // Always cleanup.
    if(_curl)
    {
        curl_easy_cleanup(_curl);
    }
}

std::string ax::Url::GetUrlData(const std::string& url)
{
    std::string str;
    if(_curl)
    {
        curl_easy_setopt(_curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(_curl, CURLOPT_WRITEFUNCTION, axUrlApi::writefunc);
        curl_easy_setopt(_curl, CURLOPT_WRITEDATA, &str);
        
        // Perform the request, res will get the return code.
        res = curl_easy_perform(_curl);
        
        // Check for errors.
        if(res != CURLE_OK)
        {
            ax::Error("curl_easy_perform() failed :", 
                      curl_easy_strerror(res));
        }
    }
    
//    std::cout << "Content : " << std::endl << str << std::endl;
    
    return str;
}

size_t ax::Url::writefunc(void* ptr, size_t size,
                          size_t nmemb, std::string s)
{
    std::string tmp;
    tmp.assign((const char*)ptr);
    
    s += tmp;
    
    return size * nmemb;
}



