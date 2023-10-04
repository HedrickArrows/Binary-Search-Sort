#include <iostream>
#include <algorithm>
#include <array>
#include <random>
#include <cmath>
#include<numeric>

/*
*    Of silly little ideas that haunt me
*        ~Mihnik
*/

using namespace std;

template<typename T, size_t S>
void BinarySearchSort(array<T, S> input, int start, int length) {

    //cout << "\n";
    //for (auto i : input)
    //    cout << i << " ";
    //cout << "\n";

    int g = 0, steps = 0, swaps = 0, when_done = -1, done_steps = 0;
    
    for (int j = 1; j < length; j *= 2) {
        for (int i = 0; i < length - 1; i++) {

            int lower = i, higher = length - 1;
            while (lower < higher - 1) {
                int mid = lower + (higher - lower) / 2;

                if (input[i] <= input[mid]) {
                    if (input[higher] < input[mid]) {
                        auto temp = input[higher];
                        input[higher] = input[mid];
                        input[mid] = temp;

                        swaps++;
                    }

                    higher = mid;
                }
                else {

                    if (i != mid) {
                        auto temp = input[i];
                        input[i] = input[mid];
                        input[mid] = temp;

                        swaps++;
                    }
                    lower = mid;
                }

                steps++;
            }
        }
        //cout << "\n";
        //for (auto i : input)
        //    cout << i << " ";
        g++;
            if (is_sorted(input.begin(), input.end()) && when_done < 0) {
                when_done = g;
                done_steps = steps;
            }
        //    break;
        
    }

    int gnomeSwaps = 0;

    for(int i = 1; i < length; i++)
        for (int j = i; j > 0 && input[j] < input[j - 1]; j--) {
            auto temp = input[j-1];
            input[j-1] = input[j];
            input[j] = temp;
            gnomeSwaps++;
        }
    //cout << "\n\n";
    //for (auto i : input)
    //    cout << i << " ";


    //text just to check if the result is correct
    if (is_sorted(begin(input), end(input)))
        cout << "\nSorted";
    else {
        std::cout << "\nFAILURE\n";
        //for (auto i : input)
        //    std::cout << i << ' ';
    }

    cout << "\nNumber of first loop iterations: " << g << " (2^" << g << "= " << std::pow(2, g) << ", length: "<< length <<" )" << " Done at " << when_done;

    cout << "\nNumber of swaps: " << swaps;
    cout << "\nNumber of steps: " << steps; // << " (Done at: " << done_steps << " )";
    cout << "\nWas cleanup necessary? ";
    if (gnomeSwaps == 0) cout << "false";
        else cout << "true (" << gnomeSwaps<<" swaps)";
}   //I only suspect this has n log² n complexity, that might be very wrong

