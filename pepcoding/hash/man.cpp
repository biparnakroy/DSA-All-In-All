#include <bits/stdc++.h>
using namespace std;

void find_height(string root, unordered_map<string, unordered_set<string>> tree, unordered_map<string, int> &res)
{

    if (tree[root].size() == 0)
    {
        res[root] = 0;
        return;
    }

    for (auto child : tree[root])
    {
        find_height(child, tree, res);
        res[root] = res[root] + res[child] + 1;
    }
}

void find_count(unordered_map<string, string> emp_man, unordered_map<string, int> &res)
{
    unordered_map<string, unordered_set<string>> tree;
    string ceo = "";
    for (auto emp : emp_man)
    {
        string man = emp.second;
        if (man == emp.first)
        {
            ceo = man; //my root
            continue;
        }
        else
            tree[man].insert(emp.first);
    }

    find_height(ceo, tree, res);
}

int main()
{
    int n;
    cin >> n;
    unordered_map<string, string> emp_man;
    vector<string> employee;
    unordered_map<string, int> res;
    for (int i = 0; i < n; i++)
    {
        string man, emp;
        cin >> emp >> man;
        emp_man[emp] = man;
        employee.push_back(emp);
    }

    find_count(emp_man, res);

    for (auto e : employee)
    {
        cout << e << " " << res[e]<< endl;
    }

    return 0;
}

/**
     * 
     * 
     *        a
     *      /   \
     *     c    d
     *   / | \   \
     *  e  f  g   h
     * 
     * a : c,d
     * c : e,f,g
     * d : h
     * 
     * 
    //  * e c
    //  * f c
    //  * g c
    //  * h d
    //  * c a
    //  * d a
    //  * a a
     * 
     * */
