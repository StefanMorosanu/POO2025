#include "Canvas.h"
#include <iostream>
#include <cmath>

Canvas::Canvas(int width, int height) : width(width), height(height) {
    matrix = new char*[height];
    for (int i = 0; i < height; ++i) {
        matrix[i] = new char[width];
        for (int j = 0; j < width; ++j)
            matrix[i][j] = ' ';
    }
}

Canvas::~Canvas() {
    for (int i = 0; i < height; ++i)
        delete[] matrix[i];
    delete[] matrix;
}

void Canvas::Clear() {
    for (int i = 0; i < height; ++i)
        for (int j = 0; j < width; ++j)
            matrix[i][j] = ' ';
}

void Canvas::Print() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j)
            std::cout << matrix[i][j];
        std::cout << "\n";
    }
}

void Canvas::SetPoint(int x, int y, char ch) {
    if (x >= 0 && x < width && y >= 0 && y < height)
        matrix[y][x] = ch;
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    for (int i = left; i <= right; ++i) {
        SetPoint(i, top, ch);
        SetPoint(i, bottom, ch);
    }
    for (int i = top; i <= bottom; ++i) {
        SetPoint(left, i, ch);
        SetPoint(right, i, ch);
    }
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
    for (int i = top; i <= bottom; ++i)
        for (int j = left; j <= right; ++j)
            SetPoint(j, i, ch);
}

void Canvas::DrawCircle(int x0, int y0, int ray, char ch) {
    for (int angle = 0; angle < 360; ++angle) {
        int x = x0 + int(ray * cos(angle * M_PI / 180));
        int y = y0 + int(ray * sin(angle * M_PI / 180));
        SetPoint(x, y, ch);
    }
}

void Canvas::FillCircle(int x0, int y0, int ray, char ch) {
    for (int y = y0 - ray; y <= y0 + ray; ++y) {
        for (int x = x0 - ray; x <= x0 + ray; ++x) {
            if ((x - x0)*(x - x0) + (y - y0)*(y - y0) <= ray*ray)
                SetPoint(x, y, ch);
        }
    }
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    // Bresenham's Line Algorithm
    int dx = abs(x2 - x1);
    int dy = -abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx + dy;

    while (true) {
        SetPoint(x1, y1, ch);
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 >= dy) { err += dy; x1 += sx; }
        if (e2 <= dx) { err += dx; y1 += sy; }
    }
}
