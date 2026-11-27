#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define BUF_SZ 32

bool exact_str_equal(const char *a, const char *b)
{
    if (a == NULL || b == NULL)
        return false;

    size_t i = 0;

    while (a[i] != '\0' && b[i] != '\0')
    {
        if (a[i] != b[i])
            return false;

        i++;
    }

    return (a[i] == '\0' && b[i] == '\0');
}

void format_station_status(char out[BUF_SZ],
                           const char *station,
                           const char *status)
{
    if (out == NULL)
        return;

    if (station == NULL)
        station = "";

    if (status == NULL)
        status = "";

    snprintf(out, BUF_SZ, "%.13s / %.14s", station, status);
}

int main()
{
    char output[BUF_SZ];

    const char *station = "HYDERABAD";
    const char *status = "ACTIVE";

    format_station_status(output, station, status);

    printf("Station Status: %s\n", output);

    if (exact_str_equal("ACTIVE", "ACTIVE"))
        printf("Strings are equal.\n");
    else
        printf("Strings are not equal.\n");

    return 0;
}
