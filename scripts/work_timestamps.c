#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_time(char times[])
{
    if (times[0] == '\0')
    {
        return 0;
    }

    // puts(times);
    // printf("%c", times[0]);
    char startHour[3];
    char startMinute[3];
    char endHour[3];
    char endMinute[3];

    // printf("%s\n", strncpy(startHour, times+0, 2));
    // printf("%s\n", strncpy(startMinute, times+2, 2));
    // printf("%s\n", strncpy(endHour, times+5, 2));
    // printf("%s\n", strncpy(endMinute, times+7, 2));
    strncpy(startHour, times, 2);
    strncpy(startMinute, &times[2], 2);
    strncpy(endHour, &times[5], 2);
    strncpy(endMinute, &times[7], 2);

    startHour[2] = '\0';
    startMinute[2] = '\0';
    endHour[2] = '\0';
    endMinute[2] = '\0';

    // puts(startHour);
    // puts(startMinute);
    // puts(endHour);
    // puts(endMinute);

    int sH = atoi(startHour);
    int sM = atoi(startMinute);
    int eH = atoi(endHour);
    int eM = atoi(endMinute);
    // printf("Start hour: %d\n", sH);
    // printf("Start minute: %d\n", sM);
    // printf("End Hour: %d\n", eH);
    // printf("End Minute: %d\n", eM);

    return (eH * 60 + eM) - (sH * 60 + sM);
}

int main()
{

    char sunday_times[10];
    char monday_times[10];
    char tuesday_times[10];
    char wednesday_times[10];
    char thursday_times[10];
    char friday_times[10];
    char saturday_times[10];

    // puts is used vs printf because puts can only output strings
    puts("This program takes in times for each day and outputs the amount of time worked throughout the week\nIf you did not work on that day, do not input anything.\nPlease enter times in military time in the format TTTT-TTTT\n");
    puts("Sunday Times: ");
    fgets(sunday_times, sizeof(sunday_times), stdin);
    int sunday_minutes = find_time(sunday_times);
    // printf("%lu", sizeof(sunday_times));

    printf("Monday Times: ");
    getchar();
    fgets(monday_times, sizeof(monday_times), stdin);
    int monday_minutes = find_time(monday_times);

    puts("Tuesday Times: ");
    getchar();
    fgets(tuesday_times, sizeof(tuesday_times), stdin);
    int tuesday_minutes = find_time(tuesday_times);

    puts("Wednesday Times: ");
    getchar();
    fgets(wednesday_times, sizeof(wednesday_times), stdin);
    int wednesday_minutes = find_time(wednesday_times);

    puts("Thursday Times: ");
    fgets(thursday_times, sizeof(thursday_times), stdin);
    getchar();
    int thursday_minutes = find_time(thursday_times);

    puts("Friday Times: ");
    getchar();
    fgets(friday_times, sizeof(friday_times), stdin);
    int friday_minutes = find_time(friday_times);

    puts("Saturday Times: ");
    getchar();
    fgets(saturday_times, sizeof(saturday_times), stdin);
    int saturday_minutes = find_time(saturday_times);

    int sum = 0;

    sum += sunday_minutes;
    sum += monday_minutes;
    sum += tuesday_minutes;
    sum += wednesday_minutes;
    sum += thursday_minutes;
    sum += friday_minutes;
    sum += saturday_minutes;

    printf("%d + %d + %d + %d + %d + %d + %d = %d minutes\n", sunday_minutes, monday_minutes, tuesday_minutes, wednesday_minutes, thursday_minutes, friday_minutes, saturday_minutes, sum);

    int hours = sum / 60;
    int minutes = sum % 60;

    printf("%d hours and %d minutes", hours, minutes);

    return 0;
}
