#include <stdio.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LEN 100
#define LINE_BUF 256

char productNames[MAX_PRODUCTS][MAX_NAME_LEN];
int productQuantities[MAX_PRODUCTS];
double productPrices[MAX_PRODUCTS];
int productCount = 0;

int my_strlen(const char *s) {
    int n = 0;
    while (s[n] != '\0') n++;
    return n;
}

int my_strcmp(const char *a, const char *b) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) return (unsigned char)a[i] - (unsigned char)b[i];
        i++;
    }
    return (unsigned char)a[i] - (unsigned char)b[i];
}

void my_strcpy(char *dest, const char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void my_strncpy(char *dest, const char *src, int n) {
    if (n <= 0) return;
    int i = 0;
    while (i < n - 1 && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i++] = '\0';
    while (i < n) {
        dest[i++] = '\0';
    }
}

void readLine(char *buffer, int size) {
    if (fgets(buffer, size, stdin) == NULL) {
        buffer[0] = '\0';
        return;
    }
    int len = my_strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') buffer[len - 1] = '\0';
}

/* find product index by exact (case-sensitive) name */
int findProductIndex(const char *name) {
    for (int i = 0; i < productCount; ++i) {
        if (my_strcmp(productNames[i], name) == 0) return i;
    }
    return -1;
}

void addProduct() {
    if (productCount >= MAX_PRODUCTS) {
        printf("Inventory full. Cannot add more products.\n");
        return;
    }

    char name[MAX_NAME_LEN];
    char line[LINE_BUF];
    int qty;
    double price;

    printf("Enter Product Name: ");
    readLine(name, sizeof(name));
    if (my_strlen(name) == 0) {
        printf("Product name cannot be empty.\n");
        return;
    }

    printf("Enter Quantity (integer): ");
    readLine(line, sizeof(line));
    if (sscanf(line, "%d", &qty) != 1) {
        printf("Invalid quantity. Aborting add.\n");
        return;
    }

    printf("Enter Price (e.g. 19.99): ");
    readLine(line, sizeof(line));
    if (sscanf(line, "%lf", &price) != 1) {
        printf("Invalid price. Aborting add.\n");
        return;
    }

    int idx = findProductIndex(name);
    if (idx >= 0) {
        productQuantities[idx] += qty;
        printf("Product '%s' updated successfully! New quantity: %d\n",
               name, productQuantities[idx]);
    } else {
        my_strncpy(productNames[productCount], name, MAX_NAME_LEN);
        productQuantities[productCount] = qty;
        productPrices[productCount] = price;
        productCount++;
        printf("Product '%s' added successfully!\n", name);
    }
}

void viewInventory() {
    if (productCount == 0) {
        printf("Inventory is empty.\n");
        return;
    }
    printf("\n%-4s %-40s %-10s %-10s\n", "No.", "Product Name", "Quantity", "Price");
    printf("------------------------------------------------------------------\n");
    for (int i = 0; i < productCount; ++i) {
        printf("%-4d %-40s %-10d Rs %.2f\n", i + 1,
               productNames[i], productQuantities[i], productPrices[i]);
    }
    printf("\n");
}

void updateStock() {
    char name[MAX_NAME_LEN];
    char line[LINE_BUF];
    int newQty;

    printf("Enter Product Name to update: ");
    readLine(name, sizeof(name));
    if (my_strlen(name) == 0) {
        printf("Product name cannot be empty.\n");
        return;
    }

    int idx = findProductIndex(name);
    if (idx == -1) {
        printf("Product not found!\n");
        return;
    }

    printf("Current quantity of '%s' is %d.\n", productNames[idx], productQuantities[idx]);
    printf("Enter new quantity (integer): ");
    readLine(line, sizeof(line));
    if (sscanf(line, "%d", &newQty) != 1) {
        printf("Invalid quantity. Aborting update.\n");
        return;
    }

    productQuantities[idx] = newQty;
    printf("Quantity updated successfully for '%s'! New quantity: %d\n",
           productNames[idx], productQuantities[idx]);
}

void deleteProduct() {
    char name[MAX_NAME_LEN];
    printf("Enter Product Name to delete: ");
    readLine(name, sizeof(name));
    if (my_strlen(name) == 0) {
        printf("Product name cannot be empty.\n");
        return;
    }

    int idx = findProductIndex(name);
    if (idx == -1) {
        printf("Product not found!\n");
        return;
    }

    for (int i = idx; i < productCount - 1; ++i) {
        my_strcpy(productNames[i], productNames[i + 1]);
        productQuantities[i] = productQuantities[i + 1];
        productPrices[i] = productPrices[i + 1];
    }
    productCount--;
    printf("Product '%s' deleted successfully!\n", name);
}

void searchProduct() {
    char name[MAX_NAME_LEN];
    printf("Enter Product Name to search: ");
    readLine(name, sizeof(name));
    if (my_strlen(name) == 0) {
        printf("Product name cannot be empty.\n");
        return;
    }

    int idx = findProductIndex(name);
    if (idx == -1) {
        printf("Product not found!\n");
        return;
    }

    printf("Product: %s\nQuantity: %d\nPrice: Rs %.2f\n",
           productNames[idx], productQuantities[idx], productPrices[idx]);
}

void saveInventoryToCSV() {
    FILE *fp = fopen("inventory.csv", "w");
    if (!fp) {
        perror("Failed to open inventory.csv for writing");
        return;
    }

    fprintf(fp, "Product Name,Quantity,Price\n");
    for (int i = 0; i < productCount; ++i) {
        char safeName[MAX_NAME_LEN * 2];
        int j = 0, k = 0;
        while (productNames[i][j] != '\0' && k < (int)(sizeof(safeName) - 2)) {
            if (productNames[i][j] == '"') {
                safeName[k++] = '"';
                safeName[k++] = '"';
            } else {
                safeName[k++] = productNames[i][j];
            }
            j++;
        }
        safeName[k] = '\0';
        fprintf(fp, "\"%s\",%d,%.2f\n", safeName, productQuantities[i], productPrices[i]);
    }
    fclose(fp);
    printf("Inventory saved to inventory.csv\n");
}

int main() {
    char choiceLine[LINE_BUF];
    int choice;
    int running = 1;

    while (running) {
        printf("\n--- Inventory Management System ---\n");
        printf("1. Add Product\n");
        printf("2. View Inventory\n");
        printf("3. Update Stock\n");
        printf("4. Delete Product\n");
        printf("5. Search Product\n");
        printf("6. Save and Exit\n");
        printf("Enter your choice (1-6): ");

        readLine(choiceLine, sizeof(choiceLine));
        if (sscanf(choiceLine, "%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 6.\n");
            continue;
        }

        if (choice == 1) addProduct();
        else if (choice == 2) viewInventory();
        else if (choice == 3) updateStock();
        else if (choice == 4) deleteProduct();
        else if (choice == 5) searchProduct();
        else if (choice == 6) {
            saveInventoryToCSV();
            printf("Exiting program...\n");
            running = 0;
        } else {
            printf("Invalid choice. Please choose between 1 and 6.\n");
        }
    }

    return 0;
}
