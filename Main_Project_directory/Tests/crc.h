#pragma once
#include <cstdint>

// Вычисляет CRC16 (CRC-16/MCRF4XX или аналог — уточнить)
// data     — указатель на массив байт (payload)
// length   — количество байт
// Возвращает 16-битную контрольную сумму
uint16_t calculateCRC16(const uint8_t* data, size_t length);
