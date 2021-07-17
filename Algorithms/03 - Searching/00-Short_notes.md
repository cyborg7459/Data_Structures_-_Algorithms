## Sorting Algorithms
- Linear search - Checks all elements one by one -> O(n)
- Binary search - In sorted array, checks middle element -> O(log n);
- Jump search - Make jumps of sqrt(n) while searching, then linear search in appropriate interval -> O(sqrt(n))
- Interpolation search - More efficient than binary search in case of uniformly distributed array. Jump is made according to the distance of point from low and high
- Exponential search - Check 1st, 2nd, 4th, 8th ,16th.... element until you find an element greater than the required number. Then binary search on the last range -> O(log n)
- Ternary search - Instead of 2, divide array into 3 parts. Seems more efficient than binary but is not (more comparisons in worst case for ternary)
