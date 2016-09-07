### Bash & C task

```
bash
1. Два варианта: выбор из фиксированного набора (например, who и wc -l либо ls -l и head -n 2) или ввод пары команд вручную
2. Подтвердить выбор одного из вариантов
3. Вариант 1
3.1 В случае фиксированного набора предоставить варианты из набора
3.2 Выбрать по номеру строки (1 или 2)
4. Вариант 2
4.1 Считать пару команд с консоли

Каждая команда записывается в отдельный макрос в файле Definition

c
1. Проект собирается из makefile
2. В makefile включается файл Definition (оттуда беруться значения макросов)
3. c-файл
3.1 Создается дочерний процесс (с использованием fork())
3.2 В дочернем процессе выполняется первая команда из Definition (с использованием execl())
3.3 Через pipe выполняется перенаправление на родительский процесс
3.4 В родительском процессе принимаются данные от дочернего процесса через pipe
3.5 Данные подаются на вход второй команды
```

Steps:

- launch `./prompt.sh` to prepare command macroses;
- run `make` to build and run the program.

The following bash sessions show the process as well.

Default commands:

```
Ivans-MBP% ./prompt.sh
Select an option:
1) Choose default commands
2) Input commands manualy
*) Quit
1
Select a command pair:
1) who | wc -l
2) ls -l | head -n 4
*) Quit
1
Commands saved.
Ivans-MBP% make
cc program.c -o program -D CMD1='"who"' -D CMD2='"wc -l"'
./program
       2
```

Or user preferred ones:

```
Ivans-MBP% ./prompt.sh
Select an option:
1) Choose default commands
2) Input commands manualy
*) Quit
2
Enter command #1:
ls -l
Enter command #2:
grep Def
Commands saved.
Ivans-MBP% make
cc program.c -o program -D CMD1='"ls -l"' -D CMD2='"grep Def"'
./program
-rw-r--r--  1 ivan  staff    29 Sep  7 11:36 Definitions
-rw-r--r--  1 ivan  staff    30 Sep  7 10:47 Definitions.example
```
