Отчёт по лабораторной работе №2 по курсу 
«Фундаментальная информатика»

Студент группы: М8О-108Б-22, Немкова Анастасия Романовна, 

№ по списку 14

Контакты: nastya.nemkova.04@mail.ru

Работа выполнена: 18.09.2022

Преподаватель: Сахаров Никита Александрович

1. Тема

Операционная среда OC UNIX

2. Цель работы

Изучение и освоение программного обеспечения ОС UNIX и приобретение навыков, необходимых для выполнения курсовых и лабораторных работ в среде UNIX.

3. Задание

Приобретение основных навыков работы в OC UNIX. Навигация в файловой системе UNIX. Создание, удаление и переименование директорий. Освоение основных команд.

4. Оборудование

Процессор: AMD RYZEN 7 5800H 3.20GHz ОП 16 ГБ
HDD: 952 ГБ
Монитор: 3840 × 2400

5. Программное обеспечение

Операционная система семейства: Linux Ubuntu, версия 22.04.1 LTS
Интерпретатор команд: bash, версия 5.0.17(1)
Система программирования: -
Редактор текстов: emacs
Утилиты операционной системы: команды who, pwd, ls, cd, cp, mv, rm, cat, ps, mkdir, rmdir, ruptime, rwho
Прикладные системы и программы: gnuplot, dc
Местонахождение и имена файлов программ и данных на домашнем компьютере: - 

6. Идея, метод, алгоритм решения задачи


1.Вывод информации о пользователе, системе, машине с помощью команд: who, rwho, uptime, ruptime, whoami, man, date

2.Работа с каталогами с помощью команд: ls, cd, mkdir, rmdir, pwd

3.Работа с текстовыми файлами с помощью команд: cat, mv, rm, cp

4.Работа с текстовым редактором Emacs с помощью команд: cat Emacs

5.Работа с утилитой Gnuptop с помощью команд: plot, splot, set parametric, [x]range



7. Сценарий выполнения работы
Команды для справочной информации

man - показывает инструкцию к программам и командам Linux

whoami -  показывает идентификатор пользователя

who - показывает перечень пользователей

rwho - показывает перечень пользователей в локальной сети

date - показывает текущую дату

tty	- показывает адрес терминала

uname -a	- показывает информацию об операционной системе

ruptime	- показывает строку состояния пользователей в сети

hostname	- определяет название компьютера и используется преимущественно для идентификации компьютера в сети

finger	- сообщает информацию о пользователях, вошедших в систему в настоящее время операционной системе


Команды для управления файлами и каталогами

ls - просмотр содержимого каталога

pwd	- показывает текущую директорию

cd - перемещение по каталогу

сat - показывает содержимое файла

cat > f1 - помещение текста с клавиатуры в файл f1

cat f1 f2 > f3 - объединение файлов f1, f2 в f3

rm	- удаление файла

mkdir	- создание новых каталогов

rmdir	- удаление каталога

cp	- копирование файлов и каталогов

mv	- переименование файлов и каталогов

Команды для работы с Gnuplot

plot	- строит двумерный график функции

splot	- строит график функции в трёхмерном пространстве

set parametric	- возможность использовать параметры

set yrange	- устанавливает диапазон значений переменной y




8. Распечатка протокола

anastasia@anastasia-VirtualBox:~$ ls

 f.txt   test.sh   Видео   Документы   Загрузки   Изображения   Музыка   Общедоступные  'Рабочий стол'   Шаблоны
 
anastasia@anastasia-VirtualBox:~$ ls -laF

итого 104

drwxr-xr-x 16 anastasia anastasia 4096 сен 19 22:11  ./

drwxr-xr-x  3 root      root      4096 сен  8 18:54  ../

-rw-------  1 anastasia anastasia   38 сен  8 19:10  .bash_history

-rw-r--r--  1 anastasia anastasia  220 сен  8 18:54  .bash_logout

-rw-r--r--  1 anastasia anastasia 3771 сен  8 18:54  .bashrc

drwx------ 14 anastasia anastasia 4096 сен 19 22:16  .cache/

drwx------ 12 anastasia anastasia 4096 сен 19 22:16  .config/

drwx------  2 anastasia anastasia 4096 сен 19 18:04  .emacs.d/

-rw-rw-r--  1 anastasia anastasia    6 сен 19 18:05  f.txt

drwx------  3 anastasia anastasia 4096 сен  8 19:04  .gnupg/

-rw-------  1 anastasia anastasia  320 сен 19 22:05  .gnuplot_history

drwxr-xr-x  3 anastasia anastasia 4096 сен  8 19:01  .local/

-rw-r--r--  1 anastasia anastasia  807 сен  8 18:54  .profile

drwx------  2 anastasia anastasia 4096 сен  8 19:04  .ssh/

