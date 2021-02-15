#include"TextFind.h"
#include<algorithm>

class Query;
class Query_base{
    friend class Query;
protected:
    virtual ~Query_base() = default;
private:

    virtual QueryResult eval(const TextQuery&) const =0;
    virtual string rep() const =0;

};

class WordQuery:public Query_base{
    friend class Query;
    WordQuery(const string &s):query_word(s){}
    QueryResult eval(const TextQuery &t) const override {return t.query(query_word);}
    string rep() const override {return query_word;}
    string query_word;
};

class Query{
    friend Query operator~(const Query &);
    friend Query operator|(const Query &, const Query &);
    friend Query operator&(const Query &, const Query &);

public:
    Query(const string &);
    Query() = default;
    QueryResult eval(const TextQuery &t) const{return q -> eval(t);}
    string rep() const {return q -> rep();}

private:
    Query(shared_ptr<Query_base> query):q(query){}
    shared_ptr<Query_base> q;
};

inline ostream& operator<<(ostream &os, const Query &q)
{
    return os << q.rep();
}
inline Query::Query(const string &s):q(new WordQuery(s)){}

class NotQuery:public Query_base{
    friend class Query operator~(const Query&);
    NotQuery(const Query &q):query(q){}
    QueryResult eval(const TextQuery&) const;
    string rep() const {return "~(" + query.rep() +")";}
    Query query;
};

inline Query operator~(const Query &operand)
{
    return shared_ptr<Query_base>(new NotQuery(operand));
}

class BinaryQuery:public Query_base{

protected:
    BinaryQuery(const Query &q1, const Query &q2, string s):lhs(q1),rhs(q2),opSym(s){}

    Query lhs,rhs;
    string opSym;
    string rep() const {return "(" + lhs.rep() + " " + opSym +" " + rhs.rep() + ")";}
};

class AndQuery:public BinaryQuery{
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query &q1, const Query &q2):BinaryQuery(q1,q2,"&"){}
    QueryResult eval(const TextQuery&) const;

};

inline Query operator&(const Query &q1, const Query &q2)
{
    return shared_ptr<Query_base>(new AndQuery(q1,q2));
}

class OrQuery:public BinaryQuery{

    friend Query operator|(const Query&, const Query&);
    OrQuery(const Query &q1, const Query &q2):BinaryQuery(q1,q2,"|"){}
    QueryResult eval(const TextQuery&) const;
};

inline Query operator|(const Query &q1, const Query &q2)
{
    return shared_ptr<Query_base>(new OrQuery(q1,q2));
}

QueryResult OrQuery::eval(const TextQuery& text) const
{
    auto right = rhs.eval(text),left = lhs.eval(text);
    auto ret_lines = make_shared<set<int>>(left.begin(),left.end());
    ret_lines -> insert(right.begin(),right.end());
    return QueryResult(rep(),ret_lines,left.get_file());
}

QueryResult AndQuery::eval(const TextQuery& text) const
{
    auto right = rhs.eval(text),left = lhs.eval(text);
    auto ret_lines = make_shared<set<int>>();
    set_intersection(left.begin(), left.end(), right.begin(), right.end(), inserter(*ret_lines,ret_lines -> begin()));
    return QueryResult(rep(),ret_lines,left.get_file());
}

QueryResult NotQuery::eval(const TextQuery& text) const
{
    auto result = query.eval(text);
    auto ret_lines = make_shared<set<int>>();
    auto beg = result.begin(),end = result.end();
    auto sz = result.get_file() -> size();
    for(int n =0; n!=sz; ++n)
    {
        if(beg == end || *beg != n)
            ret_lines -> insert(n);
        else if(beg != end)
            ++beg;
    }
    return QueryResult(rep(), ret_lines, result.get_file());

}

