#include <stdio.h>
#include <stdlib.h>

struct Room {
    int roomNo;
    char type[30];
    float price;
    int isBooked;
};

int main() {
    FILE *fp, *temp;
    struct Room r;
    int roomNo, found = 0;

    fp = fopen("rooms.txt", "r");
    temp = fopen("temp.txt", "w");

    if (fp == NULL) {
        printf("No room records found.\n");
        return 0;
    }

    printf("Enter Room Number to Check-Out: ");
    scanf("%d", &roomNo);

    while (fscanf(fp, "%d %s %f %d",
                  &r.roomNo, r.type, &r.price, &r.isBooked) != EOF) {

        if (r.roomNo == roomNo && r.isBooked == 1) {
            r.isBooked = 0;
            found = 1;
            printf("Check-out successful for Room %d\n", roomNo);
        }

        fprintf(temp, "%d %s %.2f %d\n",
                r.roomNo, r.type, r.price, r.isBooked);
    }

    fclose(fp);
    fclose(temp);

    remove("rooms.txt");
    rename("temp.txt", "rooms.txt");

    if (!found) {
        printf("Room not found or already available.\n");
    }

    return 0;
}
