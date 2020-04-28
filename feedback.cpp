#include <iostream>

/* Determine whether a circular array of relative indices
 * is composed of a single complete (all elements in array) cycle.
 */

// 2, -1, -1

bool isCompleteCycle(int arr[]) {
    int N = sizeof(arr[]) / sizeof(arr[0]);
    int pos = 0;
    
    for(int i = 0; i < N; i++) {
        pos += (arr[i] % N);
        if(pos == 0 && i < N-1) {
            return false;
        }
    }
    return true;
}