/*
template<typename T, size_t S>
void BinarySearchProperSort(array<T, S> input, int start, int length) {

    int g = 0, steps = 0, swaps = 0, when_done = -1, done_steps = -1;

    for (int j = 1; j < length ; j++) {
        for (int i = 0; i < length - 1; i++) {

            int lower = i, higher = length-1;
            while (lower < higher - 1) {
                int mid = lower + (higher - lower) / 2;

                if (input[i] <= input[mid]) {
                    higher = mid;
                }
                else {
                    lower = mid;
                }

                steps++;
            }
            int diff = input[lower] <= input[higher] ? lower : higher;
            if (i != diff && input[diff] < input[i]) {
                auto temp = input[i];
                input[i] = input[diff];
                input[diff] = temp;

                swaps++;
                }
            }
                g++;
                if (is_sorted(input.begin(), input.end()) && when_done < 0) {
                    when_done = g;
                    done_steps = steps;
                }
        //    break; 
        
    }

    //text just to check if the result is correct
    if (is_sorted(begin(input), end(input)))
        std::cout << "\nSorted";
    else { std::cout << "\nFAILURE";
    //for (auto i : input)
    //    std::cout << i << ' ';
    }
            std::cout << "\nNumber of  first loop iterations: " << g <<" (Length: "<<length<<" )" << " Done at " << when_done;

    std::cout << "\nNumber of swaps: " << swaps;
    std::cout << "\nNumber of steps: " << steps << " (Done at: " << done_steps << " )";
}   //Probably what would have the complexity of n^2 log n
*/
/*
template<typename T, size_t S>
void BinarySearchCombinedSort(array<T, S> input, int start, int length) {

    int g = 0, steps = 0, swaps = 0, when_done = -1, done_steps = -1;

    for (int j = 1; j < length * 4; j *= 2) {
        for (int i = 0; i < length - 1; i++) {

            int lower = i, higher = length-1;
            while (lower < higher - 1) {
                int mid = lower + (higher - lower) / 2;

                if (input[i] <= input[mid]) {
                    higher = mid;
                }
                else {
                    if (i != lower) {
                        auto temp = input[i];
                        input[i] = input[lower];
                        input[lower] = temp;

                        swaps++;
                    }
                    lower = mid;
                }

                steps++;
            }            
            int diff = input[lower] <= input[higher] ? lower : higher;
            if (i != diff && input[diff] < input[i]) {
                auto temp = input[i];
                input[i] = input[diff];
                input[diff] = temp;

                swaps++;
            }
        }
        g++;
        if (is_sorted(input.begin(), input.end()) && when_done < 0) {
            when_done = g;
            done_steps = steps;
        }
        //    break; 

    }

    //text just to check if the result is correct
    if (is_sorted(begin(input), end(input)))
        cout << "\nSorted";
    else {
        cout << "\nFAILURE ";
        //for (auto i : input)
        //    std::cout << i << ' ';
    }
    cout << "\nNumber of  first loop iterations: " << g << " Done at " << when_done;

    cout << "\nNumber of swaps: " << swaps;
    cout << "\nNumber of steps: " << steps << " (Done at: " << done_steps << " )";
}   //Probably what would have the complexity of n^2 log n
*/
/*
template<typename T, size_t S>
void BinarySearchLazySort(array<T, S> input, int start, int length) {

    int g = 0, steps = 0, swaps = 0, when_done = -1, done_steps = -1;

    for (int j = 1; j < length ; j++) {
        for (int i = 0; i < length - 1; i++) {

            if (i > 1 && i < length - 2 && input[i - 1] <= input[i] && input[i] <= input[i + 1]) continue;

            int lower = i, higher = length-1;
            while (lower < higher - 1) {
                int mid = lower + (higher - lower) / 2;

                if (input[i] <= input[mid]) {
                    higher = mid;
                }
                else {
                    if (i != lower) {
                        auto temp = input[i];
                        input[i] = input[lower];
                        input[lower] = temp;

                        swaps++;
                    }
                    lower = mid;
                }

                steps++;
            }
            int diff = input[lower] <= input[higher] ? lower : higher;
            if (i != diff && input[diff] < input[i]) {
                auto temp = input[i];
                input[i] = input[diff];
                input[diff] = temp;

                swaps++;
            }
        }
        g++;
        if (is_sorted(input.begin(), input.end()) && when_done < 0) {
            when_done = g;
            done_steps = steps;
        }
        //    break; 

    }

    //text just to check if the result is correct
    if (is_sorted(begin(input), end(input)))
        std::cout << "\nSorted";
    else {
        std::cout << "\nFAILURE ";
        //for (auto i : input)
        //    std::cout << i << ' ';
    }
    std::cout << "\nNumber of  first loop iterations: " << g << " Done at " << when_done;

    std::cout << "\nNumber of swaps: " << swaps;
    std::cout << "\nNumber of steps: " << steps << " (Done at: " << done_steps << " )";
}   //Probably what would have the complexity of n^2 log n
*/
/*
template<typename T, size_t S>
void BinarySearchBubbleSort(array<T, S> input, int start, int length) {

    int g = 0, steps = 0, swaps = 0, when_done = -1, done_steps = 0;

    for (int j = 1; j < length * 4; j *= 2) {
        for (int i = 0; i < length - 1; i++) {

            int lower = i, higher = length - 1;
            while (lower < higher - 1) {
                int mid = lower + (higher - lower) / 2;

                if (input[higher] < input[mid]) {
                    auto temp = input[higher];
                    input[higher] = input[mid];
                    input[mid] = temp;

                    swaps++;

                }

                if (input[mid] < input[lower]) {

                        auto temp = input[lower];
                        input[lower] = input[mid];
                        input[mid] = temp;

                        swaps++;
                    
                }
                    lower = mid;

                steps++;
            }
        }
        g++;
        if (is_sorted(input.begin(), input.end()) && when_done < 0) {
            when_done = g;
            done_steps = steps;
        }
        //    break;

    }


    //text just to check if the result is correct
    if (is_sorted(begin(input), end(input)))
        std::cout << "\nSorted";
    else {
        std::cout << "\nFAILURE\n";
        //for (auto i : input)
        //    std::cout << i << ' ';
    }
    std::cout << "\nNumber of first loop iterations: " << g << " (2^" << g << "= " << std::pow(2, g) << " )" << " Done at " << when_done;

    std::cout << "\nNumber of swaps: " << swaps;
    std::cout << "\nNumber of steps: " << steps << " (Done at: " << done_steps << " )";
}   //I only suspect this has n log² n complexity, that might be very wrong
*/

