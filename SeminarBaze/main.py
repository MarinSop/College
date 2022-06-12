from tkinter import N
import data
import os

def clearConsole():
    command = 'clear'
    if os.name in ('nt', 'dos'):  # If Machine is running on Windows, use cls
        command = 'cls'
    os.system(command)

clearConsole()

def ispis(sh,ov):
    print(sh)
    print('{ ', end='')
    for x in ov:
        for y in x[0]:
            print(y ,end='')
        print('->', end='')
        for y in x[1]:
            print(y,end="")
        print(',',end='')
    print('}')

def ispisOvisnosti(ovA,ovB,red):
    for x in ovA:
        print(x,end="")
    print('->',end='')
    for x in ovB:
        print(x,end='')
    if red:
        print()

def ispisBaze():
    lenght = len(data.sheme)
    for i in range(0,lenght):
        print(str(i) + ':  ' + str(data.sheme[i]))
        print(str(i)+ ': { ' ,end="")
        for x in data.ovisnosti[i]:
            for y in x[0]:
                print(y ,end='')
            print('->', end='')
            for y in x[1]:
                print(y,end="")
            print(',',end='')
        print('}')
        print('------------------------------')

def ispisLst(lst,red):
    for x in lst:
        print(x,end='')
    if red:
        print()

def spajanjeStr(strA,strB):
    res = strB
    for i in strA:
        if i not in strB:
            res.append(i)
    return res


def provjera(strA,strB):
    res = False
    for i in strA:
        if i in strB:
            res = True
        else:
            return False
    return res

def algoritam(odbSh,odbOv,odBr):
    print("----------Racunanje kljuca----------")
    kljuc = (odbOv[odBr][0].copy(),odbOv[odBr][1].copy())
    ispisOvisnosti(kljuc[0],kljuc[1],True)
    kljuc = (kljuc[0],spajanjeStr(kljuc[0], kljuc[1]).copy())
    ispisOvisnosti(kljuc[0],kljuc[1],True)
    odbOv.pop(odBr)
    while(True):
        prosiri = True
        for i in odbOv:
            if provjera(i[0],kljuc[1]):
                fo = (i[0],i[1])
                toRemove = []
                for j in odbOv:
                    if fo[0] == j[0]:
                        fo = (fo[0],spajanjeStr(j[1],fo[1]).copy())
                        toRemove.append(odbOv.index(j))
                for k in range(len(toRemove),0,-1):
                    odbOv.pop(toRemove[k-1])
                prosiri = False
                ispisOvisnosti(kljuc[0],fo[0],False)
                print(' i ',end='')
                ispisOvisnosti(fo[0],fo[1],True)
                kljuc = (kljuc[0],spajanjeStr(fo[1],kljuc[1]).copy())
                ispisOvisnosti(kljuc[0],kljuc[1],True)
                break
        if prosiri and len(odbOv) > 0:
            fo = (odbOv[0][0].copy(),odbOv[0][1].copy())
            toRemove = []
            for i in odbOv:
                if fo[0] == i[0]:
                    fo = (fo[0],spajanjeStr(i[1],fo[1]).copy())
                    toRemove.append(i)
            for i in toRemove:
                odbOv.remove(i)
            print("Prosirujemo sa ",end='')
            ispisOvisnosti(fo[0],fo[1],True)
            kljuc = (spajanjeStr(fo[0],kljuc[0]).copy(),spajanjeStr(fo[0],kljuc[1]).copy())
            ispisOvisnosti(kljuc[0],kljuc[1],True)
            kljuc = (kljuc[0],spajanjeStr(fo[1],kljuc[1]).copy())
            ispisOvisnosti(kljuc[0],kljuc[1],True)
        if kljuc[1] == odbSh:
            print("Izracunati kljuc: ",end='')
            ispisLst(kljuc[0],True)
            return sorted(kljuc[0].copy())
        elif kljuc[1] != odbSh and len(odbOv) == 0:
            for i in odbSh:
                if i not in kljuc[1]:
                    kljuc = (spajanjeStr(i,kljuc[0]).copy(),spajanjeStr(i,kljuc[1]).copy())
                    print("Prosirujemo sa " + i)
                    ispisOvisnosti(kljuc[0],kljuc[1],True)
            print("Izracunati kljuc: ",end='')
            ispisLst(kljuc[0],True)
            return sorted(kljuc[0].copy())


















app = True

odabranaShema = []
odabranaOvisnost = []


