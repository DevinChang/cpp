#include "Quote.h"

class Bulk_quote : public Quote
{
public:
    Bulk_quote(const string &book = "", double sales_price = 0.0, size_t qty = 0, double disc = 0.0)
        : Quote(book, sales_price), min_qty(qty), discount(disc)
    {
        cout << "Bulk_constructor is running" << endl;
    }

    double net_price(size_t cnt) const
    {
        if (cnt > min_qty)
        {
            return cnt * ( 1- discount ) * price;
        }
        else
        {
            return cnt * price;
        }
    }

    ~Bulk_quote()
    {
        cout << "Bulk_quote destructor is running" << endl;
    }
    
private:
    size_t min_qty;
    double discount;
};

ostream &operator<<(ostream &os, Bulk_quote &bq)
{
    os << "\tUsing operator<<(ostream &, Bulk_quote &)" << endl;
    return os;
}
