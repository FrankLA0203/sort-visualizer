#include "selectionSort.h"

int selectionSort() {
    RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!");

    int arr[SIZE];
    RectangleShape shapes[SIZE];
    bool sorted = false;

    srand(static_cast<int>(time(0)));
    for (size_t i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100 + 1;
    }
    makeRects(arr, shapes, 0, 0);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }
        if (sorted == false) {
            for (size_t i = 0; i < SIZE; i++) {
                while (window.pollEvent(event)) {
                    if (event.type == Event::Closed) {
                        window.close();
                        return 0;
                    }
                }
                int min = i;
                for (size_t j = i + 1; j < SIZE; j++) {
                    if (arr[j] < arr[min]) min = j;
                }
                makeRects(arr, shapes, min, i);
                swap(arr[min], arr[i]);
                window.clear();
                for (RectangleShape shape : shapes) {
                    window.draw(shape);
                }
                usleep(100000);
                window.display();
            }
            sorted = true;
        }
    }

    return 0;
}

void makeRects(int (&arr)[SIZE], RectangleShape (&shapes)[SIZE], int min, int i) {
    for (size_t j = 0; j < SIZE; j++) {
        shapes[j].setSize(Vector2f(WINDOW_WIDTH / SIZE, arr[j] * 5));
        shapes[j].setPosition(j * (WINDOW_WIDTH / SIZE), WINDOW_HEIGHT - arr[j] * 5);
        if (j == min || j <= i) {
            shapes[j].setFillColor(Color::Red);
        }
        else {
            shapes[j].setFillColor(Color::White);
        }
    }
}

void swap(int &x, int &y) {
    if (x != y) {
        x ^= y;
        y ^= x;
        x ^= y;
    }
}
