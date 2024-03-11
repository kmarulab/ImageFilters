#pragma once

#include <string>
#include <iostream>


/**
 * A function to determine the location of a pixel in a PPM image array.
 * Writing this routine makes it easier to write your other image
 * transformation functions.
 * @param width The width of the PPM image.
 * @param x The X coordinate of the pixel.
 * @param y The Y coordinate of the pixel.
 * @return The index of the first integer in the specified pixel.
 * For example:
 *         if x==1 and y==0, this function returns 3.
 */
int pixelToIndex(int width, int x, int y);

/**
 * A function which removes the red from an image.
 * @param width The width of the image to transform.
 * @param height The height of the image to transform.
 * @param ppm The PPM image to transform.
 */
void noRed(int width, int height, int* ppm);

/**
 * A function which removes the green from an image.
 * @param width The width of the image to transform.
 * @param height The height of the image to transform.
 * @param ppm The PPM image to transform.
 */
void noGreen(int width, int height, int* ppm);

/**
 * A function which removes the blue from an image.
 * @param width The width of the image to transform.
 * @param height The height of the image to transform.
 * @param ppm The PPM image to transform.
 */
void noBlue(int width, int height, int* ppm);

/**
 * A function which inverts the colors of the image.
 * @param width The width of the image to transform.
 * @param height The height of the image to transform.
 * @param ppm The PPM image to transform.
 */
void invert(int width, int height, int* ppm);

/**
 * A function which turns the image into grayscale.
 * @param width The width of the image to transform.
 * @param height The height of the image to transform.
 * @param ppm The PPM image to transform.
 */
void grayscale(int width, int height, int* ppm);

/**
 * A function which flips the image horizontally.
 * @param width The width of the image to transform.
 * @param height The height of the image to transform.
 * @param ppm The PPM image to transform.
 */

void flipHorizontally(int width, int height, int* ppm);

/**
 * A function which flips the image vertically.
 * @param width The width of the image to transform.
 * @param height The height of the image to transform.
 * @param ppm The PPM image to transform.
 */
void flipVertically(int width, int height, int* ppm);
