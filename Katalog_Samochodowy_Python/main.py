#!/usr/bin/env python
import os

samochody=[]

def TwojWybor():
    x=input("Twój wybór? ")
    if len(x) > 0:
        return eval(x)
    else: 
        return -1

def pausa():
    input()

def clear(): # github - thanks
    '''
    Clears the terminal screen and scroll back to present
    the user with a nice clean, new screen. Useful for managing
    menu screens in terminal applications.
    '''
    os.system('cls||echo -e \\\\033c')

def PauseClear():
    pausa()
    clear()

def pokaz(kr):
    print(kr[0]+" "+kr[1]+ " "+str(kr[2])+"r "+ str(kr[3])+"cm^3 "+ str(kr[4])+"Km "+ kr[5])

def wybor1():
    print("Przy wpisywaniu spacje zastąp podkreślnikiem np. 'Mercedes_Benz'")
    mar=input("Podaj markę samochodu: ").replace(" ","")
    mod=input("Podaj model samochodu: ").replace(" ","")
    rocz=eval(input("Podaj rocznik samochodu: "))
    poje=eval(input("Podaj pojemość silnika samochodu (w cm^3): "))
    prz=eval(input("Podaj przebieg samochodu (w Km): "))
    skrz=input("Podaj typ skrzyni biegów samochodu (manualna czy automatyczna): " ).replace(" ","")
    kr=(mar, mod, rocz, poje, prz, skrz)
    samochody.append(kr)
    zapisane=False
    return zapisane

def wybor2():
    for i in samochody:
        pokaz(i)
    pausa()

def wybor3():
    print("Podaj na podstawie jakiego parametru chcesz wyswietlać dane")
    print("1.Marka")
    print("2.Model")
    print("3.Rocznik")
    print("4.Pojemność")
    print("5.Przebieg")
    print("6.Typ skrzyni biegów")
    warunek=TwojWybor()
    if (warunek in (1, 2, 6)):
        parametr=input("Podaj wartość jaką ma mieć dany parametr: ")
        for item in samochody:
            if parametr == item[warunek-1]:
                pokaz(item)
    elif warunek in (3, 4, 5):
        print("Podaj, czy wyświtlane samochody mają mieć daną wartość:")
        print("1.Wiekszą")
        print("2.Taką samą")
        print("3.Mniejszą")
        zaleznosc=TwojWubor()
        if not zaleznosc in (1, 2, 3): 
            print("Nie ma takiego parametru wyboru. Wychodzę")
            return None
        wartosc=eval(input("Podaj wartość "))    
        if zaleznosc == 1:
            for item in samochody:
                if item[warunek-1] > wartosc:
                    pokaz(item)
        elif zaleznosc == 2:
            for item in samochody:
                if item[warunek-1] == wartosc:
                    pokaz(item)
        elif zaleznosc == 3:
            for item in samochody:
                if item[warunek-1] < wartosc:
                    pokaz(item)
    else:
        print("Nie ma takiego parametru wyboru!")
    pausa()    

def wybor4():
    a=eval(input("Podaj indeks samochodu którego dane chcesz zoabczyć ("+ str(len(samochody))+" samochodów w katalogu): "))
    if (0 < a and a <=len(samochody)) :
        pokaz(samochody[a-1])
    else:
        print("Nie ma samochodu o takim indeksie w katalogu. ")
    pausa()

def wybor5():
    print("Podaj parametr na podstawie którego będą sortowane dane")
    print("1.Marka")
    print("2.Model")
    print("3.Rocznik")
    print("4.Pojemność")
    print("5.Przebieg")
    print("6.Typ skrzyni biegów")
    a=TwojWybor()
    if(a>0 and a < 7) :
        print("Jak posortować dane ?")
        print("1. Malejąco / od Z do A")
        print("2. Rosnąco /od A do Z")
        jak=TwojWybor()
        li=sorted(samochody, key=lambda sam :sam[a-1])
        if (jak == 1): 
            for i in reversed(li):
                pokaz(i)
        else:
            for i in li:
                pokaz(i)
    else:
        print("Nie ma takiego parametru wg. którego sortować !!!")
    pausa();

def wybor6():
    x=1
    for i in samochody:
        print("Pozycja # ",x)
        pokaz(i)
        x=x+1
    i=eval(input("Wpisz # samochodu który chcesz usunąć z katalogu: "))
    if (i > 0 and i < x):
        samochody.pop(i-1)
        zapisane=False
    else: 
        print("Nie ma takiego # w rejestrze !")
        zapisane=True
    return zapisane

def wybor7():
    nazwa=input("Podaj nazwę pliku do którego zapisać dany katalog (np. 'dane.txt') ")
    fo=open(nazwa,"w")
    for item in samochody:
        fo.writelines(str(item)+"\n")
    fo.close()
    zapisane=True
    return zapisane

def wybor8():
    nazwa=input("Podaj nazwę pliku z którego chcesz wczytać katalog (np. 'dane.txt') ")
    fo=open(nazwa, "r")
    lista=fo.readlines()
    fo.close()
    for item in lista:
        ll=item[1:-2].split(sep=",")
        mar=ll[0][1:-1]
        mod=ll[1][2:-1]
        rocz=int(ll[2])
        poje=int(ll[3])
        prz=int(ll[4])
        skrz=ll[5][2:-1]
        kr=(mar, mod, rocz, poje, prz, skrz)
        samochody.append(kr)

def wybor9(zapisane):
    wybor=9
    if ( not zapisane):
        print("Niektóre dane nie zostały zapisane, jesteś pewien że chcesz opuścić program ?")
        print("1. Nie")
        print("2. Tak")
        czy=TwojWybor()
        if (czy == 1): 
            wybor=0
        elif(czy == 2):
            print("Nie zapisuje danych !")
            zapisane=True
            wybor=9
            pausa()
        else:
            print("Nie ma takiej opcji. Powrót")
            wybor=0
            pausa()
    return zapisane, wybor

wybor=0
zapisane=True
while wybor !=9 :
    clear()
    print("PANEL GŁÓWNY")
    print("------------")
    print("1.Wprowadź nowy samochód")
    print("2.Wyświetl listę samochodów")
    print("3.Wyświetl listę samochodów (warunkowo)")
    print("4.Wyświetl konkretny samochód")
    print("5.Wyświetl listę samochodów (posortowana wg. pewnego parametru)")
    print("6.Usuń konkretny samochód")
    print("7.Zapisz bierzący katalog")
    print("8.Wczytaj katalog z pliku")
    print("9.Wyjdź")
    wybor=TwojWybor()
    if (wybor == 1):
        zapisane=wybor1()
    elif (wybor == 2) :
        wybor2()
    elif (wybor == 3) :
        wybor3()
    elif (wybor == 4) :
        wybor4()
    elif (wybor == 5) :
        wybor5()
    elif (wybor == 6) :
        zapisane=wybor6()
    elif (wybor == 7) :
        zapisane=wybor7()
    elif (wybor == 8) :
        wybor8()
    elif (wybor == 9) :
        zapisane, wybor=wybor9(zapisane)
    else:   
        print("Nie ma takiej opcji wyboru ")
        pausa()
