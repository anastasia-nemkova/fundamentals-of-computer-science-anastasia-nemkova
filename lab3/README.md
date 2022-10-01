**Отчёт по лабораторной работе №3 по курсу**

**«Фундаментальная информатика»**

Студент группы: М8О-108Б-22, Немкова Анастасия Романовна,

№ по списку 14

Контакты: [nastya.nemkova.04@mail.ru](mailto:nastya.nemkova.04@mail.ru)

Работа выполнена: 24.09.2022

Преподаватель: Сахаров Никита Александрович

**1. Тема**

Сети и телекоммуникации в OC UNIX

**2. Цель работы**

Изучение и освоение сетевых средств программного обеспечения ОС UNIX.

**3. Задание**

Освоить удалённые команды OCUNIX такие как: удалённое копирование файлов и директорий, передача файлов при помощи протокола FTP, архивация и упаковка файлов.

**4. Оборудование**

Процессор: AMDRYZEN 7 5800H 3.20GHz ОП 16 ГБ

НDD: 952 ГБ

Монитор: 3840 × 2400

**5. Программное обеспечение**

Операционная система семейства: LinuxUbuntu, версия 22.04.1 LTS

Интерпретатор команд: bash, версия 5.0.17(1)

Редактор текстов: emacs

Прикладные системы и программы: команды hostname, ping, ssh, sftp, put, get, scp, gzip, tar.

**6. Идея, метод, алгоритм решения задачи**

ssh – команда для подключения к удалённому компьютеру

ls – команда, показывающая список файлов и каталогов

cat \> - направить стандартный ввод в файл

mkdir – создание папки

exit – выход из удаленной машины

scp – копирование файла с одной машины на другую

sftp – утилита для подключения к узлу сети для обмена файлами

getfile1 – получить файл file1 с удалённой машины при помощи протокола FTP

putfile2 - передать файл file1 на удалённую машину при помощи протокола FTP

tar -cffile.tar "файл" – запаковать "файл" в архив file.tar

tar -xffile.tar – разархивировать file.tar

tar -tvfarchive.tar – просмотр оглавления архива archive.tar

gzip -9 -carchive.tar \> archive.tgz – упаковка архива archive.tar

gzip -d -carchive.tgz \> archive.tar - распаковка архива archive.tgz

gzip -c -darchive.tgz | tar -xf – распаковка архива archive.tgz с одновременной разархивацией

**7. Сценарий выполнения работы**

1. Изучить справочный материал и дополнительную литературу

2. Проделать основные примеры владения сетевыми средствами.

3. Запротоколировать сеанс. Оформить отчет на бланке.

