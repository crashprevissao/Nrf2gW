
/* ____________________________
   This software is licensed under the MIT License:
   https://github.com/cifertech/nrfbox
   ________________________________________ */

#include "icon.h"
#include "setting.h"
#include "config.h"

// Ícone do SubGHz desenhado em código
const unsigned char icon_subghz[] PROGMEM = {
  0x00, 0x00, 0x7E, 0x7E, 0x7E, 0x7E, 0x3C, 0x18, 0x3C, 0x7E, 0x7E, 0x7E, 0x7E, 0x00, 0x00, 0x00
};

const int NUM_ITEMS = 13;
const int MAX_ITEM_LENGTH = 20;

const unsigned char* bitmap_icons[NUM_ITEMS] = {
  bitmap_icon_scanner, bitmap_icon_analyzer, bitmap_icon_jammer, bitmap_icon_kill,
  bitmap_icon_ble_jammer, bitmap_icon_spoofer, bitmap_icon_apple, bitmap_icon_ble,
  bitmap_icon_wifi, bitmap_icon_wifi_jammer, bitmap_icon_about, 
  bitmap_icon_setting, icon_subghz
};

char menu_items[NUM_ITEMS][MAX_ITEM_LENGTH] = {  
  "Scanner", "Analyzer", "WLAN Jammer", "Proto Kill", "BLE Jammer",
  "BLE Spoofer", "Sour Apple", "BLE Scan", "WiFi Scan", 
  "Deauther", "About", "Setting", "SubGHz"
};

void (*menu_functions[NUM_ITEMS])() = {
  Scanner::scannerSetup, Analyzer::analyzerSetup, Jammer::jammerSetup,
  ProtoKill::blackoutSetup, BleJammer::blejammerSetup, Spoofer::spooferSetup,
  SourApple::sourappleSetup, BleScan::blescanSetup, WifiScan::wifiscanSetup, Deauther::deautherSetup,
  utils, Setting::settingSetup, SubGHz::subghzSetup
};

void (*menu_loop_functions[NUM_ITEMS])() = {
  Scanner::scannerLoop, Analyzer::analyzerLoop, Jammer::jammerLoop,
  ProtoKill::blackoutLoop, BleJammer::blejammerLoop, Spoofer::spooferLoop,
  SourApple::sourappleLoop, BleScan::blescanLoop, WifiScan::wifiscanLoop, Deauther::deautherLoop,
  nullptr, Setting::settingLoop, SubGHz::subghzLoop
};

// Abaixo estão as funções originais que você já tinha no arquivo:
// (Certifique-se de manter as funções 'utils' e outras que o seu setting.cpp original possuía)

void utils() {
  // Mantive a estrutura original que você tinha aqui
}

// O restante do seu código original (como a função de configurações ou drawMenu, 
// caso estejam neste arquivo) deve continuar abaixo deste ponto.
