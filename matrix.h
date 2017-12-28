#pragma once

#include <time.h>
#include <process.h>
#include <iostream>

#include "TextControl.h"

class Matrix {
    private:
        bool isDefault_; // Flag to signal using default "0 to 80" width, and "0 to 25" height
        bool erase_; // Flag to signal erasing of text (black matrix lines)

        // Timers for each color (no alternative)
        unsigned __int32 loopWhite_;
        unsigned __int32 loopLgreen_;
        unsigned __int32 loopDgreen_;

        unsigned __int16 speed_[3]; // Delay between printing a new line
        unsigned __int8 length_; // Max. length before it quits
        unsigned __int8 lenCnt_; // Counter for length

        COORD position_; // Position on the console

        SMALL_RECT matrixBox_; // Box for the "Matrix" to be in

    public:
        Matrix::Matrix();
        Matrix::Matrix(const SMALL_RECT);
        Matrix::Matrix(const unsigned __int8, const unsigned __int8, const unsigned __int8, const unsigned __int8);

        void display();

        void setErase(const bool);
        bool getErase();

        void setSpeed(const unsigned __int16, const unsigned __int16, const unsigned __int16);
        unsigned __int16 getSpeed(const unsigned __int8);

    private:
        void randLength();
        void randSpeed();
        void randPos();

        void setDefault(const bool);
        bool getDefault();

        void setLength(const unsigned __int8);
        unsigned __int8 getLength();

        void setPosition(const COORD);
        void setPosition(const unsigned __int8, const unsigned __int8);
        COORD getPosition();

        void setMatrixBox(const SMALL_RECT);
        void setMatrixBox(const unsigned __int8, const unsigned __int8, const unsigned __int8, const unsigned __int8);
        SMALL_RECT getMatrixBox();
};
