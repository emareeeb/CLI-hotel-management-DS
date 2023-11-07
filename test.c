// #include <stdio.h>
// #include <string.h>

// // Define a structure to store customer information
// struct Customer {
//     char name[50];
//     char phoneNumber[15];
//     char address[100];
// };

// // Function to check if a phone number exists in the customer list
// int findCustomer(struct Customer customers[], int numCustomers, char phoneNumber[]) {
//     for (int i = 0; i < numCustomers; i++) {
//         if (strcmp(customers[i].phoneNumber, phoneNumber) == 0) {
//             return i; // Return the index of the customer
//         }
//     }
//     return -1; // Return -1 if not found
// }

// // Function to save customer data to a text file
// void saveCustomerData(struct Customer customers[], int numCustomers) {
//     FILE *file = fopen("customer_data.txt", "w");
//     if (file == NULL) {
//         printf("Error: Cannot open customer data file for writing.\n");
//         return;
//     }

//     for (int i = 0; i < numCustomers; i++) {
//         fprintf(file, "%s %s %s\n", customers[i].name, customers[i].phoneNumber, customers[i].address);
//     }

//     fclose(file);
// }

// // Function to load customer data from a text file
// int loadCustomerData(struct Customer customers[]) {
//     FILE *file = fopen("customer_data.txt", "r");
//     if (file == NULL) {
//         return 0; // File doesn't exist or cannot be opened
//     }

//     int numCustomers = 0;
//     while (fscanf(file, "%s %s %s", customers[numCustomers].name, customers[numCustomers].phoneNumber, customers[numCustomers].address) != EOF) {
//         numCustomers++;
//     }

//     fclose(file);
//     return numCustomers;
// }

// int standardRooms = 5;
// int deluxeRooms = 5;
// int familyRooms = 5;
// int suiteRooms = 5;

// void displayAvailability() {
//     printf("Room Availability:\n");
//     printf("1) Standard: %d\n", standardRooms);
//     printf("2) Deluxe: %d\n", deluxeRooms);
//     printf("3) Family: %d\n", familyRooms);
//     printf("4) Suite: %d\n", suiteRooms);
// }

// int main() {
//     struct Customer customers[100]; // Assume a maximum of 100 customers
//     int numCustomers = 0;

//     // Load customer data from the text file
//     numCustomers = loadCustomerData(customers);

//     printf("Hello! Welcome to our hotel.\n");
//     printf("Are you a previous guest? (yes/no): ");

//     char choice[5];
//     scanf("%s", choice);

//     if (strcmp(choice, "yes") == 0) {
//         // Returning customer
//         char phoneNumber[15];
//         printf("Please enter your phone number: ");
//         scanf("%s", phoneNumber);

//         int customerIndex = findCustomer(customers, numCustomers, phoneNumber);
//         if (customerIndex != -1) {
//             printf("Hello, %s!\n", customers[customerIndex].name);
//         } else {
//             printf("Sorry, we couldn't find your information in our records.\n");
//         }
//     } else if (strcmp(choice, "no") == 0) {
//         // New customer
//         struct Customer newCustomer;

//         printf("Please enter your name: ");
//         scanf("%s", newCustomer.name);

//         printf("Please enter your phone number: ");
//         scanf("%s", newCustomer.phoneNumber);

//         printf("Please enter your address: ");
//         scanf("%s", newCustomer.address);

//         customers[numCustomers] = newCustomer;
//         numCustomers++;

//         printf("Thank you for registering, %s!\n", newCustomer.name);

//         // Save the updated customer data to the text file
//         saveCustomerData(customers, numCustomers);
//     } else {
//         printf("Invalid choice. Please enter 'yes' or 'no'.\n");
//     }

//     int menuChoice;

//     while (1) {
//         printf("Choose a service:\n");
//         printf("1) New Booking\n");
//         printf("2) Checkout\n");
//         printf("3) Self Booking\n");
//         printf("4) Room Service\n");
//         printf("5) Function Hall\n");
//         printf("6) Staff Management\n");
//         printf("7) Generate Bill\n");
//         printf("8) Quit\n");

//         printf("Enter your choice: ");
//         scanf("%d", &menuChoice);

//         switch (menuChoice) {
//             case 1:
//                 printf("You selected New Booking.\n");
//                 while (1) {
//                     displayAvailability();
//                     int roomChoice;
//                     printf("Choose a room type (1-4) or enter 0 to go back: ");
//                     scanf("%d", &roomChoice);

//                     if (roomChoice == 0) {
//                         break; // Go back to the main menu
//                     } else if (roomChoice >= 1 && roomChoice <= 4) {
//                         int *roomType;
//                         int *roomAvailability;

//                         switch (roomChoice) {
//                             case 1:
//                                 roomType = &standardRooms;
//                                 roomAvailability = &standardRooms;
//                                 break;
//                             case 2:
//                                 roomType = &deluxeRooms;
//                                 roomAvailability = &deluxeRooms;
//                                 break;
//                             case 3:
//                                 roomType = &familyRooms;
//                                 roomAvailability = &familyRooms;
//                                 break;
//                             case 4:
//                                 roomType = &suiteRooms;
//                                 roomAvailability = &suiteRooms;
//                                 break;
//                         }

//                         if (*roomType > 0) {
//                             (*roomType)--;
//                             printf("Room booked successfully.\n");
//                         } else {
//                             printf("Room not available.\n");
//                         }
//                     } else {
//                         printf("Invalid room choice. Please select a valid option.\n");
//                     }
//                 }
//                 break;
//             case 2:
//                 printf("You selected Checkout.\n");
//                 displayAvailability();

//                 int checkoutChoice;
//                 printf("Choose the type of room to checkout (1-4) or enter 0 to go back: ");
//                 scanf("%d", &checkoutChoice);

//                 if (checkoutChoice == 0) {
//                     break; // Go back to the main menu
//                 } else if (checkoutChoice >= 1 && checkoutChoice <= 4) {
//                     int *roomType;
//                     int *roomAvailability;

//                     switch (checkoutChoice) {
//                         case 1:
//                             roomType = &standardRooms;
//                             roomAvailability = &standardRooms;
//                             break;
//                         case 2:
//                             roomType = &deluxeRooms;
//                             roomAvailability = &deluxeRooms;
//                             break;
//                         case 3:
//                             roomType = &familyRooms;
//                             roomAvailability = &familyRooms;
//                             break;
//                         case 4:
//                             roomType = &suiteRooms;
//                             roomAvailability = &suiteRooms;
//                             break;
//                     }

//                     (*roomType)++;
//                     printf("Checkout completed successfully. Room is now available.\n");
//                 } else {
//                     printf("Invalid room choice. Please select a valid option.\n");
//                 }
//                 break;
//             case 3:
//                 printf("You selected Self Booking.\n");
//                 // Add self-booking logic here
//                 break;
//             case 4:
//                 printf("You selected Room Service.\n");
//                 // Add room service logic here
//                 break;
//             case 5:
//                 printf("You selected Function Hall.\n");
//                 // Add function hall logic here
//                 break;
//             case 6:
//                 printf("You selected Staff Management.\n");
//                 // Add staff management logic here
//                 break;
//             case 7:
//                 printf("You selected Generate Bill.\n");
//                 // Add generate bill logic here
//                 break;
//             case 8:
//                 printf("Goodbye!\n");
//                 return 0;
//             default:
//                 printf("Invalid choice. Please select a valid option.\n");
//         }
//     }

//     return 0;
// }
