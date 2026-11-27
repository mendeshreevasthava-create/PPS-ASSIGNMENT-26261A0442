#include <stdbool.h>
#include <stdio.h>

#define MAX_PLANTS 8
#define MAX_DAYS 8

typedef struct {
    int plant_code;
    double mean;
    int valid_count;
    bool has_valid;
} PlantSummary;

void scan_plants(int grid[MAX_PLANTS][MAX_DAYS],
                 const int plant_codes[MAX_PLANTS],
                 int num_plants,
                 int num_days,
                 PlantSummary out[MAX_PLANTS]) {

    if (num_plants > MAX_PLANTS)
        num_plants = MAX_PLANTS;

    if (num_days > MAX_DAYS)
        num_days = MAX_DAYS;

    for (int p = 0; p < num_plants; p++) {

        double sum = 0.0;
        int cnt = 0;

        for (int d = 0; d < num_days; d++) {

            int val = grid[p][d];

            if (val >= 0) {
                sum += val;
                cnt++;
            }
        }

        out[p].plant_code = plant_codes[p];
        out[p].valid_count = cnt;

        if (cnt > 0) {
            out[p].has_valid = true;
            out[p].mean = sum / cnt;
        }
        else {
            out[p].has_valid = false;
            out[p].mean = 0.0;
        }
    }
}

int main() {

    int grid[MAX_PLANTS][MAX_DAYS] = {
        {10, 20, 30, -1, 40, -1, 50, 60},
        {15, 25, -1, 35, 45, 55, -1, 65},
        {-1, -1, -1, -1, -1, -1, -1, -1}
    };

    int plant_codes[MAX_PLANTS] = {
        101, 102, 103
    };

    PlantSummary out[MAX_PLANTS];

    int num_plants = 3;
    int num_days = 8;

    scan_plants(grid, plant_codes,
                num_plants, num_days, out);

    printf("Plant Code\tValid Count\tAverage\n");

    for (int i = 0; i < num_plants; i++) {

        printf("%d\t\t%d\t\t",
               out[i].plant_code,
               out[i].valid_count);

        if (out[i].has_valid)
            printf("%.2f\n", out[i].mean);
        else
            printf("No valid readings\n");
    }

    return 0;
}
