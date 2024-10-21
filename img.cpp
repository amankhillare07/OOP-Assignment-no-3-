#include<iostream>
using namespace std;

class Complex {
    int r, img; 

public:
    Complex() {
        r = 0;
        img = 0;
    }
    Complex(int a, int b) {
        r = a;
        img = b;
    }
    void display() const {
        if (img >= 0)
            cout << r << "+" << img << "i";
        else
            cout << r << img << "i";
    }
    Complex operator+(const Complex& c2) {
        Complex temp;
        temp.r = r + c2.r;
        temp.img = img + c2.img;
        return temp;
    }
    friend Complex operator-(const Complex& c1, const Complex& c2) {
        Complex temp;
        temp.r = c1.r - c2.r;
        temp.img = c1.img - c2.img;
        return temp;
    }
    Complex operator*(const Complex& c2) {
        Complex temp;
        temp.r = (r * c2.r) - (img * c2.img);
        temp.img = (r * c2.img) + (img * c2.r);
        return temp;
    }

    Complex operator/(const Complex& c2) {
        Complex temp;
        int denom = (c2.r * c2.r) + (c2.img * c2.img);
        temp.r = ((r * c2.r) + (img * c2.img)) / denom;
        temp.img = ((img * c2.r) - (r * c2.img)) / denom;
        return temp;
    }
};

int main() {
    int rr, im, choice;
    cout << "\nEnter the real and imaginary parts of the first complex number: ";
    cin >> rr >> im;
    Complex c1(rr, im);

    cout << "\nEnter the real and imaginary parts of the second complex number: ";
    cin >> rr >> im;
    Complex c2(rr, im);

    do {
        cout << "\nMenu:\n";
        cout << "1. Add\n";
        cout << "2. Subtract\n";
        cout << "3. Multiply\n";
        cout << "4. Divide\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        Complex result;

        switch (choice) {
        case 1:
            result = c1 + c2;
            cout << "\nAddition result: ";
            result.display();
            break;
        case 2:
            result = c1 - c2;
            cout << "\nSubtraction result: ";
            result.display();
            break;
        case 3:
            result = c1 * c2;
            cout << "\nMultiplication result: ";
            result.display();
            break;
        case 4:
            result = c1 / c2;
            cout << "\nDivision result: ";
            result.display();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
        cout << endl;

    } while (choice != 0);

    return 0;
}