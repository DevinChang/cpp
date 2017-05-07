#ifndef MY_STRBLOB_H
#define MY_STRBLOB_H

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <stdexcept>
using namespace std;

// ��ǰ������StrBlob�е�������������
class StrBlobPtr;

class StrBlob
{
    friend class StrBlobPtr;
public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);
    StrBlob(vector<string> *p);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    // ��Ӻ�ɾ��Ԫ��
    void push_back(const string &t) {data->push_back(t);}
    void pop_back();
    // Ԫ�ط���
    string& front();
    const string& front() const;
    string& back();
    const string& back() const ;

    // �ṩ��StrBlobPtr�Ľӿ�
    StrBlobPtr begin();  // ����StrBlobPtr����ܶ�������������
    StrBlobPtr end();
    // const�汾
    StrBlobPtr begin() const;
    StrBlobPtr end() const;
private:
    shared_ptr<std::vector<std::string>> data;
    // ���data[i]���Ϸ����׳�һ���쳣
    void check(size_type i, const std::string &msg) const;
};

inline StrBlob::StrBlob(): data(make_shared<vector<string>>()) { }
inline StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) { }
inline StrBlob::StrBlob(vector<string> *p): data(p) { }

inline void StrBlob::check(size_type i, const string &msg) const
{
    if (i >= data->size())
    {
        throw out_of_range(msg);
    }
}

inline string& StrBlob::front()
{
    // ���vectorΪ�գ�check���׳�һ���쳣
    check(0, "front on empty StrBlob");
    return data->front();
}

// const�汾front
inline const string& StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}

inline string& StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}

// const�汾back
inline const string& StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

inline void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

// ����ͼ����һ�������ڵ�Ԫ��ʱ��StrBlobPtr�׳�һ���쳣
class StrBlobPtr
{
    friend bool eq(const StrBlobPtr&, const StrBlobPtr&);
public:
    StrBlobPtr(): curr(0) { }
    StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) { }
    StrBlobPtr(const StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz) { }

    string& deref() const;
    string& deref(int off) const;
    StrBlobPtr& incr();     // ǰ׺����
    StrBlobPtr& decr();     // ǰ׺�ݼ�
private:
    // �����ɹ���check����һ��ָ��vector��shared_ptr
    shared_ptr<vector<string>> check(size_t, const string&) const;

    // ����һ��weak_ptr����ζ�ŵײ�vector���ܻᱻ����
    weak_ptr<vector<string>> wptr;
    size_t curr;    // �������еĵ�ǰλ��
};

inline shared_ptr<vector<string>> StrBlobPtr::check(size_t i, const string &msg) const
{
    auto ret = wptr.lock(); // vector��������
    if (!ret)
    {
       throw runtime_error("unbound StrBlobPtr");
    }
    if (i >= ret->size())
    {
       throw out_of_range(msg);
    }
    return ret; // ���򣬷���ָ��vector��shared_ptr
}

inline string& StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr]; // (*p)�Ƕ�����ָ���vector
}

inline string& StrBlobPtr::deref(int off) const
{
    auto p = check(curr + off, "dereference past end");
    return (*p)[curr + off]; // (*p)�Ƕ�����ָ���vector
}

// ǰ׺���������ص�����Ķ��������
inline StrBlobPtr& StrBlobPtr::incr()
{
    // ���curr�Ѿ�ָ��������β��λ�ã��Ͳ��ܵ�����
    check(curr, "increment past end of StrBlobPtr");
    ++curr; // �ƽ���ǰλ��
    return *this;
}

// ǰ׺�ݼ������صݼ���Ķ��������
inline StrBlobPtr& StrBlobPtr::decr()
{
    // ���curr�Ѿ�Ϊ0���ݼ����ͻ����һ���Ƿ��±�
    --curr;     // �ݼ���ǰλ��
    check(-1, "decrement past begin of StrBlobPtr");
    return *this;
}

// StrBlob��begin��end��Ա�Ķ���
inline StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

inline StrBlobPtr StrBlob::end()
{
  	auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

// const�汾
inline StrBlobPtr StrBlob::begin() const
{
	  return StrBlobPtr(*this);
}

inline StrBlobPtr StrBlob::end() const
{
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

// StrBlobPtr�ıȽϲ���
inline bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
    // ���ײ��vector��ͬһ��
    if (l == r)
    {
    	  // ������ָ�붼�ǿգ�����ָ����ͬԪ��ʱ���������
    	  return (!r || lhs.curr == rhs.curr);
    }
    else
    {
    	  return false; // ��ָ��ͬvector���򲻿������
    }
}

inline bool neq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	  return !eq(lhs, rhs);
}

#endif
