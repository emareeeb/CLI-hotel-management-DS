#include <stdio.h>

int standardRooms = 5;
int deluxeRooms = 5;
int familyRooms = 5;
int suiteRooms = 5;

void displayAvailability() {
    printf("Room Availability:\n");
    printf("1) Standard: %d\n", standardRooms);
    printf("2) Deluxe: %d\n", deluxeRooms);
    printf("3) Family: %d\n", familyRooms);
    printf("4) Suite: %d\n", suiteRooms);
}

int standardRooms = 5;
int deluxeRooms = 5;
int familyRooms = 5;
int suiteRooms = 5;

void displayAvailability() {
    printf("Room Availability:\n");
    printf("1) Standard: %d\n", standardRooms);
    printf("2) Deluxe: %d\n", deluxeRooms);
    printf("3) Family: %d\n", familyRooms);
    printf("4) Suite: %d\n", suiteRooms);
}

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
        printf("7) Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You selected New Booking.\n");
                while (1) {
                    displayAvailability();
                    int roomChoice;
                    printf("Choose a room type (1-4) or enter 0 to go back: ");
                    scanf("%d", &roomChoice);

                    if (roomChoice == 0) {
                        break; // Go back to the main menu
                    } else if (roomChoice >= 1 && roomChoice <= 4) {
                        int *roomType;
                        int *roomAvailability;

                        switch (roomChoice) {
                            case 1:
                                roomType = &standardRooms;
                                roomAvailability = &standardRooms;
                                break;
                            case 2:
                                roomType = &deluxeRooms;
                                roomAvailability = &deluxeRooms;
                                break;
                            case 3:
                                roomType = &familyRooms;
                                roomAvailability = &familyRooms;
                                break;
                            case 4:
                                roomType = &suiteRooms;
                                roomAvailability = &suiteRooms;
                                break;
                        }

                        if (*roomType > 0) {
                            (*roomType)--;
                            printf("Room booked successfully.\n");
                        } else {
                            printf("Room not available.\n");
                        }
                    } else {
                        printf("Invalid room choice. Please select a valid option.\n");
                    }
                }
                break;
            case 2:
                printf("You selected Checkout.\n");
                // Add checkout logic here
                break;
            case 3:
                printf("You selected Self Booking.\n");
                // Add self-booking logic here
                break;
            case 4:
                printf("You selected Room Service.\n");
                // Add room service logic here
                break;
            case 5:
                printf("You selected Function Hall.\n");
                // Add function hall logic here
                break;
            case 6:
                printf("You selected Staff Management.\n");
                // Add staff management logic here
                break;
            case 7:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}
