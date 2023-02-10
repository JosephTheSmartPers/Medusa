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
1. Utána ki kell választani a Tools>Board>Boards Manager-ben az ESP8266-ot és letölti a szükséges fájlokat.
2. Miután bedugtad a mikrokontrollert, és iró módba álíttotad (kapcsolási ábra) megnyomod az upload gombot (egy nyíl ami fölfelé néz), és megvárod, míg feltölti a fájlt.
3. Ha sikeres volt a feltöltés, ki fogja írni a konzol-ban, hogy 100%, utána kihúzod a gépből, átváltod futtató módba, majd bedugod, és megnyitod a 
Tools>Serial Monitor-t, utána ki fogja írni az IP-címet, azt ajánlott megjegyezni, mivel a mi veboldalunkra ennek segítségével lehet szenzorokat konfigurálni.
#### Veboldal kezelése
1. A veboldal linkje jelenleg [ez](http://139.162.189.55/sensor/home.php), és miután készített egy felhasználót, be lesz jelentkezve adminként utána nyomja meg a kis nyilat a bal alsó sarokban, majd válassza ki az "Admin Panelt". 
<img src="https://github.com/JosephTheSmartPers/Medusa/blob/main/admin%20panel.png" width="25%" height="25%" />
ezek után csinálnia kell egy emeletet, nyomja meg a floorst aztán írjon be valamit a "floor name" helyére ezután nymoja meg az "add floor" gombot, és elvileg néhány másodperc után meg fog jelenni az új emelet. 
<img src="https://github.com/JosephTheSmartPers/Medusa/blob/main/add%20floor.png" width="90%" height="90%" />
2.  Utána a készített emeletnél az "e" gomb megnyomásával el fogja vinni egy oldalra ahol be kell állítani a szenzor nevét, utána az IP-címét, aminek segítségével fogja lekérni az adatbázisból a méréseket. 
<img src="https://github.com/JosephTheSmartPers/Medusa/blob/main/add%20sensor.png" width="90%" height="90%" /> 
3.  Ez után rá kell nyomni a felhasználó ikonra, majd az "user panel" gombra, és vissza fog vinni a normális felületre.
<img src="https://github.com/JosephTheSmartPers/Medusa/blob/main/user.png" width="90%" height="90%" />
4.  Készen van! Elvileg meg kell jelennie a méréseknek egy nagyon menő [Charts.js](https://www.chartjs.org/) segítségével készített grafikonon, csak dugja be a szenzort, ha mindent megcsinált.
