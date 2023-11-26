#include "Ejercicio01.h"

int Ejercicio01::findMin(int nums[], int n) {
    int left = 0, right = n - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[right]) {
            // El m�nimo est� en la parte derecha
            left = mid + 1;
        }
        else {
            // El m�nimo est� en la parte izquierda o en mid
            right = mid;
        }
    }

    return nums[left]; // o nums[right], ya que left == right
}
