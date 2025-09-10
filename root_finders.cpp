#include "root_finders.hpp"
#include "black_scholes.hpp"
#include <cmath>
#include <limits>
#include <iostream>
#include <algorithm>

using namespace std;

double bisectionIV(bool isCall, double S, double K, double r, double T, double market_price, double low, double high, double tol, double max_iter)
{
    for(int i = 0;i< max_iter;i++)
    {
        double mid = 0.5 * (low + high);
        double price = black_scholes_formula(isCall, S, K, r, T, mid);

        if(fabs(price-market_price)< tol )
        {
            return mid;
        }

        if(price > market_price)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }

    return 0.5 * (low + high);
}

IVResult newtonRaphsonIV(bool isCall, double S, double K, double r, double T,
                         double market_price, double initial_sigma, double tol, int max_iter)
{
    double sigma = initial_sigma;
    bool converged = false;

   
    int i = 0;

    for (; i < max_iter; i++)
    {
        double price = black_scholes_formula(isCall, S, K, r, T, sigma);
        double diff = price - market_price;

        if (fabs(diff) < tol)
        {
            converged = true;
            break;
        }

        double v = vega(S, K, r, T, sigma);
        if (v < 1e-8 || !std::isfinite(sigma))
        {
            break;
        }

        sigma = sigma - diff / v;
        sigma = std::clamp(sigma, 1e-6, 5.0);
    }

    if (converged)
    {
        return {sigma, i + 1, true};  // Newton-Raphson success
    }

    // Fallback to bisection
    cout << "Falling back to bisection method\n";
    double fallback_sigma = bisectionIV(isCall, S, K, r, T, market_price, 1e-6, 5.0, tol, 1000);
    double fallback_price = black_scholes_formula(isCall, S, K, r, T, fallback_sigma);

    //  Check if bisection result is good enough
    bool fallback_converged = std::fabs(fallback_price - market_price) < tol;

    return {fallback_sigma, i + 1, fallback_converged};
}
