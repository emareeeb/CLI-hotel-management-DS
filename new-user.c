#include <stdio.h>
#include <string.h>

// Define a structure to store customer information
struct Customer {
    char name[50];
    char phoneNumber[15];
    char address[100];
};

// Function to check if a phone number exists in the customer listno
int findCustomer(struct Customer customers[], int numCustomers, char phoneNumber[]) {
    for (int i = 0; i < numCustomers; i++) {
        if (strcmp(customers[i].phoneNumber, phoneNumber) == 0) {
            return i; // Return the index of the customer
        }
    }
    return -1; // Return -1 if not found
}

// Function to save customer data to a text file
void saveCustomerData(struct Customer customers[], int numCustomers) {
    FILE *file = fopen("customer_data.txt", "w");
    if (file == NULL) {
        printf("Error: Cannot open customer data file for writing.\n");
        return;
    }

    for (int i = 0; i < numCustomers; i++) {
        fprintf(file, "%s %s %s\n", customers[i].name, customers[i].phoneNumber, customers[i].address);
    }

    fclose(file);
}

// Function to load customer data from a text file
int loadCustomerData(struct Customer customers[]) {
    FILE *file = fopen("customer_data.txt", "r");
    if (file == NULL) {
        return 0; // File doesn't exist or cannot be opened
    }

    int numCustomers = 0;
    while (fscanf(file, "%s %s %s", customers[numCustomers].name, customers[numCustomers].phoneNumber, customers[numCustomers].address) != EOF) {
        numCustomers++;
    }

    fclose(file);
    return numCustomers;
}

int main() {
    struct Customer customers[100]; // Assume a maximum of 100 customers
    int numCustomers = 0;

    // Load customer data from the text file
    numCustomers = loadCustomerData(customers);

    printf("Hello! Welcome to our hotel.\n");
    printf("Are you a previous guest? (yes/no): ");

    char choice[5];
    scanf("%s", choice);

    if (strcmp(choice, "yes") == 0) {
        // Returning customer
        char phoneNumber[15];
        printf("Please enter your phone number: ");
        scanf("%s", phoneNumber);

        int customerIndex = findCustomer(customers, numCustomers, phoneNumber);
        if (customerIndex != -1) {
            printf("Hello, %s!\n", customers[customerIndex].name);
        } else {
            printf("Sorry, we couldn't find your information in our records.\n");
        }
    } else if (strcmp(choice, "no") == 0) {
        // New customer
        struct Customer newCustomer;

        printf("Please enter your name: ");
        scanf("%s", newCustomer.name);

        printf("Please enter your phone number: ");
        scanf("%s", newCustomer.phoneNumber);

        printf("Please enter your address: ");
        scanf("%s", newCustomer.address);

        customers[numCustomers] = newCustomer;
        numCustomers++;

        printf("Thank you for registering, %s!\n", newCustomer.name);

        // Save the updated customer data to the text file
        saveCustomerData(customers, numCustomers);
    } else {
        printf("Invalid choice. Please enter 'yes' or 'no'.\n");
    }

    return 0;
}
