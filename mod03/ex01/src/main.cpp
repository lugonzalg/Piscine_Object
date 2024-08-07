#include "thuesdayDiscount.hpp"
#include "packageReductionDiscount.hpp"

int main() {
    Command c1("Lukas");
    c1.add_article("lettuce", 10, 0.75);
    c1.add_article("tomato", 20, 1.75);
    c1.add_article("onion", 10, 0.45);
    c1.add_article("radish", 110, 0.05);
    c1.add_article("pork", 10, 10.75);

    c1.get_total_price();

    PackageReductionDiscountCommand p1("lukas");
    p1.add_article("lettuce", 10, 0.75);
    p1.add_article("tomato", 20, 1.75);
    p1.add_article("onion", 10, 0.45);
    p1.add_article("radish", 110, 0.05);
    p1.add_article("pork", 10, 10.75);
    p1.get_total_price();

    ThuesdayDiscountCommand t1("lukas");
    t1.add_article("lettuce", 10, 0.75);
    t1.add_article("tomato", 20, 1.75);
    t1.add_article("onion", 10, 0.45);
    t1.add_article("radish", 110, 0.05);
    t1.add_article("pork", 10, 10.75);
    t1.get_total_price();

    struct tm date;

    date.tm_year = 2024 - 1900;
    date.tm_mon = 7;
    date.tm_mday = 6;
    date.tm_wday = 5;

    mktime(&date);

    ThuesdayDiscountCommand t2("lukas", &date);
    t2.add_article("lettuce", 10, 0.75);
    t2.add_article("tomato", 20, 1.75);
    t2.add_article("onion", 10, 0.45);
    t2.add_article("radish", 110, 0.05);
    t2.add_article("pork", 10, 10.75);
    t2.get_total_price();
    return 0;
}