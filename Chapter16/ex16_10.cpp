#include "ex16_10.h"


void ex10(void)
{

    std::vector<std::shared_ptr<Review>> books;
    Review temp;
    while (FillReview(temp))
        books.push_back(std::shared_ptr<Review>(new Review(temp)));

    if (books.size() > 0)
    {
        cout << "Thank you. You gave"
            << books.size() << " book ratings:\n"
            << "Rating\tBook\n";
        std::for_each(books.begin(), books.end(), ShowReview);

        std::sort(books.begin(), books.end());
        cout << "Sorted by title:\nRating\tBook\n";
        std::for_each(books.begin(), books.end(), ShowReview);

        std::sort(books.begin(), books.end(), worseThan);
        cout << "Sorted by rate:\nRating\tBook\n";
        std::for_each(books.begin(), books.end(), ShowReview);

        std::random_shuffle(books.begin(), books.end());
        cout << "After mixning:\nRating\tBook\n";
        std::for_each(books.begin(), books.end(), ShowReview);
    }
    else
        cout << "No data. ";
    cout << "Finished.\n";
}


static bool operator<(const std::shared_ptr<Review>& r1, const std::shared_ptr<Review>& r2)
{
    if (r1->title < r2->title)
        return true;
    else if (r1->title == r2->title && r1->rating < r2->rating)
        return true;
    else
        return false;
}

static bool worseThan(const std::shared_ptr<Review>& r1, const std::shared_ptr<Review>& r2)
{
    if (r1->rating < r2->rating)
        return true;
    else
        return false;
}

static bool FillReview(Review& rr)
{
    std::cout << "Enter book title (\"end\", to finish): ";
    std::cin >> std::ws;
    std::getline(std::cin, rr.title);
    if (rr.title == "end")
        return false;
    std::cout << "Enter rating: ";
    std::cin >> rr.rating;
    if (!std::cin)
        return false;
    // pozbycie siê reszty danych wejœciowych
    while (std::cin.get() != '\n')
        continue;

    return true;
}

static void ShowReview(const std::shared_ptr<Review>& rr)
{
    std::cout << rr->rating << "\t" << rr->title << std::endl;
}