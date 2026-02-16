# MyGame

## Сборка и запуск

### Зависимости
- C++17 компилятор (g++, clang, MSVC)
- [SFML](https://www.sfml-dev.org/) (графика и звук)
- libogg (обычно идёт вместе с SFML)

### Установка зависимостей
**Ubuntu**: `sudo apt install g++ cmake libsfml-dev`
**macOS**: `brew install gcc cmake sfml`
**Windows**: установите [CMake](https://cmake.org/) и [SFML](https://www.sfml-dev.org/download.php) (распакуйте в C:/SFML) или используйте vcpkg.

### Сборка
```bash
git clone https://github.com/username/Game.git
cd Game
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release   # для Windows укажите пути к SFML, если нужно
cmake --build .
