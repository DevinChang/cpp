#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class date
{
public:
    friend ostream& operator<<(ostream&, const date&);

    date() = default;
    date(string &ds);

    unsigned y() const { return year; }
    unsigned m() const { return month; }
    unsigned d() const { return day; }

private:
    unsigned year, month, day;
};

// 月份全称
const string month_name[] = { "January", "February", "March", "April", "May", "June",
                              "July", "August", "September", "October", "November", "December" };
// 月份简写
const string month_abbr[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
                              "Jul", "Aug", "Sept", "Oct", "Nov", "Dec"};
// 每月天数
const int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

inline int get_month(string &ds, int &end_of_month)
{
    int i, j;
    for (i = 0; i < 12; i++)
    {
        // 检查每个字符是否与月份简写相等
        for (j = 0; j < month_abbr[i].size(); j++)
        {
            if (ds[j] != month_abbr[i][j])  // 不是此月简写
            {
                break;
            }
        }

        if (j == month_abbr[i].size())  // 与简写匹配
        {
            break;
        }
    }

    if (i == 12)    // 与所有月份名都不相同
    {
        throw invalid_argument("不是合法月份名");
    }

    if (ds[j] == ' ') // 空白符，仅是月份简写
    {
        end_of_month = j + 1;
        return i + 1;
    }

    for (; j < month_name[i].size(); j++)
    {
        if (ds[j] != month_name[i][j])
        {
            break;
        }
    }

    if (j == month_name[i].size() && ds[j] == ' ') // 月份全称
    {
        end_of_month = j + 1;
        return i + 1;
    }

    throw invalid_argument("不是合法月份名");
}

inline int get_day(string &ds, int month, int &p)
{
    size_t q;
    int day = stoi(ds.substr(p), &q); // 从p开始的部分转换为日期值
    if (day < 1 || day > days[month])
    {
        throw invalid_argument("不是合法日期值");
    }
    p += q;   // 移动到日期值之后
    return day;
}

inline int get_year(string &ds, int &p)
{
    size_t q;
    int year = stoi(ds.substr(p), &q);  // 从p开始的部分转换为年
    if (p + q < ds.size())
    {
        throw invalid_argument("非法结尾内容");
    }
    return year;
}

date::date(string &ds)
{
    int p;
    size_t q;

    if ((p = ds.find_first_of("0123456789")) == string::npos)
    {
        throw invalid_argument("没有数字，非法日期");
    }

    if (p > 0)  // 月份名格式
    {
        month = get_month(ds, p);
        day = get_day(ds, month, p);
        if (ds[p] != ' ' && ds[p] != ',')
        {
            throw invalid_argument("非法间隔符");
        }
        p++;
        year = get_year(ds, p);
    }
    else  // 月份值格式
    {
        month = stoi(ds, &q);
        p = q;
        if (month < 1 || month > 12)
        {
            throw invalid_argument("不是合法月份值");
        }
        if (ds[p++] != '/')
        {
            throw invalid_argument("非法间隔符");
        }
        day = get_day(ds, month, p);
        if (ds[p++] != '/')
        {
            throw invalid_argument("非法间隔符");
        }
        year = get_year(ds, p);
    }
}

ostream & operator<<(ostream& out, const date& d)
{
    out << d.y() << "年" << d.m() << "月" << d.d() << "日" << endl;
    return out;
}

#endif // DATE_H_INCLUDED