-rw-r--r--  1 anastasia anastasia    0 сен  8 19:07  .sudo_as_admin_successful

-rw-rw-r--  1 anastasia anastasia    0 сен 10 13:25  test.sh

-rw-r-----  1 anastasia anastasia    5 сен 10 12:34  .vboxclient-clipboard.pid

-rw-r-----  1 anastasia anastasia    5 сен 10 12:34  .vboxclient-display-svga-x11.pid

-rw-r-----  1 anastasia anastasia    5 сен 10 12:34  .vboxclient-draganddrop.pid

-rw-r-----  1 anastasia anastasia    5 сен 10 12:34  .vboxclient-seamless.pid

drwxr-xr-x  2 anastasia anastasia 4096 сен  8 19:01  Видео/

drwxr-xr-x  3 anastasia anastasia 4096 сен 19 22:17  Документы/

drwxr-xr-x  2 anastasia anastasia 4096 сен  8 19:01  Загрузки/

drwxr-xr-x  2 anastasia anastasia 4096 сен  8 19:01  Изображения/

drwxr-xr-x  2 anastasia anastasia 4096 сен  8 19:01  Музыка/

drwxr-xr-x  2 anastasia anastasia 4096 сен  8 19:01  Общедоступные/

drwxr-xr-x  2 anastasia anastasia 4096 сен  8 19:01 'Рабочий стол'/

drwxr-xr-x  2 anastasia anastasia 4096 сен  8 19:01  Шаблоны/

anastasia@anastasia-VirtualBox:~$ ls -a

.               .bashrc    f.txt              .profile                    .vboxclient-clipboard.pid          Видео         Музыка

..              .cache     .gnupg             .ssh                        .vboxclient-display-svga-x11.pid   Документы     Общедоступные

.bash_history   .config    .gnuplot_history   .sudo_as_admin_successful   .vboxclient-draganddrop.pid        Загрузки     'Рабочий стол'

.bash_logout    .emacs.d   .local             test.sh                     .vboxclient-seamless.pid           Изображения   Шаблоны

anastasia@anastasia-VirtualBox:~$ ls -F
 
 f.txt   test.sh   Видео/   Документы/   Загрузки/   Изображения/   Музыка/   Общедоступные/  'Рабочий стол'/   Шаблоны/

anastasia@anastasia-VirtualBox:~$ ruptime

anastasia-Vi  up       7:07,     1 user,   load 0.08, 0.08, 0.04

anastasia@anastasia-VirtualBox:~$ rwho

anastasi anastasia-VirtualBox::1 Sep 10 12:34

anastasia@anastasia-VirtualBox:~$ whoami

Anastasia

anastasia@anastasia-VirtualBox:~$ date

Вт 20 сен 2022 00:08:04 MSK

anastasia@anastasia-VirtualBox:~$ tty

/dev/pts/0

anastasia@anastasia-VirtualBox:~$ hostname

anastasia-VirtualBox

anastasia@anastasia-VirtualBox:~$ uname -a

Linux anastasia-VirtualBox 5.15.0-46-generic #49~20.04.1-Ubuntu SMP Thu Aug 4 19:15:44 UTC 2022 x86_64 x86_64 x86_64 GNU/Linux

anastasia@anastasia-VirtualBox:~$ finger

Login      Name        Tty      Idle  Login Time   Office     Office Phone

anastasia  Anastasia  *:1             Sep 10 12:34 (:1)

anastasia@anastasia-VirtualBox:~$ finger anastasia

Login: anastasia      			Name: Anastasia

Directory: /home/anastasia          	Shell: /bin/bash

On since Sat Sep 10 12:34 (MSK) on :1 from :1 (messages off)

No mail.

No Plan.

anastasia@anastasia-VirtualBox:~$ pwd

/home/anastasia

anastasia@anastasia-VirtualBox:~$ who

anastasia :1           2022-09-10 12:34 (:1)

nastasia@anastasia-VirtualBox:~$ cd /

anastasia@anastasia-VirtualBox:/$ cd /bin

anastasia@anastasia-VirtualBox:/bin$ cd ..

anastasia@anastasia-VirtualBox:/$ ls

bin  boot  cdrom  dev  etc  home  lib  lib32  lib64  libx32  lost+found  media  mnt  opt  proc  root  run  sbin  snap  srv  swapfile  sys  tmp  usr  var

anastasia@anastasia-VirtualBox:~$ cat > f1.txt

1234

anastasia@anastasia-VirtualBox:~$ cat f1.txt

1234

anastasia@anastasia-VirtualBox:~$ emacs f1.txt

anastasia@anastasia-VirtualBox:~$ cat f1.txt

123gy

anastasia@anastasia-VirtualBox:~$ cat > f2.txt


