#include <math.h>
#include <stdio.h>

typedef enum {
    ERR_NONE = 0,
    ERR_NULL_PTR = -1,
    ERR_INVALID_PARAM = -2,
    ERR_DOMAIN = -3
} ErrCode;

// Input validation function
ErrCode validate_inputs(double raw1, double raw2,
                        double *out_norm1, double *out_norm2) {

    if (out_norm1 == NULL || out_norm2 == NULL) {
        return ERR_NULL_PTR;
    }

    if (!isfinite(raw1) || !isfinite(raw2) ||
        raw1 <= 0.0 || raw2 < 0.0) {
        return ERR_INVALID_PARAM;
    }

    *out_norm1 = raw1;
    *out_norm2 = raw2;

    return ERR_NONE;
}

// Dose calculation function
ErrCode compute_doses(double factor, double flow,
                      double *out_dose1, double *out_dose2) {

    if (out_dose1 == NULL || out_dose2 == NULL) {
        return ERR_NULL_PTR;
    }

    if (!isfinite(factor) || !isfinite(flow) ||
        factor <= 0.0 || flow < 0.0) {
        return ERR_DOMAIN;
    }

    double d1 = factor * flow;
    double d2 = 0.5 * d1;

    if (!isfinite(d1) || !isfinite(d2) || d1 > 100.0) {
        return ERR_DOMAIN;
    }

    *out_dose1 = d1;
    *out_dose2 = d2;

    return ERR_NONE;
}

// Main function
int main(void) {

    double raw1, raw2;
    double norm1 = 0.0, norm2 = 0.0;
    double dose1 = 0.0, dose2 = 0.0;

    ErrCode status;

    printf("Enter factor and flow: ");

    if (scanf("%lf %lf", &raw1, &raw2) != 2) {
        printf("Invalid input.\n");
        return 1;
    }

    // Validate inputs
    status = validate_inputs(raw1, raw2, &norm1, &norm2);

    if (status != ERR_NONE) {
        printf("Input validation failed. Error code: %d\n", status);
        return 1;
    }

    printf("Normalized Factor = %.2f\n", norm1);
    printf("Normalized Flow = %.2f\n", norm2);

    // Calculate doses
    status = compute_doses(norm1, norm2, &dose1, &dose2);

    if (status != ERR_NONE) {
        printf("Dose calculation failed. Error code: %d\n", status);
        return 1;
    }

    printf("Dose 1 = %.2f\n", dose1);
    printf("Dose 2 = %.2f\n", dose2);

    printf("Calculation successful.\n");

    return 0;
}
