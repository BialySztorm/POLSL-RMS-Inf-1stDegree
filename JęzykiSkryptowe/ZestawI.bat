@echo off
chcp 65001
:menu
cls
echo Proste Menu
echo 1. Wyświetl "Hello, world"
echo 2. Usuń pliki z rozszerzeniem *.txt
echo 3. Skopiuj pliki *.txt, *.jpg, *.gif
echo 4. Utwórz 10 katalogów
echo 5. Zapytaj użytkownika o imię
echo 6. Oblicz sumę/różnicę/iloczyn/iloraz
echo 7. Konwertuj nazwę miesiąca na numer
echo 8. Proste Menu - Uruchom, Backup, Informacje, Koniec
echo 9. Zapisz informacje o plikach starszych niż 30 dni
echo 10. Odwróć tekst i zapisz do pliku
echo 11. Koniec

set /p choice=Wybierz opcję: 

if "%choice%"=="1" (
    echo Hello, world
    pause
    goto menu
)

if "%choice%"=="2" (
    del *.txt
    pause
    goto menu
)

if "%choice%"=="3" (
    xcopy /s /i *.txt *.jpg *.gif C:\ścieżka\do\drugiego\katalogu
    pause
    goto menu
)

if "%choice%"=="4" (
    for /l %%i in (1,1,10) do (
        mkdir folder%%i
    )
    pause
    goto menu
)

if "%choice%"=="5" (
    set /p name=Podaj swoje imię: 
    title Konsola - Witaj, %name%!
    pause
    goto menu
)

if "%choice%"=="6" (
    set /p num1=Podaj pierwszą liczbę: 
    set /p num2=Podaj drugą liczbę: 
    set /a sum=num1+num2
    set /a difference=num1-num2
    set /a product=num1*num2
    set /a quotient=num1/num2
    echo Suma: %sum%
    echo Różnica: %difference%
    echo Iloczyn: %product%
    echo Iloraz: %quotient%
    pause
    goto menu
)

if "%choice%"=="7" (
    set /p month=Nazwa miesiąca: 
    if /i "%month%"=="Styczeń" echo 1
    if /i "%month%"=="Luty" echo 2
    if /i "%month%"=="Marzec" echo 3
    if /i "%month%"=="Kwiecień" echo 4
    if /i "%month%"=="Maj" echo 5
    if /i "%month%"=="Czerwiec" echo 6
    if /i "%month%"=="Lipiec" echo 7
    if /i "%month%"=="Sierpień" echo 8
    if /i "%month%"=="Wrzesień" echo 9
    if /i "%month%"=="Październik" echo 10
    if /i "%month%"=="Listopad" echo 11
    if /i "%month%"=="Grudzień" echo 12
    pause
    goto menu
)

if "%choice%"=="8" (
    :submenu
    cls
    echo Proste Menu - Uruchom, Backup, Informacje, Koniec
    echo 1. Uruchom
    echo 2. Backup
    echo 3. Informacje
    echo 4. Koniec
    set /p submenu_choice=Wybierz opcję: 

    if "%submenu_choice%"=="1" (
        echo Uruchom skrypt1.bat
        call skrypt1.bat
        pause
        goto submenu
    )

    if "%submenu_choice%"=="2" (
        echo Wykonuję kopię zapasową...
        
        REM Definiowanie ścieżki źródłowej i docelowej
        set "zrodlo=%CD%"
        set "docelowy=%CD%\backup"

        REM Sprawdzenie, czy katalog docelowy istnieje, jeśli nie, to go utworzenie
        if not exist "%docelowy%" (
            mkdir "%docelowy%"
        )
        echo Katalog docelowy: %docelowy%

        REM Kopiowanie plików
        for %%A in ("%zrodlo%\*") do (
            set "plik=%%~nxA"
            copy "%%A" "%docelowy%\%plik%-kopia"
        )
        pause
        goto submenu
    )

    if "%submenu_choice%"=="3" (
        echo Autor: Andrzej Manderla
        pause
        goto submenu
    )

    if "%submenu_choice%"=="4" (
        goto menu
    )
)

if "%choice%"=="9" (
    forfiles /p . /s /m *.* /d -30 /c "cmd /c echo @path @fdate" > rozwiazanieZad10.txt
    pause
    goto menu
)

if "%choice%"=="10" (
    setlocal enabledelayedexpansion
    set /p input=Podaj tekst: 
    set "reversed="
    for /l %%i in (0,1,1000) do (
        set "char=!input:~%%i,1!"
        if not defined char (
            goto write
        )
        set "reversed=!char!!reversed!"
    )
    :write
    echo !reversed! > odwrocony.txt
    pause
    goto menu
)

if "%choice%"=="11" (
    exit
)