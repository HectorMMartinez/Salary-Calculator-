

#include <iostream>
using namespace std;
float salarioPorHora(float salary, float hourlyR8, int horas) {
	hourlyR8 = salary/horas;
	return hourlyR8;
};

int main()
{
		float salary = 0, bonus = 0, hourlyR8 = 0;
		int horas = 0, extHours = 0;
		cout << "Introduzca su salario base (mensual) "; cin >> salary;
		cout << "Introduzca las horas que trabaja a la semana "; cin >> horas;
		//cout << "Introduzca las horas extras "; cin >> extHours;
		cout << "Introduzca cualquier bonus ";cin >> bonus;
		hourlyR8=salarioPorHora(salary,hourlyR8, horas);
		cout << "Este es su pago por hora" << hourlyR8 << endl;
}
