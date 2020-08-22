// MODULE:		postfix.cpp
// PROGRAMMER:	Gary J. Blair
// LANGUAGE:	C++
// DATE:		96/7/03
//
// PURPOSE:
//		Evaluate postfix arithmetic expressions.
//		Test program for Homework 3.

#include "dblstk.h"
#include "string.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class Token {
  public:
    typedef enum { operand_token,
                   operator_token,
                   eod_token } TokenType;
    typedef enum { add_op,
                   sub_op,
                   mul_op,
                   div_op } ArithmeticOperator;

    Token();
    TokenType NextToken();
    Token &operator=(char *text);
    TokenType Type();
    ArithmeticOperator Operator(void);
    double Value();

  private:
    TokenType token_type;    // The type of token.
    ArithmeticOperator oper; // The operator, if an operator_token.
    double value;            // The value, if an operand_token.
    char *source;            // The string from which tokens are generated.
    char *next;              // The next char to be looked at.
};

int main() {
    DoubleStack ds(57);      // Stack to evaluate expressions.
    Token t;                 // One token at a time.
    double lhs;              // Left-hand side operand.
    double rhs;              // Right-hand side operand.
    double result;           // Result of  lhs op  rhs.
    size_t i;                // Loop variable.
    const size_t n_data = 3; // # of data items.
    char *data[3];           // Pointers to data strings.
    double answer[3];        // Array of answers.

    data[0] = "3  2  + ";
    answer[0] = 5;
    data[1] = "13  7  *  6  3  -  * ";
    answer[1] = 273;
    data[2] = "64 4 /  8  2 +  3 4 + - * ";
    answer[2] = 48;

    ofstream fout("postfix.out");

    for (i = 0; i < n_data; ++i) {
        fout << "Processing " << data[i] << endl
             << "the correct answer is " << answer[i]
             << " and the calculated answer is ";

        t = data[i];
        while (t.NextToken() != Token::eod_token) {
            if (t.Type() == Token::operand_token) {
                result = t.Value();
                ds.push(result);
            } else {
                ds.pop(rhs);
                ds.pop(lhs);
                switch (t.Operator()) {
                case Token::add_op:
                    result = lhs + rhs;
                    break;

                case Token::sub_op:
                    result = lhs - rhs;
                    break;

                case Token::mul_op:
                    result = lhs * rhs;
                    break;

                case Token::div_op:
                    result = lhs / rhs;
                    break;
                }
                ds.push(result);
            }
        }
        ds.pop(result);
        fout << result << endl
             << endl;
        if (!ds.empty()) {
            fout << "*** Stack should be empty but is not.\n";
            exit(1);
        }
    }
    fout.close();
    return 0;
}

// Constructor.

Token::Token() {
    source = NULL;
    next = NULL;
}

// Process next token from source string and return
// the type of token it is.

Token::TokenType Token::NextToken() {
    int token_found = 0; // Have we found a token yet?
    char temp[1024];     // Temporary to sscanf an operand.
    char *pt;            // Pointer to temp.

    while (*next) {
        if (*next == ' ' || *next == '\t') {
            ++next;
            continue;
        } else if (*next == '*') {
            token_type = operator_token;
            oper = mul_op;
            ++next;
            token_found = 1;
            break;
        } else if (*next == '/') {
            token_type = operator_token;
            oper = div_op;
            ++next;
            token_found = 1;
            break;
        } else if (*next == '+' && (!strchr("0123456789", *(next + 1)))) {
            token_type = operator_token;
            oper = add_op;
            ++next;
            token_found = 1;
            break;
        } else if (*next == '-' && (!strchr("0123456789", *(next + 1)))) {
            token_type = operator_token;
            oper = sub_op;
            ++next;
            token_found = 1;
            break;
        } else {
            pt = temp;
            do {
                *(pt++) = *(next++);
            } while (*next && *next != ' ' && *next != '\t');
            *pt = '\0';
            if (!sscanf(temp, "%lf", &value)) {
                cout << "*** Error performing sscanf of '" << temp << "'\n";
                exit(1);
            }
            token_type = operand_token;
            token_found = 1;
            break;
        }
    }
    return (token_found) ? token_type : eod_token;
}

// Assign a source string to a token.

Token &Token::operator=(char *text) {
    if (source)
        delete source;
    source = new char[strlen(text) + 1];
    strcpy(source, text);
    next = source;
    return *this;
}

// Inquire the type of a token.

Token::TokenType Token::Type() {
    return token_type;
}

// Inquire which operator a token represents.

Token::ArithmeticOperator Token::Operator(void) {
    if (token_type != operator_token) {
        cerr << "*** Incorrect inquiry.\n";
        exit(1);
    }
    return oper;
}

// Inquire the numberic value of a token.

double Token::Value() {
    if (token_type != operand_token) {
        cerr << "*** Incorrect inquiry.\n";
        exit(1);
    }
    return value;
}
