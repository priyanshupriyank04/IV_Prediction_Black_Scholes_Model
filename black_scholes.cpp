#include "black_scholes.hpp"
#include <cmath> 
#include <stdexcept>
#include <iostream>

using namespace std;
constexpr double PI = 3.14159265358979323846;

//probability density function for standard normal distribution 

double norm_pdf(double x)
{
    return (1.0 / (2 * PI)) * exp(-0.5 * x * x); 
}

//continuous density function for standard normal distribution 

double norm_cdf(double x)
{
    return 0.5 * (1 + erf(x/sqrt(2.0)));
}

//d1 term in BSM 

double d1(double S, double K, double r, double T, double sigma)
{
    
    if(S<=0 || K<=0 || r<=0 || T<=0 || sigma<=0)
    {
        throw invalid_argument("Inputs must be positive");
    }

    return (log(S/K) + (r + 0.5 * sigma * sigma) * T)/(sigma * sqrt(T));
}

//d2 term in BSM 

double d2(double S, double K, double r, double T, double sigma)
{
    return d1(S,K,r,T,sigma) - sigma * sqrt(T);
}

//bsm formula calculation for call and put option 

double black_scholes_formula(bool isCall, double S, double K, double r, double T, double sigma)
{
    const double D1 = d1(S,K,r,T,sigma);
    const double D2 = d2(S,K,r,T,sigma);
    if(isCall)
    {
        return S * norm_cdf(D1) - K * exp(-r * T) * norm_cdf(D2);
    }
    else{
        return K * exp(-r * T) * norm_cdf(-D2) - S * norm_cdf(-D1);
    }
}

// vega = dprice/dsigma, measures the change in price in respect to volatility 

double vega(double S, double K, double r, double T, double sigma)
{
    const double D1 = d1(S,K,r,T,sigma);
    return S * sqrt(T) * norm_pdf(D1);
}