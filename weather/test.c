#include <stdio.h>
#include "weather.h"

int main(void){
 /*char *forecast_raw = getforecast();
 //printf("%s", forecast_raw);
 json_t *forecast_json = json_pack(forecast_raw);
 
 size_t i;
 json_t *root;
 json_error_t error;

 root = json_loads(forecast_raw, 0, &error);
 if(!root) {
   printf("error during JSON load");
 }
 json_t * data, *periods;
  json_t *current_forecast;
  data = json_object_get(json_object_get(root, "properties"),"periods");

  periods = json_array_get(data, "periods");
  printf("%s %i", json_string_value(json_object_get(json_object_get(root,"properties"),"updated")), json_array_size(data));

  json_t *cur_forcast = json_array_get(data, 0);

  for(int i = 0; i < json_array_size(data); i++){
    json_t *name, *windSpeed, *isDaytime, *temperature;
    json_t *tmp = json_array_get(data, i); 
    temperature = json_object_get(tmp, "temperature");
    printf("%s",json_string_value(temperature));
    

  }*/
  
  char degree = 248;
  int temp = gettemperature();
  printf("\n%i%cC\n", temp, degree);

 //json_t *periods = json_object_get(root,"periods");
 return 0;
 // return printf("%d", getforecast());
}
