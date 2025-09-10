#include "black_scholes.hpp"
#include "root_finders.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout<< fixed<< setprecision(6);    //fixed precision notation to 10 digits

    //input from user
    double S, K, r, T, market_price, sigma;
    int max_iter;
    char option_type;
    cout << "Enter Spot Price (S): ";
    cin >> S;
    cout << "Enter Strike Price (K): ";
    cin >> K;
    cout << "Enter Risk-free Rate (r) [in decimal, e.g. 0.05]: ";
    cin >> r;
    cout << "Enter Time to Maturity (T in years): ";
    cin >> T;
    cout << "Enter Market Price of Option: ";
    cin >> market_price;
    cout << "Enter the initial value of sigma : ";
    cin >> sigma;
    cout << "Enter the number of maximum iterations : ";
    cin >> max_iter;
    cout << "Enter Option Type (C for Call, P for Put): ";
    cin >> option_type;

    bool isCall = (option_type=='C'|| option_type=='c');

    double cbs_price = black_scholes_formula(isCall, S, K, r, T, sigma);
    cout<< "CBS Price = "<< cbs_price << endl;
    IVResult result = newtonRaphsonIV(isCall, S, K, r, T, market_price, sigma, 1e-8, max_iter);
    // Print results
    cout << "Implied Volatility via Newton Raphson's Method = " << result.IV << endl;
    cout << "Converged in " << result.iteration << " iteration" << endl;
    cout << "Converged Status = " << (result.converge ? "true" : "false") << endl;


    return 0;



}