template<typename T, size_t S>
void BinarySSort(array<T, S> input, int start, int length) {

    //cout << "\n";
    //for (auto i : input)
    //    cout << i << " ";
    //cout << "\n";

    int g = 0, steps = 0, swaps = 0, when_done = -1, g2 = 0, done_steps = 0, when_done2 = -1, steps2 = 0, done_steps2 = 0;

    for (int j = 1; j < length; j *= 2) {
        for (int i = 0; i < length - 1; i++) {

            int lower = i, higher = length - 1;
            while (lower < higher - 1) {
                int mid = lower + (higher - lower) / 2;

                if (input[i] <= input[mid]) {
                    if (input[higher] < input[mid]) {
                        auto temp = input[higher];
                        input[higher] = input[mid];
                        input[mid] = temp;

                        swaps++;
                    }

                    higher = mid;
                }
                else {

                    if (i != mid) {
                        auto temp = input[i];
                        input[i] = input[mid];
                        input[mid] = temp;

                        swaps++;
                    }
                    lower = mid;
                }

                steps2++;
            }
        }
        //cout << "\n";
        //for (auto i : input)
        //    cout << i << " ";
        g2++;
        if (is_sorted(input.begin(), input.end()) && when_done2 < 0) {
            when_done2 = g2;
            done_steps2 = steps2;
            break;
        }
        //    break;

    }

    if(when_done2 < 0){
    //for (int j = 1; j < length; j *= 2) {
        for (int i = 0; i < length - 1; i++) {

            int lower = i, higher = length - 1;
            while (lower < higher - 1) {
                int mid = lower + (higher - lower) / 2;

                if (input[mid] < input[lower]) {
                    auto temp = input[lower];
                    input[lower] = input[mid];
                    input[mid] = temp;

                    swaps++;
                }
                if (input[higher] < input[mid]) {
                    auto temp = input[higher];
                    input[higher] = input[mid];
                    input[mid] = temp;

                    swaps++;
                }
                if (input[mid] < input[lower]) {
                    auto temp = input[lower];
                    input[lower] = input[mid];
                    input[mid] = temp;

                    swaps++;
                }
                higher = mid;

                steps++;
            }
        }
        //cout << "\n";
        //for (auto i : input)
        //    cout << i << " ";
        g++;
        if (is_sorted(input.begin(), input.end()) && when_done < 0) {
            when_done = g;
            done_steps = steps;
        //    break;
        }
        //    break;

    }
    //cout << "\n\n";
    //for (auto i : input)
    //    cout << i << " ";


    //text just to check if the result is correct
    if (is_sorted(begin(input), end(input)))
        cout << "\nSorted";
    else {
        std::cout << "\nFAILURE\n";
        //for (auto i : input)
        //    std::cout << i << ' ';
    }

    cout << "\nNumber of first loop iterations: " << g2 << " (2^" << g2 << "= " << std::pow(2, g2) << ", length: " << length << " )" << " Done at " << (when_done2<0 ? g2 : when_done2) << " + " << (when_done < 0 ? 0 : when_done) ;

    cout << "\nNumber of swaps: " << swaps;
    cout << "\nNumber of steps: " << steps2 << " " << steps; // << " (Done at: " << done_steps << " )";
    //cout << "\nWas cleanup necessary? ";
    //if (gnomeSwaps == 0) cout << "false";
    //else cout << "true (" << gnomeSwaps << " swaps)";
}   //I only suspect this has n log² n complexity, that might be very wrong



