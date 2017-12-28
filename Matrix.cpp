#include "Matrix.h"

using std::cout;

Matrix::Matrix() {

    // The initial seed value of the object
    srand(static_cast<unsigned int>(getpid()) ^ static_cast<unsigned int>(clock()) ^ static_cast<unsigned int>(time(NULL)));

    // Default constructor (no arguments)
    setDefault(true);

    // Default state for 'matrix lines'
    setErase(false);

    // 80 wide, 25 tall
    setPosition((rand() % 80 + 0), (rand() % 22 + 0));

    // Based on position Y
    setLength((rand() % (getPosition().Y + 1) + 0));

    // Speed of each letter being displayed
    setSpeed((rand() % 50 + 50), (rand() % 100 + 100), (rand() % 150 + 150));

    // Time between each iteration of a new color
    loopWhite_ = GetTickCount();
    loopLgreen_ = GetTickCount();
    loopDgreen_ = GetTickCount();
    lenCnt_ = 0;
};

Matrix::Matrix(const SMALL_RECT box) {

    // The initial seed value of the object
    srand(static_cast<unsigned int>(getpid()) ^ static_cast<unsigned int>(clock()) ^ static_cast<unsigned int>(time(NULL)));

    // Copy the argument to class member attribute
    setMatrixBox(box);

    // Default constructor (no arguments)
    setDefault(false);

    // Default state for 'matrix lines'
    setErase(false);

    // 80 wide, 25 tall
    setPosition((rand() % getMatrixBox().Right + getMatrixBox().Left), (rand() % getMatrixBox().Bottom + getMatrixBox().Top));

    // Based on position Y
    setLength((rand() % (getPosition().Y + 1) + 0));

    // Speed of each letter being displayed
    setSpeed((rand() % 50 + 50), (rand() % 100 + 100), (rand() % 150 + 150));

    // Time between each iteration of a new color
    loopWhite_ = GetTickCount();
    loopLgreen_ = GetTickCount();
    loopDgreen_ = GetTickCount();
    lenCnt_ = 0;
};

Matrix::Matrix(const unsigned __int8 left, const unsigned __int8 top,
               const unsigned __int8 bottom, const unsigned __int8 right) {

    // The initial seed value of the object
    srand(static_cast<unsigned int>(getpid()) ^ static_cast<unsigned int>(clock()) ^ static_cast<unsigned int>(time(NULL)));

    // Copy the argument to class member attribute
    setMatrixBox(top, bottom, left, right);

    // Default constructor (no arguments)
    setDefault(false);

    // Default state for 'matrix lines'
    setErase(false);

    // 80 wide, 25 tall
    setPosition((rand() % getMatrixBox().Right + getMatrixBox().Left), (rand() % getMatrixBox().Bottom + getMatrixBox().Top));

    // Based on position Y
    setLength((rand() % (getPosition().Y + 1) + 0));

    // Speed of each letter being displayed
    setSpeed((rand() % 50 + 50), (rand() % 100 + 100), (rand() % 150 + 150));

    // Time between each iteration of a new color
    loopWhite_ = GetTickCount();
    loopLgreen_ = GetTickCount();
    loopDgreen_ = GetTickCount();
    lenCnt_ = 0;
};

void Matrix::randLength() {
    setLength((rand() % (getPosition().Y + 1) + 5));
}

void Matrix::randSpeed() {
    setSpeed((rand() % 50 + 50), (rand() % 100 + 100), (rand() % 150 + 150));
    //setSpeed(0);
}

void Matrix::randPos() {
    if (getDefault()) {
        setPosition((rand() % 80 + 0), (rand() % 22 + 0));
    } else {
        setPosition((rand() % getMatrixBox().Right + getMatrixBox().Left),
                    (rand() % getMatrixBox().Bottom + getMatrixBox().Top));
    }
}

void Matrix::display() {

    unsigned int whiteDelay = getSpeed(0);
    unsigned int greenDelay = getSpeed(1);
    unsigned int darkGreenDelay = getSpeed(2);

    if (GetTickCount() >= (loopWhite_ + whiteDelay)) {
        loopWhite_ = GetTickCount();

        PlaceCursor(getPosition().X, getPosition().Y);
        if (!getErase()) { SetColor(WHITE); }
        else { SetColor(BLACK); }
        cout << (char)(rand() % 121 + 34);

        if (GetTickCount() >= (loopLgreen_ + greenDelay)) {
            loopLgreen_ = GetTickCount();

            PlaceCursor(getPosition().X, getPosition().Y);
            if (!getErase()) { SetColor(GREEN); }
            else { SetColor(BLACK); }
            cout << (char)(rand() % 121 + 34);

            if (GetTickCount() >= (loopDgreen_ + darkGreenDelay)) {
                loopDgreen_ = GetTickCount();

                PlaceCursor(getPosition().X, getPosition().Y);
                if (rand() % 2) {
                    if (!getErase()) { SetColor(DARK_GREEN); }
                    else { SetColor(BLACK); }
                }
                cout << (char)(rand() % 121 + 34);

                // Move the cursor down by one
                setPosition(getPosition().X, (getPosition().Y + 1));

                if (lenCnt_ >= getLength()) {
                    randPos();
                    randSpeed();
                    randLength();

                    lenCnt_ = 0; // reset counter
                } else { lenCnt_++; }
            }
        }
    }

    return;
}

void Matrix::setDefault(const bool setting) {
    isDefault_ = setting;
}

bool Matrix::getDefault() {
    return isDefault_;
}

void Matrix::setErase(const bool setting) {
    erase_ = setting;
}

bool Matrix::getErase() {
    return erase_;
}

void Matrix::setSpeed(const unsigned __int16 white, const unsigned __int16 light_green, const unsigned __int16 dark_green) {
    speed_[0] = white;
    speed_[1] = light_green;
    speed_[2] = dark_green;
}

unsigned __int16 Matrix::getSpeed(const unsigned __int8 color) {
    return speed_[color];
}

void Matrix::setLength(const unsigned __int8 length) {
    length_ = length;
}

unsigned __int8 Matrix::getLength() {
    return length_;
}

void Matrix::setPosition(const COORD position) {
    position_.X = position.X;
    position_.Y = position.Y;
}

void Matrix::setPosition(const unsigned __int8 X, const unsigned __int8 Y) {
    position_.X = X;
    position_.Y = Y;
}

COORD Matrix::getPosition() {
    return position_;
}

void Matrix::setMatrixBox(const SMALL_RECT matrixBox) {
    matrixBox_.Top = matrixBox.Top;
    matrixBox_.Bottom = matrixBox.Bottom;
    matrixBox_.Left = matrixBox.Left;
    matrixBox_.Right = matrixBox.Right;
}

void Matrix::setMatrixBox(const unsigned __int8 top, const unsigned __int8 bottom,
                          const unsigned __int8 left, const unsigned __int8 right) {
    matrixBox_.Top = top;
    matrixBox_.Bottom = bottom;
    matrixBox_.Left = left;
    matrixBox_.Right = right;
}

SMALL_RECT Matrix::getMatrixBox() {
    return matrixBox_;
}