anastasia@anastasia-VirtualBox:~$ cat f1.txt > f2.txt

anastasia@anastasia-VirtualBox:~$ cat f2.txt

123gy

anastasia@anastasia-VirtualBox:~$ cat > f3.txt

anastasia@anastasia-VirtualBox:~$ cat f1.txt f2.txt > f3.txt

anastasia@anastasia-VirtualBox:~$ cat f3.txt

123gy

123gy

anastasia@anastasia-VirtualBox:~$ rm f2.txt

anastasia@anastasia-VirtualBox:~$ rm f3.txt

anastasia@anastasia-VirtualBox:~$ ls
 
 f.txt  f1.txt test.sh   Видео   Документы   Загрузки   Изображения   Музыка   Общедоступные  'Рабочий стол'   Шаблоны

anastasia@anastasia-VirtualBox:~$ mkdir lab

anastasia@anastasia-VirtualBox:~$ mkdir course 

anastasia@anastasia-VirtualBox:~$ ls
 
 course   f1.txt   f.txt   lab   test.sh   Видео   Документы   Загрузки   Изображения   Музыка   Общедоступные  'Рабочий стол'   Шаблоны

anastasia@anastasia-VirtualBox:~$ cp f1.txt lab

anastasia@anastasia-VirtualBox:~$ ls lab

f1.txt

anastasia@anastasia-VirtualBox:~$ cp f1.txt course

anastasia@anastasia-VirtualBox:~$ ls course

f1.txt

anastasia@anastasia-VirtualBox:~$ rm f1.txt

anastasia@anastasia-VirtualBox:~$ ls
 
 course   f.txt   lab   test.sh   Видео   Документы   Загрузки   Изображения   Музыка   Общедоступные  'Рабочий стол'   Шаблоны

anastasia@anastasia-VirtualBox:~$ cd lab

anastasia@anastasia-VirtualBox:~/lab$ ls

f1.txt

anastasia@anastasia-VirtualBox:~/lab$ rm f1.txt

anastasia@anastasia-VirtualBox:~/lab$ ls

anastasia@anastasia-VirtualBox:~/lab$ cd ..

anastasia@anastasia-VirtualBox:~$ rm lab

rm: невозможно удалить 'lab': Это каталог

anastasia@anastasia-VirtualBox:~$ rm -R lab

anastasia@anastasia-VirtualBox:~$ rm -R course

anastasia@anastasia-VirtualBox:~$ ls
 
 f.txt   test.sh   Видео   Документы   Загрузки   Изображения   Музыка   Общедоступные  'Рабочий стол'   Шаблоны

anastasia@anastasia-VirtualBox:~$ gnuplot

	
  G N U P L O T
	Version 5.2 patchlevel 8    last modified 2019-12-01 

	Copyright (C) 1986-1993, 1998, 2004, 2007-2019
  
  Thomas Williams, Colin Kelley and many others

	
  gnuplot home:     http://www.gnuplot.info
	
  faq, bugs, etc:   type "help FAQ"
	
  immediate help:   type "help"  (plot window: hit 'h')


Terminal type is now 'qt'

gnuplot> plot sin(x)*cos(x)

gnuplot> splot sin(x*x+y*y)


gnuplot> set parametric
	
  dummy variable is t for curves, u/v for surfaces

gnuplot> set trange [0 to 2*pi]

gnuplot> set xrange [-1 to 1]

gnuplot> set yrange [-1 to 1]

gnuplot> plot sin(t),cos(t)


gnuplot> set zrange [-1 to 1]

gnuplot> gnuplot> set urange [0 to 2*pi]
         
         ^
         
         invalid command

gnuplot> set zrange [-1 to 1]

gnuplot> set urange [0 to 2*pi]

gnuplot> set vrange [0 to 2*pi]

gnuplot> set nohidden3d

         ^
         warning: deprecated syntax, use "unset"

gnuplot> splot sin(u)*sin(v),sin(u)*cos(v),cos(u)

gnuplot> exit





9. Дневник отладки

№	Лаб.Или Дом.	  Дата     Время	         Событие	               Действие по исправлению	          Примечание

1     Дом.	    24.09.22	 13:00	   Освоение команд OC UNIX	              -                  Команды работали исправно   

10. Замечания автора по существу работы

Были проделаны команды для приобретения навыков работы в OC UNIX

anastasia@anastasia-VirtualBox:~$ cat > f1.txt
 1234 
 
anastasia@anastasia-VirtualBox:~$ ps

    PID TTY          TIME CMD
    
  14693 pts/0    00:00:00 bash
  
  14926 pts/0    00:00:00 ps
  
anastasia@anastasia-VirtualBox:~$ ls

 f1.txt   f.txt     Видео       Загрузки      Музыка         'Рабочий стол'
 
 f2.txt   test.sh   Документы   Изображения   Общедоступные   Шаблоны
 
