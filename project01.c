#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX 100

// Define structure
typedef struct {
    char name[50];
    char category[30];
    float supply_price;
    float sale_price;
    int quantity_sold;
} Product;

// 1. Collect one product and display benefit
void collect(Product *p) {
    printf("\nEnter product name: ");
    scanf(" %[^\n]", p->name);
    printf("Enter category: ");
    scanf(" %[^\n]", p->category);
    printf("Enter supply price: ");
    scanf("%f", &p->supply_price);
    printf("Enter sale price: ");
    scanf("%f", &p->sale_price);
    printf("Enter quantity sold: ");
    scanf("%d", &p->quantity_sold);

    float benefit = (p->sale_price - p->supply_price) * p->quantity_sold;
    printf("Benefit for '%s' is: %.2f\n", p->name, benefit);
}

// 2. Collect data for multiple toys
int collectData(Product products[]) {
    int n;
    printf("How many products do you want to enter (max %d)? ", MAX);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nProduct %d:\n", i + 1);
        collect(&products[i]);
    }
    return n;
}

// 3. General benefit
float benefit(Product products[], int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += (products[i].sale_price - products[i].supply_price) * products[i].quantity_sold;
    }
    return total;
}

// 4. Most sold product
char* mostSold(Product products[], int n) {
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (products[i].quantity_sold > products[maxIndex].quantity_sold)
            maxIndex = i;
    }
    return products[maxIndex].name;
}

// 5. Best product (highest benefit)
char* bestProduct(Product products[], int n) {
    int bestIndex = 0;
    float maxBenefit = (products[0].sale_price - products[0].supply_price) * products[0].quantity_sold;

    for (int i = 1; i < n; i++) {
        float currBenefit = (products[i].sale_price - products[i].supply_price) * products[i].quantity_sold;
        if (currBenefit > maxBenefit) {
            maxBenefit = currBenefit;
            bestIndex = i;
        }
    }
    return products[bestIndex].name;
}

// 6. Worst product (lowest (benefit^2)/quantity)
char* worstProduct(Product products[], int n) {
    int worstIndex = 0;
    float b = (products[0].sale_price - products[0].supply_price) * products[0].quantity_sold;
    float minRatio = (b * b) / products[0].quantity_sold;

    for (int i = 1; i < n; i++) {
        float currBenefit = (products[i].sale_price - products[i].supply_price) * products[i].quantity_sold;
        float ratio = (currBenefit * currBenefit) / products[i].quantity_sold;
        if (ratio < minRatio) {
            minRatio = ratio;
            worstIndex = i;
        }
    }
    return products[worstIndex].name;
}

// 7. Main function to demonstrate all
int main() {
    Product products[MAX];
    int n = collectData(products);

    printf("\n--- Report ---\n");
    printf("Total Benefit: %.2f\n", benefit(products, n));
    printf("Most Sold Product: %s\n", mostSold(products, n));
    printf("Best Product: %s\n", bestProduct(products, n));
    printf("Worst Product: %s\n", worstProduct(products, n));

    return 0;
}