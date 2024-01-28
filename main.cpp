#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cstring>


using namespace std;
vector<string> tokens;
bool isSeparator(char ch)
{
    return strchr(" ,(){}[];",ch) != NULL;
}
bool isOperator(char ch)
{
    return strchr("+-*/><=!", ch) != NULL;
}


void separateToken(string line)
{
    string token;
    for(int i = 0; i < line.size(); i++)
    {
        if(isSeparator(line[i]))
        {
            if(token != "")
            {
                tokens.push_back(token);
            }
            token="";

        }
        else if(isOperator(line[i]))
        {
            if (token != "")
            {
                tokens.push_back(token);
            }

            token=line[i];
            tokens.push_back(token);
            token="";
        }
        else
        {
            token.push_back(line[i]);
        }
    }
}



bool isKeyword(string str)
{
    string keywords[] = {"if", "else", "while", "do", "break", "continue",
                         "int", "double", "float", "return", "char", "case",
                         "long", "short", "typedef", "switch", "unsigned",
                         "void", "static", "struct", "sizeof", "long",
                         "volatile", "typedef", "enum", "const", "union",
                         "extern", "bool"
                        };


    for(string keyword : keywords)
    {
        if(str == keyword)
        {
            return true;
        }
    }
    return false;
}

bool isOperator(string str)
{
    string operators[] = {"+","-","*","/",">", "<", "=", "!", "|", "&","~","?",":"};
    for(string ope : operators)
    {
        if(str == ope)
        {
            return true;
        }
    }
    return false;
}

bool is_digits(string str)
{
    for (char ch : str)
    {
        if (!isdigit(ch))
        {
            return false;
        }
    }

    return true;
}

bool isIdentifier(string identefier)
{
    bool flag = true;

    if(identefier[0] == '_' ||
            (identefier[0] >=  'a' && identefier[0] <= 'z')
            || (identefier[0] >=  'A' && identefier[0] <= 'Z'))
    {
        for (size_t i = 1; i < identefier.length(); i++)
        {
            if(
                !(identefier[i] == '_' ||
                  (identefier[i] >= 'a' && identefier[i] <= 'z') ||
                  (identefier[i] >= 'A' && identefier[i] <= 'Z') ||
                  isdigit(identefier[i])))
            {
                flag = false;
                break;
            }
        }

        if(flag == false)
        {
            return false;
        }
        else
        {
            return true;
        }

    }
    else
    {
        return false;
    }

}


int main()
{
    ifstream file;
    string line;

    file.open("program.txt");

    while (getline(file, line))
    {
        separateToken(line);
    }

    file.close();

    for(string token : tokens)
    {

        if(isKeyword(token))
        {
            cout << token << " is a keyworkd" << endl;
        }
        else if(isOperator(token))
        {
            cout << token << " is a Operator" << endl;
        }
        else if(is_digits(token))
        {
            cout << token << " is a Number" << endl;
        }
        else if(isIdentifier(token))
        {
            cout << token << " is an Identifier" << endl;
        }
        else
        {
            cout << token << " is not valid Identifier" << endl;
        }
    }

}
