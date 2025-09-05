#ifndef BLACK_SCHOLES_HPP
#define BLACK_SCHOLES_HPP

/**
 Conventions
 -> S = spot price of the underlying asset
 -> K = strike price of the option contract 
 -> r = risk free rate of returns 
 -> T = time to contract expiry in years 
 -> sigma = volatility (annualised standard deviation)
 -> isCall = true for call and false for put option 
 */

 //Standard normal probability distribution function phi(x)

 double norm_pdf(double x);

 //standard normal cumulative distribution function 

 double norm_cdf(double x);

 //d1 term in BSM = (ln(S/K) + (r + 0.5 * sigma^2)*T)/(sigma * sqrt(T))

 double d1(double S, double K, double r, double T, double sigma);

 //d2 term in BSM = d1 - sigma * (sqrt(T))

 double d2(double S, double K, double r, double T, double sigma);

 //black scholes price calculating formula 

 double black_scholes_formula(bool isCall, double S, double K, double r, double T, double sigma);

 //vega for implied volatility calculation 

 double vega(double S, double K, double r, double T, double sigma);
#endif