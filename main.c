#include <stdio.h>
#include <stdlib.h>

void showMenu() {
    system("cls");
    printf("Velkommen til SiF\n");
    printf("Hvad ønsker du at arbejde med?\n");
    printf("1: Wien's forskydningslov\n");
    printf("2: Hubble's lov\n");
    printf("3: Frekvens fra bølgelængde og hastighed\n");
    printf("4: Fotonenergi ved elektronovergang i hydrogen (Bohr-modellen)");

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

double calcWien(double temperature){
    double b = 2.898e-3;
    return b/ temperature;
}




int main() {
    showMenu();
    int choice = getUserInput();

    if (choice == 1) {
        double temp;
        printf("indtast temperatur (Kelvin): ");
        scanf("%lf", &temp);

        double wavelength = calcWien(temp);
        printf("Maks bølgelængde: %e m\n",wavelength);

}
else if (choice == 3) {
        double wavelength, speed;
        printf("Indtast bølgelængde (m): ");
        scanf("%lf", &wavelength);
        printf("Indtast hastighed (m/s): ");
        scanf("%lf", &speed);

        double frequency = calcFrequency(wavelength, speed);
        printf("Frekvens: %f Hz\n", frequency);
 
}

    return 0;

}  