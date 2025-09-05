#include "root_finders.hpp"
#include "black_scholes.hpp"
#include <cmath>
#include <limits>
#include <iostream>

using namespace std;

IVResult newtonRaphsonIV(bool isCall, double S, double K, double r, double T, double market_price, double initial_sigma, int tol , int max_iter)
{
    double sigma = initial_sigma;
    int i = 0;

    for(; i<max_iter;i++)
    {
        double price = black_scholes_formula(isCall, S,K,r,T,sigma);
        double diff = price - market_price;

        if(fabs(diff) < tol)
        {
            return {sigma, i+1, true};
        }

        double v = vega(S,K,r,T,sigma);
        if(v < tol)
        {
            break;
        }

        sigma = sigma - diff/v;
    }

    //if loop ends without convergence
    return {sigma, i, false};
}