# hash_generatorius
 hashavimo generatorius
 
 Savybės:
 1. Maišos funkcija generuoja vienodo dydžio bitų vektorius, kurie yra pilnai užpildomi nepriklausomai nuo įvesties dydžio. Vienodo dydžio bitų vektoriai, bet išvesties šešioliktainiu skaičiumi ilgis gali skirtis
 2. Maišos funkcija nenaudoja random elementų - hash kodas priklauso tik nuo įvesties.(Deterministinė funkcija)
 3. Pamėgintas įgyvendinti sniego lavinos efektas, kuris (dalinai) veikia tik esant stambiam failui su daug simbolių, t.y. pakeitus bitą stambiame faile maišos kodas skirsis šiek tiek labiau nei pakeitus bitą smulkiame faile.
 

**Rezultatas su tuščiu failu**

![](https://i.imgur.com/5dx8uad.png)

Pridėtas funkcionalumas palyginti kelis failus, pagal šešioliktainio kodo ir pagal bitų skirtumą:

**Rezultatas su dviem skirtingais failais, kuriuose yra tik vienas simbolis: A, ir a**

![](https://i.imgur.com/KTjY4eS.png)

**Rezultatas su 1000 atsitiktinai sugeneruotų simbolių. Smarkiai skiriasi**

![](https://i.imgur.com/xCAVdcs.png)

**Rezultatas su 1000 atsitiktinai sugeneruotų simbolių. Failas buvo nukopijuotas ir viena atsitiktinai pasirinkta raidė "t" buvo pakeista į raidę "h"**

![](https://i.imgur.com/6EydqlB.png)

