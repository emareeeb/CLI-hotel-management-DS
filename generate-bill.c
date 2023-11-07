#include<stdio.h>
#include<string.h>
int main() {
    int choice;

    while (1) {
        printf("Choose a service:\n");
        printf("1) New Booking\n");
        printf("2) Checkout\n");
        printf("3) Self Booking\n");
        printf("4) Room Service\n");
        printf("5) Function Hall\n");
        printf("6) Staff Management\n");
        printf("7) Generate Bill\n");
        printf("8) Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // ... (existing code for New Booking)
                break;
            case 2:
                // ... (existing code for Checkout)
                break;
            case 3:
                // ... (existing code for Self Booking)
                break;
            case 4:
                // ... (existing code for Room Service)
                break;
            case 5:
                // ... (existing code for Function Hall)
                break;
            case 6:
                // ... (existing code for Staff Management)
                break;
            case 7:
                printf("You selected Generate Bill.\n");
                // Add generate bill logic here
                break;
            case 8:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}
