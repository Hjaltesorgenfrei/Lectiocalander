#include "curlwebsite.h"
#include <curl/curl.h>
#include <string>

std::string curlwebsite(std::string urlpassed)
{
	CURL *curl;
	CURLcode res;

	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, urlpassed.c_str());
		// example.com is redirected, so we tell libcurl to follow redirection
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

		//Perform the request, res will get the return code
		res = curl_easy_perform(curl);
		// Check for errors
		if (res != CURLE_OK)
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
				curl_easy_strerror(res));

		// always cleanup
		curl_easy_cleanup(curl);
	}
	return ("lol");
}