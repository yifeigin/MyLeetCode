#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <curl/curl.h>
#include <cstring>
#include <regex>
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

void CodePrinter(string code, ofstream& myCCfile) {
  code  = code.substr(code.find("\'")+1, code.rfind("\'")-code.find("\'")-1);
  icu::UnicodeString converter = icu::UnicodeString(code.c_str(), code.length());
  icu::UnicodeString newUstring = converter.unescape();
  code = "";
  newUstring.toUTF8String(code);
  myCCfile << code << endl;
}

string ConvertToLower(string input) {
	for (unsigned long i=0; i<input.length();i++) {
		input[i] = tolower(input[i]);
	}
	return input;
}

void CurlHandler(const string question, ofstream& myCCfile) {

  CURL *curl;
  CURLcode res;
  string data, username, password, temp;
  smatch match;
  regex pattern ("[0-9]*/\"><strong>Accepted</strong></a>");
  vector<string> Submissions;
  vector<string> Code;
  regex codePattern ("""submissionCode: \'.*\'""");
  char const * cookie = "PHPSESSID=ceqsi2msue0yyrb94bo8ktf13epuc7gr; _ga=GA1.2.1984831265.1389075465; NRAGENT=tk=26e67c3be080fab2";
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

    // Enter username and password
    //cout << "Please enter username: " << endl;
    //if (!(cin >> username)) throw "Invalid username";
    //cout << "Please enter password: "<< endl;
    //if (!(cin >> password)) throw "Invalid password";

    // Next we tell LibCurl what HTTP POST data to submit
    //temp = "";
    //temp = "username="+username+"&password="+password;
    //char const * LoginInfo = temp.c_str();
	  //curl_easy_setopt(curl, CURLOPT_POSTFIELDS, LoginInfo);
    //curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, append_to_string);
    //curl_easy_setopt(curl, CURLOPT_WRITEDATA, addressof(data));
    //res = curl_easy_perform(curl);


    if(res != CURLE_OK) {
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
      throw "Login failed: Wrong PHPSESSID or Invalid username/password";
    }
    data = "";
    temp = "";
    temp = "https://leetcode.com/problems/"+question+"/submissions/";
    cout << temp << endl;
    curl_easy_setopt(curl, CURLOPT_URL, temp.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, append_to_string);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, addressof(data));
    res = curl_easy_perform(curl);
    /* Check for errors */ 
    if(res != CURLE_OK) {
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
      throw "Invalid question: page not found";
    }
 	 //cout << data << endl;
    while (regex_search (data,match,pattern)) {
      for (auto x:match) {
        Submissions.push_back(x);
        cout << x << endl;
      }
      data = match.suffix().str();
    }

    if (Submissions.empty()) throw "No available Accepted submission. (Submissions empty)";

    for (unsigned long i=0; i<Submissions.size(); i++) {
      string TempLink = Submissions[i].substr(0, Submissions[i].find("/"));
      TempLink = "https://oj.leetcode.com/submissions/detail/" + TempLink;
      const char * link = TempLink.c_str();
      curl_easy_setopt(curl, CURLOPT_URL, link);
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, append_to_string);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, addressof(data));
      res = curl_easy_perform(curl);

      if(res != CURLE_OK) {
      	fprintf(stderr, "curl_easy_perform() failed: %s\n",
              	curl_easy_strerror(res));
      	throw "No available Accepted submission";
      }
      while (regex_search (data,match,codePattern)) {
        for (auto x:match) {
          Code.push_back(x);
          //cout << x << endl;
        }
        data = match.suffix().str();
      }
      myCCfile << "Submission " << i+1 << endl;
      myCCfile << endl;
      CodePrinter(Code.back(), myCCfile);
      myCCfile << endl;
    }
    /* always cleanup */ 
    curl_easy_cleanup(curl);
  }
}


int main() {
	vector<string> name;
	string number, line, output, filename, question, fileline, token;
	int TestNumber;
	ofstream file, myCCfile;
	file.open("README.md", ios_base::app);
	try {
	  	cout<<"Please enter question name: "<<endl;
	  	if (!getline(cin, line)) throw "Invalid question name";
	  	cout<<"Please enter question number: "<<endl;  
		if (!getline(cin, number)) throw "Invalid number";
		istringstream buffer(number);
		if (!(buffer >> TestNumber)) throw "Invalid question number";
		istringstream input(line);
		while (input >> token) {
			name.push_back(token);
		}
		output = " " + number + " | [";
		for (unsigned long i=0; i<name.size(); i++) {
			if (i==name.size()-1) output += name[i];
			else output += name[i] + " ";
		}
		output += "](https://leetcode.com/problems/";
		question = "";
		for (unsigned long i=0; i<name.size(); i++) {
			if (i==name.size()-1) question += ConvertToLower(name[i]);
			else question += ConvertToLower(name[i]) + "-";
		}
		output += question;
		output += "/) | [";

		for (unsigned long i=0; i<name.size(); i++) filename += name[i];
		filename += ".cc";
		output += filename + "] (./solutions/" + filename + ") |";
		/*while (getline(file, fileline)) {
			if (fileline==output) {
				cout<<filename+" already exists. Going to update." << endl;
				break;
			}
		}*/
		file << output << endl;
		cout << output << endl;
		myCCfile.open("./solutions/" + filename, ios_base::app);
		//if (myCCfile.peek() == std::ifstream::traits_type::eof()) {
			myCCfile <<  "// Yifei Wang" << endl;
			myCCfile << "// LeetCode Question " + number << endl;
		//}
		CurlHandler(question, myCCfile);
		myCCfile.close();
	  
	}
	catch(const char * msg) {
    	cerr << msg << endl;
  	}
  	file.close();
}




