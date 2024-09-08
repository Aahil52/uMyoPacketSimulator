#include <Arduino.h>
#include <string>
#include <array>

#include <NimBLEDevice.h>

std::vector<uint8_t> prepareData(uint8_t data_id, uint8_t battery_level, std::array<int16_t, 4> spectrum, int muscle_level, std::array<int16_t, 4> quaternion);

NimBLEAdvertising *pAdvertising = NULL;

void setup() {
  NimBLEDevice::init("uMyo v2");

  pAdvertising = NimBLEDevice::getAdvertising();
  pAdvertising->setName("uMyo v2");

  pAdvertising->setManufacturerData(prepareData(1, 255, std::array<int16_t, 4>{32767, 3223, 323, 2121}, 255, std::array<int16_t, 4>{2323, 2232, 2323, 2323}));
  pAdvertising->start();
}

void loop() {
  // put your main code here, to run repeatedly:
} 

std::vector<uint8_t> prepareData(uint8_t data_id, uint8_t battery_level, std::array<int16_t, 4> spectrum, int muscle_level, std::array<int16_t, 4> quaternion) {
  std::vector<uint8_t> data;

  data.push_back(data_id);

  data.push_back(battery_level);

  data.push_back(spectrum[0]>>8);

  data.push_back(muscle_level);

  data.push_back(spectrum[1]>>8);
  data.push_back(spectrum[1]);

  data.push_back(spectrum[2]>>8);
  data.push_back(spectrum[2]);

  data.push_back(spectrum[3]>>8);
  data.push_back(spectrum[3]);

  data.push_back(quaternion[0]>>8);
  data.push_back(quaternion[0]);

  data.push_back(quaternion[1]>>8);

  data.push_back(quaternion[2]>>8);

  data.push_back(quaternion[3]>>8);

  return data;
}