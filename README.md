# watering_system_app
Automatic watering system using NODEMCU ESP8266 written in C programming language

U ovom radu opisan je koncept i realizacija automatskog sistema kontrole nivoa vode u stajama za uzgoj stoke. <br /> Projekat je rađen s ciljem olakšanja obavljanja dijela posla stočarskim uzgajivačima na način automatizacije istog. Pošto danas nema mnogo radnika na sličnim pozicijama, uzgajivači stoke tu nekolicinu radnika nerijetko jako skupo plaćaju, a svjedoci smo i enormnog porasta cijena zadnjih godina tako da im se isto ne isplati. <br /> Rješenje bi bilo upravo automatizacija ovih I sličnih poslova ili barem dijela posla. <br />
U automatskim sistemima nadzora, radnje se poduzimaju na temelju trenutnih mjernih podataka. Drugim riječima, sistem je dovoljno pametan da poduzme nezavisne radnje upravljanja podacima, smanjujući ljudske intervencije. <br />
U ovom projektu za upravljanje procesom automatizacije korištena je mikroupravljačka pločica NodeMCU ESP8266. <br /> Kao ulazni element u sistem korišten je senzor za mjerenje nivoa vode a izvršni član je pumpa za vodu kojom se upravlja preko releja. <br />
Bežična komunikacija je omogućena preko ugrađenog WIFI NodeMCU modula na ESP8266 koji komunicira s web serverom. <br />
Nakon ulaska u web sučelje, te pokretanjem automatskog sistema kontrole vode korisnik dobiva uvid u trenutne vrijednosti očitane sa senzora.  <br />
Kada je uključeno automatsko upravljanje izvršni elementi se pokreću prema zadanim parametrima te je korisnik preko web sučelja obaviješten da je izvršni element pokrenut. <br />
Podaci očitani sa senzora se šalju i pohranjuju na Google bazu podataka - Firebase, a web stranica, impementirana u html-u kroz Visual Studio Code, je povezana na Firebase te na taj način dohvata podatke očitane sa senzora i ispisuje ih. <br />
Na slici 1 prikazan je Finite State Machine dijagram sistema za automatsku kontrolu nivoa vode u stajama za uzgoj stoke.

