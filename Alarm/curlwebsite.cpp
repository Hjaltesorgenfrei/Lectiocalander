<<<<<<< HEAD
#include "curlwebsite.h"
#include <curl/curl.h>
#include <string>
#include <iostream>

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}

std::string curlwebsite(std::string urlpassed)
{
	CURL *curl;
	CURLcode res;
	std::string readBuffer;

	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, urlpassed.c_str());		//sets the curl website to the url passed.
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);		//Perform the request, res will get the return code	
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);	//sets callback as WriteCallback
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);	//sets curl to write data to readBuffer
		res = curl_easy_perform(curl);
		if (res != CURLE_OK)	// Check for errors
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
				curl_easy_strerror(res));

		curl_easy_cleanup(curl);		// always cleanup
	}
	return (readBuffer);
=======
#include "curlwebsite.h"
#include <curl/curl.h>
#include <string>
#include <iostream>

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}

std::string curlwebsite(std::string urlpassed)
{
	CURL *curl;
	CURLcode res;
	std::string readBuffer;

	curl = curl_easy_init();
	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, urlpassed.c_str());		//sets the curl website to the url passed.
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);		//Perform the request, res will get the return code	
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);	//sets callback as WriteCallback
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);	//sets curl to write data to readBuffer
		res = curl_easy_perform(curl);
		if (res != CURLE_OK)	// Check for errors
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
				curl_easy_strerror(res));

		curl_easy_cleanup(curl);		// always cleanup
	}
	return (readBuffer);
>>>>>>> 951037755ba25e4dd3a6b0b405c0395e047f2ac6
}