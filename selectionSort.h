#include <unistd.h>
#include <SFML/Graphics.hpp>

using namespace sf;

const float WINDOW_WIDTH = 800;
const float WINDOW_HEIGHT = 600;
const int SIZE = 100;

void makeRects(int (&arr)[SIZE], RectangleShape (&shapes)[SIZE], int min, int i);
void swap(int &x, int&y);
int selectionSort();
