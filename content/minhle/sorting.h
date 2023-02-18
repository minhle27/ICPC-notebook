/**
 * Author: Simon Lindholm
 * Date: 2018-07-15
 * License: CC0
 * Source: Wikipedia
 * Description: Sorting Using Library
 * Time: 
 * Status: 
 */

int arr2[] = {5, 1, 3, 2, 4};
sort(arr2 + 1, arr2 + 4); // 5 1 2 3 4

// By default, C++ pairs are sorted by first element and then second element in case of a tie. Tuples are sorted similarly.
vector<pair<int, int>> v{{1, 5}, {2, 3}, {1, 2}};
sort(v.begin(), v.end());

// technique 1, create a custom comparison function
bool cmp(const int a, const int b) {
    return a > b; // non-decreasing order
}

sort(A.begin(), A.end(), cmp);

// technique 2, use an anonymous function (lambda expression)
sort(A.begin(), A.end(), [](const int a, const int b) {
    return a > b;
});

// technique 3, use reverse iterator
sort(A.rbegin(), A.rend());

// technique 4, add minus sign