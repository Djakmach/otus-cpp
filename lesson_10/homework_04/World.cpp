#include "World.h"
#include "Painter.h"
#include <fstream>
#include <string>
#include <iostream>

// Длительность одного тика симуляции.
// Подробнее см. update()
// Изменять не следует
static constexpr double timePerTick = 0.001;

/**
 * Конструирует объект мира для симуляции
 * @param worldFilePath путь к файлу модели мира
 */

std::istream& operator>>(std::istream& stream, Point& point) {
    stream >> point.x >> point.y;
    return stream;
}

std::istream& operator>>(std::istream& stream, Color& color) {
    double red;
    double green;
    double blue;
    stream >> red >> green >> blue;
    color = Color{red, green, blue};
    return stream;
}

std::istream& operator>>(std::istream& stream, Velocity& velocity) {
    Point velocity_vector;
    stream >> velocity_vector;
    velocity = Velocity{velocity_vector};
    return stream;
}

World::World(const std::string& worldFilePath) {

    std::ifstream stream(worldFilePath);

    stream >> topLeft >> bottomRight;
    physics.setWorldBox(topLeft, bottomRight);

    double radius;
    Point center;
    Velocity velocity;
    Color color;
    bool isCollidable;

    // Здесь не хватает обработки ошибок, но на текущем
    // уровне прохождения курса нас это устраивает
    while (stream.peek(), stream.good()) {
        // Читаем координаты центра шара (x, y) и вектор
        // его скорости (vx, vy)
        stream >> center >> velocity;
        // Читаем три составляющие цвета шара
        stream >> color;
        // Читаем радиус шара
        stream >> radius;
        // Читаем свойство шара isCollidable, которое
        // указывает, требуется ли обрабатывать пересечение
        // шаров как столкновение. Если true - требуется.
        // В базовой части задания этот параметр
        stream >> std::boolalpha >> isCollidable;

        Ball ball(center, velocity, color, radius, isCollidable);
        // После того как мы каким-то образом
        // сконструируем объект Ball ball;
        // добавьте его в конец контейнера вызовом
        balls.push_back(ball);
    }
}

/// @brief Отображает состояние мира
void World::show(Painter& painter) const {
    // Рисуем белый прямоугольник, отображающий границу
    // мира
    painter.draw(topLeft, bottomRight, Color(1, 1, 1));

    // Вызываем отрисовку каждого шара
    for (const Ball& ball : balls) {
        ball.draw(painter);
    }
}

/// @brief Обновляет состояние мира
void World::update(double time) {
    /**
     * В реальном мире время течет непрерывно. Однако
     * компьютеры дискретны по своей природе. Поэтому
     * симуляцию взаимодействия шаров выполняем дискретными
     * "тиками". Т.е. если с момента прошлой симуляции
     * прошло time секунд, time / timePerTick раз обновляем
     * состояние мира. Каждое такое обновление - тик -
     * в physics.update() перемещаем шары и обрабатываем
     * коллизии - ситуации, когда в результате перемещения
     * один шар пересекается с другим или с границей мира.
     * В общем случае время не делится нацело на
     * длительность тика, сохраняем остаток в restTime
     * и обрабатываем на следующей итерации.
     */

    // учитываем остаток времени, который мы не "доработали" при прошлом update
    time += restTime;
    const auto ticks = static_cast<size_t>(std::floor(time / timePerTick));
    restTime = time - double(ticks) * timePerTick;

    physics.update(balls, ticks);
}