while(app):
    ispisBaze()
    odabir = 'q'
    while(True):
        odabir = input("Zelite li obrisati sheme? (b)\nZelite unositi sheme? (u)\nZelite odabrati shemu? (o)\nUnesite slovo u zagradi: ")
        if odabir != 'b' and odabir != 'u' and odabir != 'o' and odabir != 'q':
            print("Neispravan unos. Pokusajte ponovno")
        else:
            break
    if odabir == 'b':
        clearConsole()
        if len(data.sheme) > 0:
            ispisBaze()
            brisUnos = -1
            while(True):
                brisUnos = int(input("Odaberite broj sheme koju zelite obrisati: "))
                if brisUnos < 0 or brisUnos > len(data.sheme)-1:
                    print("Neispravan unos")
                else:
                    break
            data.sheme.pop(brisUnos)
            data.ovisnosti.pop(brisUnos)
            clearConsole()
        else:
            print("Prazno")
    elif odabir == 'u':
        novaShema = []
        novaOvisnost = []
        while(True):
            unos = input("Unesite atribute. (--) za prestanak unosa : ")
            if unos == '--':
                break
            novaShema.append(unos)
        FOFlag = True
        while(True):
            funkOvs = ([],[])
            while(True):
                unos = input("Unesite atribute prvog dijela funkcionalne ovisnosti. (--) za prestanak prebacivanje na drugi dio :")
                if unos == '--':
                    break
                funkOvs[0].append(unos)
            while(True):
                unos = input("Unesite atribute drugog dijela funkcionalne ovisnosti. (--) za zavrsetak unosa :")
                if unos == '--':
                    break
                funkOvs[1].append(unos)
            novaOvisnost.append(funkOvs)
            if(input("Unesite q za prestanak unosa: ") == "q"):
                break
        if len(novaShema) > 0 and len(novaOvisnost) > 0:
            data.sheme.append(novaShema)
            data.ovisnosti.append(novaOvisnost)
            clearConsole()
        else:
            print("Neispravna shema ili funkcijska ovisnost")
            clearConsole()
    elif odabir == 'o':
        clearConsole()
        if len(data.sheme) == 0:
            print("Prazno")
            break
        ispisBaze()
        odabirSheme = int(input("Unesite broj sheme koju zelite odabrati: "))
        odabranaShema = data.sheme[odabirSheme]
        odabranaOvisnost = data.ovisnosti[odabirSheme]
        clearConsole()
        break
    elif odabir == 'q':
        app = False

print("Odabrana shema: ")
ispis(odabranaShema,odabranaOvisnost)
kljucevi = []
for i in range(0,len(odabranaOvisnost)):
    shCp = odabranaShema.copy()
    ovCp = odabranaOvisnost.copy()
    kljucevi.append(algoritam(shCp,ovCp,i))
resultKljucevi = [] 
for i in kljucevi: 
    if i not in resultKljucevi: 
        resultKljucevi.append(i)


print("Dobiveni ključevi:",end=" ")
for i in range(0,len(resultKljucevi)):
    print(str(i) + ": ",end="")
    ispisLst(resultKljucevi[i],False)
    print(", ",end="")
print()
odabirKljuc = []
while(True):
    odabirBrojKljuca = int(input("Upišite broj ključa koji želite odabrati."))
    if odabirBrojKljuca >= 0 and odabirBrojKljuca < len(resultKljucevi):
        odabirKljuc = resultKljucevi[odabirBrojKljuca]
        break

clearConsole()
print("----------3. Normalna Forma----------")
print("Odabrani ključ: ",end="")
ispisLst(odabirKljuc,True)

Q = []

for i in odabranaOvisnost:
    ispisOvisnosti(i[0],i[1],False)
    atr = sorted(spajanjeStr(i[0].copy(),i[1].copy()))
    print(" : ",end="")
    ispisLst(atr,False)
    dodaj = True
    for j in Q:
        if atr == j  :
            print(" Ne treba dodavati")
            dodaj = False
            break
    if dodaj:
        print(" ∉ Q => Q = {",end="")
        Q.append(atr)
        for i in Q:
            ispisLst(i,False)
            print(",",end=" ")
        print("}")
dodajKljuc = 0
for i in Q:
    dodajKljuc = 0
    for j in odabirKljuc:
        if j in i:
            dodajKljuc = dodajKljuc + 1
    if dodajKljuc == len(odabirKljuc):
        break    
if dodajKljuc != len(odabirKljuc):
    Q.append(odabirKljuc)
else:
    print("Ne treba dodavati ključ.")
print("Q = {",end=" ")
for i in Q:
    ispisLst(i,False)
    print(",",end=" ")
print("}")


print("----------BCNF----------")

BCQ = []
cnt = 0
for i in odabranaOvisnost:
    cnt = 0
    for j in i[1]:
        if j in odabranaShema:
            cnt += 1
    if cnt == len(i[1]):
        ispisOvisnosti(i[0],i[1],False)
        atr = sorted(spajanjeStr(i[0].copy(),i[1].copy()))
        print(" : ",end="")
        ispisLst(atr,False)
        BCQ.append(atr)
        for j in i[1]:
            odabranaShema.remove(j)
        print(" | R={",end="")
        ispisLst(odabranaShema,False)
        print("}")
BCQ.append(odabranaShema)
print("Q = {",end="")
for i in BCQ:
    ispisLst(i,False)
    print(", ",end="")
print("}")