#include <IRremote.hpp>
//pin sygnalu odbiornika IR podlaczony do cyfrowego pinu 11 Arduino (digital)
//Y - oznacza data
int receiverPin = 11; 
uint32_t ostatni_odkodowanyKod = 0;

void tlumaczIR() //wykonuje akcje w oparciu o odebrany kod IR
{
    //sprawdz, czy jest to powtarzajacy sie kod IR
    if(IrReceiver.decodedIRData.flags)
    {
        //ustaw aktualny kod IR jako ostatni odebrany
        IrReceiver.decodedIRData.decodedRawData = ostatni_odkodowanyKod;
        Serial.println("POWTORZENIE!");
    }
    else
    {
        //wyswietl kod IR w monitorze portu szeregowego
        Serial.print("Kod IR: 0x");
        Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
        //w systemie szesnastkowym
    }

    //mapowanie kodu IR na przycisk pilota
    switch(IrReceiver.decodedIRData.decodedRawData)
    {
        case 0xBA45FF00: Serial.println("POWER"); break;
        case 0xB847FF00: Serial.println("FUNKCJA/STOP"); break;
        case 0xB946FF00: Serial.println("VOL+"); break;
        case 0xBB44FF00: Serial.println("SZYBKI POWROT"); break;
        case 0xBF40FF00: Serial.println("PAUZA"); break;
        case 0xBC43FF00: Serial.println("SZYBKI PRZOD"); break;
        case 0xF807FF00: Serial.println("DOL"); break;
        case 0xEA15FF00: Serial.println("VOL-"); break;
        case 0xF609FF00: Serial.println("GORA"); break;
        case 0xE619FF00: Serial.println("EQ"); break;
        case 0xF20DFF00: Serial.println("ST/REPT"); break;
        case 0xE916FF00: Serial.println("0"); break;
        case 0xF30CFF00: Serial.println("1"); break;
        case 0xE718FF00: Serial.println("2"); break;
        case 0xA15EFF00: Serial.println("3"); break;
        case 0xF708FF00: Serial.println("4"); break;
        case 0xE31CFF00: Serial.println("5"); break;
        case 0xA55AFF00: Serial.println("6"); break;
        case 0xBD42FF00: Serial.println("7"); break;
        case 0xAD52FF00: Serial.println("8"); break;
        case 0xB54AFF00: Serial.println("9"); break;
        default:
            Serial.println("inny przycisk");
    }

    //zapisanie ostatniego odebranego kodu IR
    ostatni_odkodowanyKod = IrReceiver.decodedIRData.decodedRawData;
    delay(500); //0.5 sekundy opoznienia
}


void setuptask14()
{
    Serial.begin(9600);
    Serial.println("Dekodowanie przycisków odbiornika IR");
    IrReceiver.begin(receiverPin, ENABLE_LED_FEEDBACK); //uruchomienie odbiornika IR

}

void looptask14()
{
    if(IrReceiver.decode()) //czy odebrano sygnał IR?
    {
        tlumaczIR();
        IrReceiver.resume(); //odbierz nastepna wiadomosc (odblokowanie)
    }
}