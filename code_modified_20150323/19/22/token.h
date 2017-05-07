class Token
{
public:
    // 因为union含有一个string成员，所以Token必须定义拷贝控制成员
    // 定义移动构造函数和移动赋值运算符的任务留待本节练习完成
    Token() : tok(INT), ival(0) {}
    Token(const Token &t) : tok(t.tok) { copyUnion(t); }
    Token &operator=(const Token&);
    // 如果union含有一个Sales_data成员，则我们必须销毁它
    ~Token() { if (tok == SDATA) sval.~string(); }
    Token &operator=(char);
    Token &operator=(int);
    Token &operator=(double);
    Token &operator=(Sales_data);

private:
    enum {INT, CHAR, DBL, SDATA} tok;  // 判别式
    union  // 匿名联合
    {
        char cval;
        int ival;
        double dval;
        Sales_data sval;
    };  // 每个Token对象含有一个该匿名联合类型的未命名成员
    void copyUnion(const Token&);  // 检查判别式，然后酌情拷贝union成员
};

