#include <bits/stdc++.h>

using namespace std;

class DrawingShape;

class Shape {
protected:
    DrawingShape *drawer;
public:
    Shape(DrawingShape *ds) {
        drawer = ds;
    }

    virtual void draw() = 0;
};

class DrawingShape {
public:
    virtual void draw(Shape *s) = 0;
};

class DrawingCircle : public DrawingShape {
public:
    void draw(Shape *s);
};

class DrawingRectangle : public DrawingShape {
public:
    void draw(Shape *s);
};

class Rectangle : public Shape {
private:
    int x, y, width, height;
public:
    Rectangle(int x, int y, int w, int h, DrawingShape *ds) : Shape(ds) { }

    void draw();
};

class Circle : public Shape {
private:
    int x, y, radius;
public:
    Circle(int x, int y, int radius, DrawingShape *ds) : Shape(ds) { }

    void draw();
};

void Rectangle::draw() {
    cout << "Rectangle" << '\n';
    drawer->draw(this);
}

void Circle::draw() {
    cout << "Circle" << '\n';
    drawer->draw(this);
}

void DrawingCircle::draw(Shape *s) {
    cout << "Drawing Circle" << '\n';
}

void DrawingRectangle::draw(Shape *s) {
    cout << "Drawing Rectangle" << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // a không thể tạo được các đối tượng từ shape và drawingshape vì các lớp này là lớp thuần ảo chỉ có thể kế thừa và dẫn xuất
    // b đã cài đăt trong đề 
    // c dùng vector hoặc mảng 1 chiều để thực hiên => 2 cách tương tự nhau

    // d Do tính chất kế thừa nên các phần tử của mảng s (có kiểu con trỏ Shape) 
    // có thể trỏ đến các đối tượng thuộc lớp con của nó(Rectangle và Circle).
    // Do cơ chế đa xạ (polymorphism) nên trong vòng lặp gọi hàm draw, 
    // các đối tượng Rectangle và Circle sẽ biết tự gọi hàm tương ứng của lớp của mình.


    DrawingShape *ds[] = { new DrawingRectangle, new DrawingCircle, };

    Shape *s[] = {
        new Rectangle(10, 10, 10, 10, ds[0]),
        new Rectangle(20, 20, 20, 20, ds[0]),
        new Circle(30, 30, 30, ds[1]),
    };

    int n = sizeof(s) / sizeof(s[0]);
    for (int i = 0; i < n; ++i) {
        s[i]->draw();
    }

    // vector<Shape *> s = {
    //         new Rectangle(10, 10, 10, 10, ds[0]),
    //         new Rectangle(20, 20, 20, 20, ds[0]),
    //         new Circle(30, 30, 30, ds[1]),
    // };
    // for (int i = 0; i < s.size(); ++i) {
    //     s[i]->draw();
    // }

}