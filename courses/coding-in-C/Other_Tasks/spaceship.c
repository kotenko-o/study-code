#include <stdio.h>

const unsigned int LIGHT_SPEED = 299792;
const unsigned short NAME_LENGTH = 30;

int main () {
    char class[NAME_LENGTH];
    unsigned int crew;
    unsigned int mission_length;
    unsigned long distance = 4321243214; // kilometer
    double light_speed = (double) distance / LIGHT_SPEED;
    double range = 12312.123;

    printf("Please print class of the ship (up to %i symbols): ", NAME_LENGTH - 1);
    scanf("%30s", class);
    printf("Please print number of crew members: ");
    if (scanf("%u", &crew) != 1) {
        printf("Ungueltige Eingabe\n");
        return 1;
    }
    printf("Please print number of mission days: ");
    if (scanf("%u", &mission_length) != 1) {
        printf("Ungueltige Eingabe\n");
        return 1;
    }

    printf("%-30s%s\n", "Name", "Value");
    printf("---------------------------------\n");
    printf("%-30s%s\n", "Name", class);
    printf("%-30s%u\n", "Crew count", crew);
    printf("%-30s%u\n","Mission length, days", mission_length);
    printf("%-30s%ld\n","Distance traveled, km", distance);
    printf("%-30s%8.2f\n","% of light-speed", light_speed);
    printf("%-30s%8.3f\n","Current range, km", range);

    return 0;
}