anastasia@anastasia-VirtualBox:~$ ls -lAF

итого 108

-rw-------  1 anastasia anastasia 4906 сен 24 14:05  .bash_history

-rw-r--r--  1 anastasia anastasia  220 сен  8 18:54  .bash_logout

-rw-r--r--  1 anastasia anastasia 3771 сен  8 18:54  .bashrc

drwx------ 15 anastasia anastasia 4096 сен 24 09:31  .cache/

drwx------ 13 anastasia anastasia 4096 сен 24 13:08  .config/

drwx------  2 anastasia anastasia 4096 сен 19 18:04  .emacs.d/

-rw-rw-r--  1 anastasia anastasia    6 сен 24 17:44  f1.txt

-rw-rw-r--  1 anastasia anastasia    0 сен 24 13:18  f2.txt

-rw-rw-r--  1 anastasia anastasia    6 сен 19 18:05  f.txt

drwx------  3 anastasia anastasia 4096 сен  8 19:04  .gnupg/

-rw-------  1 anastasia anastasia  847 сен 20 00:07  .gnuplot_history

drwxr-xr-x  3 anastasia anastasia 4096 сен  8 19:01  .local/

drwx------  4 anastasia anastasia 4096 сен 24 09:27  .mozilla/

-rw-r--r--  1 anastasia anastasia  807 сен  8 18:54  .profile

drwx------  2 anastasia anastasia 4096 сен  8 19:04  .ssh/

-rw-r--r--  1 anastasia anastasia    0 сен  8 19:07  .sudo_as_admin_successful

-rw-rw-r--  1 anastasia anastasia    0 сен 10 13:25  test.sh

-rw-r-----  1 anastasia anastasia    5 сен 10 12:34  .vboxclient-clipboard.pid

-rw-r-----  1 anastasia anastasia    5 сен 10 12:34  .vboxclient-display-svga-x11.pid

-rw-r-----  1 anastasia anastasia    5 сен 10 12:34  .vboxclient-draganddrop.pid

-rw-r-----  1 anastasia anastasia    5 сен 10 12:34  .vboxclient-seamless.pid

drwxr-xr-x  2 anastasia anastasia 4096 сен  8 19:01  Видео/

drwxr-xr-x  2 anastasia anastasia 4096 сен 19 22:18  Документы/

drwxr-xr-x  3 anastasia anastasia 4096 сен 24 09:31  Загрузки/

drwxr-xr-x  2 anastasia anastasia 4096 сен  8 19:01  Изображения/

drwxr-xr-x  2 anastasia anastasia 4096 сен  8 19:01  Музыка/

drwxr-xr-x  2 anastasia anastasia 4096 сен  8 19:01  Общедоступные/

drwxr-xr-x  2 anastasia anastasia 4096 сен  8 19:01 'Рабочий стол'/

drwxr-xr-x  2 anastasia anastasia 4096 сен  8 19:01  Шаблоны/

anastasia@anastasia-VirtualBox:~$ ls -a

 .               .gnupg                             .vboxclient-seamless.pid
 
 ..              .gnuplot_history                   Видео
 
 .bash_history   .local                             Документы
 
 .bash_logout    .mozilla                           Загрузки
 
 .bashrc         .profile                           Изображения
 
 .cache          .ssh                               Музыка
 
 .config         .sudo_as_admin_successful          Общедоступные
 
 .emacs.d        test.sh                           'Рабочий стол'
 
 f1.txt          .vboxclient-clipboard.pid          Шаблоны
 
 f2.txt          .vboxclient-display-svga-x11.pid
 
 f.txt           .vboxclient-draganddrop.pid
 
anastasia@anastasia-VirtualBox:~$ chmod g=rw f1.txt

anastasia@anastasia-VirtualBox:~$ chmod g-x f1.txt

anastasia@anastasia-VirtualBox:~$ ps

    PID TTY          TIME CMD
    
  14693 pts/0    00:00:00 bash
  
  14725 pts/0    00:00:00 ps
  
