#include <stdio.h>
#include <curl/curl.h>
#include <jansson.h>
#include <string.h>
#include <stdio.h>

struct string {
  char *ptr;
  size_t len;
};

void init_string(struct string *s) {
  s->len = 0;
  s->ptr = malloc(s->len+1);
  if (s->ptr == NULL) {
    fprintf(stderr, "malloc() failed\n");
    exit(EXIT_FAILURE);
  }
  s->ptr[0] = '\0';
}

static size_t write_callback(char *ptr, size_t size, size_t nmemb, struct string *userdata){
  size_t new_len = userdata->len + size*nmemb;
  userdata->ptr = realloc(userdata->ptr, new_len + 1);
  if(userdata->ptr == NULL){ 
    exit(EXIT_FAILURE);
  }

  memcpy(userdata->ptr + userdata->len, ptr, size * nmemb);
  userdata->ptr[new_len] = '\0';
  userdata->len = new_len;

  return size * nmemb;
}

void init_curl(){
  curl_global_init(CURL_GLOBAL_ALL);
}

void cleanup_curl(){
  curl_global_cleanup();
}

/*
 * This function stores the day's forecast using the 
 * National Weather Service (NWS) API.
 * 
 * https://api.weather.gov
 * https://weather-gov.github.io/api/
 */
char* getforecast(){
  CURL *curl;
  CURLcode res;
  struct string data;
  curl = curl_easy_init();
  if(curl) {
  
    init_string(&data);

    curl_easy_setopt(curl, CURLOPT_URL, "https://api.weather.gov/gridpoints/FWD/91,110/forecast");
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/5.0 (Windows NT x.y; rv:10.0) Gecko/20100101 Firefox/10.0");   
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
    res = curl_easy_perform(curl);


    if(res != CURLE_OK) {
      fprintf(stderr, "curl failed: %s\n", curl_easy_strerror(res));
    }

    curl_easy_cleanup(curl);
  }
  
  //printf("%s\n", data.ptr);
  free(data.ptr);

  cleanup_curl();

  printf("Completed and cleaned up curl.");
  return data.ptr;
}
