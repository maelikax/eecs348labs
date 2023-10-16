#include <stdio.h>
float sales[12];

char *month[] = {
        "January", "February", "March", "April", "May",
        "June", "July", "August", "September",
        "October", "November", "December"
};

void readFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    
    if (file != NULL) {
        for (int i = 0; i < 12; i ++) {
            fscanf(file, "%f", &sales[i]);
        }
        fclose(file);
    }
}

void monthlyReport() {
    printf("Monthly Sales Report 2022:\n\n");
    
    printf("Month\t\tSales\n\n");
    
    for (int i = 0; i < 12; i++) {
        printf("%-10s\t$%.2f\n", month[i], sales[i]);
    }
}

void salesSummary() {
    printf("Sales Summary:\n\n");
    
    int i = 0;
    float minSale = sales[i];
    float maxSale = sales[i];
    int minMonth = 0;
    int maxMonth = 0;
    
    for (i = 0; i < 12; i++) {
        if (sales[i] > maxSale) {
            maxSale = sales[i];
            maxMonth = i;
        }
        if (sales[i] < minSale) {
            minSale = sales[i];
            minMonth = i;
        }
    }
    
    float sum = 0.0;
    
    for (int j = 0; j < 12; j++) {
        sum += sales[j];
    }
    
    float avg = sum / 12;
    
    printf("Minimum Sales:\t$%.2f\t(%s)\n", minSale, month[minMonth]);
    printf("Maximum Sales:\t$%.2f\t(%s)\n", maxSale, month[maxMonth]);
    printf("Average sales:\t$%.2f\n", avg);
}

void sixMonthAvg() {
    printf("Six-Month Moving Average Report:\n\n");
    
    for (int i = 0; i < 7; i ++) {
        float sum = 0.0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        float avg = sum / 6;
        
        printf("%-10s\t- %-10s\t$%.2f\n", month[i], month[i + 5], avg);
    }
}

void salesReport() {
    printf("Sales Report (Highest to Lowest):\n\n");
    printf("Month\t\tSales\n\n");
    
    for (int i = 0; i < 12; i++) {
        for (int j = i + 1; j < 12; j++) {
            if (sales[i] < sales[j]) {
                float temp = sales[i];
                sales[i] = sales[j];
                sales[j] = temp;
                
                char* temp2 = month[i];
                month[i] = month[j];
                month[j] = temp2;
            }
        }
    }
    
    for (int i = 0; i < 12; i++) {
        printf("%-10s\t$%.2f\n", month[i], sales[i]);
    }
}

int main()
{
    char filename[100];
    
    printf("Enter the filename: ");
    scanf("%s", filename);
    
    readFile(filename); 
    
    monthlyReport();
    
    salesSummary();
    
    sixMonthAvg();
    
    salesReport();

    return 0;
}