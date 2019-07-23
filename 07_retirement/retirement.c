#include <stdio.h>
#include <stdlib.h>


struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;


void print_info(int months, double balance){
  printf("Age %3d month %2d you have $%.2f\n", months/12, months % 12, balance);

}

  double balance_calc(double balance, retire_info status){
    balance += balance * status.rate_of_return;
    balance += status.contribution;

    return balance;
  }

void retirement(int startAge, //in months
		double initial, //inital savings in dollars
		retire_info working, //info about working
		retire_info retired){ //info about being retired 

  double balance = initial;
  int total_months = startAge;
  
  for (int i = 0; i < working.months; i++){
    print_info(total_months, balance);
    balance = balance_calc(balance, working);
    total_months++ ;
  }

  for (int j = 0; j < retired.months; j++){
    print_info(total_months, balance);
    balance = balance_calc(balance, retired);
    total_months++ ;
  }

}

int main(){
  retire_info working;
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045 / 12.0;

  retire_info retired;
  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01/12.0;

  retirement(327, 21345, working, retired);

}
