function calculateSalaries() {
    // Get values from HTML elements once
    const bonus = parseFloat(document.getElementById("Bonuses").value);
    var salary = parseFloat(document.getElementById("BaseSalary").value);
    const extHours = parseFloat(document.getElementById("extHours").value);
    const horas = parseFloat(document.getElementById("hours").value);
    const mesesWrkng = parseFloat(document.getElementById("months").value);
  
    // Calculate Christmas salary
    const ChristmasSalary = calcSalario13(salary, mesesWrkng);

    // Calculate hourly rate
    const hourlyR8 = salarioPorHora(salary, horas);
    
    //Calculate the salary after the extra hours and bonuses
    salary = salary + (extHours*(hourlyR8+(hourlyR8*0.15))) + bonus;

    // Calculate total TSS
    const totalTSS = calcTSS(salary);
  
    // Deduct TSS from salary
    const salaryAfterTSS = salary - totalTSS;
  
    // Calculate total ISR
    var totalISR = calcISR(salaryAfterTSS, totalISR);
  
    // Deduct ISR from salary
    const salaryPostDesc = salaryAfterTSS - totalISR;
  
    // Update HTML elements with calculated values
    document.getElementById("SalaryAftTax").value = salaryPostDesc.toFixed(2);
    document.getElementById("christmasSalary").value = ChristmasSalary.toFixed(2);
    document.getElementById("DeducidoISR").value = totalISR.toFixed(2);
    document.getElementById("DeducidoTSS").value = totalTSS.toFixed(2);
    document.getElementById("HourlyR8").value = hourlyR8.toFixed(2);
  
    return {
      totalISR,
      totalTSS,
      ChristmasSalary,
      hourlyR8,
      salaryPostDesc
    };
  }
  
  function calcSalario13(salary, mesesWrkng) {
    mesesWrkng = Math.min(mesesWrkng, 12);
    return salary * mesesWrkng / 12;
  }
  
  function salarioPorHora(salary, horas) {
    return salary / (4 * horas);
  }
  
  function calcTSS(salary) {
    const sfs = 0.0304;
    const afp = 0.0287;
    return (sfs + afp) * salary;
  }
//Calcula total a deducir por Impuesto Sobre la Renta
function calcISR(salaryAfterTSS, totalISR) {
    var ISR = 0, ExedenteDISR = 0, rangoISR = 0, salaryAnual=salaryAfterTSS*12;
    console.log(salaryAfterTSS);
    if (salaryAnual > 416220.01 && salaryAnual < 624329.0) {
        ISR = 0.15;
        ExedenteDISR = 416220.01;
    console.log(ISR, ExedenteDISR, rangoISR);
    }
    else if (salaryAnual > 624329.01 && salaryAnual < 867123.0) {
        ISR = 0.20;
        ExedenteDISR = 624329.01;
        rangoISR = 31216.00;
        console.log(ISR, ExedenteDISR, rangoISR);
    }
    else if (salaryAnual > 867123.01) {
        ISR = 0.25;
        ExedenteDISR = 867123.01;
        rangoISR = 79776.00;
        console.log(ISR, ExedenteDISR, rangoISR);

    }
    //if usado para calcular el total a deducir
    if (ISR != 0) {
        totalISR = (rangoISR + ((salaryAnual - ExedenteDISR) * ISR)) / 12;
        console.log(totalISR);
    } else{
        totalISR=0;
    }
    return totalISR;
  }
  