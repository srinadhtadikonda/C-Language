#include <stdio.h>
#include <math.h>

int main()
{
    int n, i, j, count, max_count = 0;
    float a[100], sum = 0, mean, median;
    float variance = 0, std;
    float mode = 0, temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Accept array elements
    printf("Enter %d elements:\n", n);

    for(i = 0; i < n; i++)
    {
        scanf("%f", &a[i]);
        sum = sum + a[i];
    }

    // Mean
    mean = sum / n;

    // Sort the array for median
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    // Median
    if(n % 2 == 0)
        median = (a[n / 2 - 1] + a[n / 2]) / 2;
    else
        median = a[n / 2];

    // Mode
    for(i = 0; i < n; i++)
    {
        count = 0;

        for(j = 0; j < n; j++)
        {
            if(a[i] == a[j])
                count++;
        }

        if(count > max_count)
        {
            max_count = count;
            mode = a[i];
        }
    }

    // Variance
    for(i = 0; i < n; i++)
    {
        variance = variance + pow(a[i] - mean, 2);
    }

    variance = variance / n;

    // Standard deviation
    std = sqrt(variance);

    // Display results
    printf("\nMean = %.2f", mean);
    printf("\nMedian = %.2f", median);

    if(max_count == 1)
        printf("\nMode = No mode");
    else
        printf("\nMode = %.2f", mode);

    printf("\nVariance = %.2f", variance);
    printf("\nStandard Deviation = %.2f\n", std);

    return 0;
}
