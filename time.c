#include<stdio.h>
#include<time.h>
#include"globals.h"

void get_date_time()
{
    int hour,minute,second,day,month,year;
    time_t now;   // `time_t` is an arithmetic time type
    // Obtain current time
    // `time()` returns the current time of the system as a `time_t` value

    time(&now);
    // Convert to local time format and print to stdout
    // printf("Today is %s", ctime(&now));

    // localtime converts a `time_t` value to calendar time and
    // returns a pointer to a `tm` structure with its members
    // filled with the corresponding values
    struct tm *local=localtime(&now);

    hour = local->tm_hour;         // get hours since midnight (0-23)
    minute = local->tm_min;        // get minutes passed after the hour (0-59)
    second = local->tm_sec;        // get seconds passed after a minute (0-59)
    day = local->tm_mday;            // get day of month (1 to 31)
    month = local->tm_mon + 1;      // get month of year (0 to 11)
    year = local->tm_year + 1900;   // get year since 1900

    // print the current date
    // printf("Date is: %02d/%02d/%d\n", day, month, year);
    // printf("Time is: %02d-%02d-%d\n", hour, minute, second);
}

unsigned long get_timestamp()
{
    return (unsigned long)time(NULL);
}

char *convert_timestamp_to_time(unsigned long timestamp)
{
    // int hour,minute,second,
    int day,month,year;
    static char buf[30];
    time_t now;
    time(&now);
    struct tm *local=localtime(&now);

    // hour = local->tm_hour;         // get hours since midnight (0-23)
    // minute = local->tm_min;        // get minutes passed after the hour (0-59)
    // second = local->tm_sec;        // get seconds passed after a minute (0-59)
    day = local->tm_mday;            // get day of month (1 to 31)
    month = local->tm_mon + 1;      // get month of year (0 to 11)
    year = local->tm_year + 1900;   // get year since 1900

    // print the current date
    // printf("Date is: %02d/%02d/%d\n", day, month, year);
    // printf("Time is: %02d-%02d-%d\n", hour, minute, second);
    sprintf(buf,"%d-%d-%d",day-1,month-1,year);
    return buf;
}

char *convert_timestamp_to_time1(unsigned long timestamp)
{
    time_t rawtime = timestamp;
    struct tm ts;
    // char buf[80];
    static char buf[30]; 
    // Format time, "ddd yyyy-mm-dd hh:mm:ss zzz"
    ts = *localtime(&rawtime);
    // strftime(buf, sizeof(buf), "%a %Y-%m-%d %H:%M:%S %Z", &ts);
    strftime(buf, sizeof(buf), "%Y-%m-%d", &ts);
    // printf("%s\n", buf);
    return buf;
}

// int main()
// {
//     get_date_time();
//     unsigned long t=get_timestamp();
//     printf("%lu",t);
//     convert_timestamp_to_time(t);
// }