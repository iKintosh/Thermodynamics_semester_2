#include <stdint.h>

#include <Wire.h>
#include <Adafruit_MLX90614.h>
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

#include <LiquidCrystal.h>
LiquidCrystal lcd(13,12,11,10,9,8);

// подключаем необходимые библиотеки и указываем пины, к которым подключены усилитель сигнала для тензорезистора, lCD экран и 
// переобозначаем длинное Adafruit_MLX90614() в mlx
float amb = 0; // внешняя температура
float obj = 0; // температура объекта
unsigned long t = 0;

void setup() 
{
  Serial.begin (9600); // обозначаем передачу данных на компьютер со скоростью 9600 бит/с
  lcd.begin(16, 2); // включаем экран, обозначаем что он имеет 2 строки по 16 символов
  mlx.begin(); // запускаем термометр
  
}

void loop() {

  amb = mlx.readAmbientTempC(); // считываем значение окружающей температуры
  obj = mlx.readObjectTempC(); // считываем значение температуры объекта
  t = millis();
  
  Serial.print(t);
  Serial.print(' ');
  Serial.print(amb);
  Serial.print(' ');
  Serial.println(obj);
  //Serial.print('\n');
  // передаем полученные значаения на компьютер

  lcd.setCursor(0,0); // выставляем курсор на экране
  lcd.print("amb.");
  lcd.print(amb);

  lcd.setCursor(0,1); // выставляем курсор на 2 строку
  lcd.print("obj.");
  lcd.print(obj);
  // печатаем данные на экране

}
