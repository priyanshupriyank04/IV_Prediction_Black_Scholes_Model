#include "black_scholes.hpp"
#include "root_finders.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout<< fixed<< setprecision(10);    //fixed precision notation to 10 digits

    //input from user
    double S, K, r, T, market_price;
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
    cout << "Enter Option Type (C for Call, P for Put): ";
    cin >> option_type;

    bool isCall = (option_type=='C'|| option_type=='c');

    IVResult result = newtonRaphsonIV(isCall, S, K, r, T, market_price);
    // Print results
    cout << "\nEstimated Implied Volatility: " << result.IV << endl;
    cout << "Iterations: " << result.iteration << endl;
    cout << "Converged: " << (result.converge ? "Yes" : "No") << endl;

    return 0;



}