anastasia@anastasia-VirtualBox:~$ ps -a

    PID TTY          TIME CMD
    
   2790 tty3     00:00:01 Xorg
   
   2862 tty3     00:00:00 dbus-run-sessio
   
   2864 tty3     00:00:00 dbus-daemon
   
   2867 tty3     00:00:00 gnome-session-b
   
   2882 tty3     00:00:00 at-spi-bus-laun
   
   2889 tty3     00:00:00 dbus-daemon
   
   2927 tty3     00:00:47 gnome-shell
   
   2973 tty3     00:00:00 ibus-daemon
   
   2976 tty3     00:00:00 ibus-memconf
   
   2979 tty3     00:00:00 ibus-x11
   
   2984 tty3     00:00:00 ibus-portal
   
   2995 tty3     00:00:00 at-spi2-registr
   
   3001 tty3     00:00:00 xdg-permission-
   
   3017 tty3     00:00:00 gjs
   
   3031 tty3     00:00:00 gsd-sharing
   
   3032 tty3     00:00:00 gsd-wacom
   
   3035 tty3     00:00:00 gsd-color
   
   3038 tty3     00:00:00 gsd-keyboard
   
   3040 tty3     00:00:00 gsd-print-notif
   
   3042 tty3     00:00:00 gsd-rfkill
   
   3044 tty3     00:00:00 gsd-smartcard
   
   3045 tty3     00:00:00 gsd-datetime
   
   3050 tty3     00:00:00 gsd-media-keys
   
   3053 tty3     00:00:00 gsd-screensaver
   
   3056 tty3     00:00:00 gsd-sound
   
   3064 tty3     00:00:00 gsd-a11y-settin
   
   3070 tty3     00:00:01 gsd-housekeepin
   
   3071 tty3     00:00:00 gsd-power
   
   3074 tty3     00:00:00 ibus-engine-sim
   
   3094 tty3     00:00:00 gsd-printer
   
   3227 tty2     00:07:35 Xorg
   
   3251 tty2     00:00:00 gnome-session-b
   
  12041 tty3     00:00:00 dconf-service
  
  14730 pts/0    00:00:00 ps
  
anastasia@anastasia-VirtualBox:~$ man ps

