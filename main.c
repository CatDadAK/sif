#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void showMenu() {
    printf("\n--- \033[1;36mVelkommen til SiF\033[0m ---\n");
    printf("\nHvad ønsker du at arbejde med?\n");
    printf("1: Wien's forskydningslov\n");
    printf("2: Hubble's lov\n");
    printf("3: Frekvens fra bølgelængde og hastighed\n");
    printf("4: Bohr-modellen (atomfysik)\n");

}

void bohrMenu(){
    printf("\n--- \033[1;36mBohr-modellen\033[0m ---\n");
    printf("\nHvad ønsker du at udregne?\n");
    printf("1: Fotonemission i hydrogen atomet\n");
    printf("2: Fotonabsorption i hydrogen atomet\n");
    printf("3: Energiniveau i en skal i hydrogenatomet\n");
}


int getUserInput() {
    int choice;
    printf("\nIndtast dit valg: ");
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

double calcEnergy(int n) {
    return -13.6 / (n * n);
}

double calcPhotonEnergy(int n1, int n2){
    double E1 = calcEnergy(n1);
    double E2 = calcEnergy(n2);
    return fabs(E2-E1);
}


int main() {
    int choice;
    
    showMenu();
    choice = getUserInput();

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

else if (choice == 4){

    bohrMenu();

    int bohrChoice;
    printf("\nindtast dit valg: ");
    scanf("%d", &bohrChoice);


if (bohrChoice == 1) {
    int n1, n2;

    printf("start skal (n1): " );
    scanf("%d", &n1);

    printf("slut skal (n2): ");
    scanf("%d", &n2);

    double energy = calcPhotonEnergy(n1, n2);
    printf("udsendt foton energi: %f eV\n", energy);

}

else if (bohrChoice == 2){
    int n1, n2;

    printf("Start skal (n1): ");
    scanf("%d", &n1);

    printf("Slut skal (n2): ");
    scanf("%d", &n2);

    double energy = calcPhotonEnergy(n1, n2);
    printf("absorberet energi: %f eV\n", energy);

}

else if (bohrChoice == 3) {
    int n;
    
    printf("indtast skal (n): ");
    scanf("%d", &n);

    double energy = calcEnergy(n);
    printf("Energi for skal %d: %f eV\n", n, energy);

}

else {
    printf("\033[1;31mFejl: vælg en gyldig mulighed\033[0m\n");

}

} 

else {
    printf("\033[1;31mFejl: vælg en gyldig mulighed\033[0m\n");

}
    

return 0;

}  