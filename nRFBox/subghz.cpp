#include "config.h"

// Ícone desenhado em código para o OLED
const unsigned char icon_controle[] PROGMEM = {
  0x00, 0x00, 0x7E, 0x7E, 0x7E, 0x7E, 0x3C, 0x18, 0x3C, 0x7E, 0x7E, 0x7E, 0x7E, 0x00, 0x00, 0x00
};

byte signalBuffer[128];
int signalSize = 0;

namespace SubGHz {

  void subghzSetup() {
    ELECHOUSE_cc1101.setSpiPin(18, 19, 23, CC1101_CSN_PIN);
    if (ELECHOUSE_cc1101.getCC1101()) {
      ELECHOUSE_cc1101.Init();
      ELECHOUSE_cc1101.setMHZ(433.92);
      ELECHOUSE_cc1101.setRx();
    }
  }

  void copySignal() {
    if (ELECHOUSE_cc1101.CheckReceiveFlag()) {
      signalSize = ELECHOUSE_cc1101.ReceiveData(signalBuffer);
      ELECHOUSE_cc1101.setRx();
    }
  }

  void playSignal() {
    if (signalSize > 0) {
      ELECHOUSE_cc1101.SendData(signalBuffer, signalSize);
      ELECHOUSE_cc1101.setRx();
    }
  }

  void subghzLoop() {
    u8g2.clearBuffer();
    // Desenha o ícone
    u8g2.drawXBMP(56, 0, 16, 8, icon_controle);
    
    u8g2.setFont(u8g2_font_6x10_tf);
    u8g2.drawStr(0, 25, "RF: 433.92 MHz");
    u8g2.drawStr(0, 40, signalSize > 0 ? "Sinal OK: Pronto" : "Aguardando...");
    u8g2.drawStr(0, 55, "SEL:Copiar | DIR:Reproduzir");
    u8g2.sendBuffer();

    if (digitalRead(BUTTON_SELECT_PIN) == LOW) copySignal();
    if (digitalRead(BTN_PIN_RIGHT) == LOW) playSignal();
  }
}
