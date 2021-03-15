# Лабораторная работа №3

## Отчёт по лабораторной работе №3

по дисциплине "Unix-подобные операционные системы"  
студента группы ПА-18-2  
Сафиюлина Александра Александровича

### Постановка задачи:

* Написать Bash-скрипт, который работает с некоторыми аргументами;
* Написать программу на языке С/C++, которая будет работать с некоторыми консольными аргументами. Скомпилировать с 
  помощью компилятора gcc/g++;
* Установить ещё 3 произвольные компилятора/интерпретатора, для проверки их работы создать аналогичные программы на 
  соответствующих языках.
  
### Выполнение

#### Bash-скрипт

По аналогии с ОС Windows, Linux имеет собственный формат скриптовых 
файлов. Вообще говоря, не принципиально каким расширением будет 
обладать скриптовый файл. Главное - это предоставить право на его 
запуск.

Напишем скрипт, который будет считать и выводить сумму двух целых чисел. 
Для этого сделаем следующие шаги:

1. Создадим файл с помощью команды `touch main.bash`;
2. Откроем с помощью команды `nano main.bash` созданный файл;
3. Вставим текст скрипта:
   ![][nano-bash]
4. Предоставим разрешение на запуск скрипта с помощью команды 
`chmod 755 main.bash`;
5. Протестируем работу `main.bash`:
    ![][bash]

[nano-bash]: img/nano-bash.png
[bash]: img/bash.png

#### Программа на C

Напишем похожую программу на С, откомпилировав оную с помощью gcc, 
предварительно установленного ранее.

1. Создадим файл с помощью команды `touch main.c`;
2. Откроем с помощью команды `nano main.c` созданный файл;
3. Вставим в него текст программы:
   ```C
   #include <ctype.h>
   #include <stdio.h>
   #include <stdlib.h>

   double Sum(const double first, const double second) {
        return first + second;
   }

   int main(int argc, const char** argv) {
       if (argc < 3) {
            fprintf(stdout, "Not enough args to complete this program\n");
            return EXIT_SUCCESS;
       }

        char* error;
        const double first  = strtod(argv[1], &error);
        const double second = strtod(argv[2], &error);
    
        if (*error != 0 && !isspace((unsigned char)*error)) {
            fprintf(stdout, "Parse error...\n");
            return EXIT_FAILURE;
        }
    
        fprintf(stdout, "%f + %f = %f\n", first, second, Sum(first, second));
        return EXIT_SUCCESS;
   }
    ```
4. Скомпилируем программу с помощью команды `gcc main.c`;
5. Запустим созданный исполнительный файл под названием `a.out`, 
протестируем работу программы.
   ![][c-program]
   
[c-program]: img/c-program.png

#### Программа на С++

Напишем аналогичную программу на языке С++. Компилировать будем с 
помощью g++, который идёт в комплекте вместе с gcc в GNU-компиляторе. 
Алогоритм уже знаком:

1. Создадим файл с помощью команды `touch main.cpp`;
2. Откроем с помощью команды `nano main.cpp` созданный файл;
3. Вставим в него текст программы:
    ```Cpp
    #include <iostream>
    
    using std::cout;
    using std::endl;
    
    double Sum(const double first, const double second) {
        return first + second;
    }
    
    int main(int argc, const char** argv) {
        if (argc < 3) {
            cout << "Not enough args to complete this program" << endl;
            return EXIT_SUCCESS;
        }
    
        char* error;
        const auto first  = strtod(argv[1], &error);
        const auto second = strtod(argv[2], &error);
    
    
        if (*error != 0 && !isspace((unsigned char)*error)) {
            cout <<  "Parse error..." << endl;
            return EXIT_FAILURE;
        }
    
        cout << first << " + " << second << " = " << Sum(first, second) << endl;
        return EXIT_SUCCESS;
    }   
   ```
4. Скомпилируем программу с помощью команды `g++ main.cpp`;
5. Запустим созданный исполнительный файл под названием `a.out`,
   протестируем работу программы.
   ![][cpp-program]
   
[cpp-program]: img/cpp-program.png

#### Программа на C#

Перепишем эту программу на языке С#. Компилировать будем с
помощью mcs, который идёт в комплекте с Mono, который в свою 
очередь идёт вместе с дистрибутивом Zorin OS. Собственно говоря, 
Linux не поддерживает файлы с расширением .exe, однако mono 
позволяет их запускать. Более того, Zorin OS даёт возможность 
не задумываясь о Mono запускать исполняемые файлы Windows как 
родные, а для C#, который компилирует именно в .exe это большое 
преимущество.

