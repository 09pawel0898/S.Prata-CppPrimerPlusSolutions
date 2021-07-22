#include "includes.h"

#ifndef EX16_10_H
#define EX16_10_H


/* ------- ex 10 -------*/

struct Review {
    std::string title;
    int rating;
    double price;
};
void ex10(void);

// declaring static functions just for visualize this compilation unit interface in header file

static bool operator<(const std::shared_ptr<Review>& r1, const std::shared_ptr<Review>& r2);
static bool worseThan(const std::shared_ptr<Review>& r1, const std::shared_ptr<Review>& r2);
static bool FillReview(Review& rr);
static void ShowReview(const std::shared_ptr<Review>& rr);

#endif