anastasia@anastasia-VirtualBox:~$ ps -A
    
    PID TTY          TIME CMD
      
      1 ?        00:00:07 systemd
      
      2 ?        00:00:00 kthreadd
      
      3 ?        00:00:00 rcu_gp
      
      4 ?        00:00:00 rcu_par_gp
      
      5 ?        00:00:00 netns
      
      7 ?        00:00:00 kworker/0:0H-events_highpri
     
     10 ?        00:00:00 mm_percpu_wq
     
     11 ?        00:00:00 rcu_tasks_rude_
     
     12 ?        00:00:00 rcu_tasks_trace
     
     13 ?        00:00:00 ksoftirqd/0
     
     14 ?        00:00:09 rcu_sched
     
     15 ?        00:00:00 migration/0
     
     16 ?        00:00:00 idle_inject/0
     
     17 ?        00:00:00 cpuhp/0
     
     18 ?        00:00:00 cpuhp/1
     
     19 ?        00:00:00 idle_inject/1
     
     20 ?        00:00:00 migration/1
     
     21 ?        00:00:00 ksoftirqd/1
     
     23 ?        00:00:00 kworker/1:0H-events_highpri
     
     24 ?        00:00:00 cpuhp/2
     
     25 ?        00:00:00 idle_inject/2
     
     26 ?        00:00:00 migration/2
     
     27 ?        00:00:00 ksoftirqd/2
     
     29 ?        00:00:00 kworker/2:0H-kblockd
     
     30 ?        00:00:00 kdevtmpfs
     
     31 ?        00:00:00 inet_frag_wq
     
     32 ?        00:00:00 kauditd
     
     33 ?        00:00:00 khungtaskd
     
     34 ?        00:00:00 oom_reaper
     
     35 ?        00:00:00 writeback
     
     36 ?        00:00:03 kcompactd0
     
     37 ?        00:00:00 ksmd
     
     38 ?        00:00:00 khugepaged
     
     84 ?        00:00:00 kintegrityd
     
     85 ?        00:00:00 kblockd
     
     86 ?        00:00:00 blkcg_punt_bio
     
     88 ?        00:00:00 tpm_dev_wq
     
     89 ?        00:00:00 ata_sff
     
     90 ?        00:00:00 md
     
     91 ?        00:00:00 edac-poller
     
     92 ?        00:00:00 devfreq_wq
     
     93 ?        00:00:00 watchdogd
     
     96 ?        00:00:00 kworker/0:1H-kblockd
     
     98 ?        00:00:00 kswapd0
    
    99 ?        00:00:00 ecryptfs-kthrea
    
    101 ?        00:00:00 kthrotld
    
    102 ?        00:00:00 acpi_thermal_pm
    
    104 ?        00:00:00 scsi_eh_0
    
    105 ?        00:00:00 scsi_tmf_0
    
    106 ?        00:00:00 scsi_eh_1
    
    107 ?        00:00:00 scsi_tmf_1
    
    109 ?        00:00:00 vfio-irqfd-clea
    
    110 ?        00:00:00 mld
    
    111 ?        00:00:00 ipv6_addrconf
    
    123 ?        00:00:00 kstrp
    
    126 ?        00:00:00 zswap-shrink
    
    127 ?        00:00:00 kworker/u7:0
    
    132 ?        00:00:00 charger_manager
    
    178 ?        00:00:00 kworker/1:1H-kblockd
    
    182 ?        00:00:00 scsi_eh_2
    
    183 ?        00:00:00 scsi_tmf_2
    
    205 ?        00:00:01 jbd2/sda5-8
    
    206 ?        00:00:00 ext4-rsv-conver
    
    220 ?        00:00:00 kworker/2:1H-kblockd
    
    247 ?        00:00:02 systemd-journal
    
    270 ?        00:00:00 ipmi-msghandler
    
    271 ?        00:00:00 systemd-udevd
    
    279 ?        00:00:00 ttm_swap
    
    280 ?        00:00:02 irq/18-vmwgfx
    
    281 ?        00:00:00 card0-crtc0
    
    282 ?        00:00:00 card0-crtc1
    
    283 ?        00:00:00 card0-crtc2
    
    284 ?        00:00:00 card0-crtc3
    
    285 ?        00:00:00 card0-crtc4
    
    286 ?        00:00:00 card0-crtc5
    
    287 ?        00:00:00 card0-crtc6
    
    288 ?        00:00:00 card0-crtc7
    
    322 ?        00:00:00 iprt-VBoxWQueue
    
    341 ?        00:00:00 cryptd
    
    555 ?        00:00:00 systemd-timesyn
    
    586 ?        00:00:01 accounts-daemon
    
    587 ?        00:00:01 acpid
    
    589 ?        00:00:00 avahi-daemon
    
    590 ?        00:00:00 cron
    
    591 ?        00:00:00 cupsd
    
    593 ?        00:00:13 dbus-daemon
    
    597 ?        00:00:12 NetworkManager
    
    610 ?        00:00:02 irqbalance
    
    611 ?        00:00:00 networkd-dispat
    
    614 ?        00:00:08 polkitd
    
    620 ?        00:00:00 rsyslogd
    
    625 ?        00:00:00 switcheroo-cont
    
    631 ?        00:00:00 udisksd
    
    637 ?        00:00:00 wpa_supplicant
    
    651 ?        00:00:00 avahi-daemon
    
    662 ?        00:00:00 cups-browsed
    
    682 ?        00:00:00 ModemManager
    
    714 ?        00:00:00 unattended-upgr
    
    736 ?        00:00:00 whoopsie
    
    738 ?        00:00:00 kerneloops
    
    747 ?        00:00:00 kerneloops
    
    907 ?        00:00:00 gdm3
    
    914 ?        00:00:10 VBoxService
    
    953 ?        00:00:01 rtkit-daemon
   
   1073 ?        00:00:01 upowerd
   
   1327 ?        00:00:00 colord
   
   2734 ?        00:00:00 systemd-logind
   
   2735 ?        00:00:00 systemd-resolve
   
   2737 ?        00:00:00 gdm-session-wor
   
   2755 ?        00:00:00 systemd
   
   2758 ?        00:00:00 (sd-pam)
   
   2780 ?        00:00:00 pulseaudio
   
   2782 ?        00:00:00 tracker-miner-f
   
   2785 ?        00:00:00 dbus-daemon
   
   2786 tty3     00:00:00 gdm-x-session
   
   2790 tty3     00:00:01 Xorg
   
   2791 ?        00:00:00 gvfsd
   
   2796 ?        00:00:00 gvfsd-fuse
   
   2821 ?        00:00:00 gvfs-udisks2-vo
   
   2833 ?        00:00:02 gvfs-afc-volume
   
   2838 ?        00:00:00 gvfs-mtp-volume
   
   2842 ?        00:00:00 gvfs-goa-volume
   
   2846 ?        00:00:00 goa-daemon
   
   2855 ?        00:00:00 goa-identity-se
   
   2860 ?        00:00:00 gvfs-gphoto2-vo
   
   2862 tty3     00:00:00 dbus-run-sessio
   
   2864 tty3     00:00:00 dbus-daemon
   
   2867 tty3     00:00:00 gnome-session-b
   
   2882 tty3     00:00:00 at-spi-bus-laun
   
   2889 tty3     00:00:00 dbus-daemon
   
   2927 tty3     00:00:47 gnome-shell
   
   2973 tty3     00:00:00 ibus-daemon
   
   2976 tty3     00:00:00 ibus-memconf
   
   2979 tty3     00:00:00 ibus-x11
   
   2984 tty3     00:00:00 ibus-portal
   
   2989 ?        00:00:00 gvfsd-metadata
   
   2995 tty3     00:00:00 at-spi2-registr
   
   3001 tty3     00:00:00 xdg-permission-
   
   3017 tty3     00:00:00 gjs
   
   3031 tty3     00:00:00 gsd-sharing
   
   3032 tty3     00:00:00 gsd-wacom
   
   3035 tty3     00:00:00 gsd-color
   
   3038 tty3     00:00:00 gsd-keyboard
   
   3040 tty3     00:00:00 gsd-print-notif
   
   3042 tty3     00:00:00 gsd-rfkill
   
   3044 tty3     00:00:00 gsd-smartcard
   
   3045 tty3     00:00:00 gsd-datetime
   
   3050 tty3     00:00:00 gsd-media-keys
   
   3053 tty3     00:00:00 gsd-screensaver
   
   3056 tty3     00:00:00 gsd-sound
   
   3064 tty3     00:00:00 gsd-a11y-settin
   
   3070 tty3     00:00:01 gsd-housekeepin
   
   3071 tty3     00:00:00 gsd-power
   
   3074 tty3     00:00:00 ibus-engine-sim
   
   3094 tty3     00:00:00 gsd-printer
   
   3140 ?        00:00:00 gdm-session-wor
   
   3147 ?        00:00:02 systemd
   
   3148 ?        00:00:00 (sd-pam)
   
   3153 ?        00:00:01 pulseaudio
   
   3155 ?        00:00:01 tracker-miner-f
   
   3157 ?        00:00:04 dbus-daemon
   
   3161 ?        00:00:00 gvfsd
   
   3167 ?        00:00:00 gnome-keyring-d
   
   3170 ?        00:00:00 gvfsd-fuse
   
   3190 ?        00:00:00 gvfs-udisks2-vo
   
   3198 ?        00:00:03 gvfs-afc-volume
   
   3204 ?        00:00:00 gvfs-mtp-volume
   
   3208 ?        00:00:00 gvfs-goa-volume
   
   3212 ?        00:00:00 goa-daemon
   
   3220 ?        00:00:00 goa-identity-se
   
   3223 tty2     00:00:00 gdm-x-session
   
   3227 tty2     00:07:36 Xorg
   
   3229 ?        00:00:00 gvfs-gphoto2-vo
   
   3251 tty2     00:00:00 gnome-session-b
   
   3325 ?        00:00:00 VBoxClient
   
   3326 ?        00:00:00 VBoxClient
   
   3338 ?        00:00:00 VBoxClient
   
   3339 ?        00:00:00 VBoxClient
   
   3345 ?        00:00:00 VBoxClient
   
   3346 ?        00:02:07 VBoxClient
   
   3349 ?        00:00:00 VBoxClient
   
   3351 ?        00:00:00 VBoxClient
   
   3357 ?        00:00:00 ssh-agent
   
   3379 ?        00:00:00 at-spi-bus-laun
   
   3384 ?        00:00:00 dbus-daemon
   
   3404 ?        00:00:00 gnome-session-c
   
   3411 ?        00:00:00 gnome-session-b
   
   3425 ?        00:26:52 gnome-shell
   
   3450 ?        00:00:01 ibus-daemon
   
   3454 ?        00:00:00 ibus-memconf
   
   3455 ?        00:00:04 ibus-extension-
   
   3458 ?        00:00:01 ibus-x11
   
   3461 ?        00:00:00 ibus-portal
   
   3471 ?        00:00:02 at-spi2-registr
  
  3475 ?        00:00:00 xdg-permission-
  
  3478 ?        00:00:00 gnome-shell-cal
  
  3486 ?        00:00:00 evolution-sourc
  
  3496 ?        00:00:00 evolution-calen
  
  3504 ?        00:00:00 dconf-service
  
  3509 ?        00:00:00 evolution-addre
  
  3528 ?        00:00:00 gjs
  
  3529 ?        00:00:00 gvfsd-trash
  
  3542 ?        00:00:00 gsd-a11y-settin
  
  3551 ?        00:00:01 gsd-color
  
  3552 ?        00:00:00 gsd-datetime
  
  3553 ?        00:00:01 gsd-housekeepin
  
  3554 ?        00:00:01 gsd-keyboard
  
  3555 ?        00:00:01 gsd-media-keys
  
  3558 ?        00:00:01 gsd-power
  
  3561 ?        00:00:00 gsd-print-notif
  
  3563 ?        00:00:00 gsd-rfkill
  
  3567 ?        00:00:00 gsd-screensaver
  
  3570 ?        00:00:01 evolution-alarm
  
  3571 ?        00:00:00 gsd-sharing
  
  3576 ?        00:00:00 gsd-smartcard
  
  3581 ?        00:00:00 gsd-sound
  
  3586 ?        00:00:00 gsd-usb-protect
  
  3588 ?        00:00:01 gsd-wacom
  
  3593 ?        00:00:00 gsd-wwan
  
  3598 ?        00:00:01 gsd-xsettings
  
  3604 ?        00:00:00 gsd-disk-utilit
  
  3687 ?        00:00:00 gsd-printer
  
  3708 ?        00:00:00 ibus-engine-sim
  
  3770 ?        00:00:00 gvfsd-metadata
  
  3773 ?        00:00:03 update-notifier
  
  5506 ?        00:00:00 rwhod
  
  5507 ?        00:00:00 rwhod
  
  9044 ?        00:00:00 gvfsd-recent
  
  9073 ?        00:00:00 gvfsd-network
  
  9084 ?        00:00:00 gvfsd-dnssd
  
  11189 ?        00:00:03 kworker/1:0-events
  
  12041 tty3     00:00:00 dconf-service
  
  12148 ?        00:06:34 firefox
  
  12189 ?        00:00:00 Socket Process
  
  12202 ?        00:00:00 xdg-desktop-por
  
  12206 ?        00:00:00 xdg-document-po
  
  12215 ?        00:00:01 xdg-desktop-por
  
  12267 ?        00:00:01 WebExtensions
  
  12287 ?        00:00:04 Privileged Cont
  
  12398 ?        00:00:00 Web Content
  
  12409 ?        00:00:00 Web Content
  
  12530 ?        00:00:00 Web Content
  
  12907 ?        00:01:20 file:// Content
  
  13365 ?        00:00:05 snapd
  
  14011 ?        00:00:00 kworker/0:1-events
  
  14147 ?        00:00:00 kworker/2:2-events
  
  14373 ?        00:00:15 gnome-terminal-
  
  14388 ?        00:00:01 kworker/2:0-events
  
  14493 ?        00:00:02 nautilus
  
  14523 ?        00:00:00 kworker/1:1-events
  
  14524 ?        00:00:00 kworker/0:2

