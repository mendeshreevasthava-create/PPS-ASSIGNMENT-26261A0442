#include <stdio.h>

int main(void) {
    int id;
    double ph, turb;

    int valid_records = 0;
    int hazard_count = 0;
    int caution_count = 0;
    int incomplete_or_invalid_count = 0;

    printf("Enter records (ID pH Turbidity):\n");

    while (scanf("%d", &id) == 1) {

        // Stop when sentinel value is entered
        if (id == -9999) {
            break;
        }

        // Read pH and turbidity
        if (scanf("%lf %lf", &ph, &turb) != 2) {
            incomplete_or_invalid_count++;
            break;
        }

        // Check missing values
        if (ph == -1.0 || turb == -1.0) {
            incomplete_or_invalid_count++;
            continue;
        }

        // Check invalid values
        if (ph < 0.0 || ph > 14.0 || turb < 0.0) {
            incomplete_or_invalid_count++;
            continue;
        }

        // Count valid records
        valid_records++;

        // Classify records
        if (ph < 6.5 || ph > 8.5 || turb > 5.0) {
            hazard_count++;
        }
        else if (ph < 7.0 || turb > 3.0) {
            caution_count++;
        }
    }

    printf("\nValid = %d\n", valid_records);
    printf("Hazard = %d\n", hazard_count);
    printf("Caution = %d\n", caution_count);
    printf("Missing/Invalid = %d\n",
           incomplete_or_invalid_count);

    return 0;
}
