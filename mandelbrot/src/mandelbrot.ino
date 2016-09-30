#include <Wire.h>
#include <TinyScreen.h>

TinyScreen display = TinyScreen(TinyScreenPlus);

int xMin = -2, xMax = 1, yMin = -1, yMax = 1;
int width = 96, height = 64;

void compute_mandelbrot(int iterations)
{
    double x, y;
    double xStep, yStep;
    double z, zi, newZ, newZI;
    int colour;
    int i, j, k;
    bool inSet;
    uint8_t buffer[96];

    /* these are used for calculating the points corresponding to the pixels */
    xStep = (xMax - xMin) / (double)width;
    yStep = (yMax - yMin) / (double)height;

    x = xMin;
    y = yMin;
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            z = 0;
            zi = 0;
            inSet = true;
            for (k = 0; k < iterations; k++)
            {
                newZ = (z * z) - (zi * zi) + x;
                newZI = 2 * z * zi + y;
                z = newZ;
                zi = newZI;
                if( ((z * z) + (zi * zi)) > 4 )
                {
                    inSet = false;
                    colour = (2760 + k) % 4096;
                    k = iterations;
                }

            }

            if (inSet)
            {
                buffer[j] = 0x00;
            }
            else
            {
                buffer[j] = colour % 4096;
            }

            x += xStep;
        }

        display.writeBuffer(buffer, 96);

        y += yStep;
        x = xMin;
    }
}

void setup()
{
    display.begin();
}

int count = 1;
void loop()
{
    display.goTo(0, 0);
    display.startData();

    compute_mandelbrot(count++);

    display.endTransfer();

    delay(5000);

    if (count > 250)
    {
        while(1);
    }
}
