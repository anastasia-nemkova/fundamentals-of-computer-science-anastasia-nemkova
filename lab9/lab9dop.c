﻿#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
    return b < a ? b : a;
}
int max(int a, int b) {
    return a < b ? b : a;
}

typedef struct {
    int i;
    int j;
    int l;
} Point;

typedef struct {
    int x;
    int y;
    int r;
} Circle;

Point updatePoint(Point p, int k) {
    Point next;
    next.i = (p.i * p.i * p.i - p.j * p.j * p.j + p.l * p.l * p.l - k) % 20;
    next.j = min(p.i * p.j * p.l - k, min(p.i * p.i * p.l - k, p.j * p.l * p.l - k)) % 30;
    next.l = max(p.i * p.j * p.l - k, max(p.i * p.i * p.l - k, p.j * p.l * p.l - k)) % 30;
    return next;
}

bool isInCircle(Circle c, Point p) {
    int dx = p.i - c.x, dy = p.j - c.y;
    return dx * dx + dy * dy <= c.r * c.r;
}

int main() {
    Point p = { 6, 27, -15 };
    Circle c = { -10, -10, 10 };
    Circle b = { -20, -20, 10 };
    for (int k = 0; k <= 50; ++k) {
        p = updatePoint(p, k);
        if (isInCircle(c, p) && isInCircle(b, p)) {
            printf("The point fell into the specified area at step %d with coordinates (%d, %d) and the motion parameter %d\n", k, p.i, p.j, p.l);
            break;
        }
        else if (k == 50)
            printf("In 50 moves, the dot never got to the area we needed.\nk=%d, i=%d, j=%d, l=%d\n", k, p.i, p.j, p.l);
    }
    return 0;
}