#include <stdio.h>

#define MAX_SPOTS 50

int spots[MAX_SPOTS];
int num_spots;

void print_status() {
    printf("Current parking lot status:\n");
    for (int i = 0; i < num_spots; i++) {
        if (spots[i] == 0) {
            printf("Spot %d: Empty\n", i+1);
        } else {
            printf("Spot %d: Occupied\n", i+1);
        }
    }
}

void enter_car() {
    for (int i = 0; i < num_spots; i++) {
        if (spots[i] == 0) {
            spots[i] = 1;
            printf("Car parked in spot %d.\n", i+1);
            return;
        }
    }
    printf("Sorry, the parking lot is full.\n");
}

void exit_car() {
    int spot_num;
    printf("Enter spot number: ");
    scanf("%d", &spot_num);
    if (spot_num < 1 || spot_num > num_spots) {
        printf("Invalid spot number.\n");
        return;
    }
    if (spots[spot_num-1] == 0) {
        printf("That spot is already empty.\n");
        return;
    }
    spots[spot_num-1] = 0;
    printf("Car exited from spot %d.\n", spot_num);
}

int main() {
    printf("Welcome to the parking lot management system.\n");
    printf("Please enter the number of parking spots: ");
    scanf("%d", &num_spots);
    for (int i = 0; i < num_spots; i++) {
        spots[i] = 0;
    }
    while (1) {
        printf("\n");
        printf("1. Print parking lot status\n");
        printf("2. Enter a car\n");
        printf("3. Exit a car\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                print_status();
                break;
            case 2:
                enter_car();
                break;
            case 3:
                exit_car();
                break;
            case 4:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
