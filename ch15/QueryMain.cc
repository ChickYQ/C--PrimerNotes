#include"Query.h"

int main()
{
    std::ifstream file("./test.txt");

    TextQuery tQuery(file);

    Query q = Query("fiery") & Query("bird") | Query("wind");

    print(cout,q.eval(tQuery)) << endl;

    return 0;
}