14637 ?        00:00:00 kworker/u6:1-events_unbound

14693 pts/0    00:00:00 bash

14700 ?        00:00:00 kworker/u6:0-events_unbound

14753 ?        00:00:00 kworker/u6:2-events_unbound

14754 pts/0    00:00:00 ps

anastasia@anastasia-VirtualBox:~$ ps -a

PID TTY          TIME CMD

2790 tty3     00:00:01 Xorg

2862 tty3     00:00:00 dbus-run-sessio

2864 tty3     00:00:00 dbus-daemon

2867 tty3     00:00:00 gnome-session-b

2882 tty3     00:00:00 at-spi-bus-laun

2889 tty3     00:00:00 dbus-daemon

2927 tty3     00:00:47 gnome-shell

2973 tty3     00:00:00 ibus-daemon

2976 tty3     00:00:00 ibus-memconf

2979 tty3     00:00:00 ibus-x11

2984 tty3     00:00:00 ibus-portal

2995 tty3     00:00:00 at-spi2-registr

3001 tty3     00:00:00 xdg-permission-

3017 tty3     00:00:00 gjs

3031 tty3     00:00:00 gsd-sharing

3032 tty3     00:00:00 gsd-wacom

3035 tty3     00:00:00 gsd-color

3038 tty3     00:00:00 gsd-keyboard