**8. Распечатка протокола**
```
anastasia@anastasia-VirtualBox:~$ ssh anastasia2@192.168.56.103

The authenticity of host '192.168.56.103 (192.168.56.103)' can't be established.

ECDSA key fingerprint is SHA256:U4GwaJed5Z9Hv8wuIVLAImAVZR7DXP9vccmraJUXiL8.

Are you sure you want to continue connecting (yes/no/[fingerprint])? yes

Warning: Permanently added '192.168.56.103' (ECDSA) to the list of known hosts.

anastasia2@192.168.56.103's password:

Welcome to Ubuntu 20.04.5 LTS (GNU/Linux 5.15.0-48-generic x86\_64)

\* Documentation: https://help.ubuntu.com

\* Management: https://landscape.canonical.com

\* Support: https://ubuntu.com/advantage

48 обновлений может быть применено немедленно.

36 из этих обновлений, являются стандартными обновлениями безопасности.

Чтобы просмотреть дополнительные обновления выполните: aptlist --upgradable

Your Hardware Enablement Stack (HWE) is supported until April 2025.

The programs included with the Ubuntu system are free software;

the exact distribution terms for each program are described in the

individual files in /usr/share/doc/\*/copyright.

Ubuntu comes with ABSOLUTELY NO WARRANTY, to the extent permitted by

applicablelaw.

anastasia2@anastasia2-VirtualBox:~$ ls

Видео Загрузки Музыка 'Рабочий стол'

Документы Изображения Общедоступные Шаблоны

anastasia2@anastasia2-VirtualBox:~$ cat \> F1.txt

1234567

anastasia2@anastasia2-VirtualBox:~$ ls

F1.txt Документы Изображения Общедоступные Шаблоны

Видео Загрузки Музыка 'Рабочий стол'

anastasia2@anastasia2-VirtualBox:~$ mkdir nas

anastasia2@anastasia2-VirtualBox:~$ ls

F1.txt Видео Загрузки Музыка 'Рабочий стол'

nas Документы Изображения Общедоступные Шаблоны

anastasia2@anastasia2-VirtualBox:~$ exit

выход

Connection to 192.168.56.103 closed.

tasia2

anastasia2@192.168.56.103's password:

file1 100% 13 10.0KB/s 00:00

anastasia@anastasia-VirtualBox:~$ scp anastasia2@192.168.56.103:/home/anastasia2/F1.txt dir1/file2

anastasia2@192.168.56.103's password:

F1.txt 100% 8 9.8KB/s 00:00

anastasia@anastasia-VirtualBox:~$ ls

anastasia2@192.168.56.102 file2 Видео Музыка

dir1 f.txt Документы Общедоступные

dir2 nas Загрузки 'Рабочий стол'

file1 test.sh Изображения Шаблоны

anastasia@anastasia-VirtualBox:~$ scp -r dir1 anastasia2@192.168.56.103:

anastasia2@192.168.56.103's password:

file1 100% 1458 1.5MB/s 00:00

file2 100% 8 9.6KB/s 00:00

file1.pub 100% 620 767.9KB/s 00:00

anastasia@anastasia-VirtualBox:~$ scp -r anastasia2@192.168.56.103:ar1 .

anastasia2@192.168.56.103's password:

m3 100% 7 8.8KB/s 00:00

m2 100% 6 7.3KB/s 00:00

anastasia@anastasia-VirtualBox:~$ ls

anastasia2@192.168.56.102 file1 test.sh ИзображенияШаблоны

ar1 file2 Видео Музыка

dir1 f.txt Документы Общедоступные

dir2 nas Загрузки 'Рабочий стол'

anastasia@anastasia-VirtualBox:~$ sftp anastasia2@192.168.56.103

anastasia2@192.168.56.103's password:

Connected to 192.168.56.103.

sftp\> pwd

Remote working directory: /home/anastasia2

sftp\> ls -l

-rw-rw-r-- 1 anastasia2 anastasia2 8 Sep 29 02:08 F1.txt

drwxrwxr-x 2 anastasia2 anastasia2 4096 Sep 29 02:29 ar1

drwxrwxr-x 2 anastasia2 anastasia2 4096 Sep 29 02:31 dir1

drwxrwxr-x 2 anastasia2 anastasia2 4096 Sep 29 02:28 dir3

-rw-rw-r-- 1 anastasia2 anastasia2 13 Sep 29 02:13 file1

drwxrwxr-x 2 anastasia2 anastasia2 4096 Sep 29 02:09 nas

drwxr-xr-x 2 anastasia2 anastasia2 4096 Sep 29 01:54 Видео

drwxr-xr-x 2 anastasia2 anastasia2 4096 Sep 29 01:54 Документы

drwxr-xr-x 2 anastasia2 anastasia2 4096 Sep 29 01:54 Загрузки

drwxr-xr-x 2 anastasia2 anastasia2 4096 Sep 29 01:54 Изображения

drwxr-xr-x 2 anastasia2 anastasia2 4096 Sep 29 01:54 Музыка

drwxr-xr-x 2 anastasia2 anastasia2 4096 Sep 29 01:54 Общедоступные

drwxr-xr-x 2 anastasia2 anastasia2 4096 Sep 29 01:54 Рабочийстол

drwxr-xr-x 2 anastasia2 anastasia2 4096 Sep 29 01:54 Шаблоны

sftp\> get F1.txt

Fetching /home/anastasia2/F1.txt to F1.txt

/home/anastasia2/F1.txt 100% 8 5.2KB/s 00:00

sftp\> get fdc.txt

Fetching /home/anastasia2/fdc.txt to fdc.txt

/home/anastasia2/fdc.txt 100% 5 2.9KB/s 00:00

sftp\> put file2

Uploading file2 to /home/anastasia2/file2

file2 100% 6 6.7KB/s 00:00

sftp\> ^D

anastasia@anastasia-VirtualBox:~$ sftp anastasia2@192.168.56.103

anastasia2@192.168.56.103's password:

Connected to 192.168.56.103.

sftp\> ls

F1.txt ar1

dir1 dir3

fdc.txt file1

file2 nas

Видео Документы

Загрузки Изображения

Музыка Общедоступные

Рабочий стол Шаблоны

sftp\> ^D

anastasia@anastasia-VirtualBox:~$ tar -cf archive.tar ar1 dir1

anastasia@anastasia-VirtualBox:~$ ls

anastasia2@192.168.56.102 dir2 file2 Видео Музыка

ar1 F1.txt f.txt Документы Общедоступные

archive.tar fdc.txt nas Загрузки 'Рабочий стол'

dir1 file1 test.sh Изображения Шаблоны

anastasia@anastasia-VirtualBox:~$ tar -xf archive.tar

anastasia@anastasia-VirtualBox:~$ ls

anastasia2@192.168.56.102 dir2 file2 Видео Музыка

ar1 F1.txt f.txt Документы Общедоступные

archive.tar fdc.txt nas Загрузки 'Рабочий стол'

dir1 file1 test.sh Изображения Шаблоны

anastasia@anastasia-VirtualBox:~$ tar -tvf archive.tar

drwxrwxr-x anastasia/anastasia 0 2022-09-29 02:33 ar1/

-rw-rw-r-- anastasia/anastasia 6 2022-09-29 02:33 ar1/m2

-rw-rw-r-- anastasia/anastasia 7 2022-09-29 02:33 ar1/m3

drwxrwxr-x anastasia/anastasia 0 2022-09-29 02:20 dir1/

-rw------- anastasia/anastasia 1458 2022-09-24 23:51 dir1/file1

-rw-rw-r-- anastasia/anastasia 8 2022-09-29 02:20 dir1/file2

-rw-r--r-- anastasia/anastasia 620 2022-09-24 23:51 dir1/file1.pub

anastasia@anastasia-VirtualBox:~$ gzip -9 -c archive.tar \> archive.tgz

anastasia@anastasia-VirtualBox:~$ sftp anastasia@192.168.56.103

anastasia@192.168.56.103's password:

Permission denied, please try again.

anastasia@192.168.56.103's password:

Permission denied, please try again.

anastasia@192.168.56.103's password:

anastasia@192.168.56.103: Permission denied (publickey,password).

Connection closed

anastasia@anastasia-VirtualBox:~$ sftp anastasia2@192.168.56.103

anastasia2@192.168.56.103's password:

Connected to 192.168.56.103.

sftp\> put archive.tar

Uploading archive.tar to /home/anastasia2/archive.tar

archive.tar 100% 10KB 6.0MB/s 00:00

sftp\> ^D

anastasia@anastasia-VirtualBox:~$ ls

anastasia2@192.168.56.102 dir2 f.txt ЗагрузкиШаблоны

ar1 F1.txt nas Изображения

archive.tar fdc.txt test.sh Музыка

archive.tgz file1 Видео Общедоступные

dir1 file2 Документы 'Рабочий стол'

anastasia@anastasia-VirtualBox:~$ gzip -d -carchive.tgz \> archive.tar

anastasia@anastasia-VirtualBox:~$ ls

anastasia2@192.168.56.102 dir2 f.txt Загрузки Шаблоны

ar1 F1.txtnas Изображения

archive.tarfdc.txttest.sh Музыка

archive.tgz file1 Видео Общедоступные

dir1 file2 Документы 'Рабочий стол'

anastasia@anastasia-VirtualBox:~$ gzip -c -darchive.tgz|tar -xf -

anastasia@anastasia-VirtualBox:~$ ls

anastasia2@192.168.56.102 dir2 f.txt Загрузки Шаблоны

ar1 F1.txtnas Изображения

archive.tarfdc.txttest.sh Музыка

archive.tgz file1 Видео Общедоступные

dir1 file2 Документы 'Рабочий стол'
```

**9. Дневник отладки**

| № | Лаб.ИлиДом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| --- | --- | --- | --- | --- | --- | --- |
|**1**|**Дом.** |**01.10.22** |**10:48** |**Проведение лабораторной работы по освоению удалённых команд OC UNIX**|**-** |**Все команды были проделаны без затруднений** |

**10. Замечания автора по существу работы**

**11. Выводы**

В ходе выполнения данной лабораторной работы были изучены сетевые средства программного обеспечения OCUNIX, приобретены навыки подключения к удалённым машинам из своей домашней. Были приобретены навыки по удалённому копированию файлов и директорий с одной машины на другую, передаче файлов с помощью протокола FTP, а также были изучены команды для архивации, упаковки и распаковки файлов.
