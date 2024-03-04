#include <iostream>
using namespace std;
//calcula salario doble o salario 13
float calcSalario13(float ChristmasSalary, float salary, int mesesWrkng) {
    if (mesesWrkng >= 12) {
        mesesWrkng = 12;
    }
    ChristmasSalary = (salary * mesesWrkng) / mesesWrkng;
    return ChristmasSalary;
};
//Calcula salario por hora
float salarioPorHora(float salary, float hourlyR8, int horas) {
    hourlyR8 = salary / (4 * horas);
    return hourlyR8;
};

//Calcula total a deducir por Impuesto Sobre la Renta
float calcISR(float salary, float totalISR, float salaryPostDesc) {
    int salaryAnual = salary * 12;
    double ISR = 0, ExedenteDISR = 0, rangoISR = 0;
    //IF usado para determinar porcentaje de isr, exedente y rango de isr
    if (salaryAnual > 416220.01 && salaryAnual < 624329.0) {
        ISR = 0.15;
        ExedenteDISR = 416220.01;

    }
    else if (salaryAnual > 624329.01 && salaryAnual < 867123.0) {
        ISR = 0.20;
        ExedenteDISR = 624329.01;
        rangoISR = 31216.00;

    }
    else if (salaryAnual > 867123.01) {
        ISR = 0.25;
        ExedenteDISR = 867123.01;
        rangoISR = 79776.00;
    }
    //if usado para calcular el total a deducir
    if (ISR != 0) {
        totalISR = (rangoISR + ((salaryAnual - ExedenteDISR) * ISR)) / 12;
        cout << "Total ISR a deducir: " << totalISR << endl;
    }
    else {
        cout << "Su salario está exento del ISR" << endl;
    }
    return totalISR;

}

//calcula total a deducir por TSS
float calcTSS(float totalTSS, float salary) {
    float sfs = 0.0304, afp = 0.0287;
    totalTSS = (sfs + afp) * salary;
    cout << "Total TSS a deducir: " << totalTSS << endl;
    return totalTSS;
}

//Deduce la tss del salario
float deducirTSS(float totalTSS, float salary) {
    salary = salary - totalTSS;
    return salary;
}

//Deduce el ISR del salario 
float deducirISR(float totalISR, float salary, float salaryPostDesc) {
    salaryPostDesc = salary - totalISR;
    return salaryPostDesc;
}

int main()
{
    float salary = 0, bonus = 0, hourlyR8 = 0, totalISR = 0, totalTSS = 0, ChristmasSalary = 0;
    float salaryPostDesc = 0;
    int horas = 0, extHours = 0, mesesWrkng = 0;
    //Ingreso de salario, horas extras, horas a la semana que trabaja y bonificaciones
    cout << "Introduzca su salario base (mensual) "; cin >> salary;
    cout << "Introduzca las horas que trabaja a la semana "; cin >> horas;
    cout << "Introduzca las horas extras "; cin >> extHours;
    cout << "Introduzca cualquier bonus ";cin >> bonus;
    cout << "Introduzca los meses que tiene en esta empresa "; cin >> mesesWrkng;
    //Calculando 
    ChristmasSalary = calcSalario13(ChristmasSalary, salary, mesesWrkng);

    //Calculo de pago por hora
    hourlyR8 = salarioPorHora(salary, hourlyR8, horas);

    //Calculo de horas extras y bonus
    salary = salary + (hourlyR8 + (hourlyR8 * 0.15) * extHours) + bonus;

    //Llamada a calcular retenciones por TSS e ISR
    totalTSS = calcTSS(totalTSS, salary);
    salary = deducirTSS(totalTSS, salary);
    totalISR = calcISR(salary, totalISR, salaryPostDesc);
    salaryPostDesc = deducirISR(totalISR, salary, salaryPostDesc);

    cout << "Tu salario Mensual despues de la TSS y la ISR es: " << salaryPostDesc;

    system("PAUSE");
    return 0;
}