3040 tty3     00:00:00 gsd-print-notif

3042 tty3     00:00:00 gsd-rfkill

3044 tty3     00:00:00 gsd-smartcard

3045 tty3     00:00:00 gsd-datetime

3050 tty3     00:00:00 gsd-media-keys

3053 tty3     00:00:00 gsd-screensaver

3056 tty3     00:00:00 gsd-sound

3064 tty3     00:00:00 gsd-a11y-settin

3070 tty3     00:00:01 gsd-housekeepin

3071 tty3     00:00:00 gsd-power

3074 tty3     00:00:00 ibus-engine-sim

3094 tty3     00:00:00 gsd-printer

3227 tty2     00:07:37 Xorg

3251 tty2     00:00:00 gnome-session-b

12041 tty3     00:00:00 dconf-service

14755 pts/0    00:00:00 ps

anastasia@anastasia-VirtualBox:~$ ps -a|wc

36     144    1362

anastasia@anastasia-VirtualBox:~$ ps -A|wc

259    1042   10027

anastasia@anastasia-VirtualBox:~$ man wc

anastasia@anastasia-VirtualBox:~$ ps -A|wc

259    1042   10050

anastasia@anastasia-VirtualBox:~$ man wc

anastasia@anastasia-VirtualBox:~$ ps -a|wc -l

36

11. Выводы

Благодаря лабораторной работе я изучила программное обеспечение ОС UNIX. Я научилась создавать, копировать и редактировать файлы и каталоги, перемещаться по директориям. Я приобрела навыки по применению утилиты Gnuplot.  Всё это поможет мне в дальнейшем более глубоко изучать данную операционную систему.
