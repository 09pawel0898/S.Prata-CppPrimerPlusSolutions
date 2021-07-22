#include "ex16_9.h"

#include <list>

void ex9(void)
{

    std::srand((unsigned)time(NULL));

    std::vector<int> vi0;
    std::vector<int> vi;
    std::list<int> li;

    clock_t start, end;

    // adding random values to vi0
    for (int i = 0; i < 900000; i++)
    {
        vi0.push_back(((rand() % 200) + 1)*211*15);
    }
    
    //copyting vi0 values to vi and li

    for (size_t i = 0; i < vi0.size(); i++)
    {
        vi.push_back(vi0[i]);
        li.push_back(vi0[i]);
    }

    start = clock();
    std::sort(vi.begin(), vi.end());
    end = clock();
    std::cout << "Duration time of sorting vi with STL sort algorithm : "<<(double)(end - start) / CLOCKS_PER_SEC << "\n";

    start = clock();
    li.sort();
    end = clock();
    std::cout << "Duration time of sorting li with an sort() method : " << (double)(end - start) / CLOCKS_PER_SEC << "\n";

    // restore the sequence in li
    std::copy(vi0.begin(), vi0.end(), li.begin());

    start = clock();
    std::copy(li.begin(), li.end(), vi.begin());
    std::sort(vi.begin(), vi.end());
    std::copy(vi.begin(), vi.end(), li.begin());
    end = clock();
    std::cout << "Duration time of copying li to vi, sorting vi, and copying back vi to li : " << (double)(end - start) / CLOCKS_PER_SEC << "\n";

    /*
    *   Case 1 (200000 elements)
    *
    *   Time of sorting vi : 0.276
    *   Time of sorting li with class method sort() : 0.371
    *   Time of copying li to vi, sorting vi, and copying back vi to li : 0.434
    *
    *   So for this case of relatively small size of list its not more efficient.
    * 
    *   Case 2 (900000 elements)
    *
    *   Time of sorting vi : 1.313
    *   Time of sorting li with class method sort() : 2.032
    *   Time of copying li to vi, sorting vi, and copying back vi to li : 1.645
    *
    *   We can see that for larger data sets the method of copying to vector, sorting, and copying back is more efficient. Thus, we shouldn't use list with large data when
    *   there might be a need for sorting it.
    */

}