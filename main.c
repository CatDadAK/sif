#include <stdio.h>
#include <stdlib.h>

void showMenu() {
    system("cls");
    printf("Velkommen til SiF\n");
    printf("Hvad ønsker du at arbejde med?\n");
    printf("1: Wien's forskydningslov\n");
    printf("2: Hubble's lov\n");
    printf("3: Frekvens fra bølgelængde og hastighed\n");
}

int getUserInput() {
    int choice;
    printf("Indtast dit valg: ");
    scanf("%d", &choice);
    return choice;
}

double calcFrequency(double wavelength, double speed) {
    return speed / wavelength;
}

int main() {
    showMenu();
    int choice = getUserInput();

    if (choice == 3) {
        double wavelength, speed;
        printf("Indtast bølgelængde (m): ");
        scanf("%lf", &wavelength);
        printf("Indtast hastighed (m/s): ");
        scanf("%lf", &speed);

        double frequency = calcFrequency(wavelength, speed);
        printf("Frekvens: %f Hz\n", frequency);
    }
}