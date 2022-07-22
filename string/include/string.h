#ifndef STRING
#define STRING

int int_to_string(char *target, int val);

int double_to_string(char *target, double val);

int float_to_string(char *target, float val);

int reverse();

char *to_lower_case(char *s);

char *to_upper_case(char *s);

/*
*   Set start/stop as NULL to skip this limit
*/

int substring(char *string, int start, int stop);



#endif 