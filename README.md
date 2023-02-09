# Medusa
### Bevezetés
A Medusa egy nyílt forrású projekt ami egy kicsi, otthon is könnyen összerakható hőszenzort és wifis mikrokontroller használ, hogy elküldje az adatokat, vagy a saját veboldaladra, vagy a mi könnyen használható felületünkre, amit lentebb majd részletesen leírunk. 
### Elektronika
### [Link a nyomtatható vázhoz és NYÁK-hoz](https://www.printables.com/model/394252-case-for-medusa-temperature-sensor/files)
#### Kapcsolási ábrák
<img src="https://github.com/JosephTheSmartPers/Medusa/blob/main/wiring.png" width="50%" height="50%" /> <img src="https://github.com/JosephTheSmartPers/Medusa/blob/main/sodering.png" width="30%" height="30%" /> <img src="https://github.com/JosephTheSmartPers/Medusa/blob/main/wiring2.png" width="50%" height="50%" /> 

### Program feltöltése mikrokontrollelre
#### Követelmények
1. Valamilyen alkalmazás, amivel feltöltöd a programot a chipre, mi az [Arduino IDE](https://www.arduino.cc/en/donate/)-t használtuk (töltsétek le a linken)
2. Egy "Board Manager" is kell az [ESP8266](https://en.wikipedia.org/wiki/ESP8266)-hoz amihez az útmutatót [itt](https://arduino.esp8266.com/stable/package_esp8266com_index.json) lehet megtalálni
3. A program amit rá kell tölteni az ESP8266-ra [homersekletOlvaso](https://github.com/JosephTheSmartPers/Medusa/tree/main) címen van feltöltve, ezt le kell tölteni, aztán meg kell nyitni a [homersekletOlvaso.ino](https://github.com/JosephTheSmartPers/Medusa/blob/main/homersekletOlvaso/homersekletOlvaso.ino) nevű fájlt.
#### Program feltöltése
1. Utána az ki kell választani a Tools>Board>Boards Manager-ben az ESP8266-ot és letölti a szükséges fájlokat.
2. Miután bedugtad a mikrokontrollert, és iró módba álíttotad (bővebben az elektronikánál) megnyomod az upload gombot, és megvárod, míg feltölti a fájlt.
3. Ha sikeres volt a feltöltés, ki fogja írni a konzol-ban, hogy 100%, utána kihúzod a gépből, átváltod futtató módba, majd bedugod, és megnyitod a 
Tools>Serial Monitor-t, utána ki fogja írni az IP-címet, azt ajánlott megjegyezni, mivel a mi veboldalunkra ennek segítségével lehet szenzorokat konfigurálni.
#### Veboldal kezelése (még nem működik)
1. A veboldal linkje jelenleg [ez](http://139.162.189.55/sensor/testhome.php), és miután készített egy felhasználót, be leszel jelentkezve adminként (bárki be tud jelentkezni vendégként, ha bekapcsolod a beálításokban) utána csinálnia kell egy emeletet, amit a plusz gomb megnyomásával lehet csinálni, a "create new floor" felirat mellett.
2. Utána a készített emeletnél a plusz gomb megnyomásával fel fog jönni egy menü, ahol be kell állítani a szenzor nevét, utána az IP-címét, aminek segítségével fogja lekérni az adatbázisból a méréseket, utána az ideális maximum és minimum hőmérsékleteket, illetve, hogy mennyi idő után szóljon, ha túllépte a hőmérsékletet.
3. Kész vagy! Elvileg meg kell jelennie a méréseknek egy nagyon menő [Charts.js](https://www.chartjs.org/) segítségével készített grafikonon