template<typename T, size_t S>
void BinarySearchSingleSort(array<T, S> input, int start, int length) {

    //cout << "\n";
    //for (auto i : input)
    //    cout << i << " ";
    //cout << "\n";

    int g = 0, steps = 0, swaps = 0, when_done = -1, done_steps = 0;

    for (int j = 1; j < length; j *= 2) {
        for (int i = 0; i < length - 1; i++) {

            int lower = i, higher = length - 1;
            while (lower < higher - 1) {
                int mid = lower + (higher - lower) / 2;

                if (input[mid] < input[lower]) {
                    auto temp = input[lower];
                    input[lower] = input[mid];
                    input[mid] = temp;

                    swaps++;
                }
                if (input[higher] < input[mid]) {
                    auto temp = input[higher];
                    input[higher] = input[mid];
                    input[mid] = temp;

                    swaps++;
                }
                if (input[mid] < input[lower]) {
                    auto temp = input[lower];
                    input[lower] = input[mid];
                    input[mid] = temp;

                    swaps++;
                }

                if (input[i] <= input[mid]) {
                    if (input[higher] < input[mid]) {
                        auto temp = input[higher];
                        input[higher] = input[mid];
                        input[mid] = temp;

                        swaps++;
                    }

                    higher = mid;
                }
                else {

                    if (i != mid) {
                        auto temp = input[i];
                        input[i] = input[mid];
                        input[mid] = temp;

                        swaps++;
                    }
                    lower = mid;
                }

                steps++;
            }
        }
        //cout << "\n";
        //for (auto i : input)
        //    cout << i << " ";
        g++;
        if (is_sorted(input.begin(), input.end()) && when_done < 0) {
            when_done = g;
            done_steps = steps;
        }
        //    break;

    }

    int gnomeSwaps = 0;

    for (int i = 1; i < length; i++)
        for (int j = i; j > 0 && input[j] < input[j - 1]; j--) {
            auto temp = input[j - 1];
            input[j - 1] = input[j];
            input[j] = temp;
            gnomeSwaps++;
        }
    //cout << "\n\n";
    //for (auto i : input)
    //    cout << i << " ";


    //text just to check if the result is correct
    if (is_sorted(begin(input), end(input)))
        cout << "\nSorted";
    else {
        std::cout << "\nFAILURE\n";
        //for (auto i : input)
        //    std::cout << i << ' ';
    }

    cout << "\nNumber of first loop iterations: " << g << " (2^" << g << "= " << std::pow(2, g) << ", length: " << length << " )" << " Done at " << when_done;

    cout << "\nNumber of swaps: " << swaps;
    cout << "\nNumber of steps: " << steps; // << " (Done at: " << done_steps << " )";
    cout << "\nWas cleanup necessary? ";
    if (gnomeSwaps == 0) cout << "false";
    else cout << "true (" << gnomeSwaps << " swaps)";
}   //I only suspect this has n log² n complexity, that might be very wrong


int main(){
    int const length = 87, start = 0;
    array<int, length> test;
    std::iota(test.begin(), test.end(), 1);

    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(begin(test), end(test), g);
    //std::cout << "Unsorted: ";
    //for (auto i : test)
    //    std::cout << i << ' ';
    //std::cout << endl;

    auto r = log2(length);
    std::cout << "Suspected growth n log^2 n: " << std::round(length * r * r) << " steps\n" <<//"\nHello World!\n";
                 "Suspected growth n^2 log n: " << std::round(length * length * r) << " steps";//"\nHello World!\n";

    std::cout << "\n\nSwap value at i with lowest found or mid value with highest current";
    BinarySearchSort(test, start, length);

    //std::cout << "\n\nSwap at the end of binary search";
    //BinarySearchProperSort(test, start, length);
    //
    //std::cout << "\n\nSwap at in both cases";
    //BinarySearchCombinedSort(test, start, length);
    //
    //std::cout << "\n\nSearch if elements locally are not sorted";
    //BinarySearchLazySort(test, start, length);
    //
    //std::cout << "\n\nI am at this point testing stuff out";
    //BinarySearchLazySort(test, start, length);
    
    std::cout << "\n\nFirst Method + Second Loop Aggregating Lower, Mid, And Higher values";
    BinarySSort(test, start, length);

    std::cout << "\n\nBoth Approaches In One Loop";
    BinarySearchSingleSort(test, start, length);


    std::cout << "\n\n";
}