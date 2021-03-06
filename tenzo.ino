#include <hx711.h>
Hx711 scale(A2, A3);

#include <stdint.h>

#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);

// подключаем необходимые библиотеки и указываем пины, к которым подключены усилитель сигнала для тензорезистора, lCD экран и 
// переобозначаем длинное Adafruit_MLX90614() в mlx

float r = 0; // сопротивление переменного резистора
int f = 0; // сила приложенная к тензорезистору

void setup() 
{
  Serial.begin (9600); // обозначаем передачу данных на компьютер со скоростью 9600 бит/с
  lcd.begin(16, 2); // включаем экран, обозначаем что он имеет 2 строки по 16 символов
}

void loop() {
  f = scale.getGram(); // считываем значение усилия на тензорезистор
  r = analogRead(A1)*5.0/1024.0; // считываем значение сопротивления
  
  Serial.print(f);
  Serial.print(' ');
  Serial.print(r);
  Serial.print('\n');
  // передаем полученные значаения на компьютер

  lcd.setCursor(0,0); // выставляем курсор на экране
  lcd.print("R=");
  lcd.print(r);

  lcd.setCursor(0,1); // выставляем курсор на 2 строку
  lcd.print("F=");
  // печатаем данные на экране

// код ниже предназначен для того, чтобы обеспечить правильный вывод данных на экран
// Так как при выводе, например, значения 123, а затем 17 на экране высветится 173,
// чтобы избежать этого символы следующие за 17 заполняются пробелами
  if (f < 10)
  {
    lcd.print(f);
    lcd.print("   ");
  }
  if ((f < 100)&&(f > 10))
  {
    lcd.print(f);
    lcd.print("  ");
  }
  if ((f < 1000)&&(f > 100))
  {
    lcd.print(f);
    lcd.print(" ");
  }
  if (f > 1000)
  {
    lcd.print(f);
  }
}
