#include <stdio.h>
#include <locale.h>


int main() {
    setlocale(LC_ALL, "Rus");

    double h, w, d, rho_dsp = 0.65, rho_dvp = 0.85, rho_wood = 0.7;
    printf("Введите высоту, ширину и глубину шкафа (см): ");
    scanf("%lf %lf %lf", &h, &w, &d);

    int sh_ct = (int)((h - 3) / 41.5);
    double volume_1 = (w - 3)*d*1.5;
    double backwall = w*h*0.5;
    double walls = 2*h*d*1.5;
    double lids = 2*w*d*1.5;
    double doors = h*w;
    double total_dsp_volume = sh_ct*volume_1 + walls + lids;
    double mass_dsp = total_dsp_volume * rho_dsp;
    double mass_dvp = backwall*rho_dvp;
    double mass_wood = doors*rho_wood;
    double mass = (mass_dsp + mass_dvp + mass_wood)/1000;
    printf("Massa = %.2lf kg, (количество полок: %d)\n", mass, sh_ct);
    return 0;
}


