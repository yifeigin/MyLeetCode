#include <string>
#include <cstring>
#include <iostream>
#include <curl/curl.h>
#include <sstream>
#include <regex>
#include <fstream>
#include <unicode/unistr.h>

using namespace std;

extern "C" std::size_t append_to_string( void* contents, std::size_t size, std::size_t nmemb, void* pstr )
{   
    const std::size_t sz = size * nmemb ;
    const char* cstr = static_cast<const char*>(contents) ;
    std::string& str = *static_cast< std::string* >(pstr) ;
    for( std::size_t i = 0 ; i < sz ; ++i ) str += cstr[i] ;
    return sz ;
}

void CodePrinter(string code) {
  code  = code.substr(code.find("\'")+1, code.rfind("\'")-code.find("\'")-1);
  icu::UnicodeString converter = icu::UnicodeString(code.c_str(), code.length());
  icu::UnicodeString newUstring = converter.unescape();
  code = "";
  newUstring.toUTF8String(code);
  cout << code << endl;
}

int main() {

	CURL *curl;
  CURLcode res;
 	string data;
  smatch match;
  regex pattern ("[0-9]*/\"><strong>Accepted</strong></a>");
  vector<string> Submissions;
  vector<string> Code;
  regex codePattern ("""submissionCode: \'.*\'""");
  char const * cookie = "PHPSESSID=gl66ynibmw6bsknzbb5endznjstx0j30; _ga=GA1.2.1984831265.1389075465; NRAGENT=tk=26e67c3be080fab2";
 	curl_global_init(CURL_GLOBAL_ALL);
  curl = curl_easy_init();
  if(curl) {
  	// Set up a couple initial paramaters that we will not need to mofiy later.
	curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_9_0) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/31.0.1650.63 Safari/537.36");
	curl_easy_setopt(curl, CURLOPT_AUTOREFERER, 1 );
	curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1 );
	curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "");
  // Obtain a PHPSESSID cookie from LeetCode page 
  curl_easy_setopt(curl, CURLOPT_COOKIE, cookie);

    // Now, can actually login. First we forge the HTTP referer field, or HTS will deny the login
    curl_easy_setopt(curl, CURLOPT_URL, "http://oj.leetcode.com/accounts/login/");
    // Next we tell LibCurl what HTTP POST data to submit
    char const * LoginInfo = "username=yifei21&password=Wang1995";
	  curl_easy_setopt(curl, CURLOPT_POSTFIELDS, LoginInfo);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, append_to_string);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, addressof(data));
    curl_easy_perform(curl);
    data = "";

    curl_easy_setopt(curl, CURLOPT_URL, "https://leetcode.com/problems/reverse-string/submissions/");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, append_to_string);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, addressof(data));
    res = curl_easy_perform(curl);
    /* Check for errors */ 
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
 	  
    while (regex_search (data,match,pattern)) {
      for (auto x:match) {
        Submissions.push_back(x);
        cout << x << endl;
      }
      data = match.suffix().str();
    }
    for (unsigned long i=0; i<Submissions.size(); i++) {
      string TempLink = Submissions[i].substr(0, Submissions[i].find("/"));
      TempLink = "https://oj.leetcode.com/submissions/detail/" + TempLink;
      const char * link = TempLink.c_str();
      curl_easy_setopt(curl, CURLOPT_URL, link);
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, append_to_string);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, addressof(data));
      res = curl_easy_perform(curl);
      //cout << data << endl;
      while (regex_search (data,match,codePattern)) {
        for (auto x:match) {
          Code.push_back(x);
          //cout << x << endl;
        }
        data = match.suffix().str();
      }
      CodePrinter(Code.back());
      cout << endl;
    }
    /* always cleanup */ 
    curl_easy_cleanup(curl);
  }
	
}