1. Создадим файл с помощью команды `touch main.cs`;
2. Откроем с помощью команды `nano main.cs` созданный файл;
3. Вставим в него текст программы:
    ```Cs
    using System;
    using System.Globalization;
    
    namespace Main {
        internal static class Operations {
            internal static double Sum(double first, double second) {
                return first + second;
            }
    }
    
        internal class Program {
            internal static int Main(string[] args) {
                if (args.Length < 2) {
                    Console.WriteLine("Not enough args to complete the program");
                    return 0;
                }
    
                try {
                    var first  = Convert.ToDouble(args[0], CultureInfo.InvariantCulture);
                    var second = Convert.ToDouble(args[1], CultureInfo.InvariantCulture);
    
                    Console.WriteLine($"{first} + {second} = {Operations.Sum(first, second)}");
                }
                catch (Exception) {
                    Console.WriteLine("Parse error...");
                }
    
                return 0;
            }
        }
    }
    ```
4. Скомпилируем при помощи команды `msc main.cs`;
5. Запустим приложение `main.exe` и протестируем его работу:
    ![][cs-program]

[cs-program]: img/cs-program.png

#### Программа на Java

Портируем это приложение на Java. Так как Java-приложения 
запускаются при помощи виртуальной машины, то помимо компилятора 
javac, который создаст файл классов, потребуется ещё java, которая 
это файл классов может превратить в рабочую программу.

1. Создадим файл с помощью команды `touch main.java`;
2. Откроем с помощью команды `nano main.java` созданный файл;
3. Вставим в него текст программы:
   ```Java
   public class main {
        public static double Sum(double first, double second) {
            return first + second;
        }
        
        public static void main(String[] args) {
            if (args.length < 2) {
                System.out.println("Not enough args to complete the program!");
                return;
            }
    
            try {
                Double first  = Double.parseDouble(args[0]);
                Double second = Double.parseDouble(args[1]);
    
                System.out.format("%s + %s = %s\n", first, second, main.Sum(first, second));
            }
            catch (Exception exception) {
                System.out.println("Parse error...");
            }
        }
    }
    ```
4. Скомпилируем при помощи `javac main.java`;
5. Запустим `java main`. Протестируем 
программу:
   ![][java-program]

[java-program]: img/java-program.png

#### Программа на Go

Теперь перепишем эту же самую консольную программу на язык 
программирования Go. Для используется одноимённый компилятор, 
который без труда можно найти в открытом доступе в качестве 
apt-пакета.

1. Создадим файл с помощью команды `touch main.go`;
2. Откроем с помощью команды `nano main.go` созданный файл;
3. Вставим в него текст программы:
   ```Go
   package main
    
    import (
        "fmt"
        "os"
        "strconv"
    )
    
    func Sum(first, second float64) float64 {
        return first + second
    }
    
    func main() {
        if (len(os.Args) < 3) {
            fmt.Println("Not enough args to complete the program!")
            return
        }
    
        first, error1  := strconv.ParseFloat(os.Args[1], 64)
        second, error2 := strconv.ParseFloat(os.Args[2], 64)
    
        if (error1 != nil || error2 != nil) {
            fmt.Println("Parse error...")
            os.Exit(1)
        }
    
        fmt.Printf("%v + %v = %v\n", first, second, Sum(first, second))
    }
   ```
4. Скомпилируем при помощи команды `go build main.go`;
5. Запустим исполняемый файл `main` и протестируем программу:
    ![][go-program]

[go-program]: img/go-program.png

#### Программа на D

Наконец напишем данное консольное приложение на языке 
программирования D. Для компиляции обычно используется 
эталонный компилятор dmd. Приступим же.

1. Создадим файл с помощью команды `touch main.d`;
2. Откроем с помощью команды `nano main.d` созданный файл;
3. Вставим в него текст программы:
   ```D
   import std.stdio, std.conv;
    
    double Sum(immutable double first, immutable double second) {
        return first + second;
    }
    
    int main(string[] args) {
        if (args.length < 3) {
            stdout.writeln("Not enough args to complete the program!");
            return 0;
        }
    
        try {
            immutable first  = parse!double(args[1]);
            immutable second = parse!double(args[2]);
    
            stdout.writefln!"%s + %s = %s"(first, second, Sum(first, second));
        }
        catch(Exception) {
            stdout.writeln("Parse error...");
        }
    
        return 0;
    }
   ```
4. Скомпилируем код командой `dmd main.d`;
5. Запустим созданный исполняемый файл и проведём несколько 
простых тестов:
   ![][d-program]

[d-program]: img/d-program.png
