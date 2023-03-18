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
	void draw(Shape *s) {
		cout << "Drawing Circle" << '\n';
	}
};

class DrawingRectangle : public DrawingShape {
public:
	void draw(Shape *s) {
		cout << "Drawing Rectangle" << '\n';
	}
};

class Rectangle : public Shape {
private:
	int x, y, width, height;
public:
	Rectangle(int x, int y, int w, int h, DrawingShape *ds) : Shape(ds) {}

	void draw() {
		cout << "Rectangle" << '\n';
		drawer->draw(this);
	}
};

class Circle : public Shape {
private:
	int x, y, radius;
public:
	Circle(int x, int y, int radius, DrawingShape *ds) : Shape(ds) {}

	void draw() {
		cout << "Circle" << '\n';
		drawer->draw(this);
	}
};

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	DrawingShape *ds[] = { new DrawingRectangle, new DrawingCircle };
	Shape *s[] = {
			new Rectangle(10, 10, 10, 10, ds[0]),
			new Rectangle(20, 20, 20, 20, ds[0]),
			new Circle(30, 30, 30, ds[1]),
	};
	int n = sizeof(s) / sizeof(s[0]);
	for (int i = 0; i < n; ++i) {
		s[i]->draw();
	}
}