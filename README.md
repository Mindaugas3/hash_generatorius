# hash_generatorius
 hashavimo generatorius
 
# Patobulinimai:
1. Atsikratyta dvigubo ciklo - konstitucija hašuojama žymiai greičiau (45 s -> 8 ms) 
2. Sukurtos pagalbines komandos(argumentai)
3. Patobulintas algoritmas, kad atsikratyti koliziju
 
# Paleidimo instrukcijos:
1. (Turintiems CLion) Edit Run/Debug configurations -> Edit Configurations -> Nurodyti argumentus(komandas ir failų pavadinimus - iki 2 failų) eilutėje "Program arguments"
Paleidimo argumentai:
1. -help, -h, ? - pagalbos funkcija
2. -file, -f  [Failo vardas] - vieno failo nuskaitymas ir suhasavimas.
3. -timer, -t [Failo vardas] - vieno failo nuskaitymas ir suhasavimas. Hasas neisvedamas i ekrana, tik ismatuojamas hasavimo laikas.
(pvz.: start hash_generatorius.exe -timer konstitucija.txt)
4. -line, -l [Failo vardas] - nuskaito kiekviena eilute ir ja atskirai suhasuoja.
5. -collision, -col [Failo vardas] - atlieka kolizijos testa su kiekviena failo eilute.
(pvz.: start hash_generatorius.exe -collision poros.txt)
6. -write, -w, (programa paleidziama be argumentu) - leidzia rasyti hashavima ranka.
7. -generate, -g: - sugeneruoja testinius failus. 1000 - sugeneruoja faila su 1000 simboliu. pairs - sugeneruoja faila su 100000 poru 

# Pseudokodas:

```
create inputvec (16) empty vector of bytes

    foreach(index = 0; i < input size; increment i by 1) do {
        choose val from array of constants
        
        define byte modifiedbyte = choose CHAR FROM INPUT
        
        modifiedbyte XOR with val and ASSIGN to self
        modifiedbyte MULTIPLY BY 5 and ASSIGN to self
        modifiedbyte RIGHT BITWISE SHIFT BY 7u and ASSIGN to self
        modifiedbyte ADD val and ASSIGN to self
        
        inputvec[index] ADD modifiedbyte and ASSIGN to self
    }
  
create bytevec (16) empty vector of bytes
    foreach(byte : bytevec) do {
        choose val from array of constants
        ASSIGN val to byte
    }
    
    if(input size > 16) do {
        for(i = 0; i < input size; increment i by 1 ) do {
            ADD byte FROM input TO bytevec[position]
            
            define sum = 0
            foreach(byte : input) do {
                sum ADD byte and ASSIGN to self
            }
            XOR sum of all bytes to bytevec[position] and ASSIGN to self
            DEREFERENCE byte AT position XOR with input[i] BITWISE RIGHT SHIFT by 3u AND ASSIGN to self
            
            increment position by 1
            if(position > 16) do {
              position = 0
            }
        }
    } else do {
        define position = 0
        for(i = 0; i < 16; i++) do {
            if(i == input size) do {
                position = 0
            } else do {
                ADD input[position] to bytevec[i]
                
                define sum = 0
                foreach(byte : input) do {
                    sum ADD byte AND ASSIGN to bytevec[i]
                }
                
                BITWISE LEFT SHIFT bytevec[i] by 3u and ASSIGN to self
                XOR bytevec[i] with input[position] and ASSIGN to self
                position++
            }
        }
    }     
        
```
 
# Savybės:
 1. + Maišos funkcija generuoja vienodo dydžio bitų vektorius, kurie yra pilnai užpildomi nepriklausomai nuo įvesties dydžio. Vienodo dydžio bitų vektoriai, bet išvesties šešioliktainiu skaičiumi ilgis gali skirtis
 2. + Maišos funkcija nenaudoja random elementų - hash kodas priklauso tik nuo įvesties.(Deterministinė funkcija)
 3. + Yra sniego lavinos efektas
 4. + Algoritmas pakankamai atsparus kolizijoms
 5. + Greitai veikia
 5. - Outputo dydis gali skirtis
 
# Testų rezultatai
**Rezultatas su tuščiu failu**

![](https://i.imgur.com/5dx8uad.png)

Pridėtas funkcionalumas palyginti kelis failus, pagal šešioliktainio kodo ir pagal bitų skirtumą:

**Rezultatas su dviem skirtingais failais, kuriuose yra tik vienas simbolis: A, ir a**

![](https://i.imgur.com/KTjY4eS.png)

**Rezultatas su 1000 atsitiktinai sugeneruotų simbolių. Smarkiai skiriasi**

![](https://i.imgur.com/xCAVdcs.png)

**Rezultatas su 1000 atsitiktinai sugeneruotų simbolių. Failas buvo nukopijuotas ir viena atsitiktinai pasirinkta raidė "t" buvo pakeista į raidę "h"**

![](https://i.imgur.com/6EydqlB.png)

**Rezultatas hašuojant konstituciją**

Procesorius: AMD Ryzen 7 3700X

![](https://i.imgur.com/OGXZLZ2.png)

**Kolizijų testai**

![](https://i.imgur.com/IwJd3dw.png)

![](https://i.imgur.com/fRDWA5h.png)

